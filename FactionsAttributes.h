//
// Created by Louis-Philippe on 10/5/2026.
//

#ifndef TOTALBATTLE2D_FACTIONSATTRIBUTES_H
#define TOTALBATTLE2D_FACTIONSATTRIBUTES_H
#include <string>
#include <unordered_map>
#include "Province.h"

struct FactionAttributesData {
    std::vector<std::string> attributes;
};

inline const FactionAttributesData* GetFactionAttributes(FactionZone faction){
    static const std::unordered_map<FactionZone, FactionAttributesData> database = {
        { FactionZone::Knight,  { { "Protective", "Honorable", "Devout" } } },
        { FactionZone::Viking,  { { "Aggressive", "Raider", "Proud" } } },
        { FactionZone::Samurai, { { "Disciplined", "Traditional", "Vengeful" } } },
    };
    auto it = database.find(faction);
    return (it != database.end()) ? &it->second : nullptr;
}

#endif //TOTALBATTLE2D_FACTIONSATTRIBUTES_H
