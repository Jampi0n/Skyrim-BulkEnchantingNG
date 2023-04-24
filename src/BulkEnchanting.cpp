#include "BulkEnchanting.h"
#include "CountMap.h"
#include "Utils.h"

namespace BulkEnchanting {

	using Count = int32_t;
	using InventoryItemMap = std::map<TESBoundObject*, std::pair<Count, std::unique_ptr<InventoryEntryData>>>;


	class SoulGemMath {
	private:
		std::unordered_map<Count, std::vector<ExtraDataList*>> knownTargets;
		Count flexible = 0;
	public:
		SoulGemMath() {
			Reset();
		}

		void Reset() {
			flexible = 0;
			knownTargets.clear();
			auto newVector = std::vector< ExtraDataList*>();
			knownTargets.insert(std::pair<Count, std::vector<ExtraDataList*>>(0, newVector));
		}

		void AddFlexible(Count num) {
			flexible += num;
		}

		void AddGroup(ExtraDataList* subgroup, Count num) {
			auto newTarget = num;
			std::vector<std::pair<Count, std::vector<ExtraDataList*>>> addedPairs;
			for (auto const& [key, val] : knownTargets) {
				newTarget = key + num;
				if (!knownTargets.contains(newTarget)) {
					auto newVector = std::vector< ExtraDataList*>(val);
					newVector.push_back(subgroup);
					addedPairs.push_back(std::pair<Count, std::vector<ExtraDataList*>>(newTarget, newVector));
				}
			}
			for (auto& pair : addedPairs) {
				knownTargets.insert(pair);
			}
		}

		std::pair<Count, std::vector<ExtraDataList*>> GetBestVector(Count target) {
			Count bestTarget = 0;
			for (auto const& [key, val] : knownTargets) {
				if (key <= target && key > bestTarget) {
					bestTarget = key;
				}
			}

			auto flex = std::min(target - bestTarget, flexible);
			return std::pair<Count, std::vector<ExtraDataList*>>(bestTarget + flex, knownTargets.at(bestTarget));

		}
	};

	bool IsEnchanted(TESBoundObject* item) {
		/// <summary>
		/// Returns true, if the base item is enchanted (not player enchanted).
		/// </summary>
		/// <param name="item"></param>
		/// <returns></returns>
		if (item->formType == FormType::Armor) {
			auto armor = static_cast<TESObjectARMO*>(item);
			return armor->formEnchanting != NULL;
		} else if (item->formType == FormType::Weapon) {
			auto weapon = static_cast<TESObjectWEAP*>(item);
			return weapon->formEnchanting != NULL;
		}
		return false;
	}

	bool IsReusable(TESSoulGem* soulGem) {
		return soulGem->HasKeywordID(FormID(0xed2f1));
	}

	ExtraEnchantment* SubgroupGetEnchantment(ExtraDataList* subgroup) {
		auto xData = subgroup->GetByType(ExtraDataType::kEnchantment);
		return xData == NULL ? NULL : static_cast<ExtraEnchantment*>(xData);
	}

	ExtraTextDisplayData* SubgroupGetName(ExtraDataList* subgroup) {
		auto xData = subgroup->GetByType(ExtraDataType::kTextDisplayData);
		return xData == NULL ? NULL : static_cast<ExtraTextDisplayData*>(xData);
	}

	ExtraSoul* SubgroupGetSoul(ExtraDataList* subgroup) {
		auto xData = subgroup->GetByType(ExtraDataType::kSoul);
		return xData == NULL ? NULL : static_cast<ExtraSoul*>(xData);
	}

	bool SubgroupIsValidForBulk(ExtraDataList* subgroup) {
		for (auto& xData : *subgroup) {
			auto xType = xData.GetType();
			if (xType != ExtraDataType::kTextDisplayData && xType != ExtraDataType::kEnchantment) {
				return false;
			}
		}
		auto xData = subgroup->GetByType(ExtraDataType::kEnchantment);
		return xData != NULL;
	}

	bool SubgroupIsPlayerEnchanted(ExtraDataList* subgroup) {
        auto xData = subgroup->GetByType(ExtraDataType::kEnchantment);
        return xData != NULL;
    }

