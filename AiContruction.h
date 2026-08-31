// Decides what the AI factions should build, region by region, in a way
// that is actually accountable for its own upkeep.

#pragma once
#ifndef TOTALBATTLE2D_AICONSTRUCTION_H
#define TOTALBATTLE2D_AICONSTRUCTION_H

#include "Buildings.h"
#include "Settlements.h"
#include "Province.h"
#include <vector>
#include <algorithm>
#include <limits>

// Candidate model

enum class AiConstructionActionType {
    NewBuilding,
    MainSettlementUpgrade,
    UpgradeBuilding
};

struct AiConstructionCandidate {
    int settlementIndex;
    int slotIndex;
    BuildingType buildingToConstruct;
    float buildingPriority;
    const char *buildingReason;
    AiConstructionActionType actionType = AiConstructionActionType::NewBuilding;
};

// Tuning constants

namespace AiConstructionTuning {
    // Keeps the AI developing even when nothing is urgent.
    constexpr float kBaselineWeight = 1.0f;

    // How much a building's steady-state net gold per turn (income - upkeep)
    // moves its priority. Positive-net buildings float up, pure upkeep
    // sinks sink down.
    constexpr float kNetIncomeWeight = 0.6f;

    // A building that costs nothing to run and still makes money is as
    // close to free money as this economy gets.
    constexpr float kZeroUpkeepBonus = 4.0f;

    // Reward for a fast payback period on buildings with positive net
    // income, capped so one absurdly cheap building doesn't eclipse
    // everything else forever.
    constexpr float kPaybackWeight = 40.0f;
    constexpr float kPaybackWeightCap = 6.0f;

    // Food.
    constexpr float kFoodStorageCriticalBonus = 8.0f; // granaries nearly full -> build more capacity
    constexpr float kFoodShortageBonus = 6.0f;        // granaries nearly empty -> favor food-producing buildings
    constexpr float kFoodStorageFullRatio = 0.85f;
    constexpr float kFoodStorageLowRatio = 0.15f;
    constexpr float kFoodUpkeepSafeFillRatio = 0.30f; // minimum granary cushion before allowing food-upkeep buildings

    // Trade goods storage.
    constexpr float kGoodsStorageFullBonus = 6.0f;
    constexpr float kGoodsStorageFullRatio = 0.85f;

    // Public order scales continuously so the AI starts caring before a
    // settlement is actually in crisis, rather than flipping on past one
    // hard cutoff.
    constexpr float kPublicOrderComfortLine = 15.0f;
    constexpr float kPublicOrderUrgencyPerPoint = 0.35f;

    // Turning an idle raw resource into its finished good - but only ever
    // proposed in a province that actually produces that raw resource.
    constexpr float kRawMaterialConversionBonus = 7.0f;
    constexpr float kMissingFactionRawGoodBonus = 7.0f; // candle/beer/tea, needed for decrees

    // Military, advanced military and defence currently have no combat
    // system to justify their upkeep  so they stay optional luxuries gated behind a genuinely
    // healthy economy rather than baseline priorities.
    constexpr float kMilitaryBaseline = 0.5f;
    constexpr float kAdvancedMilitaryBaseline = 0.3f;
    constexpr float kDefenceBaseline = 0.6f;
    constexpr float kDefencePublicOrderWeight = 0.1f;

    // Unlocking more building slots.
    constexpr float kMainUpgradeBaseline = 2.0f;
    constexpr float kMainUpgradeSlotsFullBonus = 9.0f;

    // Upgrading something already built.
    constexpr float kUpgradeBaseline = 2.0f;
    constexpr float kUpgradeEconomyStrugglingBonus = 4.0f;

    // Safety rails
    // The AI will not knowingly plan its projected income below this floor
    // unless the treasury can comfortably absorb it.
    constexpr int kMinProjectedIncomeFloor = -30;
    // How many turns of the resulting deficit the treasury must be able to
    // cover before a net-negative building is allowed anyway.
    constexpr float kTreasuryRunwayTurnsRequired = 10.0f;
    // Thresholds for deciding the economy is healthy enough to spend on
    // things that don't pay for themselves (military, defence).
    constexpr int kHealthyTreasuryGold = 800;
    constexpr int kHealthyNextTurnGold = 60;
}

// Economics helpers

inline float AiNetGoldPerTurn(const BuildingData& data) {
    return (float)(data.incomeBonus - data.upkeep);
}

