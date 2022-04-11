//windlog.cpp
//
//Class for managing calculations information
//
//Version 01
//25/02/2021 Andreas Lau, started
//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
//Includes

#include "windlog.h"
//---------------------------------------------------------------------------------------------
// Function implementations

Map<int, Map<int, float>> WindLog::GetAvgWindSpeed() const
{
    return m_windAvg;
}

Map<int, Map<int, float>> WindLog::GetWindStdDev() const
{
    return m_windStdDev;
}

Map<int, Map<int, float>> WindLog::GetAvgAirTemp() const
{
    return m_tempAvg;
}

Map<int, Map<int, float>> WindLog::GetTempStdDev() const
{
    return m_tempStdDev;
}

Map<int, Map<int, float>> WindLog::GetTotalSolarRadiation() const
{
    return m_solarTotal;
}

float WindLog::GetHighestRadiationDay() const
{
    return m_highSolar;
}

Vector<Time> WindLog::GetHighestRadiationTime() const
{
    return m_highSolarTime;
}


// Default constructor to set to default Windlog
WindLog::WindLog(Map<int, Map<int, WindLogType>> &windlog): m_windAvg(), m_windStdDev(), m_tempAvg(), m_tempStdDev(), m_solarTotal(), m_search(), m_highSolar(0), m_highSolarTime()
{
    ComputeData(windlog);
}

//windlog format = Map<first=Year, Second = Map<first=month, seccond = vector>>
void WindLog::ComputeData(Map<int, Map<int, WindLogType>> &windlog)
{
    WindLogType temp;

    int year, month;
    windlog.GetIt() = windlog.ItBegin();        //initialise year iterator
    while(windlog.GetIt() != windlog.ItEnd())       //for each year
    {
        year = windlog.GetIt()->first;      //set current year
        windlog.GetIt()->second.GetIt() = windlog.GetIt()->second.ItBegin();        //initialise month iterator
        while(windlog.GetIt()->second.GetIt() != windlog.GetIt()->second.ItEnd())       //for each month
        {
            month = windlog.GetIt()->second.GetIt()->first;     //set current month
            for(int i=0; i< windlog.GetIt()->second.GetIt()->second.ddate.GetCurrentSize(); i++)       //for each element in the vector
            {
                temp.ddate[i] = windlog.GetIt()->second.GetIt()->second.ddate[i];
                temp.wwindspeed[i] = windlog.GetIt()->second.GetIt()->second.wwindspeed[i] * 3.6;     // converts to km/h
                temp.aairTemp[i] = windlog.GetIt()->second.GetIt()->second.aairTemp[i];
                if(windlog.GetIt()->second.GetIt()->second.ssolarRadiation[i] >= 100)
                    temp.ssolarRadiation[i] = (windlog.GetIt()->second.GetIt()->second.ssolarRadiation[i] / 6 ) / 1000 ;        //convert to KWh
                else
                    temp.ssolarRadiation[i] = 0;
            }

            //cycle through all the temp month vectors and calculate averages
            if(temp.ddate.GetCurrentSize() > 0)
            {
                m_windAvg[std::move(year)][std::move(month)] = calculate::CalculateAvg(temp.wwindspeed);           //std::move required tomore &&rvalue reference
                m_windStdDev[std::move(year)][std::move(month)] = calculate::CalculateStdDev(temp.wwindspeed, calculate::CalculateAvg(temp.wwindspeed));
                m_tempAvg[std::move(year)][std::move(month)] = calculate::CalculateAvg(temp.aairTemp);
                m_tempStdDev[std::move(year)][std::move(month)] = calculate::CalculateStdDev(temp.aairTemp, calculate::CalculateAvg(temp.aairTemp));
                m_solarTotal[std::move(year)][std::move(month)] = calculate::CalculateTotal(temp.ssolarRadiation);

                m_search.AddLeaf(year*100 + month); //year*100 + month creates unique int, in order eg. Jul 2014 becomes 201407
            }
            windlog.GetIt()->second.GetIt()++;      //iterate month
        }
        windlog.GetIt()++;          //iterate year
    }
}

bool WindLog::SearchOutput(int yearMonth)
{
    return(m_search.SearchKey(yearMonth));
}

// Calculate Highest Solar Radiation
void WindLog::CalculateHighSolar(Map<int, Map<int, WindLogType>> &windlog, Date date)
{
    m_highSolar = 0;        //reset highest to 0
    m_highSolarTime.ClearVector();      //clear time array

    //Vectors for the given month
    Vector<Date> dateVector = windlog[std::move(date.GetYear())][std::move(date.GetMonth())].ddate;      //vector of dates within month
    Vector<Time> timeVector = windlog[std::move(date.GetYear())][std::move(date.GetMonth())].ttime;      //vector of times within month
    Vector<float> solarVector = windlog[std::move(date.GetYear())][std::move(date.GetMonth())].ssolarRadiation;        //vector ov solar radiation within month

    Vector<int> dayIndex;       //will hold list of month index of the day we want
    for(int i=0; i< dateVector.GetCurrentSize(); i++)      //for every day in the month
    {
        if(dateVector[i] == date)       //find the all index that have the day we want
            dayIndex.Push(i);
    }

    for(int i=0; i<dayIndex.GetCurrentSize(); i++)     //for every element in the day
    {
        if(solarVector[dayIndex[i]] == m_highSolar)     //if it's equal to current highest, add the time to vector
            m_highSolarTime.Push(timeVector[dayIndex[i]]);

        if(solarVector[dayIndex[i]] > m_highSolar)      //if it's higher than current highest, clear time array and set new highest
        {
            m_highSolar = solarVector[dayIndex[i]];
            m_highSolarTime.ClearVector();
            m_highSolarTime.Push(timeVector[dayIndex[i]]);
        }
    }
}
