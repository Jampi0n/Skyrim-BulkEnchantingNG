#include "BulkEnchanting.h"

namespace BulkEnchanting {

	using Count = int32_t;
	using InventoryItemMap = std::map<TESBoundObject*, std::pair<Count, std::unique_ptr<InventoryEntryData>>>;

	bool IsEnchanted(TESBoundObject* item) {
		if (item->formType == FormType::Armor) {
			auto armor = static_cast<TESObjectARMO*>(item);
			return armor->formEnchanting != NULL;
		} else if (item->formType == FormType::Weapon) {
			auto weapon = static_cast<TESObjectWEAP*>(item);
			return weapon->formEnchanting != NULL;
		}
		return false;
	}

	std::string GetEnchantmentKey(EnchantmentItem* enchantmentItem) {
		std::string s = "ench";
		for (auto effect : enchantmentItem->effects) {
			s += "_" + std::to_string(effect->baseEffect->GetFormID()) + "_" + effect->baseEffect->GetFullName() + "_" + std::to_string(effect->GetMagnitude()) + "_" + std::to_string(effect->GetDuration());
		}
		return s;
	}

	template<typename T>
	class CountMap {
	private:
		std::map<T, Count> _countMap;
		T def;
	public:
		void modItem(T item, Count num) {
			if (num == 0) {
				return;
			}
			auto it = _countMap.find(item);
			if (it == _countMap.end()) {
				_countMap.insert(std::pair<T, Count>(item, num));
			} else {
				Count newNum = _countMap.at(item) + num;
				_countMap.erase(item);
				if (newNum != 0) {
					_countMap.insert(std::pair<T, Count>(item, newNum));
				}
			}
		}

		Count getItem(T item) {
			auto it = _countMap.find(item);
			if (it == _countMap.end()) {
				return 0;
			} else {
				return _countMap.at(item);
			}
		}

		bool hasItem(T item) {
			return getItem(item) > 0;
		}

		CountMap<T> mul(Count factor) {
			CountMap<T> newMap;
			if (factor != 0) {
				for (auto const& [key, val] : _countMap) {
					newMap.modItem(key, val * factor);
				}
			}
			return newMap;
		}

		CountMap<T> add(CountMap<T>* other) {
			CountMap<T> newMap;
			for (auto const& [key, val] : _countMap) {
				newMap.modItem(key, val);
			}
			for (auto const& [key, val] : other->_countMap) {
				newMap.modItem(key, val);
			}
			return newMap;
		}

		CountMap<T> sub(CountMap<T>* other) {
			return add(&other->mul(-1));
		}

		std::map< T, Count>* getMap() {
			return &_countMap;
		}

		void reset() {
			_countMap.clear();
		}
		bool isSingular() {
			bool singular = _countMap.size() == 1;
			if (singular) {
				for (auto const& [key, val] : _countMap) {
					if (val == 1) {
						return true;
					}
					return false;
				}
			}
			return false;
		}

		T getSingular() {
			bool singular = _countMap.size() == 1;
			if (singular) {
				for (auto const& [key, val] : _countMap) {
					if (val == 1) {
						return key;
					}
					return def;
				}
			}
			return def;
		}
	};

	class PlayerInventory {
	public:
		CountMap<TESBoundObject*> unenchanted;
		CountMap<std::string> enchantments;
		CountMap<SOUL_LEVEL> soulGems;
	private:

		void AddSoulSize(SOUL_LEVEL size, Count num) {
			soulGems.modItem(size, num);
			logger::info("AddSoulSize({},{})", std::to_string(static_cast<int>(size)), std::to_string(num));
		}

		void AddUnenchanted(TESBoundObject* item, Count num) {
			unenchanted.modItem(item, num);
			logger::info("AddUnenchanted({},{})", item->GetName(), std::to_string(num));
		}

		void AddEnchantment(std::string enchKey, Count num) {
			enchantments.modItem(enchKey, num);
			logger::info("AddEnchantment({},{})", enchKey, std::to_string(num));
		}

