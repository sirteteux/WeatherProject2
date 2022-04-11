//windlogtype.h

#ifndef WINDLOGTYPE_H
#define WINDLOGTYPE_H
//-------------------------------------------------------------------------------------------
// Includes

#include "vector.h"
#include "date.h"
#include "time.h"

/**
*@struct
*@brief Holds relevant file date
*
* @author Andreas Lau
* @version 01
* @date 05 May 21
*/

struct WindLogType
{
    /**
    *@brief  default constructor
    */
    WindLogType();

    Vector<Date> ddate;
    Vector<Time> ttime;
    Vector<float> wwindspeed;        //meters per second
    Vector<float> aairTemp;      //ambient air temperature
    Vector<float> ssolarRadiation;     //Solar radiation
};

inline WindLogType::WindLogType()
    : ddate(), ttime(), wwindspeed(), aairTemp(), ssolarRadiation() {}

#endif // WINDLOGTYPE_H

