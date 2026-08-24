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
    int nextTurnFood = 0;
    int foodStorage = 0;
    int foodStored = 0;

    // Population
    int currentPeasantryAmount = 1000;
    int currentNobilityAmount = 100;
    int currentClergyAmount = 10;

   // Base birth/death rates. Re-randomized every turn. Same has Player
    int basePeasantryBirth = 40 + rand() % 21; // 40-60
    int basePeasantryDeath = 25 + rand() % 16; // 25-40
    int baseNobilityBirth  = 8 + rand() % 13;  // 8-20
    int baseNobilityDeath  = 2 + rand() % 9;   // 2-10
    int baseClergyGrowth   = 1 + rand() % 5;   // 1-5
    int baseClergyDeath    = 1 + rand() % 4;   // 1-4
};

class AiBehaviour{
    public:
       void RegisterFaction(FactionZone faction, int startingGold = 2500);

       AiFactionState *GetState(FactionZone faction);

    private:
        std::unordered_map<FactionZone, AiFactionState> factionStates;

};



#endif //TOTALBATTLE2D_AIBEHAVIOUR_H
