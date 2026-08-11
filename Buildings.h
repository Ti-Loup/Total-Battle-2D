//
// Created by Louis-Philippe on 4/24/2026.
//

#pragma once
#ifndef TOTALWAR2D_BUILDINGS_H
#define TOTALWAR2D_BUILDINGS_H
#include <string>
#include <vector>
#include "Province.h"
#include "State.h"
#include "Resources.h"
#include <unordered_map>

enum class BuildingType{
None,
//  -> KNIGHT BUILDINGS <-
Settlement_Village_Knight_T1,
Settlement_Village_Knight_T2,
Settlement_Village_Knight_T3,
Settlement_Castle_Knight_T1,
Settlement_Castle_Knight_T2,
Settlement_Castle_Knight_T3,
Settlement_Castle_Knight_T4,
Settlement_Castle_Knight_T5,
Settlement_Capital_Knight_T1,
Settlement_Capital_Knight_T2,
Settlement_Capital_Knight_T3,
Settlement_Capital_Knight_T4,
Settlement_Capital_Knight_T5,
    //military
Barracks_T1,
Barracks_T2,
Barracks_T3,
ArcheryRange_T1,
ArcheryRange_T2,
ArcheryRange_T3,
Stable_T1,
Stable_T2,
Stable_T3,
    //adv military
Artillery_T4,
Artillery_T5,
    //Defence
ReinforceWalls_T3,
ReinforceWalls_T4,
ReinforceWalls_T5,
    //Economy
Economy_T1,
Economy_T2,
PeasantryGrowth_T1,//peasants growth
PeasantryGrowth_T2,
PeasantryGrowth_T3,
NobilityEstate_T1,//noble growth
NobilityEstate_T2,
NobilityEstate_T3,
KnightGranary_T3,
KnightGranary_T4,
KnightGranary_T5,
    //commerce
KnightWareHouse_T3,
KnightWareHouse_T4,
KnightWareHouse_T5,
KnightRoads_T1,
KnightRoads_T2,
KnightRoads_T3,
KnightTavern_T1,
    //Industry
KnightOilPress_T1,
KnightOilPress_T2,
KnightCarpentry_T1,
KnightCarpentry_T2,
KnightTextile_T1,
KnightTextile_T2,
KnightTextile_T3,
KnightArtisan_T1,
KnightArtisan_T2,
KnightArtisan_T3,
KnightTinsmith_T2,
KnightTinsmith_T3,
KnightTinsmith_T4,
KnightMint_T2,
KnightMint_T3,
KnightMint_T4,
KnightForge_T3,
KnightForge_T4,
KnightForge_T5,
KnightJeweller_T3,
KnightJeweller_T4,
KnightJeweller_T5,
    //religion
KnightAlmsHouse_T1,//reconstitution population
KnightAlmsHouse_T2,
KnightBeeKeeper_T1,//Produce candles
KnightBeeKeeper_T2,
KnightBeeKeeper_T3,
KnightChurch_T3,//public order
KnightChurch_T4,
KnightChurch_T5,

//For Main Buildings ports Knight
KnightMilitaryPort_T1,
KnightMilitaryPort_T2,
KnightMilitaryPort_T3,
KnightMilitaryPort_T4,
KnightMilitaryPort_T5,
//For Small villages ports Knight
KnightFishingPort_T1,
KnightFishingPort_T2,
KnightFishingPort_T3,

//  -> VIKINGS BUILDINGS <-
Settlement_Village_Viking_T1,
Settlement_Village_Viking_T2,
Settlement_Village_Viking_T3,
Settlement_Castle_Viking_T1,
Settlement_Castle_Viking_T2,
Settlement_Castle_Viking_T3,
Settlement_Castle_Viking_T4,
Settlement_Castle_Viking_T5,
Settlement_Capital_Viking_T1,
Settlement_Capital_Viking_T2,
Settlement_Capital_Viking_T3,
Settlement_Capital_Viking_T4,
Settlement_Capital_Viking_T5,
WarLodge_T1,
WarLodge_T2,
WarLodge_T3,
ShootingGround_T1,
ShootingGround_T2,
ShootingGround_T3,
HorseTraining_T1,
HorseTraining_T2,
HorseTraining_T3,
ChosensOfOdin_T3,
ChosensOfOdin_T4,
ChosensOfOdin_T5,
ReinforcedDrakkar_T3,
ReinforcedDrakkar_T4,
ReinforcedDrakkar_T5,
    //Economy
SlaveMarket_T1,
SlaveMarket_T2,
PeasantryVikingGrowth_T1,
PeasantryVikingGrowth_T2,
PeasantryVikingGrowth_T3,
NobilityVikingEstate_T1,
NobilityVikingEstate_T2,
NobilityVikingEstate_T3,
VikingGranary_T3,
VikingGranary_T4,
VikingGranary_T5,
    //Commerce
VikingWareHouse_T3,
VikingWareHouse_T4,
VikingWareHouse_T5,
VikingRoads_T1,
VikingRoads_T2,
VikingRoads_T3,
VikingTavern_T1,
    //Industry
VikingOilPress_T1,
VikingOilPress_T2,
VikingCarpentry_T1,
VikingCarpentry_T2,
VikingTextile_T1,
VikingTextile_T2,
VikingTextile_T3,
VikingArtisan_T1,
VikingArtisan_T2,
VikingArtisan_T3,
VikingTinsmith_T2,
VikingTinsmith_T3,
VikingTinsmith_T4,
VikingMint_T2,
VikingMint_T3,
VikingMint_T4,
VikingForge_T3,
VikingForge_T4,
VikingForge_T5,
VikingJeweller_T3,
VikingJeweller_T4,
VikingJeweller_T5,
    //Religion
VikingShrine_T1,//Reconstitution Bonus
VikingShrine_T2,
VikingBrewKeeper_T1,//Beer production
VikingBrewKeeper_T2,
VikingBrewKeeper_T3,
VikingSacrificeRitual_T3,//Public order (Shaman)
VikingSacrificeRitual_T4,
VikingSacrificeRitual_T5,

//For Main Buildings ports Viking
VikingMilitaryPort_T1,
VikingMilitaryPort_T2,
VikingMilitaryPort_T3,
VikingMilitaryPort_T4,
VikingMilitaryPort_T5,
//For Small villages ports Viking
VikingFishingPort_T1,
VikingFishingPort_T2,
VikingFishingPort_T3,
//  -> SAMURAI BUILDINGS <-
Settlement_Village_Samurai_T1,
Settlement_Village_Samurai_T2,
Settlement_Village_Samurai_T3,
Settlement_Castle_Samurai_T1,
Settlement_Castle_Samurai_T2,
Settlement_Castle_Samurai_T3,
Settlement_Castle_Samurai_T4,
Settlement_Castle_Samurai_T5,
Settlement_Capital_Samurai_T1,
Settlement_Capital_Samurai_T2,
Settlement_Capital_Samurai_T3,
Settlement_Capital_Samurai_T4,
Settlement_Capital_Samurai_T5,
    //military
SwordSchool_T1,
SwordSchool_T2,
SwordSchool_T3,
ArcheryDojo_T1,
ArcheryDojo_T2,
ArcheryDojo_T3,
WarhorseStable_T1,
WarhorseStable_T2,
WarhorseStable_T3,
    //Adv military
SiegeEngineerWorkshop_T4,
SiegeEngineerWorkshop_T5,
GunSmith_T4,
GunSmith_T5,
    //Defence
FortifiedCastle_T3,
FortifiedCastle_T4,
FortifiedCastle_T5,
    //Economy
Market_T1,
Market_T2,
PeasantrySamuraiGrowth_T1,
PeasantrySamuraiGrowth_T2,
PeasantrySamuraiGrowth_T3,
NobilitySamuraiEstate_T1,
NobilitySamuraiEstate_T2,
NobilitySamuraiEstate_T3,
SamuraiGranary_T3,
SamuraiGranary_T4,
SamuraiGranary_T5,
    //Commerce
SamuraiWareHouse_T3,
SamuraiWareHouse_T4,
SamuraiWareHouse_T5,
SamuraiRoads_T1,
SamuraiRoads_T2,
SamuraiRoads_T3,
SamuraiTavern_T1,
    //Industry
SamuraiOilPress_T1,
SamuraiOilPress_T2,
SamuraiCarpentry_T1,
SamuraiCarpentry_T2,
SamuraiTextile_T1,
SamuraiTextile_T2,
SamuraiTextile_T3,
SamuraiArtisan_T1,
SamuraiArtisan_T2,
SamuraiArtisan_T3,
SamuraiTinsmith_T2,
SamuraiTinsmith_T3,
SamuraiTinsmith_T4,
SamuraiMint_T2,
SamuraiMint_T3,
SamuraiMint_T4,
SamuraiForge_T3,
SamuraiForge_T4,
SamuraiForge_T5,
SamuraiJeweller_T3,
SamuraiJeweller_T4,
SamuraiJeweller_T5,

    //Religion
SamuraiHospital_T1,//Bonus reconstitution
SamuraiHospital_T2,
SamuraiTeaDry_T1,//Produce Tea
SamuraiTeaDry_T2,
SamuraiTeaDry_T3,
SamuraiChapel_T3,//public orders
SamuraiChapel_T4,
SamuraiChapel_T5,

//For Main Buildings ports Samurai
SamuraiMilitaryPort_T1,
SamuraiMilitaryPort_T2,
SamuraiMilitaryPort_T3,
SamuraiMilitaryPort_T4,
SamuraiMilitaryPort_T5,
//For Small villages ports Samurai
SamuraiFishingPort_T1,
SamuraiFishingPort_T2,
SamuraiFishingPort_T3,


    //GENERAL BUILDINGS (SAME FOR ALL)
    //Iron
IronMine_T1,
IronMine_T2,
IronMine_T3,
    //Gold
GoldMine_T1,
GoldMine_T2,
GoldMine_T3,
    //Copper
CopperMine_T1,
CopperMine_T2,
CopperMine_T3,
    //Silver
SilverMine_T1,
SilverMine_T2,
SilverMine_T3,
    //Tin
TinMine_T1,
TinMine_T2,
TinMine_T3,
    //Wood
LumberCamp_T1,
LumberCamp_T2,
LumberCamp_T3,
//Wool
SheepPasture_T1,
SheepPasture_T2,
SheepPasture_T3,

};

