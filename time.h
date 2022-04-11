// time.h
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
//-------------------------------------------------------------------------------------------
// Include

#include <string>
#include <sstream>
//-------------------------------------------------------------------------------------------

/**
* @class Time
* @brief  This class is used to store the time of data.
*
* @author Andreas Lau Kuan Tze
* @version 01
* @date 02/04/2021 Andreas Lau, Include m_ into Time variable member
*
* @bug I may be wrong but there is no bugs at the moment.
*/

class Time
{
    public:

        /**
        *@brief default constructor
        */
        Time();

        /**
        * @brief default constructor of time
        *
        * @param int h and int m
        *
        * @return void
        */
        Time(int h, int m);

        /**
        *@brief Overloaded constructor
        *@param string 'HH:MM'
        */
        Time(std::string time);

        /**
        * @brief public function to set the value of hours
        *
        * @param h - value of hours as constant integer
        * @return void
        */
        void SetHour(int h);

        /**
        * @brief public function to get the hours
        *
        * @return value of hours
        */
        int GetHour() const;

        /**
        * @brief public function to set the value of the minutes
        *
        * @param m - value of minutes as constant integer
        * @return void
        */
        void SetMinute(int m);

        /**
        * @brief public function to get the minutes
        *
        * @return value of minutes
        */
        int GetMinute() const;

        /**
        *@brief Combines hours and minutes as a string
        *@return the time as a string
        */
        std::string GetTimeString() const;

        /**
        *@brief Assignment operator definition
        */
        Time& operator=(std::string &time);

            /**
        *@brief less than operator declaration
        *@param time object to compare
        */
        bool operator<(const Time& other);

        /**
        *@brief greater than operator declaration
        *@param time object to compare
        */
        bool operator>(const Time& other);

        /**
        *@brief equal to operator declaration
        *@param time object to compare
        */
        bool operator==(const Time& other);

        /**
        *@brief not equal to than operator declaration
        *@param time object to compare
        */
        bool operator!=(const Time& other);

private:
    int m_hour;
    int m_minute;
};

#endif // TIME_H_INCLUDED
