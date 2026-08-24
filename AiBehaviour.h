//
// Created by Louis-Philippe on 8/24/2026.
//
#pragma once
#ifndef TOTALBATTLE2D_AIBEHAVIOUR_H
#define TOTALBATTLE2D_AIBEHAVIOUR_H
#include "Province.h" // FactionZone
#include <unordered_map>

//Ai's Gold/Food/Population
struct AiFactionState{
    // Gold
    int currentGold = 2500;

    // Food
    int currentFood = 0;
    int foodStorage = 0;
    int foodStored = 0;

    // Population
    int currentPeasantryAmount = 1000;
    int currentNobilityAmount = 100;
    int currentClergyAmount = 10;
};

class AiBehaviour{
    public:
       void RegisterFaction(FactionZone faction, int startingGold = 2500);

       AiFactionState *GetState(FactionZone faction);

    private:
        std::unordered_map<FactionZone, AiFactionState> factionStates;

};



#endif //TOTALBATTLE2D_AIBEHAVIOUR_H
