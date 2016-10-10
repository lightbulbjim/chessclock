/**
 * Chess Clock Hacking.
 */

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "BigTime.h"

LiquidCrystal leftDisplay(6, 7, 2, 3, 4, 5);
LiquidCrystal rightDisplay(6, 8, 2, 3, 4, 5);

BigTime leftClock(&leftDisplay);
BigTime rightClock(&rightDisplay);


void setup()
{
	leftDisplay.begin(20,4);
	leftDisplay.clear();
	rightDisplay.begin(20,4);
	rightDisplay.clear();
}


void lcdTest()
{
	int i;
	for ( i=0; i<=9; i++ ) {
		leftDisplay.clear();
		leftDisplay.setCursor(0,3);
		leftDisplay.print("Testing left ");
		leftDisplay.print(i);

		leftClock.printDigit(i, 0);
		leftClock.printColon(3);
		leftClock.printDigit(i, 4);
		leftClock.printDigit(i, 7);
		leftClock.printColon(10);
		leftClock.printDigit(i, 11);
		leftClock.printDigit(i, 14);

		rightDisplay.clear();
		rightDisplay.setCursor(0,3);
		rightDisplay.print("Testing right ");
		rightDisplay.print(i);

		rightClock.printDigit(i, 0);
		rightClock.printColon(3);
		rightClock.printDigit(i, 4);
		rightClock.printDigit(i, 7);
		rightClock.printColon(10);
		rightClock.printDigit(i, 11);
		rightClock.printDigit(i, 14);

		delay(2000);
	}
}


void loop()
{
	lcdTest();
}