	std::string GetEnchantmentKey(ExtraDataList* subgroup) {
		/// <summary>
		/// Returns a unique string representation of the player enchantment.
		/// </summary>
		/// <param name="enchantmentItem"></param>
		/// <returns></returns>
		auto extraEnch = SubgroupGetEnchantment(subgroup);
		std::string s = (extraEnch != NULL) ? "ench_" : "noench_";

		auto extraName = SubgroupGetName(subgroup);
		if (extraName != NULL) {
			auto c_str = (extraName->displayName).c_str();
			s += "name=" + std::string(c_str);
		} else {
			s += "noname";
		}

		if (extraEnch != NULL) {
			auto enchantmentItem = extraEnch->enchantment;
			for (auto effect : enchantmentItem->effects) {
				std::stringstream stream;
				stream << std::hex << effect->baseEffect->GetFormID();
				std::string hexId(stream.str());

				s += "_eff=[" + hexId + "]" + effect->baseEffect->GetFullName() + "_mag=" + std::to_string(effect->GetMagnitude()) + "_dur=" + std::to_string(effect->GetDuration());
			}
		}
		return s;
	}


	class DebugHelper {
	public:
		static void LogItem(TESBoundObject* item, Count num) {
			if (spdlog::default_logger().get()->level() <= spdlog::level::level_enum::trace) {
				std::stringstream stream;
				stream << std::hex << item->GetFormID();
				std::string hexId(stream.str());

				logger::trace("[{}] {} x {}", hexId, item->GetName(), num);
			}
		}
		static void ListItems(std::string message, CountMap<TESBoundObject*>	unenchanted, CountMap<std::string> enchantments, CountMap<SOUL_LEVEL> soulGems, CountMap<ExtraDataList*> enchantedSubgroups) {
			if (spdlog::default_logger().get()->level() <= spdlog::level::level_enum::trace) {
				if (message.compare("") != 0) {
					logger::trace("{}", message);
				}

				logger::trace("Souls:");
				for (auto const& [key, val] : *soulGems.getMap()) {
					logger::trace("[{}] x {}", static_cast<int>(key), val);
				}
				logger::trace("Enchantments:");
				for (auto const& [key, val] : *enchantments.getMap()) {
					logger::trace("[{}] x {}", key, val);
				}
                logger::trace("Enchanted Subgroups:");
                for (auto const& [key, val] : *enchantedSubgroups.getMap()) {
                    logger::trace("[{}] x {}", static_cast<void*>(key), val);
                }
				logger::trace("Unenchanted:");
				for (auto const& [key, val] : *unenchanted.getMap()) {
					logger::trace("[{}] x {}", key->GetName(), val);
				}
			}
		}
	};

	/*
	Inventory:
	Actor.GetInventory() returns std::map<TESBoundObject*, std::pair<Count, std::unique_ptr<InventoryEntryData>>>
	The unique pointer cannot be stored and has to be dereferenced immediately.


	item type			optional		 optional list for every sub group within item type	   data specific for this sub group

	TESBoundObject -> InventoryEntryData -> BSSimpleList<ExtraDataList> -> ExtraDataList -> BSExtraData (e.g. Enchantment)
																		|				 -> BSExtraData (e.g. Soul Level)
																		|				 -> BSExtraData (e.g. Tempering)
																		|
																		-> ExtraDataList
																		-> ExtraDataList
																		-> ExtraDataList
																	   ...

	The inventory is stored in a map using TESBoundObject* as key type. Item forms (Weapons, Armor, Potions, ...) are inherit from TESBoundObject.
	The key can also be understood to use the FormID of the items.
	In order to differentiate sub groups of items with the same FormID, extra data is used.
	An item type (FormID) can have a list of extra data lists (BSSimpleList<ExtraDataList>).
	Each node in the BSSimpleList refers to one sub group of the item type. Base items do not have nodes in this BSSimpleList.
	So if the player has one normal iron dagger and one enchanted and simultaneously tempered iron dagger, the TESBoundObject for the iron dagger will have
	a InventoryEntryData with a BSSimpleList<ExtraDataList> with one node.
	The ExtraDataList will have two nodes, one to store the enchantment and one to store the tempering.
	As there are two iron daggers in total, but only one node in the BSSimpleList, the remaining iron dagger has no extra data and is a default iron dagger.
	A sub group can have multiple items that share their extra data. In that case, the count is stored as another node in the ExtraDataList of this sub group.



	*/

