// date_test.cpp - Unit test for date constructors.
// Results:
// Day: 0
// Month: 0
// Year: 0 (Passed)
// Author Andreas Lau
// Modified on 02/03/2021
//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
//Includes

#include <iostream>
#include "date.h"
//--------------------------------------------------------------------------------------------

void DisplayDate(Date &date)
{
    std::cout << "Day: " << date.GetDay() << std::endl;
    std::cout << "Month: " << date.GetMonth() <<std::endl;
    std::cout << "Year: " << date.GetYear() << std::endl;
}

void TestConstruct()
{
    Date date;
    DisplayDate(date);
}

int main()
{
    TestConstruct();
    return(0);
}

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
//Includes
