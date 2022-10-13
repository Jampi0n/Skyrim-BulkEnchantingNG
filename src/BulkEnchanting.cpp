#include "BulkEnchanting.h"

namespace BulkEnchanting {


	std::string ExtraDataTypeToString(ExtraDataType xType) {
		if (xType == ExtraDataType::kNone) { return "0x00"; }
		if (xType == ExtraDataType::kHavok) { return "0x01 - ExtraHavok"; }
		if (xType == ExtraDataType::kCell3D) { return "0x02 - ExtraCell3D"; }
		if (xType == ExtraDataType::kCellWaterType) { return "0x03 - ExtraCellWaterType"; }
		if (xType == ExtraDataType::kRegionList) { return "0x04 - ExtraRegionList"; }
		if (xType == ExtraDataType::kSeenData) { return "0x05 - ExtraSeenData"; }
		if (xType == ExtraDataType::kEditorID) { return "0x06 - ExtraEditorID"; }
		if (xType == ExtraDataType::kCellMusicType) { return "0x07 - ExtraCellMusicType"; }
		if (xType == ExtraDataType::kCellSkyRegion) { return "0x08 - ExtraCellSkyRegion"; }
		if (xType == ExtraDataType::kProcessMiddleLow) { return "0x09 - ExtraProcessMiddleLow"; }
		if (xType == ExtraDataType::kDetachTime) { return "0x0A - ExtraDetachTime"; }
		if (xType == ExtraDataType::kPersistentCell) { return "0x0B - ExtraPersistentCell"; }
		if (xType == ExtraDataType::kUnk0C) { return "0x0C"; }
		if (xType == ExtraDataType::kAction) { return "0x0D - ExtraAction"; }
		if (xType == ExtraDataType::kStartingPosition) { return "0x0E - ExtraStartingPosition"; }
		if (xType == ExtraDataType::kUnk0F) { return "0x0F"; }
		if (xType == ExtraDataType::kAnimGraphManager) { return "0x10 - ExtraAnimGraphManager"; }
		if (xType == ExtraDataType::kBiped) { return "0x11 - ExtraBiped"; }
		if (xType == ExtraDataType::kUsedMarkers) { return "0x12 - ExtraUsedMarkers"; }
		if (xType == ExtraDataType::kDistantData) { return "0x13 - ExtraDistantData"; }
		if (xType == ExtraDataType::kRagDollData) { return "0x14 - ExtraRagDollData"; }
		if (xType == ExtraDataType::kContainerChanges) { return "0x15 - ExtraContainerChanges"; }
		if (xType == ExtraDataType::kWorn) { return "0x16 - ExtraWorn"; }
		if (xType == ExtraDataType::kWornLeft) { return "0x17 - ExtraWornLeft"; }
		if (xType == ExtraDataType::kPackageStartLocation) { return "0x18 - ExtraPackageStartLocation"; }
		if (xType == ExtraDataType::kPackage) { return "0x19 - ExtraPackage"; }
		if (xType == ExtraDataType::kTresPassPackage) { return "0x1A - ExtraTresPassPackage"; }
		if (xType == ExtraDataType::kRunOncePacks) { return "0x1B - ExtraRunOncePacks"; }
		if (xType == ExtraDataType::kReferenceHandle) { return "0x1C - ExtraReferenceHandle"; }
		if (xType == ExtraDataType::kFollower) { return "0x1D - ExtraFollower"; }
		if (xType == ExtraDataType::kLevCreaModifier) { return "0x1E - ExtraLevCreaModifier"; }
		if (xType == ExtraDataType::kGhost) { return "0x1F - ExtraGhost"; }
		if (xType == ExtraDataType::kOriginalReference) { return "0x20 - ExtraOriginalReference"; }
		if (xType == ExtraDataType::kOwnership) { return "0x21 - ExtraOwnership"; }
		if (xType == ExtraDataType::kGlobal) { return "0x22 - ExtraGlobal"; }
		if (xType == ExtraDataType::kRank) { return "0x23 - ExtraRank"; }
		if (xType == ExtraDataType::kCount) { return "0x24 - ExtraCount"; }
		if (xType == ExtraDataType::kHealth) { return "0x25 - ExtraHealth"; }
		if (xType == ExtraDataType::kUnk26) { return "0x26"; }
		if (xType == ExtraDataType::kTimeLeft) { return "0x27 - ExtraTimeLeft"; }
		if (xType == ExtraDataType::kCharge) { return "0x28 - ExtraCharge"; }
		if (xType == ExtraDataType::kLight) { return "0x29 - ExtraLight"; }
		if (xType == ExtraDataType::kLock) { return "0x2A - ExtraLock"; }
		if (xType == ExtraDataType::kTeleport) { return "0x2B - ExtraTeleport"; }
		if (xType == ExtraDataType::kMapMarker) { return "0x2C - ExtraMapMarker"; }
		if (xType == ExtraDataType::kLeveledCreature) { return "0x2D - ExtraLeveledCreature"; }
		if (xType == ExtraDataType::kLeveledItem) { return "0x2E - ExtraLeveledItem"; }
		if (xType == ExtraDataType::kScale) { return "0x2F - ExtraScale"; }
		if (xType == ExtraDataType::kMissingLinkedRefIDs) { return "0x30 - ExtraMissingLinkedRefIDs"; }
		if (xType == ExtraDataType::kMagicCaster) { return "0x31 - ExtraMagicCaster"; }
		if (xType == ExtraDataType::kNonActorMagicTarget) { return "0x32 - NonActorMagicTarget"; }
		if (xType == ExtraDataType::kUnk33) { return "0x33"; }
		if (xType == ExtraDataType::kPlayerCrimeList) { return "0x34 - ExtraPlayerCrimeList"; }
		if (xType == ExtraDataType::kUnk35) { return "0x35"; }
		if (xType == ExtraDataType::kEnableStateParent) { return "0x36 - ExtraEnableStateParent"; }
		if (xType == ExtraDataType::kEnableStateChildren) { return "0x37 - ExtraEnableStateChildren"; }
		if (xType == ExtraDataType::kItemDropper) { return "0x38 - ExtraItemDropper"; }
		if (xType == ExtraDataType::kDroppedItemList) { return "0x39 - ExtraDroppedItemList"; }
		if (xType == ExtraDataType::kRandomTeleportMarker) { return "0x3A - ExtraRandomTeleportMarker"; }
		if (xType == ExtraDataType::kUnk3B) { return "0x3B"; }
		if (xType == ExtraDataType::kSavedHavokData) { return "0x3C - ExtraSavedHavokData"; }
		if (xType == ExtraDataType::kCannotWear) { return "0x3D - ExtraCannotWear"; }
		if (xType == ExtraDataType::kPoison) { return "0x3E - ExtraPoison"; }
		if (xType == ExtraDataType::kMagicLight) { return "0x3F - ExtraMagicLight"; }
		if (xType == ExtraDataType::kLastFinishedSequence) { return "0x40 - ExtraLastFinishedSequence"; }
		if (xType == ExtraDataType::kSavedAnimation) { return "0x41 - ExtraSavedAnimation"; }
		if (xType == ExtraDataType::kNorthRotation) { return "0x42 - ExtraNorthRotation"; }
		if (xType == ExtraDataType::kSpawnContainer) { return "0x43 - ExtraSpawnContainer"; }
		if (xType == ExtraDataType::kFriendHits) { return "0x44 - ExtraFriendHits"; }
		if (xType == ExtraDataType::kHeadingTarget) { return "0x45 - ExtraHeadingTarget"; }
		if (xType == ExtraDataType::kUnk46) { return "0x46"; }
		if (xType == ExtraDataType::kRefractionProperty) { return "0x47 - ExtraRefractionProperty"; }
		if (xType == ExtraDataType::kStartingWorldOrCell) { return "0x48 - ExtraStartingWorldOrCell"; }
		if (xType == ExtraDataType::kHotkey) { return "0x49 - ExtraHotkey"; }
		if (xType == ExtraDataType::kEditorRef3DData) { return "0x4A - ExtraEditorRef3DData"; }
		if (xType == ExtraDataType::kEditorRefMoveData) { return "0x4B - ExtraEditorRefMoveData"; }
		if (xType == ExtraDataType::kInfoGeneralTopic) { return "0x4C - ExtraInfoGeneralTopic"; }
		if (xType == ExtraDataType::kHasNoRumors) { return "0x4D - ExtraHasNoRumors"; }
		if (xType == ExtraDataType::kSound) { return "0x4E - ExtraSound"; }
		if (xType == ExtraDataType::kTerminalState) { return "0x4F - ExtraTerminalState"; }
		if (xType == ExtraDataType::kLinkedRef) { return "0x50 - ExtraLinkedRef"; }
		if (xType == ExtraDataType::kLinkedRefChildren) { return "0x51 - ExtraLinkedRefChildren"; }
		if (xType == ExtraDataType::kActivateRef) { return "0x52 - ExtraActivateRef"; }
		if (xType == ExtraDataType::kActivateRefChildren) { return "0x53 - ExtraActivateRefChildren"; }
		if (xType == ExtraDataType::kCanTalkToPlayer) { return "0x54 - ExtraCanTalkToPlayer"; }
		if (xType == ExtraDataType::kObjectHealth) { return "0x55 - ExtraObjectHealth"; }
		if (xType == ExtraDataType::kCellImageSpace) { return "0x56 - ExtraCellImageSpace"; }
		if (xType == ExtraDataType::kNavMeshPortal) { return "0x57 - ExtraNavMeshPortal"; }
		if (xType == ExtraDataType::kModelSwap) { return "0x58 - ExtraModelSwap"; }
		if (xType == ExtraDataType::kRadius) { return "0x59 - ExtraRadius"; }
		if (xType == ExtraDataType::kUnk5A) { return "0x5A"; }
		if (xType == ExtraDataType::kFactionChanges) { return "0x5B - ExtraFactionChanges"; }
		if (xType == ExtraDataType::kDismemberedLimbs) { return "0x5C - ExtraDismemberedLimbs"; }
		if (xType == ExtraDataType::kActorCause) { return "0x5D - ExtraActorCause"; }
		if (xType == ExtraDataType::kMultiBound) { return "0x5E - ExtraMultiBound"; }
		if (xType == ExtraDataType::kMultiBoundMarkerData) { return "0x5F - MultiBoundMarkerData"; }
		if (xType == ExtraDataType::kMultiBoundRef) { return "0x60 - ExtraMultiBoundRef"; }
		if (xType == ExtraDataType::kReflectedRefs) { return "0x61 - ExtraReflectedRefs"; }
		if (xType == ExtraDataType::kReflectorRefs) { return "0x62 - ExtraReflectorRefs"; }
		if (xType == ExtraDataType::kEmittanceSource) { return "0x63 - ExtraEmittanceSource"; }
		if (xType == ExtraDataType::kUnk64) { return "0x64"; }
		if (xType == ExtraDataType::kCombatStyle) { return "0x65 - ExtraCombatStyle"; }
		if (xType == ExtraDataType::kUnk66) { return "0x66"; }
		if (xType == ExtraDataType::kPrimitive) { return "0x67 - ExtraPrimitive"; }
		if (xType == ExtraDataType::kOpenCloseActivateRef) { return "0x68 - ExtraOpenCloseActivateRef"; }
		if (xType == ExtraDataType::kAnimNoteReceiver) { return "0x69 - ExtraAnimNoteReceiver"; }
		if (xType == ExtraDataType::kAmmo) { return "0x6A - ExtraAmmo"; }
		if (xType == ExtraDataType::kPatrolRefData) { return "0x6B - ExtraPatrolRefData"; }
		if (xType == ExtraDataType::kPackageData) { return "0x6C - ExtraPackageData"; }
		if (xType == ExtraDataType::kOcclusionShape) { return "0x6D - ExtraOcclusionShape"; }
		if (xType == ExtraDataType::kCollisionData) { return "0x6E - ExtraCollisionData"; }
		if (xType == ExtraDataType::kSayTopicInfoOnceADay) { return "0x6F - ExtraSayTopicInfoOnceADay"; }
		if (xType == ExtraDataType::kEncounterZone) { return "0x70 - ExtraEncounterZone"; }
		if (xType == ExtraDataType::kSayTopicInfo) { return "0x71 - ExtraSayToTopicInfo"; }
		if (xType == ExtraDataType::kOcclusionPlaneRefData) { return "0x72 - ExtraOcclusionPlaneRefData"; }
		if (xType == ExtraDataType::kPortalRefData) { return "0x73 - ExtraPortalRefData"; }
		if (xType == ExtraDataType::kPortal) { return "0x74 - ExtraPortal"; }
		if (xType == ExtraDataType::kRoom) { return "0x75 - ExtraRoom"; }
		if (xType == ExtraDataType::kHealthPerc) { return "0x76 - ExtraHealthPerc"; }
		if (xType == ExtraDataType::kRoomRefData) { return "0x77 - ExtraRoomRefData"; }
		if (xType == ExtraDataType::kGuardedRefData) { return "0x78 - ExtraGuardedRefData"; }
		if (xType == ExtraDataType::kCreatureAwakeSound) { return "0x79 - ExtraCreatureAwakeSound"; }
		if (xType == ExtraDataType::kUnk7A) { return "0x7A"; }
		if (xType == ExtraDataType::kHorse) { return "0x7B - ExtraHorse"; }
		if (xType == ExtraDataType::kIgnoredBySandbox) { return "0x7C - ExtraIgnoredBySandbox"; }
		if (xType == ExtraDataType::kCellAcousticSpace) { return "0x7D - ExtraCellAcousticSpace"; }
		if (xType == ExtraDataType::kReservedMarkers) { return "0x7E - ExtraReservedMarkers"; }
		if (xType == ExtraDataType::kWeaponIdleSound) { return "0x7F - ExtraWeaponIdleSound"; }
		if (xType == ExtraDataType::kWaterLightRefs) { return "0x80 - ExtraWaterLightRefs"; }
		if (xType == ExtraDataType::kLitWaterRefs) { return "0x81 - ExtraLitWaterRefs"; }
		if (xType == ExtraDataType::kWeaponAttackSound) { return "0x82 - ExtraWeaponAttackSound"; }
		if (xType == ExtraDataType::kActivateLoopSound) { return "0x83 - ExtraActivateLoopSound"; }
		if (xType == ExtraDataType::kPatrolRefInUseData) { return "0x84 - ExtraPatrolRefInUseData"; }
		if (xType == ExtraDataType::kAshPileRef) { return "0x85 - ExtraAshPileRef"; }
		if (xType == ExtraDataType::kCreatureMovementSound) { return "0x86 - ExtraCreatureMovementSound"; }
		if (xType == ExtraDataType::kFollowerSwimBreadcrumbs) { return "0x87 - ExtraFollowerSwimBreadcrumbs"; }
		if (xType == ExtraDataType::kAliasInstanceArray) { return "0x88 - ExtraAliasInstanceArray"; }
		if (xType == ExtraDataType::kLocation) { return "0x89 - ExtraLocation"; }
		if (xType == ExtraDataType::kUnk8A) { return "0x8A"; }
		if (xType == ExtraDataType::kLocationRefType) { return "0x8B - ExtraLocationRefType"; }
		if (xType == ExtraDataType::kPromotedRef) { return "0x8C - ExtraPromotedRef"; }
		if (xType == ExtraDataType::kAnimationSequencer) { return "0x8D - ExtraAnimationSequencer"; }
		if (xType == ExtraDataType::kOutfitItem) { return "0x8E - ExtraOutfitItem"; }
		if (xType == ExtraDataType::kUnk8F) { return "0x8F"; }
		if (xType == ExtraDataType::kLeveledItemBase) { return "0x90 - ExtraLeveledItemBase"; }
		if (xType == ExtraDataType::kLightData) { return "0x91 - ExtraLightData"; }
		if (xType == ExtraDataType::kSceneData) { return "0x92 - ExtraSceneData"; }
		if (xType == ExtraDataType::kBadPosition) { return "0x93 - ExtraBadPosition"; }
		if (xType == ExtraDataType::kHeadTrackingWeight) { return "0x94 - ExtraHeadTrackingWeight"; }
		if (xType == ExtraDataType::kFromAlias) { return "0x95 - ExtraFromAlias"; }
		if (xType == ExtraDataType::kShouldWear) { return "0x96 - ExtraShouldWear"; }
		if (xType == ExtraDataType::kFavorCost) { return "0x97 - ExtraFavorCost"; }
		if (xType == ExtraDataType::kAttachedArrows3D) { return "0x98 - ExtraAttachedArrows3D"; }
		if (xType == ExtraDataType::kTextDisplayData) { return "0x99 - ExtraTextDisplayData"; }
		if (xType == ExtraDataType::kAlphaCutoff) { return "0x9A - ExtraAlphaCutoff"; }
		if (xType == ExtraDataType::kEnchantment) { return "0x9B - ExtraEnchantment"; }
		if (xType == ExtraDataType::kSoul) { return "0x9C - ExtraSoul"; }
		if (xType == ExtraDataType::kForcedTarget) { return "0x9D - ExtraForcedTarget"; }
		if (xType == ExtraDataType::kUnk9E) { return "0x9E"; }
		if (xType == ExtraDataType::kUniqueID) { return "0x9F - ExtraUniqueID"; }
		if (xType == ExtraDataType::kFlags) { return "0xA0 - ExtraFlags"; }
		if (xType == ExtraDataType::kRefrPath) { return "0xA1 - ExtraRefrPath"; }
		if (xType == ExtraDataType::kDecalGroup) { return "0xA2 - ExtraDecalGroup"; }
		if (xType == ExtraDataType::kLockList) { return "0xA3 - ExtraLockList"; }
		if (xType == ExtraDataType::kForcedLandingMarker) { return "0xA4 - ExtraForcedLandingMarker"; }
		if (xType == ExtraDataType::kLargeRefOwnerCells) { return "0xA5 - ExtraLargeRefOwnerCells"; }
		if (xType == ExtraDataType::kCellWaterEnvMap) { return "0xA6 - ExtraCellWaterEnvMap"; }
		if (xType == ExtraDataType::kCellGrassData) { return "0xA7 - ExtraCellGrassData"; }
		if (xType == ExtraDataType::kTeleportName) { return "0xA8 - ExtraTeleportName"; }
		if (xType == ExtraDataType::kInteraction) { return "0xA9 - ExtraInteraction"; }
		if (xType == ExtraDataType::kWaterData) { return "0xAA - ExtraWaterData"; }
		if (xType == ExtraDataType::kWaterCurrentZoneData) { return "0xAB - ExtraWaterCurrentZoneData"; }
		if (xType == ExtraDataType::kAttachRef) { return "0xAC - ExtraAttachRef"; }
		if (xType == ExtraDataType::kAttachRefChildren) { return "0xAD - ExtraAttachRefChildren"; }
		if (xType == ExtraDataType::kGroupConstraint) { return "0xAE - ExtraGroupConstraint"; }
		if (xType == ExtraDataType::kScriptedAnimDependence) { return "0xAF - ExtraScriptedAnimDependence"; }
		if (xType == ExtraDataType::kCachedScale) { return "0xB0 - ExtraCachedScale"; }
		if (xType == ExtraDataType::kRaceData) { return "0xB1 - ExtraRaceData"; }
		if (xType == ExtraDataType::kGIDBuffer) { return "0xB2 - ExtraGIDBuffer"; }
		if (xType == ExtraDataType::kMissingRefIDs) { return "0xB3 - ExtraMissingRefIDs"; }
		if (xType == ExtraDataType::kUnkB4) { return "0xB4"; }
		if (xType == ExtraDataType::kResourcesPreload) { return "0xB5 - ExtraResourcesPreload"; }
		if (xType == ExtraDataType::kUnkB6) { return "0xB6"; }
		if (xType == ExtraDataType::kUnkB7) { return "0xB7"; }
		if (xType == ExtraDataType::kUnkB8) { return "0xB8"; }
		if (xType == ExtraDataType::kUnkB9) { return "0xB9"; }
		if (xType == ExtraDataType::kUnkBA) { return "0xBA"; }
		if (xType == ExtraDataType::kUnkBB) { return "0xBB"; }
		if (xType == ExtraDataType::kUnkBC) { return "0xBC"; }
		if (xType == ExtraDataType::kUnkBD) { return "0xBD"; }
		if (xType == ExtraDataType::kUnkBE) { return "0xBE"; }
		if (xType == ExtraDataType::kUnkBF) { return "0xBF"; }
		return "";
	}



