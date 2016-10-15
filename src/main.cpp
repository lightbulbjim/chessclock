/*
 * Chess Clock.
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

volatile bool leftButtonPressed = false;
volatile bool rightButtonPressed = false;
volatile bool pauseButtonPressed = false;

LiquidCrystal leftDisplay(COMMON_LCD_RS, LEFT_LCD_ENABLE, COMMON_LCD_D4,
		COMMON_LCD_D5, COMMON_LCD_D6, COMMON_LCD_D7);
LiquidCrystal rightDisplay(COMMON_LCD_RS, RIGHT_LCD_ENABLE, COMMON_LCD_D4,
		COMMON_LCD_D5, COMMON_LCD_D6, COMMON_LCD_D7);

BigTime leftBigTime(&leftDisplay);
BigTime rightBigTime(&rightDisplay);

Clock leftClock(&leftBigTime);
Clock rightClock(&rightBigTime);


void leftButtonISR()
{
	leftButtonPressed = true;
}


void rightButtonISR()
{
	rightButtonPressed = true;
}


void pauseButtonISR()
{
	pauseButtonPressed = true;
}


void setup()
{
	pinMode(LEFT_BUTTON, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(LEFT_BUTTON), leftButtonISR, LOW);

	pinMode(RIGHT_BUTTON, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(RIGHT_BUTTON), rightButtonISR, LOW);

	pinMode(PAUSE_BUTTON, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(PAUSE_BUTTON), pauseButtonISR, LOW);

	leftDisplay.begin(20,4);
	leftDisplay.clear();
	rightDisplay.begin(20,4);
	rightDisplay.clear();
}


unsigned long loopCounter = 0;

void loop()
{
	if (leftButtonPressed) {
		leftClock.stop();
		rightClock.start();
		leftButtonPressed = false;
	}

	if (rightButtonPressed) {
		rightClock.stop();
		leftClock.start();
		rightButtonPressed = false;
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
