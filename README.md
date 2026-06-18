<p align="center">
  <img src="assets/TileMap.png" alt="Total Battle 2D Banner" width="900">
</p>

<h1 align="center">Total Battle 2D</h1>

<p align="center">
  A grand strategy and real-time battles game built from scratch in <strong>C++</strong> and <strong>SDL3</strong>.<br>
  Manage provinces, construct buildings, balance your economy and food production, and lead your faction to dominance.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/version-0.1.0--prerelease-blue" alt="Version">
  <img src="https://img.shields.io/badge/language-C%2B%2B20-orange" alt="C++20">
  <img src="https://img.shields.io/badge/renderer-SDL3-green" alt="SDL3">
  <img src="https://img.shields.io/badge/status-Work%20In%20Progress-yellow" alt="WIP">
</p>

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Factions](#factions)
- [Game Systems](#game-systems)
- [Architecture](#architecture)
- [Getting Started](#getting-started)
- [Project Files](#project-Files)
- [Roadmap](#roadmap)

---

## Overview

**Total Battle 2D** is a self-made grand strategy game inspired by titles like *Total War* and *For Honor*, built entirely in C++ using the SDL3 library. Players choose to play the Knights, Vikings or samurai, manage a campaign map divided into provinces and settlements, construct faction-specific buildings, and work toward dominating the others with economic and military strenght.

The game features a full turn-based campaign layer with real-time rendering with SDL3, and a rich building system inspired by Total War.

---

## Features

-  **Three playable Cultures** : Knights, Vikings, and Samurai each with unique buildings, lore, and bonuses
-  **Province & settlement management** : Capitals, Castles, and Villages, each upgradable across multiple tiers
-  **Five building categories** : Military, Advanced Military, Defence, Economy, and Religion
-  **Economy system** : Money income, building upkeep, per-turn balance, and anticipated income UI
-  **Food storage system** : Food is produced, stored, and consumed, affecting public order
-  **Public order** : Per-province happiness tracked with visual indicators and tooltips
-  **Turn-based campaign** : End-turn button advances game state, triggering income, food, and AI turns
-  **Technology tree** : Dedicated tech panel accessible from the campaign map
-  **Audio** : Background music via SDL3_mixer with volume slider in options
-  **Custom UI** : Settlement panels, building slot popups, category selectors, cost tooltips

---

## Factions

| Faction | Playstyle | Unique Strengths |
|---------|-----------|-----------------|
| ⚔️ **Knights** | Balanced economy, strong crossbows & cavalry | Strong starting economy, Faith bonuses |
| 🪓 **Vikings** | Aggressive raiders, powerful melee | Raiding bonuses, Berserkers, Odin's Chosen |
| 🏯 **Samurai** | Ambush specialists, gunpowder access | Religion bonuses, powder units, siege engineering |

Each faction has fully independent settlement textures across all tiers (T1–T5 for Capitals and Castles, T1–T3 for Villages) to bring more immersion for the player.


---

## Game Systems

### Settlements & Provinces

The campaign map is divided into **9 provinces** (3 per faction), each containing one main settlement (Capital or Castle) and up to three Villages. Settlements upgrade through tiers, visually evolving on the map and unlocking higher-tier ?>>buildings.

### Building System

Buildings are organized into five categories, each with 2–5 upgrade levels:

- **Military** : Train infantry, archers, and cavalry (Tier 1+)
- **Advanced Military** : Siege engines, elite warriors, and gunpowder units (Tier 4+)
- **Defence** : Reinforce walls, drakkars, or castle fortifications (Tier 3+)
- **Economy** : Markets, farms, estates, and warehouses for food storage (Tier 1+)
- **Religion** : Churches, Shrines, Hospitals, and Shinto Chapels that improve public order (Tier 1+)

### Economy & Food

- Each turn calculates total income minus upkeep for the player's treasury
- Food is produced by farm-type buildings and consumed by military and structures.
- A **food storage bar** tracks stored food; low food reduces public order
- An **anticipated income Ui** shows the projected change before ending the turn

---

## Architecture

>GameApp (main.cpp)       — SDL3 init, game loop, rendering, input<br>
>State (.h/.cpp)          — Game state enum (Menu, Game, Options, Credits, Tech)<br>
>TileMap (.h/.cpp)        — To create the TileMap from a png.<br>
>Camera (.h/.cpp)         — Pan and zoom logic<br>
>Province (.h/.cpp)       — Province data and faction zone definitions<br>
>Settlements (.h/.cpp)    — Settlement types, tiers, and city data<br>
>Buildings (.h/.cpp)      — BuildingType enum, BuildingData struct, full database with all stats<br>
>TechnologyTree (.h/.cpp) — Technology research panel and tree<br>
>Player (.h/.cpp)         — Player state and resources<br>
>Entity (.h/.cpp)         — Base entity system<br>
>Components (.h/.cpp)     — ECS-style component data<br>
>UnitCardStats (.h/.cpp)  — Unit card statistics<br>
>FastNoiseLite.h          — Third-party header-only noise library

---

## Getting Started

### Prerequisites

- **CMake** ≥ 3.12
- **C++20** compatible compiler (GCC / MinGW recommended for Windows)
- **SDL3** (core, SDL3_image, SDL3_ttf) installed and accessible by CMake
- **SDL3_mixer 3.2.0** — bundled in `libs/SDL3_mixer-3.2.0/x86_64-w64-mingw32`
- **SQLite3** — linked via system or bundled library

### Building

git clone https://github.com/Ti-Loup/Total-Battle-2D.git
cmake: ninja

### Running

Open Total Battle 2D, Go to cmake-build-release, find the .exe

---

## Project Files

Total-Battle-2D/<br>
assets/               # Textures, fonts, audio, tilemaps<br>
-Knight               # Knight faction textures<br>
-Viking               # Viking faction textures<br>
-Samurai              # Samurai faction textures<br>

---

## Roadmap

| Version | Target | Status | Date | 
|---------|--------|--------|--------|
| **v0.1.0** | Campaign map, buildings, economy, | Released | May |
| **v0.1.5** | Food storage polish, texture fixes | Released | June |
| **v0.2.0** | Population system(farmers, nobility) | In Progress | July |
| **v0.2.5** | World Events + Climate (affect food production) | Planned | August |
| **Future** | Roads, playable technology tree, faction Unique mechanic, cinematic intro | Vision | one year |

---

<p align="center">
  Built with C++ by <a href="https://github.com/Ti-Loup">Louis-Philippe Gauvin</a>
</p>