enum class BuildingCategory {
    Military,
    AdvancedMilitary,
    Defence,
    Economy, //economy + Farm
    Industry, //gray Buildings
    Religion
};
//Income category Type
enum class TaxCategory {
    None,
    Farm,       // green
    Commerce,   // yellow
    Industry,   // grey
    Religious,   // purple
    Maritime        //Blue
};
//Food Category Type
enum class FoodCategory{
    None,
    Farm,
    Maritime
};
inline TaxCategory GetTaxCategory(BuildingType buildingType) {
    switch (buildingType) {
        // ── FARM (green) ──
        case BuildingType::Settlement_Village_Knight_T1: case BuildingType::Settlement_Village_Knight_T2: case BuildingType::Settlement_Village_Knight_T3:
        case BuildingType::Settlement_Village_Viking_T1: case BuildingType::Settlement_Village_Viking_T2: case BuildingType::Settlement_Village_Viking_T3:
        case BuildingType::Settlement_Village_Samurai_T1: case BuildingType::Settlement_Village_Samurai_T2: case BuildingType::Settlement_Village_Samurai_T3://villages produce farm money
        case BuildingType::PeasantryGrowth_T1: case BuildingType::PeasantryGrowth_T2: case BuildingType::PeasantryGrowth_T3:
        case BuildingType::NobilityEstate_T1: case BuildingType::NobilityEstate_T2: case BuildingType::NobilityEstate_T3:
        case BuildingType::Economy_T1: case BuildingType::Economy_T2:
        case BuildingType::PeasantryVikingGrowth_T1: case BuildingType::PeasantryVikingGrowth_T2: case BuildingType::PeasantryVikingGrowth_T3:
        case BuildingType::NobilityVikingEstate_T1: case BuildingType::NobilityVikingEstate_T2: case BuildingType::NobilityVikingEstate_T3:
        case BuildingType::SlaveMarket_T1:     case BuildingType::SlaveMarket_T2:
        case BuildingType::PeasantrySamuraiGrowth_T1: case BuildingType::PeasantrySamuraiGrowth_T2: case BuildingType::PeasantrySamuraiGrowth_T3:
        case BuildingType::NobilitySamuraiEstate_T1: case BuildingType::NobilitySamuraiEstate_T2:  case BuildingType::NobilitySamuraiEstate_T3:
        case BuildingType::Market_T1: case BuildingType::Market_T2:
        case BuildingType::KnightGranary_T3: case BuildingType::KnightGranary_T4: case BuildingType::KnightGranary_T5:
        case BuildingType::VikingGranary_T3: case BuildingType::VikingGranary_T4: case BuildingType::VikingGranary_T5:
        case BuildingType::SamuraiGranary_T3: case BuildingType::SamuraiGranary_T4: case BuildingType::SamuraiGranary_T5:
            return TaxCategory::Farm;

        // ── COMMERCE (yellow) ──
        case BuildingType::KnightWareHouse_T3: case BuildingType::KnightWareHouse_T4: case BuildingType::KnightWareHouse_T5:
        case BuildingType::KnightRoads_T1:     case BuildingType::KnightRoads_T2:     case BuildingType::KnightRoads_T3:
        case BuildingType::KnightTavern_T1:
        case BuildingType::VikingWareHouse_T3: case BuildingType::VikingWareHouse_T4: case BuildingType::VikingWareHouse_T5:
        case BuildingType::VikingRoads_T1:     case BuildingType::VikingRoads_T2:     case BuildingType::VikingRoads_T3:
        case BuildingType::VikingTavern_T1:
        case BuildingType::SamuraiWareHouse_T3:case BuildingType::SamuraiWareHouse_T4:case BuildingType::SamuraiWareHouse_T5:
        case BuildingType::SamuraiRoads_T1:    case BuildingType::SamuraiRoads_T2:    case BuildingType::SamuraiRoads_T3:
        case BuildingType::SamuraiTavern_T1:
            return TaxCategory::Commerce;

        // ── INDUSTRY (grey) ──
        case BuildingType::KnightCarpentry_T1: case BuildingType::KnightCarpentry_T2:
        case BuildingType::KnightArtisan_T1:   case BuildingType::KnightArtisan_T2:   case BuildingType::KnightArtisan_T3:
        case BuildingType::KnightForge_T3:     case BuildingType::KnightForge_T4:     case BuildingType::KnightForge_T5:
        case BuildingType::KnightJeweller_T3:  case BuildingType::KnightJeweller_T4:  case BuildingType::KnightJeweller_T5:
        case BuildingType::VikingCarpentry_T1: case BuildingType::VikingCarpentry_T2:
        case BuildingType::VikingArtisan_T1:   case BuildingType::VikingArtisan_T2:   case BuildingType::VikingArtisan_T3:
        case BuildingType::VikingForge_T3:     case BuildingType::VikingForge_T4:     case BuildingType::VikingForge_T5:
        case BuildingType::VikingJeweller_T3:  case BuildingType::VikingJeweller_T4:  case BuildingType::VikingJeweller_T5:
        case BuildingType::SamuraiCarpentry_T1:case BuildingType::SamuraiCarpentry_T2:
        case BuildingType::SamuraiArtisan_T1:  case BuildingType::SamuraiArtisan_T2:  case BuildingType::SamuraiArtisan_T3:
        case BuildingType::SamuraiForge_T3:    case BuildingType::SamuraiForge_T4:    case BuildingType::SamuraiForge_T5:
        case BuildingType::SamuraiJeweller_T3: case BuildingType::SamuraiJeweller_T4: case BuildingType::SamuraiJeweller_T5:
        case BuildingType::IronMine_T1: case BuildingType::IronMine_T2: case BuildingType::IronMine_T3:
        case BuildingType::GoldMine_T1: case BuildingType::GoldMine_T2: case BuildingType::GoldMine_T3:
        case BuildingType::CopperMine_T1: case BuildingType::CopperMine_T2: case BuildingType::CopperMine_T3:
        case BuildingType::SilverMine_T1: case BuildingType::SilverMine_T2: case BuildingType::SilverMine_T3:
        case BuildingType::TinMine_T1: case BuildingType::TinMine_T2: case BuildingType::TinMine_T3:
        case BuildingType::LumberCamp_T1: case BuildingType::LumberCamp_T2: case BuildingType::LumberCamp_T3:
        case BuildingType::SheepPasture_T1: case BuildingType::SheepPasture_T2: case BuildingType::SheepPasture_T3:
        case BuildingType::KnightOilPress_T1: case BuildingType::KnightOilPress_T2:
        case BuildingType::KnightTinsmith_T2: case BuildingType::KnightTinsmith_T3: case BuildingType::KnightTinsmith_T4:
        case BuildingType::KnightMint_T2: case BuildingType::KnightMint_T3: case BuildingType::KnightMint_T4:
        case BuildingType::VikingOilPress_T1: case BuildingType::VikingOilPress_T2:
        case BuildingType::VikingTinsmith_T2: case BuildingType::VikingTinsmith_T3: case BuildingType::VikingTinsmith_T4:
        case BuildingType::VikingMint_T2: case BuildingType::VikingMint_T3: case BuildingType::VikingMint_T4:
        case BuildingType::SamuraiOilPress_T1: case BuildingType::SamuraiOilPress_T2:
        case BuildingType::SamuraiTinsmith_T2: case BuildingType::SamuraiTinsmith_T3: case BuildingType::SamuraiTinsmith_T4:
        case BuildingType::SamuraiMint_T2: case BuildingType::SamuraiMint_T3: case BuildingType::SamuraiMint_T4:
        case BuildingType::KnightTextile_T1: case BuildingType::KnightTextile_T2: case BuildingType::KnightTextile_T3:
        case BuildingType::VikingTextile_T1: case BuildingType::VikingTextile_T2: case BuildingType::VikingTextile_T3:
        case BuildingType::SamuraiTextile_T1: case BuildingType::SamuraiTextile_T2: case BuildingType::SamuraiTextile_T3:
            return TaxCategory::Industry;

        // ── RELIGIOUS (purple) ──
        case BuildingType::KnightAlmsHouse_T1: case BuildingType::KnightAlmsHouse_T2:
        case BuildingType::KnightBeeKeeper_T1: case BuildingType::KnightBeeKeeper_T2: case BuildingType::KnightBeeKeeper_T3:
        case BuildingType::KnightChurch_T3:    case BuildingType::KnightChurch_T4:    case BuildingType::KnightChurch_T5:
        case BuildingType::VikingShrine_T1:    case BuildingType::VikingShrine_T2:
        case BuildingType::VikingBrewKeeper_T1:case BuildingType::VikingBrewKeeper_T2:case BuildingType::VikingBrewKeeper_T3:
        case BuildingType::VikingSacrificeRitual_T3: case BuildingType::VikingSacrificeRitual_T4: case BuildingType::VikingSacrificeRitual_T5:
        case BuildingType::SamuraiHospital_T1: case BuildingType::SamuraiHospital_T2:
        case BuildingType::SamuraiTeaDry_T1:   case BuildingType::SamuraiTeaDry_T2:   case BuildingType::SamuraiTeaDry_T3:
        case BuildingType::SamuraiChapel_T3:   case BuildingType::SamuraiChapel_T4:   case BuildingType::SamuraiChapel_T5:
            return TaxCategory::Religious;

        //Port Tax Type
            // ── PORTS  ──
        case BuildingType::KnightMilitaryPort_T1: case BuildingType::KnightMilitaryPort_T2: case BuildingType::KnightMilitaryPort_T3:
        case BuildingType::KnightMilitaryPort_T4: case BuildingType::KnightMilitaryPort_T5:
        case BuildingType::KnightFishingPort_T1:  case BuildingType::KnightFishingPort_T2:  case BuildingType::KnightFishingPort_T3:
        case BuildingType::VikingMilitaryPort_T1: case BuildingType::VikingMilitaryPort_T2: case BuildingType::VikingMilitaryPort_T3:
        case BuildingType::VikingMilitaryPort_T4: case BuildingType::VikingMilitaryPort_T5:
        case BuildingType::VikingFishingPort_T1:  case BuildingType::VikingFishingPort_T2:  case BuildingType::VikingFishingPort_T3:
        case BuildingType::SamuraiMilitaryPort_T1: case BuildingType::SamuraiMilitaryPort_T2: case BuildingType::SamuraiMilitaryPort_T3:
        case BuildingType::SamuraiMilitaryPort_T4: case BuildingType::SamuraiMilitaryPort_T5:
        case BuildingType::SamuraiFishingPort_T1:  case BuildingType::SamuraiFishingPort_T2:  case BuildingType::SamuraiFishingPort_T3:
            return TaxCategory::Maritime;

        default:
            return TaxCategory::None;
    }
}

inline BuildingType GetMineBuildingType(ResourceType resource, int tier) {
    switch (resource) {
        case ResourceType::Iron:
            if (tier == 1) return BuildingType::IronMine_T1;
            if (tier == 2) return BuildingType::IronMine_T2;
            if (tier == 3) return BuildingType::IronMine_T3;
            break;
        case ResourceType::Gold:
            if (tier == 1) return BuildingType::GoldMine_T1;
            if (tier == 2) return BuildingType::GoldMine_T2;
            if (tier == 3) return BuildingType::GoldMine_T3;
            break;
        case ResourceType::Copper:
            if (tier == 1) return BuildingType::CopperMine_T1;
            if (tier == 2) return BuildingType::CopperMine_T2;
            if (tier == 3) return BuildingType::CopperMine_T3;
            break;
        case ResourceType::Silver:
            if (tier == 1) return BuildingType::SilverMine_T1;
            if (tier == 2) return BuildingType::SilverMine_T2;
            if (tier == 3) return BuildingType::SilverMine_T3;
            break;
        case ResourceType::Tin:
            if (tier == 1) return BuildingType::TinMine_T1;
            if (tier == 2) return BuildingType::TinMine_T2;
            if (tier == 3) return BuildingType::TinMine_T3;
            break;
        case ResourceType::Lumber:
            if (tier == 1) return BuildingType::LumberCamp_T1;
            if (tier == 2) return BuildingType::LumberCamp_T2;
            if (tier == 3) return BuildingType::LumberCamp_T3;
            break;
        case ResourceType::Wool:
            if (tier == 1) return BuildingType::SheepPasture_T1;
            if (tier == 2) return BuildingType::SheepPasture_T2;
            if (tier == 3) return BuildingType::SheepPasture_T3;
            break;
        default:
            break;
    }
    return BuildingType::None;
}

inline FoodCategory GetFoodCategory(BuildingType buildingType){
    switch (buildingType){

    case BuildingType::Settlement_Village_Knight_T1: case BuildingType::Settlement_Village_Knight_T2: case BuildingType::Settlement_Village_Knight_T3:
    case BuildingType::Settlement_Village_Viking_T1: case BuildingType::Settlement_Village_Viking_T2: case BuildingType::Settlement_Village_Viking_T3:
    case BuildingType::Settlement_Village_Samurai_T1: case BuildingType::Settlement_Village_Samurai_T2: case BuildingType::Settlement_Village_Samurai_T3://villages produce food from farm
    case BuildingType::PeasantryGrowth_T1: case BuildingType::PeasantryGrowth_T2: case BuildingType::PeasantryGrowth_T3:
    case BuildingType::NobilityEstate_T1: case BuildingType::NobilityEstate_T2: case BuildingType::NobilityEstate_T3:
    case BuildingType::PeasantryVikingGrowth_T1: case BuildingType::PeasantryVikingGrowth_T2: case BuildingType::PeasantryVikingGrowth_T3:
    case BuildingType::NobilityVikingEstate_T1: case BuildingType::NobilityVikingEstate_T2: case BuildingType::NobilityVikingEstate_T3:
    case BuildingType::PeasantrySamuraiGrowth_T1: case BuildingType::PeasantrySamuraiGrowth_T2: case BuildingType::PeasantrySamuraiGrowth_T3:
    case BuildingType::NobilitySamuraiEstate_T1: case BuildingType::NobilitySamuraiEstate_T2:  case BuildingType::NobilitySamuraiEstate_T3:
            return FoodCategory::Farm;

    case BuildingType::KnightFishingPort_T1:  case BuildingType::KnightFishingPort_T2:  case BuildingType::KnightFishingPort_T3:
    case BuildingType::VikingFishingPort_T1:  case BuildingType::VikingFishingPort_T2:  case BuildingType::VikingFishingPort_T3:
    case BuildingType::SamuraiFishingPort_T1:  case BuildingType::SamuraiFishingPort_T2:  case BuildingType::SamuraiFishingPort_T3:
            return FoodCategory::Maritime;

        default:
            return FoodCategory::None;
    }
}


