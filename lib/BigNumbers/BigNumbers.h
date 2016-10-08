/*
	BigNumbers.h - Library for printing big numbers to a 20x4 LCD.
*/

#ifndef BigNumbers_h
#define BigNumbers_h

#include "Arduino.h"
#include "LiquidCrystal.h"

class BigNumbers
{
	public:
		BigNumbers(LiquidCrystal*);
		void begin();
		void clearDigit(byte);
		void printColon(byte);
		void printDigit(byte, byte);
	private:
		LiquidCrystal* _lcd;
};

#endif
