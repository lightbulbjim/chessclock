/*
 * Clock.h - Library for managing the clocks.
 */

#ifndef Clock_h
#define Clock_h

#include <Arduino.h>
#include <LiquidCrystal.h>

class Clock
{
	public:
		Clock(LiquidCrystal*);
		void start();
		void stop();
		void tick();
		void editHours();
		void editMinutes();
		void editSeconds();
		void incHours(int quantity = 1);
		void incMinutes(int quantity = 1);
		void incSeconds(int quantity = 1);
		unsigned int hours;
		unsigned int minutes;
		unsigned int seconds;
	private:
		unsigned long time;  // in milliseconds
}

#endif
