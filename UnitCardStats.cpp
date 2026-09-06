//
// Created by lpgau on 2026-05-19.
//

#include "UnitCardStats.h"
#include "Components.h"
#include <SDL3_image/SDL_image.h>

/*
 *Knights -> Strong cavalery and armour, less melee stats
 *Viking -> Strong Melee Stats. Less armour
 *Samurai -> Strong movement and Archers, weak armour and health
 *
 *Late games units has a bonus +
 */
//fix le speed
//


//KNIGHT UNIT CARDS STATS
//(TIER 0)
UnitCardKnight_PeasantEarlyStage::UnitCardKnight_PeasantEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 9400;
    health.current_health = 9400;
    health.max_Armour = 8;
    health.current_Armour = 8;
    health.max_leadership = 60;
    health.current_leadership = 60;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 12;
    meleeStats.current_meleeAttack = 12;
    meleeStats.max_meleeDefence = 4;
    meleeStats.current_meleeDefence = 4;
    meleeStats.max_weaponStrengh = 14;
    meleeStats.current_weaponStrengh = 14;
    meleeStats.max_chargeBonus = 12;
    meleeStats.current_chargeBonus = 12;
    AddComponent(RENDER);

    // Amount of Entities in this UnitCard
    // int maxEntities = 60;
    // int currentEntities = 60;
}

UnitCardKnight_PeasantLateStage::UnitCardKnight_PeasantLateStage() {
    AddComponent(HEALTH);
    health.max_health = 9400;
    health.current_health = 9400;
    health.max_Armour = 8;
    health.current_Armour = 8;
    health.max_leadership = 60;
    health.current_leadership = 60;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 12;
    meleeStats.current_meleeAttack = 12;
    meleeStats.max_meleeDefence = 4;
    meleeStats.current_meleeDefence = 4;
    meleeStats.max_weaponStrengh = 14;
    meleeStats.current_weaponStrengh = 14;
    meleeStats.max_chargeBonus = 12;
    meleeStats.current_chargeBonus = 12;
    AddComponent(RENDER);

    // Amount of Entities in this UnitCard
    // int maxEntities = 60;
    // int currentEntities = 60;
}

UnitCardKnight_PeasantArchersEarlyStage::UnitCardKnight_PeasantArchersEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 4500;
    health.current_health = 4500;
    health.max_Armour = 6;
    health.current_Armour = 6;
    health.max_leadership = 62;
    health.current_leadership = 62;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 5;
    meleeStats.current_meleeAttack = 5;
    meleeStats.max_meleeDefence = 7;
    meleeStats.current_meleeDefence = 7;
    meleeStats.max_weaponStrengh = 8;
    meleeStats.current_weaponStrengh = 8;
    meleeStats.max_chargeBonus = 3;
    meleeStats.current_chargeBonus = 3;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 18;
    rangedStats.current_ammunition = 18;
    rangedStats.max_range = 120;
    rangedStats.current_range = 120;
    rangedStats.max_missileDamage = 14;
    rangedStats.current_missileDamage = 14;
    AddComponent(RENDER);
}

UnitCardKnight_PeasantArchersLateStage::UnitCardKnight_PeasantArchersLateStage() {
    AddComponent(HEALTH);
    health.max_health = 4500;
    health.current_health = 4500;
    health.max_Armour = 6;
    health.current_Armour = 6;
    health.max_leadership = 62;
    health.current_leadership = 62;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 5;
    meleeStats.current_meleeAttack = 5;
    meleeStats.max_meleeDefence = 7;
    meleeStats.current_meleeDefence = 7;
    meleeStats.max_weaponStrengh = 8;
    meleeStats.current_weaponStrengh = 8;
    meleeStats.max_chargeBonus = 3;
    meleeStats.current_chargeBonus = 3;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 18;
    rangedStats.current_ammunition = 18;
    rangedStats.max_range = 120;
    rangedStats.current_range = 120;
    rangedStats.max_missileDamage = 14;
    rangedStats.current_missileDamage = 14;
    AddComponent(RENDER);
}

//TIER 1 MILITARY TROOPS
//Barracks_T1
UnitCardKnight_SwordmenEarlyStage::UnitCardKnight_SwordmenEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 6800;
    health.current_health = 6800;
    health.max_Armour = 35;
    health.current_Armour = 35;
    health.max_leadership = 70;
    health.current_leadership = 70;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 24;
    meleeStats.current_meleeAttack = 24;
    meleeStats.max_meleeDefence = 11;
    meleeStats.current_meleeDefence = 11;
    meleeStats.max_weaponStrengh = 24;
    meleeStats.current_weaponStrengh = 24;
    meleeStats.max_chargeBonus = 20;
    meleeStats.current_chargeBonus = 20;
    AddComponent(RENDER);
}
UnitCardKnight_SwordmenLateStage::UnitCardKnight_SwordmenLateStage() {
    AddComponent(HEALTH);
    health.max_health = 6800;
    health.current_health = 6800;
    health.max_Armour = 35;
    health.current_Armour = 35;
    health.max_leadership = 70;
    health.current_leadership = 70;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 24;
    meleeStats.current_meleeAttack = 24;
    meleeStats.max_meleeDefence = 11;
    meleeStats.current_meleeDefence = 11;
    meleeStats.max_weaponStrengh = 24;
    meleeStats.current_weaponStrengh = 24;
    meleeStats.max_chargeBonus = 20;
    meleeStats.current_chargeBonus = 20;
    AddComponent(RENDER);
}


//Barracks_T2
UnitCardKnight_SwordAndShieldEarlyStage::UnitCardKnight_SwordAndShieldEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 7600;
    health.current_health = 7600;
    health.max_Armour = 55;
    health.current_Armour = 55;
    health.max_leadership = 80;
    health.current_leadership = 80;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 14;
    meleeStats.current_meleeAttack = 14;
    meleeStats.max_meleeDefence = 26;
    meleeStats.current_meleeDefence = 26;
    meleeStats.max_weaponStrengh = 26;
    meleeStats.current_weaponStrengh = 26;
    meleeStats.max_chargeBonus = 20;
    meleeStats.current_chargeBonus = 20;
    AddComponent(RENDER);
}
UnitCardKnight_SwordAndShieldLateStage::UnitCardKnight_SwordAndShieldLateStage() {
    AddComponent(HEALTH);
    health.max_health = 7600;
    health.current_health = 7600;
    health.max_Armour = 55;
    health.current_Armour = 55;
    health.max_leadership = 80;
    health.current_leadership = 80;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 14;
    meleeStats.current_meleeAttack = 14;
    meleeStats.max_meleeDefence = 26;
    meleeStats.current_meleeDefence = 26;
    meleeStats.max_weaponStrengh = 26;
    meleeStats.current_weaponStrengh = 26;
    meleeStats.max_chargeBonus = 20;
    meleeStats.current_chargeBonus = 20;
    AddComponent(RENDER);
}

