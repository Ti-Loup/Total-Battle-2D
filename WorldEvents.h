//
// Created by lpgau on 2026-07-16.
//

#ifndef TOTALBATTLE2D_WORLDEVENTS_H
#define TOTALBATTLE2D_WORLDEVENTS_H

/**
 *
 *
 * This script is made to add differents events and to choose the right one when needed
 */
struct WorldEvents {
    //BAD EVENTS
    //METEO
    //-Storm -> Boats attritions -> No Food from MilitaryPorts/FishingPorts
    //-Seisme
    //-Dryness

    //HUMAN
    //-Plague  On 1 settlement (Public order decrease -> Population birthrate reduced, deathrate rise,) Spread across the territory during the event. Ends at the end of events
    //-Fire -> all Buildings damaged inside a settlement random per faction, public order decreasein that province
    //-
    //INVASION
    //-Viking invasion -> Random Spawn
    //-Knight Invasion -> Random Spawn
    //-Samurai Invasion -> Random Spawn

    //GOOD EVENTS
    //METEO
    //-Good harvest -> Generate more food
    //-
    //HUMAN
    //-Justice (Huge criminal got arrested and brought to justice) more order public and better legitimicy(future).
    //-New Invension from inventors brings job and happyness to the population and increase productivity of buildings
    //MERCENARIES

    enum BadWorldEvents{Storm, };
    enum GoodWorldEvents{};
};


#endif //TOTALBATTLE2D_WORLDEVENTS_H