	using Count = int32_t;
	using InventoryItemMap = std::map<TESBoundObject*, std::pair<Count, std::unique_ptr<InventoryEntryData>>>;

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

	std::string GetEnchantmentKey(EnchantmentItem* enchantmentItem) {
		/// <summary>
		/// Returns a unique string representation of the player enchantment.
		/// </summary>
		/// <param name="enchantmentItem"></param>
		/// <returns></returns>
		std::string s = "ench";
		for (auto effect : enchantmentItem->effects) {
			s += "_" + std::to_string(effect->baseEffect->GetFormID()) + "_" + effect->baseEffect->GetFullName() + "_" + std::to_string(effect->GetMagnitude()) + "_" + std::to_string(effect->GetDuration());
		}
		return s;
	}

	template<typename T>
	class CountMap {
		/// <summary>
		/// Stores counts for each keys.
		/// Compared to a regular map, it defaults to 0 if the key is not found and simplifies arithmetic operations between CountMaps.
		/// </summary>
		/// <typeparam name="T">Key type.</typeparam>
	private:
		std::map<T, Count> _countMap;
		T def;
	public:
		void modItem(T item, Count num) {
			/// <summary>
			/// Modifies the count of the key.
			/// </summary>
			/// <param name="item"></param>
			/// <param name="num"></param>
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
			/// <summary>
			/// Returns the count of the key.
			/// </summary>
			/// <param name="item"></param>
			/// <returns></returns>
			auto it = _countMap.find(item);
			if (it == _countMap.end()) {
				return 0;
			} else {
				return _countMap.at(item);
			}
		}

