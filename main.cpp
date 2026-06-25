
#define SDL_MAIN_USE_CALLBACKS

//La librairie
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <cmath>
//les classes
#include "State.h"
#include "Entity.h"
#include "TileMap.h"
#include "Camera.h"
#include "Province.h"
#include "Settlements.h"
#include "Player.h"

/*
 * 0.2.0
 * POPULATION SYSTEM
 * (population is affected by food storage system)
 * Having population texture positive and negative
 * Having money and food texture positive and negative
 * Update Buildings info in UI +/-
 *
 *---------------------------------------------
 * 0.2.5
 * WORLD EVENTS (plague, exceed food production, thunder) + SEASONS + DATE (12 turns a year) 3 turn per season
 * --------------------------------------------
 * 0.3.0
 * DIPLOMACY + RESSOURCE SETTLEMENTS/BUILDINGS
 * MINE, SPICE, FISH, medicine plants, hunting meat,
 * THE RESSOURCES ARE STORED IN
 * --------------------------------------------
 * 0.3.5
 * TRADE/MILITARY PORTS, COMMERCE , EXCHANGE FOR DIPLOMACY
 * EXANGE MONEY OR RESSOURCES FOR FOOD. IN TRADE.
 * If a main settlement or village is close to the sea it has a port. For villages/Fishing port, and Main settlements military port.
 * --------------------------------------------
 * 0.5.0
 * REAL TIME BATTLES FOCUS + NAVAL BATTLES
 *----------------------------------------------
 *
 *TO GET A PLAYABLE CAMPAIGN :
 *Population System
 *Roads
 *Technology
 * 1 Special mechanic per factio
 * Introduction narrator
 * camera movement at the start (cinematic vibe, black rect under and top)
 *
 *
 *----------------------------------------------
 *Character +Movement Maximum per turn
 *
 *Finished:
 *TileMap
 *Camera (missing mouse touch edge)
 * Buildings of a region + UI of that region
 * Money System
 * Turn base system
 * food storage System
 * public order works with food storage system
 * Money UI mouse hovered -> to describe the different money income and upkeep
 * Fix a bug when a building is pending you can buy an other one + if a pending building is clicked on->its refounded and removed when pending
* fix Textures errors
* ReadMe -> Github
* Hovered Population

 */



//Fonction FPS
static Uint32 TimerCallback(void *userdata, SDL_TimerID timerID, Uint32 interval) {
    bool *updateFlag = static_cast<bool *>(userdata);
    *updateFlag = true;
    return interval;
}
//to render a circle
struct Circle { float circleX, circleY, radius; };

//rgb
Uint8 r = 0, g = 0, b = 0;
class GameApp final {
public:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Texture *spritesheet = nullptr;
    //Ajout du state Menu
    State StateActuel = State::Menu;
    float colorTime = 0.0f;
    //cursor
    SDL_Cursor *cursor = nullptr;

    //TEXT ET FONT
    // -> MENU <-
    TTF_Font *gameVersionFont = nullptr;
    TTF_Text *gameVersionText = nullptr;
    TTF_Font *gameInProgressFont = nullptr;
    TTF_Text * gameInProgressText = nullptr;
    TTF_Font *menuFont = nullptr;
    TTF_Text *menuText = nullptr;

    TTF_Font *StartFont = nullptr;
    TTF_Font *TutorialFont = nullptr;
    TTF_Font *OptionsFont = nullptr;
    TTF_Font *QuitFont = nullptr;
    TTF_Font *CreditsFont = nullptr;
    TTF_Text *textStart = nullptr;
    TTF_Text *textTutorial = nullptr;
    TTF_Text *textOptions = nullptr;
    TTF_Text *textQuit = nullptr;
    TTF_Text *textCredits = nullptr;

    //Bouton Menu
    SDL_FRect BoutonPlay = {760, 600, 400, 80};
    SDL_FRect BoutonTutorial = {785, 700, 350, 70};
    SDL_FRect BoutonOptions = {810, 790, 300, 60};
    SDL_FRect BoutonQuit = {835, 870, 250, 50};
    SDL_FRect BoutonCredits = {860, 940, 200, 40};

    // -> Choose Faction <-
    TTF_Font *factionSelectionTitleFont = nullptr;
    TTF_Text *factionSelectionTitleText = nullptr;
    TTF_Font *factionSelectionFactionBonusFont = nullptr;
    TTF_Text *factionSelectionFactionBonusText = nullptr;
    TTF_Font *factionSelectionGeneralKnightFont = nullptr;
    TTF_Font *factionSelectionGeneralVikingFont = nullptr;
    TTF_Font *factionSelectionGeneralSamuraiFont = nullptr;
    TTF_Text *factionSelectionGeneralKnightText = nullptr;
    TTF_Text *factionSelectionLoreknightText = nullptr;
    TTF_Text *factionSelectionGeneralVikingText = nullptr;
    TTF_Text *factionSelectionLoreVikingText = nullptr;
    TTF_Text *factionSelectionGeneralSamuraiText = nullptr;
    TTF_Text *factionSelectionLoreSamuraiText = nullptr;
    TTF_Text *factionSelectionStartCampaignText = nullptr;

    SDL_FRect BoutonKnight = {400, 150, 100,100};
    SDL_FRect BoutonViking = {900, 150, 100, 100};
    SDL_FRect BoutonSamurai = {1400, 150, 100, 100};
    SDL_FRect BoutonStartCampaign = {850, 1000, 250, 40};
    //Texture of the Buttons
    SDL_Texture *chooseFactionKnightIcon = nullptr;
    SDL_Texture *chooseFactionVikingIcon = nullptr;
    SDL_Texture *chooseFactionSamuraiIcon = nullptr;
    int selectedFaction = 0;

    // -> OPTION <-
    struct VolumeSlider {
        float x, y, width, height;  // volume bar
        float value;
        bool bCursorIsSliding = false;
    };
    //slider for the music
    VolumeSlider volumeMusicSlider = {650,500,600,20,0.5f};

    TTF_Font *optionsTitleFont = nullptr;
    TTF_Font *optionsMusicFont = nullptr;
    TTF_Text *optionsTitleText = nullptr;
    TTF_Text *optionsMusicText = nullptr;

    // -> GAME <-
    //kingdomNames
    TTF_Font *gameKingdomNameFont = nullptr;
    TTF_Text *gameKingdomKnightNameText = nullptr;
    TTF_Text *gameKingdomVikingNameText = nullptr;
    TTF_Text *gameKingdomSamuraiNameText = nullptr;
    TTF_Font *gameGeneralFont = nullptr;
    TTF_Text *gameCurrentMoneyUiText = nullptr;
    TTF_Text *gameAnticipatedMoneyUiText = nullptr;
    TTF_Font *gameCurrentFoodUiFont = nullptr;
    TTF_Text *gameCurrentFoodUiText = nullptr;
    TTF_Font *gameMoneyIndicatorUiFont = nullptr;
    TTF_Text *gameMoneyIndicatorUiText = nullptr;
    TTF_Font *gameFoodIndicatorUiFont = nullptr;
    TTF_Text *gameFoodIndicatorUiText = nullptr;
    TTF_Font *gamePopulationIndicatorUiFont = nullptr;
    TTF_Text *gamePopulationIndicatorUiText = nullptr;
    TTF_Font *gameCurrentPopulationUiFont = nullptr;
    TTF_Text *gameCurrentPopulationUiText = nullptr;
    TTF_Text *gameNumberOfTurnText = nullptr;
    TTF_Font *gameBuildingCostUIFont = nullptr;
    TTF_Text *gameBuildingCostUIText = nullptr;
    TTF_Font *gameBuildingConstructionTimeFont = nullptr;
    TTF_Text *gameBuildingConstructionTimeText = nullptr;
    TTF_Font *gameBuildingCategoriesNameFont = nullptr;
    TTF_Text *gameBuildingCategoriesNameText = nullptr;
    //Buttons UI
    bool bButtonUIBuildingIsPressed = true;
    bool bButtonUIGarrisonIsPressed = false;
    float firstButton = 800.f;
    SDL_FRect provinceButtonUIBuilding = {firstButton,1030.f,40.f,40.f};
    SDL_FRect provinceButtonUIGarrison = {firstButton + 50.f,1030.f,40.f,40.f};
    SDL_Texture *provinceTextureUIBuilding = nullptr;
    SDL_Texture *provinceTextureUIGarrison = nullptr;
    //Circle next turn button
    Circle NextTurnButton = {1825.f, 1000.f, 55};
    //Circle for technologies
    Circle TechnologyPannel = {1725.f, 900.f, 35};
    //Circle to return to game when in technology section
    Circle TechnologyReturnGame = {900.f, 1000.f, 35};

    //End Turn
    int currentTurn = 1;
    FactionZone currentFactionTurn = FactionZone::Knight;//start with player
    //texture next turn button
    SDL_Texture  *gameNextTurnTexture = nullptr;

    //filled Segment of food -> each segment change the food stored per turn
    int filledSegs;


    //Texture coin + Turn time
    SDL_Texture *gameCoinMoneyTexture = nullptr;
    SDL_Texture *gameTurnAmountTexture = nullptr;

    //Texture Toggle Tax Settlement
    SDL_Texture *gameToggleTaxSettlementFalse = nullptr;
    SDL_Texture *gameToggleTaxSettlementTrue = nullptr;

    //Texture Public order (Green if happy, red if not, gray if 0)
    SDL_Texture *gamePublicOrderPositifTexture = nullptr;
    SDL_Texture *gamePublicOrderNegatifTexture = nullptr;
    SDL_Texture *gamePublicOrderNeutralTexture = nullptr;
    //texture population growth
    SDL_Texture *gamePopulationPositiveGrowth = nullptr;
    SDL_Texture *gamePopulationNegativeGrowth = nullptr;

    //inizialise the rect for the publicOrder so i can use it when i put my mouse on it it shows the public order next turn
    SDL_FRect publicOrderIcon = {0.f, 0.f, 0.f, 0.f};
    bool bMouseOnPublicOrderIcon = false;
    int hoveredPublicOrderSettlementIndex = -1;//when on top of Public order
    float publicOrderTooltipX = 0.f;
    float publicOrderTooltipY = 0.f;
    //Buildings Texture
    //hammer
    SDL_Texture *hammerUIBuildingUpgradeTexture = nullptr;

    //mains settlements buildings textures
    //                 ~ KNIGHT ~
    //capital
    SDL_Texture *capitalBuildingUpgrade1Knight = nullptr;
    SDL_Texture *capitalBuildingUpgrade2Knight = nullptr;
    SDL_Texture *capitalBuildingUpgrade3Knight = nullptr;
    SDL_Texture *capitalBuildingUpgrade4Knight = nullptr;
    SDL_Texture *capitalBuildingUpgrade5Knight = nullptr;
    //castle
    SDL_Texture *castleBuildingUpgrade1Knight = nullptr;
    SDL_Texture *castleBuildingUpgrade2Knight = nullptr;
    SDL_Texture *castleBuildingUpgrade3Knight = nullptr;
    SDL_Texture *castleBuildingUpgrade4Knight = nullptr;
    SDL_Texture *castleBuildingUpgrade5Knight = nullptr;
    //Village
    SDL_Texture *villageBuildingUpgrade1Knight = nullptr;
    SDL_Texture *villageBuildingUpgrade2Knight = nullptr;
    SDL_Texture *villageBuildingUpgrade3Knight = nullptr;
    //Unavailable Slot
    SDL_Texture *gameNotAvailableSlotKnight = nullptr;
    //Available Slot
    SDL_Texture *gameAvailableSlotKnight = nullptr;
    //buildings types grouping
    SDL_Texture *gameBuildingTypesGroupingMilitaryKnight = nullptr;
    SDL_Texture *gameBuildingTypesGroupingAdvMilitaryKnight = nullptr;
    SDL_Texture *gameBuildingTypesGroupingDefenceKnight = nullptr;
    SDL_Texture *gameBuildingTypesGroupingEconomyKnight = nullptr;
    SDL_Texture *gameBuildingTypesGroupingReligionKnight = nullptr;
    //                 ~ VIKING ~
    //capital
    SDL_Texture *capitalBuildingUpgrade1Viking = nullptr;
    SDL_Texture *capitalBuildingUpgrade2Viking = nullptr;
    SDL_Texture *capitalBuildingUpgrade3Viking = nullptr;
    SDL_Texture *capitalBuildingUpgrade4Viking = nullptr;
    SDL_Texture *capitalBuildingUpgrade5Viking = nullptr;
    //Castle
    SDL_Texture *castleBuildingUpgrade1Viking = nullptr;
    SDL_Texture *castleBuildingUpgrade2Viking = nullptr;
    SDL_Texture *castleBuildingUpgrade3Viking = nullptr;
    SDL_Texture *castleBuildingUpgrade4Viking = nullptr;
    SDL_Texture *castleBuildingUpgrade5Viking = nullptr;
    //Village
    SDL_Texture *villageBuildingUpgrade1Viking = nullptr;
    SDL_Texture *villageBuildingUpgrade2Viking = nullptr;
    SDL_Texture *villageBuildingUpgrade3Viking = nullptr;
    //Unavailable Slot
    SDL_Texture *gameNotAvailableSlotViking = nullptr;
    //Available Slot
    SDL_Texture *gameAvailableSlotViking = nullptr;
    //buildings types grouping
    SDL_Texture *gameBuildingTypesGroupingMilitaryViking = nullptr;
    SDL_Texture *gameBuildingTypesGroupingAdvMilitaryViking = nullptr;
    SDL_Texture *gameBuildingTypesGroupingDefenceViking = nullptr;
    SDL_Texture *gameBuildingTypesGroupingEconomyViking = nullptr;
    SDL_Texture *gameBuildingTypesGroupingReligionViking = nullptr;
    //                 ~ SAMURAI ~
    //capital
    SDL_Texture *capitalBuildingUpgrade1Samurai = nullptr;
    SDL_Texture *capitalBuildingUpgrade2Samurai = nullptr;
    SDL_Texture *capitalBuildingUpgrade3Samurai = nullptr;
    SDL_Texture *capitalBuildingUpgrade4Samurai = nullptr;
    SDL_Texture *capitalBuildingUpgrade5Samurai = nullptr;
    //castle
    SDL_Texture *castleBuildingUpgrade1Samurai = nullptr;
    SDL_Texture *castleBuildingUpgrade2Samurai = nullptr;
    SDL_Texture *castleBuildingUpgrade3Samurai = nullptr;
    SDL_Texture *castleBuildingUpgrade4Samurai = nullptr;
    SDL_Texture *castleBuildingUpgrade5Samurai = nullptr;
    //village
    SDL_Texture *villageBuildingUpgrade1Samurai = nullptr;
    SDL_Texture *villageBuildingUpgrade2Samurai = nullptr;
    SDL_Texture *villageBuildingUpgrade3Samurai = nullptr;
    //Unavailable Slot
    SDL_Texture *gameNotAvailableSlotSamurai = nullptr;
    //Available Slot
    SDL_Texture *gameAvailableSlotSamurai = nullptr;
    //buildings types grouping
    SDL_Texture *gameBuildingTypesGroupingMilitarySamurai = nullptr;
    SDL_Texture *gameBuildingTypesGroupingAdvMilitarySamurai = nullptr;
    SDL_Texture *gameBuildingTypesGroupingDefenceSamurai= nullptr;
    SDL_Texture *gameBuildingTypesGroupingEconomySamurai = nullptr;
    SDL_Texture *gameBuildingTypesGroupingReligionSamurai = nullptr;
    //food icon Texture
    SDL_Texture *gameFoodIconUi = nullptr;
    //Growth textures
    SDL_Texture *gamePeasantryIconUi = nullptr;
    SDL_Texture *gameNobilityIconUi = nullptr;
    SDL_Texture *gameClergyIconUi = nullptr;
    //Positive and negative UI Icon to put on top of diffrent Icons
    SDL_Texture *gamePositiveUiIcon = nullptr;
    SDL_Texture *gameNegativeUiIcon = nullptr;

    //UI TextFont
    TTF_Font *gameStatUITitleFont = nullptr;

    TTF_Font *gameStatUIFont = nullptr;
    TTF_Text *gameStatUITitleText = nullptr;
    TTF_Text *gameStatUIText = nullptr;
    TTF_Font *gameBuildingDescriptionFont = nullptr;
    TTF_Text *gameBuildingDescriptionText = nullptr;

    //texture provinces when Unzoom
    SDL_Texture *provinceKnightBannerTexture = nullptr;
    SDL_Texture *provinceVikingBannerTexture = nullptr;
    SDL_Texture *provinceSamuraiBannerTexture = nullptr;

    //texture of all buildings for different factions
    std::unordered_map<BuildingType, SDL_Texture *> buildingTypeTextures;

    //texture of all settlements (On the Campaign map)
    struct SettlementTextureMap {
        FactionZone faction;
        SettlementType settlementType;
        int tier;
        bool operator==(const SettlementTextureMap &texture) const {
            return faction == texture.faction && settlementType == texture.settlementType && tier == texture.tier;
        }
    };
    //securing
    struct SettlementTextureMapHash {
        size_t operator()(const SettlementTextureMap &m) const {
            return std::hash<int>()((int)m.faction * 100 + (int)m.settlementType * 10 + m.tier);
        }
    };
    std::unordered_map<SettlementTextureMap, SDL_Texture*, SettlementTextureMapHash> settlementTextureCampaign;



    // -> CREDITS <-
    TTF_Font *creditsTitleFont = nullptr;
    TTF_Text *creditsTitleText = nullptr;
    TTF_Font *creditsRoleTitleFont = nullptr;
    TTF_Text *creditsRoleTitleText = nullptr;
    TTF_Font *creditsRoleNameFont = nullptr;
    TTF_Text *creditsRoleNameText = nullptr;

    // -> OTHER <-
    TTF_Font *fpsFont = nullptr;
    TTF_Text *fpsText = nullptr;
    TTF_TextEngine *textEngine = nullptr;

    //Return Menu Button
    Circle BoutonReturn = {1875,1025,30};

    //Pour le FPS
    std::vector<float> frameTimes;
    const size_t MAX_SAMPLES = 100;
    bool shouldUpdateText = false;
    SDL_TimerID fpsTimerID;
    SDL_TimerID ShootTimerID;
    float currentFPS = 0.0f;

    float deltaTime = 0.f;


    //PATRON DE CONCEPTION SINGLETON
    static GameApp &GetInstance() {
        static GameApp instance;
        return instance;
    }

    GameApp(GameApp const &) = delete;

    void operator=(GameApp const &) = delete;

    //AUDIO
    MIX_Mixer *mixer = nullptr;
    MIX_Track *trackMusique = nullptr;
    MIX_Track *trackGame = nullptr;
    MIX_Track *trackSFX = nullptr;

    //For the tileMap
    TileMap* tileMap = nullptr;
    //For the camera
    Camera camera;
    bool bIsMovingCamera = false;
    float lastMouseX = 0;
    float lastMouseY = 0;

    std::vector<Settlement> settlements;

    // UI Campaign
    bool bHasClickedOnASettlement = false;
    int selectedSettlementIndex = -1;
    int hoveredSettlementIndex = -1;
    int hoveredTierPopupIndex = -1;
    int hoveredSlotIndex = -1;
    int buildMenuSlotIndex       = -1;
    int buildMenuSettlementIndex = -1;
    int hoveredCategory          = -1;
    int hoveredCardIndex = -1;
    //hovered an available construction building.
    int hoveredAvailableSlot = -1;
    int hoveredAvailableBuilding = -1;
    SDL_FRect hoveredAvailableSlotRect = {0,0,0,0};
    SDL_FRect categoryButtonsPopupRect = {0,0,0,0};
    //for the differents Buildings category
    int hoveredBuildingCategoryIndex = -1;
    int categoryPopupCardIndex = -1;
    BuildingType hoveredCategoryBuildingType = BuildingType::None;
    std::vector<std::pair<SDL_FRect, BuildingType>> categoryEvolutionTileRects;
    SDL_FRect categoryEvolutionPopupRect = {0,0,0,0};
    std::vector<SDL_FRect> availableSlotRects;
    std::vector<std::pair<int,int>> availableSlotInfo;
    //For the pending fix
    std::vector<SDL_FRect> pendingSlotRects;
    std::vector<std::pair<int,int>> pendingSlotInfo;

    // 0=Military 1=AdvMilitary 2=Defence 3=Economy 4=Religion
    BuildingType hoveredBuilding = BuildingType::None;
    std::vector<SDL_FRect> categoryButtonsRects;//5 rects for the buildings categories UI

    std::vector<SDL_FRect> mainBuildingSlotRects;
    SDL_FRect mainBuildingPopupRect = {0,0,0,0};

    bool hoveredBuildingSlotUpgradable = false;
    BuildingType upgradableSlotRootBuilding = BuildingType::None;

    //Money Mouse Hovered UI
    bool bMouseOnMoneyIcon = false;
    float moneyTooltipX = 0.0f;
    float moneyTooltipY = 0.0f;

    //Food Mouse Hovered New UI
    bool bMouseOnFoodIcon = false;
    float foodTooltipX = 0.0f;
    float foodTooltipY = 0.0f;

    //Population Mouse Hovered UI
    bool bMouseOnPopulationIcon = false;
    float populationTooltipX = 0.0f;
    float populationTooltipY = 0.0f;
    int hoveredPopulationType = -1;

    //toggle tax province
    //bool bToggleCollectIncome = true; is global and for each settlement i need to use Province.h
    SDL_FRect toggleTaxIncomeCollect = {0.f,0.f,14.f,14.f};


    //Provinces name + Faction Zone + which region is a capital
    std::vector<Province> provinces = {
        //knight
        {0, "NameRegion1", FactionZone::Knight, true},
        {1, "NameRegion2", FactionZone::Knight, false},//north
        {2, "NameRegion3", FactionZone::Knight, false},//south
        //viking
        {3, "NameRegion1", FactionZone::Viking, true},
        {4, "NameRegion2", FactionZone::Viking, false},//west
        {5, "NameRegion3", FactionZone::Viking, false},//est
        //samurai
        {6, "NameRegion1", FactionZone::Samurai,true},
        {7, "NameRegion2", FactionZone::Samurai,false},//est
        {8, "NameRegion3", FactionZone::Samurai,false},//west
    };




    std::vector<SDL_FRect> tierPopupRects; // 1 rect per building
    int tierPopupMaxTier = 0;

