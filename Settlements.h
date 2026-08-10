//
// Created by Louis-Philippe on 4/22/2026.
//

#ifndef TOTALWAR2D_SETTLEMENTS_H
#define TOTALWAR2D_SETTLEMENTS_H
#include "Entity.h"
#include "State.h"
#include "Components.h"
#include "Province.h"
class Settlement : public Entity {
    public:
    SettlementComponent settlementData;
    int tileCol = 0;
    int tileRow = 0;

    Settlement(SettlementType type, int provinceID, int col, int row,FactionZone faction);

    //If village&castle close to ocean
    bool bIsPort = false;
    //Raw Buildings
    bool bIsIronMine = false;
    bool bIsGoldMine = false;
    bool bIsCopperMine = false;
    bool bIsSilverMine = false;
    bool bIsTinMine = false;
    bool bIsLumberMine = false;
    bool bIsSheepPasture = false;//for textile

};

#endif //TOTALWAR2D_SETTLEMENTS_H
