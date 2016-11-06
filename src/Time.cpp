/*
 * Time.cpp - Class to represent a time period.
 */

#include "Time.h"


bool Time::isZero()
{
	return (this->hours == 0) || (this->minutes == 0) || (this->seconds == 0);
}


unsigned int Time::inMinutes()
{
	return (this->hours * 60) + this->minutes;
}


unsigned long Time::inSeconds()
{
	return (this->inMinutes() * 60) + this->seconds;
}
