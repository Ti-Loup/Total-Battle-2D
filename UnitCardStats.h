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
class UnitCardKnight_PeasantHorsemen : public Entity {
public:
    int maxEntities = 30;
    int currentEntities = 30;

    UnitCardKnight_PeasantHorsemen();
};

//Stable_T2
class UnitCardKnight_LightCavalry : public Entity {
public:
    int maxEntities = 20;
    int currentEntities = 20;

    UnitCardKnight_LightCavalry();
};
//Stable_T3
class UnitCardKnight_HeavyCavalry : public Entity {
public:
    int maxEntities = 20;
    int currentEntities = 20;

    UnitCardKnight_HeavyCavalry();
};

//BUILDING ADV. MILITARY
//Artillery_T4
class UnitCardKnight_Catapult : public Entity {
public:
    int maxEntities = 4;
    int currentEntities = 4;

    UnitCardKnight_Catapult();
};
//Artillery_T5
class UnitCardKnight_Trebuchet : public Entity {
    int maxEntities = 4;
    int currentEntities = 4;

    UnitCardKnight_Trebuchet();
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
class UnitCardViking_Peasant : public Entity {
public:
    int maxEntities = 60;
    int currentEntities = 60;

    UnitCardViking_Peasant();
};

class UnitCardViking_PeasantArchers : public Entity {
    public:
    int maxEntities = 60;
    int currentEntities = 60;
};

//Military
//WarLodge_T1
class UnitCardViking_Axemen : public Entity {
    public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardViking_Axemen();
};
//Warlodge_T2
class UnitCardViking_SwordAndShield : public Entity {
    public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardViking_SwordAndShield();
};
//Warlodge_T3
class UnitCardViking_LongAxe : public Entity {
    public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardViking_LongAxe();
};
//ShootingGround_T1
class UnitCardViking_Archers : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardViking_Archers();
};
//ShootingGround_T2
class UnitCardViking_LongbowArchers : public Entity {
    public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardViking_LongbowArchers();
} ;
//ShootingGround_T3
class UnitCardViking_EliteLongbowArchers : public Entity {
public:
    int maxEntities = 40;
    int currentEntities = 40;

    UnitCardViking_EliteLongbowArchers();
};
//HorseTraining_T1
class UnitCardViking_PeasantHorsemen : public Entity {
    public:
    int maxEntities = 30;
    int currentEntities = 30;

    UnitCardViking_PeasantHorsemen();
};
//HorseTraining_T2
class UnitCardViking_LightCavalry : public Entity {
public:
    int maxEntities = 20;
    int currentEntities = 20;

    UnitCardViking_LightCavalry();
};
//HorseTraining_T3
class UnitCardViking_HeavyCavalry : public Entity {
    public:
    int maxEntities = 20;
    int currentEntities = 20;

    UnitCardViking_HeavyCavalry();
};

//ADV.VMILITARY
//ChosensOfOdin_T3
class UnitCardViking_Berserkers : public Entity {
public:
    int maxEntities = 30;
    int currentEntities = 30;

    UnitCardViking_Berserkers();
};
//ChosensOfOdin_T4
class UnitCardViking_ArmouredBerserkers : public Entity {
public :
    int maxEntities = 30;
    int currentEntities = 30;

    UnitCardViking_ArmouredBerserkers();
};
//ChosensOfOdin_T5 (peaux de loup) elite warriors
class UnitCardViking_Ulfhednar : public Entity {
    public:
    int maxEntities = 30;
    int currentEntities = 30;

    UnitCardViking_Ulfhednar();
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