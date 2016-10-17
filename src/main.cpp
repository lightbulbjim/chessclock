/*
 * Chess Clock.
 */

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include "BigTime.h"
#include "Clock.h"
#include "Game.h"

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
const byte DEC_BUTTON = 2;
const byte PAUSE_BUTTON = 3;
const byte INC_BUTTON = 4;

volatile bool leftButtonPressed;
volatile bool rightButtonPressed;
volatile bool pauseButtonPressed;

LiquidCrystal leftDisplay(COMMON_LCD_RS, LEFT_LCD_ENABLE, COMMON_LCD_D4,
		COMMON_LCD_D5, COMMON_LCD_D6, COMMON_LCD_D7);
LiquidCrystal rightDisplay(COMMON_LCD_RS, RIGHT_LCD_ENABLE, COMMON_LCD_D4,
		COMMON_LCD_D5, COMMON_LCD_D6, COMMON_LCD_D7);

BigTime leftBigTime(&leftDisplay);
BigTime rightBigTime(&rightDisplay);

Clock leftClock(&leftBigTime);
Clock rightClock(&rightBigTime);

Game game;


void leftButtonHandler()
{
	leftButtonPressed = true;
}


void rightButtonHandler()
{
	rightButtonPressed = true;
}


void pauseButtonHandler()
{
	pauseButtonPressed = true;
}


void setupTestTimes()
{
	leftClock.time.hours = 1;
	leftClock.time.minutes = 15;
	leftClock.time.seconds = 0;
	leftClock.saveTime();

	rightClock.time.hours = 1;
	rightClock.time.minutes = 15;
	rightClock.time.seconds = 0;
	rightClock.saveTime();
}


void setup()
{
	pinMode(LEFT_BUTTON, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(LEFT_BUTTON), leftButtonHandler, FALLING);
	leftButtonPressed = false;

	pinMode(RIGHT_BUTTON, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(RIGHT_BUTTON), rightButtonHandler, FALLING);
	rightButtonPressed = false;

	pinMode(DEC_BUTTON, INPUT_PULLUP);

	pinMode(PAUSE_BUTTON, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(PAUSE_BUTTON), pauseButtonHandler, LOW);
	pauseButtonPressed = false;

	pinMode(INC_BUTTON, INPUT_PULLUP);

	leftDisplay.begin(20,4);
	leftDisplay.clear();
	rightDisplay.begin(20,4);
	rightDisplay.clear();

	setupTestTimes();

	rightDisplay.setCursor(0,3);
	rightDisplay.print("EEPROM length: ");
	rightDisplay.print(EEPROM.length());
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
