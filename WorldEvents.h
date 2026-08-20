//
// Created by lpgau on 2026-07-16.
//

#ifndef TOTALBATTLE2D_WORLDEVENTS_H
#define TOTALBATTLE2D_WORLDEVENTS_H

#include <string>
#include <unordered_map>
#include <vector>
#include "Buildings.h" // for TaxCategory && GetTaxCategory
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
    //public Order
    int publicOrderModifier = 0;
    //food production based on its Category
    float foodProductionFarmMultiplier = 1.0f;
    float foodProductionMaritimeMultiplier = 1.0f;
    int foodFlatBonus = 0;
    // Ressources Production
    float resourceFishingProductionMultiplier = 1.0f;
    //gold
    float goldIncomeFarmMultiplier = 1.0f;
    float goldIncomeCommerceMultiplier = 1.0f;
    float goldIncomeIndustryMultiplier = 1.0f;
    float goldIncomeReligionMultiplier = 1.0f;
    float goldIncomeMaritimeMultiplier = 1.0f;
    int goldFlatBonus = 0;
    //population Birth
    float populationGrowthPaysantryMultiplier = 1.0f;
    float populationGrowthNobilityMultiplier = 1.0f;
    float populationGrowthClergyMultiplier = 1.0f;
    //Population Death
    float populationDeathPaysantryMultiplier = 1.0f;
    float populationDeathNobilityMultiplier = 1.0f;
    float populationDeathClergyMultiplier = 1.0f;
    //Time
    int durationTurns = 1;
};
//Database of all Events
//Public Order, foodProductionFarmMultiplier, foodProductionMaritimeMultiplier, foodFlatBonus, resourceFishingProductionMultiplier,
//goldIncomeFarmMultiplier, goldIncomeCommerceMultiplier, goldIncomeIndustryMultiplier, goldIncomeReligionMultiplier, goldIncomeMaritimeMultiplier, goldFlatBonus
//populationGrowthPaysantryMultiplier, populationGrowthNobilityMultiplier, populationGrowthClergyMultiplier,
//populationDeathPaysantryMultiplier, populationDeathNobilityMultiplier, populationDeathClergyMultiplier, durationTurns
inline const std::unordered_map<WorldEventsType, WorldEventsData>& GetWorldEventDatabase(){
    static const std::unordered_map<WorldEventsType, WorldEventsData> database = {
        //general
        { WorldEventsType::Storm, {
            "Storm",
            "My lord, A violent storm batters the coastline. Ships are damaged and fishing ports produce no food.",
            WorldEventCategory::Negative,
            //Food production maritime 0
            //Fish Production 0
            //income maritime 0
            //Food From farm stay the same -> Food from Maritime 0
            0, 1.0f, 0.0f, 0, 0.0f, 1.0f,1.0f, 1.0f,1.0f,0.0f, 0, 1.0f, 1.0f,1.0f, 1.0f,1.0f,1.0f ,5
        }},
        //Own mechanic
        { WorldEventsType::Earthquake, {
            "Earthquake",
            "My lord, A violent Earthquare has hit our land. Hopefully none of our industries got affected.",
            //Buildings get damaged, nothing is produced if the building is damaged. must be repared first.
            WorldEventCategory::Negative,
            0, 1.0f,1.0f, 0, 1.0f, 1.0f, 1.0f,1.0f,1.0f,1.0f,0, 1.0f,1.0f,1.0f, 1.0f, 1.0f, 1.0f, 5
        }},
        //general
        { WorldEventsType::Drought, {
            "Drought",
            "My Lord, It hasn't rained in 2 weeks, people are worried and the plantation is dying.",
            WorldEventCategory::Negative,
            //Food Production -80% Farm
            //Income Farm -80%
            // Population -2 happyness
            // Population Growth paysantry -40%
            -2, 0.2f,1.0f, 0, 1.0f, 0.2f, 1.0f,1.0f,1.0f,1.0f,0, 0.6f,1.0f,1.0f, 1.0f, 1.0f, 1.0f, 5
        }},
        //Own mechanic
        { WorldEventsType::Plague, {
            "Plague",
            "My lord, a plague has pread to a settlement. It will spread quick acrost the world.",
            WorldEventCategory::Negative,
            //Public Order -2 per infected settlement.(if 4 settlements affected then -4 in same region or -3 and -1 if merged in 2 provinces).
            //Death rate x1.8 per infected settlement.
            //Food produced Farm Multiplier x0.4 for the settlement touched
            //Food produced Maritime Multiplier x0.4 for the settlement touched
            // gold income x0.4 for all type
            -2, 0.4f,0.4f , 0, 1.0f, 0.4f, 0.4f,0.4f,0.4f,0.4f,0, 1.0f,1.0f,1.0f, 1.8f, 1.8f, 1.8f, 7
        }},
        //Own mechanic
        { WorldEventsType::Fire, {
            "Fire",
            "My lord, a fire spread accros the land! we bust be careful for our population",
            //Death Rate x1.8 per settlements
            //Buildings are damaged
            //public order -2 per settlements
            //Food produced 0 (from damaged buildings)
            //income 0
            //not modified because damaged buildings makes them at 0
            WorldEventCategory::Negative,
            -2, 1.0f,1.0f, 0, 1.0f, 1.0f, 1.0f,1.0f,1.0f,1.0f,0, 1.0f,1.0f,1.0f, 1.8f, 1.8f, 1.8f, 7
        }},
        //general
        { WorldEventsType::PoorPopulation, {
            "Poor Population",
            "My lord, our population is getting poorer everyday, the cost of war has a direct percution on them. We should reduce taxes to accomodate them",
            WorldEventCategory::Negative,
            //Population reduced
            //Paysantry birthrate reduce
            //Paysantry Deathrate increase
            -3, 1.0f,1.0f, 0, 1.0f, 1.0f, 1.0f,1.0f,1.0f,1.0f,0, 0.4f,1.0f,1.0f, 1.4f, 1.0f, 1.0f, 5
        }},
        //Good Events
        //general
        { WorldEventsType::GoodHarvest,{
            "Good Harvest",
            "My lord, there's rumors of a good recolt from our farmers. We should make a feast !",
            WorldEventCategory::Positive,
            //Public Order +2
            //Food Farm production + 50%
            //Food Flat Bonus +25
            //Gold Income Farm +10%
            2, 1.5f,1.0f, 25, 1.0f, 1.1f, 1.0f,1.0f,1.0f,1.0f,0, 1.0f,1.0f,1.0f, 1.0f, 1.0f, 1.0f, 5
        }},
        //general
        { WorldEventsType::MiraculousFishCatch, {
            "Miraculous Fish Catch",
            "My lord, our fishing recolt is miraculus ! A real miracle from god.",
                WorldEventCategory::Positive,
                //Food Maritime production + 40%
                //Resource Fishing production + 50%
                //Gold Income Maritime +20%
            0, 1.0f,1.4f, 0, 1.5f, 1.0f, 1.0f,1.0f,1.0f,1.2f,0, 1.0f,1.0f,1.0f, 1.0f, 1.0f, 1.0f, 5
            }},
        //general + own mechanic when boats
        { WorldEventsType::FavorableWinds,{
            "Favorable Winds",
                "My lord, the wind is on our side, our trade merchants and ships will be faster.",
            WorldEventCategory::Positive,
            //gold from industry +25%
            0, 1.0f,1.0f, 0, 1.0f, 1.0f, 1.0f,1.25f,1.0f,1.0f,0, 1.0f,1.0f,1.0f, 1.0f, 1.0f, 1.0f, 5
        }},
        //Own Mecanic
        { WorldEventsType::Justice,{
            "Justice",
                "My lord, the fugitive known as Vitzlek has been captured. He claims noble blood and offers gold for his freedom. Will you protect him in secret, or hang him for the world to see.",
            WorldEventCategory::Positive,
            0, 1.0f,1.0f, 0, 1.0f, 1.0f, 1.0f,1.0f,1.0f,1.0f,0, 1.0f,1.0f,1.0f, 1.0f, 1.0f, 1.0f, 5
        }},
        //Own mechanic -> which branch the new invension go towards. Player must decide. (Toward industry, farm, commerce, maritime)
        { WorldEventsType::NewInvension,{
            "New Invension",
                "Sir, we have been aware that our guild masters made a new extraordinary object that will help to boost the production of our goods.",
            WorldEventCategory::Positive,
            //public order -1 (Scared)
            -1, 1.0f,1.0f, 0, 1.0f, 1.0f, 1.0f,1.0f,1.0f,1.0f,0, 1.0f,1.0f,1.0f, 1.0f, 1.0f, 1.0f, 5
        }},
        //general (Future)
        { WorldEventsType::WarSign,{
            "War Sign",
            "Sir, Our watchers and other members of other kingdoms saw a crow on top of a hill, It may be a sign of war?",
            WorldEventCategory::Positive,
            0, 1.0f,1.0f, 0, 1.0f, 1.0f, 1.0f,1.0f,1.0f,1.0f,0, 1.0f,1.0f,1.0f, 1.0f, 1.0f, 1.0f, 5
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