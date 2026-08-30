//
// Created by Louis-Philippe on 8/28/2026.
//

#pragma once
#ifndef TOTALBATTLE2D_AICONSTRUCTION_H
#define TOTALBATTLE2D_AICONSTRUCTION_H

#include "Buildings.h"
#include "Settlements.h"
#include "Province.h"
#include <vector>

//the ai will first construct new buildings and once its full they will upgrade the main settlements and then upgrade the buildings/construct new ones.
enum class AiConstructionActionType {
    NewBuilding,
    MainSettlementUpgrade,
    UpgradeBuilding
};

struct AiConstructionCandidate {
    int settlementIndex;
    int slotIndex;
    BuildingType buildingToConstruct;
    float buildingPriority;//importance of a certain building to be constructed
    const char *buildingReason;//Log Reason/ debug
    AiConstructionActionType actionType = AiConstructionActionType::NewBuilding;
};

//strenght of a priority building to be there
namespace AiConstructionWeights{
    //All 6 construction categories start on the exact same footing; only a
    //genuine need below is allowed to push one candidate above the others.
    constexpr float kCategoryBase = 3.0f;

    //Boosts stacked on top of kCategoryBase once a real need is detected.
    constexpr float kFoodStorageTooSmall = 7.0f;//granary: province can't hold much more food
    constexpr float kGoodsStorageFull = 7.0f;//warehouse: province goods storage overflowing
    constexpr float kMoneyNextTurnNegative = 7.0f;//any economy building: losing gold next turn
    constexpr float kPublicOrderWeak = 7.0f;//any religious building: base bump
    constexpr float kPublicOrderPerNegatif = 0.3f;//extra priority per point of negative public order
    constexpr float kMissingFactionRawGood = 7.0f;//beehives/brew house/tea garden, needed for decrees

    //Thresholds deciding whether storage counts as "too small" / "full".
    //Predict for the future his needs.
    constexpr float kFoodStorageFullRatio  = 0.85f;//stored >= 85% of capacity -> need more granaries
    constexpr float kGoodsStorageFullRatio = 0.85f;//stored >= 85% of capacity -> need more warehouses

    constexpr float kRawMaterialUnused = 8.0f;//idle raw resource -> build its industry chain (province-wide)

    constexpr float kMainSettlementUpgrade = 6.0f;
    constexpr float kUpgradeBuildingBase = 4.0f;
}

//To find the first empty slot to be unlockable. (main building == 0 so above that)
inline int FindEmptyBuildableSlot(const Settlement& s) {
    int tier = s.settlementData.settlementTier;
    int slotThreshold = tier;
    if (s.settlementData.type == SettlementType::Capital) slotThreshold = tier + 1;

    for (int b = 1; b < (int)s.settlementData.buildings.size(); b++) {
        if (b > slotThreshold) break; // not unlocked yet
        if (s.settlementData.buildings[b] == BuildingType::None &&
            s.settlementData.pendingBuildings[b] == BuildingType::None) {
            return b;
        }
    }
    return -1;
}
// True if this exact building type or any tier in its chain already exists somewhere in the settlement.
inline bool SettlementAlreadyHasChain(const Settlement& s, BuildingType chainRoot) {
    for (int b = 1; b < (int)s.settlementData.buildings.size(); b++) {
        BuildingType built = s.settlementData.buildings[b];
        BuildingType pending = s.settlementData.pendingBuildings[b];
        BuildingType check = (built != BuildingType::None) ? built : pending;
        if (check == BuildingType::None) continue;
        // Walk the built type back to its root and compare
        BuildingType cur = check;
        while (true) {
            if (cur == chainRoot) return true;
            bool found = false;
            for (auto& [key, data] : GetBuildingDatabase()) {
                if (data.upgradesTo == cur) { cur = key; found = true; break; }
            }
            if (!found) break;
        }
    }
    return false;
}

