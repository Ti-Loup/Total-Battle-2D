//
// Created by lpgau on 2026-05-19.
//

#ifndef TOTALWAR2D_UNITCARDSTATS_H
#define TOTALWAR2D_UNITCARDSTATS_H

#include "Entity.h"
#include "Components.h"
class UnitCardStats {

};
/*
DLC Units Ideas Knight
- Assassins, Centurion, Prest warriors(different categories), Gladiators


- 2 tier per units (Early game and late game units). Available in the technology tree
*/

//KNIGHT LORDS :
//todo

//KNIGHT HEROS :
//todo


//Knight Units PEASANT(TIER 0 / ALREADY UNLOCKED)
class UnitCardKnight_PeasantEarlyStage : public Entity {
    public:
    int maxEntities = 60;
    int currentEntities = 60;

    UnitCardKnight_PeasantEarlyStage();

};
class UnitCardKnight_PeasantLateStage : public Entity{
    public:
    int maxEntities = 60;
    int currentEntities = 60;

    UnitCardKnight_PeasantLateStage();
};

//PEASANT ARCHERS (TIER 0 / ALREADY UNLOCKED)
class UnitCardKnight_PeasantArchersEarlyStage : public Entity {
public:
    int maxEntities = 60;
    int currentEntities = 60;

    UnitCardKnight_PeasantArchersEarlyStage();

};

class UnitCardKnight_PeasantArchersLateStage : public Entity {
public:
    int maxEntities = 60;
    int currentEntities = 60;

    UnitCardKnight_PeasantArchersLateStage();

};

//BUILDING MILITARY
//Barracks_T1
class UnitCardKnight_SwordmenEarlyStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardKnight_SwordmenEarlyStage();
};
class UnitCardKnight_SwordmenLateStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardKnight_SwordmenLateStage();
};

//Barracks_T2
class UnitCardKnight_SwordAndShieldEarlyStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardKnight_SwordAndShieldEarlyStage();
};
class UnitCardKnight_SwordAndShieldLateStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardKnight_SwordAndShieldLateStage();
};

//Barracks_T3
class UnitCardKnight_MaceAndShieldEarlyStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardKnight_MaceAndShieldEarlyStage();
};
class UnitCardKnight_MaceAndShieldLateStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardKnight_MaceAndShieldLateStage();
};
//ArcheryRange_T1
class UnitCardKnight_HuntersEarlyStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardKnight_HuntersEarlyStage();
};
class UnitCardKnight_HuntersLateStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardKnight_HuntersLateStage();
};

//ArcheryRange_T2
class UnitCardKnight_ArchersEarlyStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardKnight_ArchersEarlyStage();
};
class UnitCardKnight_ArchersLateStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardKnight_ArchersLateStage();
};

//ArcheryRange_T3
class UnitCardKnight_LongBowmenEarlyStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardKnight_LongBowmenEarlyStage();
};
class UnitCardKnight_LongBowmenLateStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardKnight_LongBowmenLateStage();
};
//Stable_T1
class UnitCardKnight_PeasantHorsemenEarlyStage : public Entity {
public:
    int maxEntities = 30;
    int currentEntities = 30;

    UnitCardKnight_PeasantHorsemenEarlyStage();
};
class UnitCardKnight_PeasantHorsemenLateStage : public Entity {
public:
    int maxEntities = 30;
    int currentEntities = 30;

    UnitCardKnight_PeasantHorsemenLateStage();
};

//Stable_T2
class UnitCardKnight_LightCavalryEarlyStage : public Entity {
public:
    int maxEntities = 20;
    int currentEntities = 20;

    UnitCardKnight_LightCavalryEarlyStage();
};
class UnitCardKnight_LightCavalryLateStage : public Entity {
public:
    int maxEntities = 20;
    int currentEntities = 20;

    UnitCardKnight_LightCavalryLateStage();
};
//Stable_T3
class UnitCardKnight_HeavyCavalryEarlyStage : public Entity {
public:
    int maxEntities = 20;
    int currentEntities = 20;

    UnitCardKnight_HeavyCavalryEarlyStage();
};
class UnitCardKnight_HeavyCavalryLateStage : public Entity {
public:
    int maxEntities = 20;
    int currentEntities = 20;

    UnitCardKnight_HeavyCavalryLateStage();
};

//BUILDING ADV. MILITARY
//Artillery_T4
class UnitCardKnight_CatapultEarlyStage : public Entity {
public:
    int maxEntities = 4;
    int currentEntities = 4;

