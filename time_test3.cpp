// time_test3.cpp - Unit test for time constructors.
// Results: 10:40 (Passed)
// Author Andreas Lau
// Modified on 02/03/2021
//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
//Includes

#include <iostream>
#include "time.h"
//--------------------------------------------------------------------------------------------

void testStringConstruct()
{
    Time time("10:40");
    std::cout << time.GetTimeString() << std::endl;
}

int main()
{
    testStringConstruct();
    return(0);
}

