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
		Clock(BigTime display);
		void start();
		void stop();
		void tick();
		void editHours();
		void editMinutes();
		void editSeconds();
		void incHours(int quantity = 1);
		void incMinutes(int quantity = 1);
		void incSeconds(int quantity = 1);
		byte hours;
		byte minutes;
		byte seconds;
		void printTestTime();
	private:
		unsigned long time;  // in milliseconds
		BigTime display;
};

#endif
