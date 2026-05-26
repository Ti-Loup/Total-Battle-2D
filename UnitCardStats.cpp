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
 */
//fix le speed
//


//KNIGHT UNIT CARDS STATS
//(TIER 0)
UnitCardKnight_Peasant::UnitCardKnight_Peasant() {
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

UnitCardKnight_PeasantArchers::UnitCardKnight_PeasantArchers() {
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
UnitCardKnight_Swordmen::UnitCardKnight_Swordmen() {
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
UnitCardKnight_SwordAndShield::UnitCardKnight_SwordAndShield() {
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
UnitCardKnight_MaceAndShield::UnitCardKnight_MaceAndShield() {
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
UnitCardKnight_Hunters::UnitCardKnight_Hunters() {
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
UnitCardKnight_Archers::UnitCardKnight_Archers() {
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
    rangedStats.max_missileDamage = 21;
    rangedStats.current_missileDamage = 21;
    AddComponent(RENDER);
}

//ArcheryRange_T3
UnitCardKnight_LongBowmen::UnitCardKnight_LongBowmen() {
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

// VIKING UNIT CARDS STATS
