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
    WarSign
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
    //-War Sign -> improve war stats

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
        { WorldEventsType::Storm, {
            "Storm",
            "My lord, A violent storm batters the coastline. Ships are damaged and fishing ports produce no food.",
            WorldEventCategory::Negative,
            0, 1.0f, 0, 0, 0
        }},
        { WorldEventsType::Earthquake, {
            "Earthquake",
            "My lord, A violent Earthquare has hit us. Hopefully none of our industries got affected.",
            WorldEventCategory::Negative,
            0, 1.0f, 0, 0, 0
        }},
        { WorldEventsType::Drought, {
            "Drought",
            "My Lord, It hasn't rained in 2 weeks, people are worried and the plantation is dying.",
            WorldEventCategory::Negative,
            0, 1.0f, 0, 0, 0
        }},
        { WorldEventsType::Plague, {
            "Plague",
            "My lord, a plague has pread to a settlement. It will spread inside our kingdom if we dont do something",
            WorldEventCategory::Negative,
            0, 1.0f, 0, 0, 0
        }},
        { WorldEventsType::Fire, {
            "Fire",
            "My lord, a fire spread accros the land! we bust be careful for our population",
            WorldEventCategory::Negative,
            0, 1.0f, 0, 0, 0
        }},
        { WorldEventsType::PoorPopulation, {
            "Poor Population",
            "My lord, our population is getting poorer everyday, the cost of war has a direct percution on them. We should reduce taxes to accomodate them",
            WorldEventCategory::Negative,
            0, 1.0f, 0, 0, 0
        }},
        //Good Events
        { WorldEventsType::GoodHarvest,{
            "Good Harvest",
            "My lord, there's rumors of a good recolt from our farmers. We should make a feast !",
            WorldEventCategory::Positive,
            0, 1.0f, 0, 0, 0
        }},
        { WorldEventsType::MiraculousFishCatch, {
            "Miraculous Fish Catch",
            "My lord, our fishing recold is miraculus ! A real miracle from god.",
                WorldEventCategory::Positive,
            0, 1.0f, 0, 0, 0
            }},
        { WorldEventsType::FavorableWinds,{
            "Favorable Winds",
                "My lord, the wind is on our side, our trade merchants and ships will be faster.",
            WorldEventCategory::Positive,
            0, 1.0f, 0, 0, 0
        }},
        { WorldEventsType::Justice,{
            "Justice",
                "MY lord, the wanted man known has Vitzlek has been happrenended, justice has beena served. For the greater good",
            WorldEventCategory::Positive,
            0, 1.0f, 0, 0, 0
        }},
        { WorldEventsType::NewInvension,{
            "New Invension",
                "Sir, we have been aware that our guild masters made a new extraordinary object that will help to boost the production of our goods.",
            WorldEventCategory::Positive,
            0, 1.0f, 0, 0, 0
        }},
        { WorldEventsType::WarSign,{
            "War Sign",
            "Sir, Our watchers and other members of other kingdoms saw a crow on top of a hill, It may be a sign of war?",
            WorldEventCategory::Positive,
            0, 1.0f, 0, 0, 0
        }},
    };
    return database;
}
inline const WorldEventsData* GetWorldEventData(WorldEventsType type) {
    const auto& db = GetWorldEventDatabase();
    auto it = db.find(type);
    return (it != db.end()) ? &it->second : nullptr;
}
#endif //TOTALBATTLE2D_WORLDEVENTS_H