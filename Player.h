//
// Created by Louis-Philippe on 4/14/2026.
//

#ifndef TOTALWAR2D_PLAYER_H
#define TOTALWAR2D_PLAYER_H

#include "Entity.h"
#include "State.h"
#include "Buildings.h"
class Player : public Entity {
public :
    int currentGold = 2500;
    int nextTurnGold = 0;//next turn money
    //food
    int currentFood = 0;
    int nextTurnFood = 0;
    //Food Storage
    int foodStorage = 0;// 50 base storage per Capital Main settlement and 25 for Castle Main settlement.
    int foodStored = 0; // for stored each turn. Cant go higher than the food Storage available
    //Goods Storage
    int currentGoods = 0;
    int goodsStorage = 0;
    //Improved Growth
    //peasantry Random
    int basePeasantryBirth = 70 + rand() % 21;   // 70-90
    int basePeasantryDeath = 25 + rand() % 16;    // 25-40
    int currentPeasantryAmount = 0;
    int nextTurnPeasantryAmount = 0;
    //nobility
    int baseNobilityBirth = 8 + rand() % 13; // 8-12
    int baseNobilityDeath = 2 + rand() % 9; // 2-8
    int currentNobilityAmount = 0;
    int nextTurnNobilityAmount = 0;
    //clergy
    int baseClergyGrowth = 1 + rand() % 5; // 1-4
    int baseClergyDeath = 1 + rand () %4; // 1-3
    int currentClergyAmount = 0;
    int nextTurnClergyAmount = 0;
    //default faction played by user
    FactionZone faction = FactionZone::Knight;

    int GetUpgradeCost(int fromBuildingTier, BuildingType type);
    void AddGold(int amount);
    bool SpendGold(int amount);//if enought money than buy ->

    Player (SDL_Texture *texture = nullptr);
    ~Player();

    //texture du Player
       SDL_Texture  *texturePlayer = nullptr;

};



#endif //TOTALWAR2D_PLAYER_H
