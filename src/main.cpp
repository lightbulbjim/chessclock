/*
 * Chess Clock Hacking.
 */

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "BigTime.h"

LiquidCrystal leftDisplay(6, 7, 2, 3, 4, 5);
LiquidCrystal rightDisplay(6, 8, 2, 3, 4, 5);

BigTime leftClock(&leftDisplay);
BigTime rightClock(&rightDisplay);

static unsigned long now;


void setup()
{
	leftDisplay.begin(20,4);
	leftDisplay.clear();
	rightDisplay.begin(20,4);
	rightDisplay.clear();
}


void clockTest()
{
	byte testTime = 99;
	while (true) {
		leftClock.printTime(testTime, testTime, testTime);
		rightClock.printTime(testTime, testTime, testTime);
		testTime--;
		delay(1000);
	}
}


void loop()
{
	now = millis();

	clockTest();
}