	class PlayerInventory {
	public:
        CountMap<ExtraDataList*> enchantedSubgroups;    // Enchanted items
		CountMap<TESBoundObject*>		unenchanted;	// Unenchanted items without extra data
		CountMap<std::string>		   enchantments;	// Player made enchantments (extra data) of items with at most Enchantment and Name as extra data
		CountMap<SOUL_LEVEL>		       soulGems;	// Soul levels used to determine which soul was used to potentially trigger bulk enchanting

		std::vector<SoulGemMath>       soulGemCount;	// Detailed information on the available soul gems for bulk enchanting

	private:

		void AddSoulSize(SOUL_LEVEL size, Count num, ExtraDataList* subgroup, bool hasToBeEmptied, bool canBulkEnchant) {
			soulGems.modItem(size, num);
			auto intSize = static_cast<Count>(size);
			logger::trace("AddSoulSize({},{})", intSize, num);
			if (canBulkEnchant) {
				if (subgroup != NULL && num > 1 && hasToBeEmptied) {
					soulGemCount.at(intSize).AddGroup(subgroup, num);
				} else {
					soulGemCount.at(intSize).AddFlexible(num);
				}
			}
		}

		void AddUnenchanted(TESBoundObject* item, Count num) {
			unenchanted.modItem(item, num);
			logger::trace("AddUnenchanted({},{})", item->GetName(), num);
		}

		void AddEnchanted(ExtraDataList* item, Count num) {
            enchantedSubgroups.modItem(item, num);
        }

		void AddEnchantment(std::string enchKey, Count num) {
			enchantments.modItem(enchKey, num);
			logger::trace("AddEnchantment({},{})", enchKey, num);
		}

	public:
		void update(Actor* player) {
            enchantedSubgroups.reset();
			unenchanted.reset();
			enchantments.reset();
			soulGems.reset();
			for (auto& e : soulGemCount) {
				e.Reset();
			}
			InventoryItemMap unique = player->GetInventory();
			for (auto const& [key, val] : unique) {
				Count num = val.first;
				if (num > 0) {
					auto entryData = val.second.get();
					if (key->formType == FormType::SoulGem) {
						TESSoulGem* soulGem = static_cast<TESSoulGem*>(key);
						DebugHelper::LogItem(soulGem, num);
						int remaining = num;
						if (entryData != NULL) {
							auto extraLists = entryData->extraLists;
							if (extraLists != NULL) {
								for (auto subgroup : *extraLists) {
									if (SubgroupGetSoul(subgroup) != NULL) {
										auto defaultLevel = soulGem->GetContainedSoul();
										auto dynamicLevel = subgroup->GetSoulLevel();
										if (dynamicLevel != SOUL_LEVEL::kNone && defaultLevel == SOUL_LEVEL::kNone) {
											// dynamic soul gems must be initially empty and dynamically filled
											// if they are reusable, their souls must be emptied on use
											// the subgroup argument is required to refer to it later, when choosing which groups to empty in case of reusable soul gems,
											// as the groups have be emptied as a whole, so the correct subgroups need to be chosen to achieve the maximum number of souls
											AddSoulSize(dynamicLevel, subgroup->GetCount(), subgroup, IsReusable(soulGem), true);
											remaining -= subgroup->GetCount();
										}
									}
								}
							}
						}
						if (remaining > 0) {
							auto defaultLevel = soulGem->GetContainedSoul();
							if (defaultLevel != SOUL_LEVEL::kNone) {
								// static soul gems must be initially filled
								// if they are reusable, they cannot be used for bulk enchanting but can still trigger it (because they would keep their soul when bulk enchanting)
								// YASTM (https://www.nexusmods.com/skyrimspecialedition/mods/56144) contains statically filled reusable soul gems 
								AddSoulSize(defaultLevel, remaining, NULL, false, !IsReusable(soulGem));
							}
						}
					} else if (key->formType == FormType::Armor || key->formType == FormType::Weapon) {
						DebugHelper::LogItem(key, num);
						if (!IsEnchanted(key)) { // base item must not be enchanted, so it can be enchanted by the player
							int remaining = num;
							if (entryData != NULL) {
								auto extraLists = entryData->extraLists;
								if (extraLists != NULL) {
									for (auto subgroup : *extraLists) {
										remaining -= subgroup->GetCount();
										// must have kEnchantment extra data and optionally also kTextDisplayData
										// any other extra data is avoided, as these are the two extra datas that are added by enchanting
										if (SubgroupIsValidForBulk(subgroup)) {
											AddEnchantment(GetEnchantmentKey(subgroup), subgroup->GetCount());
										}
                                        if (SubgroupIsPlayerEnchanted(subgroup)) {
                                            AddEnchanted(subgroup, subgroup->GetCount());
										}
									}
								}
							}
							if (remaining > 0) { // no extra data, add to unenchanted items
								AddUnenchanted(key, remaining);
							}
						}
					}
				}
			}
            DebugHelper::ListItems("Player Inventory Update:", unenchanted, enchantments, soulGems, enchantedSubgroups);
		}

