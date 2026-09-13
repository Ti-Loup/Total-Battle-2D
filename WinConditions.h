//
// Created by Louis-Philippe on 9/12/2026.
//
#pragma once
#ifndef TOTALBATTLE2D_WINCONDITIONS_H
#define TOTALBATTLE2D_WINCONDITIONS_H

#include <string>
#include <vector>
#include <unordered_map>


enum class WinConditionCategory {
    Conquest,
    Construction,
    Trade,
    Ultimate   // bottom bar, no Short/Long split
};
enum class WinConditionLength {
    Short,
    Long,
    None
};

struct WinConditionObjective {
    std::string descriptionTemplate;
    int targetAmount = 0;
};

struct WinConditionData {
    WinConditionCategory category = WinConditionCategory::Conquest;
    WinConditionLength length = WinConditionLength::Short;
    std::string name; // "Short Conquest Victory"
    std::vector<WinConditionObjective> objectives;
};

struct WinConditionKey {
    WinConditionCategory category;
    WinConditionLength length;
    bool operator==(const WinConditionKey& other) const {
        return category == other.category && length == other.length;
    }
};
struct WinConditionKeyHash {
    size_t operator()(const WinConditionKey& k) const {
        return std::hash<int>()((int)k.category * 10 + (int)k.length);
    }
};

inline const std::unordered_map<WinConditionKey, WinConditionData, WinConditionKeyHash>& GetWinConditionDatabase() {
    static const std::unordered_map<WinConditionKey, WinConditionData, WinConditionKeyHash> db = {

        //CONQUEST
        { {WinConditionCategory::Conquest, WinConditionLength::Short},
          { WinConditionCategory::Conquest, WinConditionLength::Short, "Short Conquest Victory",
            {
                {"Control {0} settlements, either by direct ownership or through vassals.", 80},
                {"Control {0} provinces in full, either by direct ownership or through vassals.", 15}
            }
          }
        },
        { {WinConditionCategory::Conquest, WinConditionLength::Long},
          { WinConditionCategory::Conquest, WinConditionLength::Long, "Long Conquest Victory",
            {
                {"Control {0} settlements, either by direct ownership or through vassals.", 110},
                {"Control {0} provinces in full, either by direct ownership or through vassals.", 25}
            }
          }
        },

        //CONSTRUCTION
        { {WinConditionCategory::Construction, WinConditionLength::Short},
          { WinConditionCategory::Construction, WinConditionLength::Short, "Short Construction Victory",
            {
                {"Construct {0} Tier 3 (or higher) buildings across your kingdom.", 10},
                {"Have {0} settlements reach their maximum tier.", 3}
            }
          }
        },
        { {WinConditionCategory::Construction, WinConditionLength::Long},
          { WinConditionCategory::Construction, WinConditionLength::Long, "Long Construction Victory",
            {
                {"Construct {0} Tier 3 (or higher) buildings across your kingdom.", 25},
                {"Have {0} settlements reach their maximum tier.", 8}
            }
          }
        },

        //TRADE
        { {WinConditionCategory::Trade, WinConditionLength::Short},
          { WinConditionCategory::Trade, WinConditionLength::Short, "Short Trade Victory",
            {
                {"Reach {0} gold in your treasury.", 10000},
                {"Store goods worth {0} gold at once, across all your regions.", 3000}
            }
          }
        },
        { {WinConditionCategory::Trade, WinConditionLength::Long},
          { WinConditionCategory::Trade, WinConditionLength::Long, "Long Trade Victory",
            {
                {"Reach {0} gold in your treasury.", 30000},
                {"Store goods worth {0} gold at once, across all your regions.", 8000}
            }
          }
        },

        //ULTIMATE
        { {WinConditionCategory::Ultimate, WinConditionLength::None},
          { WinConditionCategory::Ultimate, WinConditionLength::None, "Ultimate Victory",
            {
                {"Complete any of the Long Victory types, then eliminate every rival faction.", 0}
            }
          }
        },
    };
    return db;
}

inline const WinConditionData* GetWinConditionData(WinConditionCategory category, WinConditionLength length) {
    const auto& db = GetWinConditionDatabase();
    auto it = db.find({category, length});
    return (it != db.end()) ? &it->second : nullptr;
}

inline std::string FormatWinConditionObjective(const WinConditionObjective& objective) {
    std::string result = objective.descriptionTemplate;
    const std::string placeholder = "{0}";
    size_t pos = result.find(placeholder);
    if (pos != std::string::npos) {
        result.replace(pos, placeholder.length(), std::to_string(objective.targetAmount));
    }
    return result;
}

#endif //TOTALBATTLE2D_WINCONDITIONS_H