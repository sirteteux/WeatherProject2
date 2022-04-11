// date.cpp
//
//Class for managing time information
//
//Version 02
//03/04/2021 Andreas Lau, included GetDateString to test day, month and year into date
//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
//Includes
#include "time.h"
//-------------------------------------------------------------------------------------------
// Function implementations

// Default constructor with parameters set to default 0
Time::Time(): m_hour(0), m_minute(0)
{

}

// Second default constructor to set time by hour and minute parameters
Time::Time(int hrs, int mins): m_hour(hrs), m_minute(mins)
{

}

// Third default constructor to set time by string time parameters
Time::Time(std::string time): m_hour(0), m_minute(0)
{
    std::string h, m;

    std::stringstream ss(time);
    getline(ss, h, ':');
    getline(ss, m);

    m_hour = stoi(h);
    m_minute = stoi(m);
}

//---------------------------------------------------------------------------------------------
// Set the value of hours
void Time::SetHour(int hrs)
{
    m_hour = hrs;
}

//---------------------------------------------------------------------------------------------
// return the value of hours
int Time::GetHour() const
{
    return m_hour;
}

//---------------------------------------------------------------------------------------------
// Set the value of minute
void Time::SetMinute(int mins)
{
    m_minute = mins;
}

//---------------------------------------------------------------------------------------------
// return the value of minute
int Time::GetMinute() const
{
    return m_minute;
}

//---------------------------------------------------------------------------------------------
// return the value of time in string
std::string Time::GetTimeString() const
{
    //converts hrs to string and gives leading 0 if required
    std::string hrs = std::to_string(m_hour);
    if(m_hour == 0)
        hrs = "00";
    else if(m_hour < 10)
        hrs = "0" + hrs;

    //converts mins to string and gives leading 0 if required
    std::string mins = std::to_string(m_minute);
    if(m_minute == 0)
        mins = "00";
    else if(m_minute < 10)
        mins = "0" + mins;

    return(hrs + ":" + mins);
}

//---------------------------------------------------------------------------------------------
// Assign the date as string in hh:mm'
Time& Time::operator=(std::string &time)
{
    std::string h, m;

    std::stringstream ss(time);
    getline(ss, h, ':');
    getline(ss, m);

    m_hour = stoi(h);
    m_minute = stoi(m);
}

//---------------------------------------------------------------------------------------------
// '<' overload operator
bool Time::operator<(const Time& other)
{
    return((m_hour < other.m_hour) ||
           (m_hour == other.m_hour && m_minute < other.m_minute));
}

//---------------------------------------------------------------------------------------------
// '>' overload operator
bool Time::operator>(const Time& other)
{
    return((m_hour > other.m_hour) ||
           (m_hour == other.m_hour && m_minute > other.m_minute));
}

//---------------------------------------------------------------------------------------------
// '==' overload operator
bool Time::operator==(const Time& other)
{
    return(m_hour == other.m_hour &&
           m_minute == other.m_minute );
}