//Barracks_T3
UnitCardKnight_MaceAndShieldEarlyStage::UnitCardKnight_MaceAndShieldEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 8200;
    health.current_health = 8200;
    health.max_Armour = 70;
    health.current_Armour = 70;
    health.max_leadership = 60;
    health.current_leadership = 60;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 24;
    meleeStats.current_meleeAttack = 24;
    meleeStats.max_meleeDefence = 28;
    meleeStats.current_meleeDefence = 28;
    meleeStats.max_weaponStrengh = 38;
    meleeStats.current_weaponStrengh = 38;
    meleeStats.max_chargeBonus = 26;
    meleeStats.current_chargeBonus = 26;
    AddComponent(RENDER);
}
UnitCardKnight_MaceAndShieldLateStage::UnitCardKnight_MaceAndShieldLateStage() {
    AddComponent(HEALTH);
    health.max_health = 8200;
    health.current_health = 8200;
    health.max_Armour = 70;
    health.current_Armour = 70;
    health.max_leadership = 60;
    health.current_leadership = 60;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 24;
    meleeStats.current_meleeAttack = 24;
    meleeStats.max_meleeDefence = 28;
    meleeStats.current_meleeDefence = 28;
    meleeStats.max_weaponStrengh = 38;
    meleeStats.current_weaponStrengh = 38;
    meleeStats.max_chargeBonus = 26;
    meleeStats.current_chargeBonus = 26;
    AddComponent(RENDER);
}

//ArcheryRange_T1
UnitCardKnight_HuntersEarlyStage::UnitCardKnight_HuntersEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 5200;
    health.current_health = 5200;
    health.max_Armour = 20;
    health.current_Armour = 20;
    health.max_leadership = 70;
    health.current_leadership = 70;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 8;
    meleeStats.current_meleeAttack = 8;
    meleeStats.max_meleeDefence = 10;
    meleeStats.current_meleeDefence = 10;
    meleeStats.max_weaponStrengh = 14;
    meleeStats.current_weaponStrengh = 14;
    meleeStats.max_chargeBonus = 8;
    meleeStats.current_chargeBonus = 8;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 21;
    rangedStats.current_ammunition = 21;
    rangedStats.max_range = 140;
    rangedStats.current_range = 140;
    rangedStats.max_missileDamage = 21;
    rangedStats.current_missileDamage = 21;
    AddComponent(RENDER);
}
UnitCardKnight_HuntersLateStage::UnitCardKnight_HuntersLateStage() {
    AddComponent(HEALTH);
    health.max_health = 5200;
    health.current_health = 5200;
    health.max_Armour = 20;
    health.current_Armour = 20;
    health.max_leadership = 70;
    health.current_leadership = 70;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 8;
    meleeStats.current_meleeAttack = 8;
    meleeStats.max_meleeDefence = 10;
    meleeStats.current_meleeDefence = 10;
    meleeStats.max_weaponStrengh = 14;
    meleeStats.current_weaponStrengh = 14;
    meleeStats.max_chargeBonus = 8;
    meleeStats.current_chargeBonus = 8;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 21;
    rangedStats.current_ammunition = 21;
    rangedStats.max_range = 140;
    rangedStats.current_range = 140;
    rangedStats.max_missileDamage = 21;
    rangedStats.current_missileDamage = 21;
    AddComponent(RENDER);
}

//ArcheryRange_T2
UnitCardKnight_ArchersEarlyStage::UnitCardKnight_ArchersEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 5600;
    health.current_health = 5600;
    health.max_Armour = 45;
    health.current_Armour = 45;
    health.max_leadership = 75;
    health.current_leadership = 75;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 8;
    meleeStats.current_meleeAttack = 8;
    meleeStats.max_meleeDefence = 10;
    meleeStats.current_meleeDefence = 10;
    meleeStats.max_weaponStrengh = 14;
    meleeStats.current_weaponStrengh = 14;
    meleeStats.max_chargeBonus = 8;
    meleeStats.current_chargeBonus = 8;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 21;
    rangedStats.current_ammunition = 21;
    rangedStats.max_range = 140;
    rangedStats.current_range = 140;
    rangedStats.max_missileDamage = 24;
    rangedStats.current_missileDamage = 24;
    AddComponent(RENDER);
}
UnitCardKnight_ArchersLateStage::UnitCardKnight_ArchersLateStage() {
    AddComponent(HEALTH);
    health.max_health = 5600;
    health.current_health = 5600;
    health.max_Armour = 45;
    health.current_Armour = 45;
    health.max_leadership = 75;
    health.current_leadership = 75;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 8;
    meleeStats.current_meleeAttack = 8;
    meleeStats.max_meleeDefence = 10;
    meleeStats.current_meleeDefence = 10;
    meleeStats.max_weaponStrengh = 14;
    meleeStats.current_weaponStrengh = 14;
    meleeStats.max_chargeBonus = 8;
    meleeStats.current_chargeBonus = 8;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 21;
    rangedStats.current_ammunition = 21;
    rangedStats.max_range = 140;
    rangedStats.current_range = 140;
    rangedStats.max_missileDamage = 24;
    rangedStats.current_missileDamage = 24;
    AddComponent(RENDER);
}

//ArcheryRange_T3
UnitCardKnight_LongBowmenEarlyStage::UnitCardKnight_LongBowmenEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 5400;
    health.current_health = 5400;
    health.max_Armour = 30;
    health.current_Armour = 30;
    health.max_leadership = 85;
    health.current_leadership = 85;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 6;
    meleeStats.current_meleeAttack = 6;
    meleeStats.max_meleeDefence = 12;
    meleeStats.current_meleeDefence = 12;
    meleeStats.max_weaponStrengh = 14;
    meleeStats.current_weaponStrengh = 14;
    meleeStats.max_chargeBonus = 7;
    meleeStats.current_chargeBonus = 7;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 19;
    rangedStats.current_ammunition = 19;
    rangedStats.max_range = 180;
    rangedStats.current_range = 180;
    rangedStats.max_missileDamage = 38;
    rangedStats.current_missileDamage = 38;
    AddComponent(RENDER);
}
UnitCardKnight_LongBowmenLateStage::UnitCardKnight_LongBowmenLateStage() {
    AddComponent(HEALTH);
    health.max_health = 5400;
    health.current_health = 5400;
    health.max_Armour = 30;
    health.current_Armour = 30;
    health.max_leadership = 85;
    health.current_leadership = 85;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 6;
    meleeStats.current_meleeAttack = 6;
    meleeStats.max_meleeDefence = 12;
    meleeStats.current_meleeDefence = 12;
    meleeStats.max_weaponStrengh = 14;
    meleeStats.current_weaponStrengh = 14;
    meleeStats.max_chargeBonus = 7;
    meleeStats.current_chargeBonus = 7;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 19;
    rangedStats.current_ammunition = 19;
    rangedStats.max_range = 180;
    rangedStats.current_range = 180;
    rangedStats.max_missileDamage = 38;
    rangedStats.current_missileDamage = 38;
    AddComponent(RENDER);
}

