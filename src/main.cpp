/*
 * Chess Clock Hacking.
 */

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "BigTime.h"
#include "Clock.h"

LiquidCrystal leftDisplay(6, 7, 2, 3, 4, 5);
LiquidCrystal rightDisplay(6, 8, 2, 3, 4, 5);

BigTime leftBigTime(&leftDisplay);
BigTime rightBigTime(&rightDisplay);

Clock leftClock(&leftBigTime);
Clock rightClock(&rightBigTime);


void setup()
{
	leftDisplay.begin(20,4);
	leftDisplay.clear();
	rightDisplay.begin(20,4);
	rightDisplay.clear();

	leftClock.hours = 1;
	leftClock.minutes = 15;
	leftClock.seconds = 0;
	leftClock.saveTime();
	leftClock.start();

	rightClock.hours = 0;
	rightClock.minutes = 30;
	rightClock.seconds = 0;
	rightClock.saveTime();
	rightClock.start();
}


void clockTest()
{
	byte testTime = 99;
	while (true) {
		leftBigTime.printTime(testTime, testTime, testTime);
		rightBigTime.printTime(testTime, testTime, testTime);
		testTime--;
		delay(1000);
	}
}


unsigned long loopCounter = 0;

void loop()
{
	leftClock.tick();
	rightClock.tick();

	if (millis() >= 5000) {
		leftDisplay.setCursor(0,3);
		leftDisplay.print(loopCounter / 5);
		leftDisplay.print(" loops/sec");
	} else {
		loopCounter++;
	}
}
