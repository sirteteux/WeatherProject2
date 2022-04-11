// date_test7.cpp - Unit test for date constructors.
// Results:
// Failed
// Passed (Passed)
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

void TestEqualTo()
{
    Date date, date2, date3;
    date = "02/07/2013";
    date2 = "02/07/2015";
    date3 = "20/05/2016";

    if(date == date2)
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";

    if(date != date3)
        std::cout << "PASSED \n";
    else
        std::cout << "FAILED\n";
}

int main()
{
    TestEqualTo();
    return(0);
}