// Scores a building purely on its own economics: net income, whether it's
// free to run, and how quickly it pays for itself. Higher is better; a pure
// upkeep sink (no income, real upkeep) scores negative.
inline float AiEconomicScore(const BuildingData& data) {
    float score = 0.0f;
    float netGold = AiNetGoldPerTurn(data);

    score += netGold * AiConstructionTuning::kNetIncomeWeight;

    if (data.upkeep == 0 && netGold > 0.0f) {
        score += AiConstructionTuning::kZeroUpkeepBonus;
    }

    if (netGold > 0.0f && data.cost > 0) {
        float paybackTurns = (float)data.cost / netGold;
        float paybackScore = AiConstructionTuning::kPaybackWeight / std::max(1.0f, paybackTurns);
        score += std::min(paybackScore, AiConstructionTuning::kPaybackWeightCap);
    }

    return score;
}

// True if the faction can sustain this building's recurring gold cost once ir completed
inline bool AiCanAffordUpkeep(const BuildingData& data, int factionCurrentGold, int factionNextTurnGold, int committedUpkeepThisTurn) {
    float netGold = AiNetGoldPerTurn(data);
    if (netGold >= 0.0f) return true;

    int projectedIncome = factionNextTurnGold - committedUpkeepThisTurn + (int)netGold;
    if (projectedIncome >= AiConstructionTuning::kMinProjectedIncomeFloor) return true;

    int deficit = -projectedIncome;
    if (deficit <= 0) return true;

    float runwayTurns = (float)factionCurrentGold / (float)deficit;
    return runwayTurns >= AiConstructionTuning::kTreasuryRunwayTurnsRequired;
}

// Mirrors AiCanAffordUpkeep, but for food: a building that eats more food
// than it makes should only go up once the province's granaries actually
// have a cushion to spend down.
inline bool AiCanAffordFoodUpkeep(const BuildingData& data, int provinceFoodStored, int provinceFoodCapacity) {
    int netFood = data.foodProduced - data.foodUpkeep;
    if (netFood >= 0) return true;
    if (provinceFoodCapacity <= 0) return false; // no buffer at all yet - too risky
    float fillRatio = (float)provinceFoodStored / (float)provinceFoodCapacity;
    return fillRatio > AiConstructionTuning::kFoodUpkeepSafeFillRatio;
}

inline bool AiIsTreasuryHealthy(int factionCurrentGold, int factionNextTurnGold) {
    return factionCurrentGold >= AiConstructionTuning::kHealthyTreasuryGold
        && factionNextTurnGold >= AiConstructionTuning::kHealthyNextTurnGold;
}

// Slot / chain helpers

// First empty, currently-unlocked slot a settlement could build into (main
// building slot 0 is never considered here - it upgrades on its own path).
inline int FindEmptyBuildableSlot(const Settlement& s) {
    int tier = s.settlementData.settlementTier;
    int slotThreshold = tier;
    if (s.settlementData.type == SettlementType::Capital) slotThreshold = tier + 1;

    for (int b = 1; b < (int)s.settlementData.buildings.size(); b++) {
        if (b > slotThreshold) break;
        if (s.settlementData.buildings[b] == BuildingType::None &&
            s.settlementData.pendingBuildings[b] == BuildingType::None) {
            return b;
        }
    }
    return -1;
}