		PlayerInventory(Actor* player) {
			soulGemCount = std::vector<SoulGemMath>(6, SoulGemMath());
			update(player);
		}
	};

	PlayerInventory* lastPlayerInventory = NULL;
	TESBoundObject* lastItem;
	std::string lastEnchantment;
	SOUL_LEVEL lastSoul;


	Count _starting = 0;
	Count _crafting = 0;

	void FreeData() {
		logger::trace("Free");
		std::free(lastPlayerInventory);
		lastPlayerInventory = NULL;
	}

	void DataMenuOpen() {
		_starting = 1;
	}
	void DataMenuClose() {
		_starting = 0;
		if (_crafting == 0) {
			FreeData();
		}
	}

	void DataCraftStart() {
		_crafting++;
	}
	void DataCraftEnd() {
		_crafting--;
		if (_crafting == 0 && _starting == 0) {
			FreeData();
		}
	}


	void OnStartEnchanting(StaticFunctionTag*, Actor* player) {
		logger::debug("Player activated Enchanting Table...");
		DataMenuOpen();
		if (lastPlayerInventory == NULL) {
            logger::trace("new PlayerInventory");
			lastPlayerInventory = new PlayerInventory(player);
		} else {
			logger::trace("update PlayerInventory");
			lastPlayerInventory->update(player);
		}
		lastItem = NULL;
		lastEnchantment = "";
		lastSoul = SOUL_LEVEL::kNone;
	}

	void OnEndEnchanting(StaticFunctionTag*, Actor* player) {
		logger::debug("Player leaves Enchanting Table.");
		DataMenuClose();
	}