    //Player
    Player player;

private://constructor
    GameApp() {

        //SDL INIT
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == false) {
            SDL_LogCritical(1, "failed to initialize SDL %s", SDL_GetError());
            abort();
        }
        //window + renderer
        window = SDL_CreateWindow("Total Battle 2D",1280,720,0);
        if (window == nullptr) {
            SDL_LogCritical(1,"SDL failed to create the window! &s", SDL_GetError());
            abort();
        }
        renderer = SDL_CreateRenderer(window, nullptr);
        if (renderer == nullptr) {
            SDL_LogCritical(1,"SDL failed to create the renderer &s", SDL_GetError());
            abort();
        }
        //Pour mettre en fullscreen
        SDL_SetRenderLogicalPresentation(renderer, 1920,1080, SDL_LOGICAL_PRESENTATION_LETTERBOX);
        //Pour render les text
        textEngine = TTF_CreateRendererTextEngine(renderer);
        if (textEngine == nullptr) {
            SDL_LogCritical(1, "Failed to create textEngine", SDL_GetError());
        }
        //TTF_INIT
        if (TTF_Init() == false) {
            SDL_LogCritical(1, "SDL_ttf failed to initialize! %s", SDL_GetError());
            abort();
        }
        //cursor
        SDL_Surface* cursorSurface = IMG_Load("assets/cursor.png");
        if (cursorSurface) {
            // Scale to desired size (e.g. 64x64)
            SDL_Surface* scaledSurface = SDL_ScaleSurface(cursorSurface, 32, 32, SDL_SCALEMODE_NEAREST);
            SDL_DestroySurface(cursorSurface);

            if (scaledSurface) {
                cursor = SDL_CreateColorCursor(scaledSurface, 0, 0);
                SDL_DestroySurface(scaledSurface);
                SDL_SetCursor(cursor);
            }
        }
        //Music Menu
        if (!MIX_Init()) {
            SDL_LogCritical(1, "SDL_mixer failed to initialize! %s", SDL_GetError());
            abort();
        }
        mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, nullptr);
        if (!mixer) {
            SDL_LogWarn(0, "Couldn't create mixer: %s", SDL_GetError());
        }

        // Musique Menu
        char *pathMenu = nullptr;
        SDL_asprintf(&pathMenu, "assets/The Fall of Arcana.mp3", SDL_GetBasePath());
        MIX_Audio *audioMenu = MIX_LoadAudio(mixer, pathMenu, false);
        if (audioMenu == nullptr) {
            SDL_Log("impossible de charger audio de audioMenu%s", SDL_GetError());
        } else {
            SDL_Log("audio is working");
        }
        SDL_free(pathMenu);

        if (audioMenu) {
            trackMusique = MIX_CreateTrack(mixer);
            MIX_SetTrackAudio(trackMusique, audioMenu);
            MIX_PlayTrack(trackMusique, -1); //loop infini
            MIX_SetTrackGain(trackMusique, 0.5f);//volume
        }




        // -> MENU <-
        gameInProgressFont = TTF_OpenFont("assets/KnightFont.ttf", 40);
        gameVersionFont = TTF_OpenFont("assets/Rubik.ttf", 35);
        gameVersionText = TTF_CreateText (textEngine, gameVersionFont, "Version (0.2.0)", 16);
        if (gameVersionText == nullptr) {
            SDL_LogWarn(0,"failed to create text for gameVersionText", SDL_GetError());
        }
        gameInProgressText = TTF_CreateText(textEngine, gameInProgressFont, "WORK IN PROGRESS", 16);
        if (gameInProgressText == nullptr) {
            SDL_LogWarn(0,"failed to create text for gameInProgressText", SDL_GetError());
        }
        if (TTF_SetTextColor(gameInProgressText, 255,255,255,222)==false) {
            SDL_LogWarn(1,"failed to set the color of gameInProgressText", SDL_GetError());
        }

        // GAME VERSION

        //WORK IN PROGRESS TEXT

        menuFont = TTF_OpenFont("assets/KnightFont.ttf",108);
        if (menuFont == nullptr) {
            SDL_LogCritical(1, "Failed to load font: %s", SDL_GetError());
            abort();
        }
        menuText = TTF_CreateText(textEngine, menuFont, "Total Battle 2D", 25);
        if (menuText == nullptr) {
            SDL_LogWarn(0,"failed to create text for menuText", SDL_GetError());
        }
        if (TTF_SetTextColor(menuText, 0,0,0,255)==false) {
            SDL_LogWarn(1,"failed to set the color of menuText", SDL_GetError());
        }
        //bouton Menu
        StartFont = TTF_OpenFont("assets/font.ttf",75);
        TutorialFont = TTF_OpenFont("assets/font.ttf",60);
        OptionsFont = TTF_OpenFont("assets/font.ttf",50);
        QuitFont = TTF_OpenFont("assets/font.ttf",40);
        CreditsFont = TTF_OpenFont("assets/font.ttf",30);

        textStart = TTF_CreateText(textEngine, StartFont, "Start", 25);
        if (textStart == nullptr) {
            SDL_LogWarn(1,"failed to create text for textStart", SDL_GetError());
        }
        textTutorial = TTF_CreateText(textEngine, TutorialFont, "Tutorial", 25);
        if (textTutorial == nullptr) {
            SDL_LogWarn(1,"failed to create text for textTutorial", SDL_GetError());
        }
        textOptions = TTF_CreateText(textEngine, OptionsFont, "Options", 25);
        if (textOptions == nullptr) {
            SDL_LogWarn(1,"failed to create text for textOptions", SDL_GetError());
        }
        textQuit = TTF_CreateText(textEngine, QuitFont, "Quit", 25);
        if (textQuit == nullptr) {
            SDL_LogWarn(1,"failed to create text for textQuit", SDL_GetError());
        }
        textCredits = TTF_CreateText(textEngine, CreditsFont, "Credits", 25);
        if (textCredits == nullptr) {
            SDL_LogWarn(1,"failed to create text for textCredits", SDL_GetError());
        }

        // -> Faction Selection <-
        factionSelectionTitleFont = TTF_OpenFont("assets/font.ttf",50);
        factionSelectionFactionBonusFont = TTF_OpenFont("assets/font.ttf",40);
        factionSelectionGeneralKnightFont = TTF_OpenFont("assets/KnightFont.ttf",35);
        factionSelectionGeneralVikingFont = TTF_OpenFont("assets/VikingFont.otf",30);
        factionSelectionGeneralSamuraiFont = TTF_OpenFont("assets/SamuraiFont.ttf",15);
        factionSelectionTitleText = TTF_CreateText(textEngine,factionSelectionTitleFont, "Faction Selection", 25);
        if (factionSelectionTitleText == nullptr) {
            SDL_LogWarn(0,"failed to load the text of factionSelectionTitleText ", SDL_GetError());
        }
        factionSelectionFactionBonusText = TTF_CreateText(textEngine, factionSelectionFactionBonusFont,"Faction Bonus", 25);
        if (factionSelectionFactionBonusText == nullptr) {
            SDL_LogWarn(0, "failed to lad the text of factionSelectionFactionBonus");
        }
        factionSelectionGeneralKnightText = TTF_CreateText(textEngine, factionSelectionGeneralKnightFont, "Strong start economie\nand crossbows\nFaith is all \n ", 50);
        if (factionSelectionGeneralKnightText == nullptr) {
            SDL_LogWarn(0, "failed to load the text of factionSelectionGeneralKnightText", SDL_GetError());
        }
        factionSelectionLoreknightText = TTF_CreateText(textEngine, factionSelectionGeneralKnightFont,"The Knight are a very respected and a united country\nWith strong crossbow and cavalry, They're putting all their ennemy to their knees\nThey will fight anyone who denies they're rightful King", 250);
        if (factionSelectionLoreknightText == nullptr) {
            SDL_LogWarn(0,"failed to load the text of factionSelectionLoreKnightText", SDL_GetError());
        }
        factionSelectionGeneralVikingText = TTF_CreateText(textEngine, factionSelectionGeneralVikingFont, "Raiding Bonuses \nHas access to strong berserkers\nCan call Odin \nWeak settlements incomes ", 150);
        if (factionSelectionGeneralVikingText == nullptr) {
            SDL_LogWarn(0, "failed to load the text of factionSelectionGeneralVikingText", SDL_GetError());
        }
        factionSelectionLoreVikingText = TTF_CreateText(textEngine, factionSelectionGeneralVikingFont,"These proud fighters of the north,The Vikings, are strong warriors who's melee skills exceeds all.\nStrenght is the only answer\nThey are ready to fight anyone who denies their jarl ", 250);
        if (factionSelectionLoreVikingText == nullptr) {
            SDL_LogWarn(0,"failed to load the text of factionSelectionLoreVikingText", SDL_GetError());
        }
        factionSelectionGeneralSamuraiText = TTF_CreateText(textEngine, factionSelectionGeneralSamuraiFont, "Ambush Bonuses\nPowerful Religion Bonuses \nStrong Powder Units \n ", 50);
        if (factionSelectionGeneralSamuraiText == nullptr) {
            SDL_LogWarn(0, "failed to load the text of factionSelectionGeneralSamuraiText", SDL_GetError());
        }
        factionSelectionLoreSamuraiText = TTF_CreateText(textEngine, factionSelectionGeneralSamuraiFont,"The Samurai have a great respect for tradition and honor\nThey are great fighter with very strong Katana units and strong cavalery\nThey are ready to fight anyone Who denies they're Shogun   ", 250);
        if (factionSelectionLoreSamuraiText == nullptr) {
            SDL_LogWarn(0,"failed to load the text of factionSelectionLoreSamuraiText", SDL_GetError());
        }
        factionSelectionStartCampaignText = TTF_CreateText(textEngine, factionSelectionGeneralKnightFont, "Start Campaign",25);
        if (factionSelectionStartCampaignText == nullptr) {

        }
        //texture
        chooseFactionKnightIcon = IMG_LoadTexture(renderer,"assets/ChooseFactionKnightIcon.png");
        if (chooseFactionKnightIcon == nullptr) {
            SDL_LogWarn(0, "failed to load the texture chooseFactionKnightIcon", SDL_GetError());
        }
        SDL_SetTextureScaleMode(chooseFactionKnightIcon, SDL_SCALEMODE_NEAREST);
        chooseFactionVikingIcon = IMG_LoadTexture(renderer,"assets/ChooseFactionVikingIcon.png");
        if (chooseFactionVikingIcon == nullptr) {
            SDL_LogWarn(0, "failed to load the texture chooseFactionVikingIcon", SDL_GetError());
        }
        SDL_SetTextureScaleMode(chooseFactionVikingIcon, SDL_SCALEMODE_NEAREST);
        chooseFactionSamuraiIcon = IMG_LoadTexture(renderer,"assets/ChooseFactionSamuraiIcon.png");
        if (chooseFactionSamuraiIcon == nullptr) {
            SDL_LogWarn(0, "failed to load the texture chooseFactionSamuraiIcon", SDL_GetError());
        }
        SDL_SetTextureScaleMode(chooseFactionSamuraiIcon, SDL_SCALEMODE_NEAREST);
        // -> OPTION <-
        optionsTitleFont = TTF_OpenFont("assets/font.ttf", 50);
        optionsMusicFont = TTF_OpenFont("assets/font.ttf", 20);
        optionsTitleText = TTF_CreateText(textEngine, optionsTitleFont,"Options", 25);
        optionsMusicText = TTF_CreateText(textEngine, optionsMusicFont,"Volume Music", 25);
        // -> GAME <-
        //CREATION OF TILES
        tileMap = new TileMap("assets/TileMap.png",16);
        tileMap->BakeToTexture(renderer);
        tileMap->LoadProvinceMap("assets/ProvinceMap.png");
        //UI Font
        gameStatUITitleFont = TTF_OpenFont("assets/Rubik.ttf", 25);
        gameStatUIFont = TTF_OpenFont("assets/Rubik.ttf", 20);
        gameBuildingCostUIFont = TTF_OpenFont("assets/Rubik.ttf", 15);
        gameBuildingConstructionTimeFont = TTF_OpenFont("assets/Rubik.ttf", 15);
        gameStatUITitleText = TTF_CreateText(textEngine, gameStatUITitleFont,"GameStatue", 25);
        if (gameStatUITitleText == nullptr) {
            SDL_LogWarn(0,"failed to create the text gameStatUITitleText",SDL_GetError());
        }
        gameStatUIText = TTF_CreateText(textEngine, gameStatUIFont, "GameStatue", 25);
        if (gameStatUIText == nullptr) {
            SDL_LogWarn(0,"failed to create the text gameStatUIText",SDL_GetError());
        }
        gameGeneralFont = TTF_OpenFont("assets/Rubik.ttf", 20);
        gameCurrentMoneyUiText = TTF_CreateText(textEngine, gameGeneralFont, "0", 25);
        if (gameCurrentMoneyUiText == nullptr) {
            SDL_LogWarn(0, "failed to create the text gameCurrentMoneyUiText",SDL_GetError());
        }
        gameAnticipatedMoneyUiText = TTF_CreateText(textEngine, gameGeneralFont, "(0)", 25);
        if (gameAnticipatedMoneyUiText == nullptr) {
            SDL_LogWarn(0,"failed to create the text gameAnticipatedMoneyUiText", SDL_GetError());
        }
        gameCurrentFoodUiFont = TTF_OpenFont("assets/Rubik.ttf", 15);
        gameFoodIndicatorUiFont = TTF_OpenFont ("assets/Rubik.ttf", 19);
        gameMoneyIndicatorUiFont = TTF_OpenFont("assets/Rubik.ttf", 19);
        gamePopulationIndicatorUiFont = TTF_OpenFont("assets/Rubik.ttf", 19);
        gameCurrentPopulationUiFont = TTF_OpenFont("assets/Rubik.ttf", 15);
        //same font has AnticipatedMoneyUiText
        gameCurrentFoodUiText = TTF_CreateText(textEngine, gameCurrentFoodUiFont, "", 25);
        if (gameCurrentFoodUiText == nullptr) {
            SDL_LogWarn(0, "failed to create the text for gameAnticipatedFoodUiText", SDL_GetError());
        }
        gameMoneyIndicatorUiText = TTF_CreateText(textEngine, gameMoneyIndicatorUiFont, "", 25);
        if (gameMoneyIndicatorUiText == nullptr) {
            SDL_LogWarn(0, "failed to create text gameMoneyIndicatorUiText", SDL_GetError());
        }
        gameFoodIndicatorUiText = TTF_CreateText (textEngine, gameFoodIndicatorUiFont, "", 25);
        if (gameFoodIndicatorUiText == nullptr) {
            SDL_LogWarn(0, "failed to create tex of gameFoodIndicatorUiText", SDL_GetError());
        }
        gamePopulationIndicatorUiText = TTF_CreateText (textEngine, gamePopulationIndicatorUiFont, "", 25);
        if (gamePopulationIndicatorUiText == nullptr) {
            SDL_LogWarn(0, "failed to create text of gamePopulationIndicatorUiText ", SDL_GetError());
        }
        gameCurrentPopulationUiText = TTF_CreateText (textEngine, gameCurrentPopulationUiFont, "", 25);
        if (gameCurrentPopulationUiText == nullptr) {
            SDL_LogWarn(0, "failed to load text of gameCurrentPopulationUiText", SDL_GetError());
        }

        gameNumberOfTurnText = TTF_CreateText(textEngine, gameGeneralFont, "0", 25);
        if (gameNumberOfTurnText == nullptr) {
            SDL_LogWarn(0,"failed to create the text gameNumberOfTurn",SDL_GetError());
        }
        gameBuildingCostUIText = TTF_CreateText(textEngine, gameBuildingCostUIFont, "0", 25);
        if (gameBuildingCostUIText == nullptr) {
            SDL_LogWarn(0,"failed to create the text gameBuildingCostUIText", SDL_GetError());
        }
        gameBuildingConstructionTimeText = TTF_CreateText(textEngine, gameBuildingConstructionTimeFont, "0", 25);
        if (gameBuildingConstructionTimeText == nullptr) {
            SDL_LogWarn(0,"failed to create the text gameBuildingConstructionTimeText", SDL_GetError());
        }
        gameBuildingDescriptionFont = TTF_OpenFont("assets/Rubik.ttf", 15);
        gameBuildingDescriptionText = TTF_CreateText(textEngine, gameBuildingDescriptionFont, "", 25);
        if (gameBuildingDescriptionText == nullptr) {
            SDL_LogWarn(0,"failed to create the text gameBuildingDescriptionText", SDL_GetError());
        }
        gameBuildingCategoriesNameFont = TTF_OpenFont("assets/Rubik.ttf",  16);
        gameBuildingCategoriesNameText = TTF_CreateText(textEngine, gameBuildingCategoriesNameFont, "Military", 25);
        if (gameBuildingCategoriesNameText == nullptr) {
            SDL_LogWarn(0, "failed to load text gameBuildingCategoriesNameText" , SDL_GetError());
        }

        //CREATION OF THE SETTLEMENTS
        //KNIGHT
        //CAPITAL REGION
        settlements.emplace_back(SettlementType::Capital, 0, 42, 50, FactionZone::Knight);
        settlements.back().settlementData.cityName = "CapitalName";
        settlements.emplace_back(SettlementType::Village, 0, 46, 35, FactionZone::Knight);
        settlements.back().settlementData.cityName = "Village1Name";
        settlements.emplace_back(SettlementType::Village, 0, 52, 42, FactionZone::Knight);
        settlements.back().settlementData.cityName = "Village2Name";
        settlements.emplace_back(SettlementType::Village, 0, 37, 61, FactionZone::Knight);
        settlements.back().settlementData.cityName = "Village3Name";
        //NORTH REGION
        settlements.emplace_back(SettlementType::Castle, 1, 22, 28, FactionZone::Knight);
        settlements.back().settlementData.cityName = "Castle1Name";
        settlements.emplace_back(SettlementType::Village, 1, 16, 12, FactionZone::Knight);
        settlements.back().settlementData.cityName = "Village1Name";
        settlements.emplace_back(SettlementType::Village, 1, 29, 34, FactionZone::Knight);
        settlements.back().settlementData.cityName = "Village2Name";
        settlements.emplace_back(SettlementType::Village, 1, 25, 46, FactionZone::Knight);
        settlements.back().settlementData.cityName = "Village3Name";
        //SOUTH REGION
        settlements.emplace_back(SettlementType::Castle, 2, 61,56, FactionZone::Knight);
        settlements.back().settlementData.cityName = "Castle1Name";
        settlements.emplace_back(SettlementType::Village, 2, 67, 50, FactionZone::Knight);
        settlements.back().settlementData.cityName = "Village2Name";
        settlements.emplace_back(SettlementType::Village, 2, 56, 67, FactionZone::Knight);
        settlements.back().settlementData.cityName = "Village3Name";
        // Vikings
        //NORTH CAPITAL
        settlements.emplace_back(SettlementType::Capital, 3, 60, 10, FactionZone::Viking);
        settlements.back().settlementData.cityName = "CapitalName";
        settlements.emplace_back(SettlementType::Village, 3, 50, 15, FactionZone::Viking);
        settlements.back().settlementData.cityName = "Village1Name";
        settlements.emplace_back(SettlementType::Village, 3, 70, 8, FactionZone::Viking);
        settlements.back().settlementData.cityName = "Village2Name";
        settlements.emplace_back(SettlementType::Village, 3, 83, 15, FactionZone::Viking);
        settlements.back().settlementData.cityName = "Village3Name";
        //OUEST REGION
        settlements.emplace_back(SettlementType::Castle, 4, 63, 25, FactionZone::Viking);
        settlements.back().settlementData.cityName = "Castle1Name";
        settlements.emplace_back(SettlementType::Village, 4, 36, 21, FactionZone::Viking);
        settlements.back().settlementData.cityName = "Village1Name";
        settlements.emplace_back(SettlementType::Village, 4, 64, 34, FactionZone::Viking);
        settlements.back().settlementData.cityName = "Village2Name";
        settlements.emplace_back(SettlementType::Village, 4, 68, 16, FactionZone::Viking);
        settlements.back().settlementData.cityName = "Village3Name";
        //EST REGION
        settlements.emplace_back(SettlementType::Castle, 5, 78, 34, FactionZone::Viking);
        settlements.back().settlementData.cityName = "Castle1Name";
        settlements.emplace_back(SettlementType::Village, 5, 88, 30, FactionZone::Viking);
        settlements.back().settlementData.cityName = "Village1Name";
        settlements.emplace_back(SettlementType::Village, 5, 97, 24, FactionZone::Viking);
        settlements.back().settlementData.cityName = "Village1Name";


        // Samurai
        //CAPITAL REGION
        settlements.emplace_back(SettlementType::Capital, 6, 103, 53, FactionZone::Samurai);
        settlements.back().settlementData.cityName = "CapitalName";
        settlements.emplace_back(SettlementType::Village, 6, 108, 66, FactionZone::Samurai);
        settlements.back().settlementData.cityName = "Village1Name";
        settlements.emplace_back(SettlementType::Village, 6, 101, 44, FactionZone::Samurai);
        settlements.back().settlementData.cityName = "Village2Name";
        settlements.emplace_back(SettlementType::Village, 6, 89, 41, FactionZone::Samurai);
        settlements.back().settlementData.cityName = "Village3Name";
        //EST REGION
        settlements.emplace_back(SettlementType::Castle, 7, 80, 50, FactionZone::Samurai);
        settlements.back().settlementData.cityName = "Castle1Name";
        settlements.emplace_back(SettlementType::Village, 7, 72, 62, FactionZone::Samurai);
        settlements.back().settlementData.cityName = "Village1Name";
        settlements.emplace_back(SettlementType::Village, 7, 80, 71, FactionZone::Samurai);
        settlements.back().settlementData.cityName = "Village12Name";
        settlements.emplace_back(SettlementType::Village, 7, 87, 64, FactionZone::Samurai);
        settlements.back().settlementData.cityName = "Village3Name";
        //OUEST REGION
        settlements.emplace_back(SettlementType::Castle, 8, 107, 29, FactionZone::Samurai);
        settlements.back().settlementData.cityName = "Castle1Name";
        settlements.emplace_back(SettlementType::Village, 8, 119, 59, FactionZone::Samurai);
        settlements.back().settlementData.cityName = "Village1Name";
        settlements.emplace_back(SettlementType::Village, 8, 118, 18, FactionZone::Samurai);
        settlements.back().settlementData.cityName = "Village2Name";

        // Initialize buildings[0] and baseIncome for spawned tier
        for (auto& s : settlements) {
            FactionZone faction = provinces[s.settlementData.provinceID].owner;
            s.settlementData.buildings[0] = GetSettlementBuildingType(
                s.settlementData.type, faction, s.settlementData.settlementTier);
            const BuildingData* data = GetBuildingData(s.settlementData.buildings[0]);
            if (data) s.settlementData.baseIncome = data->incomeBonus;
        }
        gameKingdomNameFont = TTF_OpenFont("assets/KnightFont.ttf", 40);
        gameKingdomKnightNameText = TTF_CreateText(textEngine, gameKingdomNameFont, "Knight\nKingdom", 25);
        if (gameKingdomKnightNameText == nullptr) {
            SDL_LogWarn(0,"failed to load the text of gameKingdomKnightNameText");
        }
        gameKingdomVikingNameText = TTF_CreateText(textEngine, gameKingdomNameFont, "Viking\nKingdom", 25);
        if (gameKingdomVikingNameText == nullptr) {
            SDL_LogWarn(0,"failed to load the text of gameKingdomVikingNameText");
        }
        gameKingdomSamuraiNameText = TTF_CreateText(textEngine, gameKingdomNameFont, "Samurai\nKingdom", 25);
        if (gameKingdomSamuraiNameText == nullptr) {
            SDL_LogWarn(0,"failed to load the text of gameKingdomSamuraiNameText");
        }
        //Texture Next Turn
        gameNextTurnTexture = IMG_LoadTexture(renderer, "assets/NextTurnTexture.png");
        if (gameNextTurnTexture == nullptr) {
            SDL_LogWarn(0,"failed to load the texture of gameNextTurnTexture", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gameNextTurnTexture, SDL_SCALEMODE_NEAREST);

        //texture Province dezoom texture
        provinceKnightBannerTexture = IMG_LoadTexture(renderer, "assets/KnightProvinceTexture.png");
        if (provinceKnightBannerTexture == nullptr) {
            SDL_LogWarn (0,"failed to load the texture of provinceKnightBannerTexture");
        }
        provinceSamuraiBannerTexture = IMG_LoadTexture(renderer, "assets/SamuraiProvinceTexture.png");
        if (provinceSamuraiBannerTexture == nullptr) {
            SDL_LogWarn(0,"failed to load the provinceSamuraiBannerTexture");
        }
        SDL_SetTextureScaleMode(provinceKnightBannerTexture, SDL_SCALEMODE_NEAREST);
        SDL_SetTextureScaleMode(provinceSamuraiBannerTexture, SDL_SCALEMODE_NEAREST);

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
        gamePopulationPositiveGrowth = IMG_LoadTexture(renderer, "assets/PopulationPositiveGrowthIcon.png");
        if (gamePopulationPositiveGrowth == nullptr) {
            SDL_LogWarn(0, "failed to load texture gamePopulationPositiveGrowth", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gamePopulationPositiveGrowth, SDL_SCALEMODE_NEAREST);
        gamePopulationNegativeGrowth = IMG_LoadTexture(renderer, "assets/PopulationNegativeGrowthIcon.png");
        if (gamePopulationNegativeGrowth == nullptr) {
            SDL_LogWarn(0, "failed to load texture gamePopulationNegativeGrowth", SDL_GetError());
        }
        SDL_SetTextureScaleMode(gamePopulationNegativeGrowth, SDL_SCALEMODE_NEAREST);

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

        buildingTypeTextures[BuildingType::Economy_T3] = IMG_LoadTexture(renderer, "assets/Knight/EconomyTier3.png");
        if (buildingTypeTextures[BuildingType::Economy_T3]  == nullptr) {
            SDL_LogWarn(0,"failed to load texture Economy_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Economy_T3], SDL_SCALEMODE_NEAREST);

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
        //Religion
        buildingTypeTextures[BuildingType::Church_T1] = IMG_LoadTexture(renderer, "assets/Knight/ChurchTier1.png");
        if (buildingTypeTextures[BuildingType::Church_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture Church_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Church_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::Church_T2] = IMG_LoadTexture(renderer, "assets/Knight/ChurchTier2.png");
        if (buildingTypeTextures[BuildingType::Church_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture Church_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Church_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::Church_T3] = IMG_LoadTexture(renderer, "assets/Knight/ChurchTier3.png");
        if (buildingTypeTextures[BuildingType::Church_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture Church_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Church_T3], SDL_SCALEMODE_NEAREST);

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

        buildingTypeTextures[BuildingType::SlaveMarket_T3]= IMG_LoadTexture(renderer, "assets/Viking/SlaveMarketTier3.png");
        if (buildingTypeTextures[BuildingType::SlaveMarket_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SlaveMarket_T3", SDL_GetError);
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SlaveMarket_T3], SDL_SCALEMODE_NEAREST);

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
        //warehouse
        buildingTypeTextures[BuildingType::VikingWareHouse_T5] = IMG_LoadTexture(renderer, "assets/Viking/WareHouseTier3.png");
        if (buildingTypeTextures[BuildingType::VikingWareHouse_T5]  == nullptr) {
            SDL_LogWarn(0, "failed to load texture VikingWareHouse_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::VikingWareHouse_T5], SDL_SCALEMODE_NEAREST);
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

        //Religion
        buildingTypeTextures[BuildingType::Shrine_T1] = IMG_LoadTexture(renderer, "assets/Viking/ShrineTier1.png");
        if (buildingTypeTextures[BuildingType::Shrine_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture Shrine_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Shrine_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::Shrine_T2] = IMG_LoadTexture(renderer, "assets/Viking/ShrineTier2.png");
        if (buildingTypeTextures[BuildingType::Shrine_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture Shrine_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Shrine_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::Shrine_T3] = IMG_LoadTexture(renderer, "assets/Viking/ShrineTier3.png");
        if (buildingTypeTextures[BuildingType::Shrine_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture Shrine_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Shrine_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::SacrificeRitual_T1] = IMG_LoadTexture(renderer, "assets/Viking/SacrificeRitualTier1.png");
        if (buildingTypeTextures[BuildingType::SacrificeRitual_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SacrificeRitual_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SacrificeRitual_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::SacrificeRitual_T2] = IMG_LoadTexture(renderer, "assets/Viking/SacrificeRitualTier2.png");
        if (buildingTypeTextures[BuildingType::SacrificeRitual_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SacrificeRitual_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SacrificeRitual_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::SacrificeRitual_T3] = IMG_LoadTexture(renderer, "assets/Viking/SacrificeRitualTier3.png");
        if (buildingTypeTextures[BuildingType::SacrificeRitual_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture SacrificeRitual_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::SacrificeRitual_T3], SDL_SCALEMODE_NEAREST);

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

        buildingTypeTextures[BuildingType::Market_T3] = IMG_LoadTexture(renderer, "assets/Samurai/MarketTier3.png");
        if (buildingTypeTextures[BuildingType::Market_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture Market_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Market_T3], SDL_SCALEMODE_NEAREST);

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

        //Religion
        buildingTypeTextures[BuildingType::Hospital_T1] = IMG_LoadTexture(renderer, "assets/Samurai/HospitalTier1.png");
        if (buildingTypeTextures[BuildingType::Hospital_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture Hospital_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Hospital_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::Hospital_T2] = IMG_LoadTexture(renderer, "assets/Samurai/HospitalTier2.png");
        if (buildingTypeTextures[BuildingType::Hospital_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture Hospital_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Hospital_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::Hospital_T3] = IMG_LoadTexture(renderer, "assets/Samurai/HospitalTier3.png");
        if (buildingTypeTextures[BuildingType::Hospital_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture Hospital_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Hospital_T3], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::Chapel_T1] = IMG_LoadTexture(renderer, "assets/Samurai/ChapelTier1.png");
        if (buildingTypeTextures[BuildingType::Chapel_T1] == nullptr) {
            SDL_LogWarn(0, "failed to load texture Chapel_T1", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Chapel_T1], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::Chapel_T2] = IMG_LoadTexture(renderer, "assets/Samurai/ChapelTier2.png");
        if (buildingTypeTextures[BuildingType::Chapel_T2] == nullptr) {
            SDL_LogWarn(0, "failed to load texture Chapel_T2", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Chapel_T2], SDL_SCALEMODE_NEAREST);

        buildingTypeTextures[BuildingType::Chapel_T3] = IMG_LoadTexture(renderer, "assets/Samurai/ChapelTier3.png");
        if (buildingTypeTextures[BuildingType::Chapel_T3] == nullptr) {
            SDL_LogWarn(0, "failed to load texture Chapel_T3", SDL_GetError());
        }
        SDL_SetTextureScaleMode(buildingTypeTextures[BuildingType::Chapel_T3], SDL_SCALEMODE_NEAREST);


        // -> CREDITS <-
        creditsTitleFont = TTF_OpenFont("assets/font.ttf", 50);
        creditsRoleTitleFont = TTF_OpenFont("assets/font.ttf", 40);
        creditsRoleNameFont = TTF_OpenFont("assets/font.ttf", 30);
        creditsTitleText = TTF_CreateText(textEngine, creditsTitleFont,"Credits", 20);
        if (creditsTitleText == nullptr) {
            SDL_LogWarn(0,"failed to load the text of creditsTitleText");
        }
        creditsRoleTitleText = TTF_CreateText(textEngine, creditsRoleTitleFont,"Programmer", 25);
        if (creditsRoleTitleText == nullptr) {
            SDL_LogWarn(0,"failed to load the text of creditsRoleTitleText");
        }

        creditsRoleNameText = TTF_CreateText(textEngine, creditsRoleNameFont, "Louis-Philippe Gauvin", 25);
        if (creditsRoleNameText == nullptr) {
            SDL_LogWarn(0,"failed to load the text of creditsRoleNameText");
        }
        //Autre
        fpsFont = TTF_OpenFont("assets/font.ttf", 24);
        fpsText = TTF_CreateText(textEngine, fpsFont, "FPS: 0", 20);
        if (fpsText == nullptr) {
            SDL_LogWarn(0,"failed to create text for fpsText FPS: 0", SDL_GetError());
        }
        if (TTF_SetTextColor(fpsText, 255,255,255,255)==false) {
            SDL_LogWarn(1,"failed to set the color of fpsText",SDL_GetError());
        }
        fpsTimerID = SDL_AddTimer(250, TimerCallback, &shouldUpdateText);


        //calcul current population / Need Bonus from buildings
        player.currentPeasantryAmount = player.basePeasantryBirth - player.basePeasantryDeath;
        player.currentNobilityAmount = player.baseNobilityBirth - player.baseNobilityDeath;
        player.currentClergyAmount = player.baseClergyGrowth - player.baseClergyDeath;
    }

    //DESTRUCTEUR
    ~GameApp() {
        //renderer
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        // Timer
        SDL_RemoveTimer(fpsTimerID);
        // ---------------------------------
        TTF_CloseFont(fpsFont);
        TTF_CloseFont(menuFont);
        TTF_CloseFont(StartFont);
        TTF_CloseFont(TutorialFont);
        TTF_CloseFont(OptionsFont);
        TTF_CloseFont(QuitFont);
        TTF_CloseFont(CreditsFont);
        TTF_CloseFont(factionSelectionTitleFont);
        TTF_CloseFont(factionSelectionFactionBonusFont);
        TTF_CloseFont(factionSelectionGeneralKnightFont);
        TTF_CloseFont(factionSelectionGeneralVikingFont);
        TTF_CloseFont(factionSelectionGeneralSamuraiFont);
        TTF_CloseFont(creditsTitleFont);
        TTF_CloseFont(creditsRoleTitleFont);
        TTF_CloseFont(creditsRoleNameFont);
        TTF_CloseFont(optionsTitleFont);
        TTF_CloseFont(optionsMusicFont);
        TTF_CloseFont(gameKingdomNameFont);
        TTF_CloseFont(gameStatUITitleFont);
        TTF_CloseFont(gameStatUIFont);
        TTF_CloseFont(gameGeneralFont);
        TTF_CloseFont(gameBuildingCostUIFont);
        TTF_CloseFont(gameBuildingConstructionTimeFont);
        TTF_CloseFont(gameBuildingDescriptionFont);
        TTF_CloseFont(gameBuildingCategoriesNameFont);
        TTF_CloseFont(gameCurrentFoodUiFont);
        TTF_CloseFont(gameMoneyIndicatorUiFont);
        TTF_CloseFont(gameFoodIndicatorUiFont);
        TTF_CloseFont(gamePopulationIndicatorUiFont);
        TTF_CloseFont(gameCurrentPopulationUiFont);
        TTF_CloseFont(gameInProgressFont);
        TTF_CloseFont(gameVersionFont);
        // ---------------------------------
        TTF_DestroyText(fpsText);
        TTF_DestroyText(menuText);
        TTF_DestroyText(textStart);
        TTF_DestroyText(textTutorial);
        TTF_DestroyText(textOptions);
        TTF_DestroyText(textQuit);
        TTF_DestroyText(textCredits);
        TTF_DestroyText(factionSelectionTitleText);
        TTF_DestroyText(factionSelectionFactionBonusText);
        TTF_DestroyText(factionSelectionGeneralKnightText);
        TTF_DestroyText(factionSelectionLoreknightText);
        TTF_DestroyText(factionSelectionGeneralVikingText);
        TTF_DestroyText(factionSelectionLoreVikingText);
        TTF_DestroyText(factionSelectionGeneralSamuraiText);
        TTF_DestroyText(factionSelectionLoreSamuraiText);
        TTF_DestroyText(factionSelectionStartCampaignText);
        TTF_DestroyText(creditsTitleText);
        TTF_DestroyText(creditsRoleTitleText);
        TTF_DestroyText(creditsRoleNameText);
        TTF_DestroyText(optionsTitleText);
        TTF_DestroyText(optionsMusicText);
        TTF_DestroyText(gameKingdomKnightNameText);
        TTF_DestroyText(gameKingdomVikingNameText);
        TTF_DestroyText(gameKingdomSamuraiNameText);
        TTF_DestroyText(gameStatUITitleText);
        TTF_DestroyText(gameStatUIText);
        TTF_DestroyText(gameCurrentMoneyUiText);
        TTF_DestroyText(gameAnticipatedMoneyUiText);
        TTF_DestroyText(gameCurrentFoodUiText);
        TTF_DestroyText(gameMoneyIndicatorUiText);
        TTF_DestroyText(gameFoodIndicatorUiText);
        TTF_DestroyText(gameNumberOfTurnText);
        TTF_DestroyText(gameBuildingCostUIText);
        TTF_DestroyText(gameBuildingConstructionTimeText);
        TTF_DestroyText(gameBuildingDescriptionText);
        TTF_DestroyText(gameBuildingCategoriesNameText);
        TTF_DestroyText(gameInProgressText);
        TTF_DestroyText(gameVersionText);
        TTF_DestroyText(gamePopulationIndicatorUiText);
        TTF_DestroyText(gameCurrentPopulationUiText);
        // ---------------------------------
        SDL_DestroyTexture(provinceKnightBannerTexture);
        SDL_DestroyTexture(provinceVikingBannerTexture);
        SDL_DestroyTexture(provinceSamuraiBannerTexture);
        SDL_DestroyTexture(provinceTextureUIBuilding);
        SDL_DestroyTexture(provinceTextureUIGarrison);
        SDL_DestroyTexture(hammerUIBuildingUpgradeTexture);
        SDL_DestroyTexture(capitalBuildingUpgrade1Knight);
        SDL_DestroyTexture(capitalBuildingUpgrade2Knight);
        SDL_DestroyTexture(capitalBuildingUpgrade3Knight);
        SDL_DestroyTexture(capitalBuildingUpgrade4Knight);
        SDL_DestroyTexture(capitalBuildingUpgrade5Knight);
        SDL_DestroyTexture(castleBuildingUpgrade1Knight);
        SDL_DestroyTexture(castleBuildingUpgrade2Knight);
        SDL_DestroyTexture(castleBuildingUpgrade3Knight);
        SDL_DestroyTexture(castleBuildingUpgrade4Knight);
        SDL_DestroyTexture(castleBuildingUpgrade5Knight);
        SDL_DestroyTexture(villageBuildingUpgrade1Knight);
        SDL_DestroyTexture(villageBuildingUpgrade2Knight);
        SDL_DestroyTexture(villageBuildingUpgrade3Knight);
        SDL_DestroyTexture(capitalBuildingUpgrade1Viking);
        SDL_DestroyTexture(capitalBuildingUpgrade2Viking);
        SDL_DestroyTexture(capitalBuildingUpgrade3Viking);
        SDL_DestroyTexture(capitalBuildingUpgrade4Viking);
        SDL_DestroyTexture(capitalBuildingUpgrade5Viking);
        SDL_DestroyTexture(castleBuildingUpgrade1Viking);
        SDL_DestroyTexture(castleBuildingUpgrade2Viking);
        SDL_DestroyTexture(castleBuildingUpgrade3Viking);
        SDL_DestroyTexture(castleBuildingUpgrade4Viking);
        SDL_DestroyTexture(castleBuildingUpgrade5Viking);
        SDL_DestroyTexture(villageBuildingUpgrade1Viking);
        SDL_DestroyTexture(villageBuildingUpgrade2Viking);
        SDL_DestroyTexture(villageBuildingUpgrade3Viking);
        SDL_DestroyTexture(capitalBuildingUpgrade1Samurai);
        SDL_DestroyTexture(capitalBuildingUpgrade2Samurai);
        SDL_DestroyTexture(capitalBuildingUpgrade3Samurai);
        SDL_DestroyTexture(capitalBuildingUpgrade4Samurai);
        SDL_DestroyTexture(capitalBuildingUpgrade5Samurai);
        SDL_DestroyTexture(castleBuildingUpgrade1Samurai);
        SDL_DestroyTexture(castleBuildingUpgrade2Samurai);
        SDL_DestroyTexture(castleBuildingUpgrade3Samurai);
        SDL_DestroyTexture(castleBuildingUpgrade4Samurai);
        SDL_DestroyTexture(castleBuildingUpgrade5Samurai);
        SDL_DestroyTexture(villageBuildingUpgrade1Samurai);
        SDL_DestroyTexture(villageBuildingUpgrade2Samurai);
        SDL_DestroyTexture(villageBuildingUpgrade3Samurai);
        SDL_DestroyTexture(chooseFactionKnightIcon);
        SDL_DestroyTexture(chooseFactionVikingIcon);
        SDL_DestroyTexture(chooseFactionSamuraiIcon);
        SDL_DestroyTexture(gameNotAvailableSlotKnight);
        SDL_DestroyTexture(gameNotAvailableSlotViking);
        SDL_DestroyTexture(gameNotAvailableSlotSamurai);
        SDL_DestroyTexture(gameAvailableSlotKnight);
        SDL_DestroyTexture(gameAvailableSlotViking);
        SDL_DestroyTexture(gameAvailableSlotSamurai);
        SDL_DestroyTexture(gameBuildingTypesGroupingMilitaryKnight);
        SDL_DestroyTexture(gameBuildingTypesGroupingAdvMilitaryKnight);
        SDL_DestroyTexture(gameBuildingTypesGroupingDefenceKnight);
        SDL_DestroyTexture(gameBuildingTypesGroupingEconomyKnight);
        SDL_DestroyTexture(gameBuildingTypesGroupingReligionKnight);
        SDL_DestroyTexture(gameBuildingTypesGroupingMilitaryViking);
        SDL_DestroyTexture(gameBuildingTypesGroupingAdvMilitaryViking);
        SDL_DestroyTexture(gameBuildingTypesGroupingDefenceViking);
        SDL_DestroyTexture(gameBuildingTypesGroupingEconomyViking);
        SDL_DestroyTexture(gameBuildingTypesGroupingReligionViking);
        SDL_DestroyTexture(gameBuildingTypesGroupingMilitarySamurai);
        SDL_DestroyTexture(gameBuildingTypesGroupingAdvMilitarySamurai);
        SDL_DestroyTexture(gameBuildingTypesGroupingDefenceSamurai);
        SDL_DestroyTexture(gameBuildingTypesGroupingEconomySamurai);
        SDL_DestroyTexture(gameBuildingTypesGroupingReligionSamurai);
        SDL_DestroyTexture(gameCoinMoneyTexture);
        SDL_DestroyTexture(gameTurnAmountTexture);
        SDL_DestroyTexture(gameToggleTaxSettlementTrue);
        SDL_DestroyTexture(gameToggleTaxSettlementFalse);
        SDL_DestroyTexture(gamePublicOrderPositifTexture);
        SDL_DestroyTexture(gamePublicOrderNegatifTexture);
        SDL_DestroyTexture(gamePublicOrderNeutralTexture);
        SDL_DestroyTexture(gameFoodIconUi);
        SDL_DestroyTexture(gamePeasantryIconUi);
        SDL_DestroyTexture(gameNobilityIconUi);
        SDL_DestroyTexture(gameClergyIconUi);
        SDL_DestroyTexture(gamePositiveUiIcon);
        SDL_DestroyTexture(gameNegativeUiIcon);
        SDL_DestroyTexture(gamePopulationPositiveGrowth);
        SDL_DestroyTexture(gamePopulationNegativeGrowth);
        // ---------------------------------
        SDL_DestroyCursor(cursor);
        delete tileMap;
        // ---------------------------------
        for (auto &[Type, texture]: buildingTypeTextures) {
            SDL_DestroyTexture(texture);
        }
        buildingTypeTextures.clear();
        // ---------------------------------
        for (auto& [key, tex] : settlementTextureCampaign)
            SDL_DestroyTexture(tex);
        settlementTextureCampaign.clear();
    }


    BuildingType GetSettlementBuildingType(SettlementType type, FactionZone faction, int tier) {
        if (faction == FactionZone::Knight) {
            if (type == SettlementType::Village) {
                if (tier == 1) return BuildingType::Settlement_Village_Knight_T1;
                if (tier == 2) return BuildingType::Settlement_Village_Knight_T2;
                if (tier == 3) return BuildingType::Settlement_Village_Knight_T3;
            }
            else if (type == SettlementType::Castle) {
                if (tier == 1) return BuildingType::Settlement_Castle_Knight_T1;
                if (tier == 2) return BuildingType::Settlement_Castle_Knight_T2;
                if (tier == 3) return BuildingType::Settlement_Castle_Knight_T3;
                if (tier == 4) return BuildingType::Settlement_Castle_Knight_T4;
                if (tier == 5) return BuildingType::Settlement_Castle_Knight_T5;
            }
            else if (type == SettlementType::Capital) {
                if (tier == 1) return BuildingType::Settlement_Capital_Knight_T1;
                if (tier == 2) return BuildingType::Settlement_Capital_Knight_T2;
                if (tier == 3) return BuildingType::Settlement_Capital_Knight_T3;
                if (tier == 4) return BuildingType::Settlement_Capital_Knight_T4;
                if (tier == 5) return BuildingType::Settlement_Capital_Knight_T5;
            }
        }
        else if (faction == FactionZone::Viking) {
            if (type == SettlementType::Village) {
                if (tier == 1) return BuildingType::Settlement_Village_Viking_T1;
                if (tier == 2) return BuildingType::Settlement_Village_Viking_T2;
                if (tier == 3) return BuildingType::Settlement_Village_Viking_T3;
            }
            else if (type == SettlementType::Castle) {
                if (tier == 1) return BuildingType::Settlement_Castle_Viking_T1;
                if (tier == 2) return BuildingType::Settlement_Castle_Viking_T2;
                if (tier == 3) return BuildingType::Settlement_Castle_Viking_T3;
                if (tier == 4) return BuildingType::Settlement_Castle_Viking_T4;
                if (tier == 5) return BuildingType::Settlement_Castle_Viking_T5;
            }
            else if (type == SettlementType::Capital) {
                if (tier == 1) return BuildingType::Settlement_Capital_Viking_T1;
                if (tier == 2) return BuildingType::Settlement_Capital_Viking_T2;
                if (tier == 3) return BuildingType::Settlement_Capital_Viking_T3;
                if (tier == 4) return BuildingType::Settlement_Capital_Viking_T4;
                if (tier == 5) return BuildingType::Settlement_Capital_Viking_T5;
            }
        }
        else if (faction == FactionZone::Samurai) {
            if (type == SettlementType::Village) {
                if (tier == 1) return BuildingType::Settlement_Village_Samurai_T1;
                if (tier == 2) return BuildingType::Settlement_Village_Samurai_T2;
                if (tier == 3) return BuildingType::Settlement_Village_Samurai_T3;
            }
            else if (type == SettlementType::Castle) {
                if (tier == 1) return BuildingType::Settlement_Castle_Samurai_T1;
                if (tier == 2) return BuildingType::Settlement_Castle_Samurai_T2;
                if (tier == 3) return BuildingType::Settlement_Castle_Samurai_T3;
                if (tier == 4) return BuildingType::Settlement_Castle_Samurai_T4;
                if (tier == 5) return BuildingType::Settlement_Castle_Samurai_T5;
            }
            else if (type == SettlementType::Capital) {
                if (tier == 1) return BuildingType::Settlement_Capital_Samurai_T1;
                if (tier == 2) return BuildingType::Settlement_Capital_Samurai_T2;
                if (tier == 3) return BuildingType::Settlement_Capital_Samurai_T3;
                if (tier == 4) return BuildingType::Settlement_Capital_Samurai_T4;
                if (tier == 5) return BuildingType::Settlement_Capital_Samurai_T5;
            }
        }
        return BuildingType::None;
    }

    //to render the Buttons
    void RenderBoutons(const SDL_FRect &rect, TTF_Text *buttonText, Uint8 buttonr, Uint8 buttong, Uint8 buttonb, Uint8 buttona) {
        SDL_SetRenderDrawColor(renderer, buttonr, buttong, buttonb, buttona);
        SDL_RenderFillRect(renderer, &rect);
        //Dessiner Texte au centre du boutton
        if (buttonText != nullptr) {
            int textW, textH; //Longeur/Largeur
            TTF_GetTextSize(buttonText, &textW, &textH);


            float textX = rect.x + (rect.w - textW) / 2.0f;
            float textY = rect.y + (rect.h - textH) / 2.0f;

            TTF_DrawRendererText(buttonText, textX, textY);
        }
    }

    //To render the sliders
    void RenderSlider(const VolumeSlider &volumeSlider, const char *music) {
        //empty part
        SDL_SetRenderDrawColor(renderer, 255, 204, 204, 255);
        SDL_FRect emptySlider = {volumeSlider.x, volumeSlider.y, volumeSlider.width, volumeSlider.height};
        SDL_RenderFillRect(renderer, &emptySlider);
        //full part
        SDL_SetRenderDrawColor(renderer, 255, 102, 102, 255);
        SDL_FRect fullSlider = {volumeSlider.x, volumeSlider.y, volumeSlider.width * volumeSlider.value, volumeSlider.height};
        SDL_RenderFillRect(renderer, &fullSlider);

        float handleX = volumeSlider.x + volumeSlider.width * volumeSlider.value - 10;
        float handleY = volumeSlider.y - 10;
        SDL_FRect handle = {handleX, handleY, 20,40};
        SDL_SetRenderDrawColor(renderer, 220, 220, 220, 255);
        SDL_RenderFillRect(renderer, &handle);
        std::string percentage = std::to_string((int)(volumeSlider.value * 100)) + "%";
    }

    //Settlement textures Campaign
    SDL_Texture* GetSettlementTexture(FactionZone faction, SettlementType type, int tier) {
        auto it = settlementTextureCampaign.find({faction, type, tier});
        if (it != settlementTextureCampaign.end()) return it->second;
        return nullptr;
    }


    //To not repeat the texture of settlements
    SDL_Texture* GetSettlementBuildingUpgradeTexture(FactionZone faction, SettlementType type, int tier) {
        if (faction == FactionZone::Knight) {
            if (type == SettlementType::Capital) {
                if (tier == 1) return capitalBuildingUpgrade1Knight;
                if (tier == 2) return capitalBuildingUpgrade2Knight;
                if (tier == 3) return capitalBuildingUpgrade3Knight;
                if (tier == 4) return capitalBuildingUpgrade4Knight;
                if (tier == 5) return capitalBuildingUpgrade5Knight;
            }
            else if (type == SettlementType::Castle) {
                if (tier == 1) return castleBuildingUpgrade1Knight;
                if (tier == 2) return castleBuildingUpgrade2Knight;
                if (tier == 3) return castleBuildingUpgrade3Knight;
                if (tier == 4) return castleBuildingUpgrade4Knight;
                if (tier == 5) return castleBuildingUpgrade5Knight;
            }
            else if (type == SettlementType::Village) {
                if (tier == 1) return villageBuildingUpgrade1Knight;
                if (tier == 2) return villageBuildingUpgrade2Knight;
                if (tier == 3) return villageBuildingUpgrade3Knight;
            }
        }
        else if (faction == FactionZone::Viking) {
            if (type == SettlementType::Capital) {
                if (tier == 1) return capitalBuildingUpgrade1Viking;
                if (tier == 2) return capitalBuildingUpgrade2Viking;
                if (tier == 3) return capitalBuildingUpgrade3Viking;
                if (tier == 4) return capitalBuildingUpgrade4Viking;
                if (tier == 5) return capitalBuildingUpgrade5Viking;
            }
            else if (type == SettlementType::Castle) {
                if (tier == 1) return castleBuildingUpgrade1Viking;
                if (tier == 2) return castleBuildingUpgrade2Viking;
                if (tier == 3) return castleBuildingUpgrade3Viking;
                if (tier == 4) return castleBuildingUpgrade4Viking;
                if (tier == 5) return castleBuildingUpgrade5Viking;
            }
            else if (type == SettlementType::Village) {
                if (tier == 1) return villageBuildingUpgrade1Viking;
                if (tier == 2) return villageBuildingUpgrade2Viking;
                if (tier == 3) return villageBuildingUpgrade3Viking;
            }
        }
        else if (faction == FactionZone::Samurai) {
            if (type == SettlementType::Capital) {
                if (tier == 1) return capitalBuildingUpgrade1Samurai;
                if (tier == 2) return capitalBuildingUpgrade2Samurai;
                if (tier == 3) return capitalBuildingUpgrade3Samurai;
                if (tier == 4) return capitalBuildingUpgrade4Samurai;
                if (tier == 5) return capitalBuildingUpgrade5Samurai;
            }
            else if (type == SettlementType::Castle) {
                if (tier == 1) return castleBuildingUpgrade1Samurai;
                if (tier == 2) return castleBuildingUpgrade2Samurai;
                if (tier == 3) return castleBuildingUpgrade3Samurai;
                if (tier == 4) return castleBuildingUpgrade4Samurai;
                if (tier == 5) return castleBuildingUpgrade5Samurai;
            }
            else if (type == SettlementType::Village) {
                if (tier == 1) return villageBuildingUpgrade1Samurai;
                if (tier == 2) return villageBuildingUpgrade2Samurai;
                if (tier == 3) return villageBuildingUpgrade3Samurai;
            }
        }
        return nullptr;
    }
    SDL_Texture* GetBuildingTexture(BuildingType type) {
        auto it = buildingTypeTextures.find(type);
        return (it != buildingTypeTextures.end()) ? it->second : nullptr;
    }

    //For the rendering on screen of the settlements. Texture to do
    void RenderSettlements() {
        //update public order bool
        bMouseOnPublicOrderIcon = false;
        hoveredPublicOrderSettlementIndex = -1;
        for (const auto& s : settlements) {
            float positionX = (float)(s.tileCol * tileMap->tileSize) * camera.zoom - camera.startX * camera.zoom;
            float positionY = (float)(s.tileRow * tileMap->tileSize) * camera.zoom - camera.startY * camera.zoom;
            float size = (float)tileMap->tileSize * camera.zoom;

            FactionZone zone = provinces[s.settlementData.provinceID].owner;

            //Square color based of faction Color
            SDL_Color factionColor;
            if (zone == FactionZone::Knight) {
                factionColor = {255, 215, 0,   255};
            }
            else if (zone == FactionZone::Viking) {
                factionColor = {255, 0,   0,   255};
            }
            else if (zone == FactionZone::Samurai) {
                factionColor = {0, 200, 160, 255};
            }
            else {
                factionColor = {150, 150, 150, 255};
            }

            // size of the building based of what they are
            float displaySize = size;
            if (s.settlementData.type == SettlementType::Capital) {
                displaySize = size * 4.f; //4x4
            }
            else if (s.settlementData.type == SettlementType::Castle) {
                displaySize = size * 3.f; //3x3
            }
            else if (s.settlementData.type == SettlementType::Village) {
                displaySize = size * 2.f; //2x2
            }
            //aligns all sizes to the grid
            SDL_FRect dst = {
                positionX,
                positionY,
                displaySize,
                displaySize
            };

            //color and texture of settlements
            //test
            SDL_SetRenderDrawColor(renderer, factionColor.r, factionColor.g, factionColor.b, 100);
            SDL_RenderFillRect(renderer, &dst);
            //Settlement texture that changes based on tier
            int tier = s.settlementData.settlementTier;
            SDL_Texture* tex = GetSettlementTexture(zone, s.settlementData.type, tier);
            if (tex) SDL_RenderTexture(renderer, tex, nullptr, &dst);


            // black border
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderRect(renderer, &dst);

            //UI elements to show (Public order / Current income of this settlement / Population )
            if (camera.zoom >= 1.1f) {
                // center of the settlement for the UI to show
                float centerX = positionX + displaySize / 2.f;
                float bottomY = positionY + displaySize;

                // size of all UI elements
                float barW   = 110.f;
                float barH   = 20.f;
                float barGap = 3.f;
                float barX   = centerX - barW / 2.f;
                float barY   = bottomY + barGap;

                // the name of the settlement
                TTF_SetTextString(gameStatUITitleText, s.settlementData.cityName.c_str(), 0);
                TTF_SetTextColor(gameStatUITitleText, 255, 255, 255, 255);
                int nameW = 0, nameH = 0;
                TTF_GetTextSize(gameStatUITitleText, &nameW, &nameH);
                float nameX = centerX - nameW / 2.f;
                float nameY = barY - nameH - 2.f;

                SDL_SetRenderDrawColor(renderer, 10, 10, 10, 200);
                SDL_FRect nameBackground = {nameX - 4.f, nameY - 2.f, (float)nameW + 4.f, (float)nameH + 2.f};
                SDL_RenderFillRect(renderer, &nameBackground);
                SDL_SetRenderDrawColor(renderer, factionColor.r, factionColor.g, factionColor.b, 160);
                SDL_RenderRect(renderer, &nameBackground);
                TTF_DrawRendererText(gameStatUITitleText, nameX, nameY);

                // INFO BAR
                SDL_SetRenderDrawColor(renderer, 10, 10, 10, 210);
                SDL_FRect infoBar = {barX, barY, barW, barH};
                SDL_RenderFillRect(renderer, &infoBar);
                SDL_SetRenderDrawColor(renderer, factionColor.r, factionColor.g, factionColor.b, 180);
                SDL_RenderRect(renderer, &infoBar);

                float iconSize = 11.f;
                float cursor = barX + 5.f;
                float iconY = barY + (barH - iconSize) / 2.f;
                float textY = barY - 2.f;

                // iconeIncome gold
                SDL_SetRenderDrawColor(renderer, 220, 180, 40, 255);
                SDL_FRect incomeIcon = {cursor, iconY, iconSize, iconSize};
                // SDL_RenderFillRect(renderer, &incomeIcon);
                // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 200);
                // SDL_RenderRect(renderer, &incomeIcon);
                SDL_RenderTexture(renderer, gameCoinMoneyTexture, nullptr, &incomeIcon);
                cursor += iconSize + 3.f;
                //the number that shows the income per settlement(baseIncome)
                //bool toggle income to show 0 if no income
                bool collectingIncome = provinces[s.settlementData.provinceID].bToggleCollectIncome;
                int totalSettlementIncome = s.settlementData.baseIncome;
                for (int b = 1; b < (int)s.settlementData.buildings.size(); b++) {
                    if (s.settlementData.buildings[b] != BuildingType::None) {
                        const BuildingData* bd = GetBuildingData(s.settlementData.buildings[b]);
                        if (bd) totalSettlementIncome += bd->incomeBonus;
                    }
                }
                std::string incomeStr = std::to_string(collectingIncome ? totalSettlementIncome : 0); // it shows 0 if the bool is true. otherwise it shows the base income for the ui settlement
                TTF_SetTextString(gameStatUIText, incomeStr.c_str(), 0);
                TTF_SetTextColor(gameStatUIText, 180, 230, 100, 255);
                TTF_DrawRendererText(gameStatUIText, cursor, textY);
                int incW = 0, incH = 0;
                TTF_GetTextSize(gameStatUIText, &incW, &incH);
                cursor += incW + 7.f;


                SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
                SDL_RenderLine(renderer, cursor, barY + 3.f, cursor, barY + barH - 3.f);
                cursor += 6.f;

                // public order icon
                int publicOrder = s.settlementData.publicOrder;
                Uint8 poR = publicOrder > 0 ? 80  : (publicOrder < 0 ? 220 : 130);
                Uint8 poG = publicOrder > 0 ? 200 : (publicOrder < 0 ? 50  : 130);
                float poSectionStartX = cursor;

                SDL_FRect poInconRect = {cursor, iconY, iconSize, iconSize};
                float mxPO, myPO;
                SDL_GetMouseState(&mxPO, &myPO);
                float lxPO, lyPO;
                SDL_RenderCoordinatesFromWindow(renderer, mxPO, myPO, &lxPO, &lyPO);
                SDL_FPoint msPO = {lxPO, lyPO};

                SDL_Texture* poTex = (publicOrder > 0) ? gamePublicOrderPositifTexture
                    : (publicOrder < 0) ? gamePublicOrderNegatifTexture
                    : gamePublicOrderNeutralTexture;
                if (poTex) SDL_RenderTexture(renderer, poTex, nullptr, &poInconRect);
                cursor += iconSize + 3.f;

                std::string orderStr = std::to_string(publicOrder);
                TTF_SetTextString(gameStatUIText, orderStr.c_str(), 0);
                TTF_SetTextColor(gameStatUIText, poR, poG, 80, 255);
                TTF_DrawRendererText(gameStatUIText, cursor, textY);

                int poTextW = 0, poTextH = 0;
                TTF_GetTextSize(gameStatUIText, &poTextW, &poTextH);

                SDL_FRect poHoverRect = {
                    poSectionStartX,
                    iconY,
                    (cursor + poTextW) - poSectionStartX,
                    iconSize
                    };
                if (SDL_PointInRectFloat(&msPO, &poHoverRect)) {
                    bMouseOnPublicOrderIcon = true;
                    hoveredPublicOrderSettlementIndex = (int)(&s - &settlements[0]);
                    publicOrderTooltipX = lxPO;
                    publicOrderTooltipY = lyPO;
                }

            }
        }
    }
    //UI of the region with their castle/villages when you click on a settlement from that province ID
    void RenderProvinceUI() {
        if (!bHasClickedOnASettlement || selectedSettlementIndex < 0) return;

        const Settlement& clickedSettlement = settlements[selectedSettlementIndex];
        int provinceID = clickedSettlement.settlementData.provinceID;//name of the province
        const Province& province = provinces[provinceID];

        std::vector<const Settlement*> provinceSettlements;
        for (const auto& s : settlements)
            if (s.settlementData.provinceID == provinceID)provinceSettlements.push_back(&s);

        int incomeTotal = 0;
        int populationTotal = 0;
        int publicOrderTotal = 0;
        for (auto* s : provinceSettlements) {
            incomeTotal += s->settlementData.baseIncome;
            for (int b = 1; b < (int)s->settlementData.buildings.size(); b++) {
                if (s->settlementData.buildings[b] != BuildingType::None) {
                    const BuildingData* bd = GetBuildingData(s->settlementData.buildings[b]);
                    if (bd) incomeTotal += bd->incomeBonus;
                }
            }
            populationTotal += s->settlementData.basePopulation;
            publicOrderTotal = s->settlementData.publicOrder;
        }
        //set the color
        SDL_Color factionColor;
        if(province.owner == FactionZone::Knight) {
            factionColor = {255, 215, 0,   255};
        }
        else if (province.owner == FactionZone::Viking) {
            factionColor = {255,0,0,255};
        }
        else if (province.owner == FactionZone::Samurai) {
            factionColor = {0,255, 215,255};
        }
        else {
            factionColor = {150, 150, 150, 255};
        }
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

        // LEFT UI PART
        //PROVINCE
        float leftW = 250.f, leftH = 380.f;//size
        float leftX = 0.f, leftY = 700.f;//position

        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 210);
        SDL_FRect leftPanel = {leftX, leftY, leftW, leftH};
        SDL_RenderFillRect(renderer, &leftPanel);

        // Title Province Name
        SDL_SetRenderDrawColor(renderer, factionColor.r, factionColor.g, factionColor.b, 180);
        SDL_FRect titleBar = {leftX, leftY, leftW, 40.f};
        SDL_RenderFillRect(renderer, &titleBar);
        SDL_SetRenderDrawColor(renderer, factionColor.r, factionColor.g, factionColor.b, 255);
        SDL_RenderRect(renderer, &leftPanel);

        // Name province
        TTF_SetTextString(gameStatUITitleText, province.name.c_str(), 0);
        TTF_SetTextColor(gameStatUITitleText, 255, 255, 255, 255);
        TTF_DrawRendererText(gameStatUITitleText, leftX + 10.f, leftY + 8.f);

        // Stats
        float statY = leftY + 55.f;

        // GROWTH TITLE SELECTION
        if (province.owner == FactionZone::Knight) {
            SDL_SetRenderDrawColor(renderer, 60, 40, 20, 200);
        }
        else if (province.owner == FactionZone::Viking) {
            SDL_SetRenderDrawColor(renderer, 60, 20, 20, 200);
        }
        else if (province.owner == FactionZone::Samurai) {
            SDL_SetRenderDrawColor(renderer, 20, 60, 45, 200);
        }
        SDL_FRect growthBar = {leftX + 5.f, statY, leftW - 10.f, 28.f};
        SDL_RenderFillRect(renderer, &growthBar);
        TTF_SetTextString(gameStatUITitleText, "Growth", 0);
        TTF_SetTextColor(gameStatUITitleText, 71, 255, 164, 255);
        TTF_DrawRendererText(gameStatUITitleText, leftX + 10.f, statY + 2.f);
        statY += 35.f;

        // Green Icone + growth amount
        SDL_SetRenderDrawColor(renderer, 80, 200, 80, 255);
        SDL_FRect popIcon = {leftX + 8.f, statY + 3.f, 14.f, 14.f};
        SDL_RenderFillRect(renderer, &popIcon);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 200);
        SDL_RenderRect(renderer, &popIcon);
        TTF_SetTextString(gameStatUIText, "Growth:", 0);
        TTF_SetTextColor(gameStatUIText, 180, 180, 180, 255);
        TTF_DrawRendererText(gameStatUIText, leftX + 28.f, statY);
        TTF_SetTextString(gameStatUIText, std::to_string(populationTotal).c_str(), 0);
        TTF_SetTextColor(gameStatUIText, 180, 230, 100, 255);
        TTF_DrawRendererText(gameStatUIText, leftX + 170.f, statY);
        statY += 34.f;

        // TAXE PROVINCE TITLE
        if (province.owner == FactionZone::Knight) {
            SDL_SetRenderDrawColor(renderer, 60, 40, 20, 200);
        }
        else if (province.owner == FactionZone::Viking) {
            SDL_SetRenderDrawColor(renderer, 60, 20, 20, 200);
        }
        else if (province.owner == FactionZone::Samurai) {
            SDL_SetRenderDrawColor(renderer, 20, 60, 45, 200);
        }
        SDL_FRect taxBar = {leftX + 5.f, statY, leftW - 10.f, 28.f};
        SDL_RenderFillRect(renderer, &taxBar);
        TTF_SetTextString(gameStatUITitleText, "Tax Province", 0);
        TTF_SetTextColor(gameStatUITitleText, 220, 180, 60, 255);
        TTF_DrawRendererText(gameStatUITitleText, leftX + 10.f, statY + 2.f);
        statY += 35.f;

        // income + gold icone
        SDL_SetRenderDrawColor(renderer, 220, 180, 40, 255);
        SDL_FRect incomeIconRect = {leftX + 8.f, statY, 20.f, 20.f};
        SDL_RenderTexture(renderer, gameCoinMoneyTexture, nullptr, &incomeIconRect);
        // SDL_RenderFillRect(renderer, &incomeIconRect);
        // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 200);
        // SDL_RenderRect(renderer, &incomeIconRect);
        TTF_SetTextString(gameStatUIText, "Income", 0);
        TTF_SetTextColor(gameStatUIText, 180, 180, 180, 255);
        TTF_DrawRendererText(gameStatUIText, leftX + 35.f, statY);
        int displayedIncome = province.bToggleCollectIncome ? incomeTotal : 0;
        TTF_SetTextString(gameStatUIText, std::to_string(displayedIncome).c_str(), 0);
        TTF_SetTextColor(gameStatUIText, 180, 230, 100, 255);
        TTF_DrawRendererText(gameStatUIText, leftX + 170.f, statY);
        statY += 34.f;

        //Toggle to tax the settlement. (collect income)
        //rect in gameapp
        toggleTaxIncomeCollect = {leftX + 8.f, statY, 20.f, 20.f};
        if (provinces[provinceID].bToggleCollectIncome) {
            // SDL_SetRenderDrawColor(renderer, 80, 200, 80, 255);  //green
            // SDL_RenderFillRect(renderer, &toggleTaxIncomeCollect);
            // SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255);
            SDL_RenderTexture(renderer, gameToggleTaxSettlementTrue, nullptr, &toggleTaxIncomeCollect);
        } else {
            // SDL_SetRenderDrawColor(renderer, 160, 50, 50, 255); //red
            // SDL_RenderFillRect(renderer, &toggleTaxIncomeCollect);
            // SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255);
            SDL_RenderTexture(renderer, gameToggleTaxSettlementFalse, nullptr, &toggleTaxIncomeCollect);
        }


        TTF_SetTextString(gameStatUIText, "Tax Province", 0);
        TTF_SetTextColor(gameStatUIText, 180, 180, 180, 255);
        TTF_DrawRendererText(gameStatUIText, leftX + 35.f, statY);


        statY += 34.f;
        // public Order Icon
        Uint8 poR  = publicOrderTotal > 0 ? 80  : (publicOrderTotal < 0 ? 220 : 130);
        Uint8 poG  = publicOrderTotal > 0 ? 200 : (publicOrderTotal < 0 ? 50  : 130);
        Uint8 poB2 = 80;
        SDL_FRect poIconRect = {leftX + 8.f, statY, 20.f, 20.f};
        SDL_Texture* poTex = (publicOrderTotal > 0) ? gamePublicOrderPositifTexture
                           : (publicOrderTotal < 0) ? gamePublicOrderNegatifTexture
                                                    : gamePublicOrderNeutralTexture;
        if (poTex) SDL_RenderTexture(renderer, poTex, nullptr, &poIconRect);
        TTF_SetTextString(gameStatUIText, "Public order", 0);
        TTF_SetTextColor(gameStatUIText, 180, 180, 180, 255);
        TTF_DrawRendererText(gameStatUIText, leftX + 35.f, statY - 3.f);
        TTF_SetTextString(gameStatUIText, std::to_string(publicOrderTotal).c_str(), 0);
        TTF_SetTextColor(gameStatUIText, poR, poG, poB2, 255);
        TTF_DrawRendererText(gameStatUIText, leftX + 170.f, statY);
        statY += 34.f;

        // Capital
        TTF_SetTextString(gameStatUIText, "Capital:", 0);
        TTF_SetTextColor(gameStatUIText, 180, 180, 180, 255);
        TTF_DrawRendererText(gameStatUIText, leftX + 28.f, statY);
        TTF_SetTextString(gameStatUIText, province.isCapital ? "Yes" : "No", 0);
        TTF_SetTextColor(gameStatUIText, 255, 215, 0, 255);
        TTF_DrawRendererText(gameStatUIText, leftX + 170.f, statY);

        //Province UI Different Buttons (buildings, garrison, All buildings, recruit a lord, recruit a hero)
        //Render those Buttons
        RenderBoutons(provinceButtonUIBuilding, nullptr,40,40,40,100);
        SDL_RenderTexture(renderer,provinceTextureUIBuilding,nullptr,&provinceButtonUIBuilding);
        RenderBoutons(provinceButtonUIGarrison, nullptr,40,40,40,100);
        SDL_RenderTexture(renderer,provinceTextureUIGarrison,nullptr,&provinceButtonUIGarrison);


        availableSlotRects.clear();
        availableSlotInfo.clear();
        pendingSlotInfo.clear();
        pendingSlotRects.clear();

        //-> BOTTOM UI PANNEL <-
        int   count = (int)provinceSettlements.size();
        float cardW = 280.f;
        float cardH = 200.f;
        float cardGap = 16.f;
        float totalW = count * cardW + (count - 1) * cardGap;
        float startX = (1920.f - totalW) / 2.f;
        float panelY = 1080.f - cardH - 65.f;
        //clear mainBuildingSlot before the for
        mainBuildingSlotRects.clear();
        mainBuildingSlotRects.resize(count, {0,0,0,0});
        for (int i = 0; i < count; i++) {
            const Settlement* s = provinceSettlements[i];
            bool isSelected = (s == &clickedSettlement);

            float cx = startX + i * (cardW + cardGap);

            // Fond carte
            SDL_SetRenderDrawColor(renderer, isSelected ? 40 : 25, isSelected ? 40 : 25, isSelected ? 40 : 25, 220);
            SDL_FRect card = {cx, panelY, cardW, cardH};
            SDL_RenderFillRect(renderer, &card);

            // Border
            if (isSelected)
                SDL_SetRenderDrawColor(renderer, factionColor.r, factionColor.g, factionColor.b, 255);
            else
                SDL_SetRenderDrawColor(renderer, 70, 70, 70, 255);
            SDL_RenderRect(renderer, &card);

            // title of each settlement UI changes the color
            SDL_Color typeColor;
            std::string typeName;
            if (s->settlementData.type == SettlementType::Capital) {
                if (province.owner == FactionZone::Knight) {
                    typeColor = {255,215,  0,255}; typeName = "Capital";
                }
                else if (province.owner == FactionZone::Samurai) {
                    typeColor = {0,255, 215,255}; typeName = "Capital";
                }
                else if (province.owner == FactionZone::Viking) {
                    typeColor = {255,0,0,255}; typeName = "Capital";
                }
            }
            else if (s->settlementData.type == SettlementType::Castle) {
                if (province.owner == FactionZone::Knight) {
                    typeColor = {255,215,0,255}; typeName = "Castle";
                }
                else if (province.owner == FactionZone::Samurai) {
                    typeColor = {0,255, 215,255}; typeName = "Castle";
                }
                else if (province.owner == FactionZone::Viking) {
                    typeColor = {255,0,0,255}; typeName = "Castle";
                }
            }
            else if (s->settlementData.type == SettlementType::Village) {
                if (province.owner == FactionZone::Knight) {
                    typeColor = {255,215,0,255}; typeName = "Village";
                }
                else if (province.owner == FactionZone::Samurai) {
                    typeColor = {0,255, 215,255}; typeName = "Village";
                }
                else if (province.owner == FactionZone::Viking) {
                    typeColor = {255,0,0,255}; typeName = "Village";
                }
            }

            SDL_SetRenderDrawColor(renderer, typeColor.r/3, typeColor.g/3, typeColor.b/3, 200);
            SDL_FRect cardTitle = {cx, panelY, cardW, 38.f};
            SDL_RenderFillRect(renderer, &cardTitle);

            // Icon
            SDL_SetRenderDrawColor(renderer, typeColor.r, typeColor.g, typeColor.b, 255);
            SDL_FRect icon = {cx + 10.f, panelY + 10.f, 18.f, 18.f};
            SDL_RenderFillRect(renderer, &icon);
            //each settlement Title ->
            TTF_SetTextString(gameStatUITitleText, s->settlementData.cityName.c_str(), 0);
            TTF_SetTextColor(gameStatUITitleText, 230, 230, 230, 255);
            TTF_DrawRendererText(gameStatUITitleText, cx + 36.f, panelY + 9.f);

            // building slots
            if (bButtonUIBuildingIsPressed) {
                float slotSize = 60.f;
                float slotGap  = 6.f;
                int cols = 0;
                if (s->settlementData.type == SettlementType::Village) cols = 2;
                else if (s->settlementData.type == SettlementType::Castle)  cols = 3;
                else if (s->settlementData.type == SettlementType::Capital) cols = 4;

                float gridW      = cols * slotSize + (cols - 1) * slotGap;
                float slotStartX = cx + (cardW - gridW) / 2.f;
                float row0Y      = panelY + cardH - (slotSize * 2 + slotGap) - 12.f;
                float row1Y      = row0Y + slotSize + slotGap;


                for (int b = 0; b < (int)s->settlementData.buildings.size(); b++) {
                    BuildingType buildingType = s->settlementData.buildings[b];

                    int col = b % cols;
                    int row = b / cols;

                    float sx = slotStartX + col * (slotSize + slotGap);
                    float sy = (row == 0) ? row0Y : row1Y;

                    // unique building per faction
                    //slot 0
                    if (b == 0) {
                        if (province.owner == FactionZone::Knight)
                            SDL_SetRenderDrawColor(renderer, 255, 215, 0, 255);
                        else if (province.owner == FactionZone::Viking)
                            SDL_SetRenderDrawColor(renderer, 255, 50, 50, 255);
                        else if (province.owner == FactionZone::Samurai)
                            SDL_SetRenderDrawColor(renderer, 0, 200, 160, 255);
                        else
                            SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);

                    } else {

                        // capital start with 2 buildings available instead of 1
                        bool built = (buildingType != BuildingType::None);
                        int tier = s->settlementData.settlementTier;

                        int slotThreshold = tier;
                        if (s->settlementData.type == SettlementType::Capital) slotThreshold = tier + 1;

                        if (b <= slotThreshold) {
                            SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); // available

                        } else {
                            SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);  // not available
                        }

                    }

                    SDL_FRect slot = {sx, sy, slotSize, slotSize};
                    SDL_RenderFillRect(renderer, &slot);

                    //Main settlement (0)
                    if (b == 0) {
                        // Texture
                        int tierToRender = s->settlementData.bBuidingUnderConstruction? s->settlementData.pendingTier: s->settlementData.settlementTier;
                        SDL_Texture* tex = GetSettlementBuildingUpgradeTexture(province.owner, s->settlementData.type, tierToRender);
                        if (tex) SDL_RenderTexture(renderer, tex, nullptr, &slot);

                        std::string tierStr = "T" + std::to_string(s->settlementData.settlementTier);
                        TTF_SetTextString(gameStatUIText, tierStr.c_str(), 0);
                        TTF_SetTextColor(gameStatUIText, 255, 255, 255, 255);
                        TTF_DrawRendererText(gameStatUIText, sx + 4.f, sy + 4.f);

                        int maxTierCheck = 3;
                        if (s->settlementData.type == SettlementType::Castle)  maxTierCheck = 5;
                        if (s->settlementData.type == SettlementType::Capital) maxTierCheck = 5;

                        //if not full tier than the hammer shows
                        BuildingType mainBuilding = s->settlementData.buildings[0];
                        int upgradeCost = player.GetUpgradeCost(s->settlementData.settlementTier, mainBuilding);
                        if (provinces[s->settlementData.provinceID].owner == player.faction) {
                            if (s->settlementData.settlementTier < maxTierCheck && hammerUIBuildingUpgradeTexture && player.currentGold  >= upgradeCost && s->settlementData.bBuidingUnderConstruction == false) {
                                SDL_FRect hammerRect = {
                                    sx + slotSize - 30.f,
                                    sy + 4.f,
                                    35.f, 35.f
                                };
                                SDL_RenderTexture(renderer, hammerUIBuildingUpgradeTexture, nullptr, &hammerRect);
                            }
                        }
                        // turn green to show the building is being upgraded
                        if (s->settlementData.bBuidingUnderConstruction) {
                            SDL_FRect baseTurnConstructionRect = {sx + 8.f, sy + 20.f, slotSize - 15.f, slotSize - 40.f};
                            SDL_SetRenderDrawColor(renderer, 144, 238, 144, 255);
                            SDL_RenderFillRect(renderer, &baseTurnConstructionRect);

                            // the number of Turn remaining before the construction is finished
                            std::string turnRemainingString = std::to_string(s->settlementData.constructionTime);
                            TTF_SetTextString(gameBuildingConstructionTimeText, turnRemainingString.c_str(), 0);
                            TTF_DrawRendererText(gameBuildingConstructionTimeText, sx + 25.f, sy + 20.f);

                            //for main buildings beeing able to refound a pending upgrade
                            pendingSlotRects.push_back(slot);
                            pendingSlotInfo.push_back({i,0});
                        }

                        mainBuildingSlotRects[i] = slot;
                        //which card is the mouse on
                        float mx, my;
                        SDL_GetMouseState(&mx, &my);
                        float lx, ly;
                        SDL_RenderCoordinatesFromWindow(renderer, mx, my, &lx, &ly);
                        SDL_FPoint mousePt = {lx, ly};
                        SDL_FRect slotCheck = {sx, sy, slotSize, slotSize};
                        if (SDL_PointInRectFloat(&mousePt, &slotCheck)) {
                            hoveredCardIndex = i;
                        }
                    }
                    else {
                        int tier = s->settlementData.settlementTier;
                        int slotThreshold = tier;
                        if (s->settlementData.type == SettlementType::Capital) {
                            slotThreshold = tier + 1; // capital start with 2 tier
                        }
                        bool slotAvailable = (b <= slotThreshold);
                        bool hasBuilding = (buildingType != BuildingType::None);

                        if (hasBuilding) {
                            SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255);
                            SDL_RenderFillRect(renderer, &slot);

                            bool upgradePending = (s->settlementData.pendingBuildings[b] != BuildingType::None);

                            // Render T2 if in construction, else T1
                            SDL_Texture* textureToRender = upgradePending
                                ? GetBuildingTexture(s->settlementData.pendingBuildings[b])
                                : GetBuildingTexture(buildingType);
                            if (textureToRender) SDL_RenderTexture(renderer, textureToRender, nullptr, &slot);

                            const BuildingData* bd = GetBuildingData(buildingType);
                            if (bd) {
                                std::string tierStr = "T" + std::to_string(bd->Tier);
                                TTF_SetTextString(gameStatUIText, tierStr.c_str(), 0);
                                TTF_SetTextColor(gameStatUIText, 255, 255, 255, 255);
                                TTF_DrawRendererText(gameStatUIText, sx + 4.f, sy + 4.f);

                                if (upgradePending) {
                                    SDL_FRect constructionRect = {sx + 8.f, sy + 20.f, slotSize - 15.f, slotSize - 40.f};
                                    SDL_SetRenderDrawColor(renderer, 144, 238, 144, 255);
                                    SDL_RenderFillRect(renderer, &constructionRect);
                                    std::string turnStr = std::to_string(s->settlementData.slotConstructionTimes[b]);
                                    TTF_SetTextString(gameBuildingConstructionTimeText, turnStr.c_str(), 0);
                                    TTF_DrawRendererText(gameBuildingConstructionTimeText, sx + 25.f, sy + 20.f);
                                    pendingSlotRects.push_back(slot);
                                    pendingSlotInfo.push_back({i, b});
                                } else {
                                    // Hammer if upgradable...
                                    if (bd->upgradesTo != BuildingType::None && hammerUIBuildingUpgradeTexture && provinces[s->settlementData.provinceID].owner == player.faction) {
                                        const BuildingData* nextBd = GetBuildingData(bd->upgradesTo);
                                        if (nextBd && nextBd->Tier <= s->settlementData.settlementTier) {
                                            if (player.currentGold >= nextBd->cost) {
                                                SDL_FRect hammerRect = { sx + slotSize - 30.f, sy + 4.f, 35.f, 35.f };
                                                SDL_RenderTexture(renderer, hammerUIBuildingUpgradeTexture, nullptr, &hammerRect);
                                            }
                                            availableSlotRects.push_back(slot);
                                            availableSlotInfo.push_back({i, b});
                                        }
                                    }
                                }
                                //To check a building name and what they do even if it's not upgradable yet.
                                float mxCheck, myCheck;
                                SDL_GetMouseState(&mxCheck, &myCheck);
                                float lxCheck, lyCheck;
                                SDL_RenderCoordinatesFromWindow(renderer, mxCheck, myCheck, &lxCheck, &lyCheck);
                                SDL_FPoint mpCheck = {lxCheck, lyCheck};
                                if (SDL_PointInRectFloat(&mpCheck, &slot) && categoryEvolutionPopupRect.w <= 0) {
                                    // if upgrade pending, show the current [ending building being constructed.
                                    bool upgPend = (s->settlementData.pendingBuildings[b] != BuildingType::None);
                                    hoveredCategoryBuildingType = upgPend
                                        ? s->settlementData.pendingBuildings[b]
                                        : buildingType;
                                }
                            }
                        }
                        else if (slotAvailable && s->settlementData.pendingBuildings[b] == BuildingType::None) {
                            // Show texture available
                            if (province.owner == FactionZone::Knight)
                                SDL_RenderTexture(renderer, gameAvailableSlotKnight, nullptr, &slot);
                            else if (province.owner == FactionZone::Viking)
                                SDL_RenderTexture(renderer, gameAvailableSlotViking, nullptr, &slot);
                            else if (province.owner == FactionZone::Samurai)
                                SDL_RenderTexture(renderer, gameAvailableSlotSamurai, nullptr, &slot);

                            availableSlotRects.push_back(slot);
                            availableSlotInfo.push_back({i, b});
                        }
                        else if (slotAvailable && s->settlementData.pendingBuildings[b] != BuildingType::None) {
                            // Texture pending building
                            SDL_Texture* pendingTex = GetBuildingTexture(s->settlementData.pendingBuildings[b]);
                            if (pendingTex) SDL_RenderTexture(renderer, pendingTex, nullptr, &slot);

                            // small rect to construct
                            SDL_FRect constructionRect = {sx + 8.f, sy + 20.f, slotSize - 15.f, slotSize - 40.f};
                            SDL_SetRenderDrawColor(renderer, 144, 238, 144, 255);
                            SDL_RenderFillRect(renderer, &constructionRect);

                            // the turn amount before completion
                            std::string turnStr = std::to_string(s->settlementData.slotConstructionTimes[b]);
                            TTF_SetTextString(gameBuildingConstructionTimeText, turnStr.c_str(), 0);
                            TTF_DrawRendererText(gameBuildingConstructionTimeText, sx + 25.f, sy + 20.f);
                            //to fix the pending bug
                            pendingSlotRects.push_back(slot);
                            pendingSlotInfo.push_back({i, b});
                        }
                        else {
                            // Not Available Slot
                            if (province.owner == FactionZone::Knight)
                                SDL_RenderTexture(renderer, gameNotAvailableSlotKnight, nullptr, &slot);
                            else if (province.owner == FactionZone::Viking)
                                SDL_RenderTexture(renderer, gameNotAvailableSlotViking, nullptr, &slot);
                            else if (province.owner == FactionZone::Samurai)
                                SDL_RenderTexture(renderer, gameNotAvailableSlotSamurai, nullptr, &slot);
                        }
                    }
                }
            }
        }

        //render of the Popup for the general Buildings
        //just to get mouse position
        float mouseX;
        float mouseY;
        SDL_GetMouseState (&mouseX, &mouseY);
        float lenghtX, lenghtY;
        SDL_RenderCoordinatesFromWindow(renderer, mouseX, mouseY, &lenghtX, &lenghtY);
        SDL_FPoint mousePt = {lenghtX, lenghtY};

        bool previousUpgradableState = hoveredBuildingSlotUpgradable;
        hoveredAvailableSlot = -1;
        hoveredAvailableBuilding = -1;
        hoveredBuildingSlotUpgradable = false;

        //to not let a upgradable slot take the priority over the one building that is trying to be upgraded/constructed
        SDL_FRect expandedCatPopup = categoryButtonsPopupRect;
        expandedCatPopup.h += 10.f;
        bool mouseInCategoryButtons = categoryButtonsPopupRect.w > 0
                                      && SDL_PointInRectFloat(&mousePt, &expandedCatPopup);
        if (!mouseInCategoryButtons) {
            for (int s = 0; s < (int)availableSlotRects.size(); s++) {
                if (SDL_PointInRectFloat(&mousePt, &availableSlotRects[s])){
                    hoveredAvailableBuilding = availableSlotInfo[s].first;
                    hoveredAvailableSlot = availableSlotInfo[s].second;
                    hoveredAvailableSlotRect = availableSlotRects[s];
                    hoveredCardIndex = availableSlotInfo[s].first;
                    categoryPopupCardIndex = hoveredCardIndex;
                    buildMenuSlotIndex = hoveredAvailableSlot;

                    // verifie if slot with existing building
                    std::vector<const Settlement*> provSCheck;
                    for (const auto& st : settlements)
                        if (st.settlementData.provinceID == provinceID) provSCheck.push_back(&st);
                    if (hoveredCardIndex < (int)provSCheck.size()) {
                        BuildingType existing = provSCheck[hoveredCardIndex]->settlementData.buildings[buildMenuSlotIndex];
                        if (existing != BuildingType::None) {
                            hoveredBuildingSlotUpgradable = true;
                            hoveredBuildingCategoryIndex = (int)GetBuildingCategory(existing);
                            BuildingType root = existing;
                            const auto& db = GetBuildingDatabase();
                            bool found = true;
                            while (found) {
                                found = false;
                                for (const auto& [key, val] : db) {
                                    if (val.upgradesTo == root) { root = key; found = true; break; }
                                }
                            }
                            hoveredCategoryBuildingType = root;
                            upgradableSlotRootBuilding = root;
                        }
                    }
                }
            }
        }
        //if mouse on popupEvolution, keep the current state
        SDL_FRect expandedEvolKeep = categoryEvolutionPopupRect;
        expandedEvolKeep.h += 20.f;
        if (hoveredAvailableSlot < 0 && previousUpgradableState &&
            categoryEvolutionPopupRect.w > 0 &&
            SDL_PointInRectFloat(&mousePt, &expandedEvolKeep)) {
            hoveredBuildingSlotUpgradable = true;
            }

        // To keep the popup of the constructions
        if (hoveredAvailableSlot < 0) {
            SDL_FRect expandedPopup = categoryButtonsPopupRect;
            expandedPopup.h += 10.f;

            // For an upgradable slot, only the evolution popup keep his state open
            bool bInBuildingCategoryButtons = !previousUpgradableState && categoryButtonsPopupRect.w > 0 && SDL_PointInRectFloat(&mousePt, &expandedPopup);
            SDL_FRect expandedEvolution = categoryEvolutionPopupRect;
            expandedEvolution.h += 20.f; // cover the gap between evolution popup and building categoriesButtons
            bool bInBuildingEvolitionButtons = categoryEvolutionPopupRect.w > 0 && SDL_PointInRectFloat(&mousePt, &expandedEvolution);
            if (bInBuildingCategoryButtons || bInBuildingEvolitionButtons) {
                hoveredAvailableSlot = 0; // keep popup open

                if (bInBuildingEvolitionButtons && previousUpgradableState) {
                    hoveredBuildingSlotUpgradable = true;
                }
            } else {
                categoryButtonsPopupRect = {0.f, 0.f, 0.f, 0.f}; // reset the rect
                categoryEvolutionPopupRect = {0.f,0.f,0.f,0.f};
                hoveredBuildingCategoryIndex = -1;
                upgradableSlotRootBuilding = BuildingType::None;
            }
        }

        // ~ Buildings Categories ~
        //military, Adv military, Defence, Economy, Religion,
        if (hoveredAvailableSlot >=0) {
            //const char* categoryNames[] = {"Mil", "Adv", "Def", "Eco", "Rel"};
            SDL_Color categoryColors[] = {
                {255, 26,  26,  255},
                {93, 23,  255,  255},
                {255,  255,  23, 255},
                {0, 131, 57,  255},
                {152, 0,  198, 255},
            };
            float buttonW = 65.f;
            float buttonH = 65.f;
            float buttonGap = 4.f;
            float totalButtonW = 5 * buttonW + 4 * buttonGap;
            float buttonStartX = hoveredAvailableSlotRect.x + (hoveredAvailableSlotRect.w - totalButtonW) / 2.f;
            float buttonY = hoveredAvailableSlotRect.y - buttonH - 6.f;

            //The rect of the buttons category
            categoryButtonsPopupRect = {buttonStartX, buttonY, totalButtonW, buttonW};
            SDL_FRect expandedEvolCheck = categoryEvolutionPopupRect;
            expandedEvolCheck.h += 20.f; // cover the gap that stop the buttons
            bool mouseOnEvolutionPopup = categoryEvolutionPopupRect.w > 0 && SDL_PointInRectFloat(&mousePt, &expandedEvolCheck);

            if (!hoveredBuildingSlotUpgradable) {
                for (int k = 0; k < 5; k++) {
                    SDL_FRect buttonsRect = {buttonStartX + k * (buttonW + buttonGap), buttonY, buttonW, buttonH};
                    //font de la couleur
                    SDL_SetRenderDrawColor(renderer, categoryColors[k].r, categoryColors[k].g, categoryColors[k].b, 200);
                    SDL_RenderFillRect(renderer, &buttonsRect);
                    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
                    SDL_RenderRect(renderer, &buttonsRect);

                    //render textures based of faction culture instead of text
                    if (province.owner == FactionZone::Knight) {
                        if (k == 0) SDL_RenderTexture(renderer, gameBuildingTypesGroupingMilitaryKnight, nullptr, &buttonsRect);
                        else if (k == 1) SDL_RenderTexture(renderer, gameBuildingTypesGroupingAdvMilitaryKnight, nullptr, &buttonsRect);
                        else if (k == 2) SDL_RenderTexture(renderer, gameBuildingTypesGroupingDefenceKnight, nullptr, &buttonsRect);
                        else if (k == 3) SDL_RenderTexture(renderer, gameBuildingTypesGroupingEconomyKnight, nullptr, &buttonsRect);
                        else if (k == 4) SDL_RenderTexture(renderer, gameBuildingTypesGroupingReligionKnight, nullptr, &buttonsRect);
                    }
                    else if (province.owner == FactionZone::Viking) {
                        if (k == 0) SDL_RenderTexture(renderer, gameBuildingTypesGroupingMilitaryViking, nullptr, &buttonsRect);
                        else if (k == 1) SDL_RenderTexture(renderer, gameBuildingTypesGroupingAdvMilitaryViking, nullptr, &buttonsRect);
                        else if (k == 2) SDL_RenderTexture(renderer, gameBuildingTypesGroupingDefenceViking, nullptr, &buttonsRect);
                        else if (k == 3) SDL_RenderTexture(renderer, gameBuildingTypesGroupingEconomyViking, nullptr, &buttonsRect);
                        else if (k == 4) SDL_RenderTexture(renderer, gameBuildingTypesGroupingReligionViking, nullptr, &buttonsRect);
                    }
                    else if (province.owner == FactionZone::Samurai) {
                        if (k == 0) SDL_RenderTexture(renderer, gameBuildingTypesGroupingMilitarySamurai, nullptr, &buttonsRect);
                        else if (k == 1) SDL_RenderTexture(renderer, gameBuildingTypesGroupingAdvMilitarySamurai, nullptr, &buttonsRect);
                        else if (k == 2) SDL_RenderTexture(renderer, gameBuildingTypesGroupingDefenceSamurai, nullptr, &buttonsRect);
                        else if (k == 3) SDL_RenderTexture(renderer, gameBuildingTypesGroupingEconomySamurai, nullptr, &buttonsRect);
                        else if (k == 4) SDL_RenderTexture(renderer, gameBuildingTypesGroupingReligionSamurai, nullptr, &buttonsRect);
                    }

                    // //TTF_SetTextString(gameStatUIText, categoryNames[k], 0);
                    // TTF_SetTextColor(gameStatUIText, 255, 255, 255, 255);
                    // int tw = 0, th = 0;
                    // TTF_GetTextSize(gameStatUIText, &tw, &th);
                    // TTF_DrawRendererText(gameStatUIText,buttonsRect.x + (buttonW - tw) / 2.f,buttonsRect.y + (buttonH - th) / 2.f);
                }
            }
            if (!mouseOnEvolutionPopup && !hoveredBuildingSlotUpgradable) {
                hoveredBuildingCategoryIndex = -1;
                for (int k = 0; k < 5; k++) {
                    SDL_FRect buttonsRect = {buttonStartX + k * (buttonW + buttonGap), buttonY, buttonW, buttonH};
                    if (SDL_PointInRectFloat(&mousePt, &buttonsRect)) {
                        hoveredBuildingCategoryIndex = k;
                    }
                }
            }
            // INDICATOR ON TOP OF THE BUILDING CATEGORIES
            if (hoveredBuildingCategoryIndex >= 0 && hoveredBuildingCategoryIndex < 5 && !mouseOnEvolutionPopup && !hoveredBuildingSlotUpgradable) {
                const char* categoryNames[] = {"Military", "Adv. Military", "Defence", "Economy", "Religion"};

                int tw = 0, th = 0;
                TTF_GetTextSize(gameBuildingCategoriesNameText, &tw, &th);

                float textX = lenghtX + 15.f;
                float textY = lenghtY - th;

                //rect
                SDL_SetRenderDrawColor(renderer, 10, 10, 10, 200);
                SDL_FRect categoryNamesBackground = {textX - 4.f, textY - 2.f, (float)tw + 8.f, (float)th + 4.f};
                SDL_RenderFillRect(renderer, &categoryNamesBackground);

                //text name
                TTF_SetTextString(gameBuildingCategoriesNameText, categoryNames[hoveredBuildingCategoryIndex], 0);
                TTF_SetTextColor(gameBuildingCategoriesNameText, 240, 240, 240, 255);
                TTF_DrawRendererText(gameBuildingCategoriesNameText, textX, textY);
            }


            //to stock their rectangles
            categoryButtonsRects.resize(5);
            for (int k = 0; k < 5; k++) {
                categoryButtonsRects[k] = {buttonStartX + k * (buttonW + buttonGap), buttonY, buttonW, buttonH};
            }
        }

        //TIER CHAIN POPUP (FOR THE MAIN SETTLEMENT BUILDING)
        float mxTier, myTier;
        SDL_GetMouseState(&mxTier, &myTier);
        float lxTier, lyTier;
        SDL_RenderCoordinatesFromWindow(renderer, mxTier, myTier, &lxTier, &lyTier);
        SDL_FPoint msPtTier = {lxTier, lyTier};

        int mainHoveredCard = -1;
        for (int i = 0; i < (int)mainBuildingSlotRects.size(); i++) {
            if (SDL_PointInRectFloat(&msPtTier, &mainBuildingSlotRects[i])) {
                mainHoveredCard = i;
                break;
            }
        }

        RenderBuildingCategoryEvolution();
        SDL_FRect expandedMainPopup = mainBuildingPopupRect;
        expandedMainPopup.h += 20.f;
        bool mouseOnExistingPopup = mainBuildingPopupRect.w > 0 && SDL_PointInRectFloat(&msPtTier, &expandedMainPopup);

        if ((mainHoveredCard >= 0 || mouseOnExistingPopup) && bButtonUIBuildingIsPressed
            && categoryButtonsPopupRect.w <= 0 && categoryEvolutionPopupRect.w <= 0) {
            if (mainHoveredCard >= 0) hoveredCardIndex = mainHoveredCard;

            if (hoveredCardIndex >= 0 && hoveredCardIndex < (int)provinceSettlements.size()) {

                const Settlement* provinceSettl = provinceSettlements[hoveredCardIndex];
                int currentTier = provinceSettl->settlementData.settlementTier;
                int maxTier = 3;//for the villages
                //for castle and capital its 5
                if (provinceSettl->settlementData.type == SettlementType::Castle || provinceSettl->settlementData.type == SettlementType::Capital) {
                    maxTier = 5;
                }


                float tileW  = 64.f;
                float tileH  = 64.f;
                float arrowH = 22.f;
                float totalH = maxTier * tileH + (maxTier - 1) * arrowH;

                float popX = mainBuildingSlotRects[hoveredCardIndex].x + (mainBuildingSlotRects[hoveredCardIndex].w - tileW) / 2.f;
                float popY = mainBuildingSlotRects[hoveredCardIndex].y - totalH - 15.f;
                if (popY < 5.f) popY = 5.f;

                // Background of popup
                SDL_SetRenderDrawColor(renderer, 10, 10, 10, 230);
                SDL_FRect bgRect = {popX - 12.f, popY - 8.f, tileW + 24.f, totalH + 16.f};
                SDL_RenderFillRect(renderer, &bgRect);
                mainBuildingPopupRect = bgRect;
                SDL_SetRenderDrawColor(renderer, factionColor.r, factionColor.g, factionColor.b, 120);
                SDL_RenderRect(renderer, &bgRect);

                // Tier 5 is UP → Tier 1 if down
                for (int t = maxTier; t >= 1; t--) {
                    int idx = maxTier - t;  // 0 = tier5(top), 4 = tier1(down)
                    float tierSquareY = popY + idx * (tileH + arrowH);

                    bool isCurrent  = (t == currentTier);
                    bool isNext = t == currentTier + 1 && currentTier < maxTier;
                    bool isUnlocked = (t < currentTier);

                    // square of tier
                    if (isCurrent) {
                        SDL_SetRenderDrawColor(renderer, factionColor.r, factionColor.g, factionColor.b, 255);
                    }
                    else if (isNext) {
                        SDL_SetRenderDrawColor(renderer, factionColor.r/2,factionColor.g/2,factionColor.b/2,255);
                    }
                    else if (isUnlocked) {
                        SDL_SetRenderDrawColor(renderer, factionColor.r,factionColor.g,factionColor.b,255);
                    }
                    else
                        SDL_SetRenderDrawColor(renderer, 22, 22, 22, 255);

                    SDL_FRect tierRect = {popX, tierSquareY, tileW, tileH};
                    SDL_RenderFillRect(renderer, &tierRect);

                    //textures of the building
                    SDL_Texture* textureBuilding = GetSettlementBuildingUpgradeTexture(province.owner,provinceSettl->settlementData.type, t );
                    if (textureBuilding) {
                        Uint8 alpha = isCurrent ? 255 : (isNext ? 180 : 60);
                        SDL_SetTextureAlphaMod(textureBuilding, alpha);
                        SDL_RenderTexture(renderer, textureBuilding, nullptr, &tierRect);
                        SDL_SetTextureAlphaMod(textureBuilding, 255); // reset
                    }
                    // Bordure
                    SDL_SetRenderDrawColor(renderer,
                        isCurrent ? factionColor.r : 65,
                        isCurrent ? factionColor.g : 65,
                        isCurrent ? factionColor.b : 65, 255);
                    SDL_RenderRect(renderer, &tierRect);
                    // Chiffre romain
                    const char* rn[] = {"I", "II", "III", "IV", "V"};
                    TTF_SetTextString(gameStatUIText, rn[t - 1], 0);
                    Uint8 la = isCurrent ? 255 : (isUnlocked ? 180 : 80);
                    TTF_SetTextColor(gameStatUIText, la, la, la, 255);
                    int tw = 0, th = 0;
                    TTF_GetTextSize(gameStatUIText, &tw, &th);
                    TTF_DrawRendererText(gameStatUIText,popX + (tileW - tw) / 2.f,tierSquareY + tileH - th - 5.f);


                    if (t > currentTier && t <= maxTier) {
                        BuildingType buildingAtTier = GetSettlementBuildingType(provinceSettl->settlementData.type, province.owner, t - 1);

                        const BuildingData* tierData = GetBuildingData(buildingAtTier);
                        const BuildingData* nextData = (tierData && tierData->upgradesTo != BuildingType::None)? GetBuildingData(tierData->upgradesTo) : nullptr;
                        int cost = nextData ? nextData->cost : 123456; // if the cost cannot be get from the dataBuilding section it returns 123456 (error)
                        int constructionTurns = nextData ? nextData->constructionTurns : 1;

                        std::string costString = std::to_string(cost);
                        TTF_SetTextString(gameBuildingCostUIText, costString.c_str(), 0);

                        //green if can purchase and red if to expensive
                        if (player.currentGold >= cost) {
                            TTF_SetTextColor(gameBuildingCostUIText, 127, 255, 0, 255);
                        }else {
                            TTF_SetTextColor(gameBuildingCostUIText, 220, 60, 60, 255);
                        }
                        int costW = 0, costH = 0;
                        TTF_GetTextSize(gameBuildingCostUIText, &costW, &costH);
                        TTF_DrawRendererText(gameBuildingCostUIText,popX + (tileW - costW) -2.f,tierSquareY + 45.f);

                        //texture gold
                        float iconSize = 12.f;
                        float totalRowW = iconSize + 3.f + costW;
                        float rowStartX = popX + (tileW - totalRowW) / 2.f;

                        SDL_FRect goldUI = {rowStartX + 57.f, tierSquareY + 48.f, iconSize, iconSize};
                        // SDL_SetRenderDrawColor(renderer, 220, 180, 40, 255);
                        // SDL_RenderFillRect(renderer, &goldUI);
                        // SDL_SetRenderDrawColor(renderer, 180, 140, 20, 255);
                        // SDL_RenderRect(renderer, &goldUI);
                        SDL_RenderTexture(renderer, gameCoinMoneyTexture, nullptr, &goldUI);

                        //Show the amount of turn before the building is constructed.
                        std::string timeConstructionAmountString = std::to_string(constructionTurns);
                        TTF_SetTextString(gameBuildingConstructionTimeText, timeConstructionAmountString.c_str(), 0);
                        int turnW = 0, turnH = 0;
                        TTF_GetTextSize(gameBuildingConstructionTimeText, &turnW, &turnH);
                        TTF_DrawRendererText(gameBuildingConstructionTimeText, popX + (tileW - turnW) -5.f,tierSquareY + 1.f);
                        //texture TurnTime Icon
                        float TurnIconSize = 12.f;
                        float TotalTurnRowW = TurnIconSize + 3.f + turnW;
                        float rowTurnStartX = popX + (tileW - TotalTurnRowW) / 2.f;

                        SDL_FRect turnUI = {rowTurnStartX + 43.f, tierSquareY + 5.f, TurnIconSize, TurnIconSize};
                        // SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
                        // SDL_RenderFillRect(renderer, &turnUI);
                        // SDL_SetRenderDrawColor(renderer, 180, 180, 180, 255);
                        // SDL_RenderFillRect(renderer, &turnUI);
                        SDL_RenderTexture(renderer, gameTurnAmountTexture, nullptr, &turnUI);

                    }


                    // up arrow between this current and next building upgrade
                    if (t > 1) {
                        float cx  = popX + tileW / 2.f;
                        float tipY = tierSquareY + tileH + 2.f;
                        float baseY = tierSquareY + tileH + arrowH - 2.f;
                        SDL_SetRenderDrawColor(renderer, 0, 180, 0, 200);
                        SDL_RenderLine(renderer, (int)cx, (int)tipY,  (int)cx, (int)baseY);
                        SDL_RenderLine(renderer, (int)cx, (int)tipY,  (int)(cx - 6), (int)(tipY + 8));
                        SDL_RenderLine(renderer, (int)cx, (int)tipY,  (int)(cx + 6), (int)(tipY + 8));
                    }
                    // Save the rect to detect the clic
                    if ((int)tierPopupRects.size() < maxTier)
                        tierPopupRects.resize(maxTier);
                    tierPopupRects[t - 1] = tierRect;
                    tierPopupMaxTier = maxTier;
                }
            }
            }

        if (bButtonUIGarrisonIsPressed) {
            //To Do later the garrison with Their Unit cards
        }
        // Title bottomProvince Title
        float middleTitlePositionX = 835.f;
        float middleTitlePositionY = 770.f;
        SDL_SetRenderDrawColor(renderer, factionColor.r, factionColor.g, factionColor.b, 180);
        SDL_FRect titleBottomBar = {middleTitlePositionX, middleTitlePositionY, 250.f, 40.f};
        SDL_RenderFillRect(renderer, &titleBottomBar);
        // Name province for bottomProvince Title
        TTF_SetTextString(gameStatUITitleText, province.name.c_str(), 0);
        TTF_SetTextColor(gameStatUITitleText, 255, 255, 255, 255);
        TTF_DrawRendererText(gameStatUITitleText, middleTitlePositionX + 50.f, middleTitlePositionY + 2.f);

        // Restore
        TTF_SetTextColor(gameStatUITitleText, 255, 255, 255, 255);

    }
    //fonction to buy a new building on a constructable square in RenderProvinceUI
    //Same has the main building
    void RenderBuildingCategoryEvolution() {
        categoryEvolutionTileRects.clear();
        if (hoveredBuildingCategoryIndex < 0 || !bHasClickedOnASettlement || selectedSettlementIndex < 0) return;
        if (categoryPopupCardIndex < 0 || categoryButtonsPopupRect.w <= 0) return;

        const Settlement& clickedSett = settlements[selectedSettlementIndex];
        int provID = clickedSett.settlementData.provinceID;
        const Province& prov = provinces[provID];
        FactionZone faction = prov.owner;

        std::vector<const Settlement*> provS;
        for (const auto& s : settlements)
            if (s.settlementData.provinceID == provID)
                provS.push_back(&s);
        if (categoryPopupCardIndex>= (int)provS.size()) return;
        const Settlement* cardSett = provS[categoryPopupCardIndex];
        int settlementTier = cardSett->settlementData.settlementTier;

        // faction color
        SDL_Color fc;
        if (faction == FactionZone::Knight) fc = {255, 215,   0, 255};
        else if (faction == FactionZone::Viking) fc = {255,   0,   0, 255};
        else fc = {  0, 200, 160, 255};


        BuildingCategory cat = (BuildingCategory)hoveredBuildingCategoryIndex;
        std::vector<BuildingType> rootBuildings = GetBuildingsForCategory(cat, faction, 5);
        if (rootBuildings.empty()) return;
        // if we hovered an existing building we show its evolutions
        if (hoveredBuildingSlotUpgradable && upgradableSlotRootBuilding != BuildingType::None) {
            rootBuildings.erase(
                std::remove_if(rootBuildings.begin(), rootBuildings.end(),
                    [&](BuildingType bt) { return bt != upgradableSlotRootBuilding; }),
                rootBuildings.end()
            );
            if (rootBuildings.empty()) return;
        }
        // upgrade chain chain.tiers[0]=T1, [last]=T_max
        struct Chain { std::vector<BuildingType> tiers; };
        std::vector<Chain> chains;
        for (BuildingType root : rootBuildings) {
            Chain c;
            BuildingType cur = root;
            while (cur != BuildingType::None) {
                c.tiers.push_back(cur);
                const BuildingData* d = GetBuildingData(cur);
                cur = (d && d->upgradesTo != BuildingType::None) ? d->upgradesTo : BuildingType::None;
            }
            chains.push_back(c);
        }

        int maxTierOverall = 0;
        for (auto& c : chains) {
            for (BuildingType bt : c.tiers) {
                const BuildingData* d = GetBuildingData(bt);
                if (d) maxTierOverall = std::max(maxTierOverall, d->Tier);
            }
        }
        //Main building Building W/H
        // float buttonW = 65.f;
        // float buttonH = 65.f;
        // float buttonGap = 4.f;
        // Layout
        float tileW  = 65.f;
        float tileH  = 65.f;
        float arrowH = 18.f;
        float colGap = 10.f;

        int maxLen = 0;
        for (auto& c : chains) maxLen = std::max(maxLen, (int)c.tiers.size());

        float totalW = (float)chains.size() * tileW + ((float)chains.size() - 1.f) * colGap;
        float totalH = (float)maxTierOverall * tileH + ((float)(maxTierOverall - 1)) * arrowH;

        // Position on top
        float popX = 400.f, popY = 300.f;
        if (hoveredBuildingSlotUpgradable) {
            // Position on top of the constructed building
            popX = hoveredAvailableSlotRect.x + hoveredAvailableSlotRect.w / 2.f - totalW / 2.f;
            popY = hoveredAvailableSlotRect.y - totalH - 14.f;
        }
        else if (hoveredBuildingCategoryIndex < (int)categoryButtonsRects.size()) {
            const SDL_FRect& btn = categoryButtonsRects[hoveredBuildingCategoryIndex];
            popX = btn.x + btn.w / 2.f - totalW / 2.f;
            popY = btn.y - totalH - 14.f;
        }
        if (popX < 5.f) popX = 5.f;
        if (popX + totalW > 1915.f) popX = 1915.f - totalW;
        if (popY < 5.f) popY = 5.f;

        // Fond of the popup
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer, 10, 10, 10, 230);
        SDL_FRect bg = {popX - 10.f, popY - 8.f, totalW + 20.f, totalH + 16.f};
        SDL_RenderFillRect(renderer, &bg);
        categoryEvolutionPopupRect = bg;
        SDL_SetRenderDrawColor(renderer, fc.r, fc.g, fc.b, 130);
        SDL_RenderRect(renderer, &bg);

        //Render each col
        for (int ci = 0; ci < (int)chains.size(); ci++) {
            const Chain& chain = chains[ci];
            int numTiers = (int)chain.tiers.size();
            float colX = popX + ci * (tileW + colGap);

            // Tier higer is 5 and lower is 1
            for (int ti = 0; ti < numTiers; ti++) {
                BuildingType bt = chain.tiers[numTiers - 1 - ti];
                const BuildingData* data = GetBuildingData(bt);
                if (!data) continue;

                int rowIndex = maxTierOverall - data->Tier; // 0 = top (tier le plus haut)
                float tileY = popY + rowIndex * (tileH + arrowH);
                bool isUnlocked = (data->Tier <= settlementTier);

                // Fond de la tuile
                if (isUnlocked)
                    SDL_SetRenderDrawColor(renderer, fc.r / 3, fc.g / 3, fc.b / 3, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
                SDL_FRect tileRect = {colX, tileY, tileW, tileH};
                SDL_RenderFillRect(renderer, &tileRect);

                //textures
                SDL_Texture* texture = GetBuildingTexture(bt);
                if (texture) {
                    Uint8 alpha;
                    if (bt == hoveredCategoryBuildingType) {
                        alpha = 255; // mouse on top
                    } else if (isUnlocked) {
                        alpha = 120;
                    } else {
                        alpha = 120; // locked
                    }
                    SDL_SetTextureAlphaMod(texture, alpha);
                    SDL_RenderTexture(renderer, texture, nullptr, &tileRect);
                    SDL_SetTextureAlphaMod(texture, 255); // reset
                }

                std::string tierStr = "T" + std::to_string(data->Tier);
                TTF_SetTextString(gameStatUIText, tierStr.c_str(), 0);
                Uint8 tierAlpha = isUnlocked ? 255 : 120;
                TTF_SetTextColor(gameStatUIText, tierAlpha, tierAlpha, tierAlpha, 255);
                TTF_DrawRendererText(gameStatUIText, colX - 5.f, tileY + tileH - 18.f);
                categoryEvolutionTileRects.push_back({tileRect, bt});//detection click
                // // Building name
                // TTF_SetTextString(gameStatUIText, data->name.c_str(), 0);
                // Uint8 nameAlpha = isUnlocked ? 220 : 80;
                // TTF_SetTextColor(gameStatUIText, nameAlpha, nameAlpha, nameAlpha, 255);
                // TTF_DrawRendererText(gameStatUIText, colX + 1.f, tileY + 3.f);

                // Cost + Icon
                std::string costStr = std::to_string(data->cost);
                TTF_SetTextString(gameBuildingCostUIText, costStr.c_str(), 0);
                //green
                if (player.currentGold >= data->cost)
                    TTF_SetTextColor(gameBuildingCostUIText, 127, 255, 0, 255);
                else //red
                    TTF_SetTextColor(gameBuildingCostUIText, 220, 60, 60, 255);
                //SDL_SetRenderDrawColor(renderer, 220, 180, 40, 255);
                SDL_FRect goldIcon = {colX + 63.f, tileY + tileH - 15.f, 12.f, 12.f};
                //SDL_RenderFillRect(renderer, &goldIcon);
                SDL_RenderTexture(renderer, gameCoinMoneyTexture, nullptr, &goldIcon);
                TTF_DrawRendererText(gameBuildingCostUIText, colX + 30.f, tileY + tileH - 19.f);

                // time construction
                std::string turnStr = std::to_string(data->constructionTurns);
                TTF_SetTextString(gameBuildingConstructionTimeText, turnStr.c_str(), 0);
                TTF_SetTextColor(gameBuildingConstructionTimeText, 180, 180, 255, 255);
                //SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255);
                SDL_FRect turnIcon = {colX + tileW - 3.f, tileY + tileH - 62.f, 12.f, 12.f};
                //SDL_RenderFillRect(renderer, &turnIcon);
                SDL_RenderTexture(renderer, gameTurnAmountTexture, nullptr, &turnIcon);
                TTF_DrawRendererText(gameBuildingConstructionTimeText, colX + tileW - 15.f, tileY + tileH - 65.f);

                //arrow towards next tier
                if (ti < numTiers - 1) {
                    BuildingType nextBt = chain.tiers[numTiers - 1 - (ti + 1)];
                    const BuildingData* nextData = GetBuildingData(nextBt);
                    if (nextData) {
                        int nextRowIndex = maxTierOverall - nextData->Tier;
                        float nextTileY = popY + nextRowIndex * (tileH + arrowH);
                        float cx   = colX + tileW / 2.f;
                        float tipY = tileY + tileH + 2.f;
                        float botY = nextTileY - 2.f;
                        SDL_SetRenderDrawColor(renderer, 0, 180, 0, 200);
                        SDL_RenderLine(renderer, (int)cx, (int)tipY, (int)cx,      (int)botY);
                        SDL_RenderLine(renderer, (int)cx, (int)tipY, (int)(cx - 5),(int)(tipY + 7));
                        SDL_RenderLine(renderer, (int)cx, (int)tipY, (int)(cx + 5),(int)(tipY + 7));
                    }
                }
            }
        }
    }



    //The top UI bar for the money / turn area
    void RenderGeneralUI() {
        //rectangle of the top ui part
        // Bordure
        float thickness = 5.0f;
        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
        SDL_FRect borderRect = {600, 0, 800, 40};
        SDL_RenderFillRect(renderer, &borderRect);

        //inner UI rectangle
        SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
        SDL_FRect contentRect = {600 + thickness,0 + thickness,800 - (thickness * 2),40 - (thickness * 2)};
        SDL_RenderFillRect(renderer, &contentRect);

        //icon Gold
        SDL_FRect goldIcon = {contentRect.x + 45.f, borderRect.y  + 10.f,20.f,20.f};
        // SDL_SetRenderDrawColor(renderer, 255,234,90,255);
        // SDL_RenderFillRect(renderer, &goldIcon);
        SDL_RenderTexture(renderer,gameCoinMoneyTexture, nullptr, &goldIcon);

        //current Gold
        std::string goldStr = std::to_string(player.currentGold);
        TTF_SetTextString(gameCurrentMoneyUiText, goldStr.c_str(), 0);
        TTF_SetTextColor(gameCurrentMoneyUiText, 255, 255, 255, 255); // keep in white
        TTF_DrawRendererText (gameCurrentMoneyUiText, contentRect.x + 70.f, contentRect.y + 4.f);

        //calculate gold next turn
        player.nextTurnGold = 0;
        for (const auto& s: settlements) {
            if (provinces[s.settlementData.provinceID].owner == player.faction) {
                // Upkeep du main building toujours déduit (même sans collecte de taxe)
                const BuildingData* mainBd = GetBuildingData(s.settlementData.buildings[0]);
                if (mainBd) player.nextTurnGold -= mainBd->upkeep;

                if (provinces[s.settlementData.provinceID].bToggleCollectIncome) {
                    player.nextTurnGold += s.settlementData.baseIncome;
                    for (int b = 1; b < (int)s.settlementData.buildings.size(); b++) {
                        if (s.settlementData.buildings[b] != BuildingType::None) {
                            const BuildingData* bd = GetBuildingData(s.settlementData.buildings[b]);
                            if (bd) player.nextTurnGold += bd->incomeBonus;
                        }
                    }
                }
            }
        }
        //Gold Next turn + (green) - (red)
        std::string nextTurnStr = "(" + (player.nextTurnGold >= 0 ? std::string("+") : std::string("")) + std::to_string(player.nextTurnGold) + ")";
        TTF_SetTextString(gameAnticipatedMoneyUiText, nextTurnStr.c_str(), 0);
        TTF_SetTextColor(gameAnticipatedMoneyUiText, player.nextTurnGold >= 0 ? 127 : 220, player.nextTurnGold >= 0 ? 255 : 60, 0, 255);
        TTF_DrawRendererText(gameAnticipatedMoneyUiText,contentRect.x + 125.f, contentRect.y + 4.f);

        //hovered Money Hoved Zone
        SDL_FRect moneyHoveredZone = {contentRect.x + 125.f, contentRect.y - 5.f, 50.f, 40.f };
        float mouseXMoney;
        float mouseYMoney;
        SDL_GetMouseState(&mouseXMoney, &mouseYMoney);
        float lenghtXMoney;
        float lenghtYMoney;
        SDL_RenderCoordinatesFromWindow(renderer, mouseXMoney, mouseYMoney, &lenghtXMoney, &lenghtYMoney);
        SDL_FPoint mousePointMoney = {lenghtXMoney, lenghtYMoney};
        //when bool true
        bMouseOnMoneyIcon = SDL_PointInRectFloat (&mousePointMoney, &moneyHoveredZone);
        moneyTooltipX = lenghtXMoney;
        moneyTooltipY = lenghtYMoney;


        //FOOD SECTION
        player.nextTurnFood = 0;
        player.foodStorage = 0;
        for (const auto &s : settlements) {
            if (provinces[s.settlementData.provinceID].owner != player.faction) continue;

            for (BuildingType building_type : s.settlementData.buildings) {
                if (building_type == BuildingType::None) continue;
                const BuildingData *building_data = GetBuildingData(building_type);
                if (!building_data)continue;
                player.nextTurnFood += building_data->foodProduced;
                player.nextTurnFood -= building_data->foodUpkeep;
                player.foodStorage += building_data->foodStorage;
            }

        }
        //Food texture
        SDL_FRect foodIconUIRect = {contentRect.x + 230.f, contentRect.y, 30.f,30.f};
        // SDL_SetRenderDrawColor(renderer, 120,255,255,255);
        // SDL_RenderFillRect(renderer, &foodIconUIRect);
        SDL_RenderTexture(renderer, gameFoodIconUi, nullptr, &foodIconUIRect);
        //food amount
        std::string foodAmountStr = std::to_string(player.currentFood);
        TTF_SetTextString(gameCurrentFoodUiText, foodAmountStr.c_str(), 0);
        TTF_SetTextColor(gameCurrentFoodUiText, 255,255,255,255);
        TTF_DrawRendererText(gameCurrentFoodUiText, contentRect.x + 256.f, contentRect.y + 4.f);

        //hovered food Zone
        SDL_FRect foodHoveredZone = {contentRect.x + 235.f, borderRect.y, 40.f, 40.f};
        float mouseXFood;
        float mouseYFood;
        SDL_GetMouseState(&mouseXFood, &mouseYFood);
        float lenghtXFood;
        float lenghtYFood;
        SDL_RenderCoordinatesFromWindow(renderer, mouseXFood, mouseYFood, &lenghtXFood, &lenghtYFood);
        SDL_FPoint mousePointFood = {lenghtXFood,lenghtYFood};
        //true if
        bMouseOnFoodIcon = SDL_PointInRectFloat(&mousePointFood, &foodHoveredZone);
        foodTooltipX = lenghtXFood;
        foodTooltipY = lenghtYFood;


        //food added because it is the production it increase only based on building not each turns with endturns
        player.currentFood = player.nextTurnFood;
        //SDL_Log("Food: %d ", player.currentFood, player.nextTurnFood);

        //Segment bar
        //food + bonus public order bonus
        if (player.currentFood >=  300) {
            filledSegs = 6;
        }
        else if (player.currentFood >= 150 && player.currentFood <300) {
            filledSegs = 5;
        }
        else if (player.currentFood >= 0 && player.currentFood < 150) {
            filledSegs = 4;
        }
        else if (player.currentFood < 0 && player.currentFood > -150) {
            filledSegs = 3;
        }
        else if (player.currentFood >= -150 && player.currentFood > -300) {
            filledSegs = 2;
        }
        else if (player.currentFood >= -300) {
            filledSegs = 1;
        }


        SDL_Color segColors[6] = {
            {190,  30,  30, 255},   // deep red
            {210,  80,  30, 255},   // orange-red
            {220, 160,  30, 255},   // orange-yellow
            {210, 210,  30, 255},   // yellow-green
            { 80, 200,  50, 255},   // green
            { 30, 170,  30, 255},   // deep green
        };
        const float segW = 20.f;
        const float segH = 14.f;
        const float segGap =  1.f;
        const float barX = contentRect.x + 280.f;
        const float barY = borderRect.y  +  13.f;

        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        for (int seg = 0; seg < 6; seg++) {
            SDL_FRect segRect = {barX + seg * (segW + segGap), barY, segW, segH};

            bool isActive = (seg < filledSegs);
            Uint8 segAlpha = 255;

            SDL_SetRenderDrawColor(renderer,
                segColors[seg].r, segColors[seg].g, segColors[seg].b, segAlpha);
            SDL_RenderFillRect(renderer, &segRect);
            SDL_SetRenderDrawColor(renderer, 70, 70, 70, 200);
            SDL_RenderRect(renderer, &segRect);
        }

        // Arrow indicator
        int indicatorSeg = std::clamp(filledSegs - 1, 0, 5);
        float arrowCX = barX + indicatorSeg * (segW + segGap) + segW / 2.f;
        float tipY = barY + segH + 2.f;   // points up towards the bar
        float arrowH = 6.f;

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 220);
        for (int dy = 0; dy <= (int)arrowH; dy++) {
            float t     = (float)dy / arrowH;
            float halfW = t * 5.f;   // widens as it goes down
            SDL_RenderLine(renderer,
                (int)(arrowCX - halfW), (int)(tipY + dy),
                (int)(arrowCX + halfW), (int)(tipY + dy));
        }


        //circle  button for the NextTurn Button
        SDL_SetRenderDrawColor(renderer, 0,80,255,0);
        RenderBoutonCercle(NextTurnButton, nullptr, gameNextTurnTexture,180, 180, 180);

        //Circle for the Technology Button
        SDL_SetRenderDrawColor(renderer, 0, 144,144,255);
        RenderBoutonCercle(TechnologyPannel, nullptr, nullptr, 180, 180, 180);
        //text to show the current Turn
        std::string endTurn = std::to_string(currentTurn);
        TTF_SetTextString(gameNumberOfTurnText, endTurn.c_str(), 0);
        TTF_SetTextColor(gameNumberOfTurnText, 255, 255, 255, 255);
        TTF_DrawRendererText(gameNumberOfTurnText, NextTurnButton.circleX+45.f, NextTurnButton.circleY+35.f);
        // --------------------------------
        // UI under the contentRect for The growth of the farmers, nobility and church prest.
        //thickness 5.f
        //border

        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
        SDL_FRect growthBorderRect = {825.f, 40.f, 350, 35};
        SDL_RenderFillRect(renderer, &growthBorderRect);
        //Background
        SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
        SDL_FRect growthContentRect = {825.f + thickness, 35.f + thickness , 350 - (thickness * 2),40 - (thickness * 2)};
        SDL_RenderFillRect(renderer, &growthContentRect);
        //inter lines to seperate the 3 types of population
        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
        SDL_FRect growthFirstLine = {935.f + thickness, 35.f + thickness, 10 - thickness , 40 - (thickness * 2)};
        SDL_RenderFillRect(renderer, &growthFirstLine);
        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
        SDL_FRect growthSecondLine = {1055.f + thickness, 35.f + thickness, 10 - thickness, 40 - (thickness * 2)};
        SDL_RenderFillRect(renderer, &growthSecondLine);
        //The rect of the different paysant type. Texture has well
        //paysantry
        //texture
        SDL_FRect peasantryGrowthLogoRect = {835.f + thickness, 38.f + thickness, 28 - thickness, 28 - thickness };
        SDL_SetRenderDrawColor(renderer, 60, 255, 60, 255);
        SDL_RenderFillRect(renderer, &peasantryGrowthLogoRect);
        //population amount
        std::string peasantryAmountStr = std::to_string(player.currentPeasantryAmount);
        TTF_SetTextString(gamePopulationIndicatorUiText, peasantryAmountStr.c_str(), 0);//convert to string
        TTF_SetTextColor(gamePopulationIndicatorUiText, 255,255,255,255);
        TTF_DrawRendererText(gamePopulationIndicatorUiText, 865.f + thickness, 38.f + thickness); // 30 from logo
        //Nobility
        //texture
        SDL_FRect nobilityGrowthLogoRect = {950.f + thickness, 38.f + thickness, 28 - thickness, 28 - thickness };
        SDL_SetRenderDrawColor(renderer,255,60,60,255);
        SDL_RenderFillRect(renderer, &nobilityGrowthLogoRect);
        //Population Amount
        std::string nobilityAmountStr = std::to_string(player.currentNobilityAmount);
        TTF_SetTextString(gamePopulationIndicatorUiText, nobilityAmountStr.c_str(), 0);
        TTF_SetTextColor(gamePopulationIndicatorUiText, 255,255,255,255);
        TTF_DrawRendererText(gamePopulationIndicatorUiText, 980.f + thickness, 38.f + thickness);
        //Church Clergy
        //texture
        SDL_FRect clergyGrowthLogoRect = {1070.f + thickness, 38.f + thickness, 28 - thickness, 28 - thickness};
        SDL_SetRenderDrawColor(renderer,148,0,211,255);
        SDL_RenderFillRect(renderer, &clergyGrowthLogoRect);
        //Population Amount
        std::string clergyAmountStr = std::to_string(player.currentClergyAmount);
        TTF_SetTextString(gamePopulationIndicatorUiText, clergyAmountStr.c_str(), 0);
        TTF_SetTextColor(gamePopulationIndicatorUiText, 255,255,255,255);
        TTF_DrawRendererText(gamePopulationIndicatorUiText, 1100.f + thickness,38.f + thickness);

        //hovered Different Populations Zone
        SDL_FRect peasantryHoveredZone = {825.f + thickness, 38.f + thickness, 60, 28};
        SDL_FRect nobilityHoveredZone = {940.f + thickness, 38.f + thickness, 60, 28};
        SDL_FRect clergyHoveredZone = {1060.f + thickness, 38.f + thickness, 60, 28 };

        float mouseXPopulation;
        float mouseYPopulation;
        SDL_GetMouseState(&mouseXPopulation, &mouseYPopulation);
        float lenghtXPopulation;
        float lenghtYPopulation;
        SDL_RenderCoordinatesFromWindow(renderer, mouseXPopulation, mouseYPopulation, &lenghtXPopulation, &lenghtYPopulation);
        SDL_FPoint mousePointPopulation = {lenghtXPopulation, lenghtYPopulation};
        //true if on peasantry or nobility or clergy zone
        if (SDL_PointInRectFloat(&mousePointPopulation, &peasantryHoveredZone)) {
            hoveredPopulationType = 0;
        } else if (SDL_PointInRectFloat(&mousePointPopulation, &nobilityHoveredZone)) {
            hoveredPopulationType = 1;
        } else if (SDL_PointInRectFloat(&mousePointPopulation, &clergyHoveredZone)) {
            hoveredPopulationType = 2;
        } else {
            hoveredPopulationType = -1;
        }
        bMouseOnPopulationIcon = (hoveredPopulationType >= 0);

        populationTooltipX = lenghtXPopulation;
        populationTooltipY = lenghtYPopulation;

    }
    //public order based on food (FILLEDS SEGS 1,2,3,4,5,6)
    /*
     * The famine arrives only when the foodStored reach 0. Otherwise theres no penalty
     */
    int GetFoodPublicOrderModifier() {
        switch (filledSegs) {
            case 1:
                return (player.foodStored > 0) ? 0 : -6;
            case 2:
                return (player.foodStored > 0) ? 0 : -4;
            case 3:
                return (player.foodStored > 0) ? 0 : -2;
            case 4: 
                return 1;
            case 5:
                return 2;
            case 6:
                return 3;

            default: return 0;
        }
    }
    //MONEY HOVERED UI FR DETAILS OF INCOME/UPKEEP
    void RenderMoneyTooltip() {
    if (!bMouseOnMoneyIcon) return;

    int taxIncome = 0;
    int buildingIncome = 0;
    int mainUpkeep = 0;
    int buildingMaintenance = 0;

    for (const auto& s : settlements) {
        if (provinces[s.settlementData.provinceID].owner != player.faction) continue; //must be the playerfaction

        //mainBuilding
        const BuildingData* mainBuilding = GetBuildingData(s.settlementData.buildings[0]);
        if (mainBuilding) mainUpkeep += mainBuilding->upkeep;
        //income
        if (provinces[s.settlementData.provinceID].bToggleCollectIncome) {
            taxIncome += s.settlementData.baseIncome;
            for (int b = 1; b < (int)s.settlementData.buildings.size(); b++) {
                if (s.settlementData.buildings[b] != BuildingType::None) {
                    const BuildingData* building_data = GetBuildingData(s.settlementData.buildings[b]);
                    if (building_data) {
                        buildingIncome += building_data->incomeBonus;
                        buildingMaintenance += building_data->upkeep;
                    }
                }
            }
        }
    }
    //income total + Expense total
    int totalIncome  = taxIncome + buildingIncome;
    int totalExpense = mainUpkeep + buildingMaintenance;
    int goldNextTurn = totalIncome - totalExpense;

    // Calcul dynamique de la hauteur
    float rowH   = 24.f;
    float titleH = 30.f;
    float sepH   = 10.f;
    float padTop =  4.f;
    float padBot =  8.f;

    //The Row shows if its not 0 and has a value
    int incomeRows = 0;
    if (taxIncome != 0) incomeRows++;
    if (buildingIncome != 0) incomeRows++;

    int expenseRows = 0;
    if (mainUpkeep != 0) expenseRows++;
    if (buildingMaintenance != 0) expenseRows++;

    float incomeSepH  = 0.f;
    if (incomeRows  > 0) incomeSepH  = sepH;

    float expenseSepH = 0.f;
    if (expenseRows > 0) expenseSepH = sepH;


    float tooltipW = 270.f;
        float tooltipH = titleH + padTop + incomeRows * rowH + incomeSepH + expenseRows * rowH + expenseSepH + 2 * rowH + sepH + rowH + padBot;

        float tooltipX = moneyTooltipX + 30.f;
        float tooltipY = moneyTooltipY + 30.f;
        if (tooltipX + tooltipW > 1910.f) tooltipX = moneyTooltipX - tooltipW - 12.f;
        if (tooltipY < 5.f) tooltipY = 5.f;

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    // Background
    SDL_SetRenderDrawColor(renderer, 12, 10, 8, 240);
    SDL_FRect background = {tooltipX, tooltipY, tooltipW, tooltipH};
    SDL_RenderFillRect(renderer, &background);

    // Title bar
    SDL_SetRenderDrawColor(renderer, 130, 100, 0, 255);
    SDL_FRect titleBar = {tooltipX, tooltipY, tooltipW, titleH};
    SDL_RenderFillRect(renderer, &titleBar);

    // Border
    SDL_SetRenderDrawColor(renderer, 180, 150, 30, 220);
    SDL_RenderRect(renderer, &background);

    // Title
    TTF_SetTextString(gameCurrentMoneyUiText, "Income", 0);
    TTF_SetTextColor(gameCurrentMoneyUiText, 255, 255, 255, 255);
    int textW, textH;
    TTF_GetTextSize(gameCurrentMoneyUiText, &textW, &textH);
    TTF_DrawRendererText(gameCurrentMoneyUiText,tooltipX + 100.f, tooltipY + 3.f);

    float lineY  = tooltipY + titleH + padTop;
    float labelX = tooltipX + 10.f;
    float rightX = tooltipX + tooltipW - 10.f;

    // Lambda row it skip if value is 0
    auto drawRow = [&](const char* label, int value, bool isExpense) {
        if (value == 0) return;

        TTF_SetTextString(gameMoneyIndicatorUiText, label, 0);
        TTF_SetTextColor(gameMoneyIndicatorUiText, 175, 170, 150, 255);
        TTF_DrawRendererText(gameMoneyIndicatorUiText, labelX, lineY);

        std::string operatorString = "";
        if (isExpense) {
            operatorString = "-" + std::to_string(std::abs(value));
        } else {
            operatorString = "+" + std::to_string(value);
        }
        TTF_SetTextString(gameMoneyIndicatorUiText, operatorString.c_str(), 0);
        if (isExpense) {
            TTF_SetTextColor(gameMoneyIndicatorUiText, 220, 60, 60, 255);
        } else {
            TTF_SetTextColor(gameMoneyIndicatorUiText, 100, 220, 60, 255);
        }
        int operatorStringW, operatorStringH;
        TTF_GetTextSize(gameMoneyIndicatorUiText, &operatorStringW, &operatorStringH);
        TTF_DrawRendererText(gameMoneyIndicatorUiText, rightX - operatorStringW, lineY);
        lineY += rowH;
    };

    // Lambda to separate de different types ----------------
    auto drawSep = [&]() {
        SDL_SetRenderDrawColor(renderer, 80, 70, 20, 200);
        SDL_RenderLine(renderer,tooltipX + 6.f,  lineY + 2.f,tooltipX + tooltipW - 6.f, lineY + 2.f);
        lineY += sepH;
    };

    // Lambda total This one is always shown to show total income and total upkeep
    auto drawTotal = [&](const char* label, int value, bool isExpense) {
        TTF_SetTextString(gameMoneyIndicatorUiText, label, 0);
        TTF_SetTextColor(gameMoneyIndicatorUiText, 215, 215, 215, 255);
        TTF_DrawRendererText(gameMoneyIndicatorUiText, labelX, lineY);

        std::string operatorString = "";
        if (isExpense) {
            operatorString = "-" + std::to_string(std::abs(value));
        } else {
            operatorString = "+" + std::to_string(value);
        }
        TTF_SetTextString(gameMoneyIndicatorUiText, operatorString.c_str(), 0);
        if (isExpense) {
            TTF_SetTextColor(gameMoneyIndicatorUiText, 220, 60, 60, 255);
        } else {
            TTF_SetTextColor(gameMoneyIndicatorUiText, 127, 255, 0, 255);
        }
        int operatorStringW, operatorStringH;
        TTF_GetTextSize(gameMoneyIndicatorUiText, &operatorStringW, &operatorStringH);
        TTF_DrawRendererText(gameMoneyIndicatorUiText, rightX - operatorStringW, lineY);
        lineY += rowH;
    };

    // Incomes
    drawRow("Taxes",           taxIncome,      false);
    drawRow("Building Income", buildingIncome, false);
    if (incomeRows > 0) drawSep();

    // Expenses
    drawRow("Army Upkeep",     mainUpkeep,          true);
    drawRow("Building Maint.", buildingMaintenance, true);
    if (expenseRows > 0) drawSep();

    // Totals
    drawTotal("Total Income",  totalIncome,  false);
    drawTotal("Total Expense", totalExpense, true);
    drawSep();

    // Gold Next Turn
    TTF_SetTextString(gameMoneyIndicatorUiText, "Gold Next Turn", 0);
    TTF_SetTextColor(gameMoneyIndicatorUiText, 255, 230, 100, 255);
    TTF_DrawRendererText(gameMoneyIndicatorUiText, labelX, lineY);
    {
        std::string operatorString = "";
        if (goldNextTurn >= 0) {
            operatorString = "+" + std::to_string(goldNextTurn);
            TTF_SetTextString(gameMoneyIndicatorUiText, operatorString.c_str(), 0);
            TTF_SetTextColor(gameMoneyIndicatorUiText, 127, 255, 0, 255);
        } else {
            operatorString = std::to_string(goldNextTurn);
            TTF_SetTextString(gameMoneyIndicatorUiText, operatorString.c_str(), 0);
            TTF_SetTextColor(gameMoneyIndicatorUiText, 220, 60, 60, 255);
        }
        int operatorStringW, operatorStringH;
        TTF_GetTextSize(gameMoneyIndicatorUiText, &operatorStringW, &operatorStringH);
        TTF_DrawRendererText(gameMoneyIndicatorUiText, rightX - operatorStringW, lineY);
    }
}

    //FOOD HOVERED UI
    void RenderFoodTooltip() {
    if (!bMouseOnFoodIcon) return;

//calcul food from buildings + units food cost (placeholders)
        int buildingFoodTotal = 0;
        for (const auto &s : settlements) {
            if (provinces[s.settlementData.provinceID].owner != player.faction) continue;
            for (BuildingType bt : s.settlementData.buildings) {
                if (bt == BuildingType::None) continue;
                const BuildingData *bd = GetBuildingData(bt);
                if (!bd) continue;
                buildingFoodTotal += bd->foodProduced;
                buildingFoodTotal -= bd->foodUpkeep;
            }
        }
        int unitsFoodTotal = 0; // placeholder

    //Food hoved Rectangle
        float tooltipW = 260.f;
        float tooltipH = 260.f;

        float tooltipX = foodTooltipX + 30.f;
        float tooltipY = foodTooltipY - tooltipH + 290.f;
        if (tooltipX + tooltipW > 1910.f) tooltipX = foodTooltipX - tooltipW - 12.f;
        if (tooltipY < 5.f) tooltipY = 5.f;

        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

        // Background
        SDL_SetRenderDrawColor(renderer, 12, 10, 8, 240);
        SDL_FRect bg = {tooltipX, tooltipY, tooltipW, tooltipH};
        SDL_RenderFillRect(renderer, &bg);

        // Title bar
        SDL_SetRenderDrawColor(renderer, 25, 65, 55, 255);
        SDL_FRect titleBar = {tooltipX, tooltipY, tooltipW, 28.f};
        SDL_RenderFillRect(renderer, &titleBar);
        //Text Title
        std::string currentFoodString = std::to_string(player.currentFood);
        TTF_SetTextString(gameFoodIndicatorUiText, currentFoodString.c_str() , 0);
        //color red/Green
        if (player.currentFood > 0) {
            TTF_SetTextColor(gameFoodIndicatorUiText, 0, 255, 0, 255); //Green positif
        }
        else {
            TTF_SetTextColor (gameFoodIndicatorUiText, 255, 0, 0, 255); //red if negatif
        }
        TTF_DrawRendererText(gameFoodIndicatorUiText, tooltipX + 25.f, tooltipY + 3.f);
        TTF_SetTextString (gameFoodIndicatorUiText, "Net Food This Turn", 0);
        TTF_SetTextColor (gameFoodIndicatorUiText, 255,255,255,255);
        TTF_DrawRendererText(gameFoodIndicatorUiText, tooltipX + 50.f, tooltipY + 3.f);

        //food stored amount
        std::string foodStoredString = "You have " + std::to_string (player.foodStored) + "/" + std::to_string (player.foodStorage) + " Food Stores.";
        TTF_SetTextString(gameCurrentFoodUiText,  foodStoredString.c_str(), 0);
        TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 5.f, tooltipY + 40.f);
        //surplus
        int foodSurplus = 0;
        switch (filledSegs) {
            case 1: foodSurplus = -9; break;
            case 2: foodSurplus = -6; break;
            case 3: foodSurplus = -3; break;
            case 4: foodSurplus =  3; break;
            case 5: foodSurplus =  6; break;
            case 6: foodSurplus =  9; break;
        }

        TTF_SetTextString (gameCurrentFoodUiText, "Surplus:", 0);
        TTF_SetTextColor (gameCurrentFoodUiText, 255, 255, 255, 255);
        TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 5.f,tooltipY +60.f);

        std::string foodSurplusString = (foodSurplus >= 0 ? std::string("+") : std::string("")) + std::to_string(foodSurplus);
        TTF_SetTextString(gameCurrentFoodUiText, foodSurplusString.c_str(), 0);
        if (foodSurplus >= 0) {
            TTF_SetTextColor(gameCurrentFoodUiText, 0, 255, 0, 255);
        }
        else {
            TTF_SetTextColor (gameCurrentFoodUiText, 255, 0, 0, 255);
        }
        TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 65.f, tooltipY + 60.f);

        // Units & Buildings
float rightEdge = tooltipX + tooltipW - 10.f;

TTF_SetTextString(gameCurrentFoodUiText, "Units Upkeep", 0);
TTF_SetTextColor(gameCurrentFoodUiText, 255, 255, 255, 255);
TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 5.f, tooltipY + 82.f);
{
    std::string unitsStr = std::to_string(unitsFoodTotal);
    TTF_SetTextString(gameCurrentFoodUiText, unitsStr.c_str(), 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 255, 255, 255, 255);
    int vW, vH;
    TTF_GetTextSize(gameCurrentFoodUiText, &vW, &vH);
    TTF_DrawRendererText(gameCurrentFoodUiText, rightEdge - vW, tooltipY + 82.f);
}

TTF_SetTextString(gameCurrentFoodUiText, "Farms", 0);
TTF_SetTextColor(gameCurrentFoodUiText, 255, 255, 255, 255);
TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 5.f, tooltipY + 102.f);
{
    std::string bldStr = (buildingFoodTotal >= 0 ? "+" : "") + std::to_string(buildingFoodTotal);
    TTF_SetTextString(gameCurrentFoodUiText, bldStr.c_str(), 0);
    TTF_SetTextColor(gameCurrentFoodUiText,
        buildingFoodTotal >= 0 ? 127 : 220,
        buildingFoodTotal >= 0 ? 255 : 60, 0, 255);
    int vW, vH; TTF_GetTextSize(gameCurrentFoodUiText, &vW, &vH);
    TTF_DrawRendererText(gameCurrentFoodUiText, rightEdge - vW, tooltipY + 102.f);
}

// Effects to show the user
TTF_SetTextString(gameFoodIndicatorUiText, "Effects", 0);
TTF_SetTextColor(gameFoodIndicatorUiText, 255, 255, 255, 255);
TTF_DrawRendererText(gameFoodIndicatorUiText, tooltipX + 90.f, tooltipY + 130.f);

if (player.currentFood >= 300) {
    SDL_FRect publicOrderBonusIcon = {tooltipX + 5.f, tooltipY + 162.f, 20, 20};
    SDL_RenderTexture(renderer, gamePublicOrderPositifTexture, nullptr, &publicOrderBonusIcon);
    TTF_SetTextString(gameCurrentFoodUiText, "Public Order :", 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 255, 255, 255, 255);
    TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 35.f, tooltipY + 162.f);
    TTF_SetTextString(gameCurrentFoodUiText, " (+3) ", 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 0, 255, 0, 255);
    TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 130.f, tooltipY + 162.f);
    SDL_FRect populationGrowthIcon = {tooltipX + 5.f, tooltipY + 202.f, 20, 20};
    SDL_RenderTexture(renderer, gamePopulationPositiveGrowth, nullptr, &populationGrowthIcon);
    TTF_SetTextString(gameCurrentFoodUiText, "200% Base Population Growth \n                        (All Provinces) ", 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 255, 255, 255, 255);
    TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 35.f, tooltipY + 202.f);
}
else if (player.currentFood >= 150 && player.currentFood < 300) {
    SDL_FRect publicOrderBonusIcon = {tooltipX + 5.f, tooltipY + 162.f, 20, 20};
    SDL_RenderTexture(renderer, gamePublicOrderPositifTexture, nullptr, &publicOrderBonusIcon);
    TTF_SetTextString(gameCurrentFoodUiText, "Public Order :", 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 255, 255, 255, 255);
    TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 35.f, tooltipY + 162.f);
    TTF_SetTextString(gameCurrentFoodUiText, " (+2) ", 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 0, 255, 0, 255);
    TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 130.f, tooltipY + 162.f);
    SDL_FRect populationGrowthIcon = {tooltipX + 5.f, tooltipY + 202.f, 20, 20};
    SDL_RenderTexture(renderer, gamePopulationPositiveGrowth, nullptr, &populationGrowthIcon);
    TTF_SetTextString(gameCurrentFoodUiText, "100% Base Population Growth \n                        (All Provinces) ", 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 255, 255, 255, 255);
    TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 35.f, tooltipY + 202.f);
}
else if (player.currentFood >= 0 && player.currentFood < 150) {
    SDL_FRect publicOrderBonusIcon = {tooltipX + 5.f, tooltipY + 162.f, 20, 20};
    SDL_RenderTexture(renderer, gamePublicOrderPositifTexture, nullptr, &publicOrderBonusIcon);
    TTF_SetTextString(gameCurrentFoodUiText, "Public Order :", 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 255, 255, 255, 255);
    TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 35.f, tooltipY + 162.f);
    TTF_SetTextString(gameCurrentFoodUiText, " (+1) ", 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 0, 255, 0, 255);
    TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 130.f, tooltipY + 162.f);
    SDL_FRect populationGrowthIcon = {tooltipX + 5.f, tooltipY + 202.f, 20, 20};
    SDL_RenderTexture(renderer, gamePopulationPositiveGrowth, nullptr, &populationGrowthIcon);
    TTF_SetTextString(gameCurrentFoodUiText, "50% Base Population Growth \n                        (All Provinces) ", 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 255, 255, 255, 255);
    TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 35.f, tooltipY + 202.f);
}
else if (player.currentFood < 0 && player.currentFood > -150) {
    SDL_FRect publicOrderBonusIcon = {tooltipX + 5.f, tooltipY + 162.f, 20, 20};
    SDL_RenderTexture(renderer, gamePublicOrderNegatifTexture, nullptr, &publicOrderBonusIcon);
    TTF_SetTextString(gameCurrentFoodUiText, "Public Order :", 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 255, 255, 255, 255);
    TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 35.f, tooltipY + 162.f);
    TTF_SetTextString(gameCurrentFoodUiText, " (-2) ", 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 255, 0, 0, 255);
    TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 130.f, tooltipY + 162.f);
    SDL_FRect populationGrowthIcon = {tooltipX + 5.f, tooltipY + 202.f, 20, 20};
    SDL_RenderTexture(renderer, gamePopulationNegativeGrowth, nullptr, &populationGrowthIcon);
    TTF_SetTextString(gameCurrentFoodUiText, "-20% Base Population Growth \n                        (All Provinces) ", 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 255, 255, 255, 255);
    TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 35.f, tooltipY + 202.f);
}
else if (player.currentFood >= -150 && player.currentFood > -300) {
    SDL_FRect publicOrderBonusIcon = {tooltipX + 5.f, tooltipY + 162.f, 20, 20};
    SDL_RenderTexture(renderer, gamePublicOrderNegatifTexture, nullptr, &publicOrderBonusIcon);
    TTF_SetTextString(gameCurrentFoodUiText, "Public Order :", 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 255, 255, 255, 255);
    TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 35.f, tooltipY + 162.f);
    TTF_SetTextString(gameCurrentFoodUiText, " (-4) ", 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 255, 0, 0, 255);
    TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 130.f, tooltipY + 162.f);
    SDL_FRect populationGrowthIcon = {tooltipX + 5.f, tooltipY + 202.f, 20, 20};
    SDL_RenderTexture(renderer, gamePopulationNegativeGrowth, nullptr, &populationGrowthIcon);
    TTF_SetTextString(gameCurrentFoodUiText, "-60% Base Population Growth \n                        (All Provinces) ", 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 255, 255, 255, 255);
    TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 35.f, tooltipY + 202.f);
}
else if (player.currentFood >= -300) {
    SDL_FRect publicOrderBonusIcon = {tooltipX + 5.f, tooltipY + 162.f, 20, 20};
    SDL_RenderTexture(renderer, gamePublicOrderNegatifTexture, nullptr, &publicOrderBonusIcon);
    TTF_SetTextString(gameCurrentFoodUiText, "Public Order :", 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 255, 255, 255, 255);
    TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 35.f, tooltipY + 162.f);
    TTF_SetTextString(gameCurrentFoodUiText, " (-6) ", 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 255, 0, 0, 255);
    TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 130.f, tooltipY + 162.f);
    SDL_FRect populationGrowthIcon = {tooltipX + 5.f, tooltipY + 202.f, 20, 20};
    SDL_RenderTexture(renderer, gamePopulationNegativeGrowth, nullptr, &populationGrowthIcon);
    TTF_SetTextString(gameCurrentFoodUiText, "-100% Base Population Growth \n                        (All Provinces) ", 0);
    TTF_SetTextColor(gameCurrentFoodUiText, 255, 255, 255, 255);
    TTF_DrawRendererText(gameCurrentFoodUiText, tooltipX + 35.f, tooltipY + 202.f);
}

