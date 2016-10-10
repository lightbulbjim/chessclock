/*
	BigTime.h - Library for printing big numbers to a 20x4 LCD.
*/

#ifndef BigTime_h
#define BigTime_h

#include <Arduino.h>
#include <LiquidCrystal.h>

class BigTime
{
	public:
		BigTime(LiquidCrystal*);
		void begin();
		void clearDigit(byte);
		void printColon(byte);
		void printDigit(byte, byte);
	private:
		LiquidCrystal* _lcd;
};

#endif