	Count OnItemEnchanted(StaticFunctionTag*, Actor* player) {
		logger::debug("New item enchanted.");
		if (lastPlayerInventory == NULL) {
			logger::warn("Previous player inventory unknown, cannot perform Bulk Enchanting.");
			return 0;
		}

		DataCraftStart();
		PlayerInventory currentPlayerInventory(player);
		auto usedSouls = lastPlayerInventory->soulGems.sub(&currentPlayerInventory.soulGems);
		auto newEnchantments = currentPlayerInventory.enchantments.sub(&lastPlayerInventory->enchantments);
        auto enchantedSubgroups = currentPlayerInventory.enchantedSubgroups.sub(&lastPlayerInventory->enchantedSubgroups);
		auto removedItems = lastPlayerInventory->unenchanted.sub(&currentPlayerInventory.unenchanted);

		lastPlayerInventory->update(player);
		DataCraftEnd();


		DebugHelper::ListItems("Delta:", removedItems, newEnchantments, usedSouls, enchantedSubgroups);



		if (usedSouls.isSingular() && newEnchantments.isSingular() && removedItems.isSingular()) {
			// After enchanting, one soul and one unenchanted item should be gone, while one enchanted item should appear
			// If this is the case, the entire enchantment process is known and can be repeated
			logger::trace("singular:");
			lastSoul = usedSouls.getSingular();
			lastItem = removedItems.getSingular();
			lastEnchantment = newEnchantments.getSingular();
			if (lastSoul == SOUL_LEVEL::kNone) {
				logger::warn("invalid singular soul");
				return 0;
			}
			if (lastEnchantment.compare("ench") == 0) {
				logger::warn("invalid singular enchantment");
				return 0;
			}

			InventoryItemMap unique = player->GetInventory();
            if (unique.find(lastItem) != unique.end()) {
                auto& unenchanted = unique.at(lastItem);
                Count num = unenchanted.first;
                if (num > 0) {
                    logger::debug("You have {} {}'s. The following cannot be enchanted (this should always include the item that was just enchanted):", num, lastItem->GetName());
                    auto entryData = unenchanted.second.get();
                    int remaining = num;
                    if (entryData != NULL) {
                        auto extraLists = entryData->extraLists;
                        if (extraLists != NULL) {
                            for (auto subgroup : *extraLists) {
                                remaining -= subgroup->GetCount();
                                logger::debug("    {} items cannot be enchanted because of this extra data:", subgroup->GetCount());
                                for (auto& xData : *subgroup) {
                                    auto xType = xData.GetType();
                                    logger::debug("        [{}]: {}", ExtraDataTypeToString(xType), ExtraDataTypeToInfo(xType));
                                }
                            }
                        }
                    }
                    logger::debug("The remaining {} items can be enchanted.", remaining);
                }
            }
			int validSouls = currentPlayerInventory.soulGems.getItem(lastSoul);
			int validItems = currentPlayerInventory.unenchanted.getItem(lastItem);
			auto maxRepeats = std::min(validSouls, validItems);
            logger::debug("You have {} soul gems of the right appropriate size, resulting in {} possible repeats.",
                          validSouls, maxRepeats);

			auto possibleRepeats = currentPlayerInventory.soulGemCount.at(static_cast<Count>(lastSoul)).GetBestVector(maxRepeats).first;

			if (possibleRepeats < maxRepeats) {
                logger::debug("Only {} of the {} soul gems can be used for bulk enchanting.", possibleRepeats, maxRepeats);
                logger::debug("  1.Reusable soul gems (e.g. Azura's Star) are emptied instead of being removed.");
				logger::debug("    Stacked groups can only be emptied as a group, so groups can only be used for bulk enchanting, if the number of enchanted items is large enough.");
				logger::debug("    Newly filled soul gems are generally not stacked and are only stacked once they are moved to chest and back.");
				logger::debug("    Note that directly enchanting a stacked reusable soul gem removes souls from the entire group (vanilla bug), so trigger the bulk enchanting with a normal soul of the same size to make use of the stacked souls.");
				logger::debug("    You cannot unstack the group without losing the souls. Dropping or removing a portion of the stacked group, removes the souls from that portion (vanilla bug).");
				logger::debug("  2.Reusable soul gems which are filled by default (e.g. Azura's Star in YASTM:https://www.nexusmods.com/skyrimspecialedition/mods/56144) cannot be used for bulk enchanting.");
				logger::debug("    Note that directly enchanting a stacked reusable soul with YASTM does work correctly and can trigger bulk enchanting.");
			}
			return possibleRepeats;
		} else {
            if (enchantedSubgroups.isSingular()) {
                logger::debug("Cannot use bulk enchanting, because enchanted item has the following extra data:");
                auto subgroup = enchantedSubgroups.getSingular();
                for (auto& xData : *subgroup) {
                    auto xType = xData.GetType();
                    if (xType != ExtraDataType::kTextDisplayData && xType != ExtraDataType::kEnchantment) {
                        logger::debug("    [{}]: {}", ExtraDataTypeToString(xType), ExtraDataTypeToInfo(xType));
                    }
                }
            } else {
                if (!usedSouls.isSingular()) {
                    logger::debug("Cannot use bulk enchanting, because used soul size could not be determined.");
				}
                if (!newEnchantments.isSingular()) {
                    logger::debug("Cannot use bulk enchanting, because used enchantment could not be determined.");
                }
				if (!removedItems.isSingular()) {
                    logger::debug("Cannot use bulk enchanting, because enchanted item could not be determined.");
				}
			}
			logger::trace("not singular:");
			lastSoul = SOUL_LEVEL::kNone;
			lastItem = NULL;
			lastEnchantment = "";
			return 0;
		}
	}

