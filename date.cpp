// date.cpp
//
//Class for managing date information
//
//Version 02
//02/04/2021 Andreas Lau, added overload operators and include m_ into members
//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
//Includes

#include "date.h"
//-------------------------------------------------------------------------------------------

Date::Date(): m_day(0), m_month(0), m_year(0)
{

}

// Second default constructor to set date by day, month and year parameters
Date::Date(int day, int month, int year): m_day(day), m_month(month), m_year(year)
{

}

// Third default constructor to set date by string date parameters
Date::Date(std::string date): m_day(0), m_month(0), m_year(0)
{
    std::string d, m, y;

    std::stringstream ss(date);
    getline(ss, d, '/');
    getline(ss, m, '/');
    getline(ss, y);

    m_day = stoi(d);
    m_month = stoi(m);
    m_year = stoi(y);
}

//---------------------------------------------------------------------------------------------
// Set the value of day
void Date::SetDay(int day)
{
    m_day = day;
}

//---------------------------------------------------------------------------------------------
// return the value of day
int Date::GetDay() const
{
    return m_day;
}

//---------------------------------------------------------------------------------------------
// Set the value of month
void Date::SetMonth(int month)
{
    m_month = month;
}

//---------------------------------------------------------------------------------------------
// return the value of month
int Date::GetMonth() const
{
    return m_month;
}

//---------------------------------------------------------------------------------------------
// set the value of year
void Date::SetYear(int year)
{
    year = year;
}

//---------------------------------------------------------------------------------------------
// return the value of year
int Date::GetYear() const
{
    return m_year;
}

//---------------------------------------------------------------------------------------------
// return the value of date in string
std::string Date::GetDateString() const
{
    //converts day to string and gives leading 0 if required
    std::string day = std::to_string(m_day);
    if(m_day < 10)
        day = "0" + day;

    //converts month to string and gives leading 0 if required
    std::string month = std::to_string(m_month);
    if(m_month < 10)
        month = "0" + month;

    std::string year = std::to_string(m_year);

    return(day + "/" + month + "/" + year);
}

//---------------------------------------------------------------------------------------------
// Assign the date as string in 'dd/mm/yyyy'
Date& Date::operator=(const std::string &date)
{
    std::string d, m, y;

    std::stringstream ss(date);
    getline(ss, d, '/');
    getline(ss, m, '/');
    getline(ss, y);

    m_day = stoi(d);
    m_month = stoi(m);
    m_year = stoi(y);

    return(*this);
}

//---------------------------------------------------------------------------------------------
// '<' overload operator
bool Date::operator<(const Date& other)
{
    return( (m_year < other.m_year) ||
           (m_year == other.m_year && m_month < other.m_month) ||
           (m_year == other.m_year && m_month == other.m_month &&
            m_day < other.m_day));
}

//---------------------------------------------------------------------------------------------
// '>' overload operator
bool Date::operator>(const Date& other)
{
    return( (m_year > other.m_year) ||
       (m_year == other.m_year && m_month > other.m_month) ||
       (m_year == other.m_year && m_month == other.m_month &&
        m_day > other.m_day));
}

//---------------------------------------------------------------------------------------------
// '==' overload operator
bool Date::operator==(const Date& other)
{
    return(m_day == other.m_day &&
           m_month == other.m_month &&
           m_year == other.m_year);
}

//---------------------------------------------------------------------------------------------
// '!=' overload operator
bool Date::operator!=(const Date& other)
{
    return(m_day != other.m_day ||
           m_month != other.m_month ||
           m_year != other.m_year);
}

//---------------------------------------------------------------------------------------------
// return integer months in string names
std::string Date::GetMonthString(int month)
{
    std::string const months[12] = {"January", "Febuary", "March", "April", "May",
    "June", "July", "August", "September", "October", "November", "December"};

    return(months[month-1]);       // -1 because counts from zero
}