//Stable_T1
UnitCardKnight_PeasantHorsemenEarlyStage::UnitCardKnight_PeasantHorsemenEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 6000;
    health.current_health = 6000;
    health.max_Armour = 15;
    health.current_Armour = 15;
    health.max_leadership = 65;
    health.current_leadership = 65;
    AddComponent(MOVEMENT);
    movement.velocity = {3.0f,3.0f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 10;
    meleeStats.current_meleeAttack = 10;
    meleeStats.max_meleeDefence = 8;
    meleeStats.current_meleeDefence = 8;
    meleeStats.max_weaponStrengh = 16;
    meleeStats.current_weaponStrengh = 16;
    meleeStats.max_chargeBonus = 28;
    meleeStats.current_chargeBonus = 28;
    AddComponent(RENDER);
}
UnitCardKnight_PeasantHorsemenLateStage::UnitCardKnight_PeasantHorsemenLateStage() {
    AddComponent(HEALTH);
    health.max_health = 6000;
    health.current_health = 6000;
    health.max_Armour = 15;
    health.current_Armour = 15;
    health.max_leadership = 65;
    health.current_leadership = 65;
    AddComponent(MOVEMENT);
    movement.velocity = {3.0f,3.0f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 10;
    meleeStats.current_meleeAttack = 10;
    meleeStats.max_meleeDefence = 8;
    meleeStats.current_meleeDefence = 8;
    meleeStats.max_weaponStrengh = 16;
    meleeStats.current_weaponStrengh = 16;
    meleeStats.max_chargeBonus = 28;
    meleeStats.current_chargeBonus = 28;
    AddComponent(RENDER);
}

//Stable_T2
UnitCardKnight_LightCavalryEarlyStage::UnitCardKnight_LightCavalryEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 7200;
    health.current_health = 7200;
    health.max_Armour = 35;
    health.current_Armour = 35;
    health.max_leadership = 75;
    health.current_leadership = 75;
    AddComponent(MOVEMENT);
    movement.velocity = {4.0f,4.0f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 16;
    meleeStats.current_meleeAttack = 16;
    meleeStats.max_meleeDefence = 14;
    meleeStats.current_meleeDefence = 14;
    meleeStats.max_weaponStrengh = 22;
    meleeStats.current_weaponStrengh = 22;
    meleeStats.max_chargeBonus = 40;
    meleeStats.current_chargeBonus = 40;
    AddComponent(RENDER);
}
UnitCardKnight_LightCavalryLateStage::UnitCardKnight_LightCavalryLateStage() {
    AddComponent(HEALTH);
    health.max_health = 7200;
    health.current_health = 7200;
    health.max_Armour = 35;
    health.current_Armour = 35;
    health.max_leadership = 75;
    health.current_leadership = 75;
    AddComponent(MOVEMENT);
    movement.velocity = {4.0f,4.0f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 16;
    meleeStats.current_meleeAttack = 16;
    meleeStats.max_meleeDefence = 14;
    meleeStats.current_meleeDefence = 14;
    meleeStats.max_weaponStrengh = 22;
    meleeStats.current_weaponStrengh = 22;
    meleeStats.max_chargeBonus = 40;
    meleeStats.current_chargeBonus = 40;
    AddComponent(RENDER);
}

//Stable_T3
UnitCardKnight_HeavyCavalryEarlyStage::UnitCardKnight_HeavyCavalryEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 8800;
    health.current_health = 8800;
    health.max_Armour = 65;
    health.current_Armour = 65;
    health.max_leadership = 85;
    health.current_leadership = 85;
    AddComponent(MOVEMENT);
    movement.velocity = {3.5f,3.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 22;
    meleeStats.current_meleeAttack = 22;
    meleeStats.max_meleeDefence = 20;
    meleeStats.current_meleeDefence = 20;
    meleeStats.max_weaponStrengh = 34;
    meleeStats.current_weaponStrengh = 34;
    meleeStats.max_chargeBonus = 55;
    meleeStats.current_chargeBonus = 55;
    AddComponent(RENDER);
}
UnitCardKnight_HeavyCavalryLateStage::UnitCardKnight_HeavyCavalryLateStage() {
    AddComponent(HEALTH);
    health.max_health = 8800;
    health.current_health = 8800;
    health.max_Armour = 65;
    health.current_Armour = 65;
    health.max_leadership = 85;
    health.current_leadership = 85;
    AddComponent(MOVEMENT);
    movement.velocity = {3.5f,3.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 22;
    meleeStats.current_meleeAttack = 22;
    meleeStats.max_meleeDefence = 20;
    meleeStats.current_meleeDefence = 20;
    meleeStats.max_weaponStrengh = 34;
    meleeStats.current_weaponStrengh = 34;
    meleeStats.max_chargeBonus = 55;
    meleeStats.current_chargeBonus = 55;
    AddComponent(RENDER);
}

//BUILDING ADV. MILITARY
//Artillery_T4
UnitCardKnight_CatapultEarlyStage::UnitCardKnight_CatapultEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 3000;
    health.current_health = 3000;
    health.max_Armour = 5;
    health.current_Armour = 5;
    health.max_leadership = 50;
    health.current_leadership = 50;
    AddComponent(MOVEMENT);
    movement.velocity = {0.8f,0.8f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 2;
    meleeStats.current_meleeAttack = 2;
    meleeStats.max_meleeDefence = 2;
    meleeStats.current_meleeDefence = 2;
    meleeStats.max_weaponStrengh = 5;
    meleeStats.current_weaponStrengh = 5;
    meleeStats.max_chargeBonus = 0;
    meleeStats.current_chargeBonus = 0;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 10;
    rangedStats.current_ammunition = 10;
    rangedStats.max_range = 300;
    rangedStats.current_range = 300;
    rangedStats.max_missileDamage = 120;
    rangedStats.current_missileDamage = 120;
    AddComponent(RENDER);
}
UnitCardKnight_CatapultLateStage::UnitCardKnight_CatapultLateStage() {
    AddComponent(HEALTH);
    health.max_health = 3000;
    health.current_health = 3000;
    health.max_Armour = 5;
    health.current_Armour = 5;
    health.max_leadership = 50;
    health.current_leadership = 50;
    AddComponent(MOVEMENT);
    movement.velocity = {0.8f,0.8f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 2;
    meleeStats.current_meleeAttack = 2;
    meleeStats.max_meleeDefence = 2;
    meleeStats.current_meleeDefence = 2;
    meleeStats.max_weaponStrengh = 5;
    meleeStats.current_weaponStrengh = 5;
    meleeStats.max_chargeBonus = 0;
    meleeStats.current_chargeBonus = 0;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 10;
    rangedStats.current_ammunition = 10;
    rangedStats.max_range = 300;
    rangedStats.current_range = 300;
    rangedStats.max_missileDamage = 120;
    rangedStats.current_missileDamage = 120;
    AddComponent(RENDER);
}

//Artillery_T5
UnitCardKnight_TrebuchetEarlyStage::UnitCardKnight_TrebuchetEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 3400;
    health.current_health = 3400;
    health.max_Armour = 8;
    health.current_Armour = 8;
    health.max_leadership = 55;
    health.current_leadership = 55;
    AddComponent(MOVEMENT);
    movement.velocity = {0.6f,0.6f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 2;
    meleeStats.current_meleeAttack = 2;
    meleeStats.max_meleeDefence = 2;
    meleeStats.current_meleeDefence = 2;
    meleeStats.max_weaponStrengh = 5;
    meleeStats.current_weaponStrengh = 5;
    meleeStats.max_chargeBonus = 0;
    meleeStats.current_chargeBonus = 0;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 8;
    rangedStats.current_ammunition = 8;
    rangedStats.max_range = 380;
    rangedStats.current_range = 380;
    rangedStats.max_missileDamage = 180;
    rangedStats.current_missileDamage = 180;
    AddComponent(RENDER);
}
UnitCardKnight_TrebuchetLateStage::UnitCardKnight_TrebuchetLateStage() {
    AddComponent(HEALTH);
    health.max_health = 3400;
    health.current_health = 3400;
    health.max_Armour = 8;
    health.current_Armour = 8;
    health.max_leadership = 55;
    health.current_leadership = 55;
    AddComponent(MOVEMENT);
    movement.velocity = {0.6f,0.6f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 2;
    meleeStats.current_meleeAttack = 2;
    meleeStats.max_meleeDefence = 2;
    meleeStats.current_meleeDefence = 2;
    meleeStats.max_weaponStrengh = 5;
    meleeStats.current_weaponStrengh = 5;
    meleeStats.max_chargeBonus = 0;
    meleeStats.current_chargeBonus = 0;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 8;
    rangedStats.current_ammunition = 8;
    rangedStats.max_range = 380;
    rangedStats.current_range = 380;
    rangedStats.max_missileDamage = 180;
    rangedStats.current_missileDamage = 180;
    AddComponent(RENDER);
}


// VIKING UNIT CARDS STATS
//(TIER 0)
UnitCardViking_PeasantEarlyStage::UnitCardViking_PeasantEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 9400;
    health.current_health = 9400;
    health.max_Armour = 5;
    health.current_Armour = 5;
    health.max_leadership = 60;
    health.current_leadership = 60;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 14;
    meleeStats.current_meleeAttack = 14;
    meleeStats.max_meleeDefence = 3;
    meleeStats.current_meleeDefence = 3;
    meleeStats.max_weaponStrengh = 16;
    meleeStats.current_weaponStrengh = 16;
    meleeStats.max_chargeBonus = 12;
    meleeStats.current_chargeBonus = 12;
    AddComponent(RENDER);
}
UnitCardViking_PeasantLateStage::UnitCardViking_PeasantLateStage() {
    AddComponent(HEALTH);
    health.max_health = 9400;
    health.current_health = 9400;
    health.max_Armour = 5;
    health.current_Armour = 5;
    health.max_leadership = 60;
    health.current_leadership = 60;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 14;
    meleeStats.current_meleeAttack = 14;
    meleeStats.max_meleeDefence = 3;
    meleeStats.current_meleeDefence = 3;
    meleeStats.max_weaponStrengh = 16;
    meleeStats.current_weaponStrengh = 16;
    meleeStats.max_chargeBonus = 12;
    meleeStats.current_chargeBonus = 12;
    AddComponent(RENDER);
}
UnitCardViking_PeasantArchersEarlyStage::UnitCardViking_PeasantArchersEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 4500;
    health.current_health = 4500;
    health.max_Armour = 4;
    health.current_Armour = 4;
    health.max_leadership = 62;
    health.current_leadership = 62;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 6;
    meleeStats.current_meleeAttack = 6;
    meleeStats.max_meleeDefence = 5;
    meleeStats.current_meleeDefence = 5;
    meleeStats.max_weaponStrengh = 9;
    meleeStats.current_weaponStrengh = 9;
    meleeStats.max_chargeBonus = 3;
    meleeStats.current_chargeBonus = 3;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 16;
    rangedStats.current_ammunition = 16;
    rangedStats.max_range = 110;
    rangedStats.current_range = 110;
    rangedStats.max_missileDamage = 14;
    rangedStats.current_missileDamage = 14;
    AddComponent(RENDER);
}
UnitCardViking_PeasantArchersLateStage::UnitCardViking_PeasantArchersLateStage() {
    AddComponent(HEALTH);
    health.max_health = 4500;
    health.current_health = 4500;
    health.max_Armour = 4;
    health.current_Armour = 4;
    health.max_leadership = 62;
    health.current_leadership = 62;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 6;
    meleeStats.current_meleeAttack = 6;
    meleeStats.max_meleeDefence = 5;
    meleeStats.current_meleeDefence = 5;
    meleeStats.max_weaponStrengh = 9;
    meleeStats.current_weaponStrengh = 9;
    meleeStats.max_chargeBonus = 3;
    meleeStats.current_chargeBonus = 3;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 16;
    rangedStats.current_ammunition = 16;
    rangedStats.max_range = 110;
    rangedStats.current_range = 110;
    rangedStats.max_missileDamage = 14;
    rangedStats.current_missileDamage = 14;
    AddComponent(RENDER);
}

//Military
//WarLodge_T1
UnitCardViking_AxemenEarlyStage::UnitCardViking_AxemenEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 6500;
    health.current_health = 6500;
    health.max_Armour = 25;
    health.current_Armour = 25;
    health.max_leadership = 68;
    health.current_leadership = 68;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 30;
    meleeStats.current_meleeAttack = 30;
    meleeStats.max_meleeDefence = 8;
    meleeStats.current_meleeDefence = 8;
    meleeStats.max_weaponStrengh = 28;
    meleeStats.current_weaponStrengh = 28;
    meleeStats.max_chargeBonus = 22;
    meleeStats.current_chargeBonus = 22;
    AddComponent(RENDER);
}
UnitCardViking_AxemenLateStage::UnitCardViking_AxemenLateStage() {
    AddComponent(HEALTH);
    health.max_health = 6500;
    health.current_health = 6500;
    health.max_Armour = 25;
    health.current_Armour = 25;
    health.max_leadership = 68;
    health.current_leadership = 68;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 30;
    meleeStats.current_meleeAttack = 30;
    meleeStats.max_meleeDefence = 8;
    meleeStats.current_meleeDefence = 8;
    meleeStats.max_weaponStrengh = 28;
    meleeStats.current_weaponStrengh = 28;
    meleeStats.max_chargeBonus = 22;
    meleeStats.current_chargeBonus = 22;
    AddComponent(RENDER);
}

//Warlodge_T2
UnitCardViking_SwordAndShieldEarlyStage::UnitCardViking_SwordAndShieldEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 7200;
    health.current_health = 7200;
    health.max_Armour = 40;
    health.current_Armour = 40;
    health.max_leadership = 78;
    health.current_leadership = 78;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 18;
    meleeStats.current_meleeAttack = 18;
    meleeStats.max_meleeDefence = 20;
    meleeStats.current_meleeDefence = 20;
    meleeStats.max_weaponStrengh = 30;
    meleeStats.current_weaponStrengh = 30;
    meleeStats.max_chargeBonus = 22;
    meleeStats.current_chargeBonus = 22;
    AddComponent(RENDER);
}
UnitCardViking_SwordAndShieldLateStage::UnitCardViking_SwordAndShieldLateStage() {
    AddComponent(HEALTH);
    health.max_health = 7200;
    health.current_health = 7200;
    health.max_Armour = 40;
    health.current_Armour = 40;
    health.max_leadership = 78;
    health.current_leadership = 78;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 18;
    meleeStats.current_meleeAttack = 18;
    meleeStats.max_meleeDefence = 20;
    meleeStats.current_meleeDefence = 20;
    meleeStats.max_weaponStrengh = 30;
    meleeStats.current_weaponStrengh = 30;
    meleeStats.max_chargeBonus = 22;
    meleeStats.current_chargeBonus = 22;
    AddComponent(RENDER);
}

//Warlodge_T3
UnitCardViking_LongAxeEarlyStage::UnitCardViking_LongAxeEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 7800;
    health.current_health = 7800;
    health.max_Armour = 50;
    health.current_Armour = 50;
    health.max_leadership = 58;
    health.current_leadership = 58;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 30;
    meleeStats.current_meleeAttack = 30;
    meleeStats.max_meleeDefence = 20;
    meleeStats.current_meleeDefence = 20;
    meleeStats.max_weaponStrengh = 44;
    meleeStats.current_weaponStrengh = 44;
    meleeStats.max_chargeBonus = 30;
    meleeStats.current_chargeBonus = 30;
    AddComponent(RENDER);
}
UnitCardViking_LongAxeLateStage::UnitCardViking_LongAxeLateStage() {
    AddComponent(HEALTH);
    health.max_health = 7800;
    health.current_health = 7800;
    health.max_Armour = 50;
    health.current_Armour = 50;
    health.max_leadership = 58;
    health.current_leadership = 58;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 30;
    meleeStats.current_meleeAttack = 30;
    meleeStats.max_meleeDefence = 20;
    meleeStats.current_meleeDefence = 20;
    meleeStats.max_weaponStrengh = 44;
    meleeStats.current_weaponStrengh = 44;
    meleeStats.max_chargeBonus = 30;
    meleeStats.current_chargeBonus = 30;
    AddComponent(RENDER);
}

