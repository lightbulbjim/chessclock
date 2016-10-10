/*
 * BigTime.h - Library for printing big numbers to a 20x4 LCD.
 */

#ifndef BigTime_h
#define BigTime_h

#include <Arduino.h>
#include <LiquidCrystal.h>

class BigTime
{
	public:
		BigTime(LiquidCrystal*);
		void clearDigit(byte x);
		void printColon(byte x);
		void printDigit(byte digit, byte x);
		void printTime(byte hours, byte minutes, byte seconds);
	private:
		LiquidCrystal* lcd;
};

#endif
