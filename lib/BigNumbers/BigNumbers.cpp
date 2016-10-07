/*
	BigNumbers.cpp - Library for printing big numbers to a 20x4 LCD.
*/

#include "BigNumbers.h"

byte LT[8] = 
{
 B00111,
 B01111,
 B11111,
 B11111,
 B11111,
 B11111,
 B11111,
 B11111
};
byte UB[8] =
{
 B11111,
 B11111,
 B11111,
 B00000,
 B00000,
 B00000,
 B00000,
 B00000
};
byte RT[8] =
{
 B11100,
 B11110,
 B11111,
 B11111,
 B11111,
 B11111,
 B11111,
 B11111
};
byte LL[8] =
{
 B11111,
 B11111,
 B11111,
 B11111,
 B11111,
 B11111,
 B01111,
 B00111
};
byte LB[8] =
{
 B00000,
 B00000,
 B00000,
 B00000,
 B00000,
 B11111,
 B11111,
 B11111
};
byte LR[8] =
{
 B11111,
 B11111,
 B11111,
 B11111,
 B11111,
 B11111,
 B11110,
 B11100
};
byte MB[8] =
{
 B11111,
 B11111,
 B11111,
 B00000,
 B00000,
 B00000,
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

// Creates BigNumbers object
// LiquidCrystal* lcd: LiquidCrystal object to use
BigNumbers::BigNumbers(LiquidCrystal* lcd)
{
	_lcd = lcd;
}

void BigNumbers::begin()
{
	// assignes each segment a print number
	_lcd->createChar(0,LT);
	_lcd->createChar(1,UB);
	_lcd->createChar(2,RT);
	_lcd->createChar(3,LL);
	_lcd->createChar(4,LB);
	_lcd->createChar(5,LR);
	_lcd->createChar(6,MB);
	_lcd->createChar(7,block);
}

// x is column of upper left corner for large character
void BigNumbers::clearDigit(byte x)
{
	_lcd->setCursor(x,0);
	_lcd->print("   ");
	_lcd->setCursor(x,1); 
	_lcd->print("   ");
}

// n is number to display, x is column of upper left corner for large character
void BigNumbers::printDigit(byte n, byte x)
{
	switch (n)
	{
		case 0:
		{
			_lcd->setCursor(0,0);
			_lcd->write(byte(0));
			_lcd->write(byte(1));
			_lcd->write(byte(2));
			_lcd->setCursor(0, 1);
			_lcd->write(byte(3));
			_lcd->write(byte(4));
			_lcd->write(byte(5));
			break;
		}
		case 1:
		{
			_lcd->setCursor(0,0);
			_lcd->write(byte(1));
			_lcd->write(byte(2));
			_lcd->setCursor(0, 1);
			_lcd->write(byte(4));
			_lcd->write(byte(7));
			_lcd->write(byte(4));
			break;
		}
		case 2:
		{
			_lcd->setCursor(0,0);
			_lcd->write(byte(6));
			_lcd->write(byte(6));
			_lcd->write(byte(2));
			_lcd->setCursor(0, 1);
			_lcd->write(byte(3));
			_lcd->write(byte(4));
			_lcd->write(byte(4));
			break;
		}
		case 3:
		{
			_lcd->setCursor(0,0);
			_lcd->write(byte(6));
			_lcd->write(byte(6));
			_lcd->write(byte(2));
			_lcd->setCursor(0, 1);
			_lcd->write(byte(4));
			_lcd->write(byte(4));
			_lcd->write(byte(5));
			break;
		}
		case 4:
		{
			_lcd->setCursor(0,0);
			_lcd->write(byte(3));
			_lcd->write(byte(4));
			_lcd->write(byte(7));
			_lcd->setCursor(2, 1);
			_lcd->write(byte(7));
			break;
		}
		case 5:
		{
			_lcd->setCursor(0,0);
			_lcd->write(byte(3));
			_lcd->write(byte(6));
			_lcd->write(byte(6));
			_lcd->setCursor(0, 1);
			_lcd->write(byte(4));
			_lcd->write(byte(4));
			_lcd->write(byte(5));
			break;
		}
		case 6:
		{
			_lcd->setCursor(0,0);
			_lcd->write(byte(0));
			_lcd->write(byte(6));
			_lcd->write(byte(6));
			_lcd->setCursor(0, 1);
			_lcd->write(byte(3));
			_lcd->write(byte(4));
			_lcd->write(byte(5));
			break;
		}
		case 7:
		{
			_lcd->setCursor(0,0);
			_lcd->write(byte(1));
			_lcd->write(byte(1));
			_lcd->write(byte(2));
			_lcd->setCursor(2, 1);
			_lcd->write(byte(7));
			break;
		}
		case 8:
		{
			_lcd->setCursor(0,0);
			_lcd->write(byte(0));
			_lcd->write(byte(6));
			_lcd->write(byte(2));
			_lcd->setCursor(0, 1);
			_lcd->write(byte(3));
			_lcd->write(byte(4));
			_lcd->write(byte(5));
			break;
		}
		case 9:
		{
			_lcd->setCursor(0,0);
			_lcd->write(byte(0));
			_lcd->write(byte(6));
			_lcd->write(byte(2));
			_lcd->setCursor(2, 1);
			_lcd->write(byte(7));
			break;
		}
	}
}