	public:
		void update(Actor* player) {
			unenchanted.reset();
			enchantments.reset();
			soulGems.reset();
			InventoryItemMap unique = player->GetInventory();
			for (auto const& [key, val] : unique) {
				Count num = val.first;
				if (num > 0) {
					auto entryData = val.second.get();
					if (key->formType == FormType::SoulGem) {
						TESSoulGem* soulGem = static_cast<TESSoulGem*>(key);

						std::stringstream stream;
						stream << std::hex << soulGem->GetFormID();
						std::string hexId(stream.str());

						logger::info("[{}] {} x {}", hexId, soulGem->GetName(), std::to_string(num));
						if (entryData != NULL) {
							logger::info("entryData found");
							int remaining = num;

							logger::info("{}", std::to_string(static_cast<int>(entryData->GetSoulLevel())));
							auto extraLists = entryData->extraLists;
							if (extraLists != NULL) {
								logger::info("Add list data");
								for (auto extra : *extraLists) {
									logger::info("{}", std::to_string(static_cast<int>(extra->GetSoulLevel())));
									AddSoulSize(extra->GetSoulLevel(), extra->GetCount());
									remaining -= extra->GetCount();
								}
							} else {
								logger::info("Add singular data");
								AddSoulSize(entryData->GetSoulLevel(), 1);
								remaining--;
							}
							if (remaining > 0) {
								logger::info("Add remaining default");
								AddSoulSize(soulGem->GetContainedSoul(), remaining);
							}
						} else {
							logger::info("no entry data found");
							logger::info("Add all default");
							AddSoulSize(soulGem->GetContainedSoul(), num);
						}


					} else if (key->formType == FormType::Armor || key->formType == FormType::Weapon) {
						std::stringstream stream;
						stream << std::hex << key->GetFormID();
						std::string hexId(stream.str());

						logger::info("[{}] {} x {}", hexId, key->GetName(), std::to_string(num));

						if (!IsEnchanted(key)) {
							if (entryData != NULL) {
								logger::info("entryData found");
								int remaining = num;
								auto extraLists = entryData->extraLists;
								if (extraLists != NULL) {
									logger::info("Add list data");
									for (auto extra : *extraLists) {
										auto extraEnch = extra->GetByType(ExtraDataType::kEnchantment);
										bool enchanted = extraEnch != NULL;
										logger::info("extra: {} x {}", std::to_string(enchanted), std::to_string(extra->GetCount()));
										remaining -= extra->GetCount();
										if (enchanted) {
											auto ench = static_cast<ExtraEnchantment*>(extraEnch);
											auto enchKey = GetEnchantmentKey(ench->enchantment);
											AddEnchantment(enchKey, extra->GetCount());
										} else {
											logger::info("Add unenchanted list entry");
											// unenchanted but other extra data
											//AddUnenchanted(key, extra->GetCount());
										}
									}
								} else {
									logger::info("Add singular data");
									// unenchanted but other extra data
									//AddUnenchanted(key, 1);
									remaining--;
								}
								if (remaining > 0) {
									logger::info("Add remaining default");
									AddUnenchanted(key, remaining);
								}
							} else {
								AddUnenchanted(key, num);
							}
						}
					}
				}
			}
			logger::info("Souls:");
			for (auto const& [key, val] : *soulGems.getMap()) {
				logger::info("[{}] x {}", std::to_string(static_cast<int>(key)), std::to_string(val));
			}
			logger::info("Enchantments:");
			for (auto const& [key, val] : *enchantments.getMap()) {
				logger::info("[{}] x {}", key, std::to_string(val));
			}
			logger::info("Unenchanted:");
			for (auto const& [key, val] : *unenchanted.getMap()) {
				logger::info("[{}] x {}", key->GetName(), std::to_string(val));
			}
		}
		PlayerInventory(Actor* player) {
			update(player);
		}
	};

