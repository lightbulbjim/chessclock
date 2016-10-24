/*
 * Time.h - Class to represent a time period.
 */

#ifndef Time_h
#define Time_h

#include <Arduino.h>

class Time
{
	public:
		byte hours = 0;
		byte minutes = 0;
		byte seconds = 0;
		bool isZero();
};

#endif
