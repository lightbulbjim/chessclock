/*
 * Clock.h - Library for managing the clocks.
 */

#ifndef Clock_h
#define Clock_h

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <BigTime.h>

class Clock
{
	public:
		Clock(BigTime* display);
		void start();
		void stop();
		void tick();
		void setHours(byte hours);
		void setMinutes(byte minutes);
		void setSeconds(byte seconds);
		byte hours;
		byte minutes;
		byte seconds;
	private:
		BigTime* display;
		unsigned long target_milliseconds;
};

#endif
