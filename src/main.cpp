/*
 * Chess Clock Hacking.
 */

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "BigTime.h"
#include "Clock.h"

const byte LEFT_BUTTON = 0;
const byte RIGHT_BUTTON = 1;

LiquidCrystal leftDisplay(6, 7, 10, 16, 14, 15);
LiquidCrystal rightDisplay(6, 8, 10, 16, 14, 15);

BigTime leftBigTime(&leftDisplay);
BigTime rightBigTime(&rightDisplay);

Clock leftClock(&leftBigTime);
Clock rightClock(&rightBigTime);


void setup()
{
	pinMode(LEFT_BUTTON, INPUT_PULLUP);
	pinMode(RIGHT_BUTTON, INPUT_PULLUP);

	leftDisplay.begin(20,4);
	leftDisplay.clear();
	rightDisplay.begin(20,4);
	rightDisplay.clear();

	leftClock.hours = 1;
	leftClock.minutes = 15;
	leftClock.saveTime();

	rightClock.hours = 1;
	rightClock.minutes = 15;
	rightClock.saveTime();
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
	if (digitalRead(LEFT_BUTTON) == LOW) {
		leftClock.stop();
		rightClock.start();
	}

	if (digitalRead(RIGHT_BUTTON) == LOW) {
		rightClock.stop();
		leftClock.start();
	}

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