// Border
SDL_SetRenderDrawColor(renderer, 90, 170, 140, 255);
SDL_RenderRect(renderer, &bg);

}
    //Population Hovered Ui Show
    void RenderPopulationTooltip() {
    if (!bMouseOnPopulationIcon) return;

    const char *populationTitleStr = "";
    const char *populationDescriptionStr = "";
    const char *populationDescriptionYellowStr = "";
    const char *populationDescriptionGreenStr = "";//for peasantry and clergy
    const char *populationDescriptionRedStr = "";//For nobility
    int amount = 0;

    //peasantry
    if (hoveredPopulationType == 0) {
        amount = player.currentPeasantryAmount;
        populationTitleStr = "Peasantry";
        populationDescriptionStr = "The sound of the whetstone and the lowing of cattle return to the shires.There is enough labor to maintain the status quo.";
        populationDescriptionYellowStr = "Peasant manpower grows over time, and grows faster when food is plentiful. When peasants are recruited into armies, settleents are raided or sacked, or famine strikes, manpower will be lost.";
        populationDescriptionGreenStr = "When peasants are plentiful, the economy and construction time will improve, your kingdom will also be able to replenish armies faster.";
    }
    //Nobility
    else if (hoveredPopulationType == 1) {
        amount = player.currentNobilityAmount;
        populationTitleStr = "Nobility";
        populationDescriptionStr = "An established noble class ensures the King's peace. From the highest jarl to the lowest thegn, the chain of command is unbroken and effective.";
        populationDescriptionYellowStr = "Noble manpower grows over time, and can be increased by improving the Allegiance of your regions. When nobles are recruited into armies, settlements are raided or sacked, or famine strikes, manpower will be lost.";
        populationDescriptionRedStr = "Authority falters when the Lords are outnumbered by more than ten-to-one, or when the noble headcount falls too low to oversee the King's lands.";
    }
    //Clergy
    else if (hoveredPopulationType == 2) {
        amount = player.currentClergyAmount;
        populationTitleStr = "Clergy";
        populationDescriptionStr = "Humble chapels begin to rise, faith is the most important to have a united Kingdom. The faith is a flickering candle in the dark.";
        populationDescriptionYellowStr = "Clergy are trained over time in Abbeys and Monasteries throughout your kingdom. When settlements containing your churchers are sacked, clergy will be lost.";
        populationDescriptionGreenStr = "A large clergy brings improved Public Order, improved allegiance, faster Research Rate, and a decrease in monastery building costs and time.";
    }

    float labelX = 0.f;
    float rightX = 0.f;
    float rowH = 22.f;
    float sepH = 8.f;

    // calculate bonus building for population
    int buildingBonus = 0;
    for (const auto& s : settlements) {
        if (provinces[s.settlementData.provinceID].owner != player.faction) continue;
        for (BuildingType bt : s.settlementData.buildings) {
            if (bt == BuildingType::None) continue;
            const BuildingData* bd = GetBuildingData(bt);
            if (!bd) continue;
            if (hoveredPopulationType == 0) buildingBonus += bd->peasantryBornBonus;
            else if (hoveredPopulationType == 1) buildingBonus += bd->nobilityBornBonus;
            else if (hoveredPopulationType == 2) buildingBonus += bd->clergyTrainedBonus;
        }
    }


    //Population hoved Rectangle
    float tooltipW = 260.f;
    float titleBarH = 28.f;
    float padH = 10.f;
    float wrapW = tooltipW - 10.f; //5px margin for each side

    // measure description before laying out the rec
    TTF_SetTextWrapWidth(gameCurrentPopulationUiText, (int)wrapW);
    TTF_SetTextString(gameCurrentPopulationUiText, populationDescriptionStr, 0);
    TTF_SetTextString(gameCurrentPopulationUiText, populationDescriptionYellowStr, 0);
    TTF_SetTextString(gameCurrentPopulationUiText, populationDescriptionGreenStr, 0);
    TTF_SetTextString(gameCurrentPopulationUiText, populationDescriptionRedStr, 0);
    int descW, descH;
    TTF_GetTextSize(gameCurrentPopulationUiText, &descW, &descH);
    float tooltipH = titleBarH + padH + (float)descH + padH;

    float tooltipX = populationTooltipX + 30.f;
    float tooltipY = populationTooltipY + 30.f;
    if (tooltipX + tooltipW > 1910.f) tooltipX = populationTooltipX - tooltipW - 12.f;
    if (tooltipY < 5.f) tooltipY = 5.f;

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    // Background
    SDL_SetRenderDrawColor(renderer, 12, 10, 8, 240);
    SDL_FRect bg = {tooltipX, tooltipY, tooltipW, tooltipH};
    SDL_RenderFillRect(renderer, &bg);
    // Title bar
    SDL_SetRenderDrawColor(renderer, 25, 65, 55, 255);
    SDL_FRect titleBar = {tooltipX, tooltipY, tooltipW, 28.f};
    SDL_RenderFillRect(renderer, &titleBar);
    SDL_SetRenderDrawColor(renderer, 90, 170, 140, 255);
    SDL_RenderRect(renderer, &bg);
    //Text Title
        TTF_SetTextWrapWidth(gamePopulationIndicatorUiText, 0); // no wrap for title
        TTF_SetTextString(gamePopulationIndicatorUiText, populationTitleStr, 0);
        TTF_SetTextColor(gamePopulationIndicatorUiText, 255, 255, 255, 255);
        int titleW, titleH;
        TTF_GetTextSize(gamePopulationIndicatorUiText, &titleW, &titleH);
        TTF_DrawRendererText(gamePopulationIndicatorUiText,
            tooltipX + (tooltipW - titleW) / 2.f,
            tooltipY + (titleBarH - titleH) / 2.f);
        // Description text (already wrapped)
        TTF_SetTextColor(gameCurrentPopulationUiText, 255, 255, 255, 255);
        TTF_DrawRendererText(gameCurrentPopulationUiText,
            tooltipX + 5.f,
            tooltipY + titleBarH + padH / 2.f);

        // Reset wrap width so other text objects are unaffected
        //Yellow Description Text
        TTF_SetTextColor(gameCurrentPopulationUiText, 255,255,0,255);
        TTF_DrawRendererText(gameCurrentPopulationUiText,
            tooltipX + 5.f,
            tooltipY + titleBarH + padH / 2.f);


}



        //for the information about a specific Building when mouse on it
   void RenderBuildingInfoUI() {
    if (hoveredSlotIndex != 0 || hoveredCardIndex < 0 || !bHasClickedOnASettlement) return;

    const Settlement& clicked = settlements[selectedSettlementIndex];
    int provID = clicked.settlementData.provinceID;
    const Province& province = provinces[provID];

    std::vector<const Settlement*> provS;
    for (const auto& s : settlements)
        if (s.settlementData.provinceID == provID) provS.push_back(&s);

    if (hoveredCardIndex >= (int)provS.size()) return;
    const Settlement* s = provS[hoveredCardIndex];

    int tierToShow = (hoveredTierPopupIndex > 0)? hoveredTierPopupIndex: (s->settlementData.bBuidingUnderConstruction? s->settlementData.pendingTier: s->settlementData.settlementTier);

    BuildingType buildingType  = GetSettlementBuildingType(s->settlementData.type, province.owner, tierToShow); // to get the building name and is tier
    const BuildingData* data = GetBuildingData(buildingType);
    if (!data) return;

    SDL_Color fc;
    if (province.owner == FactionZone::Knight) fc = {255, 215,   0, 255};
    else if (province.owner == FactionZone::Viking) fc = {255,   0,   0, 255};
    else fc = {  0, 255, 215, 255};//samurai

    float tooltipX = 0.f;
    float tooltipW = 250.f;
    float tooltipH = 175.f;
    float tooltipY = 708.f - tooltipH - 6.f;

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    SDL_SetRenderDrawColor(renderer, 15, 15, 15, 220);
    SDL_FRect bg = {tooltipX, tooltipY, tooltipW, tooltipH};
    SDL_RenderFillRect(renderer, &bg);

    SDL_SetRenderDrawColor(renderer, fc.r, fc.g, fc.b, 180);
    SDL_FRect titleBar = {tooltipX, tooltipY, tooltipW, 30.f};
    SDL_RenderFillRect(renderer, &titleBar);

    SDL_SetRenderDrawColor(renderer, fc.r, fc.g, fc.b, 255);
    SDL_RenderRect(renderer, &bg);

    TTF_SetTextString(gameStatUITitleText, data->name.c_str(), 0);
    TTF_SetTextColor(gameStatUITitleText, 255, 255, 255, 255);
    TTF_DrawRendererText(gameStatUITitleText, tooltipX + 8.f, tooltipY + 4.f);

    float lineY = tooltipY + 36.f;

    //building description
    TTF_SetTextString(gameBuildingDescriptionText, (data->description).c_str(), 0);
        TTF_SetTextColor(gameBuildingDescriptionText, 180, 230, 100, 255);
        TTF_DrawRendererText(gameBuildingDescriptionText, tooltipX + 15.f, lineY);
    lineY += 80.f;
    // Income bonus
    SDL_SetRenderDrawColor(renderer, 220, 180, 40, 255);
    SDL_FRect goldIcon = {tooltipX + 8.f, lineY + 3.f, 12.f, 12.f};
    SDL_RenderFillRect(renderer, &goldIcon);
    TTF_SetTextString(gameStatUIText, "Income:", 0);
    TTF_SetTextColor(gameStatUIText, 180, 180, 180, 255);
    TTF_DrawRendererText(gameStatUIText, tooltipX + 26.f, lineY);
    TTF_SetTextString(gameStatUIText, ("+" + std::to_string(data->incomeBonus)).c_str(), 0);
    TTF_SetTextColor(gameStatUIText, 180, 230, 100, 255);
    TTF_DrawRendererText(gameStatUIText, tooltipX + 190.f, lineY);
    lineY += 26.f;

    // Public order bonus
    SDL_SetRenderDrawColor(renderer, 80, 200, 80, 255);
    SDL_FRect orderIcon = {tooltipX + 8.f, lineY + 3.f, 12.f, 12.f};
    SDL_RenderFillRect(renderer, &orderIcon);
    TTF_SetTextString(gameStatUIText, "Public Order:", 0);
    TTF_SetTextColor(gameStatUIText, 180, 180, 180, 255);
    TTF_DrawRendererText(gameStatUIText, tooltipX + 26.f, lineY);
    TTF_SetTextString(gameStatUIText, ("+" + std::to_string(data->publicOrderBonus)).c_str(), 0);
    TTF_SetTextColor(gameStatUIText, 71, 255, 164, 255);
    TTF_DrawRendererText(gameStatUIText, tooltipX + 190.f, lineY);
}
void RenderCategoryBuildingInfoUI() {
    if (hoveredCategoryBuildingType == BuildingType::None) return;

    const BuildingData* data = GetBuildingData(hoveredCategoryBuildingType);
    if (!data) return;

    if (!bHasClickedOnASettlement || selectedSettlementIndex < 0) return;
    int provID = settlements[selectedSettlementIndex].settlementData.provinceID;
    const Province& province = provinces[provID];

    SDL_Color fc;
    if (province.owner == FactionZone::Knight) fc = {255, 215,   0, 255};
    else if (province.owner == FactionZone::Viking)  fc = {255,   0,   0, 255};
    else fc = {  0, 255, 215, 255};

    float tooltipX = 0.f;
    float tooltipW = 250.f;
    float tooltipH = 175.f;
    float tooltipY = 708.f - tooltipH - 6.f;

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    // Fond
    SDL_SetRenderDrawColor(renderer, 15, 15, 15, 220);
    SDL_FRect bg = {tooltipX, tooltipY, tooltipW, tooltipH};
    SDL_RenderFillRect(renderer, &bg);

    // Barre titre
    SDL_SetRenderDrawColor(renderer, fc.r, fc.g, fc.b, 180);
    SDL_FRect titleBar = {tooltipX, tooltipY, tooltipW, 30.f};
    SDL_RenderFillRect(renderer, &titleBar);

    // Bordure
    SDL_SetRenderDrawColor(renderer, fc.r, fc.g, fc.b, 255);
    SDL_RenderRect(renderer, &bg);

    // Nom du building
    TTF_SetTextString(gameStatUITitleText, data->name.c_str(), 0);
    TTF_SetTextColor(gameStatUITitleText, 255, 255, 255, 255);
    TTF_DrawRendererText(gameStatUITitleText, tooltipX + 8.f, tooltipY + 4.f);

    float lineY = tooltipY + 36.f;

    // Description
    if (!data->description.empty()) {
        TTF_SetTextString(gameBuildingDescriptionText, data->description.c_str(), 0);
        TTF_SetTextColor(gameBuildingDescriptionText, 180, 230, 100, 255);
        TTF_DrawRendererText(gameBuildingDescriptionText, tooltipX + 8.f, lineY);
    }
    lineY += 80.f;

    // Income bonus
    SDL_SetRenderDrawColor(renderer, 220, 180, 40, 255);
    SDL_FRect goldIcon = {tooltipX + 8.f, lineY + 3.f, 12.f, 12.f};
    SDL_RenderFillRect(renderer, &goldIcon);
    TTF_SetTextString(gameStatUIText, "Income:", 0);
    TTF_SetTextColor(gameStatUIText, 180, 180, 180, 255);
    TTF_DrawRendererText(gameStatUIText, tooltipX + 26.f, lineY);
    TTF_SetTextString(gameStatUIText, ("+" + std::to_string(data->incomeBonus)).c_str(), 0);
    TTF_SetTextColor(gameStatUIText, 180, 230, 100, 255);
    TTF_DrawRendererText(gameStatUIText, tooltipX + 190.f, lineY);
    lineY += 26.f;

    // Public order bonus
    SDL_SetRenderDrawColor(renderer, 80, 200, 80, 255);
    SDL_FRect orderIcon = {tooltipX + 8.f, lineY + 3.f, 12.f, 12.f};
    SDL_RenderFillRect(renderer, &orderIcon);
    TTF_SetTextString(gameStatUIText, "Public Order:", 0);
    TTF_SetTextColor(gameStatUIText, 180, 180, 180, 255);
    TTF_DrawRendererText(gameStatUIText, tooltipX + 26.f, lineY);
    TTF_SetTextString(gameStatUIText, ("+" + std::to_string(data->publicOrderBonus)).c_str(), 0);
    TTF_SetTextColor(gameStatUIText, 71, 255, 164, 255);
    TTF_DrawRendererText(gameStatUIText, tooltipX + 190.f, lineY);
}

    void UpdateBackgroundTint(const float deltaTime) {
        constexpr float speed = 5.0f;
        colorTime += deltaTime * speed;

        constexpr float Amplitude = 60.0f;
        constexpr float MidPoint = 144.0f;

        r = static_cast<Uint8>(std::clamp(std::sin(colorTime) * Amplitude + MidPoint, 0.0f, 255.0f));
        g = static_cast<Uint8>(std::clamp(std::sin(colorTime + 2.0f) * Amplitude + MidPoint, 0.0f, 255.0f));
        b = static_cast<Uint8>(std::clamp(std::sin(colorTime + 4.0f) * Amplitude + MidPoint, 0.0f, 255.0f));
    }
