// calculate.h

//-------------------------------------------------------------------------------------------
// Includes
#include "vector.h"
#include <cmath>

/**
* @namespace calculate
* @brief Simple mathematical template functions - Average, Standard deviation and Total.
*
*
* @author Andreas Lau Kuan Tze
* @version 01
* @date  11/04/2021
*
* @bug I may be wrong but there is no bugs at the moment.
*/

namespace calculate
{
    /**
    * @brief Calculates Average
    * @param Vector
    * @return Average
    */
    template<class T>
    float CalculateAvg(Vector<T> &data);

    /**
    * @brief Calculates standard deviation
    * @param Vector and average
    * @return Standard deviation
    */
    template<class T>
    float CalculateStdDev(Vector<T> &data, float avg);

    /**
    * @brief Calculates total
    * @param Vector
    * @return total
    */
    template<class T>
    float CalculateTotal(Vector<T> &data);
}

//-------------------------------------------------------------------------------------------
// Implementations

template<class T>
float calculate::CalculateAvg(Vector<T> &data)
{
    float sum = 0;
    int n = data.GetCurrentSize();

    for(int i = 0; i<n; i++)
        sum += data[i];

    return(sum/n);
}

template<class T>
float calculate::CalculateStdDev(Vector<T> &data, float avg)
{
    float sum = 0;
    int n = data.GetCurrentSize();

    for(int i=0; i<n; i++)
        sum += (data[i] - avg) * (data[i] - avg);

    return(sqrt( sum/(n-1) ));
}

template<class T>
float calculate::CalculateTotal(Vector<T> &data)
{
    float sum = 0;
    int n = data.GetCurrentSize();
    for(int i=0; i<n; i++)
        sum += data[i];

    return(sum);
}

