// date_test1.cpp - Unit test for date constructors.
// Results:
// Day: 1
// Month: 3
// Year: 2015 (Passed)
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

void TestStringConstruct()
{
    Date date("01/03/2015");
    DisplayDate(date);
}

int main()
{
    TestStringConstruct();
    return(0);
}