//To calculate the fps ingame
    void CalculateFPS(const float deltaTime) {
        frameTimes.push_back(deltaTime);
        if (frameTimes.size() > MAX_SAMPLES) {
            frameTimes.erase(frameTimes.begin());
        }
        const float sum = std::accumulate(frameTimes.begin(), frameTimes.end(), 0.0f);
        const float avgDelta = sum / static_cast<float>(frameTimes.size());
        currentFPS = (avgDelta > 0) ? 1.0f / avgDelta : 0;

        if (shouldUpdateText) {
            std::string fpsStr = "FPS: " + std::to_string(static_cast<int>(currentFPS));
            TTF_SetTextString(fpsText, fpsStr.c_str(), 0);
            shouldUpdateText = false; // Reset the flag
        }
    }

    //Menu
    void Menu(float deltaTime) {
        SDL_Event MenuEvents;

        UpdateBackgroundTint(deltaTime);
        TTF_SetTextColor(menuText, r,g,b,255);

        //clear everything out
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        //Background menu



        //Boutons menu
        RenderBoutons(BoutonPlay, textStart, 20, 20, 20,255);
        RenderBoutons(BoutonTutorial, textTutorial, 20, 20, 20,255);
        RenderBoutons(BoutonOptions, textOptions, 20, 20, 20,255);
        RenderBoutons(BoutonQuit, textQuit, 20, 20, 20,255);
        RenderBoutons(BoutonCredits, textCredits, 20, 20, 20,255);


        TTF_DrawRendererText(menuText, 700,150);
        TTF_DrawRendererText(fpsText, 1800, 10);
        TTF_DrawRendererText(gameVersionText, 10,10);
        SDL_RenderPresent(renderer);
    }

    //Choose Character
    void ChooseCharacter(float deltaTime) {
        UpdateBackgroundTint(deltaTime);


        //clear everything out
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        //title
        TTF_DrawRendererText(factionSelectionTitleText, 750, 50);
        TTF_DrawRendererText(factionSelectionFactionBonusText, 1600,400);
        int knightAlpha = (selectedFaction == 0) ? 255 : 60;
        RenderBoutons(BoutonKnight, nullptr, 255, 215, 0,   knightAlpha);
        SDL_RenderTexture(renderer,chooseFactionKnightIcon, nullptr, &BoutonKnight);
        SDL_SetTextureAlphaMod(chooseFactionKnightIcon, knightAlpha);
        int vikingAlpha = (selectedFaction == 1) ? 255 : 60;
        RenderBoutons(BoutonViking, nullptr, 255, 50,  50,  vikingAlpha);
        SDL_RenderTexture(renderer, chooseFactionVikingIcon, nullptr, &BoutonViking);
        SDL_SetTextureAlphaMod(chooseFactionVikingIcon, vikingAlpha);
        int samuraiAlpha = (selectedFaction == 2) ? 255 : 60;
        RenderBoutons(BoutonSamurai, nullptr, 0,   200, 160, samuraiAlpha);
        SDL_RenderTexture(renderer, chooseFactionSamuraiIcon, nullptr, &BoutonSamurai);
        SDL_SetTextureAlphaMod(chooseFactionSamuraiIcon,  samuraiAlpha);
        RenderBoutons(BoutonStartCampaign, factionSelectionStartCampaignText, 60,60,60,255);

        if (selectedFaction == 0) {
            TTF_DrawRendererText(factionSelectionGeneralKnightText, 1600,500);
            TTF_DrawRendererText(factionSelectionLoreknightText, 200, 900);
        }
        else if (selectedFaction == 1) {
            TTF_DrawRendererText(factionSelectionGeneralVikingText, 1600,500);
            TTF_DrawRendererText(factionSelectionLoreVikingText, 200, 900);
        }
        else if (selectedFaction == 2) {
            TTF_DrawRendererText(factionSelectionGeneralSamuraiText, 1600,500);
            TTF_DrawRendererText(factionSelectionLoreSamuraiText, 200, 900);
        }

        RenderBoutonCercle(BoutonReturn, nullptr, nullptr,80, 80, 80);
        SDL_RenderPresent(renderer);
    }
    //Game
    void Game(float deltaTime) {
        UpdateBackgroundTint(deltaTime);
        // camera wasd movement
        const bool* keys = SDL_GetKeyboardState(nullptr);
        float baseSpeed = 400.f;
        float multiplierSpeed = 2.f;
        float currentSpeed = baseSpeed;
        if (keys[SDL_SCANCODE_LSHIFT]) {
            currentSpeed *= multiplierSpeed;
        }
        if (keys[SDL_SCANCODE_W]) camera.Movement(0, -currentSpeed * deltaTime);
        if (keys[SDL_SCANCODE_S]) camera.Movement(0,  currentSpeed * deltaTime);
        if (keys[SDL_SCANCODE_A]) camera.Movement(-currentSpeed * deltaTime, 0);
        if (keys[SDL_SCANCODE_D]) camera.Movement( currentSpeed* deltaTime, 0);
        //camera mouse on edge
        float mouseX;
        float mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        float logicX, logicY;
        SDL_RenderCoordinatesFromWindow(renderer, mouseX,mouseY,&logicX,&logicY);

        float speed = 400.f;
        float edgeSize = 5.f;
        //left
        if (logicX < edgeSize) {
            camera.Movement(-speed * deltaTime, 0);
        }
        if (logicX > 1920 - edgeSize) {
            camera.Movement(speed * deltaTime, 0);
        }
        if (logicY < edgeSize) {
            camera.Movement(0, -speed * deltaTime);
        }
        if (logicY > 1080 - edgeSize) {
            camera.Movement(0, speed* deltaTime);
        }

        camera.Update(deltaTime,  1920.f,1080.f);

        //clear everything out
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        //tilemap
        if (tileMap) tileMap->Render(renderer, camera);
        //provinces map
        if (tileMap) tileMap->RenderProvinceBorders(renderer, provinces, camera);

        //Render the settlements
        RenderSettlements();

        //if camera is far enough the texts of kingdoms + their texture shows
        if (camera.zoom < 1.8f && tileMap) {
            //faction names inside Territory
            struct FactionLabel {
                int      startProvince;
                int      endProvince;
                TTF_Text* text;
            };

            auto getFactionCenter = [&](int p1, int p2, int p3) -> SDL_FPoint {
                SDL_FPoint c1 = tileMap->GetProvinceCenter(p1);
                SDL_FPoint c2 = tileMap->GetProvinceCenter(p2);
                SDL_FPoint c3 = tileMap->GetProvinceCenter(p3);
                return {
                    (c1.x + c2.x + c3.x) / 3.f,
                    (c1.y + c2.y + c3.y) / 3.f
                };
            };

            // alpha based on zoom
            float alpha = std::clamp((1.1f - camera.zoom) / 0.3f, 0.f, 1.f);
            Uint8 a = (Uint8)(alpha * 255.f);

            SDL_FPoint knightCenter  = getFactionCenter(0, 1, 2);
            SDL_FPoint vikingCenter  = getFactionCenter(3, 4, 5);
            SDL_FPoint samuraiCenter = getFactionCenter(6, 7, 8);

            auto worldToScreen = [&](SDL_FPoint wp) -> SDL_FPoint {
                return {
                    wp.x * camera.zoom - camera.startX * camera.zoom,
                    wp.y * camera.zoom - camera.startY * camera.zoom
                };
            };

            SDL_FPoint kScreen = worldToScreen(knightCenter);
            SDL_FPoint vScreen = worldToScreen(vikingCenter);
            SDL_FPoint sScreen = worldToScreen(samuraiCenter);

            //Banner position for the kight
            auto renderKnightBanner = [&](SDL_Texture* provincesTexture, SDL_FPoint screenPos, Uint8 alpha) {
                if (!provincesTexture) return;
                SDL_FRect dst = {
                    screenPos.x - 145.f,
                    screenPos.y - 70.f,
                    275.f, 150.f
                };
                SDL_SetTextureAlphaMod(provincesTexture, alpha);
                SDL_SetTextureBlendMode(provincesTexture, SDL_BLENDMODE_BLEND);
                SDL_RenderTexture(renderer, provincesTexture, nullptr, &dst);
            };
            //render for the samurai
            auto renderSamuraiBanner = [&](SDL_Texture* provincesTexture, SDL_FPoint screenPos, Uint8 alpha) {
                if (!provincesTexture) return;
                SDL_FRect dst = {
                    screenPos.x - 140.f,
                    screenPos.y - 75.f,
                    275.f, 150.f
                };
                SDL_SetTextureAlphaMod(provincesTexture, alpha);
                SDL_SetTextureBlendMode(provincesTexture, SDL_BLENDMODE_BLEND);
                SDL_RenderTexture(renderer, provincesTexture, nullptr, &dst);
            };
            //render for the viking
            auto renderVikingBanner = [&](SDL_Texture* provincesTexture, SDL_FPoint screenPos, Uint8 alpha) {
                if (!provincesTexture) return;
                SDL_FRect dst = {
                    screenPos.x - 100.f,
                    screenPos.y - 70.f,
                    275.f, 150.f
                };
                SDL_SetTextureAlphaMod(provincesTexture, alpha);
                SDL_SetTextureBlendMode(provincesTexture, SDL_BLENDMODE_BLEND);
                SDL_RenderTexture(renderer, provincesTexture, nullptr, &dst);
            };

            renderKnightBanner(provinceKnightBannerTexture,  kScreen, a);
            //renderVikingBanner(vikingBanner,  vScreen, a);
            renderSamuraiBanner(provinceSamuraiBannerTexture, sScreen, a);


            TTF_SetTextColor(gameKingdomKnightNameText, 140, 100, 42,   a);
            TTF_SetTextColor(gameKingdomVikingNameText, 220,50,50, a);
            TTF_SetTextColor(gameKingdomSamuraiNameText,0, 200,  160,  a);

            int textW, textH;

            TTF_GetTextSize(gameKingdomKnightNameText, &textW, &textH);
            TTF_DrawRendererText(gameKingdomKnightNameText, kScreen.x - textW/2.f, kScreen.y - textH/2.f);

            TTF_GetTextSize(gameKingdomVikingNameText, &textW, &textH);
            TTF_DrawRendererText(gameKingdomVikingNameText, vScreen.x - textW/2.f, vScreen.y - textH/2.f);

            TTF_GetTextSize(gameKingdomSamuraiNameText, &textW, &textH);
            TTF_DrawRendererText(gameKingdomSamuraiNameText, sScreen.x - textW/2.f, sScreen.y - textH/2.f);;
        }

        //Render the UI of provinces
        RenderProvinceUI();
        RenderGeneralUI();
        RenderMoneyTooltip();
        RenderFoodTooltip();
        RenderPopulationTooltip();
        RenderBuildingInfoUI();
        RenderCategoryBuildingInfoUI();
        // Tooltip public order
if (bMouseOnPublicOrderIcon && hoveredPublicOrderSettlementIndex >= 0) {
    const Settlement& sPO = settlements[hoveredPublicOrderSettlementIndex];
    int provID = sPO.settlementData.provinceID;
    bool collecting = provinces[provID].bToggleCollectIncome;
    int po = sPO.settlementData.publicOrder;

    // Calcul du bonus bâtiments de la province
    int provinceBuildingBonus = 0;
    for (const auto& s : settlements) {
        if (s.settlementData.provinceID != provID) continue;
        for (auto bt : s.settlementData.buildings) {
            if (bt == BuildingType::None) continue;
            const BuildingData* bd = GetBuildingData(bt);
            if (bd && bd->publicOrderBonus != 0)
                provinceBuildingBonus += bd->publicOrderBonus;
        }
    }

    //public order based on food UI
    bool bIsPlayerProvince = (provinces[provID].owner == player.faction);
    int foodModifier = bIsPlayerProvince ? GetFoodPublicOrderModifier() : 0;
    //Money public order penalty
    int taxPenalty = collecting ? -4 : 0;
    int totalDelta = taxPenalty + provinceBuildingBonus + foodModifier;
    int nextPO     = std::clamp(po + totalDelta, -100, 100);

    // add the high difference for each categories
    float tooltipW = 260.f;
    float tooltipH = 36.f + 30.f + 12.f; // titre + current + separator
    if (provinceBuildingBonus != 0) tooltipH += 24.f;
    if (taxPenalty != 0) tooltipH += 24.f;
    if (foodModifier != 0) tooltipH += 24.f;
    tooltipH += 10.f; // padding

    float tooltipX = publicOrderTooltipX + 12.f;
    float tooltipY = publicOrderTooltipY - tooltipH - 8.f;
    if (tooltipX + tooltipW > 1910.f) tooltipX = publicOrderTooltipX - tooltipW - 12.f;
    if (tooltipY < 5.f)               tooltipY = 5.f;

    float rightEdge = tooltipX + tooltipW - 12.f;

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    // Font
    SDL_SetRenderDrawColor(renderer, 12, 10, 8, 240);
    SDL_FRect bg = {tooltipX, tooltipY, tooltipW, tooltipH};
    SDL_RenderFillRect(renderer, &bg);

    // Title Bar
    SDL_SetRenderDrawColor(renderer, 55, 45, 20, 255);
    SDL_FRect titleBar = {tooltipX, tooltipY, tooltipW, 28.f};
    SDL_RenderFillRect(renderer, &titleBar);

    // Border
    SDL_SetRenderDrawColor(renderer, 110, 90, 40, 255);
    SDL_RenderRect(renderer, &bg);

    // Title Public Order details
    TTF_SetTextString(gameStatUITitleText, "Public Order Details", 0);
    TTF_SetTextColor(gameStatUITitleText, 215, 190, 130, 255);
    int titleW, titleH;
    TTF_GetTextSize(gameStatUITitleText, &titleW, &titleH);
    TTF_DrawRendererText(gameStatUITitleText,
        tooltipX + (tooltipW - titleW) / 2.f,
        tooltipY + (28.f - titleH) / 2.f);

    float lineY = tooltipY + 36.f;

    TTF_SetTextString(gameStatUIText, "Current", 0);
    TTF_SetTextColor(gameStatUIText, 210, 210, 210, 255);
    TTF_DrawRendererText(gameStatUIText, tooltipX + 10.f, lineY);
    // current value (White)
    std::string poStr = std::to_string(po);
    TTF_SetTextString(gameStatUIText, poStr.c_str(), 0);
    int poW, poH; TTF_GetTextSize(gameStatUIText, &poW, &poH);

    // Delta red or green
    std::string deltaStr = std::string(" (") + (totalDelta >= 0 ? "+" : "") + std::to_string(totalDelta) + ")";
    TTF_SetTextString(gameStatUIText, deltaStr.c_str(), 0);
    int dW, dH; TTF_GetTextSize(gameStatUIText, &dW, &dH);

    float poX = rightEdge - poW - dW;
    TTF_SetTextString(gameStatUIText, poStr.c_str(), 0);
    TTF_SetTextColor(gameStatUIText, 255, 255, 255, 255);
    TTF_DrawRendererText(gameStatUIText, poX, lineY);

    TTF_SetTextString(gameStatUIText, deltaStr.c_str(), 0);
    TTF_SetTextColor(gameStatUIText,
        totalDelta >= 0 ? 80  : 220,
        totalDelta >= 0 ? 200 : 60, 80, 255);
    TTF_DrawRendererText(gameStatUIText, poX + poW, lineY);
    lineY += 28.f;

    // seperation
    SDL_SetRenderDrawColor(renderer, 80, 65, 30, 200);
    SDL_RenderLine(renderer,
        tooltipX + 5.f, lineY,
        tooltipX + tooltipW - 5.f, lineY);
    lineY += 10.f;

    // the lampda
    auto drawModLine = [&](const char* label, int value) {
        TTF_SetTextString(gameStatUIText, label, 0);
        TTF_SetTextColor(gameStatUIText, 150, 145, 130, 255);
        TTF_DrawRendererText(gameStatUIText, tooltipX + 22.f, lineY);

        std::string valStr = (value > 0 ? "+" : "") + std::to_string(value);
        TTF_SetTextString(gameStatUIText, valStr.c_str(), 0);
        TTF_SetTextColor(gameStatUIText,
            value > 0 ? 80  : (value < 0 ? 220 : 130),
            value > 0 ? 200 : (value < 0 ? 60  : 130),
            80, 255);
        int vW, vH; TTF_GetTextSize(gameStatUIText, &vW, &vH);
        TTF_DrawRendererText(gameStatUIText, rightEdge - vW, lineY);
        lineY += 24.f;
    };

    if (provinceBuildingBonus != 0) drawModLine("Buildings",        provinceBuildingBonus);
    if (taxPenalty != 0)            drawModLine("Collected income",  taxPenalty);
    if (foodModifier != 0) drawModLine ("Food", foodModifier);
}
        //fps
        TTF_DrawRendererText(fpsText, 10, 10);


        //Work in progress Text
        TTF_DrawRendererText(gameInProgressText, 10, 30);
        SDL_RenderPresent(renderer);
    }

    //Technology tree
    void TechnologyTree(float deltaTime) {

        UpdateBackgroundTint(deltaTime);
        //Clear everything
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderClear(renderer);

        //Render Return Button
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        RenderBoutonCercle(TechnologyReturnGame,nullptr, nullptr, 255,255,255);



        SDL_RenderPresent(renderer);
    }

    //Tutorial
    void Tutorial (float deltaTime) {
        UpdateBackgroundTint(deltaTime);
        //clear everything out
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);


        RenderBoutonCercle(BoutonReturn, nullptr, nullptr,80, 80, 80);
        SDL_RenderPresent(renderer);
    }
    //Options
    void Options(float deltaTime) {
        UpdateBackgroundTint(deltaTime);


        //clear everything out
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        TTF_DrawRendererText(optionsTitleText, 850,50);
        TTF_DrawRendererText(optionsMusicText, 660,450);
        RenderSlider(volumeMusicSlider, "Volume Music");

        RenderBoutonCercle(BoutonReturn, nullptr, nullptr,80, 80, 80);
        SDL_RenderPresent(renderer);
    }

    void Credits(float deltaTime) {
        UpdateBackgroundTint(deltaTime);


        //clear everything out
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        TTF_DrawRendererText(creditsTitleText, 850,50);
        //role 1
        TTF_DrawRendererText(creditsRoleTitleText, 1500,400);
        TTF_DrawRendererText(creditsRoleNameText, 1450, 500);

        RenderBoutonCercle(BoutonReturn, nullptr, nullptr,80, 80, 80);
        SDL_RenderPresent(renderer);
    }


