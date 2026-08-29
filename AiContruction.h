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

struct AiConstructionCandidate {
    int settlementIndex;
    int slotIndex;
    BuildingType buildingToConstruct;
    float buildingPriority;//importance of a certain building to be constructed
    const char *buildingReason;//Log Reason/ debug
};

//strenght of a priority building to be there
namespace AiConstructionWeights{
    constexpr float kPublicOrderBase = 6.0f;
    constexpr float kPublicOrderPerNegatif = 0.3f;//extra priotiy per points of negative public order
    constexpr float kRawMaterialUnused = 8.0f;//Raw materials idle has higer chance to build transformed building in priority
    constexpr float kEconomyFiller = 2.0f; // less priority for the rest
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

inline int FindProvinceMainSettlement(const std::vector<int>& settlementIndices, const std::vector<Settlement>& settlements) {
    for (int idx : settlementIndices) {
        SettlementType t = settlements[idx].settlementData.type;
        if (t == SettlementType::Castle || t == SettlementType::Capital) return idx;
    }
    return -1;
}

inline void EvaluateProvinceConstructionNeeds(
    int provinceID,
    const std::vector<int>& settlementIndices,
    const std::vector<Settlement>& settlements,
    FactionZone faction,
    std::vector<AiConstructionCandidate>& outCandidates)
{
    //Per-settlement needs: public order + baseline growth 
    for (int idx : settlementIndices) {
        const Settlement& s = settlements[idx];
        int emptySlot = FindEmptyBuildableSlot(s);
        if (emptySlot < 0) continue;

        if (s.settlementData.publicOrder < 0) {
            std::vector<BuildingType> religionOptions = GetBuildingsForCategory(BuildingCategory::Religion, faction, 1);
            if (!religionOptions.empty() && !SettlementAlreadyHasChain(s, religionOptions[0])) {
                float priority = AiConstructionWeights::kPublicOrderBase
                                + (-s.settlementData.publicOrder) * AiConstructionWeights::kPublicOrderPerNegatif;
                outCandidates.push_back({idx, emptySlot, religionOptions[0], priority, "Negative public order"});
                continue; // don't also queue filler for this slot
            }
        }

        std::vector<BuildingType> economyOptions = GetBuildingsForCategory(BuildingCategory::Economy, faction, s.settlementData.settlementTier);
        if (!economyOptions.empty() && !SettlementAlreadyHasChain(s, economyOptions[0])) {
            outCandidates.push_back({idx, emptySlot, economyOptions[0], AiConstructionWeights::kEconomyFiller, "Baseline growth"});
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
