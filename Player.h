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
    //Improved Growth
    //peasantry
    int basePeasantryBirth = 75;
    int basePeasantryDeath = 28;
    int buildingPeasantryBonus = 0;
    int nextTurnPeasantry = 0;
    //nobility
    int baseNobilityBirth = 12;
    int baseNobilityDeath = 4;
    int buildingNobilityBonus = 0;
    int nextTurnNobility = 0;
    //clergy
    int baseClergyGrowth = 3;
    int baseClergyDeath = 1;
    int buildingClergy = 0;
    int nextTurnClergy = 0;
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
