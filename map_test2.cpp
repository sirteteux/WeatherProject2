// map_test2.cpp - Unit test for maps
// Results: (Passed)
// Fifth : 5
// First : 1
// Fourth : 4
// Second : 2
// Third : 3
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
    Map<std::string, int> testMap;
    testMap["First"] = 1;
    testMap["Second"] = 2;
    testMap["Third"] = 3;
    testMap["Fourth"] = 4;
    testMap["Fifth"] = 5;
    testMap.GetIt() = testMap.ItBegin();
    while(testMap.GetIt() != testMap.ItEnd())
    {
        std::cout << testMap.GetIt()->first << " : " <<  testMap.GetIt()->second << std::endl;
        testMap.GetIt()++;
    }

    return(0);
}
