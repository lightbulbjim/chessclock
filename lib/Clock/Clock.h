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
		void tick();
		void saveTime();
		void start();
		void stop();
		byte hours;
		byte minutes;
		byte seconds;
		unsigned long targetMilliseconds;
		unsigned long remainingMilliseconds;
	private:
		BigTime* display;
		bool running;
};

#endif