inline BuildingCategory GetBuildingCategory(BuildingType buildingType){
    switch (buildingType){
    case BuildingType::Barracks_T1:
    case BuildingType::Barracks_T2:
    case BuildingType::Barracks_T3:
    case BuildingType::ArcheryRange_T1:
    case BuildingType::ArcheryRange_T2:
    case BuildingType::ArcheryRange_T3:
    case BuildingType::Stable_T1:
    case BuildingType::Stable_T2:
    case BuildingType::Stable_T3:
    case BuildingType::WarLodge_T1:
    case BuildingType::WarLodge_T2:
    case BuildingType::WarLodge_T3:
    case BuildingType::ShootingGround_T1:
    case BuildingType::ShootingGround_T2:
    case BuildingType::ShootingGround_T3:
    case BuildingType::HorseTraining_T1:
    case BuildingType::HorseTraining_T2:
    case BuildingType::HorseTraining_T3:
    case BuildingType::SwordSchool_T1:
    case BuildingType::SwordSchool_T2:
    case BuildingType::SwordSchool_T3:
    case BuildingType::ArcheryDojo_T1:
    case BuildingType::ArcheryDojo_T2:
    case BuildingType::ArcheryDojo_T3:
    case BuildingType::WarhorseStable_T1:
    case BuildingType::WarhorseStable_T2:
    case BuildingType::WarhorseStable_T3:
        return BuildingCategory::Military;

    case BuildingType::Artillery_T4:
    case BuildingType::Artillery_T5:
    case BuildingType::ChosensOfOdin_T3:
    case BuildingType::ChosensOfOdin_T4:
    case BuildingType::ChosensOfOdin_T5:
    case BuildingType::SiegeEngineerWorkshop_T4:
    case BuildingType::SiegeEngineerWorkshop_T5:
    case BuildingType::GunSmith_T4:
    case BuildingType::GunSmith_T5:
        return BuildingCategory::AdvancedMilitary;

    case BuildingType::ReinforceWalls_T3:
    case BuildingType::ReinforceWalls_T4:
    case BuildingType::ReinforceWalls_T5:
    case BuildingType::ReinforcedDrakkar_T3:
    case BuildingType::ReinforcedDrakkar_T4:
    case BuildingType::ReinforcedDrakkar_T5:
    case BuildingType::FortifiedCastle_T3:
    case BuildingType::FortifiedCastle_T4:
    case BuildingType::FortifiedCastle_T5:
        return BuildingCategory::Defence;

    case BuildingType::Economy_T1:
    case BuildingType::Economy_T2:
    case BuildingType::PeasantryGrowth_T1:
    case BuildingType::PeasantryGrowth_T2:
    case BuildingType::PeasantryGrowth_T3:
    case BuildingType::NobilityEstate_T1:
    case BuildingType::NobilityEstate_T2:
    case BuildingType::NobilityEstate_T3:
    case BuildingType::KnightWareHouse_T3:
    case BuildingType::KnightWareHouse_T4:
    case BuildingType::KnightWareHouse_T5:
    case BuildingType::KnightTavern_T1:
    case BuildingType::KnightGranary_T3:
    case BuildingType::KnightGranary_T4:
    case BuildingType::KnightGranary_T5:
    case BuildingType::SlaveMarket_T1:
    case BuildingType::SlaveMarket_T2:
    case BuildingType::PeasantryVikingGrowth_T1:
    case BuildingType::PeasantryVikingGrowth_T2:
    case BuildingType::PeasantryVikingGrowth_T3:
    case BuildingType::NobilityVikingEstate_T1:
    case BuildingType::NobilityVikingEstate_T2:
    case BuildingType::NobilityVikingEstate_T3:
    case BuildingType::VikingWareHouse_T3:
    case BuildingType::VikingWareHouse_T4:
    case BuildingType::VikingWareHouse_T5:
    case BuildingType::VikingTavern_T1:
    case BuildingType::VikingGranary_T3:
    case BuildingType::VikingGranary_T4:
    case BuildingType::VikingGranary_T5:
    case BuildingType::Market_T1:
    case BuildingType::Market_T2:
    case BuildingType::PeasantrySamuraiGrowth_T1:
    case BuildingType::PeasantrySamuraiGrowth_T2:
    case BuildingType::PeasantrySamuraiGrowth_T3:
    case BuildingType::NobilitySamuraiEstate_T1:
    case BuildingType::NobilitySamuraiEstate_T2:
    case BuildingType::NobilitySamuraiEstate_T3:
    case BuildingType::SamuraiWareHouse_T3:
    case BuildingType::SamuraiWareHouse_T4:
    case BuildingType::SamuraiWareHouse_T5:
    case BuildingType::SamuraiTavern_T1:
    case BuildingType::SamuraiGranary_T3:
    case BuildingType::SamuraiGranary_T4:
    case BuildingType::SamuraiGranary_T5:
    case BuildingType::KnightRoads_T1:
    case BuildingType::KnightRoads_T2:
    case BuildingType::KnightRoads_T3:
    case BuildingType::VikingRoads_T1:
    case BuildingType::VikingRoads_T2:
    case BuildingType::VikingRoads_T3:
    case BuildingType::SamuraiRoads_T1:
    case BuildingType::SamuraiRoads_T2:
    case BuildingType::SamuraiRoads_T3:
        return BuildingCategory::Economy;


    case BuildingType::KnightMint_T2:
    case BuildingType::KnightMint_T3:
    case BuildingType::KnightMint_T4:
    case BuildingType::VikingMint_T2:
    case BuildingType::VikingMint_T3:
    case BuildingType::VikingMint_T4:
    case BuildingType::SamuraiMint_T2:
    case BuildingType::SamuraiMint_T3:
    case BuildingType::SamuraiMint_T4:
    case BuildingType::KnightCarpentry_T1:
    case BuildingType::KnightCarpentry_T2:
    case BuildingType::KnightArtisan_T1:
    case BuildingType::KnightArtisan_T2:
    case BuildingType::KnightArtisan_T3:
    case BuildingType::KnightForge_T3:
    case BuildingType::KnightForge_T4:
    case BuildingType::KnightForge_T5:
    case BuildingType::KnightJeweller_T3:
    case BuildingType::KnightJeweller_T4:
    case BuildingType::KnightJeweller_T5:
    case BuildingType::VikingCarpentry_T1:
    case BuildingType::VikingCarpentry_T2:
    case BuildingType::VikingArtisan_T1:
    case BuildingType::VikingArtisan_T2:
    case BuildingType::VikingArtisan_T3:
    case BuildingType::VikingForge_T3:
    case BuildingType::VikingForge_T4:
    case BuildingType::VikingForge_T5:
    case BuildingType::VikingJeweller_T3:
    case BuildingType::VikingJeweller_T4:
    case BuildingType::VikingJeweller_T5:
    case BuildingType::SamuraiCarpentry_T1:
    case BuildingType::SamuraiCarpentry_T2:
    case BuildingType::SamuraiArtisan_T1:
    case BuildingType::SamuraiArtisan_T2:
    case BuildingType::SamuraiArtisan_T3:
    case BuildingType::SamuraiForge_T3:
    case BuildingType::SamuraiForge_T4:
    case BuildingType::SamuraiForge_T5:
    case BuildingType::SamuraiJeweller_T3:
    case BuildingType::SamuraiJeweller_T4:
    case BuildingType::SamuraiJeweller_T5:
    case BuildingType::KnightOilPress_T1:
    case BuildingType::KnightOilPress_T2:
    case BuildingType::KnightTinsmith_T2:
    case BuildingType::KnightTinsmith_T3:
    case BuildingType::KnightTinsmith_T4:
    case BuildingType::VikingOilPress_T1:
    case BuildingType::VikingOilPress_T2:
    case BuildingType::VikingTinsmith_T2:
    case BuildingType::VikingTinsmith_T3:
    case BuildingType::VikingTinsmith_T4:
    case BuildingType::SamuraiOilPress_T1:
    case BuildingType::SamuraiOilPress_T2:
    case BuildingType::SamuraiTinsmith_T2:
    case BuildingType::SamuraiTinsmith_T3:
    case BuildingType::SamuraiTinsmith_T4:
    case BuildingType::KnightTextile_T1:
    case BuildingType::KnightTextile_T2:
    case BuildingType::KnightTextile_T3:
    case BuildingType::VikingTextile_T1:
    case BuildingType::VikingTextile_T2:
    case BuildingType::VikingTextile_T3:
    case BuildingType::SamuraiTextile_T1:
    case BuildingType::SamuraiTextile_T2:
    case BuildingType::SamuraiTextile_T3:
        return BuildingCategory::Industry;

    case BuildingType::KnightAlmsHouse_T1:
    case BuildingType::KnightAlmsHouse_T2:
    case BuildingType::KnightBeeKeeper_T1:
    case BuildingType::KnightBeeKeeper_T2:
    case BuildingType::KnightBeeKeeper_T3:
    case BuildingType::KnightChurch_T3:
    case BuildingType::KnightChurch_T4:
    case BuildingType::KnightChurch_T5:
    case BuildingType::VikingShrine_T1:
    case BuildingType::VikingShrine_T2:
    case BuildingType::VikingBrewKeeper_T1:
    case BuildingType::VikingBrewKeeper_T2:
    case BuildingType::VikingBrewKeeper_T3:
    case BuildingType::VikingSacrificeRitual_T3:
    case BuildingType::VikingSacrificeRitual_T4:
    case BuildingType::VikingSacrificeRitual_T5:
    case BuildingType::SamuraiHospital_T1:
    case BuildingType::SamuraiHospital_T2:
    case BuildingType::SamuraiTeaDry_T1:
    case BuildingType::SamuraiTeaDry_T2:
    case BuildingType::SamuraiTeaDry_T3:
    case BuildingType::SamuraiChapel_T3:
    case BuildingType::SamuraiChapel_T4:
    case BuildingType::SamuraiChapel_T5:
        return BuildingCategory::Religion;

    default:
        return BuildingCategory::Economy;
    }
}
//To get the right port if Village or Castle
inline BuildingType GetPortBuildingType(SettlementType type, FactionZone faction, int tier) {
    if (type == SettlementType::Village) {
        if (faction == FactionZone::Knight) {
            if (tier == 1) return BuildingType::KnightFishingPort_T1;
            if (tier == 2) return BuildingType::KnightFishingPort_T2;
            if (tier == 3) return BuildingType::KnightFishingPort_T3;
        }
        else if (faction == FactionZone::Viking) {
            if (tier == 1) return BuildingType::VikingFishingPort_T1;
            if (tier == 2) return BuildingType::VikingFishingPort_T2;
            if (tier == 3) return BuildingType::VikingFishingPort_T3;
        }
        else if (faction == FactionZone::Samurai) {
            if (tier == 1) return BuildingType::SamuraiFishingPort_T1;
            if (tier == 2) return BuildingType::SamuraiFishingPort_T2;
            if (tier == 3) return BuildingType::SamuraiFishingPort_T3;
        }
    }
    else { // Castle ou Capital -> port militaire
        if (faction == FactionZone::Knight) {
            if (tier == 1) return BuildingType::KnightMilitaryPort_T1;
            if (tier == 2) return BuildingType::KnightMilitaryPort_T2;
            if (tier == 3) return BuildingType::KnightMilitaryPort_T3;
            if (tier == 4) return BuildingType::KnightMilitaryPort_T4;
            if (tier == 5) return BuildingType::KnightMilitaryPort_T5;
        }
        else if (faction == FactionZone::Viking) {
            if (tier == 1) return BuildingType::VikingMilitaryPort_T1;
            if (tier == 2) return BuildingType::VikingMilitaryPort_T2;
            if (tier == 3) return BuildingType::VikingMilitaryPort_T3;
            if (tier == 4) return BuildingType::VikingMilitaryPort_T4;
            if (tier == 5) return BuildingType::VikingMilitaryPort_T5;
        }
        else if (faction == FactionZone::Samurai) {
            if (tier == 1) return BuildingType::SamuraiMilitaryPort_T1;
            if (tier == 2) return BuildingType::SamuraiMilitaryPort_T2;
            if (tier == 3) return BuildingType::SamuraiMilitaryPort_T3;
            if (tier == 4) return BuildingType::SamuraiMilitaryPort_T4;
            if (tier == 5) return BuildingType::SamuraiMilitaryPort_T5;
        }
    }
    return BuildingType::None;
}




struct BuildingData {
    std::string name;
    std::string description;
    int cost;
    int upkeep;
    int incomeBonus;
    int publicOrderBonus;
    //constuction
    int Tier;
    int constructionTurns;
    //Food
    int foodUpkeep;
    int foodProduced;
    int foodStorage;
    //Resources
    //Growth
    int peasantryBornBonus;
    int nobilityBornBonus;
    int clergyTrainedBonus;
    //Death Growth
    int peasantryDeathBonus;
    BuildingType upgradesTo;

    //From Resources.h
    std::vector<ResourceAmount> resourcesProduced;
    int resourcesStorage = 0;//Fish and others share this storage. Must be bigger than the food storage
};