		bool hasItem(T item) {
			/// <summary>
			/// Returns true, if the key has a positive count.
			/// </summary>
			/// <param name="item"></param>
			/// <returns></returns>
			return getItem(item) > 0;
		}

		CountMap<T> mul(Count factor) {
			/// <summary>
			/// Returns a new CountMap with multiplied counts.
			/// </summary>
			/// <param name="factor"></param>
			/// <returns></returns>
			CountMap<T> newMap;
			if (factor != 0) {
				for (auto const& [key, val] : _countMap) {
					newMap.modItem(key, val * factor);
				}
			}
			return newMap;
		}

		CountMap<T> add(CountMap<T>* other) {
			/// <summary>
			/// Returns a new CountMap with added counts.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
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
			/// <summary>
			/// Returns a new CountMap with subtracted counts.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			return add(&other->mul(-1));
		}

		std::map< T, Count>* getMap() {
			/// <summary>
			/// Returns the underlying map to iterate over the entries.
			/// Keys with counts of 0 are never in the map.
			/// </summary>
			/// <returns></returns>
			return &_countMap;
		}

		void reset() {
			/// <summary>
			/// Removes all keys from the map.
			/// </summary>
			_countMap.clear();
		}
		bool isSingular() {
			/// <summary>
			/// Returns true, if the map contains only a single key with count 1.
			/// </summary>
			/// <returns></returns>
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
			/// <summary>
			/// If the map is singular, it returns the singular key.
			/// </summary>
			/// <returns></returns>
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
		CountMap<TESBoundObject*>	unenchanted;	// Unenchanted items without extra data
		CountMap<std::string>	   enchantments;	// Player made enchantments (extra data) of items with at most Enchantment and Name as extra data
		CountMap<SOUL_LEVEL>		   soulGems;	// Soul levels
	private:

		void AddSoulSize(SOUL_LEVEL size, Count num) {
			soulGems.modItem(size, num);
			logger::info("AddSoulSize({},{})", static_cast<int>(size), num);
		}

		void AddUnenchanted(TESBoundObject* item, Count num) {
			unenchanted.modItem(item, num);
			logger::info("AddUnenchanted({},{})", item->GetName(), num);
		}

		void AddEnchantment(std::string enchKey, Count num) {
			enchantments.modItem(enchKey, num);
			logger::info("AddEnchantment({},{})", enchKey, num);
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

						logger::info("[{}] {} x {}", hexId, soulGem->GetName(), num);
						if (entryData != NULL) {
							logger::info("entryData found x {}", entryData->countDelta);
							int remaining = num;

							logger::info("{}", static_cast<int>(entryData->GetSoulLevel()));
							auto extraLists = entryData->extraLists;
							if (extraLists != NULL) {
								logger::info("Add list data");
								for (auto subgroup : *extraLists) {
									logger::info("{}", static_cast<int>(subgroup->GetSoulLevel()));
									AddSoulSize(subgroup->GetSoulLevel(), subgroup->GetCount());
									remaining -= subgroup->GetCount();
								}
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

						logger::info("[{}] {} x {}", hexId, key->GetName(), num);

						if (!IsEnchanted(key)) { // base item must not be enchanted, so it can be enchanted by the player
							if (entryData != NULL) {
								logger::info("entryData found x {}", entryData->countDelta);
								int remaining = num;
								auto extraLists = entryData->extraLists;
								if (extraLists != NULL) {
									logger::info("Add list data");
									for (auto subgroup : *extraLists) {
										auto extraEnch = subgroup->GetByType(ExtraDataType::kEnchantment);
										bool enchanted = extraEnch != NULL;
										logger::info("extra: {} x {}", enchanted, subgroup->GetCount());
										remaining -= subgroup->GetCount();
										// must have kEnchantment extra data and optionally also kTextDisplayData
										// any other extra data is avoided, as these are the two extra datas that are added by enchanting
										if (enchanted) {
											Count numExtraData = 0;
											bool outerContinue = false;
											for (auto& xData : *subgroup) {
												auto xType = xData.GetType();
												if (xType != ExtraDataType::kTextDisplayData && xType != ExtraDataType::kEnchantment) {
													outerContinue = true;
													break;
												}
											}
											if (outerContinue) {
												continue;
											}
											auto ench = static_cast<ExtraEnchantment*>(extraEnch);
											auto enchKey = GetEnchantmentKey(ench->enchantment);
											AddEnchantment(enchKey, subgroup->GetCount());
										}
									}
								}
								if (remaining > 0) { // no extra data, add to unenchanted items
									AddUnenchanted(key, remaining);
								}
							} else { // no extra data, add to unenchanted items
								AddUnenchanted(key, num);
							}
						}
					}
				}
			}
			logger::info("Souls:");
			for (auto const& [key, val] : *soulGems.getMap()) {
				logger::info("[{}] x {}", static_cast<int>(key), val);
			}
			logger::info("Enchantments:");
			for (auto const& [key, val] : *enchantments.getMap()) {
				logger::info("[{}] x {}", key, val);
			}
			logger::info("Unenchanted:");
			for (auto const& [key, val] : *unenchanted.getMap()) {
				logger::info("[{}] x {}", key->GetName(), val);
			}
		}
		PlayerInventory(Actor* player) {
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

		lastPlayerInventory->update(player);
		DataCraftEnd();

		logger::info("Delta");
		logger::info("Souls:");
		for (auto const& [key, val] : *usedSouls.getMap()) {
			logger::info("[{}] x {}", static_cast<int>(key), val);
		}
		logger::info("Enchantments:");
		for (auto const& [key, val] : *newEnchantments.getMap()) {
			logger::info("[{}] x {}", key, val);
		}
		logger::info("Unenchanted:");
		for (auto const& [key, val] : *removedItems.getMap()) {
			logger::info("[{}] x {}", key->GetName(), val);
		}


		if (usedSouls.isSingular() && newEnchantments.isSingular() && removedItems.isSingular()) {
			logger::info("singular:");
			lastSoul = usedSouls.getSingular();
			lastItem = removedItems.getSingular();
			lastEnchantment = newEnchantments.getSingular();

			int validSouls = currentPlayerInventory.soulGems.getItem(lastSoul);
			int validItems = currentPlayerInventory.unenchanted.getItem(lastItem);

			auto tmp = std::min(validSouls, validItems);
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
		logger::info("--------------------- repeat: {}", repeat);
		auto unique = player->GetInventory();

		if (unique.contains(lastItem)) {
			Count num = unique.at(lastItem).first;
			auto entryData = unique.at(lastItem).second.get();
			if (entryData != NULL) {
				logger::info("entryData found");
				int remaining = num;
				auto extraLists = entryData->extraLists;
				if (extraLists != NULL) {
					logger::info("Add list data");
					for (auto subgroup : *extraLists) {
						auto extraEnch = subgroup->GetByType(ExtraDataType::kEnchantment);
						bool enchanted = extraEnch != NULL;
						logger::info("extra: {} x {}", enchanted, subgroup->GetCount());
						remaining -= subgroup->GetCount();
						if (enchanted) {
							Count numExtraData = 0;
							bool outerContinue = false;
							for (auto& xData : *subgroup) {
								auto xType = xData.GetType();
								if (xType != ExtraDataType::kTextDisplayData && xType != ExtraDataType::kEnchantment) {
									outerContinue = true;
									break;
								}
							}
							if (outerContinue) {
								continue;
							}

							auto ench = static_cast<ExtraEnchantment*>(extraEnch);
							auto enchKey = GetEnchantmentKey(ench->enchantment);
							if (enchKey.compare(lastEnchantment) == 0) {
								logger::info("Found same enchantment");
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

						logger::info("[{}] {} x {}", hexId, soulGem->GetName(), num);
						if (entryData != NULL) {
							logger::info("entryData found");
							int remaining = num;

							logger::info("{}", static_cast<int>(entryData->GetSoulLevel()));
							auto extraLists = entryData->extraLists;
							if (extraLists != NULL) {
								logger::info("Add list data");
								for (auto subgroup : *extraLists) {
									logger::info("{}", static_cast<int>(subgroup->GetSoulLevel()));
									remaining -= subgroup->GetCount();
									if (subgroup->GetSoulLevel() == lastSoul) {
										logger::info("Remove list soul gems");
										Count remove = std::min(subgroup->GetCount(), remainingSouls);
										player->RemoveItem(key, remove, ITEM_REMOVE_REASON::kRemove, subgroup, nullptr);
										HandleSoulStar(player, soulGem);
										remainingSouls -= remove;
									}
								}
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
		//UIMessageQueue::GetSingleton()->AddMessage(CraftingMenu::MENU_NAME, RE::UI_MESSAGE_TYPE::kUpdate, nullptr);
		//UIMessageQueue::GetSingleton()->AddMessage(CraftingMenu::MENU_NAME, RE::UI_MESSAGE_TYPE::kReshow, nullptr);
		logger::info("RE::UI_MESSAGE_TYPE::kHide");
		UIMessageQueue::GetSingleton()->AddMessage(CraftingMenu::MENU_NAME, RE::UI_MESSAGE_TYPE::kHide, nullptr);
		logger::info("RE::UI_MESSAGE_TYPE::kShow");
		UIMessageQueue::GetSingleton()->AddMessage(CraftingMenu::MENU_NAME, RE::UI_MESSAGE_TYPE::kShow, nullptr);
		lastPlayerInventory->update(player);
		logger::info("repeat done");
	}

	bool RegisterFuncs(BSScript::IVirtualMachine* vm) {
		vm->RegisterFunction("OnStartEnchanting", "JBulk_NativeFunctions", BulkEnchanting::OnStartEnchanting);
		vm->RegisterFunction("OnEndEnchanting", "JBulk_NativeFunctions", BulkEnchanting::OnEndEnchanting);
		vm->RegisterFunction("OnItemEnchanted", "JBulk_NativeFunctions", BulkEnchanting::OnItemEnchanted);
		vm->RegisterFunction("RepeatEnchantment", "JBulk_NativeFunctions", BulkEnchanting::RepeatEnchantment);
		return true;
	}
}


