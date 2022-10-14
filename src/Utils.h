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
}