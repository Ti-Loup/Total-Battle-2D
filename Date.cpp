//
// Created by Louis-Philippe on 7/9/2026.
//

#include "Date.h"
#include <algorithm>

namespace Date {
    std::string GetMonthName(int month) {
        static const char* monthNames[12] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };
        return monthNames[std::clamp(month - 1, 0, 11)];
    }

    void GetCurrentDate(int currentTurn, int &outYear, int &outMonth,
                        int startYear, int startMonth) {
        int zeroBasedTurn = currentTurn - 1; // Turn 1 = the starting month/year
        int totalMonths = (startMonth - 1) + zeroBasedTurn;
        outYear  = startYear + totalMonths / 12;
        outMonth = 1 + totalMonths % 12;
    }

    std::string GetDateString(int currentTurn, int startYear, int startMonth) {
        int year = 0, month = 0;
        GetCurrentDate(currentTurn, year, month, startYear, startMonth);
        return GetMonthName(month) + ", Year " + std::to_string(year);
    }

    Season GetSeasonForMonth(int month) {
        // Winter = Nov, Dec, Jan
        if (month == 11 || month == 12 || month == 1) return Season::Winter;
        // Spring = Feb, Mar, Apr
        if (month >= 2 && month <= 4) return Season::Spring;
        // Summer = May, Jun, Jul
        if (month >= 5 && month <= 7) return Season::Summer;
        // Autumn = Aug, Sep, Oct
        return Season::Autumn;
    }

    Season GetCurrentSeason(int currentTurn, int startMonth) {
        int zeroBasedTurn = currentTurn - 1;
        int monthIndex = (startMonth - 1 + zeroBasedTurn) % 12; // 0-11
        int month = monthIndex + 1;
        return GetSeasonForMonth(month);
    }

    std::string GetSeasonName(Season season) {
        switch (season) {
            case Season::Winter: return "Winter";
            case Season::Spring: return "Spring";
            case Season::Summer: return "Summer";
            case Season::Autumn: return "Autumn";
        }
        return "";
    }
}