// True if this exact building type or any tier in its chain already exists (built or pending)
// anywhere in the province so two different settlements in the same province never both
// end up wanting the same building. Ports are unaffected: they're assigned directly at settlement creation via bIsPort and never go through this candidate system.
inline bool ProvinceAlreadyHasChain(const std::vector<int>& settlementIndices, const std::vector<Settlement>& settlements, BuildingType chainRoot) {
    for (int idx : settlementIndices) {
        if (SettlementAlreadyHasChain(settlements[idx], chainRoot)) return true;
    }
    return false;
}

// Returns the first building root in the list not already present (built or pending)
// anywhere in the province, so a filled slot in one settlement lets a category move on to its next option instead of a sibling settlement building the exact same thing.
inline BuildingType FindFirstMissingBuildingInProvince(const std::vector<int>& settlementIndices, const std::vector<Settlement>& settlements, const std::vector<BuildingType>& options) {
    for (BuildingType bt : options) {
        if (!ProvinceAlreadyHasChain(settlementIndices, settlements, bt)) return bt;
    }
    return BuildingType::None;
}

inline int FindProvinceMainSettlement(const std::vector<int>& settlementIndices, const std::vector<Settlement>& settlements) {
    for (int idx : settlementIndices) {
        SettlementType t = settlements[idx].settlementData.type;
        if (t == SettlementType::Castle || t == SettlementType::Capital) return idx;
    }
    return -1;
}

//Faction's dedicated raw-good religion building (produces the resource decrees are paid with)
inline BuildingType GetFactionRawGoodBuildingRoot(FactionZone faction) {
    switch (faction) {
        case FactionZone::Knight:  return BuildingType::KnightBeeKeeper_T1;  //Candle
        case FactionZone::Viking:  return BuildingType::VikingBrewKeeper_T1; //Beer
        case FactionZone::Samurai: return BuildingType::SamuraiTeaDry_T1;    //GreenTea
        default: return BuildingType::None;
    }
}
inline ResourceType GetFactionRawGoodResourceType(FactionZone faction) {
    switch (faction) {
        case FactionZone::Knight:  return ResourceType::Candle;
        case FactionZone::Viking:  return ResourceType::Beer;
        case FactionZone::Samurai: return ResourceType::GreenTea;
        default: return ResourceType::Fish;
    }
}
inline BuildingType GetFactionGranaryRoot(FactionZone faction) {
    switch (faction) {
        case FactionZone::Knight:  return BuildingType::KnightGranary_T3;
        case FactionZone::Viking:  return BuildingType::VikingGranary_T3;
        case FactionZone::Samurai: return BuildingType::SamuraiGranary_T3;
        default: return BuildingType::None;
    }
}
inline BuildingType GetFactionWarehouseRoot(FactionZone faction) {
    switch (faction) {
        case FactionZone::Knight:  return BuildingType::KnightWareHouse_T3;
        case FactionZone::Viking:  return BuildingType::VikingWareHouse_T3;
        case FactionZone::Samurai: return BuildingType::SamuraiWareHouse_T3;
        default: return BuildingType::None;
    }
}