//ShootingGround_T1
UnitCardViking_ArchersEarlyStage::UnitCardViking_ArchersEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 5000;
    health.current_health = 5000;
    health.max_Armour = 14;
    health.current_Armour = 14;
    health.max_leadership = 68;
    health.current_leadership = 68;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 10;
    meleeStats.current_meleeAttack = 10;
    meleeStats.max_meleeDefence = 8;
    meleeStats.current_meleeDefence = 8;
    meleeStats.max_weaponStrengh = 16;
    meleeStats.current_weaponStrengh = 16;
    meleeStats.max_chargeBonus = 8;
    meleeStats.current_chargeBonus = 8;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 18;
    rangedStats.current_ammunition = 18;
    rangedStats.max_range = 130;
    rangedStats.current_range = 130;
    rangedStats.max_missileDamage = 20;
    rangedStats.current_missileDamage = 20;
    AddComponent(RENDER);
}
UnitCardViking_ArchersLateStage::UnitCardViking_ArchersLateStage() {
    AddComponent(HEALTH);
    health.max_health = 5000;
    health.current_health = 5000;
    health.max_Armour = 14;
    health.current_Armour = 14;
    health.max_leadership = 68;
    health.current_leadership = 68;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 10;
    meleeStats.current_meleeAttack = 10;
    meleeStats.max_meleeDefence = 8;
    meleeStats.current_meleeDefence = 8;
    meleeStats.max_weaponStrengh = 16;
    meleeStats.current_weaponStrengh = 16;
    meleeStats.max_chargeBonus = 8;
    meleeStats.current_chargeBonus = 8;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 18;
    rangedStats.current_ammunition = 18;
    rangedStats.max_range = 130;
    rangedStats.current_range = 130;
    rangedStats.max_missileDamage = 20;
    rangedStats.current_missileDamage = 20;
    AddComponent(RENDER);
}