public:
    //To render the circles
    void RenderCircle(float circleX, float circleY, float radius) {
        for (float y = -radius; y <= radius; y++) {
            float distanceX = sqrtf(radius * radius - y * y);
            SDL_RenderLine(renderer, circleX - distanceX, circleY + y, circleX + distanceX,circleY + y);
        }
    }
    void RenderBoutonCercle(const Circle &circle, TTF_Text *buttonText, SDL_Texture *texture,Uint8 buttonr, Uint8 buttong, Uint8 buttonb) {
        //SDL_SetRenderDrawColor(renderer, 120,40,120,255);
        RenderCircle(circle.circleX, circle.circleY, circle.radius);

        // Render texture
        if (texture != nullptr) {
            SDL_FRect dst = {
                circle.circleX - circle.radius,
                circle.circleY - circle.radius,
                circle.radius * 2,
                circle.radius * 2
            };
            SDL_RenderTexture(renderer, texture, nullptr, &dst);
        }

        if (buttonText != nullptr) {
            int textW, textH;
            TTF_GetTextSize(buttonText, &textW, &textH);
            TTF_DrawRendererText(buttonText, circle.circleX - textW/2, circle.circleY - textH/2 );
        }
    }
    //if circle been clicked
    bool ClickInsideCircle(float mouseX, float mouseY, const Circle &circle) {
        float distanceX = mouseX - circle.circleX;
        float distanceY = mouseY - circle.circleY;
        return (distanceX* distanceX + distanceY * distanceY) <= (circle.radius * circle.radius);
    }

    //To Know the construction time for a building
    int GetConstructionTurns(SettlementType type, int fromTier) {
        if (type == SettlementType::Village) {
            if (fromTier == 1) return 3;
            if (fromTier == 2) return 4;
        }
        else if (type == SettlementType::Castle) {
            if (fromTier == 1) return 3;
            if (fromTier == 2) return 4;
            if (fromTier == 3) return 6;
            if (fromTier == 4) return 8;
        }
        else if (type == SettlementType::Capital) {
            if (fromTier == 1) return 3;
            if (fromTier == 2) return 4;
            if (fromTier == 3) return 6;
            if (fromTier == 4) return 8;
        }
        return 1;
    }

    //fonction to end a turn
    void EndTurn() {

    //Bonus public order per province all buildings
    std::unordered_map<int, int> provincePublicOrderBonus; // provinceID → bonus total
    for (const auto& s : settlements) {
        int provID = s.settlementData.provinceID;
        for (auto building_type : s.settlementData.buildings) {
            if (building_type == BuildingType::None) continue;
            const BuildingData* building_data = GetBuildingData(building_type);
            if (building_data && building_data->publicOrderBonus != 0)
                provincePublicOrderBonus[provID] += building_data->publicOrderBonus;
        }
    }

    // money & food  // bonus public order inside a province
    int goldEarned = 0;
    int foodPublicOrderModifier = GetFoodPublicOrderModifier();
    for (auto& s : settlements) {
        int provID = s.settlementData.provinceID;

        // tax only for player. with toggleCollectIncome
        if (provinces[provID].owner == player.faction && provinces[provID].bToggleCollectIncome) {
            goldEarned += s.settlementData.baseIncome;
            s.settlementData.publicOrder -= 4; //minus 4 if collected
        }

        // applied bonus to all province
        s.settlementData.publicOrder += provincePublicOrderBonus[provID];

        if (provinces[provID].owner == player.faction) {
            s.settlementData.publicOrder += foodPublicOrderModifier;
        }


        s.settlementData.publicOrder = std::clamp(s.settlementData.publicOrder, -100, 100);
    }


    // gold added
    player.AddGold(player.nextTurnGold);
    // //food added
    // player.currentFood = player.nextTurnFood;
    //     SDL_Log("Food: %d ", player.currentFood, player.nextTurnFood);

    // building constructions
    for (auto& s : settlements) {
        for (int b = 1; b < (int)s.settlementData.pendingBuildings.size(); b++) {
            if (s.settlementData.pendingBuildings[b] != BuildingType::None) {
                s.settlementData.slotConstructionTimes[b]--;
                if (s.settlementData.slotConstructionTimes[b] <= 0) {
                    s.settlementData.buildings[b] = s.settlementData.pendingBuildings[b];
                    s.settlementData.pendingBuildings[b] = BuildingType::None;
                    SDL_Log("Building finished in slot %d of %s", b, s.settlementData.cityName.c_str());
                }
            }
        }
        // main building
        if (s.settlementData.bBuidingUnderConstruction) {
            s.settlementData.constructionTime--;
            if (s.settlementData.constructionTime <= 0) {
                s.settlementData.settlementTier = s.settlementData.pendingTier;
                s.settlementData.bBuidingUnderConstruction = false;
                s.settlementData.pendingTier = 0;
                SDL_Log("Construction finished: %s is now tier %d",
                    s.settlementData.cityName.c_str(), s.settlementData.settlementTier);
                FactionZone faction = provinces[s.settlementData.provinceID].owner;
                s.settlementData.buildings[0] = GetSettlementBuildingType(
                    s.settlementData.type, faction, s.settlementData.settlementTier);
                const BuildingData* data = GetBuildingData(s.settlementData.buildings[0]);
                if (data) s.settlementData.baseIncome = data->incomeBonus;
            }
        }
    }

    //Food
        /*
         * if in segs 1,2,3 means produce less food than they consume.
         * foodStore gets negative. If reach 0, attrition, negative order, etc etc
         */
        if (filledSegs == 1) {//consume food in storage before having famine
            if (player.foodStored > 0) {
                player.foodStored -= 9;
            }
        }
        else if (filledSegs == 2) {//consume food in storage
            if (player.foodStored > 0) {
                player.foodStored -= 6;
            }
        }
        else if (filledSegs == 3) {//consume food in storage
            if (player.foodStored > 0) {
                player.foodStored -=3;
            }
        }
        else if (filledSegs == 4) { // increase food in storage
           player.foodStored = std::min(player.foodStored+3, player.foodStorage);
        }
        else if (filledSegs == 5) {// increase food in storage
            player.foodStored = std::min(player.foodStored+6, player.foodStorage);
        }
        else if (filledSegs == 6) { // increase food in storage
            player.foodStored = std::min(player.foodStored+9, player.foodStorage);
        }

        // Re randomize the base Birth and death of each population after the end turn for a different outcome each turn.
        player.basePeasantryBirth = 70 + rand() % 21;
        player.basePeasantryDeath = 25 + rand() % 16;
        player.baseNobilityBirth  = 8  + rand() % 13;
        player.baseNobilityDeath  = 2  + rand() % 9;
        player.baseClergyGrowth   = 1  + rand() % 5;
        player.baseClergyDeath    = 1  + rand() % 4;

        //population increase each turn based on base random bonus + building bonus
        int buildingPeasantryBonus = 0;
        int buildingNobilityBonus = 0;
        int buildingClergyBonus = 0;

        for (const auto &s : settlements) {
            if (provinces[s.settlementData.provinceID].owner != player.faction) continue;//Not player faction -> continue

            for (BuildingType building_type : s.settlementData.buildings) {
                if (building_type == BuildingType::None) continue;//no building -> continue
                const BuildingData *building_data = GetBuildingData(building_type);
                if (!building_data) continue;
                buildingPeasantryBonus += building_data->peasantryBornBonus;
                buildingNobilityBonus += building_data->nobilityBornBonus;
                buildingClergyBonus += building_data->clergyTrainedBonus;
            }
        }
        // stock the net growth
        player.nextTurnPeasantryAmount = (player.basePeasantryBirth - player.basePeasantryDeath) + buildingPeasantryBonus;
        player.nextTurnNobilityAmount = (player.baseNobilityBirth  - player.baseNobilityDeath)  + buildingNobilityBonus;
        player.nextTurnClergyAmount = (player.baseClergyGrowth   - player.baseClergyDeath)    + buildingClergyBonus;

        player.currentPeasantryAmount += player.nextTurnPeasantryAmount;
        player.currentNobilityAmount += player.nextTurnNobilityAmount;
        player.currentClergyAmount += player.nextTurnClergyAmount;

    // AI TURNS~!
    std::vector<FactionZone> turnOrder = { FactionZone::Knight, FactionZone::Viking, FactionZone::Samurai };
    int playerIndex = 0;
    for (int i = 0; i < (int)turnOrder.size(); i++) {
        if (turnOrder[i] == player.faction) { playerIndex = i; break; }
    }
    for (int i = 1; i < (int)turnOrder.size(); i++) {
        FactionZone aiTurn = turnOrder[(playerIndex + i) % turnOrder.size()];
        SDL_Log("AI turn: faction %d", (int)aiTurn);
        // AIPlayTurn(aiTurn);
    }

    currentTurn++;
    SDL_Log("Turn %d || your turn (%d)", currentTurn, (int)player.faction);
}

    SDL_AppResult RunCallBacks() {
        static uint64_t lastTime = SDL_GetTicks();
        //temps global
        const uint64_t currentTime = SDL_GetTicks();
        deltaTime = static_cast<float>(currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        //fps
        CalculateFPS(deltaTime);
        switch (StateActuel) {
            case State::Menu:
                if (trackMusique && !MIX_TrackPlaying(trackMusique)) {
                    MIX_PlayTrack(trackMusique, -1);
                }
                Menu(deltaTime);
                break;
            case State::ChooseCharacter:
                ChooseCharacter(deltaTime);
                break;
            case State::Game:
                Game(deltaTime);
                break;
            case State::Tutorial:
                Tutorial(deltaTime);
                break;
            case State::Options:
                Options(deltaTime);
                break;
            case State::Credits:
                Credits(deltaTime);
                break;
            case State::Technology:
                TechnologyTree(deltaTime);
                break;
            case State::Quit:
                return SDL_APP_SUCCESS;
        }
        return SDL_APP_CONTINUE;
    }

};

