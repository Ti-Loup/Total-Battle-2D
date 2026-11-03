//
// Created by Louis-Philippe on 11/2/2026.
//
#ifndef TOTALBATTLE2D_TEXTURELOADER_H
#define TOTALBATTLE2D_TEXTURELOADER_H

// Destroys a texture and nulls the pointer
inline void DestroyTex(SDL_Texture*& t) {
    if (t) {
        SDL_DestroyTexture(t);
        t = nullptr;
    }
}
//LoadTextures
inline SDL_Texture* GameApp::LoadTex(const char* path) {
    SDL_Texture* t = IMG_LoadTexture(renderer, path);
    if (!t) {
        SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION,
                    "failed to load %s: %s", path, SDL_GetError());
        return nullptr;
    }
    SDL_SetTextureScaleMode(t, SDL_SCALEMODE_NEAREST);
    return t;
}

inline void GameApp::LoadTextures() {
//Texture Next Turn
        gameNextTurnTexture = IMG_LoadTexture(renderer, "assets/NextTurnTexture.png");
        if (gameNextTurnTexture == nullptr) {
            SDL_LogWarn(0,"failed to load the texture of gameNextTurnTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameNextTurnTexture, SDL_SCALEMODE_NEAREST);
        //Textures to show the Seasons Icon
        gameSeasonWinterIconUiTexture = IMG_LoadTexture(renderer, "assets/SeasonWinterIcon.png");
        if (gameSeasonWinterIconUiTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture of gameSeasonWinterIconUiTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameSeasonWinterIconUiTexture, SDL_SCALEMODE_NEAREST);
        gameSeasonSpringIconUiTexture = IMG_LoadTexture(renderer, "assets/SeasonSpringIcon.png");
        if (gameSeasonSpringIconUiTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture of gameSeasonSpringIconUiTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameSeasonSpringIconUiTexture, SDL_SCALEMODE_NEAREST);
        gameSeasonSummerIconUiTexture = IMG_LoadTexture(renderer, "assets/SeasonSummerIcon.png");
        if (gameSeasonSummerIconUiTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture of gameSeasonSummerIconUiTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameSeasonSummerIconUiTexture, SDL_SCALEMODE_NEAREST);
        gameSeasonAutumnIconUiTexture = IMG_LoadTexture(renderer, "assets/SeasonAutumnIcon.png");
        if (gameSeasonAutumnIconUiTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture of gameSeasonAutumnIconUiTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameSeasonAutumnIconUiTexture, SDL_SCALEMODE_NEAREST);
        //Destroy and repair building icon UI
        gameDestroyBuildingButtonIconUi = IMG_LoadTexture(renderer, "assets/DestroyBuildingIcon.png");
        if (gameDestroyBuildingButtonIconUi == nullptr) {
            SDL_LogWarn(0, "failed to load texture of gameDestroyBuildingButtonIconUi", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameDestroyBuildingButtonIconUi, SDL_SCALEMODE_NEAREST);
        gameRepairBuildingButtonIconUi = IMG_LoadTexture(renderer, "assets/RepairBuildingIcon.png");
        if (gameRepairBuildingButtonIconUi == nullptr) {
            SDL_LogWarn(0, "failed to load texture of gameRepairBuildingButtonIconUi", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameRepairBuildingButtonIconUi, SDL_SCALEMODE_NEAREST);
        //Texture repair Buildings
        gameBuildingDamagedIconUi = IMG_LoadTexture(renderer, "assets/BuildingDamagedIcon.png");
        if (gameBuildingDamagedIconUi == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameBuildingDamagedIconUi", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingDamagedIconUi, SDL_SCALEMODE_NEAREST);


        //texture Province dezoom texture
        provinceKnightBannerTexture = IMG_LoadTexture(renderer, "assets/KnightProvinceTexture.png");
        if (provinceKnightBannerTexture == nullptr) {
            SDL_LogWarn (0,"failed to load the texture of provinceKnightBannerTexture");
        }
        provinceSamuraiBannerTexture = IMG_LoadTexture(renderer, "assets/SamuraiProvinceTexture.png");
        if (provinceSamuraiBannerTexture == nullptr) {
            SDL_LogWarn(0,"failed to load the provinceSamuraiBannerTexture");
        }
        provinceVikingBannerTexture = IMG_LoadTexture(renderer, "assets/VikingProvinceTexture.png");
        if (provinceVikingBannerTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture provinceVikingBannerTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(provinceVikingBannerTexture, SDL_SCALEMODE_NEAREST);
        SDL_SetTextureScaleMode(provinceKnightBannerTexture, SDL_SCALEMODE_NEAREST);
        SDL_SetTextureScaleMode(provinceSamuraiBannerTexture, SDL_SCALEMODE_NEAREST);
        //Textures settlements banner icon faction
        settlementKnightBannerTexture = IMG_LoadTexture(renderer, "assets/SettlementKnightBanner.png");
        if (settlementKnightBannerTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture settlementKnightBannerTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementKnightBannerTexture, SDL_SCALEMODE_NEAREST);
        settlementVikingBannerTexture = IMG_LoadTexture(renderer, "assets/SettlementVikingBanner.png");
        if (settlementVikingBannerTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture settlementVikingBannerTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementVikingBannerTexture, SDL_SCALEMODE_NEAREST);
        settlementSamuraiBannerTexture = IMG_LoadTexture(renderer, "assets/SettlementSamuraiBanner.png");
        if (settlementSamuraiBannerTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture settlementSamuraiBannerTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementSamuraiBannerTexture, SDL_SCALEMODE_NEAREST);
        //Texture Bouton UI Province
        provinceTextureUIBuilding = IMG_LoadTexture(renderer, "assets/BuildingUILogo.png");
        if (provinceTextureUIBuilding == nullptr) {
            SDL_LogWarn(0,"failed to load the texture of provinceTextureUIBuilding", SDL_GetError());
        }
        provinceTextureUIGarrison = IMG_LoadTexture(renderer, "assets/GarrisonUILogo.png");
        if (provinceTextureUIGarrison == nullptr) {
            SDL_LogWarn(0,"failed to load the texture of provinceTextureUIGarrison", SDL_GetError());
        }
        SDL_SetTextureScaleMode(provinceTextureUIBuilding, SDL_SCALEMODE_NEAREST);
        SDL_SetTextureScaleMode(provinceTextureUIGarrison, SDL_SCALEMODE_NEAREST);
        //Texture Positive and negative Icon On top of other textures
        gamePositiveUiIcon = IMG_LoadTexture(renderer, "assets/PositiveUiLogo.png");
        if (gamePositiveUiIcon == nullptr) {
            SDL_LogWarn(0, "failed to load texture of gamePositiveUiIcon", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gamePositiveUiIcon, SDL_SCALEMODE_NEAREST);
        gameNegativeUiIcon = IMG_LoadTexture(renderer, "assets/NegativeUiLogo.png");
        if (gamePositiveUiIcon == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameNegativeUiIcon", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameNegativeUiIcon, SDL_SCALEMODE_NEAREST);
        //Texture Food Storage Ui
        gameFoodStorageUiIcon = IMG_LoadTexture(renderer, "assets/FoodStorageUiLogo.png");
        if (gameFoodStorageUiIcon == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameStorageUiIcon", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameFoodStorageUiIcon, SDL_SCALEMODE_NEAREST);
        //Texture Goods Storage Ui
        gameGoodsStorageUiIcon = IMG_LoadTexture(renderer, "assets/GoodsStorageUiLogo.png");
        if (gameGoodsStorageUiIcon == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameGoodsStorageUiIcon", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameGoodsStorageUiIcon, SDL_SCALEMODE_NEAREST);
        //Texture construction Hammer
        hammerUIBuildingUpgradeTexture = IMG_LoadTexture(renderer, "assets/UIHammer.png");
        if (hammerUIBuildingUpgradeTexture == nullptr) {
            SDL_LogWarn(0,"failed to load the texture of hammerUIBuildingUpgradeTexture",SDL_GetError());
        }
        SDL_SetTextureScaleMode(hammerUIBuildingUpgradeTexture, SDL_SCALEMODE_NEAREST);

        //Texture Coin + Turn amount
        gameCoinMoneyTexture = IMG_LoadTexture(renderer, "assets/CoinsTexture.png");
        if (gameCoinMoneyTexture == nullptr) {
            SDL_LogWarn(0,"failed to load the texture gameCoinMoneyTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameCoinMoneyTexture, SDL_SCALEMODE_NEAREST);

        gameTurnAmountTexture = IMG_LoadTexture(renderer, "assets/TurnAmountTexture.png");
        if (gameTurnAmountTexture == nullptr) {
            SDL_LogWarn(0,"failed to load texture gameTurnAmountTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameTurnAmountTexture, SDL_SCALEMODE_NEAREST);

        //Texture Food UI
        gameFoodIconUi = IMG_LoadTexture(renderer, "assets/FoodIcon.png");
        if (gameFoodIconUi == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameFoodIconUi", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameFoodIconUi, SDL_SCALEMODE_NEAREST);
        //Texture Growth UI
        gamePeasantryIconUi = IMG_LoadTexture(renderer, "assets/PeasantryIcon.png");
        if (gamePeasantryIconUi == nullptr) {
            SDL_LogWarn(0, "failed to load texture gamePeasantryIconUi", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gamePeasantryIconUi, SDL_SCALEMODE_NEAREST);
        gameNobilityIconUi = IMG_LoadTexture(renderer, "assets/NobilityIcon.png");
        if (gameNobilityIconUi == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameNobilityIconUi", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameNobilityIconUi, SDL_SCALEMODE_NEAREST);
        gameClergyIconUi = IMG_LoadTexture(renderer, "assets/ClergyIcon.png");
        if (gameClergyIconUi == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameClergyIconUi", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameClergyIconUi, SDL_SCALEMODE_NEAREST);

        //Texture toggle tax settlements
        gameToggleTaxSettlementTrue = IMG_LoadTexture(renderer, "assets/toggleTaxSettlementTrue.png");
        if (gameToggleTaxSettlementTrue == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameToggleTaxSettlementTrue", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameToggleTaxSettlementTrue, SDL_SCALEMODE_NEAREST );
        gameToggleTaxSettlementFalse = IMG_LoadTexture(renderer, "assets/toggleTaxSettlementFalse.png");
        if (gameToggleTaxSettlementFalse == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameToggleTaxSettlementFalse", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameToggleTaxSettlementFalse, SDL_SCALEMODE_NEAREST);

        //Texture Public order
        gamePublicOrderPositifTexture = IMG_LoadTexture(renderer, "assets/HappyPublicOrderIcon.png");
        if (gamePublicOrderPositifTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gamePublicOrderPositifTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gamePublicOrderPositifTexture, SDL_SCALEMODE_NEAREST);
        gamePublicOrderNeutralTexture = IMG_LoadTexture(renderer, "assets/NeutralPublicOrderIcon.png");
        if (gamePublicOrderNeutralTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gamePublicOrderNeutralTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gamePublicOrderNeutralTexture, SDL_SCALEMODE_NEAREST);
        gamePublicOrderNegatifTexture = IMG_LoadTexture(renderer, "assets/AngryPublicOrderIcon.png");
        if (gamePublicOrderNegatifTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gamePublicOrderNegatifTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gamePublicOrderNegatifTexture, SDL_SCALEMODE_NEAREST);
        //Texture Population Growth
        gamePopulationGrowth = IMG_LoadTexture(renderer, "assets/PopulationGrowthIcon.png");
        if (gamePopulationGrowth == nullptr) {
            SDL_LogWarn(0, "failed to load texture gamePopulationGrowth", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gamePopulationGrowth, SDL_SCALEMODE_NEAREST);

        //Textures Buttons UI
        decreesPannelTexture = IMG_LoadTexture(renderer, "assets/DecreesPannel.png");
        if (decreesPannelTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture decreesPannelTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(decreesPannelTexture, SDL_SCALEMODE_NEAREST);
        winConditionPannelTexture = IMG_LoadTexture(renderer, "assets/WinConditionPannel.png");
        if (winConditionPannelTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture winConditionPannelTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(winConditionPannelTexture, SDL_SCALEMODE_NEAREST);
        treasuryPannelTexture = IMG_LoadTexture(renderer, "assets/TreasuryPannel.png");
        if (treasuryPannelTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture treasuryPannelTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(treasuryPannelTexture, SDL_SCALEMODE_NEAREST);
        diplomacyPannelTexture = IMG_LoadTexture(renderer, "assets/DiplomacyPannel.png");
        if (diplomacyPannelTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture diploacyPannelTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(diplomacyPannelTexture, SDL_SCALEMODE_NEAREST);
        technologyPannelTexture = IMG_LoadTexture(renderer, "assets/TechnologyPannel.png");
        if (technologyPannelTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture technologyPannelTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(technologyPannelTexture, SDL_SCALEMODE_NEAREST);
        familyHierarchyPannelTexture = IMG_LoadTexture(renderer, "assets/FamilyHierarchyPannel.png");
        if (familyHierarchyPannelTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture familyHierarchyPannelTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(familyHierarchyPannelTexture, SDL_SCALEMODE_NEAREST);
        cameraResetPannelTexture = IMG_LoadTexture(renderer, "assets/CameraResetPannel.png");
        if (cameraResetPannelTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture cameraResetPannelTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(cameraResetPannelTexture, SDL_SCALEMODE_NEAREST);

        // Win Conditions Icons
        gameWinConditionConquestShortIconTexture = IMG_LoadTexture(renderer, "assets/WinConditions/ConquestShort.png");
        if (gameWinConditionConquestShortIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameWinConditionConquestShortIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameWinConditionConquestShortIconTexture, SDL_SCALEMODE_NEAREST);

        gameWinConditionConquestLongIconTexture = IMG_LoadTexture(renderer, "assets/WinConditions/ConquestLong.png");
        if (gameWinConditionConquestLongIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameWinConditionConquestLongIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameWinConditionConquestLongIconTexture, SDL_SCALEMODE_NEAREST);

        gameWinConditionConstructionShortIconTexture = IMG_LoadTexture(renderer, "assets/WinConditions/ConstructionShort.png");
        if (gameWinConditionConstructionShortIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameWinConditionConstructionShortIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameWinConditionConstructionShortIconTexture, SDL_SCALEMODE_NEAREST);

        gameWinConditionConstructionLongIconTexture = IMG_LoadTexture(renderer, "assets/WinConditions/ConstructionLong.png");
        if (gameWinConditionConstructionLongIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameWinConditionConstructionLongIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameWinConditionConstructionLongIconTexture, SDL_SCALEMODE_NEAREST);

        gameWinConditionTradeShortIconTexture = IMG_LoadTexture(renderer, "assets/WinConditions/TradeShort.png");
        if (gameWinConditionTradeShortIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameWinConditionTradeShortIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameWinConditionTradeShortIconTexture, SDL_SCALEMODE_NEAREST);

        gameWinConditionTradeLongIconTexture = IMG_LoadTexture(renderer, "assets/WinConditions/TradeLong.png");
        if (gameWinConditionTradeLongIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameWinConditionTradeLongIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameWinConditionTradeLongIconTexture, SDL_SCALEMODE_NEAREST);

        gameWinConditionUltimateIconTexture = IMG_LoadTexture(renderer, "assets/WinConditions/Ultimate.png");
        if (gameWinConditionUltimateIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameWinConditionUltimateIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameWinConditionUltimateIconTexture, SDL_SCALEMODE_NEAREST);
        //Treasury Info Textures
        gameTreasuryChestIconTexture = IMG_LoadTexture(renderer, "assets/TreasuryChest.png");
        if (gameTreasuryChestIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to laod texture gameTreasuryChestIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameTreasuryChestIconTexture, SDL_SCALEMODE_NEAREST);



        //SETTLEMENTS EVOLUTIF IN CAMPAIGN FOR EACH FACTION
        /*
         *Castle and capital Tier 1 no wall, Tier 2 wood wall, Tier 3 Stone wall, Tier 4 Better wall, Tier 5 2 layout of walls.
         *
         */
        //                              ~ KNIGHT ~
        // Capital -> 5 tiers Upgrade
        settlementTextureCampaign[{FactionZone::Knight, SettlementType::Capital, 1}] = IMG_LoadTexture(renderer, "assets/Knight/Settlement/CapitalKnight_T1.png");
        if (settlementTextureCampaign[{FactionZone::Knight, SettlementType::Capital, 1}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Knight, Capital, Tier1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Knight, SettlementType::Capital,1}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Knight, SettlementType::Capital, 2}] = IMG_LoadTexture(renderer, "assets/Knight/Settlement/CapitalKnight_T2.png");
        if (settlementTextureCampaign[{FactionZone::Knight, SettlementType::Capital, 2}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Knight, Capital, Tier2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Knight, SettlementType::Capital,2}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Knight, SettlementType::Capital, 3}] = IMG_LoadTexture(renderer, "assets/Knight/Settlement/CapitalKnight_T3.png");
        if (settlementTextureCampaign[{FactionZone::Knight, SettlementType::Capital, 3}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Knight, Capital, Tier3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Knight, SettlementType::Capital,3}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Knight, SettlementType::Capital, 4}] = IMG_LoadTexture(renderer, "assets/Knight/Settlement/CapitalKnight_T4.png");
        if (settlementTextureCampaign[{FactionZone::Knight, SettlementType::Capital, 4}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Knight, Capital, Tier4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Knight, SettlementType::Capital,4}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Knight, SettlementType::Capital, 5}] = IMG_LoadTexture(renderer, "assets/Knight/Settlement/CapitalKnight_T5.png");
        if (settlementTextureCampaign[{FactionZone::Knight, SettlementType::Capital, 5}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Knight, Capital, Tier5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Knight, SettlementType::Capital,5}], SDL_SCALEMODE_NEAREST);
        // Castles -> 5 tiers Upgrade
        settlementTextureCampaign[{FactionZone::Knight, SettlementType::Castle, 1}] = IMG_LoadTexture(renderer, "assets/Knight/Settlement/CastleKnight_T1.png");
        if (settlementTextureCampaign[{FactionZone::Knight, SettlementType::Castle, 1}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Knight, Castle, Tier1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Knight, SettlementType::Castle,1}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Knight, SettlementType::Castle, 2}] = IMG_LoadTexture(renderer, "assets/Knight/Settlement/CastleKnight_T2.png");
        if (settlementTextureCampaign[{FactionZone::Knight, SettlementType::Castle, 2}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Knight, Castle, Tier2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Knight, SettlementType::Castle,2}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Knight, SettlementType::Castle, 3}] = IMG_LoadTexture(renderer, "assets/Knight/Settlement/CastleKnight_T3.png");
        if (settlementTextureCampaign[{FactionZone::Knight, SettlementType::Castle, 3}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Knight, Castle, Tier3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Knight, SettlementType::Castle,3}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Knight, SettlementType::Castle, 4}] = IMG_LoadTexture(renderer, "assets/Knight/Settlement/CastleKnight_T4.png");
        if (settlementTextureCampaign[{FactionZone::Knight, SettlementType::Castle, 4}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Knight, Castle, Tier4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Knight, SettlementType::Castle,4}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Knight, SettlementType::Castle, 5}] = IMG_LoadTexture(renderer, "assets/Knight/Settlement/CastleKnight_T5.png");
        if (settlementTextureCampaign[{FactionZone::Knight, SettlementType::Castle, 5}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Knight, Castle, Tier5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Knight, SettlementType::Castle,5}], SDL_SCALEMODE_NEAREST);
        // Villages -> 3 tiers Upgrade
        settlementTextureCampaign[{FactionZone::Knight, SettlementType::Village, 1}] = IMG_LoadTexture(renderer, "assets/Knight/Settlement/VillageKnight_T1.png");
        if (settlementTextureCampaign[{FactionZone::Knight, SettlementType::Village, 1}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Knight, Village, Tier1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Knight, SettlementType::Village,1}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Knight, SettlementType::Village, 2}] = IMG_LoadTexture(renderer, "assets/Knight/Settlement/VillageKnight_T2.png");
        if (settlementTextureCampaign[{FactionZone::Knight, SettlementType::Village, 2}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Knight, Village, Tier2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Knight, SettlementType::Village,2}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Knight, SettlementType::Village, 3}] = IMG_LoadTexture(renderer, "assets/Knight/Settlement/VillageKnight_T3.png");
        if (settlementTextureCampaign[{FactionZone::Knight, SettlementType::Village, 3}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Knight, Village, Tier3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Knight, SettlementType::Village,3}], SDL_SCALEMODE_NEAREST);
        //                               ~ VIKING ~
        // Capital -> 5 tiers Upgrade
        settlementTextureCampaign[{FactionZone::Viking, SettlementType::Capital, 1}] = IMG_LoadTexture(renderer, "assets/Viking/Settlement/CapitalViking_T1.png");
        if (settlementTextureCampaign[{FactionZone::Viking, SettlementType::Capital, 1}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Viking, Capital, Tier1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Viking, SettlementType::Capital,1}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Viking, SettlementType::Capital, 2}] = IMG_LoadTexture(renderer, "assets/Viking/Settlement/CapitalViking_T2.png");
        if (settlementTextureCampaign[{FactionZone::Viking, SettlementType::Capital, 2}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Viking, Capital, Tier2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Viking, SettlementType::Capital,2}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Viking, SettlementType::Capital, 3}] = IMG_LoadTexture(renderer, "assets/Viking/Settlement/CapitalViking_T3.png");
        if (settlementTextureCampaign[{FactionZone::Viking, SettlementType::Capital, 3}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Viking, Capital, Tier3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Viking, SettlementType::Capital,3}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Viking, SettlementType::Capital, 4}] = IMG_LoadTexture(renderer, "assets/Viking/Settlement/CapitalViking_T4.png");
        if (settlementTextureCampaign[{FactionZone::Viking, SettlementType::Capital, 4}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Viking, Capital, Tier4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Viking, SettlementType::Capital,4}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Viking, SettlementType::Capital, 5}] = IMG_LoadTexture(renderer, "assets/Viking/Settlement/CapitalViking_T5.png");
        if (settlementTextureCampaign[{FactionZone::Viking, SettlementType::Capital, 5}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Viking, Capital, Tier5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Viking, SettlementType::Capital,5}], SDL_SCALEMODE_NEAREST);
        // Castles -> 5 tiers Upgrade
        settlementTextureCampaign[{FactionZone::Viking, SettlementType::Castle, 1}] = IMG_LoadTexture(renderer, "assets/Viking/Settlement/CastleViking_T1.png");
        if (settlementTextureCampaign[{FactionZone::Viking, SettlementType::Castle, 1}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Viking, Castle, Tier1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Viking, SettlementType::Castle,1}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Viking, SettlementType::Castle, 2}] = IMG_LoadTexture(renderer, "assets/Viking/Settlement/CastleViking_T2.png");
        if (settlementTextureCampaign[{FactionZone::Viking, SettlementType::Castle, 2}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Viking, Castle, Tier2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Viking, SettlementType::Castle,2}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Viking, SettlementType::Castle, 3}] = IMG_LoadTexture(renderer, "assets/Viking/Settlement/CastleViking_T3.png");
        if (settlementTextureCampaign[{FactionZone::Viking, SettlementType::Castle, 3}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Viking, Castle, Tier3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Viking, SettlementType::Castle,3}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Viking, SettlementType::Castle, 4}] = IMG_LoadTexture(renderer, "assets/Viking/Settlement/CastleViking_T4.png");
        if (settlementTextureCampaign[{FactionZone::Viking, SettlementType::Castle, 4}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Viking, Castle, Tier4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Viking, SettlementType::Castle,4}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Viking, SettlementType::Castle, 5}] = IMG_LoadTexture(renderer, "assets/Viking/Settlement/CastleViking_T5.png");
        if (settlementTextureCampaign[{FactionZone::Viking, SettlementType::Castle, 5}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Viking, Castle, Tier5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Viking, SettlementType::Castle,5}], SDL_SCALEMODE_NEAREST);
        // Villages -> 3 tiers Upgrade
        settlementTextureCampaign[{FactionZone::Viking, SettlementType::Village, 1}] = IMG_LoadTexture(renderer, "assets/Viking/Settlement/VillageViking_T1.png");
        if (settlementTextureCampaign[{FactionZone::Viking, SettlementType::Village, 1}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Viking, Village, Tier1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Viking, SettlementType::Village,1}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Viking, SettlementType::Village, 2}] = IMG_LoadTexture(renderer, "assets/Viking/Settlement/VillageViking_T2.png");
        if (settlementTextureCampaign[{FactionZone::Viking, SettlementType::Village, 2}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Viking, Village, Tier2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Viking, SettlementType::Village,2}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Viking, SettlementType::Village, 3}] = IMG_LoadTexture(renderer, "assets/Viking/Settlement/VillageViking_T3.png");
        if (settlementTextureCampaign[{FactionZone::Viking, SettlementType::Village, 3}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Viking, Village, Tier3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Viking, SettlementType::Village,3}], SDL_SCALEMODE_NEAREST);

        // ~ SAMURAI ~
        // Capital -> 5 tiers Upgrade
        settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Capital, 1}] = IMG_LoadTexture(renderer, "assets/Samurai/Settlement/CapitalSamurai_T1.png");
        if (settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Capital, 1}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Samurai, Capital, Tier1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Capital,1}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Capital, 2}] = IMG_LoadTexture(renderer, "assets/Samurai/Settlement/CapitalSamurai_T2.png");
        if (settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Capital, 2}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Samurai, Capital, Tier2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Capital,2}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Capital, 3}] = IMG_LoadTexture(renderer, "assets/Samurai/Settlement/CapitalSamurai_T3.png");
        if (settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Capital, 3}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Samurai, Capital, Tier3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Capital,3}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Capital, 4}] = IMG_LoadTexture(renderer, "assets/Samurai/Settlement/CapitalSamurai_T4.png");
        if (settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Capital, 4}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Samurai, Capital, Tier4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Capital,4}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Capital, 5}] = IMG_LoadTexture(renderer, "assets/Samurai/Settlement/CapitalSamurai_T5.png");
        if (settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Capital, 5}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Samurai, Capital, Tier5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Capital,5}], SDL_SCALEMODE_NEAREST);
        // Castles -> 5 tiers Upgrade
        settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Castle, 1}] = IMG_LoadTexture(renderer, "assets/Samurai/Settlement/CastleSamurai_T1.png");
        if (settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Castle, 1}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Samurai, Castle, Tier1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Castle,1}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Castle, 2}] = IMG_LoadTexture(renderer, "assets/Samurai/Settlement/CastleSamurai_T2.png");
        if (settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Castle, 2}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Samurai, Castle, Tier2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Castle,2}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Castle, 3}] = IMG_LoadTexture(renderer, "assets/Samurai/Settlement/CastleSamurai_T3.png");
        if (settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Castle, 3}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Samurai, Castle, Tier3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Castle,3}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Castle, 4}] = IMG_LoadTexture(renderer, "assets/Samurai/Settlement/CastleSamurai_T4.png");
        if (settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Castle, 4}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Samurai, Castle, Tier4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Castle,4}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Castle, 5}] = IMG_LoadTexture(renderer, "assets/Samurai/Settlement/CastleSamurai_T5.png");
        if (settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Castle, 5}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Samurai, Castle, Tier5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Castle,5}], SDL_SCALEMODE_NEAREST);
        // Villages -> 3 tiers Upgrade
        settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Village, 1}] = IMG_LoadTexture(renderer, "assets/Samurai/Settlement/VillageSamurai_T1.png");
        if (settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Village, 1}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Samurai, Village, Tier1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Village,1}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Village, 2}] = IMG_LoadTexture(renderer, "assets/Samurai/Settlement/VillageSamurai_T2.png");
        if (settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Village, 2}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Samurai, Village, Tier2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Village,2}], SDL_SCALEMODE_NEAREST);
        settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Village, 3}] = IMG_LoadTexture(renderer, "assets/Samurai/Settlement/VillageSamurai_T3.png");
        if (settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Village, 3}] == nullptr) {
            SDL_LogWarn(0,"failed to load texture settlementTextureCampaign ->Samurai, Village, Tier3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(settlementTextureCampaign[{FactionZone::Samurai, SettlementType::Village,3}], SDL_SCALEMODE_NEAREST);

        //Textures World Events Images UI
        //World Events Textures
        worldEventsImageTextures[WorldEventsType::Storm] = IMG_LoadTexture(renderer, "assets/WorldEvents/Storm.png");
        if (worldEventsImageTextures[WorldEventsType::Storm] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsImageTextures Storm", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsImageTextures[WorldEventsType::Storm], SDL_SCALEMODE_NEAREST);

        worldEventsImageTextures[WorldEventsType::Earthquake] = IMG_LoadTexture(renderer, "assets/WorldEvents/Earthquake.png");
        if (worldEventsImageTextures[WorldEventsType::Earthquake] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsImageTextures Earthquake", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsImageTextures[WorldEventsType::Earthquake], SDL_SCALEMODE_NEAREST);

        worldEventsImageTextures[WorldEventsType::Drought] = IMG_LoadTexture(renderer, "assets/WorldEvents/Drought.png");
        if (worldEventsImageTextures[WorldEventsType::Drought] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsImageTextures Drought", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsImageTextures[WorldEventsType::Drought], SDL_SCALEMODE_NEAREST);

        worldEventsImageTextures[WorldEventsType::Plague] = IMG_LoadTexture(renderer, "assets/WorldEvents/Plague.png");
        if (worldEventsImageTextures[WorldEventsType::Plague] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsImageTextures Plague", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsImageTextures[WorldEventsType::Plague], SDL_SCALEMODE_NEAREST);

        worldEventsImageTextures[WorldEventsType::Fire] = IMG_LoadTexture(renderer, "assets/WorldEvents/Fire.png");
        if (worldEventsImageTextures[WorldEventsType::Fire] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsImageTextures Fire", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsImageTextures[WorldEventsType::Fire], SDL_SCALEMODE_NEAREST);

        worldEventsImageTextures[WorldEventsType::PoorPopulation] = IMG_LoadTexture(renderer, "assets/WorldEvents/PoorPopulation.png");
        if (worldEventsImageTextures[WorldEventsType::PoorPopulation] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsImageTextures PoorPopulation", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsImageTextures[WorldEventsType::PoorPopulation], SDL_SCALEMODE_NEAREST);

        worldEventsImageTextures[WorldEventsType::GoodHarvest] = IMG_LoadTexture(renderer, "assets/WorldEvents/GoodHarvest.png");
        if (worldEventsImageTextures[WorldEventsType::GoodHarvest] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsImageTextures GoodHarvest", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsImageTextures[WorldEventsType::GoodHarvest], SDL_SCALEMODE_NEAREST);

        worldEventsImageTextures[WorldEventsType::MiraculousFishCatch] = IMG_LoadTexture(renderer, "assets/WorldEvents/MiraculousFishCatch.png");
        if (worldEventsImageTextures[WorldEventsType::MiraculousFishCatch] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsImageTextures MiraculousFishCatch", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsImageTextures[WorldEventsType::MiraculousFishCatch], SDL_SCALEMODE_NEAREST);

        worldEventsImageTextures[WorldEventsType::FavorableWinds] = IMG_LoadTexture(renderer, "assets/WorldEvents/FavorableWinds.png");
        if (worldEventsImageTextures[WorldEventsType::FavorableWinds] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsImageTextures FavorableWinds", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsImageTextures[WorldEventsType::FavorableWinds], SDL_SCALEMODE_NEAREST);

        worldEventsImageTextures[WorldEventsType::Justice] = IMG_LoadTexture(renderer, "assets/WorldEvents/Justice.png");
        if (worldEventsImageTextures[WorldEventsType::Justice] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsImageTextures Justice", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsImageTextures[WorldEventsType::Justice], SDL_SCALEMODE_NEAREST);

        worldEventsImageTextures[WorldEventsType::NewInvension] = IMG_LoadTexture(renderer, "assets/WorldEvents/NewInvension.png");
        if (worldEventsImageTextures[WorldEventsType::NewInvension] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsImageTextures NewInvension", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsImageTextures[WorldEventsType::NewInvension], SDL_SCALEMODE_NEAREST);

        worldEventsImageTextures[WorldEventsType::WarSign] = IMG_LoadTexture(renderer, "assets/WorldEvents/WarSign.png");
        if (worldEventsImageTextures[WorldEventsType::WarSign] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsImageTextures WarSign", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsImageTextures[WorldEventsType::WarSign], SDL_SCALEMODE_NEAREST);
        //WorldEvents return button
        gameReturnButtons = IMG_LoadTexture(renderer, "assets/WorldEvents/returnButtons.png");
        if (gameReturnButtons == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsReturnButtons", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameReturnButtons, SDL_SCALEMODE_NEAREST);
        //Icon for each World Events
        worldEventsIconTextures[WorldEventsType::Storm] = IMG_LoadTexture(renderer, "assets/WorldEvents/StormIcon.png");
        if (worldEventsIconTextures[WorldEventsType::Storm] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsIconTextures Storm", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsIconTextures[WorldEventsType::Storm], SDL_SCALEMODE_NEAREST);
        worldEventsIconTextures[WorldEventsType::Earthquake] = IMG_LoadTexture(renderer, "assets/WorldEvents/EarthquakeIcon.png");
        if (worldEventsIconTextures[WorldEventsType::Earthquake] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsIconTextures Earthquake", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsIconTextures[WorldEventsType::Earthquake], SDL_SCALEMODE_NEAREST);

        worldEventsIconTextures[WorldEventsType::Drought] = IMG_LoadTexture(renderer, "assets/WorldEvents/DroughtIcon.png");
        if (worldEventsIconTextures[WorldEventsType::Drought] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsIconTextures Drought", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsIconTextures[WorldEventsType::Drought], SDL_SCALEMODE_NEAREST);

        worldEventsIconTextures[WorldEventsType::Plague] = IMG_LoadTexture(renderer, "assets/WorldEvents/PlagueIcon.png");
        if (worldEventsIconTextures[WorldEventsType::Plague] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsIconTextures Plague", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsIconTextures[WorldEventsType::Plague], SDL_SCALEMODE_NEAREST);

        worldEventsIconTextures[WorldEventsType::Fire] = IMG_LoadTexture(renderer, "assets/WorldEvents/FireIcon.png");
        if (worldEventsIconTextures[WorldEventsType::Fire] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsIconTextures Fire", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsIconTextures[WorldEventsType::Fire], SDL_SCALEMODE_NEAREST);

        worldEventsIconTextures[WorldEventsType::PoorPopulation] = IMG_LoadTexture(renderer, "assets/WorldEvents/PoorPopulationIcon.png");
        if (worldEventsIconTextures[WorldEventsType::PoorPopulation] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsIconTextures PoorPopulation", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsIconTextures[WorldEventsType::PoorPopulation], SDL_SCALEMODE_NEAREST);

        worldEventsIconTextures[WorldEventsType::GoodHarvest] = IMG_LoadTexture(renderer, "assets/WorldEvents/GoodHarvestIcon.png");
        if (worldEventsIconTextures[WorldEventsType::GoodHarvest] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsIconTextures GoodHarvest", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsIconTextures[WorldEventsType::GoodHarvest], SDL_SCALEMODE_NEAREST);

        worldEventsIconTextures[WorldEventsType::MiraculousFishCatch] = IMG_LoadTexture(renderer, "assets/WorldEvents/MiraculousFishCatchIcon.png");
        if (worldEventsIconTextures[WorldEventsType::MiraculousFishCatch] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsIconTextures MiraculousFishCatch", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsIconTextures[WorldEventsType::MiraculousFishCatch], SDL_SCALEMODE_NEAREST);

        worldEventsIconTextures[WorldEventsType::FavorableWinds] = IMG_LoadTexture(renderer, "assets/WorldEvents/FavorableWindsIcon.png");
        if (worldEventsIconTextures[WorldEventsType::FavorableWinds] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsIconTextures FavorableWinds", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsIconTextures[WorldEventsType::FavorableWinds], SDL_SCALEMODE_NEAREST);

        worldEventsIconTextures[WorldEventsType::Justice] = IMG_LoadTexture(renderer, "assets/WorldEvents/JusticeIcon.png");
        if (worldEventsIconTextures[WorldEventsType::Justice] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsIconTextures Justice", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsIconTextures[WorldEventsType::Justice], SDL_SCALEMODE_NEAREST);

        worldEventsIconTextures[WorldEventsType::NewInvension] = IMG_LoadTexture(renderer, "assets/WorldEvents/NewInvensionIcon.png");
        if (worldEventsIconTextures[WorldEventsType::NewInvension] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsIconTextures NewInvension", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsIconTextures[WorldEventsType::NewInvension], SDL_SCALEMODE_NEAREST);

        worldEventsIconTextures[WorldEventsType::WarSign] = IMG_LoadTexture(renderer, "assets/WorldEvents/WarSignIcon.png");
        if (worldEventsIconTextures[WorldEventsType::WarSign] == nullptr) {
            SDL_LogWarn(0, "failed to load texture worldEventsIconTextures WarSign", SDL_GetError());
        }
        SDL_SetTextureScaleMode(worldEventsIconTextures[WorldEventsType::WarSign], SDL_SCALEMODE_NEAREST);
        //decree
        gameDecree1KnightTexture = IMG_LoadTexture(renderer, "assets/Decrees/Decree1Knight.png");
        if (gameDecree1KnightTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameDecree1KnightTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameDecree1KnightTexture, SDL_SCALEMODE_NEAREST);
        gameDecree2KnightTexture = IMG_LoadTexture(renderer, "assets/Decrees/Decree2Knight.png");
        if (gameDecree2KnightTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameDecree2KnightTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameDecree2KnightTexture, SDL_SCALEMODE_NEAREST);
        gameDecree3KnightTexture = IMG_LoadTexture(renderer, "assets/Decrees/Decree3Knight.png");
        if (gameDecree3KnightTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameDecree3KnightTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameDecree3KnightTexture, SDL_SCALEMODE_NEAREST);
        gameDecree1VikingTexture = IMG_LoadTexture(renderer, "assets/Decrees/Decree1Viking.png");
        if (gameDecree1VikingTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameDecree1VikingTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameDecree1VikingTexture, SDL_SCALEMODE_NEAREST);
        gameDecree2VikingTexture = IMG_LoadTexture(renderer, "assets/Decrees/Decree2Viking.png");
        if (gameDecree2VikingTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameDecree2VikingTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameDecree2VikingTexture, SDL_SCALEMODE_NEAREST);
        gameDecree3VikingTexture = IMG_LoadTexture(renderer, "assets/Decrees/Decree3Viking.png");
        if (gameDecree3VikingTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameDecree3VikingTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameDecree3VikingTexture, SDL_SCALEMODE_NEAREST);
        gameDecree1SamuraiTexture = IMG_LoadTexture(renderer, "assets/Decrees/Decree1Samurai.png");
        if (gameDecree1SamuraiTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameDecree1SamuraiTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameDecree1SamuraiTexture, SDL_SCALEMODE_NEAREST);
        gameDecree2SamuraiTexture = IMG_LoadTexture(renderer, "assets/Decrees/Decree2Samurai.png");
        if (gameDecree2SamuraiTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameDecree2SamuraiTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameDecree2SamuraiTexture, SDL_SCALEMODE_NEAREST);
        gameDecree3SamuraiTexture = IMG_LoadTexture(renderer, "assets/Decrees/Decree3Samurai.png");
        if (gameDecree3SamuraiTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameDecree3SamuraiTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameDecree3SamuraiTexture, SDL_SCALEMODE_NEAREST);
        //Diplomacy Icons by types
        vassalDiplomacyIconTexture = IMG_LoadTexture(renderer, "assets/VassalDiplomacyIcon.png");
        if (vassalDiplomacyIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture vassalDiplomacyIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(vassalDiplomacyIconTexture, SDL_SCALEMODE_NEAREST);
        tradeDiplomacyIconTexture = IMG_LoadTexture (renderer, "assets/TradeDiplomacyIcon.png");
        if (tradeDiplomacyIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture tradeDiplomacyIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(tradeDiplomacyIconTexture, SDL_SCALEMODE_NEAREST);
        defensiveAllianceDiplomacyIconTexture = IMG_LoadTexture(renderer, "assets/DefensiveAllianceDiplomacyIcon.png");
        if (defensiveAllianceDiplomacyIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture defensiveAllianceDiplomacyIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(defensiveAllianceDiplomacyIconTexture, SDL_SCALEMODE_NEAREST);
        militaryAllianceDiplomacyIconTexture = IMG_LoadTexture (renderer, "assets/MilitaryAllianceDiplomacyIcon.png");
        if (militaryAllianceDiplomacyIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture militaryAllianceDiplomacyIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(militaryAllianceDiplomacyIconTexture, SDL_SCALEMODE_NEAREST);
        warDiplomacyIconTexture = IMG_LoadTexture(renderer, "assets/WarDiplomacyIcon.png");
        if (warDiplomacyIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture warDiplomacyIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(warDiplomacyIconTexture, SDL_SCALEMODE_NEAREST);
        friendshipDiplomacyIconTexture = IMG_LoadTexture(renderer, "assets/FriendshipDiplomacyIcon.png");
        if (friendshipDiplomacyIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture friendshipDiplomacyIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(friendshipDiplomacyIconTexture, SDL_SCALEMODE_NEAREST);

        militaryAccessDiplomacyIconTexture = IMG_LoadTexture(renderer, "assets/MilitaryAccessDiplomacyIcon.png");
        if (militaryAccessDiplomacyIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture militaryAccessDiplomacyIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(militaryAccessDiplomacyIconTexture, SDL_SCALEMODE_NEAREST);
        gameStartDiplomacyTexture = IMG_LoadTexture(renderer, "assets/StartDiplomacyIcon.png");
        if (gameStartDiplomacyTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameStartDiplomacyTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameStartDiplomacyTexture, SDL_SCALEMODE_NEAREST);
        //Offer gifts textures
        smallGiftDiplomacyIconTexture = IMG_LoadTexture(renderer, "assets/SmallGiftIcon.png");
        if (smallGiftDiplomacyIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture smallGiftDiplomacyIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(smallGiftDiplomacyIconTexture, SDL_SCALEMODE_NEAREST);
        mediumGiftDiplomacyIconTexture = IMG_LoadTexture(renderer, "assets/MediumGiftIcon.png");
        if (mediumGiftDiplomacyIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture mediumGiftDiplomacyIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(mediumGiftDiplomacyIconTexture, SDL_SCALEMODE_NEAREST);
        largeGiftDiplomacyIconTexture = IMG_LoadTexture(renderer, "assets/LargeGiftIcon.png");
        if (largeGiftDiplomacyIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture largeGiftDiplomacyIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(largeGiftDiplomacyIconTexture, SDL_SCALEMODE_NEAREST);
        gameGiftSelectedCheckTexture = IMG_LoadTexture(renderer, "assets/GiftSelectedCheck.png");
        if (gameGiftSelectedCheckTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameGiftSelectedCheckTexture", SDL_GetError());
        } else {
            SDL_SetTextureScaleMode(gameGiftSelectedCheckTexture, SDL_SCALEMODE_NEAREST);
        }
        //Demand texture section
        gameDemandMinusArrowTexture = IMG_LoadTexture(renderer, "assets/DemandMoneyMinusArrow.png");
        if (gameDemandMinusArrowTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameDemandMinusArrowTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameDemandMinusArrowTexture, SDL_SCALEMODE_NEAREST);
        gameDemandPlusArrowTexture = IMG_LoadTexture(renderer, "assets/DemandMoneyPlusArrow.png");
        if (gameDemandPlusArrowTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameDemandPlusArrowTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameDemandPlusArrowTexture, SDL_SCALEMODE_NEAREST);

        gameCounterDealTexture = IMG_LoadTexture(renderer, "assets/CounterDealIcon.png");
        if (gameCounterDealTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameCounterDealTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameCounterDealTexture, SDL_SCALEMODE_NEAREST);
        gameMakeDealTexture = IMG_LoadTexture(renderer, "assets/MakeDealIcon.png");
        if (gameMakeDealTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameMakeDealTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameMakeDealTexture, SDL_SCALEMODE_NEAREST);
        gameQuitDealTexture = IMG_LoadTexture(renderer, "assets/QuitDealIcon.png");
        if (gameQuitDealTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameQuitDealTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameQuitDealTexture, SDL_SCALEMODE_NEAREST);

        //Treasury
        gameTreasuryTaxRateIndicatorTexture = IMG_LoadTexture (renderer, "assets/TreasuryTaxRateIndicator.png");
        if (gameTreasuryTaxRateIndicatorTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameTreasuryTaxRateIndicatorTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameTreasuryTaxRateIndicatorTexture, SDL_SCALEMODE_NEAREST);

        // |~ Character portraits ~|
        //baby
        babyCharacterPortraitTexture = IMG_LoadTexture (renderer, "assets/Characters/BabyPortrait.png");
        if (babyCharacterPortraitTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture babyCharacterPortraitTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(babyCharacterPortraitTexture, SDL_SCALEMODE_NEAREST);
        //young
        youngMaleCharacterPortraitTexture = IMG_LoadTexture(renderer, "assets/Characters/YoungMalePortrait.png");
        if (youngMaleCharacterPortraitTexture == nullptr) {
            SDL_LogWarn(0,"failed to load texture youngMaleCharacterPortraitTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(youngMaleCharacterPortraitTexture, SDL_SCALEMODE_NEAREST);
        youngFemaleCharacterPortraitTexture = IMG_LoadTexture(renderer, "assets/Characters/YoungFemalePortrait.png");
        if (youngFemaleCharacterPortraitTexture == nullptr) {
            SDL_LogWarn(0,"failed to load texture youngFemaleCharacterPortraitTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(youngFemaleCharacterPortraitTexture, SDL_SCALEMODE_NEAREST);
        //variants
        //male
        maleVariant1CharacterPortraitTexture = IMG_LoadTexture(renderer, "assets/Characters/MaleVariant1Portrait.png");
        if (maleVariant1CharacterPortraitTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture maleVariant1CharacterPortraitTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(maleVariant1CharacterPortraitTexture, SDL_SCALEMODE_NEAREST);
        maleOldVariant1CharacterPortraitTexture = IMG_LoadTexture(renderer, "assets/Characters/MaleOldVariant1Portrait.png");
        if (maleOldVariant1CharacterPortraitTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture maleOldVariant1CharacterPortraitTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(maleOldVariant1CharacterPortraitTexture, SDL_SCALEMODE_NEAREST);
        maleVariant2CharacterPortraitTexture = IMG_LoadTexture(renderer, "assets/Characters/MaleVariant2Portrait.png");
        if (maleVariant2CharacterPortraitTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture maleVariant2CharacterPortraitTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(maleVariant2CharacterPortraitTexture, SDL_SCALEMODE_NEAREST);
        maleOldVariant2CharacterPortraitTexture = IMG_LoadTexture(renderer, "assets/Characters/MaleOldVariant2Portrait.png");
        if (maleOldVariant2CharacterPortraitTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture maleOldVariant2CharacterPortraitTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(maleOldVariant2CharacterPortraitTexture, SDL_SCALEMODE_NEAREST);
        maleVariant3CharacterPortraitTexture = IMG_LoadTexture(renderer, "assets/Characters/MaleVariant3Portrait.png");
        if (maleVariant3CharacterPortraitTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture maleVariant3CharacterPortraitTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(maleVariant3CharacterPortraitTexture, SDL_SCALEMODE_NEAREST);
        maleOldVariant3CharacterPortraitTexture = IMG_LoadTexture(renderer, "assets/Characters/MaleOldVariant3Portrait.png");
        if (maleOldVariant3CharacterPortraitTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture maleOldVariant3CharacterPortraitTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(maleOldVariant1CharacterPortraitTexture, SDL_SCALEMODE_NEAREST);
        //female
        femaleVariant1CharacterPortraitTexture = IMG_LoadTexture(renderer, "assets/Characters/FemaleVariant1Portrait.png");
        if (femaleVariant1CharacterPortraitTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture femaleVariant1CharacterPortraitTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(femaleVariant1CharacterPortraitTexture, SDL_SCALEMODE_NEAREST);
        femaleOldVariant1CharacterPortraitTexture = IMG_LoadTexture(renderer, "assets/Characters/FemaleOldVariant1Portrait.png");
        if (femaleOldVariant1CharacterPortraitTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture femaleOldVariant1CharacterPortraitTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(femaleOldVariant1CharacterPortraitTexture, SDL_SCALEMODE_NEAREST);
        femaleVariant2CharacterPortraitTexture = IMG_LoadTexture(renderer, "assets/Characters/FemaleVariant2Portrait.png");
        if (femaleVariant2CharacterPortraitTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture femaleVariant2CharacterPortraitTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(femaleVariant2CharacterPortraitTexture, SDL_SCALEMODE_NEAREST);
        femaleOldVariant2CharacterPortraitTexture = IMG_LoadTexture(renderer, "assets/Characters/FemaleOldVariant2Portrait.png");
        if (femaleOldVariant2CharacterPortraitTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture femaleOldVariant2CharacterPortraitTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(femaleOldVariant2CharacterPortraitTexture, SDL_SCALEMODE_NEAREST);
        femaleVariant3CharacterPortraitTexture = IMG_LoadTexture(renderer, "assets/Characters/FemaleVariant3Portrait.png");
        if (femaleVariant3CharacterPortraitTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture femaleVariant3CharacterPortraitTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(femaleVariant3CharacterPortraitTexture, SDL_SCALEMODE_NEAREST);
        femaleOldVariant3CharacterPortraitTexture = IMG_LoadTexture(renderer, "assets/Characters/FemaleOldVariant3Portrait.png");
        if (femaleOldVariant3CharacterPortraitTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture femaleOldVariant3CharacterPortraitTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(femaleOldVariant3CharacterPortraitTexture, SDL_SCALEMODE_NEAREST);

        //TODO: Unique Characters portraits

        // BUILDING UIS
        //                  ! KNIGHT !
        //capitals
        capitalBuildingUpgrade1Knight = IMG_LoadTexture(renderer, "assets/Knight/CapitalBuildingUpgrade1Knight.png");
        if (capitalBuildingUpgrade1Knight == nullptr) {
            SDL_LogWarn(0, "failed to load the texture of capitalBuildingUpgrade1Knight", SDL_GetError());
        }
        SDL_SetTextureScaleMode(capitalBuildingUpgrade1Knight, SDL_SCALEMODE_NEAREST);
        capitalBuildingUpgrade2Knight = IMG_LoadTexture(renderer, "assets/Knight/CapitalBuildingUpgrade2Knight.png");
        if (capitalBuildingUpgrade2Knight == nullptr) {
            SDL_LogWarn(0, "failed to load the texture of capitalBuildingUpgrade2Knight", SDL_GetError());
        }
        SDL_SetTextureScaleMode(capitalBuildingUpgrade2Knight, SDL_SCALEMODE_NEAREST);
        capitalBuildingUpgrade3Knight = IMG_LoadTexture(renderer, "assets/Knight/CapitalBuildingUpgrade3Knight.png");
        if (capitalBuildingUpgrade3Knight == nullptr) {
            SDL_LogWarn(0, "failed to load the texture of capitalBuildingUpgrade3Knight", SDL_GetError());
        }
        SDL_SetTextureScaleMode(capitalBuildingUpgrade3Knight, SDL_SCALEMODE_NEAREST);
        capitalBuildingUpgrade4Knight = IMG_LoadTexture(renderer, "assets/Knight/CapitalBuildingUpgrade4Knight.png");
        if (capitalBuildingUpgrade4Knight == nullptr) {
            SDL_LogWarn(0, "failed to load the texture of capitalBuildingUpgrade4Knight", SDL_GetError());
        }
        SDL_SetTextureScaleMode(capitalBuildingUpgrade4Knight, SDL_SCALEMODE_NEAREST);
        capitalBuildingUpgrade5Knight = IMG_LoadTexture(renderer, "assets/Knight/CapitalBuildingUpgrade5Knight.png");
        if (capitalBuildingUpgrade5Knight == nullptr) {
            SDL_LogWarn(0, "failed to load the texture of capitalBuildingUpgrade5Knight", SDL_GetError());
        }
        SDL_SetTextureScaleMode(capitalBuildingUpgrade5Knight, SDL_SCALEMODE_NEAREST);
        //castle
        castleBuildingUpgrade1Knight = IMG_LoadTexture(renderer, "assets/Knight/CastleBuildingUpgrade1Knight.png");
        if (castleBuildingUpgrade1Knight == nullptr) {
            SDL_LogWarn(0,"failed to load the texture of castleBuildingUpgrade1Knight", SDL_GetError());
        }
        SDL_SetTextureScaleMode(castleBuildingUpgrade1Knight, SDL_SCALEMODE_NEAREST);
        castleBuildingUpgrade2Knight = IMG_LoadTexture(renderer, "assets/Knight/CastleBuildingUpgrade2Knight.png");
        if (castleBuildingUpgrade2Knight == nullptr) {
            SDL_LogWarn(0,"failed to load the texture of castleBuildingUpgrade2Knight", SDL_GetError());
        }
        SDL_SetTextureScaleMode(castleBuildingUpgrade2Knight, SDL_SCALEMODE_NEAREST);
        castleBuildingUpgrade3Knight = IMG_LoadTexture(renderer, "assets/Knight/CastleBuildingUpgrade3Knight.png");
        if (castleBuildingUpgrade3Knight == nullptr) {
            SDL_LogWarn(0,"failed to load the texture of castleBuildingUpgrade3Knight", SDL_GetError());
        }
        SDL_SetTextureScaleMode(castleBuildingUpgrade3Knight, SDL_SCALEMODE_NEAREST);
        castleBuildingUpgrade4Knight = IMG_LoadTexture(renderer, "assets/Knight/CastleBuildingUpgrade4Knight.png");
        if (castleBuildingUpgrade4Knight == nullptr) {
            SDL_LogWarn(0,"failed to load the texture of castleBuildingUpgrade4Knight", SDL_GetError());
        }
        SDL_SetTextureScaleMode(castleBuildingUpgrade4Knight, SDL_SCALEMODE_NEAREST);
        castleBuildingUpgrade5Knight = IMG_LoadTexture(renderer, "assets/Knight/CastleBuildingUpgrade5Knight.png");
        if (castleBuildingUpgrade5Knight == nullptr) {
            SDL_LogWarn(0,"failed to load the texture of castleBuildingUpgrade5Knight", SDL_GetError());
        }
        SDL_SetTextureScaleMode(castleBuildingUpgrade5Knight, SDL_SCALEMODE_NEAREST);
        //village
        villageBuildingUpgrade1Knight = IMG_LoadTexture(renderer, "assets/Knight/VillageBuildingUpgrade1Knight.png");
        if (villageBuildingUpgrade1Knight == nullptr) {
            SDL_LogWarn(0,"failed to load the texture of villageBuildingUpgrade1knight",SDL_GetError());
        }
        SDL_SetTextureScaleMode(villageBuildingUpgrade1Knight, SDL_SCALEMODE_NEAREST);
        villageBuildingUpgrade2Knight = IMG_LoadTexture(renderer, "assets/Knight/VillageBuildingUpgrade2Knight.png");
        if (villageBuildingUpgrade2Knight == nullptr) {
            SDL_LogWarn(0,"failed to load the texture of villageBuildingUpgrade2knight",SDL_GetError());
        }
        SDL_SetTextureScaleMode(villageBuildingUpgrade2Knight, SDL_SCALEMODE_NEAREST);
        villageBuildingUpgrade3Knight = IMG_LoadTexture(renderer, "assets/Knight/VillageBuildingUpgrade3Knight.png");
        if (villageBuildingUpgrade3Knight == nullptr) {
            SDL_LogWarn(0,"failed to load the texture of villageBuildingUpgrade3knight",SDL_GetError());
        }
        SDL_SetTextureScaleMode(villageBuildingUpgrade3Knight, SDL_SCALEMODE_NEAREST);
        //Unavailable Slot
        gameNotAvailableSlotKnight = IMG_LoadTexture(renderer, "assets/Knight/BuildingNotAvailableKnight.png");
        if (gameNotAvailableSlotKnight == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameNotAvailableSlotKnight", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameNotAvailableSlotKnight, SDL_SCALEMODE_NEAREST);
        //Available Slot
        gameAvailableSlotKnight = IMG_LoadTexture(renderer, "assets/Knight/BuildingAvailableKnight.png");
        if (gameAvailableSlotKnight == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameAvailableSlotKnight", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameAvailableSlotKnight, SDL_SCALEMODE_NEAREST);
        //buildings types grouping Textures
        gameBuildingTypesGroupingMilitaryKnight = IMG_LoadTexture(renderer,"assets/Knight/BuildingTypesGroupingMilitaryKnight.png");
        if (gameBuildingTypesGroupingMilitaryKnight == nullptr) {
            SDL_LogWarn(0,"failed to load texture gameBuildingTypesGroupingMilitaryKnight",SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingTypesGroupingMilitaryKnight, SDL_SCALEMODE_NEAREST);
        gameBuildingTypesGroupingAdvMilitaryKnight = IMG_LoadTexture(renderer, "assets/Knight/BuildingTypesGroupingAdvMilitaryKnight.png");
        if (gameBuildingTypesGroupingAdvMilitaryKnight == nullptr) {
            SDL_LogWarn(0,"failed to load texture gameBuildingTypesGroupingAdvMilitaryKnight",SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingTypesGroupingAdvMilitaryKnight, SDL_SCALEMODE_NEAREST);
        gameBuildingTypesGroupingDefenceKnight = IMG_LoadTexture(renderer, "assets/Knight/BuildingTypesGroupingDefenceKnight.png");
        if (gameBuildingTypesGroupingDefenceKnight == nullptr) {
            SDL_LogWarn(0,"failed to load texture gameBuildingTypesGroupingDefenceKnight", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingTypesGroupingDefenceKnight, SDL_SCALEMODE_NEAREST);
        gameBuildingTypesGroupingEconomyKnight = IMG_LoadTexture(renderer, "assets/Knight/BuildingTypesGroupingEconomyKnight.png");
        if (gameBuildingTypesGroupingEconomyKnight == nullptr) {
            SDL_LogWarn(0, "failed to load texture of gameBuildingTypesGroupingEconomyKnight", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingTypesGroupingEconomyKnight, SDL_SCALEMODE_NEAREST);
        gameBuildingTypesGroupingIndustryKnight = IMG_LoadTexture(renderer, "assets/Knight/BuildingTypesGroupingIndustryKnight.png");
        if (gameBuildingTypesGroupingIndustryKnight == nullptr) {
            SDL_LogWarn(0, "failed to load texture of gameBuildingTypesGroupingIndustryKnight", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingTypesGroupingIndustryKnight, SDL_SCALEMODE_NEAREST);
        gameBuildingTypesGroupingReligionKnight = IMG_LoadTexture(renderer, "assets/Knight/BuildingTypesGroupingReligionKnight.png");
        if (gameBuildingTypesGroupingReligionKnight == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameBuildingTypesGroupingReligionKnight",SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingTypesGroupingReligionKnight, SDL_SCALEMODE_NEAREST);

        //textures for all differents buildings (KNIGHT)
        //barracks
        buildingTypeTextures[BuildingType::Barracks_T1] = IMG_LoadTexture(renderer, "assets/Knight/BarracksTier1.png");
        if (buildingTypeTextures[BuildingType::Barracks_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture of Barracks_T1",SDL_GetError);
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Barracks_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::Barracks_T2] = IMG_LoadTexture(renderer, "assets/Knight/BarracksTier2.png");
        if (buildingTypeTextures[BuildingType::Barracks_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture Barracks_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Barracks_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::Barracks_T3] = IMG_LoadTexture(renderer, "assets/Knight/BarracksTier3.png");
        if (buildingTypeTextures[BuildingType::Barracks_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture Barracks_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Barracks_T3], SDL_SCALEMODE_NEAREST);

        //ArcheryRange
        buildingTypeTextures[BuildingType::ArcheryRange_T1] = IMG_LoadTexture(renderer, "assets/Knight/ArcheryRangeTier1.png");
        if (buildingTypeTextures[BuildingType::ArcheryRange_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture ArcheryRange_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::ArcheryRange_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::ArcheryRange_T2] = IMG_LoadTexture(renderer, "assets/Knight/ArcheryRangeTier2.png");
        if (buildingTypeTextures[BuildingType::ArcheryRange_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture ArcheryRange_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::ArcheryRange_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::ArcheryRange_T3] = IMG_LoadTexture(renderer, "assets/Knight/ArcheryRangeTier3.png");
        if (buildingTypeTextures[BuildingType::ArcheryRange_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture ArcheryRange_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::ArcheryRange_T3], SDL_SCALEMODE_NEAREST);

        //Stable
        buildingTypeTextures[BuildingType::Stable_T1] = IMG_LoadTexture(renderer, "assets/Knight/StableTier1.png");
        if (buildingTypeTextures[BuildingType::Stable_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture Stable_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Stable_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::Stable_T2] = IMG_LoadTexture(renderer, "assets/Knight/StableTier2.png");
        if (buildingTypeTextures[BuildingType::Stable_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture stable_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Stable_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::Stable_T3] = IMG_LoadTexture(renderer, "assets/Knight/StableTier3.png");
        if (buildingTypeTextures[BuildingType::Stable_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture stable_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Stable_T3], SDL_SCALEMODE_NEAREST);

        //Artillery
        buildingTypeTextures[BuildingType::Artillery_T4] = IMG_LoadTexture(renderer, "assets/Knight/ArtilleryTier4.png");
        if (buildingTypeTextures[BuildingType::Artillery_T4] == nullptr) {
            SDL_LogWarn(0, "failed to load  texture Artillery_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Artillery_T4], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::Artillery_T5] = IMG_LoadTexture(renderer, "assets/Knight/ArtilleryTier5.png");
        if (buildingTypeTextures[BuildingType::Artillery_T5] == nullptr) {
            SDL_LogWarn(0,"failed to load texture Artillery_T5", SDL_GetError);
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Artillery_T5], SDL_SCALEMODE_NEAREST);

        //Walls
        buildingTypeTextures[BuildingType::ReinforceWalls_T3] = IMG_LoadTexture(renderer, "assets/Knight/ReinforceWallsTier3.png");
        if (buildingTypeTextures[BuildingType::ReinforceWalls_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture ReinforceWalls_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::ReinforceWalls_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::ReinforceWalls_T4] = IMG_LoadTexture(renderer, "assets/Knight/ReinforceWallsTier4.png");
        if (buildingTypeTextures[BuildingType::ReinforceWalls_T4]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture ReinforceWalls_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::ReinforceWalls_T4], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::ReinforceWalls_T5] = IMG_LoadTexture(renderer, "assets/Knight/ReinforceWallsTier5.png");
        if (buildingTypeTextures[BuildingType::ReinforceWalls_T5]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture ReinforceWalls_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::ReinforceWalls_T5], SDL_SCALEMODE_NEAREST);

        //Economy
        //warehouse
        buildingTypeTextures[BuildingType::KnightWareHouse_T3] = IMG_LoadTexture(renderer, "assets/Knight/WareHouseTier3.png");
        if (buildingTypeTextures[BuildingType::KnightWareHouse_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightWareHouse_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightWareHouse_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightWareHouse_T4] = IMG_LoadTexture(renderer, "assets/Knight/WareHouseTier4.png");
        if (buildingTypeTextures[BuildingType::KnightWareHouse_T4]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightWareHouse_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightWareHouse_T4], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightWareHouse_T5] = IMG_LoadTexture(renderer, "assets/Knight/WareHouseTier5.png");
        if (buildingTypeTextures[BuildingType::KnightWareHouse_T5]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightWareHouse_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightWareHouse_T5], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightMint_T2] = IMG_LoadTexture(renderer, "assets/Knight/MintTier2.png");
        if (buildingTypeTextures[BuildingType::KnightMint_T2]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightMint_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightMint_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightMint_T3] = IMG_LoadTexture(renderer, "assets/Knight/MintTier3.png");
        if (buildingTypeTextures[BuildingType::KnightMint_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightMint_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightMint_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightMint_T4] = IMG_LoadTexture(renderer, "assets/Knight/MintTier4.png");
        if (buildingTypeTextures[BuildingType::KnightMint_T4]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightMint_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightMint_T4], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightTavern_T1] = IMG_LoadTexture(renderer, "assets/Knight/TavernTier1.png");
        if (buildingTypeTextures[BuildingType::KnightTavern_T1]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightTavern_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightTavern_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::Economy_T1] = IMG_LoadTexture(renderer, "assets/Knight/EconomyTier1.png");
        if (buildingTypeTextures[BuildingType::Economy_T1]  == nullptr) {
            SDL_LogWarn(0,"failed to load texture Economy_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Economy_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::Economy_T2] = IMG_LoadTexture(renderer, "assets/Knight/EconomyTier2.png");
        if (buildingTypeTextures[BuildingType::Economy_T2]  == nullptr) {
            SDL_LogWarn(0,"failed to load texture Economy_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Economy_T2], SDL_SCALEMODE_NEAREST);


        buildingTypeTextures[BuildingType::PeasantryGrowth_T1] = IMG_LoadTexture(renderer, "assets/Knight/PeasantryGrowthTier1.png");
        if (buildingTypeTextures[BuildingType::PeasantryGrowth_T1]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture Growth_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::PeasantryGrowth_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::PeasantryGrowth_T2] = IMG_LoadTexture(renderer, "assets/Knight/PeasantryGrowthTier2.png");
        if (buildingTypeTextures[BuildingType::PeasantryGrowth_T2]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture Growth_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::PeasantryGrowth_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::PeasantryGrowth_T3] = IMG_LoadTexture(renderer, "assets/Knight/PeasantryGrowthTier3.png");
        if (buildingTypeTextures[BuildingType::PeasantryGrowth_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture Growth_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::PeasantryGrowth_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::NobilityEstate_T1] = IMG_LoadTexture(renderer, "assets/Knight/NobilityGrowthTier1.png");
        if (buildingTypeTextures[BuildingType::NobilityEstate_T1]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture NobilityEstate_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::NobilityEstate_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::NobilityEstate_T2] = IMG_LoadTexture(renderer, "assets/Knight/NobilityGrowthTier2.png");
        if (buildingTypeTextures[BuildingType::NobilityEstate_T2]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture NobilityEstate_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::NobilityEstate_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::NobilityEstate_T3] = IMG_LoadTexture(renderer, "assets/Knight/NobilityGrowthTier3.png");
        if (buildingTypeTextures[BuildingType::NobilityEstate_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture NobilityEstate_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::NobilityEstate_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightGranary_T3] = IMG_LoadTexture(renderer, "assets/Knight/GranaryTier3.png");
        if (buildingTypeTextures[BuildingType::KnightGranary_T3] == nullptr) {
            SDL_LogWarn (0, "failed to load texture KnightGranary_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightGranary_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightGranary_T4] = IMG_LoadTexture(renderer, "assets/Knight/GranaryTier4.png");
        if (buildingTypeTextures[BuildingType::KnightGranary_T4] == nullptr) {
            SDL_LogWarn (0, "failed to load texture KnightGranary_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightGranary_T4], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightGranary_T5] = IMG_LoadTexture(renderer, "assets/Knight/GranaryTier5.png");
        if (buildingTypeTextures[BuildingType::KnightGranary_T5] == nullptr) {
            SDL_LogWarn (0, "failed to load texture KnightGranary_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightGranary_T5], SDL_SCALEMODE_NEAREST);

        //Industry
        buildingTypeTextures[BuildingType::KnightOilPress_T1] = IMG_LoadTexture(renderer, "assets/Knight/OilPressTier1.png");
        if (buildingTypeTextures[BuildingType::KnightOilPress_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightOilPress_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightOilPress_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightOilPress_T2] = IMG_LoadTexture(renderer, "assets/Knight/OilPressTier2.png");
        if (buildingTypeTextures[BuildingType::KnightOilPress_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightOilPress_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightOilPress_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightCarpentry_T1] = IMG_LoadTexture(renderer, "assets/Knight/CarpentryTier1.png");
        if (buildingTypeTextures[BuildingType::KnightCarpentry_T1]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightCarpentry_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightCarpentry_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightCarpentry_T2] = IMG_LoadTexture(renderer, "assets/Knight/CarpentryTier2.png");
        if (buildingTypeTextures[BuildingType::KnightCarpentry_T2]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightCarpentry_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightCarpentry_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightTextile_T1] = IMG_LoadTexture(renderer, "assets/Knight/TextileTier1.png");
        if (buildingTypeTextures[BuildingType::KnightTextile_T1]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightTextile_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightTextile_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightTextile_T2] = IMG_LoadTexture(renderer, "assets/Knight/TextileTier2.png");
        if (buildingTypeTextures[BuildingType::KnightTextile_T2]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightTextile_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightTextile_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightTextile_T3] = IMG_LoadTexture(renderer, "assets/Knight/TextileTier3.png");
        if (buildingTypeTextures[BuildingType::KnightTextile_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightTextile_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightTextile_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::KnightArtisan_T1] = IMG_LoadTexture(renderer, "assets/Knight/ArtisanTier1.png");
        if (buildingTypeTextures[BuildingType::KnightArtisan_T1]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightArtisan_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightArtisan_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightArtisan_T2] = IMG_LoadTexture(renderer, "assets/Knight/ArtisanTier2.png");
        if (buildingTypeTextures[BuildingType::KnightArtisan_T2]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightArtisan_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightArtisan_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightArtisan_T3] = IMG_LoadTexture(renderer, "assets/Knight/ArtisanTier3.png");
        if (buildingTypeTextures[BuildingType::KnightArtisan_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightArtisan_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightArtisan_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::KnightTinsmith_T2] = IMG_LoadTexture(renderer, "assets/Knight/TinSmithTier2.png");
        if (buildingTypeTextures[BuildingType::KnightTinsmith_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightTinsmith_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightTinsmith_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightTinsmith_T3] = IMG_LoadTexture(renderer, "assets/Knight/TinSmithTier3.png");
        if (buildingTypeTextures[BuildingType::KnightTinsmith_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightTinsmith_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightTinsmith_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightTinsmith_T4] = IMG_LoadTexture(renderer, "assets/Knight/TinSmithTier4.png");
        if (buildingTypeTextures[BuildingType::KnightTinsmith_T4] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightTinsmith_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightTinsmith_T4], SDL_SCALEMODE_NEAREST);


        buildingTypeTextures[BuildingType::KnightForge_T3] = IMG_LoadTexture(renderer, "assets/Knight/ForgeTier3.png");
        if (buildingTypeTextures[BuildingType::KnightForge_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightForge_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightForge_T3],  SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightForge_T4] = IMG_LoadTexture(renderer, "assets/Knight/ForgeTier4.png");
        if (buildingTypeTextures[BuildingType::KnightForge_T4]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightForge_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightForge_T4],  SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightForge_T5] = IMG_LoadTexture(renderer, "assets/Knight/ForgeTier5.png");
        if (buildingTypeTextures[BuildingType::KnightForge_T5]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightForge_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightForge_T5],  SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightJeweller_T3] = IMG_LoadTexture(renderer, "assets/Knight/JewellerTier3.png");
        if (buildingTypeTextures[BuildingType::KnightJeweller_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightJeweller_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightJeweller_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightJeweller_T4] = IMG_LoadTexture(renderer, "assets/Knight/JewellerTier4.png");
        if (buildingTypeTextures[BuildingType::KnightJeweller_T4]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightJeweller_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightJeweller_T4], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightJeweller_T5] = IMG_LoadTexture(renderer, "assets/Knight/JewellerTier5.png");
        if (buildingTypeTextures[BuildingType::KnightJeweller_T5]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightJeweller_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightJeweller_T5], SDL_SCALEMODE_NEAREST);
        //Religion
        //reconstitution
        buildingTypeTextures[BuildingType::KnightAlmsHouse_T1] = IMG_LoadTexture(renderer, "assets/Knight/AlmsHouse_T1.png");
        if (buildingTypeTextures[BuildingType::KnightAlmsHouse_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightAlmsHouse_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightAlmsHouse_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightAlmsHouse_T2] = IMG_LoadTexture(renderer, "assets/Knight/AlmsHouse_T2.png");
        if (buildingTypeTextures[BuildingType::KnightAlmsHouse_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightAlmsHouse_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightAlmsHouse_T2], SDL_SCALEMODE_NEAREST);
        //BeeKeeper Candle production
        buildingTypeTextures[BuildingType::KnightBeeKeeper_T1] = IMG_LoadTexture(renderer, "assets/Knight/BeeKeeper_T1.png");
        if (buildingTypeTextures[BuildingType::KnightBeeKeeper_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightBeeKeeper_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightBeeKeeper_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightBeeKeeper_T2] = IMG_LoadTexture(renderer, "assets/Knight/BeeKeeper_T2.png");
        if (buildingTypeTextures[BuildingType::KnightBeeKeeper_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightBeeKeeper_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightBeeKeeper_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightBeeKeeper_T3] = IMG_LoadTexture(renderer, "assets/Knight/BeeKeeper_T3.png");
        if (buildingTypeTextures[BuildingType::KnightBeeKeeper_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightBeeKeeper_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightBeeKeeper_T3], SDL_SCALEMODE_NEAREST);
        //Church (Public order)
        buildingTypeTextures[BuildingType::KnightChurch_T3] = IMG_LoadTexture(renderer, "assets/Knight/ChurchTier3.png");
        if (buildingTypeTextures[BuildingType::KnightChurch_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightChurch_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightChurch_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightChurch_T4] = IMG_LoadTexture(renderer, "assets/Knight/ChurchTier4.png");
        if (buildingTypeTextures[BuildingType::KnightChurch_T4] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightChurch_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightChurch_T4], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightChurch_T5] = IMG_LoadTexture(renderer, "assets/Knight/ChurchTier5.png");
        if (buildingTypeTextures[BuildingType::KnightChurch_T5] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightChurch_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightChurch_T5], SDL_SCALEMODE_NEAREST);
        //ports
        buildingTypeTextures[BuildingType::KnightMilitaryPort_T1] = IMG_LoadTexture(renderer, "assets/Knight/MilitaryPortTier1.png");
        if (buildingTypeTextures[BuildingType::KnightMilitaryPort_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightMilitaryPort_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightMilitaryPort_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightMilitaryPort_T2] = IMG_LoadTexture(renderer, "assets/Knight/MilitaryPortTier2.png");
        if (buildingTypeTextures[BuildingType::KnightMilitaryPort_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightMilitaryPort_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightMilitaryPort_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightMilitaryPort_T3] = IMG_LoadTexture(renderer, "assets/Knight/MilitaryPortTier3.png");
        if (buildingTypeTextures[BuildingType::KnightMilitaryPort_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightMilitaryPort_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightMilitaryPort_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightMilitaryPort_T4] = IMG_LoadTexture(renderer, "assets/Knight/MilitaryPortTier4.png");
        if (buildingTypeTextures[BuildingType::KnightMilitaryPort_T4] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightMilitaryPort_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightMilitaryPort_T4], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightMilitaryPort_T5] = IMG_LoadTexture(renderer, "assets/Knight/MilitaryPortTier5.png");
        if (buildingTypeTextures[BuildingType::KnightMilitaryPort_T5] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightMilitaryPort_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightMilitaryPort_T5], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightFishingPort_T1] = IMG_LoadTexture(renderer, "assets/Knight/FishingPortTier1.png");
        if (buildingTypeTextures[BuildingType::KnightFishingPort_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightFishingPort_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightFishingPort_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightFishingPort_T2] = IMG_LoadTexture(renderer, "assets/Knight/FishingPortTier2.png");
        if (buildingTypeTextures[BuildingType::KnightFishingPort_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightFishingPort_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightFishingPort_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightFishingPort_T3] = IMG_LoadTexture(renderer, "assets/Knight/FishingPortTier3.png");
        if (buildingTypeTextures[BuildingType::KnightFishingPort_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightFishingPort_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightFishingPort_T3], SDL_SCALEMODE_NEAREST);

        //                  ! VIKING !
        //capitals
        capitalBuildingUpgrade1Viking = IMG_LoadTexture(renderer, "assets/Viking/CapitalBuildingUpgrade1Viking.png");
        if (capitalBuildingUpgrade1Viking == nullptr) {
            SDL_LogWarn(0,"failed to load texture capitalBuildingUpgrade1Viking", SDL_GetError());
        }
        SDL_SetTextureScaleMode(capitalBuildingUpgrade1Viking, SDL_SCALEMODE_NEAREST);
        capitalBuildingUpgrade2Viking = IMG_LoadTexture(renderer, "assets/Viking/CapitalBuildingUpgrade2Viking.png");
        if (capitalBuildingUpgrade2Viking == nullptr) {
            SDL_LogWarn(0,"failed to load texture capitalBuildingUpgrade2Viking", SDL_GetError());
        }
        SDL_SetTextureScaleMode(capitalBuildingUpgrade2Viking, SDL_SCALEMODE_NEAREST);
        capitalBuildingUpgrade3Viking = IMG_LoadTexture(renderer, "assets/Viking/CapitalBuildingUpgrade3Viking.png");
        if (capitalBuildingUpgrade3Viking == nullptr) {
            SDL_LogWarn(0,"failed to load texture capitalBuildingUpgrade3Viking", SDL_GetError());
        }
        SDL_SetTextureScaleMode(capitalBuildingUpgrade3Viking, SDL_SCALEMODE_NEAREST);
        capitalBuildingUpgrade4Viking = IMG_LoadTexture(renderer, "assets/Viking/CapitalBuildingUpgrade4Viking.png");
        if (capitalBuildingUpgrade4Viking == nullptr) {
            SDL_LogWarn(0,"failed to load texture capitalBuildingUpgrade4Viking", SDL_GetError());
        }
        SDL_SetTextureScaleMode(capitalBuildingUpgrade4Viking, SDL_SCALEMODE_NEAREST);
        capitalBuildingUpgrade5Viking = IMG_LoadTexture(renderer, "assets/Viking/CapitalBuildingUpgrade5Viking.png");
        if (capitalBuildingUpgrade5Viking == nullptr) {
            SDL_LogWarn(0,"failed to load texture capitalBuildingUpgrade5Viking", SDL_GetError());
        }
        SDL_SetTextureScaleMode(capitalBuildingUpgrade5Viking, SDL_SCALEMODE_NEAREST);
        //Castles
        castleBuildingUpgrade1Viking = IMG_LoadTexture(renderer, "assets/Viking/CastleBuildingUpgrade1Viking.png");
        if (castleBuildingUpgrade1Viking == nullptr) {
            SDL_LogWarn(0,"failed to load texture castleBuildingUpgrade1Viking",SDL_GetError());
        }
        SDL_SetTextureScaleMode(castleBuildingUpgrade1Viking, SDL_SCALEMODE_NEAREST);
        castleBuildingUpgrade2Viking = IMG_LoadTexture(renderer, "assets/Viking/CastleBuildingUpgrade2Viking.png");
        if (castleBuildingUpgrade2Viking == nullptr) {
            SDL_LogWarn(0,"failed to load texture castleBuildingUpgrade2Viking", SDL_GetError());
        }
        SDL_SetTextureScaleMode(castleBuildingUpgrade2Viking, SDL_SCALEMODE_NEAREST);
        castleBuildingUpgrade3Viking = IMG_LoadTexture(renderer, "assets/Viking/CastleBuildingUpgrade3Viking.png");
        if (castleBuildingUpgrade3Viking == nullptr) {
            SDL_LogWarn(0,"failed to load texture castleBuildingUpgrade3Viking", SDL_GetError());
        }
        SDL_SetTextureScaleMode(castleBuildingUpgrade3Viking, SDL_SCALEMODE_NEAREST);
        castleBuildingUpgrade4Viking = IMG_LoadTexture(renderer, "assets/Viking/CastleBuildingUpgrade4Viking.png");
        if (castleBuildingUpgrade4Viking == nullptr) {
            SDL_LogWarn(0,"failed to load texture castleBuildingUpgrade4Viking", SDL_GetError());
        }
        SDL_SetTextureScaleMode(castleBuildingUpgrade4Viking, SDL_SCALEMODE_NEAREST);
        castleBuildingUpgrade5Viking = IMG_LoadTexture(renderer, "assets/Viking/CastleBuildingUpgrade5Viking.png");
        if (castleBuildingUpgrade5Viking == nullptr) {
            SDL_LogWarn(0,"failed to load texture castleBuildingUpgrade5Viking", SDL_GetError());
        }
        SDL_SetTextureScaleMode(castleBuildingUpgrade5Viking, SDL_SCALEMODE_NEAREST);
        //Villages
        villageBuildingUpgrade1Viking = IMG_LoadTexture(renderer, "assets/Viking/VillageBuildingUpgrade1Viking.png");
        if (villageBuildingUpgrade1Viking == nullptr) {
            SDL_LogWarn(0,"failed to load texture villageBuildingUpgrade1Viking", SDL_GetError());
        }
        SDL_SetTextureScaleMode(villageBuildingUpgrade1Viking, SDL_SCALEMODE_NEAREST);
        villageBuildingUpgrade2Viking = IMG_LoadTexture(renderer, "assets/Viking/VillageBuildingUpgrade2Viking.png");
        if (villageBuildingUpgrade2Viking == nullptr) {
            SDL_LogWarn(0,"failed to load texture villageBuildingUpgrade2Viking", SDL_GetError());
        }
        SDL_SetTextureScaleMode(villageBuildingUpgrade2Viking, SDL_SCALEMODE_NEAREST);
        villageBuildingUpgrade3Viking = IMG_LoadTexture(renderer, "assets/Viking/VillageBuildingUpgrade3Viking.png");
        if (villageBuildingUpgrade3Viking == nullptr) {
            SDL_LogWarn(0,"failed to load texture villageBuildingUpgrade3Viking", SDL_GetError());
        }
        SDL_SetTextureScaleMode(villageBuildingUpgrade3Viking, SDL_SCALEMODE_NEAREST);
        //Unavailable Slot
        gameNotAvailableSlotViking = IMG_LoadTexture(renderer, "assets/Viking/BuildingNotAvailableViking.png");
        if (gameNotAvailableSlotViking == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameNotAvailableSlotViking", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameNotAvailableSlotViking, SDL_SCALEMODE_NEAREST);
        //Available Slot
        gameAvailableSlotViking = IMG_LoadTexture(renderer, "assets/Viking/BuildingAvailableViking.png");
        if (gameAvailableSlotViking == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameAvailableSlotViking", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameAvailableSlotViking, SDL_SCALEMODE_NEAREST);

        //buildings types grouping Textures
        gameBuildingTypesGroupingMilitaryViking = IMG_LoadTexture(renderer,"assets/Viking/BuildingTypesGroupingMilitaryViking.png");
        if (gameBuildingTypesGroupingMilitaryViking == nullptr) {
            SDL_LogWarn(0,"failed to load texture gameBuildingTypesGroupingMilitaryViking",SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingTypesGroupingMilitaryViking, SDL_SCALEMODE_NEAREST);
        gameBuildingTypesGroupingAdvMilitaryViking = IMG_LoadTexture(renderer, "assets/Viking/BuildingTypesGroupingAdvMilitaryViking.png");
        if (gameBuildingTypesGroupingAdvMilitaryViking == nullptr) {
            SDL_LogWarn(0,"failed to load texture gameBuildingTypesGroupingAdvMilitaryViking",SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingTypesGroupingAdvMilitaryViking, SDL_SCALEMODE_NEAREST);
        gameBuildingTypesGroupingDefenceViking = IMG_LoadTexture(renderer, "assets/Viking/BuildingTypesGroupingDefenceViking.png");
        if (gameBuildingTypesGroupingDefenceViking == nullptr) {
            SDL_LogWarn(0,"failed to load texture gameBuildingTypesGroupingDefenceViking", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingTypesGroupingDefenceViking, SDL_SCALEMODE_NEAREST);
        gameBuildingTypesGroupingEconomyViking = IMG_LoadTexture(renderer, "assets/Viking/BuildingTypesGroupingEconomyViking.png");
        if (gameBuildingTypesGroupingEconomyViking == nullptr) {
            SDL_LogWarn(0, "failed to load texture of gameBuildingTypesGroupingEconomyViking", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingTypesGroupingEconomyViking, SDL_SCALEMODE_NEAREST);
        gameBuildingTypesGroupingIndustryViking = IMG_LoadTexture(renderer, "assets/Viking/BuildingTypesGroupingIndustryViking.png");
        if (gameBuildingTypesGroupingIndustryViking == nullptr) {
            SDL_LogWarn(0, "failed to load texture of gameBuildingTypesGroupingIndutryViking", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingTypesGroupingIndustryViking, SDL_SCALEMODE_NEAREST);
        gameBuildingTypesGroupingReligionViking = IMG_LoadTexture(renderer, "assets/Viking/BuildingTypesGroupingReligionViking.png");
        if (gameBuildingTypesGroupingReligionViking == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameBuildingTypesGroupingReligionViking",SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingTypesGroupingReligionViking, SDL_SCALEMODE_NEAREST);

        //Buildings Texture
        //Military
        buildingTypeTextures[BuildingType::WarLodge_T1] = IMG_LoadTexture(renderer, "assets/Viking/WarLodgeTier1.png");
        if (buildingTypeTextures[BuildingType::WarLodge_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture WarLodge_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::WarLodge_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::WarLodge_T2] = IMG_LoadTexture(renderer, "assets/Viking/WarLodgeTier2.png");
        if (buildingTypeTextures[BuildingType::WarLodge_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture WarLodge_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::WarLodge_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::WarLodge_T3] = IMG_LoadTexture(renderer, "assets/Viking/WarLodgeTier3.png");
        if (buildingTypeTextures[BuildingType::WarLodge_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture WarLodge_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::WarLodge_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::ShootingGround_T1] = IMG_LoadTexture(renderer, "assets/Viking/ShootingGroundTier1.png");
        if (buildingTypeTextures[BuildingType::ShootingGround_T1] == nullptr){
            SDL_LogWarn(0, "failed to load texture ShootingGround_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::ShootingGround_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::ShootingGround_T2] = IMG_LoadTexture(renderer, "assets/Viking/ShootingGroundTier2.png");
        if (buildingTypeTextures[BuildingType::ShootingGround_T2] == nullptr){
            SDL_LogWarn(0, "failed to load texture ShootingGround_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::ShootingGround_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::ShootingGround_T3] = IMG_LoadTexture(renderer, "assets/Viking/ShootingGroundTier3.png");
        if (buildingTypeTextures[BuildingType::ShootingGround_T3] == nullptr){
            SDL_LogWarn(0, "failed to load texture ShootingGround_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::ShootingGround_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::HorseTraining_T1] = IMG_LoadTexture(renderer, "assets/Viking/HorseTrainingTier1.png");
        if (buildingTypeTextures[BuildingType::HorseTraining_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture HorseTraining_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::HorseTraining_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::HorseTraining_T2] = IMG_LoadTexture(renderer, "assets/Viking/HorseTrainingTier2.png");
        if (buildingTypeTextures[BuildingType::HorseTraining_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture HorseTraining_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::HorseTraining_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::HorseTraining_T3] = IMG_LoadTexture(renderer, "assets/Viking/HorseTrainingTier3.png");
        if (buildingTypeTextures[BuildingType::HorseTraining_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture HorseTraining_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::HorseTraining_T3], SDL_SCALEMODE_NEAREST);

        //Adv Military
        buildingTypeTextures[BuildingType::ChosensOfOdin_T3] = IMG_LoadTexture(renderer, "assets/Viking/ChosensOfOdinTier3.png");
        if (buildingTypeTextures[BuildingType::ChosensOfOdin_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture ChosensOfOdin_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::ChosensOfOdin_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::ChosensOfOdin_T4] = IMG_LoadTexture(renderer, "assets/Viking/ChosensOfOdinTier4.png");
        if (buildingTypeTextures[BuildingType::ChosensOfOdin_T4] == nullptr) {
            SDL_LogWarn(0, "failed to load texture ChosensOfOdin_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::ChosensOfOdin_T4], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::ChosensOfOdin_T5] = IMG_LoadTexture(renderer, "assets/Viking/ChosensOfOdinTier5.png");
        if (buildingTypeTextures[BuildingType::ChosensOfOdin_T5] == nullptr) {
            SDL_LogWarn(0, "failed to load texture ChosensOfOdin_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::ChosensOfOdin_T5], SDL_SCALEMODE_NEAREST);

        //Defence
        buildingTypeTextures[BuildingType::ReinforcedDrakkar_T3] = IMG_LoadTexture(renderer, "assets/Viking/ReinforcedDrakkarTier3.png");
        if (buildingTypeTextures[BuildingType::ReinforcedDrakkar_T3] == nullptr) {
            SDL_LogWarn(0,"failed to load texture ReinforcedDrakkar_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::ReinforcedDrakkar_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::ReinforcedDrakkar_T4] = IMG_LoadTexture(renderer, "assets/Viking/ReinforcedDrakkarTier4.png");
        if (buildingTypeTextures[BuildingType::ReinforcedDrakkar_T4] == nullptr) {
            SDL_LogWarn(0,"failed to load texture ReinforcedDrakkar_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::ReinforcedDrakkar_T4], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::ReinforcedDrakkar_T5] = IMG_LoadTexture(renderer, "assets/Viking/ReinforcedDrakkarTier5.png");
        if (buildingTypeTextures[BuildingType::ReinforcedDrakkar_T5] == nullptr) {
            SDL_LogWarn(0,"failed to load texture ReinforcedDrakkar_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::ReinforcedDrakkar_T5], SDL_SCALEMODE_NEAREST);

        //Economy
        //warehouse
        buildingTypeTextures[BuildingType::VikingWareHouse_T3] = IMG_LoadTexture(renderer, "assets/Viking/WareHouseTier3.png");
        if (buildingTypeTextures[BuildingType::VikingWareHouse_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingWareHouse_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingWareHouse_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingWareHouse_T4] = IMG_LoadTexture(renderer, "assets/Viking/WareHouseTier4.png");
        if (buildingTypeTextures[BuildingType::VikingWareHouse_T4]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingWareHouse_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingWareHouse_T4], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingWareHouse_T5] = IMG_LoadTexture(renderer, "assets/Viking/WareHouseTier5.png");
        if (buildingTypeTextures[BuildingType::VikingWareHouse_T5]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingWareHouse_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingWareHouse_T5], SDL_SCALEMODE_NEAREST);
        //roads
        buildingTypeTextures[BuildingType::KnightRoads_T1] = IMG_LoadTexture(renderer, "assets/Knight/RoadsTier1.png");
        if (buildingTypeTextures[BuildingType::KnightRoads_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightRoads_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightRoads_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightRoads_T2] = IMG_LoadTexture(renderer, "assets/Knight/RoadsTier2.png");
        if (buildingTypeTextures[BuildingType::KnightRoads_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightRoads_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightRoads_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::KnightRoads_T3] = IMG_LoadTexture(renderer, "assets/Knight/RoadsTier3.png");
        if (buildingTypeTextures[BuildingType::KnightRoads_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture KnightRoads_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::KnightRoads_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingRoads_T1] = IMG_LoadTexture(renderer, "assets/Viking/RoadsTier1.png");
        if (buildingTypeTextures[BuildingType::VikingRoads_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingRoads_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingRoads_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingRoads_T2] = IMG_LoadTexture(renderer, "assets/Viking/RoadsTier2.png");
        if (buildingTypeTextures[BuildingType::VikingRoads_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingRoads_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingRoads_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingRoads_T3] = IMG_LoadTexture(renderer, "assets/Viking/RoadsTier3.png");
        if (buildingTypeTextures[BuildingType::VikingRoads_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingRoads_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingRoads_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiRoads_T1] = IMG_LoadTexture(renderer, "assets/Samurai/RoadsTier1.png");
        if (buildingTypeTextures[BuildingType::SamuraiRoads_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiRoads_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiRoads_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiRoads_T2] = IMG_LoadTexture(renderer, "assets/Samurai/RoadsTier2.png");
        if (buildingTypeTextures[BuildingType::SamuraiRoads_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiRoads_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiRoads_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiRoads_T3] = IMG_LoadTexture(renderer, "assets/Samurai/RoadsTier3.png");
        if (buildingTypeTextures[BuildingType::SamuraiRoads_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiRoads_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiRoads_T3], SDL_SCALEMODE_NEAREST);


        buildingTypeTextures[BuildingType::VikingMint_T2] = IMG_LoadTexture(renderer, "assets/Viking/MintTier2.png");
        if (buildingTypeTextures[BuildingType::VikingMint_T2]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingMint_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingMint_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingMint_T3] = IMG_LoadTexture(renderer, "assets/Viking/MintTier3.png");
        if (buildingTypeTextures[BuildingType::VikingMint_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingMint_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingMint_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingMint_T4] = IMG_LoadTexture(renderer, "assets/Viking/MintTier4.png");
        if (buildingTypeTextures[BuildingType::VikingMint_T4]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingMint_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingMint_T4], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingTavern_T1] = IMG_LoadTexture(renderer, "assets/Viking/TavernTier1.png");
        if (buildingTypeTextures[BuildingType::VikingTavern_T1]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingTavern_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingTavern_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::SlaveMarket_T1]= IMG_LoadTexture(renderer, "assets/Viking/SlaveMarketTier1.png");
        if (buildingTypeTextures[BuildingType::SlaveMarket_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SlaveMarket_T1", SDL_GetError);
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SlaveMarket_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::SlaveMarket_T2]= IMG_LoadTexture(renderer, "assets/Viking/SlaveMarketTier2.png");
        if (buildingTypeTextures[BuildingType::SlaveMarket_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SlaveMarket_T2", SDL_GetError);
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SlaveMarket_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::PeasantryVikingGrowth_T1] = IMG_LoadTexture(renderer, "assets/Viking/PeasantryGrowthTier1.png");
        if (buildingTypeTextures[BuildingType::PeasantryVikingGrowth_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture PeasantryVikingGrowth_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::PeasantryVikingGrowth_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::PeasantryVikingGrowth_T2] = IMG_LoadTexture(renderer, "assets/Viking/PeasantryGrowthTier2.png");
        if (buildingTypeTextures[BuildingType::PeasantryVikingGrowth_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture PeasantryVikingGrowth_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::PeasantryVikingGrowth_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::PeasantryVikingGrowth_T3] = IMG_LoadTexture(renderer, "assets/Viking/PeasantryGrowthTier3.png");
        if (buildingTypeTextures[BuildingType::PeasantryVikingGrowth_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture PeasantryVikingGrowth_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::PeasantryVikingGrowth_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::NobilityVikingEstate_T1] = IMG_LoadTexture(renderer, "assets/Viking/NobilityGrowthTier1.png");
        if (buildingTypeTextures[BuildingType::NobilityVikingEstate_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture NobilityVikingEstate_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::NobilityVikingEstate_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::NobilityVikingEstate_T2] = IMG_LoadTexture(renderer, "assets/Viking/NobilityGrowthTier2.png");
        if (buildingTypeTextures[BuildingType::NobilityVikingEstate_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture NobilityVikingEstate_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::NobilityVikingEstate_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::NobilityVikingEstate_T3] = IMG_LoadTexture(renderer, "assets/Viking/NobilityGrowthTier3.png");
        if (buildingTypeTextures[BuildingType::NobilityVikingEstate_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture NobilityVikingEstate_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::NobilityVikingEstate_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingGranary_T3] = IMG_LoadTexture(renderer, "assets/Viking/GranaryTier3.png");
        if (buildingTypeTextures[BuildingType::VikingGranary_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingGranary_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingGranary_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingGranary_T4] = IMG_LoadTexture(renderer, "assets/Viking/GranaryTier4.png");
        if (buildingTypeTextures[BuildingType::VikingGranary_T4] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingGranary_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingGranary_T4], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingGranary_T5] = IMG_LoadTexture(renderer, "assets/Viking/GranaryTier5.png");
        if (buildingTypeTextures[BuildingType::VikingGranary_T5] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingGranary_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingGranary_T5], SDL_SCALEMODE_NEAREST);


        //Industry
        buildingTypeTextures[BuildingType::VikingOilPress_T1] = IMG_LoadTexture(renderer, "assets/Viking/OilPressTier1.png");
        if (buildingTypeTextures[BuildingType::VikingOilPress_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingOilPress_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingOilPress_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingOilPress_T2] = IMG_LoadTexture(renderer, "assets/Viking/OilPressTier2.png");
        if (buildingTypeTextures[BuildingType::VikingOilPress_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingOilPress_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingOilPress_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingCarpentry_T1] = IMG_LoadTexture(renderer, "assets/Viking/CarpentryTier1.png");
        if (buildingTypeTextures[BuildingType::VikingCarpentry_T1]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingCarpentry_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingCarpentry_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingCarpentry_T2] = IMG_LoadTexture(renderer, "assets/Viking/CarpentryTier2.png");
        if (buildingTypeTextures[BuildingType::VikingCarpentry_T2]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingCarpentry_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingCarpentry_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::VikingTextile_T1] = IMG_LoadTexture(renderer, "assets/Viking/TextileTier1.png");
        if (buildingTypeTextures[BuildingType::VikingTextile_T1]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingTextile_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingTextile_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingTextile_T2] = IMG_LoadTexture(renderer, "assets/Viking/TextileTier2.png");
        if (buildingTypeTextures[BuildingType::VikingTextile_T2]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingTextile_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingTextile_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingTextile_T3] = IMG_LoadTexture(renderer, "assets/Viking/TextileTier3.png");
        if (buildingTypeTextures[BuildingType::VikingTextile_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingTextile_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingTextile_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::VikingArtisan_T1] = IMG_LoadTexture(renderer, "assets/Viking/ArtisanTier1.png");
        if (buildingTypeTextures[BuildingType::VikingArtisan_T1]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingArtisan_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingArtisan_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingArtisan_T2] = IMG_LoadTexture(renderer, "assets/Viking/ArtisanTier2.png");
        if (buildingTypeTextures[BuildingType::VikingArtisan_T2]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingArtisan_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingArtisan_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingArtisan_T3] = IMG_LoadTexture(renderer, "assets/Viking/ArtisanTier3.png");
        if (buildingTypeTextures[BuildingType::VikingArtisan_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingArtisan_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingArtisan_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::VikingTinsmith_T2] = IMG_LoadTexture(renderer, "assets/Viking/TinSmithTier2.png");
        if (buildingTypeTextures[BuildingType::VikingTinsmith_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingTinsmith_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingTinsmith_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingTinsmith_T3] = IMG_LoadTexture(renderer, "assets/Viking/TinSmithTier3.png");
        if (buildingTypeTextures[BuildingType::VikingTinsmith_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingTinsmith_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingTinsmith_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingTinsmith_T4] = IMG_LoadTexture(renderer, "assets/Viking/TinSmithTier4.png");
        if (buildingTypeTextures[BuildingType::VikingTinsmith_T4] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingTinsmith_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingTinsmith_T4], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::VikingForge_T3] = IMG_LoadTexture(renderer, "assets/Viking/ForgeTier3.png");
        if (buildingTypeTextures[BuildingType::VikingForge_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingForge_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingForge_T3],  SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingForge_T4] = IMG_LoadTexture(renderer, "assets/Viking/ForgeTier4.png");
        if (buildingTypeTextures[BuildingType::VikingForge_T4]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingForge_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingForge_T4],  SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingForge_T5] = IMG_LoadTexture(renderer, "assets/Viking/ForgeTier5.png");
        if (buildingTypeTextures[BuildingType::VikingForge_T5]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingForge_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingForge_T5],  SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingJeweller_T3] = IMG_LoadTexture(renderer, "assets/Viking/JewellerTier3.png");
        if (buildingTypeTextures[BuildingType::VikingJeweller_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingJeweller_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingJeweller_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingJeweller_T4] = IMG_LoadTexture(renderer, "assets/Viking/JewellerTier4.png");
        if (buildingTypeTextures[BuildingType::VikingJeweller_T4]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingJeweller_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingJeweller_T4], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingJeweller_T5] = IMG_LoadTexture(renderer, "assets/Viking/JewellerTier5.png");
        if (buildingTypeTextures[BuildingType::VikingJeweller_T5]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingJeweller_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingJeweller_T5], SDL_SCALEMODE_NEAREST);

        //Religion
        //reconstitution
        buildingTypeTextures[BuildingType::VikingShrine_T1] = IMG_LoadTexture(renderer, "assets/Viking/ShrineTier1.png");
        if (buildingTypeTextures[BuildingType::VikingShrine_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingShrine_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingShrine_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::VikingShrine_T2] = IMG_LoadTexture(renderer, "assets/Viking/ShrineTier2.png");
        if (buildingTypeTextures[BuildingType::VikingShrine_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingShrine_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingShrine_T2], SDL_SCALEMODE_NEAREST);
        //Beer production
        buildingTypeTextures[BuildingType::VikingBrewKeeper_T1] = IMG_LoadTexture(renderer, "assets/Viking/BrewKeeper_T1.png");
        if (buildingTypeTextures[BuildingType::VikingBrewKeeper_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingBrewKeeper_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingBrewKeeper_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingBrewKeeper_T2] = IMG_LoadTexture(renderer, "assets/Viking/BrewKeeper_T2.png");
        if (buildingTypeTextures[BuildingType::VikingBrewKeeper_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingBrewKeeper_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingBrewKeeper_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingBrewKeeper_T3] = IMG_LoadTexture(renderer, "assets/Viking/BrewKeeper_T3.png");
        if (buildingTypeTextures[BuildingType::VikingBrewKeeper_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingBrewKeeper_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingBrewKeeper_T3], SDL_SCALEMODE_NEAREST);
        //Public order
        buildingTypeTextures[BuildingType::VikingSacrificeRitual_T3] = IMG_LoadTexture(renderer, "assets/Viking/SacrificeRitualTier3.png");
        if (buildingTypeTextures[BuildingType::VikingSacrificeRitual_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingSacrificeRitual_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingSacrificeRitual_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingSacrificeRitual_T4] = IMG_LoadTexture(renderer, "assets/Viking/SacrificeRitualTier4.png");
        if (buildingTypeTextures[BuildingType::VikingSacrificeRitual_T4] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingSacrificeRitual_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingSacrificeRitual_T4], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingSacrificeRitual_T5] = IMG_LoadTexture(renderer, "assets/Viking/SacrificeRitualTier5.png");
        if (buildingTypeTextures[BuildingType::VikingSacrificeRitual_T5] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingSacrificeRitual_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingSacrificeRitual_T5], SDL_SCALEMODE_NEAREST);
        //Ports
        buildingTypeTextures[BuildingType::VikingMilitaryPort_T1] = IMG_LoadTexture(renderer, "assets/Viking/MilitaryPortTier1.png");
        if (buildingTypeTextures[BuildingType::VikingMilitaryPort_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingMilitaryPort_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingMilitaryPort_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingMilitaryPort_T2] = IMG_LoadTexture(renderer, "assets/Viking/MilitaryPortTier2.png");
        if (buildingTypeTextures[BuildingType::VikingMilitaryPort_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingMilitaryPort_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingMilitaryPort_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingMilitaryPort_T3] = IMG_LoadTexture(renderer, "assets/Viking/MilitaryPortTier3.png");
        if (buildingTypeTextures[BuildingType::VikingMilitaryPort_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingMilitaryPort_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingMilitaryPort_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingMilitaryPort_T4] = IMG_LoadTexture(renderer, "assets/Viking/MilitaryPortTier4.png");
        if (buildingTypeTextures[BuildingType::VikingMilitaryPort_T4] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingMilitaryPort_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingMilitaryPort_T4], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingMilitaryPort_T5] = IMG_LoadTexture(renderer, "assets/Viking/MilitaryPortTier5.png");
        if (buildingTypeTextures[BuildingType::VikingMilitaryPort_T5] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingMilitaryPort_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingMilitaryPort_T5], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingFishingPort_T1] = IMG_LoadTexture(renderer, "assets/Viking/FishingPortTier1.png");
        if (buildingTypeTextures[BuildingType::VikingFishingPort_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingFishingPort_T1", SDL_GetError);
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingFishingPort_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingFishingPort_T2] = IMG_LoadTexture(renderer, "assets/Viking/FishingPortTier2.png");
        if (buildingTypeTextures[BuildingType::VikingFishingPort_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingFishingPort_T2", SDL_GetError);
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingFishingPort_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::VikingFishingPort_T3] = IMG_LoadTexture(renderer, "assets/Viking/FishingPortTier3.png");
        if (buildingTypeTextures[BuildingType::VikingFishingPort_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingFishingPort_T3", SDL_GetError);
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingFishingPort_T3], SDL_SCALEMODE_NEAREST);
        //                  ! SAMURAI !
        //capitals
        capitalBuildingUpgrade1Samurai = IMG_LoadTexture(renderer, "assets/Samurai/CapitalBuildingUpgrade1Samurai.png");
        if (capitalBuildingUpgrade1Samurai == nullptr) {
            SDL_LogWarn(0, "failed to load texture capitalBuildingUpgrade1Samurai");
        }
        SDL_SetTextureScaleMode(capitalBuildingUpgrade1Samurai, SDL_SCALEMODE_NEAREST);
        capitalBuildingUpgrade2Samurai = IMG_LoadTexture(renderer, "assets/Samurai/CapitalBuildingUpgrade2Samurai.png");
        if (capitalBuildingUpgrade2Samurai == nullptr) {
            SDL_LogWarn(0, "failed to load texture capitalBuildingUpgrade2Samurai");
        }
        SDL_SetTextureScaleMode(capitalBuildingUpgrade2Samurai, SDL_SCALEMODE_NEAREST);
        capitalBuildingUpgrade3Samurai = IMG_LoadTexture(renderer, "assets/Samurai/CapitalBuildingUpgrade3Samurai.png");
        if (capitalBuildingUpgrade3Samurai == nullptr) {
            SDL_LogWarn(0, "failed to load texture capitalBuildingUpgrade3Samurai");
        }
        SDL_SetTextureScaleMode(capitalBuildingUpgrade3Samurai, SDL_SCALEMODE_NEAREST);
        capitalBuildingUpgrade4Samurai = IMG_LoadTexture(renderer, "assets/Samurai/CapitalBuildingUpgrade4Samurai.png");
        if (capitalBuildingUpgrade4Samurai == nullptr) {
            SDL_LogWarn(0, "failed to load texture capitalBuildingUpgrade4Samurai");
        }
        SDL_SetTextureScaleMode(capitalBuildingUpgrade4Samurai, SDL_SCALEMODE_NEAREST);
        capitalBuildingUpgrade5Samurai = IMG_LoadTexture(renderer, "assets/Samurai/CapitalBuildingUpgrade5Samurai.png");
        if (capitalBuildingUpgrade5Samurai == nullptr) {
            SDL_LogWarn(0, "failed to load texture capitalBuildingUpgrade5Samurai");
        }
        SDL_SetTextureScaleMode(capitalBuildingUpgrade5Samurai, SDL_SCALEMODE_NEAREST);
        //castles
        castleBuildingUpgrade1Samurai = IMG_LoadTexture(renderer, "assets/Samurai/CastleBuildingUpgrade1Samurai.png");
        if (castleBuildingUpgrade1Samurai == nullptr) {
            SDL_LogWarn(0, "failed to load texture castleBuildingUpgrade1Samurai", SDL_GetError());
        }
        SDL_SetTextureScaleMode(castleBuildingUpgrade1Samurai, SDL_SCALEMODE_NEAREST);
        castleBuildingUpgrade2Samurai = IMG_LoadTexture(renderer, "assets/Samurai/CastleBuildingUpgrade2Samurai.png");
        if (castleBuildingUpgrade2Samurai == nullptr) {
            SDL_LogWarn(0, "failed to load texture castleBuildingUpgrade2Samurai", SDL_GetError());
        }
        SDL_SetTextureScaleMode(castleBuildingUpgrade2Samurai, SDL_SCALEMODE_NEAREST);
        castleBuildingUpgrade3Samurai = IMG_LoadTexture(renderer, "assets/Samurai/CastleBuildingUpgrade3Samurai.png");
        if (castleBuildingUpgrade3Samurai == nullptr) {
            SDL_LogWarn(0, "failed to load texture castleBuildingUpgrade3Samurai", SDL_GetError());
        }
        SDL_SetTextureScaleMode(castleBuildingUpgrade3Samurai, SDL_SCALEMODE_NEAREST);
        castleBuildingUpgrade4Samurai = IMG_LoadTexture(renderer, "assets/Samurai/CastleBuildingUpgrade4Samurai.png");
        if (castleBuildingUpgrade4Samurai == nullptr) {
            SDL_LogWarn(0, "failed to load texture castleBuildingUpgrade4Samurai", SDL_GetError());
        }
        SDL_SetTextureScaleMode(castleBuildingUpgrade4Samurai, SDL_SCALEMODE_NEAREST);
        castleBuildingUpgrade5Samurai = IMG_LoadTexture(renderer, "assets/Samurai/CastleBuildingUpgrade5Samurai.png");
        if (castleBuildingUpgrade5Samurai == nullptr) {
            SDL_LogWarn(0, "failed to load texture castleBuildingUpgrade5Samurai", SDL_GetError());
        }
        SDL_SetTextureScaleMode(castleBuildingUpgrade5Samurai, SDL_SCALEMODE_NEAREST);
        //villages
        villageBuildingUpgrade1Samurai = IMG_LoadTexture(renderer, "assets/Samurai/VillageBuildingUpgrade1Samurai.png");
        if (villageBuildingUpgrade1Samurai == nullptr) {
            SDL_LogWarn(0,"failed to load texture villageBuildingUpgrade1Samurai", SDL_GetError());
        }
        SDL_SetTextureScaleMode(villageBuildingUpgrade1Samurai, SDL_SCALEMODE_NEAREST);
        villageBuildingUpgrade2Samurai = IMG_LoadTexture(renderer, "assets/Samurai/VillageBuildingUpgrade2Samurai.png");
        if (villageBuildingUpgrade2Samurai == nullptr) {
            SDL_LogWarn(0,"failed to load texture villageBuildingUpgrade2Samurai", SDL_GetError());
        }
        SDL_SetTextureScaleMode(villageBuildingUpgrade2Samurai, SDL_SCALEMODE_NEAREST);
        villageBuildingUpgrade3Samurai = IMG_LoadTexture(renderer, "assets/Samurai/VillageBuildingUpgrade3Samurai.png");
        if (villageBuildingUpgrade3Samurai == nullptr) {
            SDL_LogWarn(0,"failed to load texture villageBuildingUpgrade3Samurai", SDL_GetError());
        }
        SDL_SetTextureScaleMode(villageBuildingUpgrade3Samurai, SDL_SCALEMODE_NEAREST);
        //Unavailable Slot
        gameNotAvailableSlotSamurai = IMG_LoadTexture(renderer, "assets/Samurai/BuildingNotAvailableSamurai.png");
        if (gameNotAvailableSlotSamurai == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameNotAvailableSlotSamurai", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameNotAvailableSlotSamurai, SDL_SCALEMODE_NEAREST);
        //Available Slot
        gameAvailableSlotSamurai = IMG_LoadTexture(renderer, "assets/Samurai/BuildingAvailableSamurai.png");
        if (gameAvailableSlotSamurai == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameAvailableSlotSamurai", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameAvailableSlotSamurai, SDL_SCALEMODE_NEAREST);

        //buildings types grouping Textures
        gameBuildingTypesGroupingMilitarySamurai = IMG_LoadTexture(renderer,"assets/Samurai/BuildingTypesGroupingMilitarySamurai.png");
        if (gameBuildingTypesGroupingMilitarySamurai == nullptr) {
            SDL_LogWarn(0,"failed to load texture gameBuildingTypesGroupingMilitarySamurai",SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingTypesGroupingMilitarySamurai, SDL_SCALEMODE_NEAREST);
        gameBuildingTypesGroupingAdvMilitarySamurai = IMG_LoadTexture(renderer, "assets/Samurai/BuildingTypesGroupingAdvMilitarySamurai.png");
        if (gameBuildingTypesGroupingAdvMilitarySamurai == nullptr) {
            SDL_LogWarn(0,"failed to load texture gameBuildingTypesGroupingAdvMilitarySamurai",SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingTypesGroupingAdvMilitarySamurai, SDL_SCALEMODE_NEAREST);
        gameBuildingTypesGroupingDefenceSamurai = IMG_LoadTexture(renderer, "assets/Samurai/BuildingTypesGroupingDefenceSamurai.png");
        if (gameBuildingTypesGroupingDefenceSamurai == nullptr) {
            SDL_LogWarn(0,"failed to load texture gameBuildingTypesGroupingDefenceSamurai", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingTypesGroupingDefenceSamurai, SDL_SCALEMODE_NEAREST);
        gameBuildingTypesGroupingEconomySamurai = IMG_LoadTexture(renderer, "assets/Samurai/BuildingTypesGroupingEconomySamurai.png");
        if (gameBuildingTypesGroupingEconomySamurai == nullptr) {
            SDL_LogWarn(0, "failed to load texture of gameBuildingTypesGroupingEconomySamurai", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingTypesGroupingEconomySamurai, SDL_SCALEMODE_NEAREST);
        gameBuildingTypesGroupingIndustrySamurai = IMG_LoadTexture(renderer, "assets/Samurai/BuildingTypesGroupingIndustrySamurai.png");
        if (gameBuildingTypesGroupingIndustrySamurai == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameBuildingTypesGroupingIndustrySamurai", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingTypesGroupingIndustrySamurai, SDL_SCALEMODE_NEAREST);
        gameBuildingTypesGroupingReligionSamurai = IMG_LoadTexture(renderer, "assets/Samurai/BuildingTypesGroupingReligionSamurai.png");
        if (gameBuildingTypesGroupingReligionSamurai == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameBuildingTypesGroupingReligionSamurai",SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameBuildingTypesGroupingReligionSamurai, SDL_SCALEMODE_NEAREST);

        //Buildings
        //Military
        buildingTypeTextures[BuildingType::SwordSchool_T1] = IMG_LoadTexture(renderer, "assets/Samurai/SwordSchoolTier1.png");
        if (buildingTypeTextures[BuildingType::SwordSchool_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SwordSchool_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SwordSchool_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::SwordSchool_T2] = IMG_LoadTexture(renderer, "assets/Samurai/SwordSchoolTier2.png");
        if (buildingTypeTextures[BuildingType::SwordSchool_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SwordSchool_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SwordSchool_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::SwordSchool_T3] = IMG_LoadTexture(renderer, "assets/Samurai/SwordSchoolTier3.png");
        if (buildingTypeTextures[BuildingType::SwordSchool_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SwordSchool_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SwordSchool_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::ArcheryDojo_T1] = IMG_LoadTexture(renderer, "assets/Samurai/ArcheryDojoTier1.png");
        if (buildingTypeTextures[BuildingType::ArcheryDojo_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture ArcheryDojo_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::ArcheryDojo_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::ArcheryDojo_T2] = IMG_LoadTexture(renderer, "assets/Samurai/ArcheryDojoTier2.png");
        if (buildingTypeTextures[BuildingType::ArcheryDojo_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture ArcheryDojo_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::ArcheryDojo_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::ArcheryDojo_T3] = IMG_LoadTexture(renderer, "assets/Samurai/ArcheryDojoTier3.png");
        if (buildingTypeTextures[BuildingType::ArcheryDojo_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture ArcheryDojo_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::ArcheryDojo_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::WarhorseStable_T1] = IMG_LoadTexture(renderer, "assets/Samurai/WarhorseStableTier1.png");
        if (buildingTypeTextures[BuildingType::WarhorseStable_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture WarhorseStable_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::WarhorseStable_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::WarhorseStable_T2] = IMG_LoadTexture(renderer, "assets/Samurai/WarhorseStableTier2.png");
        if (buildingTypeTextures[BuildingType::WarhorseStable_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture WarhorseStable_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::WarhorseStable_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::WarhorseStable_T3] = IMG_LoadTexture(renderer, "assets/Samurai/WarhorseStableTier3.png");
        if (buildingTypeTextures[BuildingType::WarhorseStable_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture WarhorseStable_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::WarhorseStable_T3], SDL_SCALEMODE_NEAREST);

        //Adv Military
        buildingTypeTextures[BuildingType::SiegeEngineerWorkshop_T4] = IMG_LoadTexture(renderer, "assets/Samurai/SiegeEngineerWorkshopTier4.png");
        if (buildingTypeTextures[BuildingType::SiegeEngineerWorkshop_T4] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SiegeEngineerWorkshop_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SiegeEngineerWorkshop_T4], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::SiegeEngineerWorkshop_T5] = IMG_LoadTexture(renderer, "assets/Samurai/SiegeEngineerWorkshopTier5.png");
        if (buildingTypeTextures[BuildingType::SiegeEngineerWorkshop_T5] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SiegeEngineerWorkshop_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SiegeEngineerWorkshop_T5], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::GunSmith_T4] = IMG_LoadTexture(renderer,"assets/Samurai/GunSmithTier4.png");
        if (buildingTypeTextures[BuildingType::GunSmith_T4] == nullptr) {
            SDL_LogWarn(0, "failed to load texture GunSmith_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::GunSmith_T4], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::GunSmith_T5] = IMG_LoadTexture(renderer,"assets/Samurai/GunSmithTier5.png");
        if (buildingTypeTextures[BuildingType::GunSmith_T5] == nullptr) {
            SDL_LogWarn(0, "failed to load texture GunSmith_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::GunSmith_T5], SDL_SCALEMODE_NEAREST);

        //Defence
        buildingTypeTextures[BuildingType::FortifiedCastle_T3] = IMG_LoadTexture(renderer, "assets/Samurai/FortifiedCastleTier3.png");
        if (buildingTypeTextures[BuildingType::FortifiedCastle_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture FortifiedCastle_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::FortifiedCastle_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::FortifiedCastle_T4] = IMG_LoadTexture(renderer, "assets/Samurai/FortifiedCastleTier4.png");
        if (buildingTypeTextures[BuildingType::FortifiedCastle_T4] == nullptr) {
            SDL_LogWarn(0, "failed to load texture FortifiedCastle_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::FortifiedCastle_T4], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::FortifiedCastle_T5] = IMG_LoadTexture(renderer, "assets/Samurai/FortifiedCastleTier5.png");
        if (buildingTypeTextures[BuildingType::FortifiedCastle_T5] == nullptr) {
            SDL_LogWarn(0, "failed to load texture FortifiedCastle_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::FortifiedCastle_T5], SDL_SCALEMODE_NEAREST);

        //Economy
        //warehouse
        buildingTypeTextures[BuildingType::SamuraiWareHouse_T3] = IMG_LoadTexture(renderer, "assets/Samurai/WareHouseTier3.png");
        if (buildingTypeTextures[BuildingType::SamuraiWareHouse_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiWareHouse_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiWareHouse_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiWareHouse_T4] = IMG_LoadTexture(renderer, "assets/Samurai/WareHouseTier4.png");
        if (buildingTypeTextures[BuildingType::SamuraiWareHouse_T4]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiWareHouse_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiWareHouse_T4], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiWareHouse_T5] = IMG_LoadTexture(renderer, "assets/Samurai/WareHouseTier5.png");
        if (buildingTypeTextures[BuildingType::SamuraiWareHouse_T5]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiWareHouse_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiWareHouse_T5], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::SamuraiMint_T2] = IMG_LoadTexture(renderer, "assets/Samurai/MintTier2.png");
        if (buildingTypeTextures[BuildingType::SamuraiMint_T2]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiMint_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiMint_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiMint_T3] = IMG_LoadTexture(renderer, "assets/Samurai/MintTier3.png");
        if (buildingTypeTextures[BuildingType::SamuraiMint_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiMint_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiMint_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiMint_T4] = IMG_LoadTexture(renderer, "assets/Samurai/MintTier4.png");
        if (buildingTypeTextures[BuildingType::SamuraiMint_T4]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiMint_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiMint_T4], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiTavern_T1] = IMG_LoadTexture(renderer, "assets/Samurai/TavernTier1.png");
        if (buildingTypeTextures[BuildingType::SamuraiTavern_T1]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiTavern_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiTavern_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::Market_T1] = IMG_LoadTexture(renderer, "assets/Samurai/MarketTier1.png");
        if (buildingTypeTextures[BuildingType::Market_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture Market_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Market_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::Market_T2] = IMG_LoadTexture(renderer, "assets/Samurai/MarketTier2.png");
        if (buildingTypeTextures[BuildingType::Market_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture Market_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Market_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::PeasantrySamuraiGrowth_T1] = IMG_LoadTexture(renderer, "assets/Samurai/PeasantryGrowthTier1.png");
        if (buildingTypeTextures[BuildingType::PeasantrySamuraiGrowth_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture PeasantrySamuraiGrowth_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::PeasantrySamuraiGrowth_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::PeasantrySamuraiGrowth_T2] = IMG_LoadTexture(renderer, "assets/Samurai/PeasantryGrowthTier2.png");
        if (buildingTypeTextures[BuildingType::PeasantrySamuraiGrowth_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture PeasantrySamuraiGrowth_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::PeasantrySamuraiGrowth_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::PeasantrySamuraiGrowth_T3] = IMG_LoadTexture(renderer, "assets/Samurai/PeasantryGrowthTier3.png");
        if (buildingTypeTextures[BuildingType::PeasantrySamuraiGrowth_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture PeasantrySamuraiGrowth_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::PeasantrySamuraiGrowth_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::NobilitySamuraiEstate_T1] = IMG_LoadTexture(renderer, "assets/Samurai/NobilityGrowthTier1.png");
        if (buildingTypeTextures[BuildingType::NobilitySamuraiEstate_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture NobilitySamuraiEstate_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::NobilitySamuraiEstate_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::NobilitySamuraiEstate_T2] = IMG_LoadTexture(renderer, "assets/Samurai/NobilityGrowthTier2.png");
        if (buildingTypeTextures[BuildingType::NobilitySamuraiEstate_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture NobilitySamuraiEstate_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::NobilitySamuraiEstate_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::NobilitySamuraiEstate_T3] = IMG_LoadTexture(renderer, "assets/Samurai/NobilityGrowthTier3.png");
        if (buildingTypeTextures[BuildingType::NobilitySamuraiEstate_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture NobilitySamuraiEstate_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::NobilitySamuraiEstate_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiGranary_T3] = IMG_LoadTexture(renderer, "assets/Samurai/GranaryTier3.png");
        if (buildingTypeTextures[BuildingType::SamuraiGranary_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiGranary_T3", SDL_GetError);
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiGranary_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiGranary_T4] = IMG_LoadTexture(renderer, "assets/Samurai/GranaryTier4.png");
        if (buildingTypeTextures[BuildingType::SamuraiGranary_T4] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiGranary_T4", SDL_GetError);
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiGranary_T4], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiGranary_T5] = IMG_LoadTexture(renderer, "assets/Samurai/GranaryTier5.png");
        if (buildingTypeTextures[BuildingType::SamuraiGranary_T5] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiGranary_T5", SDL_GetError);
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiGranary_T5], SDL_SCALEMODE_NEAREST);

        //Industry
        buildingTypeTextures[BuildingType::SamuraiOilPress_T1] = IMG_LoadTexture(renderer, "assets/Samurai/OilPressTier1.png");
        if (buildingTypeTextures[BuildingType::SamuraiOilPress_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiOilPress_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiOilPress_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiOilPress_T2] = IMG_LoadTexture(renderer, "assets/Samurai/OilPressTier2.png");
        if (buildingTypeTextures[BuildingType::SamuraiOilPress_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiOilPress_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiOilPress_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::SamuraiCarpentry_T1] = IMG_LoadTexture(renderer, "assets/Samurai/CarpentryTier1.png");
        if (buildingTypeTextures[BuildingType::SamuraiCarpentry_T1]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiCarpentry_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiCarpentry_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiCarpentry_T2] = IMG_LoadTexture(renderer, "assets/Samurai/CarpentryTier2.png");
        if (buildingTypeTextures[BuildingType::SamuraiCarpentry_T2]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiCarpentry_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiCarpentry_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiTextile_T1] = IMG_LoadTexture(renderer, "assets/Samurai/TextileTier1.png");
        if (buildingTypeTextures[BuildingType::SamuraiTextile_T1]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiTextile_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiTextile_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiTextile_T2] = IMG_LoadTexture(renderer, "assets/Samurai/TextileTier2.png");
        if (buildingTypeTextures[BuildingType::SamuraiTextile_T2]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiTextile_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiTextile_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiTextile_T3] = IMG_LoadTexture(renderer, "assets/Samurai/TextileTier3.png");
        if (buildingTypeTextures[BuildingType::SamuraiTextile_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiTextile_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiTextile_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::SamuraiArtisan_T1] = IMG_LoadTexture(renderer, "assets/Samurai/ArtisanTier1.png");
        if (buildingTypeTextures[BuildingType::SamuraiArtisan_T1]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiArtisan_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiArtisan_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiArtisan_T2] = IMG_LoadTexture(renderer, "assets/Samurai/ArtisanTier2.png");
        if (buildingTypeTextures[BuildingType::SamuraiArtisan_T2]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiArtisan_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiArtisan_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiArtisan_T3] = IMG_LoadTexture(renderer, "assets/Samurai/ArtisanTier3.png");
        if (buildingTypeTextures[BuildingType::SamuraiArtisan_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiArtisan_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiArtisan_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::SamuraiTinsmith_T2] = IMG_LoadTexture(renderer, "assets/Samurai/TinSmithTier2.png");
        if (buildingTypeTextures[BuildingType::SamuraiTinsmith_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiTinsmith_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiTinsmith_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiTinsmith_T3] = IMG_LoadTexture(renderer, "assets/Samurai/TinSmithTier3.png");
        if (buildingTypeTextures[BuildingType::SamuraiTinsmith_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiTinsmith_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiTinsmith_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiTinsmith_T4] = IMG_LoadTexture(renderer, "assets/Samurai/TinSmithTier4.png");
        if (buildingTypeTextures[BuildingType::SamuraiTinsmith_T4] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiTinsmith_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiTinsmith_T4], SDL_SCALEMODE_NEAREST);



        buildingTypeTextures[BuildingType::SamuraiForge_T3] = IMG_LoadTexture(renderer, "assets/Samurai/ForgeTier3.png");
        if (buildingTypeTextures[BuildingType::SamuraiForge_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiForge_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiForge_T3],  SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiForge_T4] = IMG_LoadTexture(renderer, "assets/Samurai/ForgeTier4.png");
        if (buildingTypeTextures[BuildingType::SamuraiForge_T4]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiForge_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiForge_T4],  SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiForge_T5] = IMG_LoadTexture(renderer, "assets/Samurai/ForgeTier5.png");
        if (buildingTypeTextures[BuildingType::SamuraiForge_T5]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiForge_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiForge_T5],  SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiJeweller_T3] = IMG_LoadTexture(renderer, "assets/Samurai/JewellerTier3.png");
        if (buildingTypeTextures[BuildingType::SamuraiJeweller_T3]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiJeweller_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiJeweller_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiJeweller_T4] = IMG_LoadTexture(renderer, "assets/Samurai/JewellerTier4.png");
        if (buildingTypeTextures[BuildingType::SamuraiJeweller_T4]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiJeweller_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiJeweller_T4], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiJeweller_T5] = IMG_LoadTexture(renderer, "assets/Samurai/JewellerTier5.png");
        if (buildingTypeTextures[BuildingType::SamuraiJeweller_T5]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiJeweller_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiJeweller_T5], SDL_SCALEMODE_NEAREST);

        //Religion
        //reconstitution
        buildingTypeTextures[BuildingType::SamuraiHospital_T1] = IMG_LoadTexture(renderer, "assets/Samurai/HospitalTier1.png");
        if (buildingTypeTextures[BuildingType::SamuraiHospital_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiHospital_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiHospital_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::SamuraiHospital_T2] = IMG_LoadTexture(renderer, "assets/Samurai/HospitalTier2.png");
        if (buildingTypeTextures[BuildingType::SamuraiHospital_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiHospital_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiHospital_T2], SDL_SCALEMODE_NEAREST);
        //Tea dry Production
        buildingTypeTextures[BuildingType::SamuraiTeaDry_T1] = IMG_LoadTexture(renderer, "assets/Samurai/TeaDryTier1.png");
        if (buildingTypeTextures[BuildingType::SamuraiTeaDry_T1] == nullptr) {
            SDL_LogWarn(0,"failed to load texture SamuraiTeaDry_T1", SDL_GetError);
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiTeaDry_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiTeaDry_T2] = IMG_LoadTexture(renderer, "assets/Samurai/TeaDryTier2.png");
        if (buildingTypeTextures[BuildingType::SamuraiTeaDry_T2] == nullptr) {
            SDL_LogWarn(0,"failed to load texture SamuraiTeaDry_T2", SDL_GetError);
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiTeaDry_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiTeaDry_T3] = IMG_LoadTexture(renderer, "assets/Samurai/TeaDryTier3.png");
        if (buildingTypeTextures[BuildingType::SamuraiTeaDry_T3] == nullptr) {
            SDL_LogWarn(0,"failed to load texture SamuraiTeaDry_T3", SDL_GetError);
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiTeaDry_T3], SDL_SCALEMODE_NEAREST);
        //public order
        buildingTypeTextures[BuildingType::SamuraiChapel_T3] = IMG_LoadTexture(renderer, "assets/Samurai/ChapelTier3.png");
        if (buildingTypeTextures[BuildingType::SamuraiChapel_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiChapel_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiChapel_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiChapel_T4] = IMG_LoadTexture(renderer, "assets/Samurai/ChapelTier4.png");
        if (buildingTypeTextures[BuildingType::SamuraiChapel_T4] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiChapel_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiChapel_T4], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiChapel_T5] = IMG_LoadTexture(renderer, "assets/Samurai/ChapelTier5.png");
        if (buildingTypeTextures[BuildingType::SamuraiChapel_T5] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiChapel_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiChapel_T5], SDL_SCALEMODE_NEAREST);
        //Ports
        buildingTypeTextures[BuildingType::SamuraiMilitaryPort_T1] = IMG_LoadTexture(renderer, "assets/Samurai/MilitaryPortTier1.png");
        if (buildingTypeTextures[BuildingType::SamuraiMilitaryPort_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiMilitaryPort_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiMilitaryPort_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiMilitaryPort_T2] = IMG_LoadTexture(renderer, "assets/Samurai/MilitaryPortTier2.png");
        if (buildingTypeTextures[BuildingType::SamuraiMilitaryPort_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiMilitaryPort_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiMilitaryPort_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiMilitaryPort_T3] = IMG_LoadTexture(renderer, "assets/Samurai/MilitaryPortTier3.png");
        if (buildingTypeTextures[BuildingType::SamuraiMilitaryPort_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiMilitaryPort_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiMilitaryPort_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiMilitaryPort_T4] = IMG_LoadTexture(renderer, "assets/Samurai/MilitaryPortTier4.png");
        if (buildingTypeTextures[BuildingType::SamuraiMilitaryPort_T4] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiMilitaryPort_T4", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiMilitaryPort_T4], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiMilitaryPort_T5] = IMG_LoadTexture(renderer, "assets/Samurai/MilitaryPortTier5.png");
        if (buildingTypeTextures[BuildingType::SamuraiMilitaryPort_T5] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiMilitaryPort_T5", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiMilitaryPort_T5], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiFishingPort_T1] = IMG_LoadTexture(renderer, "assets/Samurai/FishingPortTier1.png");
        if (buildingTypeTextures[BuildingType::SamuraiFishingPort_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiFishingPort_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiFishingPort_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiFishingPort_T2] = IMG_LoadTexture(renderer, "assets/Samurai/FishingPortTier2.png");
        if (buildingTypeTextures[BuildingType::SamuraiFishingPort_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiFishingPort_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiFishingPort_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SamuraiFishingPort_T3] = IMG_LoadTexture(renderer, "assets/Samurai/FishingPortTier3.png");
        if (buildingTypeTextures[BuildingType::SamuraiFishingPort_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SamuraiFishingPort_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SamuraiFishingPort_T3], SDL_SCALEMODE_NEAREST);

        //Goods Managers
        gameGoodsManagerMinusTexture = IMG_LoadTexture(renderer, "assets/GoodsManagerMinusArrow.png");
        if (gameGoodsManagerMinusTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameGoodsManagerMinusTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameGoodsManagerMinusTexture, SDL_SCALEMODE_NEAREST);
        gameGoodsManagerPlusTexture = IMG_LoadTexture(renderer, "assets/GoodsManagerPlusArrow.png");
        if (gameGoodsManagerPlusTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameGoodsManagerPlusTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameGoodsManagerPlusTexture, SDL_SCALEMODE_NEAREST);
        goodsProductionManagerButtonTexture = IMG_LoadTexture(renderer, "assets/GoodsProductionManagerButton.png");
        if (goodsProductionManagerButtonTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture goodsProductionManagerButtonTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(goodsProductionManagerButtonTexture, SDL_SCALEMODE_NEAREST);
        diplomacyGoodsExportArrowIndicatorTexture = IMG_LoadTexture(renderer, "assets/ExportArrowIndicator.png");
        if (diplomacyGoodsExportArrowIndicatorTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture diplomacyGoodsExportArrowIndicatorTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(diplomacyGoodsExportArrowIndicatorTexture, SDL_SCALEMODE_NEAREST);
        diplomacyGoodsImportArrowIndicatorTexture = IMG_LoadTexture(renderer, "assets/ImportArrowIndicator.png");
        if (diplomacyGoodsImportArrowIndicatorTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture diplomacyGoodsExportArrowIndicatorTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(diplomacyGoodsImportArrowIndicatorTexture, SDL_SCALEMODE_NEAREST);
        //Goods Value Icon
        gameGoodsTradeValueTexture = IMG_LoadTexture(renderer, "assets/TradeValue.png");
        if (gameGoodsTradeValueTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameGoodsTradeValueTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameGoodsTradeValueTexture, SDL_SCALEMODE_NEAREST);

        //Military Port Icon
        gameMilitaryPortIconTexture = IMG_LoadTexture(renderer, "assets/MilitaryPortIcon.png");
        if (gameMilitaryPortIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameMilitaryPortIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameMilitaryPortIconTexture, SDL_SCALEMODE_NEAREST);

        //Mines Textures (Raw Buildings)
        //IronMine Texture
        buildingTypeTextures[BuildingType::IronMine_T1] = IMG_LoadTexture(renderer, "assets/RawBuildings/IronMineTier1.png");
        if (buildingTypeTextures[BuildingType::IronMine_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture IronMine_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::IronMine_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::IronMine_T2] = IMG_LoadTexture(renderer, "assets/RawBuildings/IronMineTier2.png");
        if (buildingTypeTextures[BuildingType::IronMine_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture IronMine_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::IronMine_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::IronMine_T3] = IMG_LoadTexture(renderer, "assets/RawBuildings/IronMineTier3.png");
        if (buildingTypeTextures[BuildingType::IronMine_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture IronMine_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::IronMine_T3], SDL_SCALEMODE_NEAREST);

        //GoldMine
        buildingTypeTextures[BuildingType::GoldMine_T1] = IMG_LoadTexture(renderer, "assets/RawBuildings/GoldMineTier1.png");
        if (buildingTypeTextures[BuildingType::GoldMine_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture GoldMine_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::GoldMine_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::GoldMine_T2] = IMG_LoadTexture(renderer, "assets/RawBuildings/GoldMineTier2.png");
        if (buildingTypeTextures[BuildingType::GoldMine_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture GoldMine_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::GoldMine_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::GoldMine_T3] = IMG_LoadTexture(renderer, "assets/RawBuildings/GoldMineTier3.png");
        if (buildingTypeTextures[BuildingType::GoldMine_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture GoldMine_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::GoldMine_T3], SDL_SCALEMODE_NEAREST);

        //CopperMine
        buildingTypeTextures[BuildingType::CopperMine_T1] = IMG_LoadTexture(renderer, "assets/RawBuildings/CopperMineTier1.png");
        if (buildingTypeTextures[BuildingType::CopperMine_T1]==nullptr) {
            SDL_LogWarn(0, "failed to load texture CopperMine_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::CopperMine_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::CopperMine_T2] = IMG_LoadTexture(renderer, "assets/RawBuildings/CopperMineTier2.png");
        if (buildingTypeTextures[BuildingType::CopperMine_T2]==nullptr) {
            SDL_LogWarn(0, "failed to load texture CopperMine_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::CopperMine_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::CopperMine_T3] = IMG_LoadTexture(renderer, "assets/RawBuildings/CopperMineTier3.png");
        if (buildingTypeTextures[BuildingType::CopperMine_T3]==nullptr) {
            SDL_LogWarn(0, "failed to load texture CopperMine_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::CopperMine_T3], SDL_SCALEMODE_NEAREST);

        //SilverMine
        buildingTypeTextures[BuildingType::SilverMine_T1] = IMG_LoadTexture(renderer, "assets/RawBuildings/SilverMineTier1.png");
        if (buildingTypeTextures[BuildingType::SilverMine_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SilverMine_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SilverMine_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SilverMine_T2] = IMG_LoadTexture(renderer, "assets/RawBuildings/SilverMineTier2.png");
        if (buildingTypeTextures[BuildingType::SilverMine_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SilverMine_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SilverMine_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SilverMine_T3] = IMG_LoadTexture(renderer, "assets/RawBuildings/SilverMineTier3.png");
        if (buildingTypeTextures[BuildingType::SilverMine_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SilverMine_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SilverMine_T3], SDL_SCALEMODE_NEAREST);

        //Tin Mine
        buildingTypeTextures[BuildingType::TinMine_T1] = IMG_LoadTexture(renderer, "assets/RawBuildings/TinMineTier1.png");
        if (buildingTypeTextures[BuildingType::TinMine_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture TinMine_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::TinMine_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::TinMine_T2] = IMG_LoadTexture(renderer, "assets/RawBuildings/TinMineTier2.png");
        if (buildingTypeTextures[BuildingType::TinMine_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture TinMine_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::TinMine_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::TinMine_T3] = IMG_LoadTexture(renderer, "assets/RawBuildings/TinMineTier3.png");
        if (buildingTypeTextures[BuildingType::TinMine_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture TinMine_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::TinMine_T3], SDL_SCALEMODE_NEAREST);

        //Lumber Camp
        buildingTypeTextures[BuildingType::LumberCamp_T1] = IMG_LoadTexture(renderer, "assets/RawBuildings/LumberCampTier1.png");
        if (buildingTypeTextures[BuildingType::LumberCamp_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture LumberCamp_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::LumberCamp_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::LumberCamp_T2] = IMG_LoadTexture(renderer, "assets/RawBuildings/LumberCampTier2.png");
        if (buildingTypeTextures[BuildingType::LumberCamp_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture LumberCamp_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::LumberCamp_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::LumberCamp_T3] = IMG_LoadTexture(renderer, "assets/RawBuildings/LumberCampTier3.png");
        if (buildingTypeTextures[BuildingType::LumberCamp_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture LumberCamp_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::LumberCamp_T3], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SheepPasture_T1] = IMG_LoadTexture(renderer, "assets/RawBuildings/SheepPastureTier1.png");
        if (buildingTypeTextures[BuildingType::SheepPasture_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SheepPasture_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SheepPasture_T1], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SheepPasture_T2] = IMG_LoadTexture(renderer, "assets/RawBuildings/SheepPastureTier2.png");
        if (buildingTypeTextures[BuildingType::SheepPasture_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SheepPasture_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SheepPasture_T2], SDL_SCALEMODE_NEAREST);
        buildingTypeTextures[BuildingType::SheepPasture_T3] = IMG_LoadTexture(renderer, "assets/RawBuildings/SheepPastureTier3.png");
        if (buildingTypeTextures[BuildingType::SheepPasture_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SheepPasture_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SheepPasture_T3], SDL_SCALEMODE_NEAREST);

        // RESOURCES TEXTURES
        gameResourceFishIconTexture = IMG_LoadTexture(renderer, "assets/Resources/FishIcon.png");
        if (gameResourceFishIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameResourceFishIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourceFishIconTexture, SDL_SCALEMODE_NEAREST);
        gameResourceIronIconTexture = IMG_LoadTexture(renderer, "assets/Resources/IronIcon.png");
        if (gameResourceIronIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameResourceIronIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourceIronIconTexture, SDL_SCALEMODE_NEAREST);
        gameResourceGoldIconTexture = IMG_LoadTexture(renderer, "assets/Resources/GoldIcon.png");
        if (gameResourceGoldIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameResourceGoldIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourceGoldIconTexture, SDL_SCALEMODE_NEAREST);
        gameResourceSilverIconTexture = IMG_LoadTexture(renderer, "assets/Resources/SilverIcon.png");
        if (gameResourceSilverIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameResourceSilverIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourceSilverIconTexture, SDL_SCALEMODE_NEAREST);
        gameResourceCopperIconTexture = IMG_LoadTexture(renderer, "assets/Resources/CopperIcon.png");
        if (gameResourceCopperIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameResourceCopperIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourceCopperIconTexture, SDL_SCALEMODE_NEAREST);
        gameResourceTinIconTexture = IMG_LoadTexture(renderer, "assets/Resources/TinIcon.png");
        if (gameResourceTinIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameResourceTinInconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourceTinIconTexture, SDL_SCALEMODE_NEAREST);
        gameResourceLumberIconTexture = IMG_LoadTexture(renderer, "assets/Resources/LumberIcon.png");
        if (gameResourceLumberIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameResourceLumberIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourceLumberIconTexture, SDL_SCALEMODE_NEAREST);
        gameResourceWoolIconTexture = IMG_LoadTexture(renderer, "assets/Resources/WoolIcon.png");
        if (gameResourceWoolIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameResourceWoolIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourceWoolIconTexture, SDL_SCALEMODE_NEAREST);
        //religion raw goods
        gameResourceCandleIconTexture = IMG_LoadTexture(renderer, "assets/Resources/CandleIcon.png");
        if (gameResourceCandleIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameResourceCandleIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourceCandleIconTexture, SDL_SCALEMODE_NEAREST);
        gameResourceBeerIconTexture = IMG_LoadTexture(renderer, "assets/Resources/BeerIcon.png");
        if (gameResourceBeerIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameResourceBeerIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourceBeerIconTexture, SDL_SCALEMODE_NEAREST);
        gameResourceGreenTeaIconTexture = IMG_LoadTexture(renderer, "assets/Resources/GreenTeaIcon.png");
        if (gameResourceGreenTeaIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to laod texture gameResourceGreenTeaIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourceGreenTeaIconTexture, SDL_SCALEMODE_NEAREST);

        //Transformed goods
        gameResourceFishOilIconTexture = IMG_LoadTexture(renderer, "assets/Resources/FishOilIcon.png");
        if (gameResourceFishOilIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameResourceFishOilIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourceFishOilIconTexture, SDL_SCALEMODE_NEAREST);
        gameResourceHardWoodIconTexture = IMG_LoadTexture(renderer, "assets/Resources/HardWoodIcon.png");
        if (gameResourceHardWoodIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameResourceHardWoodIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourceHardWoodIconTexture, SDL_SCALEMODE_NEAREST);
        gameResourceToolsIconTexture = IMG_LoadTexture(renderer, "assets/Resources/ToolsIcon.png");
        if (gameResourceToolsIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameResourceToolsIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourceToolsIconTexture, SDL_SCALEMODE_NEAREST);
        gameResourceCopperJewleryIconTexture = IMG_LoadTexture(renderer, "assets/Resources/CopperJewleryIcon.png");
        if (gameResourceCopperJewleryIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameResourceCopperJewleryIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourceCopperJewleryIconTexture, SDL_SCALEMODE_NEAREST);
        gameResourcePewterIconTexture = IMG_LoadTexture(renderer, "assets/Resources/PewterIcon.png");
        if (gameResourcePewterIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameResourcePewterIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourcePewterIconTexture, SDL_SCALEMODE_NEAREST);
        gameResourceSilverCoinsIconTexture = IMG_LoadTexture(renderer, "assets/Resources/SilverCoinsIcon.png");
        if (gameResourceSilverCoinsIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameResourceSilverCoinsIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourceSilverCoinsIconTexture, SDL_SCALEMODE_NEAREST);
        gameResourceGoldJewleryIconTexture = IMG_LoadTexture(renderer, "assets/Resources/GoldJewleryIcon.png");
        if (gameResourceGoldJewleryIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameResourceGoldJewleryIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourceGoldJewleryIconTexture, SDL_SCALEMODE_NEAREST);
        gameResourceTextileIconTexture = IMG_LoadTexture(renderer, "assets/Resources/TextileIcon.png");
        if (gameResourceTextileIconTexture == nullptr) {
            SDL_LogWarn(0, "failed to load texture gameResourceTextileIconTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameResourceTextileIconTexture, SDL_SCALEMODE_NEAREST);

}

inline void GameApp::DestroyTextures() {
    // Each group is a list of pointers to the member variables, destroyed in one loop
    SDL_Texture** singles[] = {
        // Menu / faction select / minimap
        &chooseFactionKnightIcon, &chooseFactionVikingIcon, &chooseFactionSamuraiIcon,
        &tileMapTexture,

        // Banners
        &provinceKnightBannerTexture, &provinceVikingBannerTexture, &provinceSamuraiBannerTexture,
        &settlementKnightBannerTexture, &settlementVikingBannerTexture, &settlementSamuraiBannerTexture,

        // General UI
        &provinceTextureUIBuilding, &provinceTextureUIGarrison, &hammerUIBuildingUpgradeTexture,
        &gameNextTurnTexture, &gameCoinMoneyTexture, &gameTurnAmountTexture,
        &gameToggleTaxSettlementTrue, &gameToggleTaxSettlementFalse,
        &gamePublicOrderPositifTexture, &gamePublicOrderNegatifTexture, &gamePublicOrderNeutralTexture,
        &gameFoodIconUi, &gamePeasantryIconUi, &gameNobilityIconUi, &gameClergyIconUi,
        &gamePositiveUiIcon, &gameNegativeUiIcon, &gamePopulationGrowth,
        &gameFoodStorageUiIcon, &gameGoodsStorageUiIcon,
        &gameSeasonWinterIconUiTexture, &gameSeasonSpringIconUiTexture,
        &gameSeasonSummerIconUiTexture, &gameSeasonAutumnIconUiTexture,
        &gameDestroyBuildingButtonIconUi, &gameRepairBuildingButtonIconUi, &gameBuildingDamagedIconUi,
        &gameMilitaryPortIconTexture, &gameReturnButtons,

        // Top-right panel buttons
        &decreesPannelTexture, &winConditionPannelTexture, &treasuryPannelTexture,
        &technologyPannelTexture, &diplomacyPannelTexture, &familyHierarchyPannelTexture,
        &cameraResetPannelTexture,

        // Goods manager
        &gameGoodsManagerMinusTexture, &gameGoodsManagerPlusTexture,
        &goodsProductionManagerButtonTexture, &gameGoodsTradeValueTexture,
        &diplomacyGoodsExportArrowIndicatorTexture, &diplomacyGoodsImportArrowIndicatorTexture,

        // Win conditions / treasury
        &gameWinConditionConquestShortIconTexture, &gameWinConditionConquestLongIconTexture,
        &gameWinConditionConstructionShortIconTexture, &gameWinConditionConstructionLongIconTexture,
        &gameWinConditionTradeShortIconTexture, &gameWinConditionTradeLongIconTexture,
        &gameWinConditionUltimateIconTexture,
        &gameTreasuryChestIconTexture, &gameTreasuryTaxRateIndicatorTexture,

        // Decrees
        &gameDecree1KnightTexture, &gameDecree2KnightTexture, &gameDecree3KnightTexture,
        &gameDecree1VikingTexture, &gameDecree2VikingTexture, &gameDecree3VikingTexture,
        &gameDecree1SamuraiTexture, &gameDecree2SamuraiTexture, &gameDecree3SamuraiTexture,

        // Character portraits
        &babyCharacterPortraitTexture, &youngMaleCharacterPortraitTexture, &youngFemaleCharacterPortraitTexture,
        &maleVariant1CharacterPortraitTexture, &maleOldVariant1CharacterPortraitTexture,
        &maleVariant2CharacterPortraitTexture, &maleOldVariant2CharacterPortraitTexture,
        &maleVariant3CharacterPortraitTexture, &maleOldVariant3CharacterPortraitTexture,
        &femaleVariant1CharacterPortraitTexture, &femaleOldVariant1CharacterPortraitTexture,
        &femaleVariant2CharacterPortraitTexture, &femaleOldVariant2CharacterPortraitTexture,
        &femaleVariant3CharacterPortraitTexture, &femaleOldVariant3CharacterPortraitTexture,

        // Diplomacy
        &tradeDiplomacyIconTexture, &vassalDiplomacyIconTexture,
        &defensiveAllianceDiplomacyIconTexture, &militaryAllianceDiplomacyIconTexture,
        &warDiplomacyIconTexture, &friendshipDiplomacyIconTexture, &militaryAccessDiplomacyIconTexture,
        &smallGiftDiplomacyIconTexture, &mediumGiftDiplomacyIconTexture, &largeGiftDiplomacyIconTexture,
        &gameGiftSelectedCheckTexture, &gameDemandMinusArrowTexture, &gameDemandPlusArrowTexture,
        &gameStartDiplomacyTexture, &gameCounterDealTexture, &gameMakeDealTexture, &gameQuitDealTexture,

        // Resources (raw)
        &gameResourceFishIconTexture, &gameResourceIronIconTexture, &gameResourceGoldIconTexture,
        &gameResourceSilverIconTexture, &gameResourceCopperIconTexture, &gameResourceTinIconTexture,
        &gameResourceLumberIconTexture, &gameResourceWoolIconTexture,
        &gameResourceCandleIconTexture, &gameResourceBeerIconTexture, &gameResourceGreenTeaIconTexture,
        // Resources (transformed)
        &gameResourceFishOilIconTexture, &gameResourceHardWoodIconTexture, &gameResourceTextileIconTexture,
        &gameResourceToolsIconTexture, &gameResourceCopperJewleryIconTexture, &gameResourcePewterIconTexture,
        &gameResourceSilverCoinsIconTexture, &gameResourceGoldJewleryIconTexture,

        // ~ KNIGHT ~
        &capitalBuildingUpgrade1Knight, &capitalBuildingUpgrade2Knight, &capitalBuildingUpgrade3Knight,
        &capitalBuildingUpgrade4Knight, &capitalBuildingUpgrade5Knight,
        &castleBuildingUpgrade1Knight, &castleBuildingUpgrade2Knight, &castleBuildingUpgrade3Knight,
        &castleBuildingUpgrade4Knight, &castleBuildingUpgrade5Knight,
        &villageBuildingUpgrade1Knight, &villageBuildingUpgrade2Knight, &villageBuildingUpgrade3Knight,
        &gameNotAvailableSlotKnight, &gameAvailableSlotKnight,
        &gameBuildingTypesGroupingMilitaryKnight, &gameBuildingTypesGroupingAdvMilitaryKnight,
        &gameBuildingTypesGroupingDefenceKnight, &gameBuildingTypesGroupingEconomyKnight,
        &gameBuildingTypesGroupingIndustryKnight, &gameBuildingTypesGroupingReligionKnight,

        // ~ VIKING ~
        &capitalBuildingUpgrade1Viking, &capitalBuildingUpgrade2Viking, &capitalBuildingUpgrade3Viking,
        &capitalBuildingUpgrade4Viking, &capitalBuildingUpgrade5Viking,
        &castleBuildingUpgrade1Viking, &castleBuildingUpgrade2Viking, &castleBuildingUpgrade3Viking,
        &castleBuildingUpgrade4Viking, &castleBuildingUpgrade5Viking,
        &villageBuildingUpgrade1Viking, &villageBuildingUpgrade2Viking, &villageBuildingUpgrade3Viking,
        &gameNotAvailableSlotViking, &gameAvailableSlotViking,
        &gameBuildingTypesGroupingMilitaryViking, &gameBuildingTypesGroupingAdvMilitaryViking,
        &gameBuildingTypesGroupingDefenceViking, &gameBuildingTypesGroupingEconomyViking,
        &gameBuildingTypesGroupingIndustryViking, &gameBuildingTypesGroupingReligionViking,

        // ~ SAMURAI ~
        &capitalBuildingUpgrade1Samurai, &capitalBuildingUpgrade2Samurai, &capitalBuildingUpgrade3Samurai,
        &capitalBuildingUpgrade4Samurai, &capitalBuildingUpgrade5Samurai,
        &castleBuildingUpgrade1Samurai, &castleBuildingUpgrade2Samurai, &castleBuildingUpgrade3Samurai,
        &castleBuildingUpgrade4Samurai, &castleBuildingUpgrade5Samurai,
        &villageBuildingUpgrade1Samurai, &villageBuildingUpgrade2Samurai, &villageBuildingUpgrade3Samurai,
        &gameNotAvailableSlotSamurai, &gameAvailableSlotSamurai,
        &gameBuildingTypesGroupingMilitarySamurai, &gameBuildingTypesGroupingAdvMilitarySamurai,
        &gameBuildingTypesGroupingDefenceSamurai, &gameBuildingTypesGroupingEconomySamurai,
        &gameBuildingTypesGroupingIndustrySamurai, &gameBuildingTypesGroupingReligionSamurai,
    };
    for (SDL_Texture** t : singles) DestroyTex(*t);

    // Maps
    for (auto& [type, tex] : buildingTypeTextures) DestroyTex(tex);
    for (auto& [key,  tex] : settlementTextureCampaign) DestroyTex(tex);
    for (auto& [type, tex] : worldEventsImageTextures) DestroyTex(tex);
    for (auto& [type, tex] : worldEventsIconTextures) DestroyTex(tex);
    buildingTypeTextures.clear();
    settlementTextureCampaign.clear();
    worldEventsImageTextures.clear();
    worldEventsIconTextures.clear();
}


#endif //TOTALBATTLE2D_TEXTURELOADER_H