//ShootingGround_T2
UnitCardViking_LongbowArchersEarlyStage::UnitCardViking_LongbowArchersEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 5400;
    health.current_health = 5400;
    health.max_Armour = 35;
    health.current_Armour = 35;
    health.max_leadership = 73;
    health.current_leadership = 73;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 10;
    meleeStats.current_meleeAttack = 10;
    meleeStats.max_meleeDefence = 8;
    meleeStats.current_meleeDefence = 8;
    meleeStats.max_weaponStrengh = 16;
    meleeStats.current_weaponStrengh = 16;
    meleeStats.max_chargeBonus = 8;
    meleeStats.current_chargeBonus = 8;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 18;
    rangedStats.current_ammunition = 18;
    rangedStats.max_range = 130;
    rangedStats.current_range = 130;
    rangedStats.max_missileDamage = 23;
    rangedStats.current_missileDamage = 23;
    AddComponent(RENDER);
}
UnitCardViking_LongbowArchersLateStage::UnitCardViking_LongbowArchersLateStage() {
    AddComponent(HEALTH);
    health.max_health = 5400;
    health.current_health = 5400;
    health.max_Armour = 35;
    health.current_Armour = 35;
    health.max_leadership = 73;
    health.current_leadership = 73;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 10;
    meleeStats.current_meleeAttack = 10;
    meleeStats.max_meleeDefence = 8;
    meleeStats.current_meleeDefence = 8;
    meleeStats.max_weaponStrengh = 16;
    meleeStats.current_weaponStrengh = 16;
    meleeStats.max_chargeBonus = 8;
    meleeStats.current_chargeBonus = 8;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 18;
    rangedStats.current_ammunition = 18;
    rangedStats.max_range = 130;
    rangedStats.current_range = 130;
    rangedStats.max_missileDamage = 23;
    rangedStats.current_missileDamage = 23;
    AddComponent(RENDER);
}

