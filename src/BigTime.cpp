/*
 * BigTime.cpp - Class for printing large time values to a 20x4 LCD.
 */

#include "BigTime.h"


byte custom1[8] = 
{
	B00011,
	B00111,
	B01111,
	B11111,
	B00000,
	B00000,
	B00000,
	B00000
};

byte custom2[8] =
{
	B11000,
	B11100,
	B11110,
	B11111,
	B00000,
	B00000,
	B00000,
	B00000
};

byte custom3[8] =
{
	B11111,
	B11111,
	B11111,
	B11111,
	B00000,
	B00000,
	B00000,
	B00000
};

byte custom4[8] =
{
	B11111,
	B11110,
	B11100,
	B11000,
	B00000,
	B00000,
	B00000,
	B00000
};

byte custom5[8] =
{
	B11111,
	B01111,
	B00111,
	B00011,
	B00000,
	B00000,
	B00000,
	B00000
};

byte custom6[8] =
{
	B00011,
	B00111,
	B01111,
	B11111,
	B11111,
	B11111,
	B11111,
	B11111
};

byte custom7[8] =
{
	B11000,
	B11100,
	B11110,
	B11111,
	B11111,
	B11111,
	B11111,
	B11111
};

byte block[8] =
{
	B11111,
	B11111,
	B11111,
	B11111,
	B11111,
	B11111,
	B11111,
	B11111
};


BigTime::BigTime(LiquidCrystal* lcd)
{
	this->lcd = lcd;
	this->digitWidth = 3;

	for (byte i=0; i<20; i++) {
		this->digitCache[i] = 255;
	}

	this->lcd->createChar(0, custom1);
	this->lcd->createChar(1, custom2);
	this->lcd->createChar(2, custom3);
	this->lcd->createChar(3, custom4);
	this->lcd->createChar(4, custom5);
	this->lcd->createChar(5, custom6);
	this->lcd->createChar(6, custom7);
	this->lcd->createChar(7, block);
}


void BigTime::clearDigit(byte x)
{
	this->lcd->setCursor(x, 0);
	this->lcd->print(F("   "));
	this->lcd->setCursor(x, 1); 
	this->lcd->print(F("   "));
	this->lcd->setCursor(x, 2); 
	this->lcd->print(F("   "));
}


void BigTime::printColon(byte x)
{
	this->lcd->setCursor(x, 0);
	this->lcd->print("o");
	this->lcd->setCursor(x, 1);
	this->lcd->print("o");
}