inline const std::unordered_map<BuildingType, BuildingData>& GetBuildingDatabase() {
    static std::unordered_map<BuildingType, BuildingData> db;
    if (!db.empty()) return db;

    // Helper lambda to insert cleanly
    auto add = [&](BuildingType key, BuildingData data) { db[key] = data; };
//{"Nom", "Desc", COST, upkeep, income, publicOrder, Tier, constructionTurns, Food Upkeep, Food Produced, foodStorage, peasantryBornBonus, nobilityBornBonus, clergyTrainedBonus, upgradesTo}
    // ── KNIGHT SETTLEMENTS ──
    add(BuildingType::Settlement_Village_Knight_T1, {"Hamlet", "A small town where farmers\ngrowth their lands", 0, 0, 10,  0, 1, 1, 0, 5, 0, 0, 0, 0, 0, BuildingType::Settlement_Village_Knight_T2});
    add(BuildingType::Settlement_Village_Knight_T2, {"Village", "The villagers has improved\nfarms and lands.", 250, 0, 25, 0, 2, 4, 0, 10, 0, 0, 0, 0,0, BuildingType::Settlement_Village_Knight_T3});
    add(BuildingType::Settlement_Village_Knight_T3, {"Large Village", "The farms are at their fullest\n potencial.", 1000, 0, 50, 0, 3, 6, 0, 15, 0, 0, 0, 0,0, BuildingType::None});
    add(BuildingType::Settlement_Castle_Knight_T1,  {"Small Fort", "A Wodden fort protecting\nthe nearby lands.", 900, 0, 0, 0, 1, 1, 5, 0, 25,0, 0, 0, 0, BuildingType::Settlement_Castle_Knight_T2});
    add(BuildingType::Settlement_Castle_Knight_T2,  {"Fort", "Stone walls and trained guards\nsecure the Castle.", 1100, 50, 0, 1, 2, 6, 10, 0, 25,0, 0, 0, 0, BuildingType::Settlement_Castle_Knight_T3});
    add(BuildingType::Settlement_Castle_Knight_T3,  {"Castle", "A strong castle housing nobles\nand military forces.", 2000, 120, 0, 1, 3, 8, 15, 0, 25, 0, 0, 0, 0, BuildingType::Settlement_Castle_Knight_T4});
    add(BuildingType::Settlement_Castle_Knight_T4,  {"Large Castle", "Massive walls and towers dominate\nthe surrounding region.", 3100, 190, 0, 2, 4, 10, 20, 0, 25, 0, 0, 0, 0, BuildingType::Settlement_Castle_Knight_T5});
    add(BuildingType::Settlement_Castle_Knight_T5,  {"Citadel",  "An impregnable stronghold and\nthe heart of military power.", 4000, 260, 0, 3, 5, 12, 25, 0, 25, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::Settlement_Capital_Knight_T1, {"Small Town Capital", "A growing capital where merchants\nand nobles gather.", 1500, 0, 0,  0, 1, 0, 5, 0, 50, 0, 0, 0, 0, BuildingType::Settlement_Capital_Knight_T2});
    add(BuildingType::Settlement_Capital_Knight_T2, {"Town Capital", "Busting streets and markets\nexpand the local economy.", 3100, 65, 0,  1, 2, 6, 10, 0, 50, 0, 0, 0, 0, BuildingType::Settlement_Capital_Knight_T3});
    add(BuildingType::Settlement_Capital_Knight_T3, {"City Capital", "A wealthy city filled with trader,\ncraftsmen and influence.", 4000, 140, 0,  1, 3, 8, 15, 0, 50, 0, 0, 0, 0, BuildingType::Settlement_Capital_Knight_T4});
    add(BuildingType::Settlement_Capital_Knight_T4, {"Large Capital", "Great districts and stone roads\nshape the mighty capital.", 6900, 220, 0,  2, 4, 10, 20, 0, 50, 0, 0, 0, 0, BuildingType::Settlement_Capital_Knight_T5});
    add(BuildingType::Settlement_Capital_Knight_T5, {"Royal Capital", "The glorious center of the kingdom,\nruled by powerful lords and nobility. ", 8000, 300, 0, 3, 5, 12, 40, 0, 50, 0, 0, 0, 0, BuildingType::None});

    // ── PORTS (KNIGHT) ──
    add(BuildingType::KnightMilitaryPort_T1, {"Naval Yard", "Modest docks where light vessels\nare built to patrol the coast\nand ferry troops abroad.", 500, 10, 0, 0, 1, 4, 0,0, 0, 0,0,0, 0, BuildingType::KnightMilitaryPort_T2});
    add(BuildingType::KnightMilitaryPort_T2, {"War Harbor", "Expanded shipyards turn out sturdier\nhulls, built to withstand the\nrigors of naval combat.", 900, 15, 0, 0, 2, 5, 0,0, 0, 0,0,0, 0, BuildingType::KnightMilitaryPort_T3});
    add(BuildingType::KnightMilitaryPort_T3, {"War Port", "A proper port of war, its docks\nnever idle as new warships are\nlaunched for the King's fleet.", 1400, 25, 0, 0, 3, 6, 0,0, 0, 0,0,0, 0, BuildingType::KnightMilitaryPort_T4});
    add(BuildingType::KnightMilitaryPort_T4, {"Grand War Port", "A vast harbor bristling with\nwarships, standing ready to\ndefend the realm's shores.", 2000, 40, 0, 0, 4, 8, 0,0, 0, 0,0,0, 0, BuildingType::KnightMilitaryPort_T5});
    add(BuildingType::KnightMilitaryPort_T5, {"Royal Shipyard", "The kingdom's greatest naval yard,\ncapable of arming an entire fleet\nin the King's name.", 3200, 50, 0, 0, 5, 10, 0,0, 0, 0,0,0, 0, BuildingType::None});

    add(BuildingType::KnightFishingPort_T1, {"Fishing Dock", "Small boats set out at dawn,\nbringing in just enough to\nfeed the village.", 400, 0, 15, 0, 1, 3, 0, 9, 0, 0,0,0, 0, BuildingType::KnightFishingPort_T2});
    add(BuildingType::KnightFishingPort_T2, {"Fishing Harbor", "An enlarged fleet of fishing boats\nbrings a steady bounty in from\nthe surrounding waters.", 700, 0, 25, 0, 2, 4, 0, 15, 0, 0,0,0, 0, BuildingType::KnightFishingPort_T3});
    add(BuildingType::KnightFishingPort_T3, {"Grand Fishing Harbor", "A thriving harbor where fishermen\nreturn each day with catches\nenough to feed the whole province.", 1100, 0, 40, 0, 3, 6, 0, 25, 0, 0,0,0, 0, BuildingType::None});

    // ── VIKING SETTLEMENTS ──
    add(BuildingType::Settlement_Village_Viking_T1, {"Small Settlement", "A small farm built by\nhardworking northern clans.", 0, 0, 25,  0, 1, 1, 0, 5, 0, 0, 0, 0, 0, BuildingType::Settlement_Village_Viking_T2});
    add(BuildingType::Settlement_Village_Viking_T2, {"Settlement",       "Wooden homes and fishing docks\nsupport the growing community.", 0, 0, 50,  0, 2, 1, 0, 10, 0, 0, 0, 0, 0, BuildingType::Settlement_Village_Viking_T3});
    add(BuildingType::Settlement_Village_Viking_T3, {"Large Settlement", "Thriving farms and busy harbors\nbring wealth to the village", 0, 0, 100, 0, 3, 1, 0, 15, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::Settlement_Castle_Viking_T1,  {"Small Longfort",   "A defensive camp protecting\nraiders and nearby villages.", 0, 0, 100, 0, 1, 1, 5, 0, 25, 0, 0, 0, 0, BuildingType::Settlement_Castle_Viking_T2});
    add(BuildingType::Settlement_Castle_Viking_T2,  {"Longfort",         "Strong wooden palisades guard\nthe warriors of the clan.", 0, 0, 175, 0, 2, 1, 10, 0, 25, 0, 0, 0, 0, BuildingType::Settlement_Castle_Viking_T3});
    add(BuildingType::Settlement_Castle_Viking_T3,  {"Great Longfort",   "A mighty stronghold where fierce\nvikings prepare for war.", 0, 0, 275, 0, 3, 1, 15, 0, 25, 0, 0, 0, 0, BuildingType::Settlement_Castle_Viking_T4});
    add(BuildingType::Settlement_Castle_Viking_T4,  {"Viking Fortress",  "Towering defenses and war camps\ndominate the northern lands.", 0, 0, 400, 0, 4, 1, 20, 0, 25, 0, 0, 0, 0, BuildingType::Settlement_Castle_Viking_T5});
    add(BuildingType::Settlement_Castle_Viking_T5,  {"Jarl's Keep",      "the seat of a powerful Jarl\nfeared across the seas.", 0, 0, 550, 0, 5, 1, 25, 0, 25, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::Settlement_Capital_Viking_T1, {"Small Longhouse Capital",  "A modest hall where the clan\nleaders gather and feast.", 0, 0, 200,  0, 1, 1, 5, 0, 50, 0, 0, 0, 0, BuildingType::Settlement_Capital_Viking_T2});
    add(BuildingType::Settlement_Capital_Viking_T2, {"Longhouse Capital",        "A great wooden hall filled with\nwarriors, merchants and skalds.", 0, 0, 350,  0, 2, 1, 10, 0, 50, 0, 0, 0, 0, BuildingType::Settlement_Capital_Viking_T3});
    add(BuildingType::Settlement_Capital_Viking_T3, {"Great Longhouse Capital",  "Large feasts and proud warriors\nstrength the clan's influence.", 0, 0, 550,  0, 3, 1, 15, 0, 50, 0, 0, 0, 0, BuildingType::Settlement_Capital_Viking_T4});
    add(BuildingType::Settlement_Capital_Viking_T4, {"Viking City Capital", "A prosperous northern city built\nthrough trade and conquest.", 0, 0, 800,  0, 4, 1, 20, 0, 50, 0, 0, 0,0, BuildingType::Settlement_Capital_Viking_T5});
    add(BuildingType::Settlement_Capital_Viking_T5, {"Jarl's Capital",   "The glorious capital of the Jarls,\nruling the northern kingdoms.", 0, 0, 1100, 0, 5, 1, 40, 0, 50, 0, 0, 0, 0, BuildingType::None});

    // ── PORTS (VIKING) ──
    add(BuildingType::VikingMilitaryPort_T1, {"Drakkar Yard", "A raw shipyard where young longships\nare hewn from northern timber,\nready for raid and plunder.", 500, 10, 0, 0, 1, 4, 0,0,0, 0,0,0, 0, BuildingType::VikingMilitaryPort_T2});
    add(BuildingType::VikingMilitaryPort_T2, {"Raiding Harbor", "Sturdier drakkars leave these docks,\ncarrying warriors far across\nthe cold northern seas.", 900, 15, 0, 0, 2, 5, 0,0,0, 0,0,0, 0, BuildingType::VikingMilitaryPort_T3});
    add(BuildingType::VikingMilitaryPort_T3, {"War Fjord", "A sheltered fjord turned shipyard\nof war, launching drakkars built\nfor battle upon the waves.", 1400, 25, 0, 0, 3, 6, 0,0, 0, 0,0,0, 0, BuildingType::VikingMilitaryPort_T4});
    add(BuildingType::VikingMilitaryPort_T4, {"Grand Longship Yard", "Rows of longships crowd the harbor,\na fleet fierce enough to strike\nfear into distant shores.", 2000, 40, 0, 0, 4, 8, 0,0,0, 0,0,0, 0, BuildingType::VikingMilitaryPort_T5});
    add(BuildingType::VikingMilitaryPort_T5, {"Jarl's Shipyard", "The greatest shipyard of the north,\nwhere the Jarl's fleet is forged\nto conquer the seas themselves.", 3200, 50, 0, 0, 5, 10, 0,0, 0, 0,0,0, 0, BuildingType::None});

    add(BuildingType::VikingFishingPort_T1, {"Fishing Camp", "A handful of boats brave the cold\nwaters each morning, bringing back\njust enough to feed the settlement.", 400, 0, 15, 0, 1, 3, 0, 9, 0, 0,0,0, 0, BuildingType::VikingFishingPort_T2});
    add(BuildingType::VikingFishingPort_T2, {"Fishing Cove", "A growing fleet works the coastal\nwaters, hauling in a steady\nbounty for the clan.", 700, 0, 25, 0, 2, 4, 0, 15, 0, 0,0,0,0, BuildingType::VikingFishingPort_T3});
    add(BuildingType::VikingFishingPort_T3, {"Grand Fishing Fjord", "A bustling fjord harbor where\nfishermen return laden with catch,\nfeeding villages up and down the coast.", 1100, 0, 40, 0, 3, 6, 0, 25, 0, 0,0,0, 0, BuildingType::None});

    // ── SAMURAI SETTLEMENTS ──
    add(BuildingType::Settlement_Village_Samurai_T1, {"Small Village", "A peaceful village surrounded\nby rice flields and farmers.", 0, 0, 25,  0, 1, 1, 0, 5, 0, 0, 0, 0, 0, BuildingType::Settlement_Village_Samurai_T2});
    add(BuildingType::Settlement_Village_Samurai_T2, {"Village", "Growing farms and skilled workers\nsupport the local clan.", 0, 0, 50,  0, 2, 1, 0, 10, 0, 0, 0, 0, 0, BuildingType::Settlement_Village_Samurai_T3});
    add(BuildingType::Settlement_Village_Samurai_T3, {"Large Village", "Prosperous lands and busy markets\nbring honor to the Shogun", 0, 0, 100, 0, 3, 1, 0, 15, 0, 0, 0, 0,0, BuildingType::None});
    add(BuildingType::Settlement_Castle_Samurai_T1,  {"Small Yashiro", "A modest stronghold guardgin\nthe nearby population", 0, 0, 100, 0, 1, 1, 5, 0, 25, 0, 0, 0, 0, BuildingType::Settlement_Castle_Samurai_T2});
    add(BuildingType::Settlement_Castle_Samurai_T2,  {"Yashiro", "Samurai warriors defend the clan\nfrom behind sturdy walls.", 0, 0, 175, 0, 2, 1, 10, 0, 25, 0, 0, 0,0, BuildingType::Settlement_Castle_Samurai_T3});
    add(BuildingType::Settlement_Castle_Samurai_T3,  {"Castle", "A respected castle housing\nwhere study and tradition meet protection.", 0, 0, 275, 0, 3, 1, 15, 0, 25, 0, 0, 0, 0, BuildingType::Settlement_Castle_Samurai_T4});
    add(BuildingType::Settlement_Castle_Samurai_T4,  {"Large Castle", "Tall towers and fortified gates\nprotect the province.", 0, 0, 400, 0, 4, 1, 20, 0, 25, 0, 0, 0, 0, BuildingType::Settlement_Castle_Samurai_T5});
    add(BuildingType::Settlement_Castle_Samurai_T5,  {"Fortress", "An immense fortress symbolizing\nthe power of the daimyo.", 0, 0, 550, 0, 5, 1, 25, 0, 25, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::Settlement_Capital_Samurai_T1, {"Small Town Capital", "A growing Capital where merchants\nand farmers gather", 0, 0, 200,  0, 1, 1, 5, 0, 50, 0, 0, 0,0, BuildingType::Settlement_Capital_Samurai_T2});
    add(BuildingType::Settlement_Capital_Samurai_T2, {"Town Capital", "Bustling streets and temples\nculture and military power.", 0, 0, 350,  0, 2, 1, 10, 0, 50, 0, 0, 0, 0, BuildingType::Settlement_Capital_Samurai_T3});
    add(BuildingType::Settlement_Capital_Samurai_T3, {"City Capital", "A wealthy Capital known for trade,\nculture and military power.", 0, 0, 550,  0, 3, 1, 15, 0, 50, 0, 0, 0, 0, BuildingType::Settlement_Capital_Samurai_T4});
    add(BuildingType::Settlement_Capital_Samurai_T4, {"Large City Capital", "Great districts and noble estates\nshape the mighty city", 0, 0, 800,  0, 4, 1, 20, 0, 50, 0, 0, 0, 0, BuildingType::Settlement_Capital_Samurai_T5});
    add(BuildingType::Settlement_Capital_Samurai_T5, {"Shogun's Capital", "The glorious seat of the Shogun,\nruling the empire with honor.", 0, 0, 1100, 0, 5, 1, 40, 0, 50, 0, 0, 0, 0, BuildingType::None});

    // ── PORTS (SAMURAI) ──
    add(BuildingType::SamuraiMilitaryPort_T1, {"Coastal Shipwright", "A modest wharf where shipwrights\ncraft light vessels to guard\nthe coastline and ferry troops.", 500, 10, 0, 0, 1, 4, 0,0,0, 0,0,0, 0, BuildingType::SamuraiMilitaryPort_T2});
    add(BuildingType::SamuraiMilitaryPort_T2, {"War Harbor", "Reinforced hulls leave this busier\nharbor, built to serve the\ndaimyo's growing ambitions.", 900, 15, 0, 0, 2, 5, 0,0, 0, 0,0,0, 0, BuildingType::SamuraiMilitaryPort_T3});
    add(BuildingType::SamuraiMilitaryPort_T3, {"Naval Stronghold", "A fortified harbor turning out\nwarships worthy of the Shogunate's\nnaval traditions.", 1400, 25, 0, 0, 3, 6, 0,0, 0, 0,0,0, 0, BuildingType::SamuraiMilitaryPort_T4});
    add(BuildingType::SamuraiMilitaryPort_T4, {"Grand Fleet Harbor", "An imposing harbor housing a fleet\nlarge enough to project the\nclan's power across the seas.", 2000, 40, 0, 0, 4, 8, 0,0,0, 0,0,0, 0, BuildingType::SamuraiMilitaryPort_T5});
    add(BuildingType::SamuraiMilitaryPort_T5, {"Shogun's Armada", "The empire's mightiest shipyard,\nwhere the Shogun's armada is\nbuilt to rule the surrounding waters.", 3200, 50, 0, 0, 5, 10, 0,0,0, 0,0,0, 0, BuildingType::None});

    add(BuildingType::SamuraiFishingPort_T1, {"Fishing Village Dock", "Small fishing boats set out at\ndawn, bringing back a modest\ncatch for the village.", 400, 0, 15, 0, 1, 3, 0, 9, 0, 0,0,0,0, BuildingType::SamuraiFishingPort_T2});
    add(BuildingType::SamuraiFishingPort_T2, {"Fishing Harbor", "An expanded fleet of fishing boats\nbrings home a steady harvest\nfrom the surrounding waters.", 700, 0, 25, 0, 2, 4, 0, 15, 0, 0,0,0, 0, BuildingType::SamuraiFishingPort_T3});
    add(BuildingType::SamuraiFishingPort_T3, {"Grand Fishing Harbor", "A prosperous harbor where the\ndaily catch is plentiful enough\nto sustain the whole province.", 1100, 0, 40, 0, 3, 6, 0, 25, 0, 0,0,0,0, BuildingType::None});
    // ── KNIGHT ECONOMY ──
    add(BuildingType::KnightWareHouse_T3, {"Storehouse", "Not everything can be sold\nstraight away, must be stored.", 700, 40, 0, 0, 3, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::KnightWareHouse_T4}); //store 25 food
    add(BuildingType::KnightWareHouse_T4, {"Warehouse", "A large storage of goods \nready to be sold", 850, 60, 0, 0, 4, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::KnightWareHouse_T5}); // store 50 food
    add(BuildingType::KnightWareHouse_T5, {"Great Warehouse", "All goods can be stored,\nsafe from the weather", 1000, 80, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::None}); // store 75 food
    add(BuildingType::KnightRoads_T1, {"Dirt Roads", "Simple tracks packed by hoof\nand cart, easing the passage\nof goods between towns.", 400, 5, 15, 0, 1, 4, 0, 0, 0, 0, 0, 0, 0, BuildingType::KnightRoads_T2});
    add(BuildingType::KnightRoads_T2, {"Paved Roads", "Stone-laid roads speed merchants\nand messengers alike across\nthe kingdom's lands.", 650, 10, 30, 0, 2, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::KnightRoads_T3});
    add(BuildingType::KnightRoads_T3, {"Royal Highway", "A great highway binding the\nrealm together, along which\ntrade flows without pause.", 950, 15, 50, 0, 3, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::KnightTavern_T1, {"Tavern", "An intelligent man is sometimes \nforced to be intoxicated to \nspend time with fools.", 900, 0, 20, 3, 1,6, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});

    add(BuildingType::Economy_T1, {"Small Farm shop", "Basic farmland.",        100,  0,  20,  0, 1, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::Economy_T2});
    add(BuildingType::Economy_T2, {"Village market", "Established farmland.",   250,  0,  35,  0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::PeasantryGrowth_T1,  {"Small community farms", "Grows peasant population.", 195,  0,  15,  2, 1, 2, 0, 13, 0, 5, 0, 0, 0, BuildingType::PeasantryGrowth_T2});//Peasantry generate more food
    add(BuildingType::PeasantryGrowth_T2,  {"Open field farms", "Grows population faster.", 225, 0,  20,  4, 2, 3, 0, 20, 0, 10, 0, 0, 0, BuildingType::PeasantryGrowth_T3});
    add(BuildingType::PeasantryGrowth_T3,  {"Commons", "Major peasantrygrowth bonus.",  270, 0, 25,  6, 3, 4, 0, 26, 0, 30, 0, 0, 0, BuildingType::None});
    add(BuildingType::NobilityEstate_T1,  {"Small private farm", "Grows population.", 80,  0,  15,  2, 1, 2, 0, 6, 0, 0, 3, 0, 0, BuildingType::NobilityEstate_T2});//Nobility generate less food but more money
    add(BuildingType::NobilityEstate_T2,  {"Lord's Fields", "Grows population faster.", 200, 0,  30,  4, 2, 3, 0, 10, 0, 0, 5, 0, 0, BuildingType::NobilityEstate_T3});
    add(BuildingType::NobilityEstate_T3,  {"Grand Manor Farm", "Major growth bonus.", 400, 0, 45,  6, 3, 4, 0, 14, 0, 0, 8, 0, 0, BuildingType::None});
    add(BuildingType::KnightGranary_T3, {"Granary", "Not everything can be sold\nstraight away, must be stored.", 700, 40, 0, 0, 3, 5, 0, 0, 25, 0, 0, 0, 0, BuildingType::KnightGranary_T4});
    add(BuildingType::KnightGranary_T4, {"Grand Granary", "A large storage of goods \nready to be sold", 850, 60, 0, 0, 4, 5, 0, 0, 50, 0, 0, 0, 0, BuildingType::KnightGranary_T5});
    add(BuildingType::KnightGranary_T5, {"Royal Granary", "All goods can be stored,\nsafe from the weather", 1000, 80, 0, 0, 5, 7, 0, 0, 75, 0, 0, 0, 0, BuildingType::None});

    // ── KNIGHT INDUSTRY ──
    add(BuildingType::KnightOilPress_T1, {"Fish Render", "The parts of the catch too poor\nto sell are rendered down into\noil, wasting nothing.", 500, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::KnightOilPress_T2});
    add(BuildingType::KnightOilPress_T2, {"Rendery", "A proper rendery turns the day's\ncatch into oil fit for lamps,\nleather, and trade alike.", 750, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::KnightCarpentry_T1, {"Carpenter", "Natural shelter from the elements\ncan be found here, as well as\nprecious timber reserves.", 450, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::KnightCarpentry_T2});
    add(BuildingType::KnightCarpentry_T2, {"Woodshop", "The forest itself provides the\n handle for the woodcutter's axe.", 700, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::None });
    add(BuildingType::KnightTextile_T1, {"Weaver's Cottage", "Wool spun by hand here becomes\nthe cloth that clothes both\npeasant and lord alike.", 600, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::KnightTextile_T2});
    add(BuildingType::KnightTextile_T2, {"Weaver's Guild", "Skilled weavers turn raw wool\ninto fine cloth, sought after\nin markets near and far.", 750, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::KnightTextile_T3});
    add(BuildingType::KnightTextile_T3, {"Grand Textile Hall", "The finest cloth in the realm\nis woven here, rivaling even\nforeign silks in quality.", 900, 0, 0, 0, 3, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::KnightArtisan_T1, {"Artisan", "If you've got made-goods to sell,\nthe chances are that this man\ncan find you a buyer.", 750, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::KnightArtisan_T2});
    add(BuildingType::KnightArtisan_T2, {"Craft Workshop", "If you travel far enough, there's\nalways a buyer willing to buy\nor barter for your wares.", 900, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::KnightArtisan_T3 });
    add(BuildingType::KnightArtisan_T3, {"Crafts Industry", "I have buyers lined up across the\nkingdom and beyond, and the vessels to get\nthe goods where they need to be.", 1050, 0, 0, 0, 3, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::None });
    add(BuildingType::KnightTinsmith_T2, {"Tinsmith", "Tin, once beaten and shaped,\nbecomes plate, cup and tankard\nfor lord and peasant alike.", 750, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::KnightTinsmith_T3});
    add(BuildingType::KnightTinsmith_T3, {"Pewter Workshop", "Pewter wares leave this workshop\nby the cartload, bound for every\nmarket in the realm.", 900, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::KnightTinsmith_T4});
    add(BuildingType::KnightTinsmith_T4, {"Pewterers' Hall", "The guild's finest pewterers work\nhere, their wares prized far\nbeyond the kingdom's borders.", 1050, 0, 0, 0, 4, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::KnightMint_T2, {"Mint", "Coins hold power beyond wealth.\nThey are legitimacy.\nThey are loyalty.", 600, 5, 0, 0, 2, 11, 0, 0, 0, 0, 0, 0, 0, BuildingType::KnightMint_T3});
    add(BuildingType::KnightMint_T3, {"Royal Mint", "When your face is everywhere,\nthere can be no doubt \nwho rules.", 750, 10, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, BuildingType::KnightMint_T4});
    add(BuildingType::KnightMint_T4, {"Treasury", "The coffers of the state, from \nwhich funds are drawn \naccording to need and favour.", 900, 15, 0, 0, 4, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::KnightForge_T3, {"Blacksmith", "What is wrought by the blacksmith\nwill last a lifetime.", 850, 0, 0, 0, 3, 8, 0, 0, 0, 0, 0, 0, 0, BuildingType::KnightForge_T4});
    add(BuildingType::KnightForge_T4, {"Forge", "The modern world is born\nof the forge.", 1000, 0, 0, 0, 4, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::KnightForge_T5 });
    add(BuildingType::KnightForge_T5, {"Great Forge", "Incredible temperatures allow\nmetals and alloys to be shaped with\nthe greatest of ease.", 1200, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::None });
    add(BuildingType::KnightJeweller_T3, {"Jewellers", "The rare skills necessary to work\nprecious metals ensure that\nthose who have them are never\nout of work.", 750, 0, 0, 0, 3, 9, 0, 0, 0, 0, 0, 0, 0, BuildingType::KnightJeweller_T4});
    add(BuildingType::KnightJeweller_T4, {"Master jewellers", "To take the necessary and make\nit special? Now that takes skill", 900, 0, 0, 0, 4, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::KnightJeweller_T5 });
    add(BuildingType::KnightJeweller_T5, {"Jewelley Industry", "As pure function has given way\nto ornate forms, so the artisan\njeweller has risen to be master of his craft.", 1050, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::None });

    // ── KNIGHT MILITARY ──
    add(BuildingType::Barracks_T1,     {"Militia Grounds",  "Trains basic infantry.",   150, 10, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::Barracks_T2});
    add(BuildingType::Barracks_T2,     {"Training Grounds", "Trains medium infantry.",  300, 20, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::Barracks_T3});
    add(BuildingType::Barracks_T3,     {"War Academy",      "Trains elite infantry.",   600, 35, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::ArcheryRange_T1, {"Archery Range",    "Trains archers.",          150, 10, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::ArcheryRange_T2});
    add(BuildingType::ArcheryRange_T2, {"Fletchers Guild",  "Trains longbowmen.",       300, 20, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::ArcheryRange_T3});
    add(BuildingType::ArcheryRange_T3, {"Royal Archery",    "Trains elite archers.",    600, 35, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::Stable_T1,       {"Stable",           "Trains light cavalry.",    150, 10, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::Stable_T2});
    add(BuildingType::Stable_T2,       {"Knight Stable",    "Trains heavy cavalry.",    300, 20, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::Stable_T3});
    add(BuildingType::Stable_T3,       {"Royal Stable",     "Trains elite cavalry.",    600, 35, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});

    // ── KNIGHT ADVANCED MILITARY ──
    add(BuildingType::Artillery_T4, {"Siege Workshop",  "Builds catapults.",   800,  40, 0, 0, 4, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::Artillery_T5});
    add(BuildingType::Artillery_T5, {"Royal Artillery", "Builds trebuchets.", 1200,  60, 0, 0, 5, 6, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});

    // ── KNIGHT DEFENCE ──
    add(BuildingType::ReinforceWalls_T3, {"Stone Walls",     "Reinforces defences.",    600, 20, 0,  5, 3, 4, 10, 0, 0, 0, 0, 0, 0, BuildingType::ReinforceWalls_T4});
    add(BuildingType::ReinforceWalls_T4, {"Fortified Walls", "Strong stone walls.",     900, 30, 0,  8, 4, 5, 15, 0, 0, 0, 0, 0, 0, BuildingType::ReinforceWalls_T5});
    add(BuildingType::ReinforceWalls_T5, {"Castle Walls",    "Impregnable defences.",  1400, 45, 0, 12, 5, 6, 25, 0, 0, 0, 0, 0, 0, BuildingType::None});

    // ── KNIGHT RELIGION ──
    //Reconstitution
    add(BuildingType::KnightAlmsHouse_T1, {"Small Hospital",    "Improves public order.",  100,  5, 0,  2, 1, 2, 0, 0, 0, 0, 0, 1, 0, BuildingType::KnightAlmsHouse_T2});
    add(BuildingType::KnightAlmsHouse_T2, {"Medium hospital",    "Strong public order.",    250, 10, 0, 3, 2, 3, 0, 0, 0, 0, 0, 3, 0, BuildingType::None});
    //Bee production
    add(BuildingType::KnightBeeKeeper_T1, {"BeeKeeper1",    "Improves public order.",  100,  5, 0,  2, 1, 2, 0, 0, 0, 0, 0, 1, 0, BuildingType::KnightBeeKeeper_T2});
    add(BuildingType::KnightBeeKeeper_T2, {"Beekeeper2",    "Strong public order.",    250, 10, 0, 3, 2, 3, 0, 0, 0, 0, 0, 3, 0, BuildingType::KnightBeeKeeper_T3});
    add(BuildingType::KnightBeeKeeper_T3, {"Beekeeper3", "Major public order.",     500, 15, 0, 4, 3, 4, 0, 0, 0, 0, 0, 5, 0, BuildingType::None});
    //public order
    add(BuildingType::KnightChurch_T3, {"Chapel",    "Improves public order.",  100,  5, 0,  2, 3, 2, 0, 0, 0, 0, 0, 1, 0, BuildingType::KnightChurch_T4});
    add(BuildingType::KnightChurch_T4, {"Church",    "Strong public order.",    250, 10, 0, 3, 4, 3, 0, 0, 0, 0, 0, 3, 0, BuildingType::KnightChurch_T5});
    add(BuildingType::KnightChurch_T5, {"Cathedral", "Major public order.",     500, 15, 0, 4, 5, 4, 0, 0, 0, 0, 0, 5, 0, BuildingType::None});

    // ── VIKING MILITARY ──
    add(BuildingType::WarLodge_T1,       {"War Lodge",       "Trains raiders.",         150, 10, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::WarLodge_T2});
    add(BuildingType::WarLodge_T2,       {"Warrior Hall",    "Trains berserkers.",      300, 20, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::WarLodge_T3});
    add(BuildingType::WarLodge_T3,       {"Jarl's War Hall", "Trains elite warriors.",  600, 35, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::ShootingGround_T1, {"Shooting Ground", "Trains skirmishers.",     150, 10, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::ShootingGround_T2});
    add(BuildingType::ShootingGround_T2, {"Hunting Lodge",   "Trains hunters.",         300, 20, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::ShootingGround_T3});
    add(BuildingType::ShootingGround_T3, {"Elite Marksmen",  "Trains elite archers.",   600, 35, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::HorseTraining_T1,  {"Horse Training",  "Trains light cavalry.",   150, 10, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::HorseTraining_T2});
    add(BuildingType::HorseTraining_T2,  {"Cavalry Grounds", "Trains heavy cavalry.",   300, 20, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::HorseTraining_T3});
    add(BuildingType::HorseTraining_T3,  {"Elite Horsemen",  "Trains elite cavalry.",   600, 35, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});

    // ── VIKING ADVANCED MILITARY ──
    add(BuildingType::ChosensOfOdin_T3, {"Chosen of Odin",  "Elite berserker unit.",   800,  40, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, BuildingType::ChosensOfOdin_T4});
    add(BuildingType::ChosensOfOdin_T4, {"Odin's Warriors", "Legendary berserkers.",  1200,  60, 0, 0, 4, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::ChosensOfOdin_T5});
    add(BuildingType::ChosensOfOdin_T5, {"Einherjar",       "Mythical warriors.",     1800,  80, 0, 0, 5, 6, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});

    // ── VIKING DEFENCE ──
    add(BuildingType::ReinforcedDrakkar_T3, {"Drakkar Docks",     "Reinforced ships.",    600, 20, 0,  5, 3, 4, 10, 0, 0, 0, 0, 0, 0, BuildingType::ReinforcedDrakkar_T4});
    add(BuildingType::ReinforcedDrakkar_T4, {"War Drakkar",       "Heavy warships.",      900, 30, 0,  8, 4, 5, 15, 0, 0, 0, 0, 0, 0, BuildingType::ReinforcedDrakkar_T5});
    add(BuildingType::ReinforcedDrakkar_T5, {"Legendary Drakkar", "Unstoppable fleet.",  1400, 45, 0, 12, 5, 6, 25, 0, 0, 0, 0, 0, 0, BuildingType::None});

    // ── VIKING ECONOMY ──

    add(BuildingType::VikingWareHouse_T3, {"Storehouse", "Not everything can be sold\nstraight away, must be stored.", 700, 40, 0, 0, 3, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingWareHouse_T4});
    add(BuildingType::VikingWareHouse_T4, {"Warehouse", "A large storage of goods \nready to be sold", 850, 60, 0, 0, 4, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingWareHouse_T5});
    add(BuildingType::VikingWareHouse_T5, {"Great Warehouse", "All goods can be stored,\nsafe from the weather", 1000, 80, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::VikingRoads_T1, {"Trade Path", "A worn path linking settlement\nto settlement, trodden by\ntraders and raiders alike.", 400, 5, 15, 0, 1, 4, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingRoads_T2});
    add(BuildingType::VikingRoads_T2, {"Stone Track", "Laid stone speeds carts and\nsledges through the northern\nclan lands.", 650, 10, 30, 0, 2, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingRoads_T3});
    add(BuildingType::VikingRoads_T3, {"Grand Trade Route", "A route stretching far beyond\nthe clan's own lands, bringing\nwealth from distant shores.", 950, 15, 50, 0, 3, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::VikingTavern_T1, {"Tavern", "An intelligent man is sometimes \nforced to be intoxicated to \nspend time with fools.", 900, 0, 20, 3, 1,6, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});

    add(BuildingType::SlaveMarket_T1, {"Slave Market", "Income from raids.", 100,  0,  20,  0, 1, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::SlaveMarket_T2});
    add(BuildingType::SlaveMarket_T2, {"Slave Medium Market", "More raid income.", 250,  0,  35,  0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::PeasantryVikingGrowth_T1,  {"Viking Village Market", "Grows peasant population.", 195,  0,  15,  2, 1, 2, 0, 13, 0, 5, 0, 0, 0, BuildingType::PeasantryVikingGrowth_T2});
    add(BuildingType::PeasantryVikingGrowth_T2,  {"Town Market", "Grows population faster.", 225, 0,  20,  4, 2, 3, 0, 20, 0, 10, 0, 0, 0, BuildingType::PeasantryVikingGrowth_T3});
    add(BuildingType::PeasantryVikingGrowth_T3,  {"Grand Market", "Major growth bonus.", 270, 0, 25,  6, 3, 4, 0, 26, 0,  30, 0, 0, 0, BuildingType::None});
    add(BuildingType::NobilityVikingEstate_T1,  {"Viking Village Market", "Grows population.", 80,  0,  15,  2, 1, 2, 0, 6, 0, 0, 3, 0, 0, BuildingType::NobilityVikingEstate_T2});
    add(BuildingType::NobilityVikingEstate_T2,  {"Town Market", "Grows population faster.", 200, 0,  30,  4, 2, 3, 0, 10, 0,  0, 5, 0, 0, BuildingType::NobilityVikingEstate_T3});
    add(BuildingType::NobilityVikingEstate_T3,  {"Grand Market", "Major growth bonus.", 400, 0, 45,  6, 3, 4, 0, 14, 0, 0, 8, 0, 0, BuildingType::None});
    add(BuildingType::VikingGranary_T3, {"Granary", "Not everything can be sold\nstraight away, must be stored.", 700, 40, 0, 0, 3, 5, 0, 0, 25, 0, 0, 0, 0, BuildingType::VikingGranary_T4});
    add(BuildingType::VikingGranary_T4, {"Grand Granary", "A large storage of goods \nready to be sold", 850, 60, 0, 0, 4, 5, 0, 0, 50, 0, 0, 0, 0, BuildingType::VikingGranary_T5});
    add(BuildingType::VikingGranary_T5, {"Royal Granary", "All goods can be stored,\nsafe from the weather", 1000, 80, 0, 0, 5, 7, 0, 0, 75, 0, 0, 0, 0, BuildingType::None});

    // ── VIKING INDUSTRY ──
    add(BuildingType::VikingOilPress_T1, {"Blubber Shed", "Fish and whatever else the sea\ngives up is boiled down here,\nnothing wasted in the cold north.", 500, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingOilPress_T2});
    add(BuildingType::VikingOilPress_T2, {"Trying House", "A proper trying house, its fires\nnever cold, renders oil enough\nto light halls through the winter.", 750, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::VikingCarpentry_T1, {"Carpenter", "Natural shelter from the elements\ncan be found here, as well as\nprecious timber reserves.", 450, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingCarpentry_T2});
    add(BuildingType::VikingCarpentry_T2, {"Woodshop", "The forest itself provides the\n handle for the woodcutter's axe.", 700, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::None });
    add(BuildingType::VikingTextile_T1, {"Wool Shed", "Sheep shorn upon the fells\nprovide wool enough to keep\nthe clan warm through winter.", 600, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingTextile_T2});
    add(BuildingType::VikingTextile_T2, {"Weaving Hall", "Norse women weave sturdy sailcloth\nand garments, their skill prized\nas much as any warrior's.", 750, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingTextile_T3});
    add(BuildingType::VikingTextile_T3, {"Grand Weaving Hall", "Sails and cloaks woven here carry\nthe clan's mark across the seas,\nfit for jarls and raiders alike.", 900, 0, 0, 0, 3, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::VikingArtisan_T1, {"Artisan", "If you've got made-goods to sell,\nthe chances are that this man\ncan find you a buyer.", 750, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingArtisan_T2});
    add(BuildingType::VikingArtisan_T2, {"Craft Workshop", "If you travel far enough, there's\nalways a buyer willing to buy\nor barter for your wares.", 900, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingArtisan_T3 });
    add(BuildingType::VikingArtisan_T3, {"Crafts Industry", "I have buyers lined up across the\nkingdom and beyond, and the vessels to get\nthe goods where they need to be.", 1050, 0, 0, 0, 3, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::None });
    add(BuildingType::VikingTinsmith_T2, {"Tin Caster", "Tin is cast into cups and clasps\nhere, humble work for a\nhumble metal.", 750, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingTinsmith_T3});
    add(BuildingType::VikingTinsmith_T3, {"Casting Hearth", "A busy hearth where tin is\nworked into wares traded up\nand down the coast.", 900, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingTinsmith_T4});
    add(BuildingType::VikingTinsmith_T4, {"Grand Tin Foundry", "The finest pewter in the north\nis cast here, fit for a Jarl's\nown table.", 1050, 0, 0, 0, 4, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::VikingMint_T2, {"Mint", "Coins hold power beyond wealth.\nThey are legitimacy.\nThey are loyalty.", 600, 5, 0, 0, 2, 11, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingMint_T3});
    add(BuildingType::VikingMint_T3, {"Royal Mint", "When your face is everywhere,\nthere can be no doubt \nwho rules.", 750, 10, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingMint_T4});
    add(BuildingType::VikingMint_T4, {"Treasury", "The coffers of the state, from \nwhich funds are drawn \naccording to need and favour.", 900, 15, 0, 0, 4, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::VikingForge_T3, {"Blacksmith", "What is wrought by the blacksmith\nwill last a lifetime.", 850, 0, 0, 0, 3, 8, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingForge_T4});
    add(BuildingType::VikingForge_T4, {"Forge", "The modern world is born\nof the forge.", 1000, 0, 0, 0, 4, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingForge_T5 });
    add(BuildingType::VikingForge_T5, {"Great Forge", "Incredible temperatures allow\nmetals and alloys to be shaped with\nthe greatest of ease.", 1200, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::None });
    add(BuildingType::VikingJeweller_T3, {"Jewellers", "The rare skills necessary to work\nprecious metals ensure that\nthose who have them are never\nout of work.", 750, 0, 0, 0, 3, 9, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingJeweller_T4});
    add(BuildingType::VikingJeweller_T4, {"Master jewellers", "To take the necessary and make\nit special? Now that takes skill", 900, 0, 0, 0, 4, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingJeweller_T5 });
    add(BuildingType::VikingJeweller_T5, {"Jewelley Industry", "As pure function has given way\nto ornate forms, so the artisan\njeweller has risen to be master of his craft.", 1050, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::None });
    
    // ── VIKING RELIGION ──
    //reconstitution
    add(BuildingType::VikingShrine_T1,{"Shrine",          "Pleases the gods.",        100,  5, 0,  0, 1, 2, 0, 0, 0, 0, 0, 1, 0, BuildingType::VikingShrine_T2});
    add(BuildingType::VikingShrine_T2,{"Temple",          "Greater divine favor.",    250, 10, 0, 1, 2, 3, 0, 0, 0, 0, 0, 3, 0, BuildingType::None});
    //Beer production
    add(BuildingType::VikingBrewKeeper_T1, {"SmallReligiousBeerProduction",    "Improves public order.",  100,  5, 0,  2, 1, 2, 0, 0, 0, 0, 0, 1, 0, BuildingType::VikingBrewKeeper_T2});
    add(BuildingType::VikingBrewKeeper_T2, {"MediumReligiousBeerProduction",    "Strong public order.",    250, 10, 0, 3, 2, 3, 0, 0, 0, 0, 0, 3, 0, BuildingType::VikingBrewKeeper_T3});
    add(BuildingType::VikingBrewKeeper_T3, {"LargeReligiousBeerProduction", "Major public order.",     500, 15, 0, 4, 3, 4, 0, 0, 0, 0, 0, 5, 0, BuildingType::None});
    //PublicOrder
    add(BuildingType::VikingSacrificeRitual_T3, {"Ritual Ground",   "Blood for Odin.",          150,  5, 0,  2, 3, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingSacrificeRitual_T4});
    add(BuildingType::VikingSacrificeRitual_T4, {"Sacrifice Altar", "Greater blood offering.",  300, 10, 0, 3, 4, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::VikingSacrificeRitual_T5});
    add(BuildingType::VikingSacrificeRitual_T5, {"Grand Sacrifice", "Odin's full blessing.",    600, 15, 0, 4, 5, 4, 0, 0, 0, 0, 0, 0,0, BuildingType::None});

    // ── SAMURAI MILITARY ──
    add(BuildingType::SwordSchool_T1,    {"Sword School",    "Trains katana units.",     150, 10, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::SwordSchool_T2});
    add(BuildingType::SwordSchool_T2,    {"Kenjutsu Dojo",   "Trains elite swordsmen.",  300, 20, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::SwordSchool_T3});
    add(BuildingType::SwordSchool_T3,    {"Bushido Academy", "Trains master swordsmen.", 600, 35, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::ArcheryDojo_T1,    {"Archery Dojo",    "Trains bowmen.",           150, 10, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::ArcheryDojo_T2});
    add(BuildingType::ArcheryDojo_T2,    {"Kyudo School",    "Trains expert archers.",   300, 20, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::ArcheryDojo_T3});
    add(BuildingType::ArcheryDojo_T3,    {"Master Kyudo",    "Trains elite archers.",    600, 35, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::WarhorseStable_T1, {"Warhorse Stable", "Trains light cavalry.",    150, 10, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::WarhorseStable_T2});
    add(BuildingType::WarhorseStable_T2, {"Samurai Stable",  "Trains heavy cavalry.",    300, 20, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::WarhorseStable_T3});
    add(BuildingType::WarhorseStable_T3, {"Elite Warhorse",  "Trains elite cavalry.",    600, 35, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});

    // ── SAMURAI ADVANCED MILITARY ──
    add(BuildingType::SiegeEngineerWorkshop_T4, {"Siege Workshop", "Builds siege engines.",  800,  40, 0, 0, 4, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::SiegeEngineerWorkshop_T5});
    add(BuildingType::SiegeEngineerWorkshop_T5, {"Master Siege",   "Elite siege engines.",  1200,  60, 0, 0, 5, 6, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::GunSmith_T4,              {"Gunsmith",        "Builds firearms.",       800,  40, 0, 0, 4, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::GunSmith_T5});
    add(BuildingType::GunSmith_T5,              {"Master Gunsmith", "Elite firearms.",        1200, 60, 0, 0, 5, 6, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});

    // ── SAMURAI DEFENCE ──
    add(BuildingType::FortifiedCastle_T3, {"Stone Castle",     "Reinforced castle.",    600, 20, 0,  5, 3, 4, 10, 0, 0, 0, 0, 0, 0, BuildingType::FortifiedCastle_T4});
    add(BuildingType::FortifiedCastle_T4, {"Fortified Castle", "Strong defences.",      900, 30, 0,  8, 4, 5, 15, 0, 0, 0, 0, 0, 0, BuildingType::FortifiedCastle_T5});
    add(BuildingType::FortifiedCastle_T5, {"Impregnable Keep", "Unbreachable walls.",  1400, 45, 0, 12, 5, 6, 25, 0, 0, 0, 0, 0, 0, BuildingType::None});

    // ── SAMURAI ECONOMY ──

    add(BuildingType::SamuraiWareHouse_T3, {"Storehouse", "Not everything can be sold\nstraight away, must be stored.", 700, 40, 0, 0, 3, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiWareHouse_T4});
    add(BuildingType::SamuraiWareHouse_T4, {"Warehouse", "A large storage of goods \nready to be sold", 850, 60, 0, 0, 4, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiWareHouse_T5});
    add(BuildingType::SamuraiWareHouse_T5, {"Great Warehouse", "All goods can be stored,\nsafe from the weather", 1000, 80, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::SamuraiRoads_T1, {"Mountain Path", "A narrow path winding between\nvillages, carrying goods over\nthe province's hills.", 400, 5, 15, 0, 1, 4, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiRoads_T2});
    add(BuildingType::SamuraiRoads_T2, {"Stone Road", "A properly laid road allowing\nswift passage of merchants\nand messengers alike.", 650, 10, 30, 0, 2, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiRoads_T3});
    add(BuildingType::SamuraiRoads_T3, {"Imperial Highway", "A grand road connecting the\nprovince to the wider empire,\ncarrying trade without end.", 950, 15, 50, 0, 3, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::SamuraiTavern_T1, {"Tavern", "An intelligent man is sometimes \nforced to be intoxicated to \nspend time with fools.", 900, 0, 20, 3, 1,6, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});

    add(BuildingType::Market_T1, {"Samurai Village Market", "Basic trade.", 100,  0,  20,  0, 1, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::Market_T2});
    add(BuildingType::Market_T2, {"Town Market",    "Established trade.",  250,  0,  35,  0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::PeasantrySamuraiGrowth_T1,  {"samurai Village Market",    "Grows peasant population.", 195,  0,  15,  2, 1, 2, 0, 13, 0, 5, 0, 0, 0, BuildingType::PeasantrySamuraiGrowth_T2});
    add(BuildingType::PeasantrySamuraiGrowth_T2,  {"Town Market",       "Grows population faster.", 225, 0,  20,  4, 2, 3, 0, 20, 0, 10, 0, 0, 0, BuildingType::PeasantrySamuraiGrowth_T3});
    add(BuildingType::PeasantrySamuraiGrowth_T3,  {"Grand Market",      "Major growth bonus.", 270, 0, 25,  6, 3, 4, 0, 26, 0, 30, 0, 0, 0, BuildingType::None});
    add(BuildingType::NobilitySamuraiEstate_T1,  {"Samurai Village Market",    "Grows population.", 80,  0,  15,  2, 1, 2, 0, 6, 0, 0, 3, 0, 0, BuildingType::NobilitySamuraiEstate_T2});
    add(BuildingType::NobilitySamuraiEstate_T2,  {"Town Market",       "Grows population faster.", 200, 0,  30,  4, 2, 3, 0, 10, 0, 0, 5, 0, 0, BuildingType::NobilitySamuraiEstate_T3});
    add(BuildingType::NobilitySamuraiEstate_T3,  {"Grand Market",      "Major growth bonus.", 400, 0, 45,  6, 3, 4, 0, 14, 0, 0, 8, 0, 0, BuildingType::None});
    add(BuildingType::SamuraiGranary_T3, {"Granary", "Not everything can be sold\nstraight away, must be stored.", 700, 40, 0, 0, 3, 5, 0, 0, 25, 0, 0, 0, 0, BuildingType::SamuraiGranary_T4});
    add(BuildingType::SamuraiGranary_T4, {"Grand Granary", "A large storage of goods \nready to be sold", 850, 60, 0, 0, 4, 5, 0, 0, 50, 0, 0, 0, 0, BuildingType::SamuraiGranary_T5});
    add(BuildingType::SamuraiGranary_T5, {"Royal Granary", "All goods can be stored,\nsafe from the weather", 1000, 80, 0, 0, 5, 7, 0, 0, 75, 0, 0, 0, 0, BuildingType::None});

    // ── SAMURAI INDUSTRY ──
    add(BuildingType::SamuraiOilPress_T1, {"Oil Hut", "Nothing from the day's catch\ngoes to waste, rendered instead\ninto oil for lamp and trade.", 500, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiOilPress_T2});
    add(BuildingType::SamuraiOilPress_T2, {"Abura-ya", "A dedicated oil house, its stores\nsupplying lamps and markets\nfar beyond the coast.", 750, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::SamuraiCarpentry_T1, {"Carpenter", "Natural shelter from the elements\ncan be found here, as well as\nprecious timber reserves.", 450, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiCarpentry_T2});
    add(BuildingType::SamuraiCarpentry_T2, {"Woodshop", "The forest itself provides the\n handle for the woodcutter's axe.", 700, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::None });
    add(BuildingType::SamuraiTextile_T1, {"Silk Hut", "Silkworms are tended carefully\nhere, their threads destined\nfor fine robes and banners.", 600, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiTextile_T2});
    add(BuildingType::SamuraiTextile_T2, {"Silk Workshop", "Skilled weavers spin silk into\ncloth prized by nobles and\nmerchants throughout the province.", 750, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiTextile_T3});
    add(BuildingType::SamuraiTextile_T3, {"Grand Silk Hall", "The province's finest silk is\nwoven here, worthy of the\nShogun's own court.", 900, 0, 0, 0, 3, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::SamuraiArtisan_T1, {"Artisan", "If you've got made-goods to sell,\nthe chances are that this man\ncan find you a buyer.", 750, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiArtisan_T2});
    add(BuildingType::SamuraiArtisan_T2, {"Craft Workshop", "If you travel far enough, there's\nalways a buyer willing to buy\nor barter for your wares.", 900, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiArtisan_T3 });
    add(BuildingType::SamuraiArtisan_T3, {"Crafts Industry", "I have buyers lined up across the\nkingdom and beyond, and the vessels to get\nthe goods where they need to be.", 1050, 0, 0, 0, 3, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::None });
    add(BuildingType::SamuraiTinsmith_T2, {"Suzu Smith", "Tin is worked into simple wares\nhere, valued for both use and\ntrade.", 750, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiTinsmith_T3});
    add(BuildingType::SamuraiTinsmith_T3, {"Suzu Workshop", "A busy workshop turning out\npewter goods sought after\nacross the province.", 900, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiTinsmith_T4});
    add(BuildingType::SamuraiTinsmith_T4, {"Suzu-za", "The province's finest tinware\nguild hall, its pewter prized\nby merchants and nobles alike.", 1050, 0, 0, 0, 4, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::SamuraiMint_T2, {"Mint", "Coins hold power beyond wealth.\nThey are legitimacy.\nThey are loyalty.", 600, 5, 0, 0, 2, 11, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiMint_T3});
    add(BuildingType::SamuraiMint_T3, {"Royal Mint", "When your face is everywhere,\nthere can be no doubt \nwho rules.", 750, 10, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiMint_T4});
    add(BuildingType::SamuraiMint_T4, {"Treasury", "The coffers of the state, from \nwhich funds are drawn \naccording to need and favour.", 900, 15, 0, 0, 4, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    add(BuildingType::SamuraiForge_T3, {"Blacksmith", "What is wrought by the blacksmith\nwill last a lifetime.", 850, 0, 0, 0, 3, 8, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiForge_T4});
    add(BuildingType::SamuraiForge_T4, {"Forge", "The modern world is born\nof the forge.", 1000, 0, 0, 0, 4, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiForge_T5 });
    add(BuildingType::SamuraiForge_T5, {"Great Forge", "Incredible temperatures allow\nmetals and alloys to be shaped with\nthe greatest of ease.", 1200, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 0, BuildingType::None });
    add(BuildingType::SamuraiJeweller_T3, {"Jewellers", "The rare skills necessary to work\nprecious metals ensure that\nthose who have them are never\nout of work.", 750, 0, 0, 0, 3, 9, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiJeweller_T4});
    add(BuildingType::SamuraiJeweller_T4, {"Master jewellers", "To take the necessary and make\nit special? Now that takes skill", 900, 0, 0, 0, 4, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiJeweller_T5 });
    add(BuildingType::SamuraiJeweller_T5, {"Jewelley Industry", "As pure function has given way\nto ornate forms, so the artisan\njeweller has risen to be master of his craft.", 1050, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::None });

    // ── SAMURAI RELIGION ──
    //reconstitution
    add(BuildingType::SamuraiHospital_T1, {"Field Hospital", "Heals troops.", 100,  5, 0,  2, 1, 2, 0, 0, 0, 0, 0, 0, 0, BuildingType::SamuraiHospital_T2});
    add(BuildingType::SamuraiHospital_T2, {"Hospital", "Better healing.", 250, 10, 0, 3, 2, 3, 0, 0, 0, 0, 0, 0, 0, BuildingType::None});
    //Tea Dry
    add(BuildingType::SamuraiTeaDry_T1, {"small religious tea dry", "Improves public order.",  100,  5, 0,  2, 1, 2, 0, 0, 0, 0, 0, 1, 0, BuildingType::SamuraiTeaDry_T2});
    add(BuildingType::SamuraiTeaDry_T2, {"Medium religious tea dry", "Strong public order.", 250, 10, 0, 3, 2, 3, 0, 0, 0, 0, 0, 3, 0, BuildingType::SamuraiTeaDry_T3});
    add(BuildingType::SamuraiTeaDry_T3, {"Large religious tea dry", "Major public order.", 500, 15, 0, 4, 3, 4, 0, 0, 0, 0, 0, 5, 0, BuildingType::None});
    //public order
    add(BuildingType::SamuraiChapel_T3, {"Shinto Shrine", "Basic worship.", 100, 5, 0,  1, 3, 2, 0, 0, 0, 0, 0, 1, 0, BuildingType::SamuraiChapel_T4});
    add(BuildingType::SamuraiChapel_T4, {"Shinto Temple", "Greater worship.", 250, 10, 0, 1, 4, 3, 0, 0, 0, 0, 0, 3, 0, BuildingType::SamuraiChapel_T5});
    add(BuildingType::SamuraiChapel_T5, {"Grand Shrine", "Divine blessing.", 500, 15, 0, 2, 5, 4, 0, 0, 0, 0, 0, 5, 0, BuildingType::None});

    // -- MINES (Raw Ressources Building Production)--
    //iron
    add(BuildingType::IronMine_T1, {"Iron Veins", "Iron ore is are common as it is useful.", 750, 15, 0, 0, 1, 14, 0, 0, 0, 0, 0, 0, 5, BuildingType::IronMine_T2});
    add(BuildingType::IronMine_T2, {"Iron Mine", "The reign of iron is well underway\nwherever it can be mined, it\nabsolutely should be.", 900, 20, 0, 0, 2, 7, 0, 0, 0, 0, 0, 0, 8, BuildingType::IronMine_T3});
    add(BuildingType::IronMine_T3, {"Iron Foundry", "Iron ore, once refined, is used to\nmake myriad items both valuable\nand lethal.", 1100, 25, 0, 0, 3, 10, 0, 0, 0, 0, 0, 0, 13, BuildingType::None});
    //gold
    add(BuildingType::GoldMine_T1, {"Gold Veins", "Great seams of gold, running like\n rivers through stone...", 1050, 15, 0, 0, 1, 18, 0, 0, 0, 0, 0, 0, 5, BuildingType::GoldMine_T2});
    add(BuildingType::GoldMine_T2, {"Gold Mine", "All that glitters may not be gold, but\n if it is, you're probably minted.", 1150, 20, 0, 0, 2, 10,  0, 0, 0, 0, 0, 0,  8, BuildingType::GoldMine_T3});
    add(BuildingType::GoldMine_T3, {"Gold Foundry", "The lure of pure gold makes even the\nwisest man forget himself.", 1250, 25, 0, 0, 3, 14, 0, 0, 0, 0, 0, 0, 13, BuildingType::None});
    //copper
    add(BuildingType::CopperMine_T1, {"Copper Veins", "The red metal of Cyprus can also be\nfound in the parts.", 850, 15, 0, 0, 1, 14, 0, 0, 0, 0, 0, 0, 5, BuildingType::CopperMine_T2});
    add(BuildingType::CopperMine_T2, {"Copper Mine", "To take advantage of copper's useful\nqualities, all that is needed is a\ndeeplying trench.", 1000, 20, 0, 0, 2, 5, 0, 0, 0, 0, 0, 0, 8, BuildingType::CopperMine_T3});
    add(BuildingType::CopperMine_T3, {"Copper Smelter", "The sulphides extracted from the\nopen-face mines are processed here,", 1200, 25, 0, 0, 3, 7, 0, 0, 0, 0, 0, 0, 13, BuildingType::None});
    //Silver
    add(BuildingType::SilverMine_T1, {"Silver Veins", "With its metallic lustre, some\nconsider silver's aesthetic qualities to\nbe as attractive as gold.", 950, 15, 0, 0, 1, 12, 0, 0, 0, 0, 0, 0, 5, BuildingType::SilverMine_T2});
    add(BuildingType::SilverMine_T2, {"Silver Mine", "Tapping into such a resource enables\nthe fashioning of all manner of\nvaluable items.", 1100, 20, 0, 0, 2, 7, 0, 0, 0, 0, 0, 0, 8, BuildingType::SilverMine_T3});
    add(BuildingType::SilverMine_T3, {"Silver Smelter", "To smelt silver is to manifest\ncurrency, in doing so harnessing\nwealth and power.", 1300, 25, 0, 0, 3, 10, 0, 0, 0, 0, 0, 0, 13, BuildingType::None});
    //Tin
    add(BuildingType::TinMine_T1, {"Tin Veins", "Without tin, there would be no\nbronze age, and by extension little\nknowledge of metalcraft.", 850, 15, 0, 0, 1, 12, 0, 0, 0, 0, 0, 0, 5, BuildingType::TinMine_T2});
    add(BuildingType::TinMine_T2, {"Tin Mine", "A material so rarely mined in this\npart of the world is extremely\nvaluable indeed.", 1000, 20, 0, 0, 2, 7, 0, 0, 0, 0, 0, 0, 8, BuildingType::TinMine_T3});
    add(BuildingType::TinMine_T3, {"Tin Smelter", "When smelting in paltry wood fires is\nno longer sufficient, one needs a\nbigger furnace.", 1200, 25, 0, 0, 3, 10, 0, 0, 0, 0, 0, 0, 13, BuildingType::None});
    //Wood
    add(BuildingType::LumberCamp_T1, {"Small lumber camp", "Lumber is very important.\nWithout it we can't build arrows or furnitures.", 650, 10, 0, 0, 1, 12, 0, 0, 0, 0, 0, 0, 2, BuildingType::LumberCamp_T2});
    add(BuildingType::LumberCamp_T2, {"Lumber camp", "Lumber is very important.\nWithout it we can't build arrows or furnitures.", 800, 15, 0, 0, 2, 6, 0, 0, 0, 0, 0, 0, 3, BuildingType::LumberCamp_T3});
    add(BuildingType::LumberCamp_T3, {"Large lumber camp", "Lumber is very important.\nWithout it we can't build arrows or furnitures.", 650, 20, 0, 0, 3, 12, 0, 0, 0, 0, 0, 0, 5, BuildingType::None});
    //Wool
    add(BuildingType::SheepPasture_T1, {"Small Sheep Pasture", "Flocks graze upon these fields,\ntheir wool sheared for cloth\nand trade alike.", 650, 10, 0, 0, 1, 12, 0, 0, 0, 0, 0, 0, 2, BuildingType::SheepPasture_T2});
    add(BuildingType::SheepPasture_T2, {"Sheep Pasture", "A larger flock is tended here,\nyielding wool enough to supply\nweavers across the province.", 800, 15, 0, 0, 2, 6, 0, 0, 0, 0, 0, 0, 3, BuildingType::SheepPasture_T3});
    add(BuildingType::SheepPasture_T3, {"Large Sheep Pasture", "Vast pastures teem with sheep,\ntheir wool feeding a thriving\ntextile trade.", 650, 20, 0, 0, 3, 12, 0, 0, 0, 0, 0, 0, 5, BuildingType::None});
    // ── RESOURCE PRODUCTION ──
    //ports
    db[BuildingType::KnightFishingPort_T1].resourcesProduced = {{ResourceType::Fish, 1}};
    db[BuildingType::KnightFishingPort_T2].resourcesProduced = {{ResourceType::Fish, 2}};
    db[BuildingType::KnightFishingPort_T3].resourcesProduced = {{ResourceType::Fish, 3}};

    db[BuildingType::VikingFishingPort_T1].resourcesProduced = {{ResourceType::Fish, 1}};
    db[BuildingType::VikingFishingPort_T2].resourcesProduced = {{ResourceType::Fish, 2}};
    db[BuildingType::VikingFishingPort_T3].resourcesProduced = {{ResourceType::Fish, 3}};

    db[BuildingType::SamuraiFishingPort_T1].resourcesProduced = {{ResourceType::Fish, 1}};
    db[BuildingType::SamuraiFishingPort_T2].resourcesProduced = {{ResourceType::Fish, 2}};
    db[BuildingType::SamuraiFishingPort_T3].resourcesProduced = {{ResourceType::Fish, 3}};

    //Iron Mine
    db[BuildingType::IronMine_T1].resourcesProduced = {{ResourceType::Iron, 1}};
    db[BuildingType::IronMine_T2].resourcesProduced = {{ResourceType::Iron, 2}};
    db[BuildingType::IronMine_T3].resourcesProduced = {{ResourceType::Iron, 3}};
    //Gold Mine
    db[BuildingType::GoldMine_T1].resourcesProduced = {{ResourceType::Gold, 1}};
    db[BuildingType::GoldMine_T2].resourcesProduced = {{ResourceType::Gold, 2}};
    db[BuildingType::GoldMine_T3].resourcesProduced = {{ResourceType::Gold, 3}};
    //Copper Mine
    db[BuildingType::CopperMine_T1].resourcesProduced = {{ResourceType::Copper, 1}};
    db[BuildingType::CopperMine_T2].resourcesProduced = {{ResourceType::Copper, 2}};
    db[BuildingType::CopperMine_T3].resourcesProduced = {{ResourceType::Copper, 3}};
    //Silver Mine
    db[BuildingType::SilverMine_T1].resourcesProduced = {{ResourceType::Silver, 1}};
    db[BuildingType::SilverMine_T2].resourcesProduced = {{ResourceType::Silver, 2}};
    db[BuildingType::SilverMine_T3].resourcesProduced = {{ResourceType::Silver, 3}};
    //Tin Mine
    db[BuildingType::TinMine_T1].resourcesProduced = {{ResourceType::Tin, 1}};
    db[BuildingType::TinMine_T2].resourcesProduced = {{ResourceType::Tin, 2}};
    db[BuildingType::TinMine_T3].resourcesProduced = {{ResourceType::Tin, 3}};
    //Lumber camp
    db[BuildingType::LumberCamp_T1].resourcesProduced = {{ResourceType::Lumber, 1}};
    db[BuildingType::LumberCamp_T2].resourcesProduced = {{ResourceType::Lumber, 2}};
    db[BuildingType::LumberCamp_T3].resourcesProduced = {{ResourceType::Lumber, 3}};
    //Wool  sheep pasture
    db[BuildingType::SheepPasture_T1].resourcesProduced = {{ResourceType::Wool, 1}};
    db[BuildingType::SheepPasture_T2].resourcesProduced = {{ResourceType::Wool, 2}};
    db[BuildingType::SheepPasture_T3].resourcesProduced = {{ResourceType::Wool, 3}};

    // ── GOODS STORAGE CAPACITY ──
    // Capitals (base 100 slot each)
    db[BuildingType::Settlement_Capital_Knight_T1].resourcesStorage = 100;
    db[BuildingType::Settlement_Capital_Knight_T2].resourcesStorage = 100;
    db[BuildingType::Settlement_Capital_Knight_T3].resourcesStorage = 100;
    db[BuildingType::Settlement_Capital_Knight_T4].resourcesStorage = 100;
    db[BuildingType::Settlement_Capital_Knight_T5].resourcesStorage = 100;
    db[BuildingType::Settlement_Capital_Viking_T1].resourcesStorage = 100;
    db[BuildingType::Settlement_Capital_Viking_T2].resourcesStorage = 100;
    db[BuildingType::Settlement_Capital_Viking_T3].resourcesStorage = 100;
    db[BuildingType::Settlement_Capital_Viking_T4].resourcesStorage = 100;
    db[BuildingType::Settlement_Capital_Viking_T5].resourcesStorage = 100;
    db[BuildingType::Settlement_Capital_Samurai_T1].resourcesStorage = 100;
    db[BuildingType::Settlement_Capital_Samurai_T2].resourcesStorage = 100;
    db[BuildingType::Settlement_Capital_Samurai_T3].resourcesStorage = 100;
    db[BuildingType::Settlement_Capital_Samurai_T4].resourcesStorage = 100;
    db[BuildingType::Settlement_Capital_Samurai_T5].resourcesStorage = 100;

    // Castles (base 50 slot each)
    db[BuildingType::Settlement_Castle_Knight_T1].resourcesStorage = 50;
    db[BuildingType::Settlement_Castle_Knight_T2].resourcesStorage = 50;
    db[BuildingType::Settlement_Castle_Knight_T3].resourcesStorage = 50;
    db[BuildingType::Settlement_Castle_Knight_T4].resourcesStorage = 50;
    db[BuildingType::Settlement_Castle_Knight_T5].resourcesStorage = 50;
    db[BuildingType::Settlement_Castle_Viking_T1].resourcesStorage = 50;
    db[BuildingType::Settlement_Castle_Viking_T2].resourcesStorage = 50;
    db[BuildingType::Settlement_Castle_Viking_T3].resourcesStorage = 50;
    db[BuildingType::Settlement_Castle_Viking_T4].resourcesStorage = 50;
    db[BuildingType::Settlement_Castle_Viking_T5].resourcesStorage = 50;
    db[BuildingType::Settlement_Castle_Samurai_T1].resourcesStorage = 50;
    db[BuildingType::Settlement_Castle_Samurai_T2].resourcesStorage = 50;
    db[BuildingType::Settlement_Castle_Samurai_T3].resourcesStorage = 50;
    db[BuildingType::Settlement_Castle_Samurai_T4].resourcesStorage = 50;
    db[BuildingType::Settlement_Castle_Samurai_T5].resourcesStorage = 50;

    // Warehouses (adds on top of Capital/Castle base)
    db[BuildingType::KnightWareHouse_T3].resourcesStorage = 100;
    db[BuildingType::KnightWareHouse_T4].resourcesStorage = 150;
    db[BuildingType::KnightWareHouse_T5].resourcesStorage = 250;
    db[BuildingType::VikingWareHouse_T3].resourcesStorage = 100;
    db[BuildingType::VikingWareHouse_T4].resourcesStorage = 150;
    db[BuildingType::VikingWareHouse_T5].resourcesStorage = 250;
    db[BuildingType::SamuraiWareHouse_T3].resourcesStorage = 100;
    db[BuildingType::SamuraiWareHouse_T4].resourcesStorage = 150;
    db[BuildingType::SamuraiWareHouse_T5].resourcesStorage = 250;

    return db;
}
//data of a building
inline const BuildingData* GetBuildingData(BuildingType type) {
    const auto& buildingDataBase = GetBuildingDatabase();
    auto it = buildingDataBase.find(type);
    return (it != buildingDataBase.end()) ? &it->second : nullptr;
}

inline std::vector<BuildingType> GetBuildingsForCategory(BuildingCategory categoryType, FactionZone faction, int settlementTier) {
    int maxTier = settlementTier;

    std::vector<BuildingType> results;

    switch (categoryType) {
        case BuildingCategory::Military:
            if (faction == FactionZone::Knight)
                results = {BuildingType::Barracks_T1, BuildingType::ArcheryRange_T1, BuildingType::Stable_T1};
            else if (faction == FactionZone::Viking)
                results = {BuildingType::WarLodge_T1, BuildingType::ShootingGround_T1, BuildingType::HorseTraining_T1};
            else if (faction == FactionZone::Samurai)
                results = {BuildingType::SwordSchool_T1, BuildingType::ArcheryDojo_T1, BuildingType::WarhorseStable_T1};
            break;

        case BuildingCategory::AdvancedMilitary:
            if (faction == FactionZone::Knight)
                results = {BuildingType::Artillery_T4};
            else if (faction == FactionZone::Viking)
                results = {BuildingType::ChosensOfOdin_T3};
            else if (faction == FactionZone::Samurai)
                results = {BuildingType::SiegeEngineerWorkshop_T4, BuildingType::GunSmith_T4};
            break;

        case BuildingCategory::Defence:
            if (faction == FactionZone::Knight)
                results = {BuildingType::ReinforceWalls_T3};
            else if (faction == FactionZone::Viking)
                results = {BuildingType::ReinforcedDrakkar_T3};
            else if (faction == FactionZone::Samurai)
                results = {BuildingType::FortifiedCastle_T3};
            break;

        case BuildingCategory::Economy:
            if (faction == FactionZone::Knight)
                results = {BuildingType::KnightWareHouse_T3, BuildingType::KnightRoads_T1, BuildingType::KnightTavern_T1, BuildingType::Economy_T1, BuildingType::PeasantryGrowth_T1, BuildingType::NobilityEstate_T1, BuildingType::KnightGranary_T3};
            else if (faction == FactionZone::Viking)
                results = {BuildingType::VikingWareHouse_T3, BuildingType::VikingRoads_T1, BuildingType::VikingTavern_T1, BuildingType::SlaveMarket_T1, BuildingType::PeasantryVikingGrowth_T1, BuildingType::NobilityVikingEstate_T1, BuildingType::VikingGranary_T3};
            else if (faction == FactionZone::Samurai)
                results = {BuildingType::SamuraiWareHouse_T3, BuildingType::SamuraiRoads_T1, BuildingType::SamuraiTavern_T1, BuildingType::Market_T1, BuildingType::PeasantrySamuraiGrowth_T1, BuildingType::NobilitySamuraiEstate_T1, BuildingType::SamuraiGranary_T3};
            break;

        case BuildingCategory::Industry:
        if (faction == FactionZone::Knight)
              results = {BuildingType::KnightOilPress_T1, BuildingType::KnightCarpentry_T1, BuildingType::KnightTextile_T1 ,BuildingType::KnightArtisan_T1, BuildingType::KnightTinsmith_T2, BuildingType::KnightMint_T2, BuildingType:: KnightForge_T3, BuildingType::KnightJeweller_T3};
        else if (faction == FactionZone::Viking)
              results = {BuildingType::VikingOilPress_T1, BuildingType::VikingCarpentry_T1, BuildingType::VikingTextile_T1 ,BuildingType::VikingArtisan_T1, BuildingType::VikingTinsmith_T2, BuildingType::VikingMint_T2, BuildingType:: VikingForge_T3, BuildingType::VikingJeweller_T3};
        else if (faction == FactionZone::Samurai)
              results = {BuildingType::SamuraiOilPress_T1, BuildingType::SamuraiCarpentry_T1, BuildingType::SamuraiTextile_T1 ,BuildingType::SamuraiArtisan_T1, BuildingType::SamuraiTinsmith_T2, BuildingType::SamuraiMint_T2, BuildingType:: SamuraiForge_T3, BuildingType::SamuraiJeweller_T3};
            break;
        case BuildingCategory::Religion:
            if (faction == FactionZone::Knight)
                results = {BuildingType::KnightAlmsHouse_T1, BuildingType::KnightBeeKeeper_T1, BuildingType::KnightChurch_T3};
            else if (faction == FactionZone::Viking)
                results = {BuildingType::VikingShrine_T1, BuildingType::VikingBrewKeeper_T1, BuildingType::VikingSacrificeRitual_T3};
            else if (faction == FactionZone::Samurai)
                results = {BuildingType::SamuraiHospital_T1, BuildingType::SamuraiTeaDry_T1, BuildingType::SamuraiChapel_T3};
            break;
    }

    std::vector<BuildingType> filtered;
    for (BuildingType bt : results) {
        const BuildingData* data = GetBuildingData(bt);
        if (data && data->Tier <= maxTier)
            filtered.push_back(bt);
    }
    return filtered;
}

#endif //TOTALWAR2D_BUILDINGS_H