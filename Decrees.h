//
// Created by Louis-Philippe on 8/22/2026.
//

#pragma once
#ifndef TOTALBATTLE2D_DECREES_H
#define TOTALBATTLE2D_DECREES_H

#include <string>
#include <unordered_map>
#include "Province.h"   // FactionZone
#include "Resources.h"  // ResourceType

struct DecreeData {
    std::string name;
    std::string description;
    ResourceType costResourceType;
    int costResourceAmount;
    int decreeCost;
    int decreeCooldown;
    int decreeDuration;
};

struct DecreeKey {
    FactionZone faction;
    int slotIndex;
    bool operator==(const DecreeKey &other) const {
        return faction == other.faction && slotIndex == other.slotIndex;
    }
};
struct DecreeKeyHash {
    size_t operator()(const DecreeKey &k) const {
        return std::hash<int>()((int)k.faction * 10 + k.slotIndex);
    }
};

inline const std::unordered_map<DecreeKey, DecreeData, DecreeKeyHash>& GetDecreeDatabase() {
    static std::unordered_map<DecreeKey, DecreeData, DecreeKeyHash> db;
    if (!db.empty()) return db;

    auto add = [&](FactionZone faction, int slot, DecreeData data) {
        db[{faction, slot}] = data;
    };

    // KNIGHT (Slot 1 -> Candle, Slot 2 -> Beer, Slot 3 -> GreenTea)
    add(FactionZone::Knight, 0, {"Embrace the Church", "+75% Research rate", ResourceType::Candle, 10, 500, 20, 6});
    add(FactionZone::Knight, 1, {"Feast for All", "description2Knight", ResourceType::Beer, 10, 1000, 20, 6});
    add(FactionZone::Knight, 2, {"Noble by Nature", "Description3Knight", ResourceType::GreenTea, 10, 1200, 20, 6});

    // VIKING
    add(FactionZone::Viking, 0, {"Scholarly Works", "+75% Research rate", ResourceType::Candle, 10, 500, 20, 6});
    add(FactionZone::Viking, 1, {"Great Viking Land", "-50% to building construction time", ResourceType::Beer, 10, 1000, 20, 6});
    add(FactionZone::Viking, 2, {"A Healty Force", "+25% Unit replenishement\n+5 Supplies", ResourceType::GreenTea, 10, 1200, 20, 6});

    // SAMURAI
    add(FactionZone::Samurai, 0, {"Bushido Code", "Les samouraïs réaffirment leur code\nd'honneur et de discipline.", ResourceType::Candle, 10, 500, 20, 6});
    add(FactionZone::Samurai, 1, {"Shogunate Decree", "+10 to faction Allegiance", ResourceType::Beer, 10, 1000, 20, 6});
    add(FactionZone::Samurai, 2, {"Tea Ceremony", "+3 Public order(all provinces)\n+50% Income from Religious building chains", ResourceType::GreenTea, 10, 1200, 20, 6});

    return db;
}

inline const DecreeData* GetDecreeData(FactionZone faction, int slotIndex) {
    const auto& db = GetDecreeDatabase();
    auto it = db.find({faction, slotIndex});
    return (it != db.end()) ? &it->second : nullptr;
}

#endif //TOTALBATTLE2D_DECREES_H