	Count RepeatEnchantment(StaticFunctionTag*, Actor* player, Count repeat) {
		logger::trace("RepeatEnchantment({}, {}, {}) x {}", lastItem->GetName(), lastEnchantment, static_cast<int>(lastSoul), repeat);
        logger::debug("Player decides to use bulk enchanting on {} {} times.", lastItem->GetName(), repeat);

		// Get updated soul gem information
		PlayerInventory currentPlayerInventory(player);
		auto soulGemInfo = currentPlayerInventory.soulGemCount.at(static_cast<Count>(lastSoul)).GetBestVector(repeat);
		if (soulGemInfo.first < repeat) {
			logger::error("Trying to repeat ({}) more often than there are valid soul gems ({}).", repeat, soulGemInfo.first);
			logger::info("    This may be caused by your soul gems being removed from the outside while enchanting.");
			repeat = soulGemInfo.first;
		}


		// Find newly enchanted item
		// This may not find the exact item that was enchanted, but it will find one that is equal
		// SubgroupIsValidForBulk ensures the only allowed extra datas are Name and Enchantment
		// GetEnchantmentKey ensures these extra datas are the same
		// If the newly enchanted item has the same name and enchantments as an existing one,
		// the newly enchanted item will not stack with it until it is removed and added again.
		// Bulk enchanting may pick the existing item instead of the newly enchanted one,
		// as they are the same and cannot be distinguished. As a result it will also
		// not be noticeable.
		auto unique = player->GetInventory();
		bool foundEnchantment = false;
		if (unique.contains(lastItem)) {
			Count num = unique.at(lastItem).first;
			auto entryData = unique.at(lastItem).second.get();
			if (entryData != NULL) {
				int remaining = num;
				auto extraLists = entryData->extraLists;
				if (extraLists != NULL) {
					for (auto subgroup : *extraLists) {
						remaining -= subgroup->GetCount();
						if (SubgroupIsValidForBulk(subgroup)) {
							auto enchKey = GetEnchantmentKey(subgroup);
							if (enchKey.compare(lastEnchantment) == 0) {
								foundEnchantment = true;
								auto xCount = subgroup->GetByType<ExtraCount>();
								if (!xCount) {
									xCount = new ExtraCount(1);
									subgroup->Add(xCount);
								}
								xCount->count += repeat;
								break;
							}
						}
					}
				}
			}
		}
		if (!foundEnchantment) {
			logger::error("The enchanted item was not found. Cannot bulk enchant.");
			logger::info("    This may be caused by our weapons or armor being removed from the outside while enchanting.");
			return 0;
		}

		// This function already considers xp multipliers (e.g. Mage Stone) and the skill settings (Skill Use Mult)
		// The xp for every enchantment is 1 in vanilla, so it needs to be replaced by repeat
		PlayerCharacter::GetSingleton()->AddSkillExperience(ActorValue::kEnchanting, repeat);


		// Use soul gems
		Count remainingSouls = repeat;

		// Use grouped && reusable soul gems
		std::vector<ExtraDataList*> groupedSoulGemOrder = soulGemInfo.second;
		for (auto subgroup : groupedSoulGemOrder) {
			auto extraSoul = SubgroupGetSoul(subgroup);
			if (extraSoul == NULL) {
				logger::error("Soul gem is already empty.");
			} else {
				extraSoul->soul = SOUL_LEVEL::kNone;
				remainingSouls -= subgroup->GetCount();
			}
		}

		if (remainingSouls < 0) {
			logger::error("Too many soul gems have been removed.");
		}

		// Use flexible soul gems
		// These soul gems can be removed one by one, as they are either not reusable or not grouped
		// While these reusable groups can still be encountered in the loop, the optimal groups have already been used
		// and the remaining ones are too large to be used.
		for (auto const& [key, val] : unique) {
			Count num = val.first;
			if (num > 0) {
				if (key->formType == FormType::SoulGem) {
					if (remainingSouls > 0) {
						auto entryData = val.second.get();
						TESSoulGem* soulGem = static_cast<TESSoulGem*>(key);
						DebugHelper::LogItem(soulGem, num);
						int remaining = num;
						if (entryData != NULL) {
							auto extraLists = entryData->extraLists;
							if (extraLists != NULL) {
								for (auto subgroup : *extraLists) {
									remaining -= subgroup->GetCount();
									if (subgroup->GetSoulLevel() == lastSoul) {
										Count remove = std::min(subgroup->GetCount(), remainingSouls);
										if (IsReusable(soulGem)) {
											// if the soul gem is reusable, set the soul level to 0 in the extra data
											if (remove < subgroup->GetCount()) {
												// Cannot set soul for only a subset of the subgroup, continue with next subgroup
											} else {
												// Remove soul from subgroup
												// This should usually not happen, as all possible reusable groups have already been used and the
												// remaining ones should be too large.
												auto extraSoul = SubgroupGetSoul(subgroup);
												if (extraSoul == NULL) {
													logger::error("Soul gem is already empty.");
												} else {
													extraSoul->soul = SOUL_LEVEL::kNone;
													remainingSouls -= remove;
												}
											}
										} else {
											// These are not reusable and can just be removed
											// The RemoveItem function works with a subgroup argument to remove items from a specific subgroup (even partially)
											player->RemoveItem(key, remove, ITEM_REMOVE_REASON::kRemove, subgroup, nullptr);
											remainingSouls -= remove;
										}
										
									}
								}
							}
						}
						if (remaining > 0) {
							if (soulGem->GetContainedSoul() == lastSoul) {
								Count remove = std::min(remaining, remainingSouls);
								if (IsReusable(soulGem)) {
									// If the soul gem is reusable and has no extra data it's just an infinitely full soul gem
									// Ignore, these soul gems are not supported for bulk enchanting and there should be enough left that are supported
								} else {
									// These are the most normal soul gems that can just be removed
									player->RemoveItem(key, remove, ITEM_REMOVE_REASON::kRemove, nullptr, nullptr);
									remainingSouls -= remove;
								}
							}
						}
					} else {
						break;
					}
				}
			}
		}
		if (remainingSouls > 0) {
			logger::error("Not enough soul gems could be removed.");
		}
		// Refresh the enchanting UI
		// This updates available items and soul gems and updates the xp bar
		// The menu visibly closes and opens for a moment
		UIMessageQueue::GetSingleton()->AddMessage(CraftingMenu::MENU_NAME, RE::UI_MESSAGE_TYPE::kHide, nullptr);
		UIMessageQueue::GetSingleton()->AddMessage(CraftingMenu::MENU_NAME, RE::UI_MESSAGE_TYPE::kShow, nullptr);
		lastPlayerInventory->update(player);
        return repeat;
	}