inline void EvaluateProvinceConstructionNeeds(
    int provinceID,
    const std::vector<int>& settlementIndices,
    const std::vector<Settlement>& settlements,
    FactionZone faction,
    int provinceFoodStored,
    int provinceFoodCapacity,
    int provinceGoodsStored,
    int provinceGoodsCapacity,
    int factionNextTurnGold,
    int factionRawGoodStored,
    bool factionAlreadyHasRawGoodBuilding,
    std::vector<AiConstructionCandidate>& outCandidates)
{
    static const BuildingCategory kAllCategories[] = {
        BuildingCategory::Military,
        BuildingCategory::AdvancedMilitary,
        BuildingCategory::Defence,
        BuildingCategory::Economy,
        BuildingCategory::Industry,
        BuildingCategory::Religion,
    };

    bool bFoodStorageTooSmall = provinceFoodCapacity <= 0 ||
        (float)provinceFoodStored >= (float)provinceFoodCapacity * AiConstructionWeights::kFoodStorageFullRatio;
    bool bGoodsStorageFull = provinceGoodsCapacity <= 0 ||
        (float)provinceGoodsStored >= (float)provinceGoodsCapacity * AiConstructionWeights::kGoodsStorageFullRatio;
    bool bMoneyNextTurnNegative = factionNextTurnGold < 0;
    // Only counts as missing if nobody in the faction already has it built or pending anywhere.
    bool bMissingFactionRawGood = factionRawGoodStored <= 0 && !factionAlreadyHasRawGoodBuilding;

    BuildingType granaryRoot = GetFactionGranaryRoot(faction);
    BuildingType warehouseRoot = GetFactionWarehouseRoot(faction);
    BuildingType rawGoodBuildingRoot = GetFactionRawGoodBuildingRoot(faction);

    for (int idx : settlementIndices) {
        const Settlement& s = settlements[idx];
        int tier = s.settlementData.settlementTier;
        int emptySlot = FindEmptyBuildableSlot(s);

        if (emptySlot >= 0) {
            // Room available -> build new things
            for (BuildingCategory category : kAllCategories) {
                std::vector<BuildingType> options = GetBuildingsForCategory(category, faction, tier);
                BuildingType pick = FindFirstMissingBuildingInProvince(settlementIndices, settlements, options);
                if (pick == BuildingType::None) continue;

                float priority = AiConstructionWeights::kCategoryBase;
                const char* reason = "Baseline growth";

                if (category == BuildingCategory::Economy && bMoneyNextTurnNegative) {
                    priority += AiConstructionWeights::kMoneyNextTurnNegative;
                    reason = "Losing gold next turn";
                }
                if (category == BuildingCategory::Religion && s.settlementData.publicOrder < 0) {
                    priority += AiConstructionWeights::kPublicOrderWeak
                              + (-s.settlementData.publicOrder) * AiConstructionWeights::kPublicOrderPerNegatif;
                    reason = "Weak public order";
                }
                outCandidates.push_back({idx, emptySlot, pick, priority, reason, AiConstructionActionType::NewBuilding});
            }

            if (bFoodStorageTooSmall && granaryRoot != BuildingType::None && !ProvinceAlreadyHasChain(settlementIndices, settlements, granaryRoot)) {
                const BuildingData* granaryData = GetBuildingData(granaryRoot);
                if (granaryData && granaryData->Tier <= tier)
                    outCandidates.push_back({idx, emptySlot, granaryRoot,
                        AiConstructionWeights::kCategoryBase + AiConstructionWeights::kFoodStorageTooSmall,
                        "Food storage nearly full", AiConstructionActionType::NewBuilding});
            }
            if (bGoodsStorageFull && warehouseRoot != BuildingType::None && !ProvinceAlreadyHasChain(settlementIndices, settlements, warehouseRoot)) {
                const BuildingData* warehouseData = GetBuildingData(warehouseRoot);
                if (warehouseData && warehouseData->Tier <= tier)
                    outCandidates.push_back({idx, emptySlot, warehouseRoot,
                        AiConstructionWeights::kCategoryBase + AiConstructionWeights::kGoodsStorageFull,
                        "Goods storage full", AiConstructionActionType::NewBuilding});
            }
            if (bMissingFactionRawGood && rawGoodBuildingRoot != BuildingType::None && !SettlementAlreadyHasChain(s, rawGoodBuildingRoot)) {
                const BuildingData* rawGoodData = GetBuildingData(rawGoodBuildingRoot);
                if (rawGoodData && rawGoodData->Tier <= tier)
                    outCandidates.push_back({idx, emptySlot, rawGoodBuildingRoot,
                        AiConstructionWeights::kCategoryBase + AiConstructionWeights::kMissingFactionRawGood,
                        "Missing faction raw good", AiConstructionActionType::NewBuilding});
            }
        }
        else {
            // No room -> upgrade main settlement (unlocks slots)
            if (!s.settlementData.bBuidingUnderConstruction) {
                const BuildingData* mainBd = GetBuildingData(s.settlementData.buildings[0]);
                if (mainBd && mainBd->upgradesTo != BuildingType::None) {
                    outCandidates.push_back({idx, 0, BuildingType::None,
                        AiConstructionWeights::kMainSettlementUpgrade,
                        "No room left, upgrading main settlement",
                        AiConstructionActionType::MainSettlementUpgrade});
                }
            }
            // Also try upgrading buildings already constructed
            for (int b = 1; b < (int)s.settlementData.buildings.size(); b++) {
                BuildingType built = s.settlementData.buildings[b];
                if (built == BuildingType::None) continue;
                if (s.settlementData.pendingBuildings[b] != BuildingType::None) continue;

                const BuildingData* builtData = GetBuildingData(built);
                if (!builtData || builtData->upgradesTo == BuildingType::None) continue;
                const BuildingData* nextData = GetBuildingData(builtData->upgradesTo);
                if (!nextData || nextData->Tier > tier) continue;

                float priority = AiConstructionWeights::kUpgradeBuildingBase;
                const char* reason = "Upgrading existing building";
                BuildingCategory cat = GetBuildingCategory(built);
                if (cat == BuildingCategory::Economy && bMoneyNextTurnNegative) {
                    priority += AiConstructionWeights::kMoneyNextTurnNegative;
                    reason = "Upgrading economy building, losing gold";
                }
                if (cat == BuildingCategory::Religion && s.settlementData.publicOrder < 0) {
                    priority += AiConstructionWeights::kPublicOrderWeak
                              + (-s.settlementData.publicOrder) * AiConstructionWeights::kPublicOrderPerNegatif;
                    reason = "Upgrading religious building, weak public order";
                }
                outCandidates.push_back({idx, b, builtData->upgradesTo, priority, reason, AiConstructionActionType::UpgradeBuilding});
            }
        }
    }

    //Province-wide need: raw material -> Industry building, always in the MAIN settlement
    int mainSettlementIndex = FindProvinceMainSettlement(settlementIndices, settlements);
    if (mainSettlementIndex < 0) return; // no Castle/Capital in this province yet

    const Settlement& mainSettlement = settlements[mainSettlementIndex];
    int industrySlot = FindEmptyBuildableSlot(mainSettlement);
    if (industrySlot < 0) return;

    for (int idx : settlementIndices) {
        const Settlement& mine = settlements[idx];
        ResourceType mineResource;
        bool isMine = true;
        if (mine.bIsIronMine) mineResource = ResourceType::Iron;
        else if (mine.bIsGoldMine) mineResource = ResourceType::Gold;
        else if (mine.bIsCopperMine) mineResource = ResourceType::Copper;
        else if (mine.bIsSilverMine) mineResource = ResourceType::Silver;
        else if (mine.bIsTinMine) mineResource = ResourceType::Tin;
        else if (mine.bIsLumberMine) mineResource = ResourceType::Lumber;
        else if (mine.bIsSheepPasture) mineResource = ResourceType::Wool;
        else isMine = false;
        if (!isMine) continue;

         BuildingType industryRoot = GetIndustryBuildingForRawResource(mineResource, faction);
         if (industryRoot == BuildingType::None) continue;
         if (SettlementAlreadyHasChain(mainSettlement, industryRoot)) continue; // province already processes this resource

         const BuildingData* industryData = GetBuildingData(industryRoot);
         if (!industryData || industryData->Tier > mainSettlement.settlementData.settlementTier) continue; // not unlocked yet

         outCandidates.push_back({mainSettlementIndex, industrySlot, industryRoot,
         AiConstructionWeights::kRawMaterialUnused, "Unused raw material in province"});
          break; // one Industry candidate per pass; next resource gets picked up once this slot fills
    }
}
#endif //TOTALBATTLE2D_AICONTRUCTION_H