//ShootingGround_T3
UnitCardViking_EliteLongbowArchersEarlyStage::UnitCardViking_EliteLongbowArchersEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 5200;
    health.current_health = 5200;
    health.max_Armour = 22;
    health.current_Armour = 22;
    health.max_leadership = 83;
    health.current_leadership = 83;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 8;
    meleeStats.current_meleeAttack = 8;
    meleeStats.max_meleeDefence = 10;
    meleeStats.current_meleeDefence = 10;
    meleeStats.max_weaponStrengh = 16;
    meleeStats.current_weaponStrengh = 16;
    meleeStats.max_chargeBonus = 7;
    meleeStats.current_chargeBonus = 7;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 16;
    rangedStats.current_ammunition = 16;
    rangedStats.max_range = 170;
    rangedStats.current_range = 170;
    rangedStats.max_missileDamage = 36;
    rangedStats.current_missileDamage = 36;
    AddComponent(RENDER);
}
UnitCardViking_EliteLongbowArchersLateStage::UnitCardViking_EliteLongbowArchersLateStage() {
    AddComponent(HEALTH);
    health.max_health = 5200;
    health.current_health = 5200;
    health.max_Armour = 22;
    health.current_Armour = 22;
    health.max_leadership = 83;
    health.current_leadership = 83;
    AddComponent(MOVEMENT);
    movement.velocity = {1.5f,1.5f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 8;
    meleeStats.current_meleeAttack = 8;
    meleeStats.max_meleeDefence = 10;
    meleeStats.current_meleeDefence = 10;
    meleeStats.max_weaponStrengh = 16;
    meleeStats.current_weaponStrengh = 16;
    meleeStats.max_chargeBonus = 7;
    meleeStats.current_chargeBonus = 7;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 16;
    rangedStats.current_ammunition = 16;
    rangedStats.max_range = 170;
    rangedStats.current_range = 170;
    rangedStats.max_missileDamage = 36;
    rangedStats.current_missileDamage = 36;
    AddComponent(RENDER);
}

//HorseTraining_T1
UnitCardViking_PeasantHorsemenEarlyStage::UnitCardViking_PeasantHorsemenEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 5800;
    health.current_health = 5800;
    health.max_Armour = 10;
    health.current_Armour = 10;
    health.max_leadership = 63;
    health.current_leadership = 63;
    AddComponent(MOVEMENT);
    movement.velocity = {3.2f,3.2f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 12;
    meleeStats.current_meleeAttack = 12;
    meleeStats.max_meleeDefence = 6;
    meleeStats.current_meleeDefence = 6;
    meleeStats.max_weaponStrengh = 18;
    meleeStats.current_weaponStrengh = 18;
    meleeStats.max_chargeBonus = 30;
    meleeStats.current_chargeBonus = 30;
    AddComponent(RENDER);
}
UnitCardViking_PeasantHorsemenLateStage::UnitCardViking_PeasantHorsemenLateStage() {
    AddComponent(HEALTH);
    health.max_health = 5800;
    health.current_health = 5800;
    health.max_Armour = 10;
    health.current_Armour = 10;
    health.max_leadership = 63;
    health.current_leadership = 63;
    AddComponent(MOVEMENT);
    movement.velocity = {3.2f,3.2f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 12;
    meleeStats.current_meleeAttack = 12;
    meleeStats.max_meleeDefence = 6;
    meleeStats.current_meleeDefence = 6;
    meleeStats.max_weaponStrengh = 18;
    meleeStats.current_weaponStrengh = 18;
    meleeStats.max_chargeBonus = 30;
    meleeStats.current_chargeBonus = 30;
    AddComponent(RENDER);
}

//HorseTraining_T2
UnitCardViking_LightCavalryEarlyStage::UnitCardViking_LightCavalryEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 7000;
    health.current_health = 7000;
    health.max_Armour = 28;
    health.current_Armour = 28;
    health.max_leadership = 73;
    health.current_leadership = 73;
    AddComponent(MOVEMENT);
    movement.velocity = {4.3f,4.3f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 20;
    meleeStats.current_meleeAttack = 20;
    meleeStats.max_meleeDefence = 10;
    meleeStats.current_meleeDefence = 10;
    meleeStats.max_weaponStrengh = 26;
    meleeStats.current_weaponStrengh = 26;
    meleeStats.max_chargeBonus = 42;
    meleeStats.current_chargeBonus = 42;
    AddComponent(RENDER);
}
UnitCardViking_LightCavalryLateStage::UnitCardViking_LightCavalryLateStage() {
    AddComponent(HEALTH);
    health.max_health = 7000;
    health.current_health = 7000;
    health.max_Armour = 28;
    health.current_Armour = 28;
    health.max_leadership = 73;
    health.current_leadership = 73;
    AddComponent(MOVEMENT);
    movement.velocity = {4.3f,4.3f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 20;
    meleeStats.current_meleeAttack = 20;
    meleeStats.max_meleeDefence = 10;
    meleeStats.current_meleeDefence = 10;
    meleeStats.max_weaponStrengh = 26;
    meleeStats.current_weaponStrengh = 26;
    meleeStats.max_chargeBonus = 42;
    meleeStats.current_chargeBonus = 42;
    AddComponent(RENDER);
}

//HorseTraining_T3
UnitCardViking_HeavyCavalryEarlyStage::UnitCardViking_HeavyCavalryEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 8500;
    health.current_health = 8500;
    health.max_Armour = 55;
    health.current_Armour = 55;
    health.max_leadership = 83;
    health.current_leadership = 83;
    AddComponent(MOVEMENT);
    movement.velocity = {3.7f,3.7f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 26;
    meleeStats.current_meleeAttack = 26;
    meleeStats.max_meleeDefence = 16;
    meleeStats.current_meleeDefence = 16;
    meleeStats.max_weaponStrengh = 38;
    meleeStats.current_weaponStrengh = 38;
    meleeStats.max_chargeBonus = 58;
    meleeStats.current_chargeBonus = 58;
    AddComponent(RENDER);
}
UnitCardViking_HeavyCavalryLateStage::UnitCardViking_HeavyCavalryLateStage() {
    AddComponent(HEALTH);
    health.max_health = 8500;
    health.current_health = 8500;
    health.max_Armour = 55;
    health.current_Armour = 55;
    health.max_leadership = 83;
    health.current_leadership = 83;
    AddComponent(MOVEMENT);
    movement.velocity = {3.7f,3.7f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 26;
    meleeStats.current_meleeAttack = 26;
    meleeStats.max_meleeDefence = 16;
    meleeStats.current_meleeDefence = 16;
    meleeStats.max_weaponStrengh = 38;
    meleeStats.current_weaponStrengh = 38;
    meleeStats.max_chargeBonus = 58;
    meleeStats.current_chargeBonus = 58;
    AddComponent(RENDER);
}

//ADV.VMILITARY
//ChosensOfOdin_T3
UnitCardViking_BerserkersEarlyStage::UnitCardViking_BerserkersEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 7000;
    health.current_health = 7000;
    health.max_Armour = 15;
    health.current_Armour = 15;
    health.max_leadership = 75;
    health.current_leadership = 75;
    AddComponent(MOVEMENT);
    movement.velocity = {2.0f,2.0f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 40;
    meleeStats.current_meleeAttack = 40;
    meleeStats.max_meleeDefence = 12;
    meleeStats.current_meleeDefence = 12;
    meleeStats.max_weaponStrengh = 36;
    meleeStats.current_weaponStrengh = 36;
    meleeStats.max_chargeBonus = 25;
    meleeStats.current_chargeBonus = 25;
    AddComponent(RENDER);
}
UnitCardViking_BerserkersLateStage::UnitCardViking_BerserkersLateStage() {
    AddComponent(HEALTH);
    health.max_health = 7000;
    health.current_health = 7000;
    health.max_Armour = 15;
    health.current_Armour = 15;
    health.max_leadership = 75;
    health.current_leadership = 75;
    AddComponent(MOVEMENT);
    movement.velocity = {2.0f,2.0f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 40;
    meleeStats.current_meleeAttack = 40;
    meleeStats.max_meleeDefence = 12;
    meleeStats.current_meleeDefence = 12;
    meleeStats.max_weaponStrengh = 36;
    meleeStats.current_weaponStrengh = 36;
    meleeStats.max_chargeBonus = 25;
    meleeStats.current_chargeBonus = 25;
    AddComponent(RENDER);
}

//ChosensOfOdin_T4
UnitCardViking_ArmouredBerserkersEarlyStage::UnitCardViking_ArmouredBerserkersEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 8500;
    health.current_health = 8500;
    health.max_Armour = 45;
    health.current_Armour = 45;
    health.max_leadership = 85;
    health.current_leadership = 85;
    AddComponent(MOVEMENT);
    movement.velocity = {1.8f,1.8f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 48;
    meleeStats.current_meleeAttack = 48;
    meleeStats.max_meleeDefence = 18;
    meleeStats.current_meleeDefence = 18;
    meleeStats.max_weaponStrengh = 42;
    meleeStats.current_weaponStrengh = 42;
    meleeStats.max_chargeBonus = 28;
    meleeStats.current_chargeBonus = 28;
    AddComponent(RENDER);
}
UnitCardViking_ArmouredBerserkersLateStage::UnitCardViking_ArmouredBerserkersLateStage() {
    AddComponent(HEALTH);
    health.max_health = 8500;
    health.current_health = 8500;
    health.max_Armour = 45;
    health.current_Armour = 45;
    health.max_leadership = 85;
    health.current_leadership = 85;
    AddComponent(MOVEMENT);
    movement.velocity = {1.8f,1.8f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 48;
    meleeStats.current_meleeAttack = 48;
    meleeStats.max_meleeDefence = 18;
    meleeStats.current_meleeDefence = 18;
    meleeStats.max_weaponStrengh = 42;
    meleeStats.current_weaponStrengh = 42;
    meleeStats.max_chargeBonus = 28;
    meleeStats.current_chargeBonus = 28;
    AddComponent(RENDER);
}

//ChosensOfOdin_T5 (peaux de loup) elite warriors
UnitCardViking_UlfhednarEarlyStage::UnitCardViking_UlfhednarEarlyStage() {
    AddComponent(HEALTH);
    health.max_health = 9000;
    health.current_health = 9000;
    health.max_Armour = 30;
    health.current_Armour = 30;
    health.max_leadership = 95;
    health.current_leadership = 95;
    AddComponent(MOVEMENT);
    movement.velocity = {2.2f,2.2f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 58;
    meleeStats.current_meleeAttack = 58;
    meleeStats.max_meleeDefence = 22;
    meleeStats.current_meleeDefence = 22;
    meleeStats.max_weaponStrengh = 50;
    meleeStats.current_weaponStrengh = 50;
    meleeStats.max_chargeBonus = 32;
    meleeStats.current_chargeBonus = 32;
    AddComponent(RENDER);
}
UnitCardViking_UlfhednarLateStage::UnitCardViking_UlfhednarLateStage() {
    AddComponent(HEALTH);
    health.max_health = 9000;
    health.current_health = 9000;
    health.max_Armour = 30;
    health.current_Armour = 30;
    health.max_leadership = 95;
    health.current_leadership = 95;
    AddComponent(MOVEMENT);
    movement.velocity = {2.2f,2.2f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 58;
    meleeStats.current_meleeAttack = 58;
    meleeStats.max_meleeDefence = 22;
    meleeStats.current_meleeDefence = 22;
    meleeStats.max_weaponStrengh = 50;
    meleeStats.current_weaponStrengh = 50;
    meleeStats.max_chargeBonus = 32;
    meleeStats.current_chargeBonus = 32;
    AddComponent(RENDER);
}


//SAMURAI UNIT CARDS STATS
//(TIER 0)
UnitCardSamurai_Peasants::UnitCardSamurai_Peasants() {
    AddComponent(HEALTH);
    health.max_health = 7000;
    health.current_health = 7000;
    health.max_Armour = 5;
    health.current_Armour = 5;
    health.max_leadership = 58;
    health.current_leadership = 58;
    AddComponent(MOVEMENT);
    movement.velocity = {2.0f,2.0f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 10;
    meleeStats.current_meleeAttack = 10;
    meleeStats.max_meleeDefence = 5;
    meleeStats.current_meleeDefence = 5;
    meleeStats.max_weaponStrengh = 12;
    meleeStats.current_weaponStrengh = 12;
    meleeStats.max_chargeBonus = 10;
    meleeStats.current_chargeBonus = 10;
    AddComponent(RENDER);
}
UnitCardSamurai_PeasantArchers::UnitCardSamurai_PeasantArchers() {
    AddComponent(HEALTH);
    health.max_health = 3800;
    health.current_health = 3800;
    health.max_Armour = 4;
    health.current_Armour = 4;
    health.max_leadership = 60;
    health.current_leadership = 60;
    AddComponent(MOVEMENT);
    movement.velocity = {2.0f,2.0f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 4;
    meleeStats.current_meleeAttack = 4;
    meleeStats.max_meleeDefence = 6;
    meleeStats.current_meleeDefence = 6;
    meleeStats.max_weaponStrengh = 7;
    meleeStats.current_weaponStrengh = 7;
    meleeStats.max_chargeBonus = 2;
    meleeStats.current_chargeBonus = 2;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 20;
    rangedStats.current_ammunition = 20;
    rangedStats.max_range = 130;
    rangedStats.current_range = 130;
    rangedStats.max_missileDamage = 16;
    rangedStats.current_missileDamage = 16;
    AddComponent(RENDER);
}

//MILITARY
//SwordSchool_T1
UnitCardSamurai_YariAshigaru::UnitCardSamurai_YariAshigaru() {
    AddComponent(HEALTH);
    health.max_health = 5200;
    health.current_health = 5200;
    health.max_Armour = 18;
    health.current_Armour = 18;
    health.max_leadership = 65;
    health.current_leadership = 65;
    AddComponent(MOVEMENT);
    movement.velocity = {2.2f,2.2f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 20;
    meleeStats.current_meleeAttack = 20;
    meleeStats.max_meleeDefence = 8;
    meleeStats.current_meleeDefence = 8;
    meleeStats.max_weaponStrengh = 20;
    meleeStats.current_weaponStrengh = 20;
    meleeStats.max_chargeBonus = 18;
    meleeStats.current_chargeBonus = 18;
    AddComponent(RENDER);
}

//SwordSchool_T2 Samurai
UnitCardSamurai_KatanaSamurai::UnitCardSamurai_KatanaSamurai() {
    AddComponent(HEALTH);
    health.max_health = 5800;
    health.current_health = 5800;
    health.max_Armour = 30;
    health.current_Armour = 30;
    health.max_leadership = 75;
    health.current_leadership = 75;
    AddComponent(MOVEMENT);
    movement.velocity = {2.3f,2.3f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 28;
    meleeStats.current_meleeAttack = 28;
    meleeStats.max_meleeDefence = 16;
    meleeStats.current_meleeDefence = 16;
    meleeStats.max_weaponStrengh = 30;
    meleeStats.current_weaponStrengh = 30;
    meleeStats.max_chargeBonus = 20;
    meleeStats.current_chargeBonus = 20;
    AddComponent(RENDER);
}

//SwordSchool_T3
UnitCardSamurai_NoDachiSamurai::UnitCardSamurai_NoDachiSamurai() {
    AddComponent(HEALTH);
    health.max_health = 6200;
    health.current_health = 6200;
    health.max_Armour = 35;
    health.current_Armour = 35;
    health.max_leadership = 65;
    health.current_leadership = 65;
    AddComponent(MOVEMENT);
    movement.velocity = {2.4f,2.4f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 36;
    meleeStats.current_meleeAttack = 36;
    meleeStats.max_meleeDefence = 14;
    meleeStats.current_meleeDefence = 14;
    meleeStats.max_weaponStrengh = 40;
    meleeStats.current_weaponStrengh = 40;
    meleeStats.max_chargeBonus = 22;
    meleeStats.current_chargeBonus = 22;
    AddComponent(RENDER);
}

//ArcheryDojo_T1
UnitCardSamurai_BowAshigaru::UnitCardSamurai_BowAshigaru() {
    AddComponent(HEALTH);
    health.max_health = 4200;
    health.current_health = 4200;
    health.max_Armour = 12;
    health.current_Armour = 12;
    health.max_leadership = 65;
    health.current_leadership = 65;
    AddComponent(MOVEMENT);
    movement.velocity = {2.2f,2.2f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 8;
    meleeStats.current_meleeAttack = 8;
    meleeStats.max_meleeDefence = 8;
    meleeStats.current_meleeDefence = 8;
    meleeStats.max_weaponStrengh = 14;
    meleeStats.current_weaponStrengh = 14;
    meleeStats.max_chargeBonus = 7;
    meleeStats.current_chargeBonus = 7;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 24;
    rangedStats.current_ammunition = 24;
    rangedStats.max_range = 150;
    rangedStats.current_range = 150;
    rangedStats.max_missileDamage = 22;
    rangedStats.current_missileDamage = 22;
    AddComponent(RENDER);
}

//ArcheryDojo_T2
UnitCardSamurai_BowSamurai::UnitCardSamurai_BowSamurai() {
    AddComponent(HEALTH);
    health.max_health = 4600;
    health.current_health = 4600;
    health.max_Armour = 25;
    health.current_Armour = 25;
    health.max_leadership = 78;
    health.current_leadership = 78;
    AddComponent(MOVEMENT);
    movement.velocity = {2.3f,2.3f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 8;
    meleeStats.current_meleeAttack = 8;
    meleeStats.max_meleeDefence = 8;
    meleeStats.current_meleeDefence = 8;
    meleeStats.max_weaponStrengh = 14;
    meleeStats.current_weaponStrengh = 14;
    meleeStats.max_chargeBonus = 8;
    meleeStats.current_chargeBonus = 8;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 24;
    rangedStats.current_ammunition = 24;
    rangedStats.max_range = 155;
    rangedStats.current_range = 155;
    rangedStats.max_missileDamage = 26;
    rangedStats.current_missileDamage = 26;
    AddComponent(RENDER);
}

//ArcheryDojo_T3
UnitCardSamurai_EliteBowSamurai::UnitCardSamurai_EliteBowSamurai() {
    AddComponent(HEALTH);
    health.max_health = 4400;
    health.current_health = 4400;
    health.max_Armour = 18;
    health.current_Armour = 18;
    health.max_leadership = 88;
    health.current_leadership = 88;
    AddComponent(MOVEMENT);
    movement.velocity = {2.4f,2.4f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 7;
    meleeStats.current_meleeAttack = 7;
    meleeStats.max_meleeDefence = 10;
    meleeStats.current_meleeDefence = 10;
    meleeStats.max_weaponStrengh = 14;
    meleeStats.current_weaponStrengh = 14;
    meleeStats.max_chargeBonus = 7;
    meleeStats.current_chargeBonus = 7;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 22;
    rangedStats.current_ammunition = 22;
    rangedStats.max_range = 195;
    rangedStats.current_range = 195;
    rangedStats.max_missileDamage = 40;
    rangedStats.current_missileDamage = 40;
    AddComponent(RENDER);
}

//WarhorseStable_T1
UnitCardSamurai_PeasantHorsemen::UnitCardSamurai_PeasantHorsemen() {
    AddComponent(HEALTH);
    health.max_health = 4600;
    health.current_health = 4600;
    health.max_Armour = 8;
    health.current_Armour = 8;
    health.max_leadership = 60;
    health.current_leadership = 60;
    AddComponent(MOVEMENT);
    movement.velocity = {3.6f,3.6f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 10;
    meleeStats.current_meleeAttack = 10;
    meleeStats.max_meleeDefence = 5;
    meleeStats.current_meleeDefence = 5;
    meleeStats.max_weaponStrengh = 16;
    meleeStats.current_weaponStrengh = 16;
    meleeStats.max_chargeBonus = 26;
    meleeStats.current_chargeBonus = 26;
    AddComponent(RENDER);
}

//WarhorseStable_T2
UnitCardSamurai_KatanaCavalry::UnitCardSamurai_KatanaCavalry() {
    AddComponent(HEALTH);
    health.max_health = 5800;
    health.current_health = 5800;
    health.max_Armour = 20;
    health.current_Armour = 20;
    health.max_leadership = 75;
    health.current_leadership = 75;
    AddComponent(MOVEMENT);
    movement.velocity = {4.8f,4.8f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 22;
    meleeStats.current_meleeAttack = 22;
    meleeStats.max_meleeDefence = 8;
    meleeStats.current_meleeDefence = 8;
    meleeStats.max_weaponStrengh = 26;
    meleeStats.current_weaponStrengh = 26;
    meleeStats.max_chargeBonus = 44;
    meleeStats.current_chargeBonus = 44;
    AddComponent(RENDER);
}

//WarhorseStable_T3
UnitCardSamurai_EliteYariCavalry::UnitCardSamurai_EliteYariCavalry() {
    AddComponent(HEALTH);
    health.max_health = 6800;
    health.current_health = 6800;
    health.max_Armour = 40;
    health.current_Armour = 40;
    health.max_leadership = 85;
    health.current_leadership = 85;
    AddComponent(MOVEMENT);
    movement.velocity = {4.2f,4.2f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 28;
    meleeStats.current_meleeAttack = 28;
    meleeStats.max_meleeDefence = 12;
    meleeStats.current_meleeDefence = 12;
    meleeStats.max_weaponStrengh = 34;
    meleeStats.current_weaponStrengh = 34;
    meleeStats.max_chargeBonus = 60;
    meleeStats.current_chargeBonus = 60;
    AddComponent(RENDER);
}

//ADV. MILITARY
//SiegeEngineerWorkshop_T4
UnitCardSamurai_FireProjectingMangonels::UnitCardSamurai_FireProjectingMangonels() {
    AddComponent(HEALTH);
    health.max_health = 2600;
    health.current_health = 2600;
    health.max_Armour = 5;
    health.current_Armour = 5;
    health.max_leadership = 48;
    health.current_leadership = 48;
    AddComponent(MOVEMENT);
    movement.velocity = {0.7f,0.7f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 2;
    meleeStats.current_meleeAttack = 2;
    meleeStats.max_meleeDefence = 2;
    meleeStats.current_meleeDefence = 2;
    meleeStats.max_weaponStrengh = 5;
    meleeStats.current_weaponStrengh = 5;
    meleeStats.max_chargeBonus = 0;
    meleeStats.current_chargeBonus = 0;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 8;
    rangedStats.current_ammunition = 8;
    rangedStats.max_range = 280;
    rangedStats.current_range = 280;
    rangedStats.max_missileDamage = 110;
    rangedStats.current_missileDamage = 110;
    AddComponent(RENDER);
}

//SiegeEngineerWorkshop_T5
UnitCardSamurai_EuropeanCannons::UnitCardSamurai_EuropeanCannons() {
    AddComponent(HEALTH);
    health.max_health = 3000;
    health.current_health = 3000;
    health.max_Armour = 8;
    health.current_Armour = 8;
    health.max_leadership = 53;
    health.current_leadership = 53;
    AddComponent(MOVEMENT);
    movement.velocity = {0.6f,0.6f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 2;
    meleeStats.current_meleeAttack = 2;
    meleeStats.max_meleeDefence = 2;
    meleeStats.current_meleeDefence = 2;
    meleeStats.max_weaponStrengh = 5;
    meleeStats.current_weaponStrengh = 5;
    meleeStats.max_chargeBonus = 0;
    meleeStats.current_chargeBonus = 0;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 6;
    rangedStats.current_ammunition = 6;
    rangedStats.max_range = 400;
    rangedStats.current_range = 400;
    rangedStats.max_missileDamage = 220;
    rangedStats.current_missileDamage = 220;
    AddComponent(RENDER);
}

//GunSmith_T4
UnitCardSamurai_MatchlockSamurai::UnitCardSamurai_MatchlockSamurai() {
    AddComponent(HEALTH);
    health.max_health = 4000;
    health.current_health = 4000;
    health.max_Armour = 10;
    health.current_Armour = 10;
    health.max_leadership = 70;
    health.current_leadership = 70;
    AddComponent(MOVEMENT);
    movement.velocity = {2.0f,2.0f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 6;
    meleeStats.current_meleeAttack = 6;
    meleeStats.max_meleeDefence = 6;
    meleeStats.current_meleeDefence = 6;
    meleeStats.max_weaponStrengh = 10;
    meleeStats.current_weaponStrengh = 10;
    meleeStats.max_chargeBonus = 5;
    meleeStats.current_chargeBonus = 5;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 15;
    rangedStats.current_ammunition = 15;
    rangedStats.max_range = 160;
    rangedStats.current_range = 160;
    rangedStats.max_missileDamage = 45;
    rangedStats.current_missileDamage = 45;
    AddComponent(RENDER);
}

//GunSmith_T5
UnitCardSamurai_PortugueseTercos::UnitCardSamurai_PortugueseTercos() {
    AddComponent(HEALTH);
    health.max_health = 4400;
    health.current_health = 4400;
    health.max_Armour = 20;
    health.current_Armour = 20;
    health.max_leadership = 80;
    health.current_leadership = 80;
    AddComponent(MOVEMENT);
    movement.velocity = {2.0f,2.0f};
    AddComponent(MELEE);
    meleeStats.max_meleeAttack = 10;
    meleeStats.current_meleeAttack = 10;
    meleeStats.max_meleeDefence = 10;
    meleeStats.current_meleeDefence = 10;
    meleeStats.max_weaponStrengh = 14;
    meleeStats.current_weaponStrengh = 14;
    meleeStats.max_chargeBonus = 8;
    meleeStats.current_chargeBonus = 8;
    AddComponent(RANGED);
    rangedStats.max_ammunition = 15;
    rangedStats.current_ammunition = 15;
    rangedStats.max_range = 170;
    rangedStats.current_range = 170;
    rangedStats.max_missileDamage = 52;
    rangedStats.current_missileDamage = 52;
    AddComponent(RENDER);
}