	PlayerInventory* lastPlayerInventory;
	TESBoundObject* lastItem;
	std::string lastEnchantment;
	SOUL_LEVEL lastSoul;


	Count _starting = 0;
	Count _crafting = 0;

	void FreeData() {
		logger::info("------------------------------------- Free");
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



	void PrintInventory(Actor* player) {
		PlayerInventory inv(player);
	}



	void OnStartEnchanting(StaticFunctionTag*, Actor* player) {
		logger::info("start");
		DataMenuOpen();
		if (lastPlayerInventory == NULL) {
			lastPlayerInventory = new PlayerInventory(player);
		} else {
			lastPlayerInventory->update(player);
		}
		lastItem = NULL;
		lastEnchantment = "";
		lastSoul = SOUL_LEVEL::kNone;
		//PrintInventory(player);
	}

	void OnEndEnchanting(StaticFunctionTag*, Actor* player) {
		logger::info("end");
		DataMenuClose();
	}

	Count OnItemEnchanted(StaticFunctionTag*, Actor* player) {
		DataCraftStart();
		logger::info("--------------------- craft");
		PlayerInventory currentPlayerInventory(player);
		auto usedSouls = lastPlayerInventory->soulGems.sub(&currentPlayerInventory.soulGems);
		auto newEnchantments = currentPlayerInventory.enchantments.sub(&lastPlayerInventory->enchantments);
		auto removedItems = lastPlayerInventory->unenchanted.sub(&currentPlayerInventory.unenchanted);

		logger::info("..4");
		lastPlayerInventory->update(player);
		DataCraftEnd();

		logger::info("Delta");
		logger::info("Souls:");
		for (auto const& [key, val] : *usedSouls.getMap()) {
			logger::info("[{}] x {}", std::to_string(static_cast<int>(key)), std::to_string(val));
		}
		logger::info("Enchantments:");
		for (auto const& [key, val] : *newEnchantments.getMap()) {
			logger::info("[{}] x {}", key, std::to_string(val));
		}
		logger::info("Unenchanted:");
		for (auto const& [key, val] : *removedItems.getMap()) {
			logger::info("[{}] x {}", key->GetName(), std::to_string(val));
		}


		if (usedSouls.isSingular() && newEnchantments.isSingular() && removedItems.isSingular()) {
			logger::info("singular:");
			lastSoul = usedSouls.getSingular();
			lastItem = removedItems.getSingular();
			lastEnchantment = newEnchantments.getSingular();

			int validSouls = currentPlayerInventory.soulGems.getItem(lastSoul);
			int validItems = currentPlayerInventory.unenchanted.getItem(lastItem);

			auto tmp =  std::min(validSouls, validItems);
			return tmp;
		} else {
			logger::info("not singular:");
			lastSoul = SOUL_LEVEL::kNone;
			lastItem = NULL;
			lastEnchantment = "";
			return 0;
		}
	}

	void HandleSoulStar(Actor* player, TESSoulGem* soulGem) {
		auto formID = soulGem->GetFormID();
		if (formID == 0x00063B27 || formID == 0x00063B29) {
			player->GetContainer()->AddObjectToContainer(soulGem, 1, player);
		} 
	}

	void RepeatEnchantment(StaticFunctionTag*, Actor* player, Count repeat) {
		logger::info("--------------------- repeat: {}", std::to_string(repeat));
		auto unique = player->GetInventory();

		if(unique.contains(lastItem))
		{
			Count num = unique.at(lastItem).first;
			auto entryData = unique.at(lastItem).second.get();
			if (entryData != NULL) {
				logger::info("entryData found");
				int remaining = num;
				auto extraLists = entryData->extraLists;
				if (extraLists != NULL) {
					logger::info("Add list data");
					for (auto extra : *extraLists) {
						auto extraEnch = extra->GetByType(ExtraDataType::kEnchantment);
						bool enchanted = extraEnch != NULL;
						logger::info("extra: {} x {}", std::to_string(enchanted), std::to_string(extra->GetCount()));
						remaining -= extra->GetCount();
						if (enchanted) {
							auto ench = static_cast<ExtraEnchantment*>(extraEnch);
							auto enchKey = GetEnchantmentKey(ench->enchantment);
							if (enchKey.compare(lastEnchantment) == 0) {
								logger::info("Found same enchantment");
								auto xCount = extra->GetByType<ExtraCount>();
								if (!xCount) {
									xCount = new ExtraCount(1);
									extra->Add(xCount);
								}
								xCount->count += repeat;
								break;
							}
						}
					}
				}
			}
		} else {
			return;
		}

		Count remainingSouls = repeat;
		for (auto const& [key, val] : unique) {
			Count num = val.first;
			if (num > 0) {
				auto entryData = val.second.get();
				if (key->formType == FormType::SoulGem) {
					if (remainingSouls > 0) {
						TESSoulGem* soulGem = static_cast<TESSoulGem*>(key);

						std::stringstream stream;
						stream << std::hex << soulGem->GetFormID();
						std::string hexId(stream.str());

						logger::info("[{}] {} x {}", hexId, soulGem->GetName(), std::to_string(num));
						if (entryData != NULL) {
							logger::info("entryData found");
							int remaining = num;

							logger::info("{}", std::to_string(static_cast<int>(entryData->GetSoulLevel())));
							auto extraLists = entryData->extraLists;
							if (extraLists != NULL) {
								logger::info("Add list data");
								for (auto extra : *extraLists) {
									logger::info("{}", std::to_string(static_cast<int>(extra->GetSoulLevel())));
									remaining -= extra->GetCount();
									if (extra->GetSoulLevel() == lastSoul) {
										logger::info("Remove list soul gems");
										Count remove = std::min(extra->GetCount(), remainingSouls);
										player->RemoveItem(key, remove, ITEM_REMOVE_REASON::kRemove, extra, nullptr);
										HandleSoulStar(player, soulGem);
										remainingSouls -= remove;
									}
								}
							} else {
								logger::info("Remove singular soul gem");
								if (entryData->GetSoulLevel() == lastSoul) {
									player->RemoveItem(key, 1, ITEM_REMOVE_REASON::kRemove, nullptr, nullptr);
									HandleSoulStar(player, soulGem);
									remainingSouls--;
								}
								remaining--;
							}
							if (remaining > 0) {
								if (soulGem->GetContainedSoul() == lastSoul) {
									logger::info("Remove remaining soul gems");
									Count remove = std::min(remaining, remainingSouls);
									player->RemoveItem(key, remove, ITEM_REMOVE_REASON::kRemove, nullptr, nullptr);
									HandleSoulStar(player, soulGem);
									remainingSouls -= remove;
								}
							}
						} else {
							logger::info("no entry data found");
							logger::info("Remove default soul gems");
							if (soulGem->GetContainedSoul() == lastSoul) {
								Count remove = std::min(num, remainingSouls);
								player->RemoveItem(key, remove, ITEM_REMOVE_REASON::kRemove, nullptr, nullptr);
								HandleSoulStar(player, soulGem);
								remainingSouls -= remove;
							}
						}
					}
				}
			}
		}
	}

	bool RegisterFuncs(BSScript::IVirtualMachine* vm) {
		vm->RegisterFunction("OnStartEnchanting", "JBulk_NativeFunctions", BulkEnchanting::OnStartEnchanting);
		vm->RegisterFunction("OnEndEnchanting", "JBulk_NativeFunctions", BulkEnchanting::OnEndEnchanting);
		vm->RegisterFunction("OnItemEnchanted", "JBulk_NativeFunctions", BulkEnchanting::OnItemEnchanted);
		vm->RegisterFunction("RepeatEnchantment", "JBulk_NativeFunctions", BulkEnchanting::RepeatEnchantment);
		return true;
	}
}


