//
// Created by Louis-Philippe on 8/24/2026.
//

#include "AiBehaviour.h"

void AiBehaviour::RegisterFaction(FactionZone faction, int startingGold) {
    AiFactionState state;
    state.currentGold = startingGold;
    factionStates[faction] = state;
}

AiFactionState* AiBehaviour::GetState(FactionZone faction) {
    auto it = factionStates.find(faction);
    return (it != factionStates.end()) ? &it->second : nullptr;
}