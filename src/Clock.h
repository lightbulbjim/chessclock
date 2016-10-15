/*
 * Clock.h - Class to represent a countdown clock.
 */

#ifndef Clock_h
#define Clock_h

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "Time.h"
#include "BigTime.h"

class Clock
{
	public:
		Clock(BigTime* display);
		void tick();
		void saveTime();
		void start();
		void stop();
		Time time;
	private:
		BigTime* display;
		bool running;
		unsigned long targetMilliseconds;
		unsigned long remainingMilliseconds;
};

#endif
