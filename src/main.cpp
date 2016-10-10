/**
 * Chess Clock Hacking.
 */

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "BigTime.h"

LiquidCrystal leftDisplay(6, 7, 2, 3, 4, 5);
LiquidCrystal rightDisplay(6, 8, 2, 3, 4, 5);

BigTime left(&leftDisplay);

void setup()
{
	leftDisplay.begin(20,4);
	leftDisplay.clear();
	left.begin();
	rightDisplay.begin(20,4);
	rightDisplay.clear();
}

void lcdTest()
{
	int i;
	for ( i=0; i<=9; i++ ) {
		left.printDigit(i, 0);
		left.printColon(3);
		left.printDigit(i, 4);
		left.printDigit(i, 7);
		left.printColon(10);
		left.printDigit(i, 11);
		left.printDigit(i, 14);

		rightDisplay.clear();
		rightDisplay.print("Testing right ");
		rightDisplay.print(i);

		delay(2000);
	}
}

void loop()
{
	lcdTest();
}