SDL_AppResult
SDL_AppInit(void **appstate, int argc, char *argv[]) {
    GameApp &app = GameApp::GetInstance();
    return SDL_APP_CONTINUE;
}
//les events touches etc
SDL_AppResult
SDL_AppEvent(void *appstate, SDL_Event *event) {
    GameApp &app = GameApp::GetInstance();

    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN && event->button.button == SDL_BUTTON_LEFT) {
        //Les variables
        float nouveauX, nouveauY;

        //new variables if fullScreen vs window mod
        SDL_RenderCoordinatesFromWindow(app.renderer, event->button.x, event->button.y, &nouveauX, &nouveauY);
        SDL_FPoint MousePT = {nouveauX, nouveauY};

        //IF IN MENU
        if (app.StateActuel == State::Menu) {
            if (SDL_PointInRectFloat(&MousePT, &app.BoutonPlay)) {
                app.StateActuel = State::ChooseCharacter;
            }
            if (SDL_PointInRectFloat(&MousePT, &app.BoutonTutorial)) {
                app.StateActuel = State::Tutorial;
            }
            if (SDL_PointInRectFloat(&MousePT, &app.BoutonOptions)) {
                app.StateActuel = State::Options;
            }
            if (SDL_PointInRectFloat(&MousePT, &app.BoutonQuit)) {
                app.StateActuel = State::Quit;
            }
            if (SDL_PointInRectFloat(&MousePT, &app.BoutonCredits)) {
                app.StateActuel = State::Credits;
            }
        }
        //IF IN CHOOSE FACTION
        if (app.StateActuel == State::ChooseCharacter) {
            if (SDL_PointInRectFloat(&MousePT, &app.BoutonKnight)) {
                app.selectedFaction = 0;
            }
            if (SDL_PointInRectFloat(&MousePT, &app.BoutonViking)) {
                app.selectedFaction = 1;
            }
            if (SDL_PointInRectFloat(&MousePT, &app.BoutonSamurai)) {
                app.selectedFaction = 2;
            }
            if (SDL_PointInRectFloat(&MousePT, &app.BoutonStartCampaign)) {
                if (app.selectedFaction == 0) {
                    app.player.faction = FactionZone::Knight;
                }
                else if (app.selectedFaction == 1) {
                    app.player.faction = FactionZone::Viking;
                }
                else if (app.selectedFaction == 2) {
                    app.player.faction = FactionZone::Samurai;
                }
                app.StateActuel= State::Game;
            }
            //Circle
            if (app.ClickInsideCircle(nouveauX, nouveauY, app.BoutonReturn)) {
                app.StateActuel = State::Menu;
            }

        }
        //IF IN GAME
        //When pressded it shows the position of 1 tile
        if (app.StateActuel == State::Game) {
    float worldX = (nouveauX + app.camera.startX * app.camera.zoom) / app.camera.zoom;
    float worldY = (nouveauY + app.camera.startY * app.camera.zoom) / app.camera.zoom;
    int tileC = (int)(worldX / app.tileMap->tileSize);
    int tileR = (int)(worldY / app.tileMap->tileSize);
    SDL_Log("Tile: col=%d, row=%d", tileC, tileR);



            if (app.ClickInsideCircle(nouveauX, nouveauY, app.BoutonReturn)) {
                app.bHasClickedOnASettlement = false;
                app.bButtonUIBuildingIsPressed = true;
                app.selectedSettlementIndex = -1;
                app.hoveredSlotIndex = -1;
                return SDL_APP_CONTINUE;
            }

    if (app.bHasClickedOnASettlement) {
        SDL_FPoint pt = {nouveauX, nouveauY};
        if (SDL_PointInRectFloat(&pt, &app.provinceButtonUIBuilding)) {
            app.bButtonUIBuildingIsPressed = true;
            app.bButtonUIGarrisonIsPressed = false;
            return SDL_APP_CONTINUE;
        }
        if (SDL_PointInRectFloat(&pt, &app.provinceButtonUIGarrison)) {
            app.bButtonUIGarrisonIsPressed = true;
            app.bButtonUIBuildingIsPressed = false;
            return SDL_APP_CONTINUE;
        }
    }

            // Clic on a popup of the main menu
            if (app.bHasClickedOnASettlement &&
                app.hoveredSlotIndex == 0 &&
                app.hoveredCardIndex >= 0 &&
                !app.tierPopupRects.empty())
            {
                SDL_FPoint pt = {nouveauX, nouveauY};
                for (int t = 1; t <= app.tierPopupMaxTier; t++) {
                    if (SDL_PointInRectFloat(&pt, &app.tierPopupRects[t - 1])) {
                        const Settlement& clicked = app.settlements[app.selectedSettlementIndex];
                        int provID = clicked.settlementData.provinceID;
                        std::vector<Settlement*> provS;
                        for (auto& s : app.settlements)
                            if (s.settlementData.provinceID == provID)
                                provS.push_back(&s);

                        if (app.hoveredCardIndex < (int)provS.size()) {
                            Settlement* sel = provS[app.hoveredCardIndex];
                            // Only upgrade if next tier
                            if (t == sel->settlementData.settlementTier + 1 && t <= app.tierPopupMaxTier) {
                                //continue if not player Faction
                                int provID = clicked.settlementData.provinceID;
                                if (app.provinces[provID].owner != app.player.faction) {
                                    return SDL_APP_CONTINUE;
                                }

                                BuildingType mainBuilding = sel->settlementData.buildings[0];
                                //cost of each settlement + if money of player is higher than the price -> can purchase other it doesnt
                                int cost = app.player.GetUpgradeCost(sel->settlementData.settlementTier, mainBuilding);
                                if (sel->settlementData.bBuidingUnderConstruction) {
                                    SDL_Log("Already in construction (%d turn remaining)",sel->settlementData.constructionTime);
                                }
                                else if (app.player.SpendGold(cost)) {
                                    // read the database of building types
                                    BuildingType currentBuilding = sel->settlementData.buildings[0];
                                    const BuildingData* currentData = GetBuildingData(currentBuilding);
                                    const BuildingData* nextTierData = (currentData && currentData->upgradesTo != BuildingType::None)? GetBuildingData(currentData->upgradesTo): nullptr;
                                    int turns = nextTierData ? nextTierData->constructionTurns : 1;
                                    sel->settlementData.bBuidingUnderConstruction = true;
                                    sel->settlementData.pendingTier = t;
                                    sel->settlementData.constructionTime= turns;
                                    SDL_Log("Construction started : tier %d in %d turns, or remaining: %d",t, turns, app.player.currentGold);
                                } else {
                                    SDL_Log("not enough gold! Need: %d, get: %d", cost, app.player.currentGold);
                                }
                            }
                        }
                        return SDL_APP_CONTINUE;
                    }
                }
            }

            // click on a pending building -> cancel and refund
            if (app.bHasClickedOnASettlement && app.bButtonUIBuildingIsPressed &&
                !app.pendingSlotRects.empty())
            {
                SDL_FPoint pt = {nouveauX, nouveauY};
                for (int p = 0; p < (int)app.pendingSlotRects.size(); p++) {
                    if (SDL_PointInRectFloat(&pt, &app.pendingSlotRects[p])) {
                        auto [cardIdx, slotIdx] = app.pendingSlotInfo[p];
                        const Settlement& clicked = app.settlements[app.selectedSettlementIndex];
                        int provID = clicked.settlementData.provinceID;

                        std::vector<Settlement*> provS;
                        for (auto& s : app.settlements)
                            if (s.settlementData.provinceID == provID) provS.push_back(&s);

                        //to refound a pending building for the main settlement
                        if (cardIdx < (int)provS.size()) {
                            Settlement* sel = provS[cardIdx];
                            if (slotIdx == 0) {
                                if (sel->settlementData.bBuidingUnderConstruction) {
                                    BuildingType currentBuilding = sel->settlementData.buildings[0];
                                    const BuildingData* currentData = GetBuildingData(currentBuilding);
                                    if (currentData && currentData->upgradesTo != BuildingType::None) {
                                        const BuildingData* nextData = GetBuildingData(currentData->upgradesTo);
                                        if (nextData) app.player.AddGold(nextData->cost);
                                    }
                                    sel->settlementData.bBuidingUnderConstruction = false;
                                    sel->settlementData.pendingTier = 0;
                                    sel->settlementData.constructionTime = 0;
                                }
                            } else {
                                BuildingType pendingBt = sel->settlementData.pendingBuildings[slotIdx];
                                if (pendingBt != BuildingType::None) {
                                    const BuildingData* data = GetBuildingData(pendingBt);
                                    if (data) app.player.AddGold(data->cost);
                                    sel->settlementData.pendingBuildings[slotIdx] = BuildingType::None;
                                    sel->settlementData.slotConstructionTimes[slotIdx] = 0;
                                }
                            }
                        }
                        return SDL_APP_CONTINUE;
                    }
                }
            }

            // clic on a popup building of category

            // clic on a popup building of category
            if (app.bHasClickedOnASettlement &&
    app.categoryEvolutionPopupRect.w > 0 &&
    !app.categoryEvolutionTileRects.empty())
{
    SDL_FPoint pt = {nouveauX, nouveauY};
    SDL_Log("Click Check: tiles=%d, popupW=%.1f",
        (int)app.categoryEvolutionTileRects.size(),
        app.categoryEvolutionPopupRect.w);

    for (auto& [rect, bt] : app.categoryEvolutionTileRects) {
        if (SDL_PointInRectFloat(&pt, &rect)) {
            SDL_Log("Tile hit! bt=%d", (int)bt);

            const BuildingData* data = GetBuildingData(bt);
            if (!data) { SDL_Log("EXIT: no data"); return SDL_APP_CONTINUE; }

            const Settlement& clicked = app.settlements[app.selectedSettlementIndex];
            int provID = clicked.settlementData.provinceID;
            if (app.provinces[provID].owner != app.player.faction) { SDL_Log("EXIT: wrong faction"); return SDL_APP_CONTINUE; }

            std::vector<Settlement*> provS;
            for (auto& s : app.settlements)
                if (s.settlementData.provinceID == provID) provS.push_back(&s);

            if (app.categoryPopupCardIndex >= (int)provS.size()) { SDL_Log("EXIT: cardIndex %d >= %d", app.categoryPopupCardIndex, (int)provS.size()); return SDL_APP_CONTINUE; }
            Settlement* sel = provS[app.categoryPopupCardIndex];

            int slotB = app.buildMenuSlotIndex;
            SDL_Log("slotB=%d, buildings.size=%d", slotB, (int)sel->settlementData.buildings.size());
            if (slotB <= 0 || slotB >= (int)sel->settlementData.buildings.size()) { SDL_Log("EXIT: slotB invalid"); return SDL_APP_CONTINUE; }

            if (data->Tier > sel->settlementData.settlementTier) { SDL_Log("EXIT: tier %d > settlementTier %d", data->Tier, sel->settlementData.settlementTier); return SDL_APP_CONTINUE; }

            BuildingType currentInSlot = sel->settlementData.buildings[slotB];
            SDL_Log("currentInSlot=%d, bt=%d", (int)currentInSlot, (int)bt);

            if (currentInSlot == BuildingType::None) {
                bool hasPrerequisite = false;
                const auto& db = GetBuildingDatabase();
                for (const auto& [key, val] : db) {
                    if (val.upgradesTo == bt) { hasPrerequisite = true; break; }
                }
                if (hasPrerequisite) { SDL_Log("EXIT: must build base tier first"); return SDL_APP_CONTINUE; }
            } else {
                const BuildingData* currentBd = GetBuildingData(currentInSlot);
                if (!currentBd || currentBd->upgradesTo != bt) { SDL_Log("EXIT: invalid upgrade path, upgradesTo=%d, bt=%d", currentBd ? (int)currentBd->upgradesTo : -1, (int)bt); return SDL_APP_CONTINUE; }
            }

            bool alreadyBuilt = false;
            for (const auto& existingBt : sel->settlementData.buildings) {
                if (existingBt == bt) { alreadyBuilt = true; break; }
            }
            if (alreadyBuilt) { SDL_Log("EXIT: already built"); return SDL_APP_CONTINUE; }

            for (const auto& pb : sel->settlementData.pendingBuildings) {
                if (pb == bt) { SDL_Log("EXIT: already being built"); return SDL_APP_CONTINUE; }
            }
            if (sel->settlementData.pendingBuildings[slotB] != BuildingType::None) {
                SDL_Log("EXIT: slot already has a pending building");
                return SDL_APP_CONTINUE;
            }

            if (app.player.SpendGold(data->cost)) {
                sel->settlementData.pendingBuildings[slotB] = bt;
                sel->settlementData.slotConstructionTimes[slotB] = data->constructionTurns;
                SDL_Log("SUCCESS: Construction started %d in %d turns", (int)bt, data->constructionTurns);
            } else {
                SDL_Log("EXIT: not enough gold, need=%d have=%d", data->cost, app.player.currentGold);
            }
            return SDL_APP_CONTINUE;
        }
    }
    SDL_Log("No tile hit at (%.1f, %.1f)", nouveauX, nouveauY);
}



    // detection if clicked a settlement
    bool bClickedOutsideOfUI = false;
    for (int i = 0; i < (int)app.settlements.size(); i++) {
        const auto &s = app.settlements[i];
        int settlementSize = 2;
        if (s.settlementData.type == SettlementType::Capital) settlementSize = 4;
        else if (s.settlementData.type == SettlementType::Castle) settlementSize = 3;

        if (tileC >= s.tileCol && tileC < s.tileCol + settlementSize &&
            tileR >= s.tileRow && tileR < s.tileRow + settlementSize) {
            app.bHasClickedOnASettlement = true;
            app.selectedSettlementIndex = i;
            bClickedOutsideOfUI = true;
            break;
        }
    }
            if (!bClickedOutsideOfUI) {

    // Otherwise, check if the click landed inside any UI panel
    bool bInsideUI = false;

    if (app.bHasClickedOnASettlement) {
        SDL_FPoint pt = {nouveauX, nouveauY};

        // Left panel (province stats)
        SDL_FRect leftPanel = {0.f, 700.f, 250.f, 380.f};
        // Bottom panel (settlement cards)
        SDL_FRect bottomPanel = {0.f, 815.f, 1600.f, 265.f};
        // Tab buttons (buildings / garrison)
        SDL_FRect buttonsArea = {app.firstButton - 10.f, 1025.f, 100.f, 55.f};
        // Top bar UI (gold / turns)
        SDL_FRect topBar = {600.f, 0.f, 800.f, 45.f};

        if (SDL_PointInRectFloat(&pt, &leftPanel)   ||
            SDL_PointInRectFloat(&pt, &bottomPanel) ||
            SDL_PointInRectFloat(&pt, &buttonsArea) ||
            SDL_PointInRectFloat(&pt, &topBar))
        {
            bInsideUI = true;
        }
        // Tier popup
        if (!bInsideUI && app.mainBuildingPopupRect.w > 0) {
            SDL_FRect popupExpanded = app.mainBuildingPopupRect;
            popupExpanded.h += 20.f;
            if (SDL_PointInRectFloat(&pt, &popupExpanded)) bInsideUI = true;
        }
        // Category buttons popup
        if (!bInsideUI && app.categoryButtonsPopupRect.w > 0) {
            if (SDL_PointInRectFloat(&pt, &app.categoryButtonsPopupRect)) bInsideUI = true;
        }
        // Evolution popup
        if (!bInsideUI && app.categoryEvolutionPopupRect.w > 0) {
            SDL_FRect evolExpanded = app.categoryEvolutionPopupRect;
            evolExpanded.h += 20.f;
            if (SDL_PointInRectFloat(&pt, &evolExpanded)) bInsideUI = true;
        }
    }

    if (!bInsideUI) {
        app.bHasClickedOnASettlement = false;
        app.bButtonUIBuildingIsPressed = true;
        app.selectedSettlementIndex = -1;
        app.hoveredSlotIndex = -1;
    }

    //toggle the tax Collect region
    if (SDL_PointInRectFloat(&MousePT, &app.toggleTaxIncomeCollect)) {
        int provID = app.settlements[app.selectedSettlementIndex].settlementData.provinceID;
        if (app.provinces[provID].owner == app.player.faction) { // if its our faction
            app.provinces[provID].bToggleCollectIncome = !app.provinces[provID].bToggleCollectIncome;//true and false can change between eachother
        }
        return SDL_APP_CONTINUE;
    }



}

//When End turn button is pressed it call the EnTurn fonction
    if (app.ClickInsideCircle(nouveauX,nouveauY, app.NextTurnButton)) {
        app.EndTurn();
        return SDL_APP_CONTINUE;
    }
    //When button Technology is pressed it goes to the Technology State
    if (app.ClickInsideCircle(nouveauX, nouveauY, app.TechnologyPannel)) {
        app.StateActuel = State::Technology;
        return SDL_APP_CONTINUE;
    }

}
        //TECHNOLOGYTREE SECTION
        if (app.StateActuel == State::Technology) {
            if (app.ClickInsideCircle(nouveauX, nouveauY, app.TechnologyReturnGame)) {
                app.StateActuel = State::Game;
                return SDL_APP_CONTINUE;
            }
        }



        //TUTORIAL
        if (app.StateActuel == State::Tutorial) {
            if (app.ClickInsideCircle(nouveauX, nouveauY, app.BoutonReturn)) {
                app.StateActuel = State::Menu;
            }
        }

        //IF IN OPTIONS
        if (app.StateActuel == State::Options) {
            if (app.ClickInsideCircle(nouveauX, nouveauY, app.BoutonReturn)) {
                app.StateActuel = State::Menu;
            }
            GameApp::VolumeSlider &s = app.volumeMusicSlider;
            SDL_FRect sliderRect = {s.x, s.y - 10, s.width, s.height + 20};
            SDL_FPoint pt = {nouveauX, nouveauY};
            if (SDL_PointInRectFloat(&pt, &sliderRect)) {
                s.bCursorIsSliding = true;
                s.value = std::clamp((nouveauX - s.x) / s.width, 0.0f, 1.0f);
                MIX_SetTrackGain(app.trackMusique, s.value);//the value of the gain of the music is changing based of the slider
            }
        }
        //IF IN CREDITS
        if (app.StateActuel == State::Credits) {
            if (app.ClickInsideCircle(nouveauX, nouveauY, app.BoutonReturn)) {
                app.StateActuel = State::Menu;
            }
        }
    }

    if (event->type == SDL_EVENT_MOUSE_BUTTON_UP) {
        app.volumeMusicSlider.bCursorIsSliding = false;
    }
    //for the slider
    if (event->type == SDL_EVENT_MOUSE_MOTION && app.volumeMusicSlider.bCursorIsSliding) {
        float mouseX, mouseY;
        SDL_RenderCoordinatesFromWindow(app.renderer, event->motion.x, event->motion.y, &mouseX, &mouseY);
        app.volumeMusicSlider.value = std::clamp((mouseX - app.volumeMusicSlider.x) / app.volumeMusicSlider.width, 0.0f, 1.0f);
        MIX_SetTrackGain(app.trackMusique, app.volumeMusicSlider.value);
    }
    //holding mouse wheel to move the camera
    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN &&event->button.button == SDL_BUTTON_MIDDLE &&app.StateActuel == State::Game) {
        app.bIsMovingCamera = true;
        SDL_RenderCoordinatesFromWindow(app.renderer,event->button.x, event->button.y,&app.lastMouseX, &app.lastMouseY);
    }
    if (event->type == SDL_EVENT_MOUSE_BUTTON_UP &&event->button.button == SDL_BUTTON_MIDDLE) {
        app.bIsMovingCamera= false;
        }
    if (event->type == SDL_EVENT_MOUSE_MOTION &&app.bIsMovingCamera &&app.StateActuel == State::Game) {
        float mx, my;
        SDL_RenderCoordinatesFromWindow(app.renderer,event->motion.x, event->motion.y, &mx, &my);
        app.camera.Movement(-(mx - app.lastMouseX), -(my - app.lastMouseY));
        app.lastMouseX = mx;
        app.lastMouseY = my;
    }// Hover slot of the principal building
    if (event->type == SDL_EVENT_MOUSE_MOTION &&app.StateActuel == State::Game &&app.bHasClickedOnASettlement &&app.bButtonUIBuildingIsPressed)
    {
        float mx, my;
        SDL_RenderCoordinatesFromWindow(app.renderer, event->motion.x, event->motion.y, &mx, &my);
        SDL_FPoint pt = {mx, my};

        bool onAnySlot = false;
        for (int i = 0; i < (int)app.mainBuildingSlotRects.size(); i++) {
            if (SDL_PointInRectFloat(&pt, &app.mainBuildingSlotRects[i])) {
                app.hoveredSlotIndex = 0;
                app.hoveredCardIndex = i;
                onAnySlot = true;
                break;
            }
        }
        //little gap for the popup
        SDL_FRect popupWithGap = app.mainBuildingPopupRect;
        popupWithGap.h += 20.f; // couvre le gap de 15px + marge
        bool onPopup = SDL_PointInRectFloat(&pt, &popupWithGap);
        bool onCategoryPopup = app.categoryButtonsPopupRect.w > 0 && SDL_PointInRectFloat(&pt, &app.categoryButtonsPopupRect);
        SDL_FRect expandedEvol = app.categoryEvolutionPopupRect;
        expandedEvol.h += 20.f;
        bool onEvolutionPopup = app.categoryEvolutionPopupRect.w > 0 && SDL_PointInRectFloat(&pt, &expandedEvol);

        if (!onAnySlot && !onPopup && !onCategoryPopup && !onEvolutionPopup) {
            app.hoveredSlotIndex = -1;
            app.hoveredCardIndex = -1;
            app.hoveredCategoryBuildingType = BuildingType::None;
            app.categoryEvolutionPopupRect = {0,0,0,0};//reset the rect
        }
        //suppress tier popup when category popups are active
        if (onCategoryPopup || onEvolutionPopup) {
            app.hoveredSlotIndex = -1;
        }
        // Hover of the buttons categories ui
        if (!onEvolutionPopup) {
            app.hoveredBuildingCategoryIndex = -1;
            for (int k = 0; k < (int)app.categoryButtonsRects.size(); k++) {
                if (SDL_PointInRectFloat(&pt, &app.categoryButtonsRects[k])) {
                    app.hoveredBuildingCategoryIndex = k;
                    break;
                }
            }
        }
        //when mouse on top of the buiding
        app.hoveredTierPopupIndex = -1;
        if (app.hoveredSlotIndex == 0 && !app.tierPopupRects.empty()) {
            for (int t = 1; t <= app.tierPopupMaxTier; t++) {
                if (SDL_PointInRectFloat(&pt, &app.tierPopupRects[t - 1])) {
                    app.hoveredTierPopupIndex = t;
                    break;
                }
            }
        }


        // Hover on the tiles of the popup of the categories
        app.hoveredCategoryBuildingType = BuildingType::None;
        for (auto& [rect, bt] : app.categoryEvolutionTileRects) {
            if (SDL_PointInRectFloat(&pt, &rect)) {
                app.hoveredCategoryBuildingType = bt;
                break;
            }
        }
    }
    //if mouse on the rect of the public order of the settlement it shows the positive and negative public order buff and debuff
    if (event->type == SDL_EVENT_MOUSE_MOTION &&app.StateActuel == State::Game) {
        float nouveauX, nouveauY;
        SDL_RenderCoordinatesFromWindow(app.renderer, event->motion.x, event->motion.y, &nouveauX, &nouveauY);
        app.publicOrderTooltipX = nouveauX;
        app.publicOrderTooltipY = nouveauY;
    }



    // Zoom
    if (event->type == SDL_EVENT_MOUSE_WHEEL && app.StateActuel == State::Game) {
        float factor = (event->wheel.y > 0) ? 1.1f : 0.9f;
        app.camera.Zoom(factor, 1920.f, 1080.f);
        }
    //When Mouse touch a edge it



    if (event->type == SDL_EVENT_KEY_DOWN) {
        //To put game in fullscreen
        if (event->key.scancode == SDL_SCANCODE_F) {
            //flag
            Uint32 FullScreenflag = SDL_GetWindowFlags(app.window);

            //si on est en plein ecran alors on retourne en fenetrer
            if (FullScreenflag & SDL_WINDOW_FULLSCREEN) {
                SDL_SetWindowFullscreen(app.window, 0); //0 -> fenetrer
            }
            //Sinon on va en fullscreen
            else {
                SDL_SetWindowFullscreen(app.window, SDL_WINDOW_FULLSCREEN);
            }
        }

        //to make the game on pause P

        //To escape
        if (event->key.scancode == SDL_SCANCODE_ESCAPE) {
            app.StateActuel = State::Quit;
        }
    }

    //If pressed on windowX -> Exit
    if (event->type == SDL_EVENT_QUIT) {
        app.StateActuel = State::Quit;
        return SDL_APP_CONTINUE;
    }

    return SDL_APP_CONTINUE;
}
SDL_AppResult
SDL_AppIterate(void *appstate) {
    return GameApp::GetInstance().RunCallBacks();
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    TTF_Quit();
}