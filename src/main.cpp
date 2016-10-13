/*
 * Chess Clock Hacking.
 */

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "BigTime.h"
#include "Clock.h"

// Pin definitions.
const byte LEFT_LCD_ENABLE = 7;
const byte RIGHT_LCD_ENABLE = 8;
const byte COMMON_LCD_RS = 6;
const byte COMMON_LCD_D4 = 10;
const byte COMMON_LCD_D5 = 16;
const byte COMMON_LCD_D6 = 14;
const byte COMMON_LCD_D7 = 15;
const byte LEFT_BUTTON = 0;
const byte RIGHT_BUTTON = 1;
const byte PAUSE_BUTTON = 2;

volatile bool pauseButtonPressed = false;

LiquidCrystal leftDisplay(COMMON_LCD_RS, LEFT_LCD_ENABLE, COMMON_LCD_D4,
		COMMON_LCD_D5, COMMON_LCD_D6, COMMON_LCD_D7);
LiquidCrystal rightDisplay(COMMON_LCD_RS, RIGHT_LCD_ENABLE, COMMON_LCD_D4,
		COMMON_LCD_D5, COMMON_LCD_D6, COMMON_LCD_D7);

BigTime leftBigTime(&leftDisplay);
BigTime rightBigTime(&rightDisplay);

Clock leftClock(&leftBigTime);
Clock rightClock(&rightBigTime);


void pauseButtonISR()
{
	pauseButtonPressed = true;
}


void setup()
{
	pinMode(LEFT_BUTTON, INPUT_PULLUP);
	pinMode(RIGHT_BUTTON, INPUT_PULLUP);
	pinMode(PAUSE_BUTTON, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(PAUSE_BUTTON), pauseButtonISR, LOW);

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

	if (pauseButtonPressed) {
		leftClock.stop();
		rightClock.stop();
		pauseButtonPressed = false;
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
