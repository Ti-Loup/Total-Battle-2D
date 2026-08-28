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
//To find the first empty slot to be unlockable.

#endif //TOTALBATTLE2D_AICONTRUCTION_H
