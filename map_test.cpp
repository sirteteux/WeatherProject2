// map_test.cpp - Unit test for maps
// Results (Passed)
//January 2001
//Febuary 2001
//July 2003
//November 2003
//July 2004
//December 2004
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
    Map<int, Map<int, std::string>> testMap;
    testMap[2001][01] = "January 2001";
    testMap[2001][02] = "Febuary 2001";
    testMap[2003][07] = "July 2003";
    testMap[2004][12] = "December 2004";
    testMap[2003][11] = "November 2003";
    testMap[2004][07] = "July 2004";

    testMap.GetIt() = testMap.ItBegin();
    while(testMap.GetIt() != testMap.ItEnd())
    {
        testMap.GetIt()->second.GetIt() = testMap.GetIt()->second.ItBegin();
        while(testMap.GetIt()->second.GetIt() != testMap.GetIt()->second.ItEnd())
        {
            std::cout << testMap.GetIt()->second.GetIt()->second << std::endl;
            testMap.GetIt()->second.GetIt()++;
        }
        testMap.GetIt()++;
    }

    return(0);
}
