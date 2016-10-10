/*
	BigTime.cpp - Library for printing big numbers to a 20x4 LCD.
*/

#include <BigTime.h>

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
	_lcd = lcd;

	// assignes each segment a print number
	_lcd->createChar(0,custom1);
	_lcd->createChar(1,custom2);
	_lcd->createChar(2,custom3);
	_lcd->createChar(3,custom4);
	_lcd->createChar(4,custom5);
	_lcd->createChar(5,custom6);
	_lcd->createChar(6,custom7);
	_lcd->createChar(7,block);
}

// x is column number
void BigTime::clearDigit(byte x)
{
	_lcd->setCursor(x,0);
	_lcd->print("   ");
	_lcd->setCursor(x,1); 
	_lcd->print("   ");
	_lcd->setCursor(x,2); 
	_lcd->print("   ");
}

// x is column number
void BigTime::printColon(byte x)
{
	_lcd->setCursor(x,0);
	_lcd->print("o");
	_lcd->setCursor(x,1);
	_lcd->print("o");
}

// n is number to display, x is column number
void BigTime::printDigit(byte n, byte x)
{
	clearDigit(x);
	switch (n)
	{
		case 0:
		{
			_lcd->setCursor(x,0);
			_lcd->write(byte(5));
			_lcd->write(byte(2));
			_lcd->write(byte(6));
			_lcd->setCursor(x, 1);
			_lcd->write(byte(7));
			_lcd->setCursor(x + 2, 1);
			_lcd->write(byte(7));
			_lcd->setCursor(x, 2);
			_lcd->write(byte(4));
			_lcd->write(byte(2));
			_lcd->write(byte(3));
			break;
		}
		case 1:
		{
			_lcd->setCursor(x,0);
			_lcd->write(byte(0));
			_lcd->write(byte(7));
			_lcd->setCursor(x + 1, 1);
			_lcd->write(byte(7));
			_lcd->setCursor(x, 2);
			_lcd->write(byte(2));
			_lcd->write(byte(2));
			_lcd->write(byte(2));
			break;
		}
		case 2:
		{
			_lcd->setCursor(x,0);
			_lcd->write(byte(0));
			_lcd->write(byte(2));
			_lcd->write(byte(6));
			_lcd->setCursor(x, 1);
			_lcd->write(byte(5));
			_lcd->write(byte(2));
			_lcd->write(byte(3));
			_lcd->setCursor(x, 2);
			_lcd->write(byte(4));
			_lcd->write(byte(2));
			_lcd->write(byte(3));
			break;
		}
		case 3:
		{
			_lcd->setCursor(x,0);
			_lcd->write(byte(0));
			_lcd->write(byte(2));
			_lcd->write(byte(6));
			_lcd->setCursor(x + 1, 1);
			_lcd->write(byte(2));
			_lcd->write(byte(7));
			_lcd->setCursor(x, 2);
			_lcd->write(byte(4));
			_lcd->write(byte(2));
			_lcd->write(byte(3));
			break;
		}
		case 4:
		{
			_lcd->setCursor(x,0);
			_lcd->write(byte(7));
			_lcd->setCursor(x + 2,0);
			_lcd->write(byte(7));
			_lcd->setCursor(x, 1);
			_lcd->write(byte(4));
			_lcd->write(byte(2));
			_lcd->write(byte(7));
			_lcd->setCursor(x + 2, 2);
			_lcd->write(byte(2));
			break;
		}
		case 5:
		{
			_lcd->setCursor(x,0);
			_lcd->write(byte(7));
			_lcd->write(byte(2));
			_lcd->write(byte(3));
			_lcd->setCursor(x, 1);
			_lcd->write(byte(2));
			_lcd->write(byte(2));
			_lcd->write(byte(6));
			_lcd->setCursor(x, 2);
			_lcd->write(byte(4));
			_lcd->write(byte(2));
			_lcd->write(byte(3));
			break;
		}
		case 6:
		{
			_lcd->setCursor(x,0);
			_lcd->write(byte(5));
			_lcd->write(byte(2));
			_lcd->write(byte(1));
			_lcd->setCursor(x, 1);
			_lcd->write(byte(7));
			_lcd->write(byte(2));
			_lcd->write(byte(6));
			_lcd->setCursor(x, 2);
			_lcd->write(byte(4));
			_lcd->write(byte(2));
			_lcd->write(byte(3));
			break;
		}
		case 7:
		{
			_lcd->setCursor(x,0);
			_lcd->write(byte(4));
			_lcd->write(byte(2));
			_lcd->write(byte(7));
			_lcd->setCursor(x + 1, 1);
			_lcd->write(byte(5));
			_lcd->write(byte(3));
			_lcd->setCursor(x + 1, 2);
			_lcd->write(byte(2));
			break;
		}
		case 8:
		{
			_lcd->setCursor(x,0);
			_lcd->write(byte(5));
			_lcd->write(byte(2));
			_lcd->write(byte(6));
			_lcd->setCursor(x, 1);
			_lcd->write(byte(7));
			_lcd->write(byte(2));
			_lcd->write(byte(7));
			_lcd->setCursor(x, 2);
			_lcd->write(byte(4));
			_lcd->write(byte(2));
			_lcd->write(byte(3));
			break;
		}
		case 9:
		{
			_lcd->setCursor(x,0);
			_lcd->write(byte(5));
			_lcd->write(byte(2));
			_lcd->write(byte(6));
			_lcd->setCursor(x, 1);
			_lcd->write(byte(4));
			_lcd->write(byte(2));
			_lcd->write(byte(7));
			_lcd->setCursor(x, 2);
			_lcd->write(byte(4));
			_lcd->write(byte(2));
			_lcd->write(byte(3));
			break;
		}
	}
}