void BigTime::printDigit(byte digit, byte x)
{
	if (this->digitCache[x] == digit) {
		return;
	}

	this->digitCache[x] = digit;

	clearDigit(x);
	switch (digit)
	{
		case 0:
		{
			this->lcd->setCursor(x, 0);
			this->lcd->write(byte(5));
			this->lcd->write(byte(2));
			this->lcd->write(byte(6));
			this->lcd->setCursor(x, 1);
			this->lcd->write(byte(7));
			this->lcd->setCursor(x + 2, 1);
			this->lcd->write(byte(7));
			this->lcd->setCursor(x, 2);
			this->lcd->write(byte(4));
			this->lcd->write(byte(2));
			this->lcd->write(byte(3));
			break;
		}
		case 1:
		{
			this->lcd->setCursor(x, 0);
			this->lcd->write(byte(0));
			this->lcd->write(byte(7));
			this->lcd->setCursor(x + 1, 1);
			this->lcd->write(byte(7));
			this->lcd->setCursor(x, 2);
			this->lcd->write(byte(2));
			this->lcd->write(byte(2));
			this->lcd->write(byte(2));
			break;
		}
		case 2:
		{
			this->lcd->setCursor(x,0);
			this->lcd->write(byte(0));
			this->lcd->write(byte(2));
			this->lcd->write(byte(6));
			this->lcd->setCursor(x, 1);
			this->lcd->write(byte(5));
			this->lcd->write(byte(2));
			this->lcd->write(byte(3));
			this->lcd->setCursor(x, 2);
			this->lcd->write(byte(4));
			this->lcd->write(byte(2));
			this->lcd->write(byte(3));
			break;
		}
		case 3:
		{
			this->lcd->setCursor(x, 0);
			this->lcd->write(byte(0));
			this->lcd->write(byte(2));
			this->lcd->write(byte(6));
			this->lcd->setCursor(x + 1, 1);
			this->lcd->write(byte(2));
			this->lcd->write(byte(7));
			this->lcd->setCursor(x, 2);
			this->lcd->write(byte(4));
			this->lcd->write(byte(2));
			this->lcd->write(byte(3));
			break;
		}
		case 4:
		{
			this->lcd->setCursor(x, 0);
			this->lcd->write(byte(7));
			this->lcd->setCursor(x + 2, 0);
			this->lcd->write(byte(7));
			this->lcd->setCursor(x, 1);
			this->lcd->write(byte(4));
			this->lcd->write(byte(2));
			this->lcd->write(byte(7));
			this->lcd->setCursor(x + 2, 2);
			this->lcd->write(byte(2));
			break;
		}
		case 5:
		{
			this->lcd->setCursor(x, 0);
			this->lcd->write(byte(7));
			this->lcd->write(byte(2));
			this->lcd->write(byte(3));
			this->lcd->setCursor(x, 1);
			this->lcd->write(byte(2));
			this->lcd->write(byte(2));
			this->lcd->write(byte(6));
			this->lcd->setCursor(x, 2);
			this->lcd->write(byte(4));
			this->lcd->write(byte(2));
			this->lcd->write(byte(3));
			break;
		}
		case 6:
		{
			this->lcd->setCursor(x, 0);
			this->lcd->write(byte(5));
			this->lcd->write(byte(2));
			this->lcd->write(byte(1));
			this->lcd->setCursor(x, 1);
			this->lcd->write(byte(7));
			this->lcd->write(byte(2));
			this->lcd->write(byte(6));
			this->lcd->setCursor(x, 2);
			this->lcd->write(byte(4));
			this->lcd->write(byte(2));
			this->lcd->write(byte(3));
			break;
		}
		case 7:
		{
			this->lcd->setCursor(x, 0);
			this->lcd->write(byte(4));
			this->lcd->write(byte(2));
			this->lcd->write(byte(7));
			this->lcd->setCursor(x + 1, 1);
			this->lcd->write(byte(5));
			this->lcd->write(byte(3));
			this->lcd->setCursor(x + 1, 2);
			this->lcd->write(byte(2));
			break;
		}
		case 8:
		{
			this->lcd->setCursor(x, 0);
			this->lcd->write(byte(5));
			this->lcd->write(byte(2));
			this->lcd->write(byte(6));
			this->lcd->setCursor(x, 1);
			this->lcd->write(byte(7));
			this->lcd->write(byte(2));
			this->lcd->write(byte(7));
			this->lcd->setCursor(x, 2);
			this->lcd->write(byte(4));
			this->lcd->write(byte(2));
			this->lcd->write(byte(3));
			break;
		}
		case 9:
		{
			this->lcd->setCursor(x, 0);
			this->lcd->write(byte(5));
			this->lcd->write(byte(2));
			this->lcd->write(byte(6));
			this->lcd->setCursor(x, 1);
			this->lcd->write(byte(4));
			this->lcd->write(byte(2));
			this->lcd->write(byte(7));
			this->lcd->setCursor(x, 2);
			this->lcd->write(byte(4));
			this->lcd->write(byte(2));
			this->lcd->write(byte(3));
			break;
		}
	}
}


void BigTime::printValue(byte value, byte x)
{
	if (value < 10) {
		this->printDigit(0, x);
		this->printDigit(value, x + this->digitWidth);
	} else {
		this->printDigit((value / 10) % 10, x);
		this->printDigit(value % 10, x + this->digitWidth);
	}
}


void BigTime::printTime(Time& time)
{
	byte x = 0;

	this->printValue(time.hours, x);
	x += (this->digitWidth * 2);

	this->printColon(x);
	x += 1;

	this->printValue(time.minutes, x);
	x += (this->digitWidth * 2);

	this->printColon(x);
	x += 1;

	this->printValue(time.seconds, x);
	x += (this->digitWidth * 2);
}
