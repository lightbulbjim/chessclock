/*
 * Time.cpp - Class to represent a time period.
 */

#include "Time.h"


bool Time::isZero()
{
	return (this->hours == 0) || (this->minutes == 0) || (this->seconds == 0);
}
