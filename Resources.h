/*
Script to get all the resources that the buildings produces.
*/
#pragma once
#ifndef TOTALBATTLE2D_RESOURCES_H
#define TOTALBATTLE2D_RESOURCES_H

#include <string>
#include <unordered_map>
#include <vector>

//Types of Resources
enum class ResourceType {
    //Raw
    Fish,
    Iron,
    Gold,
    Copper,
    Silver,
    Tin,
    Lumber,
    //Transformed
    FishOil,
    HardWood,
    Tools,
    CopperJewlery,
    TinTransfored,
    SilverCoins,//(Silver) increase trade Resources value
    GoldJewlery,
};

//If Raw or Transformed Goods
enum class ResourceCategory{
    Raw,
    Transformed
};

//Data of Resources
struct ResourceData{
    std::string name;
    std::string description;
    std::string iconPath;
    ResourceCategory goodsCategory;
    int ResourceValue;
};
/*
 *The value of a Transformed Resource will be 5x the base price.
 * 5 Raw materials to make 1 Transformed one
 */

inline const std::unordered_map<ResourceType, ResourceData>& GetResourceDatabase() {
    static const std::unordered_map<ResourceType, ResourceData> database = {
        //Raw
        { ResourceType::Fish, { "Fish", "Caught by fishing ports. Feeds the population and can be traded.", "assets/Resources/Fish.png", ResourceCategory::Raw, 5}},
        { ResourceType::Iron, { "Iron", "From iron mines. Good to produce tools in the forge or traded.", "assets/Resources/Iron.png", ResourceCategory::Raw, 10}},
        { ResourceType::Gold, { "Gold", "From gold mines. These are the most valuables goods to craft Jewelley.", "assets/Resources/Gold.png", ResourceCategory::Raw, 25}},
        { ResourceType::Copper, { "Copper", "From copper mines. Valuable to make Copper Jewelley.", "assets/Resources/Copper.png", ResourceCategory::Raw, 12}},
        { ResourceType::Silver, { "Silver", "From silver mines. Silver is always usefull to create those coins.", "assets/Resources/Silver.png", ResourceCategory::Raw, 20}},
        { ResourceType::Tin, { "Tin", "From tin mines. Tin is used to make tin coins.", "assets/Resources/Tin.png", ResourceCategory::Raw, 16}},
        { ResourceType::Lumber, { "Lumber", "Lumber, from the forest is very important to build fournitures.", "assets/Resources/Lumber.png", ResourceCategory::Raw, 8}},
        //Transformed
        { ResourceType::FishOil, { "Fish Oil", "Every parts of the fish can be used.", "assets/Resources/FishOil.png", ResourceCategory::Transformed, 25}},
        { ResourceType::HardWood, { "Hard Wood", "Transformed wood is perfect to build houses and fournitures.", "assets/Resources/HardWood.png", ResourceCategory::Transformed, 40}},
        { ResourceType::Tools, { "Tools", "No Kingdom can thrive without tools, what makes it so valuable.", "assets/Resources/Tools.png", ResourceCategory::Transformed, 50}},
        { ResourceType::CopperJewlery, {"Copper Jewlery", "Copper is pretty and cheap at the same time. Available for all.", "assets/Resources/CopperJewlery.png", ResourceCategory::Transformed, 60}},
        { ResourceType::TinTransfored, {"Tin Transformed", "Tin is Tin.", "assets/Resources/TinTransfored.png", ResourceCategory::Transformed, 80}},
        { ResourceType::SilverCoins, { "Silver Coins", "Making your own coins with your face on it shows trade strenght.", "assets/Resources/SilverCoins.png", ResourceCategory::Transformed, 100}},
        { ResourceType::GoldJewlery, { "Gold Jewlery", "The most expensive material is for nobility.", "assets/Resources/GoldJewlery.png", ResourceCategory::Transformed, 125}}

    };
    return database;
}

inline const ResourceData* GetResourceData(ResourceType type) {
    const auto& db = GetResourceDatabase();
    auto it = db.find(type);
    return (it != db.end()) ? &it->second : nullptr;
}

// this building produces/consumes Number of this resource per turn
struct ResourceAmount {
    ResourceType type;
    int amount;
};

#endif //TOTALBATTLE2D_RESOURCES_H