    UnitCardKnight_CatapultEarlyStage();
};
class UnitCardKnight_CatapultLateStage : public Entity {
public:
    int maxEntities = 4;
    int currentEntities = 4;

    UnitCardKnight_CatapultLateStage();
};
//Artillery_T5
class UnitCardKnight_TrebuchetEarlyStage : public Entity {
    int maxEntities = 4;
    int currentEntities = 4;

    UnitCardKnight_TrebuchetEarlyStage();
};
class UnitCardKnight_TrebuchetLateStage : public Entity {
    int maxEntities = 4;
    int currentEntities = 4;

    UnitCardKnight_TrebuchetLateStage();
};

//Religion (future dlc for religious troops)
//////////////////////////////////////////

//VIKING UNITS
//Possible Unit DLC : Big Hammer, Seer, boats

//Viking LORDS :
//todo

//Viking HEROS :
//todo Shaman

//Viking Units PEASANTS(TIER 0 / ALREADY UNLOCKED)
class UnitCardViking_PeasantEarlyStage : public Entity {
public:
    int maxEntities = 60;
    int currentEntities = 60;

    UnitCardViking_PeasantEarlyStage();
};
class UnitCardViking_PeasantLateStage : public Entity {
public:
    int maxEntities = 60;
    int currentEntities = 60;

    UnitCardViking_PeasantLateStage();
};
class UnitCardViking_PeasantArchersEarlyStage : public Entity {
    public:
    int maxEntities = 60;
    int currentEntities = 60;

    UnitCardViking_PeasantArchersEarlyStage();
};
class UnitCardViking_PeasantArchersLateStage : public Entity {
public:
    int maxEntities = 60;
    int currentEntities = 60;

    UnitCardViking_PeasantArchersLateStage();
};

//Military
//WarLodge_T1
class UnitCardViking_AxemenEarlyStage : public Entity {
    public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardViking_AxemenEarlyStage();
};
class UnitCardViking_AxemenLateStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardViking_AxemenLateStage();
};
//Warlodge_T2
class UnitCardViking_SwordAndShieldEarlyStage : public Entity {
    public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardViking_SwordAndShieldEarlyStage();
};
class UnitCardViking_SwordAndShieldLateStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardViking_SwordAndShieldLateStage();
};

//Warlodge_T3
class UnitCardViking_LongAxeEarlyStage : public Entity {
    public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardViking_LongAxeEarlyStage();
};
class UnitCardViking_LongAxeLateStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardViking_LongAxeLateStage();
};

//ShootingGround_T1
class UnitCardViking_ArchersEarlyStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardViking_ArchersEarlyStage();
};
class UnitCardViking_ArchersLateStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardViking_ArchersLateStage();
};

//ShootingGround_T2
class UnitCardViking_LongbowArchersEarlyStage : public Entity {
    public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardViking_LongbowArchersEarlyStage();
} ;
class UnitCardViking_LongbowArchersLateStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardViking_LongbowArchersLateStage();
} ;

//ShootingGround_T3
class UnitCardViking_EliteLongbowArchersEarlyStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardViking_EliteLongbowArchersEarlyStage();
};
class UnitCardViking_EliteLongbowArchersLateStage : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardViking_EliteLongbowArchersLateStage();
};

//HorseTraining_T1
class UnitCardViking_PeasantHorsemenEarlyStage : public Entity {
    public:
    int maxEntities = 30;
    int currentEntities = 30;

    UnitCardViking_PeasantHorsemenEarlyStage();
};
class UnitCardViking_PeasantHorsemenLateStage : public Entity {
public:
    int maxEntities = 30;
    int currentEntities = 30;

    UnitCardViking_PeasantHorsemenLateStage();
};

//HorseTraining_T2
class UnitCardViking_LightCavalryEarlyStage : public Entity {
public:
    int maxEntities = 20;
    int currentEntities = 20;

    UnitCardViking_LightCavalryEarlyStage();
};
class UnitCardViking_LightCavalryLateStage : public Entity {
public:
    int maxEntities = 20;
    int currentEntities = 20;

    UnitCardViking_LightCavalryLateStage();
};

//HorseTraining_T3
class UnitCardViking_HeavyCavalryEarlyStage : public Entity {
    public:
    int maxEntities = 20;
    int currentEntities = 20;

    UnitCardViking_HeavyCavalryEarlyStage();
};
class UnitCardViking_HeavyCavalryLateStage : public Entity {
public:
    int maxEntities = 20;
    int currentEntities = 20;

