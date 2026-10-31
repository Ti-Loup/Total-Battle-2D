//
// Created by Louis-Philippe on 10/5/2026.
//

#ifndef TOTALBATTLE2D_FACTIONSATTRIBUTES_H
#define TOTALBATTLE2D_FACTIONSATTRIBUTES_H
#include <string>
#include <vector>
#include <unordered_map>
#include <numeric>
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

//attitude Between factions.
struct AttitudeModifier{
    std::string name;
    int value = 0;
    int turnsRemaining = -1;
    //decay slowly over time
    int minValue = 0;
    int decayPerTurn = 0;
};

//all possible positive and negative
namespace AttitudeValues {
    //bonus
    constexpr int Friendship = 20;//can be replaced by defensive pact
    constexpr int MilitaryAccess = 18;
    constexpr int Trade = 12;
    constexpr int Marriage = 80;
    constexpr int DefensivePact = 65;
    constexpr int MilitaryAlliance = 108;
    //Gifts (decaying)
    constexpr int SmallGiftValue = 8; constexpr int SmallGiftFloor = 2; constexpr int SmallGiftDecay = 1;
    constexpr int MediumGiftValue = 20; constexpr int MediumGiftFloor = 4; constexpr int MediumGiftDecay = 2;
    constexpr int LargeGiftValue = 40; constexpr int LargeGiftFloor = 8; constexpr int LargeGiftDecay = 2;
    constexpr int GiftMaxValue = 60;    // gifts stack up to this
    constexpr int GiftMaxFloor = 15;
    //Trade history (cumulative)
    constexpr int TradeHistoryPerTurn = 3;  // gained each turn a trade exchange bonus
    constexpr int TradeHistoryMax = 30;
    constexpr int TradeHistoryFloorGain = 1;
    constexpr int TradeHistoryFloorMax = 10;
    constexpr int TradeHistoryDecay = 1;

    //military actions with a faction with common enemy
    constexpr int CommonEnemy = 10;
    constexpr int MilitaryActionsAgaintsCommonEnemy = 8;//cumulatif
    constexpr int RaidActionAgaintsCommonEnemy = 4;//cumulatif
    //negatives
    constexpr int AtWar = -150;
    //military actions againts a faction with his ally
    constexpr int EnemyWithMyAlly = -40;
    constexpr int MilitaryActionsWithMyAlly = -8;//cuumulatif
    constexpr int RaidActionsWithMyAlly = -4;//cumulatif
    constexpr int Trespasser = -15;//cumulatif

    //Attitude labels
    constexpr int HostileMax = -150;
    constexpr int UnfriendlyMax = -40;
    constexpr int FriendlyMin = 20;
    constexpr int VeryFriendlyMin = 80;
}
//per faction to faction attitude
struct PairAttitudeModifier {
    FactionZone fromAttitude;
    FactionZone towardAttitude;
    const char* name;
    int value;
};

inline std::vector<AttitudeModifier> GetBaseAttitudeModifiers(FactionZone fromAttitude, FactionZone towardAttitude) {
    static const std::vector<PairAttitudeModifier> database = {
        { FactionZone::Knight,  FactionZone::Viking,  "Cultural differences", -30},
        { FactionZone::Knight, FactionZone::Samurai, "Cultural differences", -10},
        { FactionZone::Viking,  FactionZone::Knight,  "Cultural differences", -30},
        { FactionZone::Viking, FactionZone::Samurai, "Cultural differences", -30},
        { FactionZone::Samurai, FactionZone::Knight, "Cultural differences", -10},
        { FactionZone::Samurai, FactionZone::Viking, "Cultural differences", -30},
    };

    std::vector<AttitudeModifier> mods;
    if (fromAttitude == towardAttitude) return mods;

    // for all factions pair
    //mods.push_back({ "Cultural differences", -10, -1 });

    for (const PairAttitudeModifier& entry : database) {
        if (entry.fromAttitude == fromAttitude && entry.towardAttitude == towardAttitude)
            mods.push_back({ entry.name, entry.value, -1 });
    }
    return mods;
}

// TOTAL + LABEL + COLOR
inline int GetTotalAttitude(const std::vector<AttitudeModifier>& mods) {
    int total = 0;
    for (const AttitudeModifier& m : mods) total += m.value;
    return total;
}


inline const char* GetAttitudeLabel(int total) {
    if (total <= AttitudeValues::HostileMax)      return "Hostile";
    if (total <= AttitudeValues::UnfriendlyMax)   return "Unfriendly";
    if (total >= AttitudeValues::VeryFriendlyMin) return "Very friendly";
    if (total >= AttitudeValues::FriendlyMin)     return "Friendly";
    return "Neutral";
}

struct AttitudeColor { unsigned char r, g, b; };

inline AttitudeColor GetAttitudeColor(int total) {
    if (total <= AttitudeValues::HostileMax)      return { 200,  40,  40 };
    if (total <= AttitudeValues::UnfriendlyMax)   return { 230, 120,  80 };
    if (total >= AttitudeValues::VeryFriendlyMin) return {  60, 220,  80 };
    if (total >= AttitudeValues::FriendlyMin)     return { 140, 220, 120 };
    return { 220, 220, 220 };
}


#endif //TOTALBATTLE2D_FACTIONSATTRIBUTES_H
