//
// Created by lpgau on 2026-07-16.
//

#ifndef TOTALBATTLE2D_WORLDEVENTS_H
#define TOTALBATTLE2D_WORLDEVENTS_H

#include <string>
#include <unordered_map>
#include <vector>
/**
 *
 *
 * This script is made to add differents events and to choose the right one when needed
 */

enum class WorldEventsType{
    None,
    //Bad EVENTS
    Storm,
    Earthquake,
    Drought,
    Plague,
    Fire,
    PoorPopulation,
    //GoodEvent
    GoodHarvest,
    MiraculousFishCatch,
    FavorableWinds,
    Justice,
    NewInvension,
    WarPreparation
};
enum class WorldEventCategory{
    Positive,
    Negative,
};
struct WorldEventsData {
    //BAD EVENTS
    //METEO
    //-Storm -> Boats attritions -> No Food from MilitaryPorts/FishingPorts
    //-Earthquake
    //-Dryness
    //HUMAN
    //-Plague  On 1 settlement (Public order decrease -> Population birthrate reduced, deathrate rise,) Spread across the territory during the event. Ends at the end of events
    //-Fire -> all Buildings damaged inside a settlement random per faction, public order decreasein that province
    //-Poor Population -> Live too expensive and war keep happening

    //GOOD EVENTS
    //METEO
    //-Good harvest -> Generate more food
    //-miraculous fish catch
    //-Favorable Winds -> Increase fleet movement speed and Maritime Trade income
    //HUMAN
    //-Justice (Huge criminal got arrested and brought to justice) more order public and better legitimicy(future).
    //-New Invension from inventors brings job and happyness to the population and increase productivity of buildings
    //-War Preparation -> improve war stats

    std::string name;
    std::string description;
    WorldEventCategory category;

    //Effects
    int publicOrderModifier = 0;
    float foodProductionMultiplier = 1.0f;
    int foodFlatBonus = 0;
    int goldIncomeMultiplier = 1.0f;
    int goldFlatBonus = 0;
    int durationTurns = 1;
};
//Database of all Events
inline const std::unordered_map<WorldEventsType, WorldEventsData>& GetWorldEventDatabase(){
    static const std::unordered_map<WorldEventsType, WorldEventsData> database = {
        { WorldEventType::Storm, {
            "Storm",
            "A violent storm batters the coastline. Ships are damaged and fishing ports produce no food.",
            WorldEventCategory::Bad,
            0, 1.0f, 0, 0, 0
        }},
    };
    return database;
}
inline const WorldEventData* GetWorldEventData(WorldEventType type) {
    const auto& db = GetWorldEventDatabase();
    auto it = db.find(type);
    return (it != db.end()) ? &it->second : nullptr;
}
#endif //TOTALBATTLE2D_WORLDEVENTS_H