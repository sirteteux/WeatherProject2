// date.h
#ifndef DATE_H
#define DATE_H
//-------------------------------------------------------------------------------------------
// Includes

#include <string>
#include <sstream>
//-------------------------------------------------------------------------------------------

/**
* @class Date
* @brief  This class is used to store the date of the date.
*
* @author Andreas Lau Kuan Tze
* @version 02
* @date 02/04/2021 Andreas Lau, added overload operators and include m_ into members
*
* @bug I may be wrong but there is no bugs at the moment.
*/

class Date
{
    public:

        /**
        *@brief default constructor
        */
        Date();

        /**
        *@brief default constructor with parameters for date class
        */
        Date(int day, int month, int year);

        /**
        * @brief default constructor that construct a date from string dd/mm/yyyy
        */
        Date(std::string date);

        /**
        * @brief public function to set the value of day
        *
        * @param day - value of day as integer
        * @return void
        */
        void SetDay(int day);

        /**
        * @brief public function to get the day
        *
        * @return value of day
        */
        int GetDay() const;

        /**
        * @brief public function to set the value of the month
        *
        * @param month - value of month as constant integer
        * @return void
        */
        void SetMonth(int month);

        /**
        * @brief  public function to get the value of month.
        *
        * @return value of month.
        */
        int GetMonth() const;

        /**
        * @brief public function to set the value of the year
        *
        * @param year - value of year as constant integer
        * @return void
        */
        void SetYear(int day);

        /**
        * @brief  public function to get the value of year.
        *
        * @return value of year.
        */
        int GetYear() const;

        /**
        *@brief public function to get the value of date in string
        *
        *@return returns date as string
        */
        std::string GetDateString() const;

        /**
        *@brief Assignment operator declaration
        *
        *@param the date as a string 'dd/mm/yyyy'
        */
        Date& operator= (const std::string &date);

        /**
        *@brief less than operator declaration
        *
        *@param date object to compare
        */
        bool operator< (const Date& other);

        /**
        *@brief greater than operator declaration
        *
        *@param date object to compare
        */
        bool operator> (const Date& other);

        /**
        *@brief equal to operator declaration
        *
        *@param date object to compare
        */
        bool operator== (const Date& other);

        /**
        *@brief not equal to than operator declaration
        *
        *@param date object to compare
        */
        bool operator!= (const Date& other);

        /**
        *@brief Returns the month as a string
        *
        *@return month as a string
        */
        static std::string GetMonthString(int month);

private:
    int m_day;
    int m_month;
    int m_year;
};

#endif
