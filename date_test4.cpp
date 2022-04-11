// date_test4.cpp - Unit test for date constructors.
// Results:
// 00/00/0 (Passed)
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

void TestGetDateString()
{
    Date date;
    std::cout << date.GetDateString();
}

int main()
{
    TestGetDateString();
    return(0);
}