    UnitCardViking_HeavyCavalryLateStage();
};

//ADV.VMILITARY
//ChosensOfOdin_T3
class UnitCardViking_BerserkersEarlyStage : public Entity {
public:
    int maxEntities = 30;
    int currentEntities = 30;

    UnitCardViking_BerserkersEarlyStage();
};
class UnitCardViking_BerserkersLateStage : public Entity {
public:
    int maxEntities = 30;
    int currentEntities = 30;

    UnitCardViking_BerserkersLateStage();
};

//ChosensOfOdin_T4
class UnitCardViking_ArmouredBerserkersEarlyStage : public Entity {
public :
    int maxEntities = 30;
    int currentEntities = 30;

    UnitCardViking_ArmouredBerserkersEarlyStage();
};
class UnitCardViking_ArmouredBerserkersLateStage : public Entity {
public :
    int maxEntities = 30;
    int currentEntities = 30;

    UnitCardViking_ArmouredBerserkersLateStage();
};
//ChosensOfOdin_T5 (peaux de loup) elite warriors
class UnitCardViking_UlfhednarEarlyStage : public Entity {
    public:
    int maxEntities = 30;
    int currentEntities = 30;

    UnitCardViking_UlfhednarEarlyStage();
};
class UnitCardViking_UlfhednarLateStage : public Entity {
public:
    int maxEntities = 30;
    int currentEntities = 30;

    UnitCardViking_UlfhednarLateStage();
};
//Religion Future dlc
////////////////////////////////////
//SAMURAI Units
//DLC IDEAS : ninjas, double sword samurai, Big Boy

//Samurai LORDS

//Samurai Heros

//Samurai Tier 0 Units
class UnitCardSamurai_Peasants : public Entity {
    public:
    int maxEntities = 60;
    int currentEntities = 60;

    UnitCardSamurai_Peasants();
};
class UnitCardSamurai_PeasantArchers : public Entity {
    public:
    int maxEntities = 60;
    int currentEntities = 60;

    UnitCardSamurai_PeasantArchers();
};
//MILITARY
//SwordSchool_T1
class UnitCardSamurai_YariAshigaru : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardSamurai_YariAshigaru();
};
//SwordSchool_T2nSamurai
class UnitCardSamurai_KatanaSamurai : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardSamurai_KatanaSamurai();
};
//SwordSchool_T3
class UnitCardSamurai_NoDachiSamurai : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardSamurai_NoDachiSamurai();
};
//ArcheryDojo_T1
class UnitCardSamurai_BowAshigaru : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardSamurai_BowAshigaru();
};
//ArcheryDojo_T2
class UnitCardSamurai_BowSamurai : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardSamurai_BowSamurai();
};
//ArcheryDojo_T3
class UnitCardSamurai_EliteBowSamurai : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardSamurai_EliteBowSamurai();
};
//WarhorseStable_T1
class UnitCardSamurai_PeasantHorsemen : public Entity {
public:
    int maxEntities = 30;
    int currentEntities = 30;

    UnitCardSamurai_PeasantHorsemen();
};
//WarhorseStabe_T2
class UnitCardSamurai_KatanaCavalry : public Entity {
public:
    int maxEntities = 20;
    int currentEntities = 20;

    UnitCardSamurai_KatanaCavalry();
};
//WarhorseStable_T3
class UnitCardSamurai_EliteYariCavalry : public Entity {
public:
    int maxEntities = 20;
    int currentEntities = 20;

    UnitCardSamurai_EliteYariCavalry();
};

//ADV. MILITARY
//SiegeEngineerWorkshop_T4
class UnitCardSamurai_FireProjectingMangonels : public Entity {
public:
    int maxEntities = 4;
    int currentEntities = 4;

    UnitCardSamurai_FireProjectingMangonels();
};
//SiegeEngineerWorkshop_T5
class UnitCardSamurai_EuropeanCannons : public Entity {
public:
    int maxEntities = 4;
    int currentEntities = 4;

    UnitCardSamurai_EuropeanCannons();
};
//GunSmith_T4
class UnitCardSamurai_MatchlockSamurai : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardSamurai_MatchlockSamurai();
};
//GunSmith_T5
class UnitCardSamurai_PortugueseTercos : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardSamurai_PortugueseTercos();
};

//RELIGION Troops monks(DLC)

#endif //TOTALWAR2D_UNITCARDSTATS_H