// True if this exact building type, or any tier in its upgrade chain,
// already exists (built or pending) anywhere in this one settlement.
inline bool SettlementAlreadyHasChain(const Settlement& s, BuildingType chainRoot) {
    for (int b = 1; b < (int)s.settlementData.buildings.size(); b++) {
        BuildingType built = s.settlementData.buildings[b];
        BuildingType pending = s.settlementData.pendingBuildings[b];
        BuildingType check = (built != BuildingType::None) ? built : pending;
        if (check == BuildingType::None) continue;

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

// Same, but across every settlement in a province, so two settlements in
// the same region never both end up wanting the same building.
inline bool ProvinceAlreadyHasChain(const std::vector<int>& settlementIndices, const std::vector<Settlement>& settlements, BuildingType chainRoot) {
    for (int idx : settlementIndices) {
        if (SettlementAlreadyHasChain(settlements[idx], chainRoot)) return true;
    }
    return false;
}

// True if bt is chainRoot itself or any tier reachable by following
// upgradesTo forward from chainRoot. Used to recognise "this built slot is
// a Granary/Warehouse of some tier" without hardcoding tier lists.
inline bool AiIsPartOfChain(BuildingType bt, BuildingType chainRoot) {
    BuildingType cur = chainRoot;
    while (cur != BuildingType::None) {
        if (cur == bt) return true;
        const BuildingData* d = GetBuildingData(cur);
        cur = (d && d->upgradesTo != BuildingType::None) ? d->upgradesTo : BuildingType::None;
    }
    return false;
}

// Picks the missing building (not already present anywhere in the province)
// with the strongest economics, instead of a random one.
inline BuildingType FindBestMissingBuildingInProvince(
    const std::vector<int>& settlementIndices,
    const std::vector<Settlement>& settlements,
    const std::vector<BuildingType>& options)
{
    BuildingType best = BuildingType::None;
    float bestScore = -std::numeric_limits<float>::infinity();

    for (BuildingType bt : options) {
        if (ProvinceAlreadyHasChain(settlementIndices, settlements, bt)) continue;
        const BuildingData* data = GetBuildingData(bt);
        if (!data) continue;

        float score = AiEconomicScore(*data);
        if (best == BuildingType::None || score > bestScore) {
            best = bt;
            bestScore = score;
        }
    }
    return best;
}

inline int FindProvinceMainSettlement(const std::vector<int>& settlementIndices, const std::vector<Settlement>& settlements) {
    for (int idx : settlementIndices) {
        SettlementType t = settlements[idx].settlementData.type;
        if (t == SettlementType::Castle || t == SettlementType::Capital) return idx;
    }
    return -1;
}

// Faction's dedicated raw-good religion building (produces the resource
// decrees are paid with).
inline BuildingType GetFactionRawGoodBuildingRoot(FactionZone faction) {
    switch (faction) {
        case FactionZone::Knight:  return BuildingType::KnightBeeKeeper_T1;  // Candle
        case FactionZone::Viking:  return BuildingType::VikingBrewKeeper_T1; // Beer
        case FactionZone::Samurai: return BuildingType::SamuraiTeaDry_T1;    // GreenTea
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

// Main evaluation

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
    std::vector<AiConstructionCandidate>& outCandidates,
    int factionCurrentGold = 0,               // pass aiState.currentGold for full treasury awareness
    int factionCommittedUpkeepThisTurn = 0)   // pass a running tally to stay safe across one turn's spending
{
    // Both new parameters default to conservative values (no treasury
    // cushion assumed, nothing committed yet), which makes the safety
    // checks maximally cautious out of the box: only buildings that don't
    // risk the faction's real income floor get built, and military/defence
    // stay off entirely until wired up. See the bottom of this file for how
    // to plug in the real numbers from GameApp.cpp.

    // Industry is deliberately absent from this list: it's only ever
    // considered further down, where the AI can check the province
    // actually produces the raw material a Mint/Forge/Jeweller/etc needs.
    // Proposing one blind just buys a building that will sit idle forever.
    static const BuildingCategory kGeneralCategories[] = {
        BuildingCategory::Military,
        BuildingCategory::AdvancedMilitary,
        BuildingCategory::Defence,
        BuildingCategory::Economy,
        BuildingCategory::Religion,
    };

    bool bFoodStorageCritical = provinceFoodCapacity <= 0 ||
        (float)provinceFoodStored >= (float)provinceFoodCapacity * AiConstructionTuning::kFoodStorageFullRatio;
    bool bFoodStorageLow = provinceFoodCapacity > 0 &&
        (float)provinceFoodStored <= (float)provinceFoodCapacity * AiConstructionTuning::kFoodStorageLowRatio;
    bool bGoodsStorageFull = provinceGoodsCapacity <= 0 ||
        (float)provinceGoodsStored >= (float)provinceGoodsCapacity * AiConstructionTuning::kGoodsStorageFullRatio;
    bool bMoneyNextTurnNegative = factionNextTurnGold < 100;
    bool bMissingFactionRawGood = factionRawGoodStored <= 0 && !factionAlreadyHasRawGoodBuilding;
    bool bTreasuryHealthy = AiIsTreasuryHealthy(factionCurrentGold, factionNextTurnGold);

    BuildingType granaryRoot = GetFactionGranaryRoot(faction);
    BuildingType warehouseRoot = GetFactionWarehouseRoot(faction);
    BuildingType rawGoodBuildingRoot = GetFactionRawGoodBuildingRoot(faction);

    for (int idx : settlementIndices) {
        const Settlement& s = settlements[idx];
        int tier = s.settlementData.settlementTier;
        int emptySlot = FindEmptyBuildableSlot(s);

        if (emptySlot >= 0) {
            for (BuildingCategory category : kGeneralCategories) {
                // Skip whole categories that make no sense right now,
                // before even looking at specific buildings in them.
                if ((category == BuildingCategory::Military || category == BuildingCategory::AdvancedMilitary) && !bTreasuryHealthy) {
                    continue; // don't put soldiers on the payroll while broke
                }
                if (category == BuildingCategory::Defence) {
                    if (!bTreasuryHealthy) continue;
                    if (s.settlementData.publicOrder >= AiConstructionTuning::kPublicOrderComfortLine) continue; // nothing to guard against
                }

                std::vector<BuildingType> options = GetBuildingsForCategory(category, faction, tier);

                // Storage and the faction's raw-good building have their own
                // dedicated need-based checks below; keep them out of this
                // general merit scan so they're only ever built on purpose.
                if (rawGoodBuildingRoot != BuildingType::None)
                    options.erase(std::remove(options.begin(), options.end(), rawGoodBuildingRoot), options.end());
                if (granaryRoot != BuildingType::None)
                    options.erase(std::remove(options.begin(), options.end(), granaryRoot), options.end());
                if (warehouseRoot != BuildingType::None)
                    options.erase(std::remove(options.begin(), options.end(), warehouseRoot), options.end());

                BuildingType pick = FindBestMissingBuildingInProvince(settlementIndices, settlements, options);
                if (pick == BuildingType::None) continue;

                const BuildingData* data = GetBuildingData(pick);
                if (!data) continue;
                if (!AiCanAffordUpkeep(*data, factionCurrentGold, factionNextTurnGold, factionCommittedUpkeepThisTurn)) continue;
                if (!AiCanAffordFoodUpkeep(*data, provinceFoodStored, provinceFoodCapacity)) continue;

                float priority = 0.0f;
                const char* reason = "Baseline growth";

                switch (category) {
                    case BuildingCategory::Economy: {
                        priority = AiConstructionTuning::kBaselineWeight + AiEconomicScore(*data);
                        reason = "Growing the economy";
                        if (bMoneyNextTurnNegative) {
                            priority += 5.0f;
                            reason = "Shoring up a struggling economy";
                        }
                        if (bFoodStorageLow && data->foodProduced > data->foodUpkeep) {
                            priority += AiConstructionTuning::kFoodShortageBonus;
                            reason = "Also grows food while reserves run low";
                        }
                        break;
                    }
                    case BuildingCategory::Religion: {
                        float urgency = 0.0f;
                        if (s.settlementData.publicOrder < AiConstructionTuning::kPublicOrderComfortLine) {
                            urgency = (AiConstructionTuning::kPublicOrderComfortLine - s.settlementData.publicOrder)
                                    * AiConstructionTuning::kPublicOrderUrgencyPerPoint;
                        }
                        priority = AiConstructionTuning::kBaselineWeight * 0.5f + urgency + AiEconomicScore(*data);
                        reason = urgency > 0.0f ? "Public order needs attention" : "Long-term stability, cheap to run";
                        break;
                    }
                    case BuildingCategory::Military:
                        priority = AiConstructionTuning::kMilitaryBaseline;
                        reason = "Treasury can spare it for the future";
                        break;
                    case BuildingCategory::AdvancedMilitary:
                        priority = AiConstructionTuning::kAdvancedMilitaryBaseline;
                        reason = "Treasury can spare it for the future";
                        break;
                    case BuildingCategory::Defence:
                        priority = AiConstructionTuning::kDefenceBaseline
                                 + (AiConstructionTuning::kPublicOrderComfortLine - s.settlementData.publicOrder) * AiConstructionTuning::kDefencePublicOrderWeight;
                        reason = "Reinforcing while it's affordable";
                        break;
                    default:
                        priority = AiConstructionTuning::kBaselineWeight;
                        break;
                }

                outCandidates.push_back({idx, emptySlot, pick, priority, reason, AiConstructionActionType::NewBuilding});
            }

            if (bFoodStorageCritical && granaryRoot != BuildingType::None && !ProvinceAlreadyHasChain(settlementIndices, settlements, granaryRoot)) {
                const BuildingData* granaryData = GetBuildingData(granaryRoot);
                if (granaryData && granaryData->Tier <= tier &&
                    AiCanAffordUpkeep(*granaryData, factionCurrentGold, factionNextTurnGold, factionCommittedUpkeepThisTurn)) {
                    outCandidates.push_back({idx, emptySlot, granaryRoot,
                        AiConstructionTuning::kBaselineWeight + AiConstructionTuning::kFoodStorageCriticalBonus,
                        "Granaries are nearly full", AiConstructionActionType::NewBuilding});
                }
            }
            if (bGoodsStorageFull && warehouseRoot != BuildingType::None && !ProvinceAlreadyHasChain(settlementIndices, settlements, warehouseRoot)) {
                const BuildingData* warehouseData = GetBuildingData(warehouseRoot);
                if (warehouseData && warehouseData->Tier <= tier &&
                    AiCanAffordUpkeep(*warehouseData, factionCurrentGold, factionNextTurnGold, factionCommittedUpkeepThisTurn)) {
                    outCandidates.push_back({idx, emptySlot, warehouseRoot,
                        AiConstructionTuning::kBaselineWeight + AiConstructionTuning::kGoodsStorageFullBonus,
                        "Trade goods storage is nearly full", AiConstructionActionType::NewBuilding});
                }
            }
            if (bMissingFactionRawGood && rawGoodBuildingRoot != BuildingType::None && !SettlementAlreadyHasChain(s, rawGoodBuildingRoot)) {
                const BuildingData* rawGoodData = GetBuildingData(rawGoodBuildingRoot);
                if (rawGoodData && rawGoodData->Tier <= tier &&
                    AiCanAffordUpkeep(*rawGoodData, factionCurrentGold, factionNextTurnGold, factionCommittedUpkeepThisTurn)) {
                    outCandidates.push_back({idx, emptySlot, rawGoodBuildingRoot,
                        AiConstructionTuning::kBaselineWeight + AiConstructionTuning::kMissingFactionRawGoodBonus,
                        "No source of the faction's decree resource yet", AiConstructionActionType::NewBuilding});
                }
            }
        }
        else {
            // No room left: either grow the settlement, or upgrade what's already there.
            if (!s.settlementData.bBuidingUnderConstruction) {
                const BuildingData* mainBd = GetBuildingData(s.settlementData.buildings[0]);
                if (mainBd && mainBd->upgradesTo != BuildingType::None) {
                    const BuildingData* nextBd = GetBuildingData(mainBd->upgradesTo);
                    if (nextBd) {
                        BuildingData upkeepProbe = *nextBd;
                        upkeepProbe.upkeep = std::max(0, nextBd->upkeep - mainBd->upkeep);
                        upkeepProbe.incomeBonus = 0;

                        if (AiCanAffordUpkeep(upkeepProbe, factionCurrentGold, factionNextTurnGold, factionCommittedUpkeepThisTurn)) {
                            float priority = AiConstructionTuning::kMainUpgradeBaseline + AiConstructionTuning::kMainUpgradeSlotsFullBonus;
                            outCandidates.push_back({idx, 0, BuildingType::None, priority,
                                "No room left, growing the settlement", AiConstructionActionType::MainSettlementUpgrade});
                        }
                    }
                }
            }

            for (int b = 1; b < (int)s.settlementData.buildings.size(); b++) {
                BuildingType built = s.settlementData.buildings[b];
                if (built == BuildingType::None) continue;
                if (s.settlementData.pendingBuildings[b] != BuildingType::None) continue;

                const BuildingData* builtData = GetBuildingData(built);
                if (!builtData || builtData->upgradesTo == BuildingType::None) continue;
                const BuildingData* nextData = GetBuildingData(builtData->upgradesTo);
                if (!nextData || nextData->Tier > tier) continue;

                BuildingCategory cat = GetBuildingCategory(built);
                if ((cat == BuildingCategory::Military || cat == BuildingCategory::AdvancedMilitary || cat == BuildingCategory::Defence) && !bTreasuryHealthy) {
                    continue; // stop sinking money into the army/walls once the treasury is thin
                }
                if (granaryRoot != BuildingType::None && AiIsPartOfChain(built, granaryRoot) && !bFoodStorageCritical) {
                    continue; // more granary capacity isn't needed yet
                }
                if (warehouseRoot != BuildingType::None && AiIsPartOfChain(built, warehouseRoot) && !bGoodsStorageFull) {
                    continue; // more warehouse capacity isn't needed yet
                }
                if (!AiCanAffordUpkeep(*nextData, factionCurrentGold, factionNextTurnGold, factionCommittedUpkeepThisTurn)) continue;
                if (!AiCanAffordFoodUpkeep(*nextData, provinceFoodStored, provinceFoodCapacity)) continue;

                float priority = AiConstructionTuning::kUpgradeBaseline + AiEconomicScore(*nextData);
                const char* reason = "Upgrading an existing building";

                if (cat == BuildingCategory::Economy && bMoneyNextTurnNegative) {
                    priority += AiConstructionTuning::kUpgradeEconomyStrugglingBonus;
                    reason = "Upgrading income to fix a struggling economy";
                }
                if (cat == BuildingCategory::Religion && s.settlementData.publicOrder < AiConstructionTuning::kPublicOrderComfortLine) {
                    priority += (AiConstructionTuning::kPublicOrderComfortLine - s.settlementData.publicOrder)
                              * AiConstructionTuning::kPublicOrderUrgencyPerPoint;
                    reason = "Upgrading to steady public order";
                }

                outCandidates.push_back({idx, b, builtData->upgradesTo, priority, reason, AiConstructionActionType::UpgradeBuilding});
            }
        }
    }

    // Province-wide: turn an idle raw material into its finished good, in
    // the province's main settlement, and only if that raw material is
    // genuinely being produced somewhere in the province.
    int mainSettlementIndex = FindProvinceMainSettlement(settlementIndices, settlements);
    if (mainSettlementIndex < 0) return;

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
        if (SettlementAlreadyHasChain(mainSettlement, industryRoot)) continue;

        const BuildingData* industryData = GetBuildingData(industryRoot);
        if (!industryData || industryData->Tier > mainSettlement.settlementData.settlementTier) continue;
        if (!AiCanAffordUpkeep(*industryData, factionCurrentGold, factionNextTurnGold, factionCommittedUpkeepThisTurn)) continue;

        outCandidates.push_back({mainSettlementIndex, industrySlot, industryRoot,
            AiConstructionTuning::kBaselineWeight + AiConstructionTuning::kRawMaterialConversionBonus,
            "Putting an idle raw material to use", AiConstructionActionType::NewBuilding});
        break;
    }
}

// Turn-level bookkeeping

// Rough estimate of how much a chosen candidate will worsen (positive) the
// faction's steady-state gold income once construction completes. Sum this
// across every purchase made in the same turn and feed the running total
// back in as factionCommittedUpkeepThisTurn, so a burst of individually
// affordable purchases can't collectively overcommit an economy that looked
// fine one building at a time.
//
// In GameApp.cpp's ProcessAiFactionConstructionForTurn(), this means:
//   1) `int committedUpkeepThisTurn = 0;` before the `while (true)` loop.
//   2) Pass `, aiState.currentGold, committedUpkeepThisTurn` as the last two
//      arguments to EvaluateProvinceConstructionNeeds(...).
//   3) Right after a candidate is chosen and bought (after both branches of
//      the `if (chosen->actionType == ...)` block), add:
//      `committedUpkeepThisTurn += AiEstimateFutureUpkeepDelta(*chosen, settlements);`
inline int AiEstimateFutureUpkeepDelta(const AiConstructionCandidate& candidate, const std::vector<Settlement>& settlements) {
    const Settlement& sel = settlements[candidate.settlementIndex];

    if (candidate.actionType == AiConstructionActionType::MainSettlementUpgrade) {
        const BuildingData* mainData = GetBuildingData(sel.settlementData.buildings[0]);
        if (!mainData || mainData->upgradesTo == BuildingType::None) return 0;
        const BuildingData* nextData = GetBuildingData(mainData->upgradesTo);
        if (!nextData) return 0;
        int netChange = (nextData->incomeBonus - mainData->incomeBonus) - (nextData->upkeep - mainData->upkeep);
        return netChange < 0 ? -netChange : 0;
    }

    const BuildingData* newData = GetBuildingData(candidate.buildingToConstruct);
    if (!newData) return 0;

    const BuildingData* oldData = nullptr;
    if (candidate.actionType == AiConstructionActionType::UpgradeBuilding &&
        candidate.slotIndex >= 0 && candidate.slotIndex < (int)sel.settlementData.buildings.size()) {
        oldData = GetBuildingData(sel.settlementData.buildings[candidate.slotIndex]);
    }

    int oldIncome = oldData ? oldData->incomeBonus : 0;
    int oldUpkeep = oldData ? oldData->upkeep : 0;
    int netChange = (newData->incomeBonus - oldIncome) - (newData->upkeep - oldUpkeep);
    return netChange < 0 ? -netChange : 0;
}

#endif //TOTALBATTLE2D_AICONSTRUCTION_H