// time_test4.cpp - Unit test for time constructors.
// Results:
// 00:00
// Time: 20:10
// 20:10 (Passed)
// Author Andreas Lau
// Modified on 02/03/2021
//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
//Includes

#include <iostream>
#include "time.h"
//--------------------------------------------------------------------------------------------

void TestSetGet()
{
    Time time;
    std::cout << time.GetTimeString() << std::endl;
    time.SetMinute(10);
    time.SetHour(20);
    std::cout << "Time: " << time.GetHour() << ":" << time.GetMinute() << std::endl;
    std::cout << time.GetTimeString() << std::endl;
}

int main()
{
    TestSetGet();
    return(0);
}

