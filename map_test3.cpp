// map_test3.cpp - Unit test for maps
// Results: (Passed)
// 10 Elements in Map
// 0
// 3
// 6
// 9
// 12
// 15
// 18
// 21
// 24
// 27
// Author Andreas Lau
// Modified on 07/04/2021
//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
// Includes

#include <iostream>
#include "map.h"
#include "string"
//-------------------------------------------------------------------------------------------

int main()
{
    Map<int, int> testMap;
    for(int i=0; i<10; i++)
        testMap.Add(i, i*3);
    std::cout << testMap.GetSize() << " Elements in Map\n";
    for(int i=0; i<10; i++)
        std::cout << testMap.GetAt(i) << std::endl;

    return(0);
}
