/*
 * BigTime.h - Class for printing large time values to a 20x4 LCD.
 */

#ifndef BigTime_h
#define BigTime_h

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "Time.h"

class BigTime
{
	public:
		BigTime(LiquidCrystal* lcd);
		void printTime(Time& time);
	private:
		LiquidCrystal* lcd;
		byte digitWidth;
		byte digitCache [20];
		void clearDigit(byte x);
		void printColon(byte x);
		void printDigit(byte digit, byte x);
		void printValue(byte value, byte x);
};

#endif
