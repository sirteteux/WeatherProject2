// windlog.h
#ifndef WINDLOG_H
#define WINDLOG_H
//-------------------------------------------------------------------------------------------
// Includes

#include <iostream>
#include <string>
#include "calculate.h"
#include "windlogType.h"
#include "BSTree.h"
#include "map.h"
//-------------------------------------------------------------------------------------------

struct WindLogType;


/**
* @class WindLog
* @brief  This class contain a struct that store data of date class, time class,
*          windspeed, air temperature and solar radiation. Besides, this class is
*          used to do the calculations of data, such as calculating the average of
*          windspeed and air temperature and the total solar radiation.
*
* @author Andreas
* @version 02
* @date 04/04/2021 Andreas Lau updated for menu 5 and changed all function names in caps
*
* @bug I may be wrong but there is no bugs at the moment.
*/

class WindLog
{
    public:
        /**
        *@brief Constructs and fills the relevant data ready for output
        *@param The full windlog struct, and the specified year
        */
        WindLog(Map<int, Map<int, WindLogType>> &windlog);

        /**
        *@brief Gets month
        *@return The month
        */
        Map<int, Map<int, std::string>> GetMonth() const;

        /**
        *@brief Gets the average wind speed
        *@return wind average
        */
        Map<int, Map<int, float>> GetAvgWindSpeed() const;

        /**
        *@brief Gets wind standard deviation
        *@return the wind standard deviation
        */
        Map<int, Map<int, float>> GetWindStdDev() const;

        /**
        *@brief Average temperature
        *@return temperature average
        */
        Map<int, Map<int, float>> GetAvgAirTemp() const;

        /**
        *@brief Gets temperature standard deviation
        *@return temperature standard deviation
        */
        Map<int, Map<int, float>> GetTempStdDev() const;

        /**
        *@brief Gets Solar radiation total
        *@return Solar radiation total
        */
        Map<int, Map<int, float>> GetTotalSolarRadiation() const;

        /**
        *@brief Gets the highest solar value for specified day
        *@return the highest solar value
        */
        float GetHighestRadiationDay() const;

        /**
        *@brief Gets the time of day the highest solar value was recorded
        *@return Vector of the times
        */
        Vector<Time> GetHighestRadiationTime() const;

        /**
        *@brief searches quickly if there's data for that year/month
        *@param int specifying year and month with the formula year*100 + month
        *@return true if data exists for that year/month
        */
        bool SearchOutput(int yearMonth);

        /**
        *@brief Calculates the highest solar in a given a day
        *@param the complete windlog reference and the given date
        */
        void CalculateHighSolar(Map<int, Map<int, WindLogType>> &windlog, Date date);

    private:

        BST<int> m_search;

        Map<int, Map<int, float>> m_windAvg;
        Map<int, Map<int, float>> m_windStdDev;
        Map<int, Map<int, float>> m_tempAvg;
        Map<int, Map<int, float>> m_tempStdDev;
        Map<int, Map<int, float>> m_solarTotal;
        float m_highSolar;
        Vector<Time> m_highSolarTime;

        /**
        *@brief computes the data from windlog into the desired ouput information - called by the constructor
        *@param the windlog reference
        */
        void ComputeData(Map<int, Map<int, WindLogType>> &windlog);
};

#endif // WINDLOG_H