	void  ConfigPlugin(StaticFunctionTag*, Count logLevel) {
		auto log = spdlog::default_logger().get();

		auto newLogLevel = spdlog::level::level_enum::info;
		std::string newLogLevelName = "info";
		if (logLevel == 0) {
			newLogLevel = spdlog::level::level_enum::trace;
			newLogLevelName = "trace";
		} else if (logLevel == 1) {
			newLogLevel = spdlog::level::level_enum::debug;
			newLogLevelName = "debug";
		} else if (logLevel == 2) {
			newLogLevel = spdlog::level::level_enum::info;
			newLogLevelName = "info";
		} else if (logLevel == 3) {
			newLogLevel = spdlog::level::level_enum::warn;
			newLogLevelName = "warn";
		} else if (logLevel == 4) {
			newLogLevel = spdlog::level::level_enum::err;
			newLogLevelName = "err";
		} else if (logLevel == 5) {
			newLogLevel = spdlog::level::level_enum::critical;
			newLogLevelName = "critical";
		} else if (logLevel == 6) {
			newLogLevel = spdlog::level::level_enum::off;
			newLogLevelName = "off";
		}
		log->set_level(spdlog::level::level_enum::info);
		log->flush_on(spdlog::level::level_enum::info);
		logger::info("Setting log level to \"{}\".", newLogLevelName);
		log->set_level(newLogLevel);
		log->flush_on(newLogLevel);

	}

	bool RegisterFuncs(BSScript::IVirtualMachine* vm) {
		vm->RegisterFunction("OnStartEnchanting", "JBulkR_NativeFunctions", BulkEnchanting::OnStartEnchanting);
		vm->RegisterFunction("OnEndEnchanting", "JBulkR_NativeFunctions", BulkEnchanting::OnEndEnchanting);
		vm->RegisterFunction("OnItemEnchanted", "JBulkR_NativeFunctions", BulkEnchanting::OnItemEnchanted);
		vm->RegisterFunction("RepeatEnchantment", "JBulkR_NativeFunctions", BulkEnchanting::RepeatEnchantment);
		vm->RegisterFunction("ConfigPlugin", "JBulkR_NativeFunctions", BulkEnchanting::ConfigPlugin);
		return true;
	}
}


