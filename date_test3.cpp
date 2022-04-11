// date_test1.cpp - Unit test for date constructors.
// Results:
// Day: 28
// Month: 03
// Year: 0 since there is no record of 2021 (Passed)
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

void TestSetters()
{
    Date date;
    date.SetDay(28);
    date.SetMonth(03);
    date.SetYear(2021);
    DisplayDate(date);
}

int main()
{
    TestSetters();
    return(0);
}
