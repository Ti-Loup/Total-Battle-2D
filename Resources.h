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
    Fish,
    Iron,
    Gold,
    Copper,
    Silver,
    Tin,
    Lumber
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

inline const std::unordered_map<ResourceType, ResourceData>& GetResourceDatabase() {
    static const std::unordered_map<ResourceType, ResourceData> database = {
        
        { ResourceType::Fish, { "Fish", "Caught by fishing ports. Feeds the population and can be traded.", "assets/Resources/Fish.png", ResourceCategory::Raw, 5}},
        { ResourceType::Iron, { "Iron", "From iron mines. Good to produce tools in the forge or traded.", "assets/Resources/Iron.png", ResourceCategory::Raw, 10}},
        { ResourceType::Gold, { "Gold", "From gold mines. These are the most valuables goods to craft Jewelley.", "assets/Resources/Gold.png", ResourceCategory::Raw, 25}},
        { ResourceType::Copper, { "Copper", "From copper mines. Valuable to make Copper Jewelley.", "assets/Resources/Copper.png", ResourceCategory::Raw, 12}},
        { ResourceType::Silver, { "Silver", "From silver mines. Silver is always usefull to create those coins.", "assets/Resources/Silver.png", ResourceCategory::Raw, 20}},
        { ResourceType::Tin, { "Tin", "From tin mines. Tin is used to make tin coins.", "assets/Resources/Tin.png", ResourceCategory::Raw, 16}},
        { ResourceType::Lumber, { "Lumber", "Lumber, from the forest is very important to build fournitures.", "assets/Resources/Lumber.png", ResourceCategory::Raw, 8}}
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
