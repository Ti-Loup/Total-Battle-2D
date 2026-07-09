//
// Created by Louis-Philippe on 7/9/2026.
//
#ifndef TOTALBATTLE2D_DATE_H
#define TOTALBATTLE2D_DATE_H
#pragma once
#include <string>
/*
* Simple Calendar that display the current Month and the year
*/
namespace Date {

    enum class Season { Winter, Spring, Summer, Autumn };

        std::string GetMonthName(int month);
        // startYear/startMonth to chose in GameApp
        void GetCurrentDate(int currentTurn, int &outYear, int &outMonth,
                            int startYear = 1, int startMonth = 1);

        std::string GetDateString(int currentTurn, int startYear = 1, int startMonth = 1);

        Season GetCurrentSeason(int currentTurn, int startMonth = 1);

        Season GetSeasonForMonth(int month);

        std::string GetSeasonName(Season season);
}




#endif //TOTALBATTLE2D_DATE_H
