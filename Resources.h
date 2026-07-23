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
    Fish
};

//Data of Resources
struct ResourceData{
    std::string name;
    std::string description;
    int buildingStorage; //how much one building can store that resource
    std::string iconPath;
};

inline const std::unordered_map<ResourceType, ResourceData>& GetResourceDatabase() {
    static const std::unordered_map<ResourceType, ResourceData> database = {
        { ResourceType::Fish, { "Fish", "Caught by fishing ports. Feeds the population and can be traded.", 25, "assets/Resources/Fish.png" } }

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
