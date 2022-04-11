// map_test1.cpp - Unit test for maps
// Results: 69 (Passed)
//
// Author Andreas Lau
// Modified on 07/04/2021
//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
//Includes

#include <iostream>
#include "map.h"
#include "string"
//-------------------------------------------------------------------------------------------

int main()
{
    Map<int, Map<int, int>> testMap;
    int year =  1997;
    int month = 7;
    int value = 69;
    testMap[std::move(year)][std::move(month)] = value;
    std::cout << testMap[std::move(year)][std::move(month)];

    return(0);
}
