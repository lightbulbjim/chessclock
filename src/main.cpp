/*
 * Chess Clock.
 */

#include <Arduino.h>
#include <LiquidCrystal.h>
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


void printGameData()
{
	game.save(1);
	game.load(1);

	leftDisplay.setCursor(0,0);
	leftDisplay.print(game.left.firstPhase.time.hours);
	leftDisplay.print(":");
	leftDisplay.print(game.left.firstPhase.time.minutes);
	leftDisplay.print(":");
	leftDisplay.print(game.left.firstPhase.time.seconds);
	leftDisplay.print(" ");
	leftDisplay.print(game.left.firstPhase.delayTime.hours);
	leftDisplay.print(":");
	leftDisplay.print(game.left.firstPhase.delayTime.minutes);
	leftDisplay.print(":");
	leftDisplay.print(game.left.firstPhase.delayTime.seconds);
	leftDisplay.print(" ");
	leftDisplay.print(game.left.firstPhase.delayType);
	leftDisplay.print(" ");
	leftDisplay.print(game.left.firstPhase.moveLimit);
	leftDisplay.print(" ");
	leftDisplay.print(game.left.firstPhase.enabled);

	leftDisplay.setCursor(0,1);
	leftDisplay.print(game.left.secondPhase.time.hours);
	leftDisplay.print(":");
	leftDisplay.print(game.left.secondPhase.time.minutes);
	leftDisplay.print(":");
	leftDisplay.print(game.left.secondPhase.time.seconds);
	leftDisplay.print(" ");
	leftDisplay.print(game.left.secondPhase.delayTime.hours);
	leftDisplay.print(":");
	leftDisplay.print(game.left.secondPhase.delayTime.minutes);
	leftDisplay.print(":");
	leftDisplay.print(game.left.secondPhase.delayTime.seconds);
	leftDisplay.print(" ");
	leftDisplay.print(game.left.secondPhase.delayType);
	leftDisplay.print(" ");
	leftDisplay.print(game.left.secondPhase.moveLimit);
	leftDisplay.print(" ");
	leftDisplay.print(game.left.secondPhase.enabled);

	leftDisplay.setCursor(0,2);
	leftDisplay.print(game.left.thirdPhase.time.hours);
	leftDisplay.print(":");
	leftDisplay.print(game.left.thirdPhase.time.minutes);
	leftDisplay.print(":");
	leftDisplay.print(game.left.thirdPhase.time.seconds);
	leftDisplay.print(" ");
	leftDisplay.print(game.left.thirdPhase.delayTime.hours);
	leftDisplay.print(":");
	leftDisplay.print(game.left.thirdPhase.delayTime.minutes);
	leftDisplay.print(":");
	leftDisplay.print(game.left.thirdPhase.delayTime.seconds);
	leftDisplay.print(" ");
	leftDisplay.print(game.left.thirdPhase.delayType);
	leftDisplay.print(" ");
	leftDisplay.print(game.left.thirdPhase.moveLimit);
	leftDisplay.print(" ");
	leftDisplay.print(game.left.thirdPhase.enabled);

	rightDisplay.setCursor(0,0);
	rightDisplay.print(game.right.firstPhase.time.hours);
	rightDisplay.print(":");
	rightDisplay.print(game.right.firstPhase.time.minutes);
	rightDisplay.print(":");
	rightDisplay.print(game.right.firstPhase.time.seconds);
	rightDisplay.print(" ");
	rightDisplay.print(game.right.firstPhase.delayTime.hours);
	rightDisplay.print(":");
	rightDisplay.print(game.right.firstPhase.delayTime.minutes);
	rightDisplay.print(":");
	rightDisplay.print(game.right.firstPhase.delayTime.seconds);
	rightDisplay.print(" ");
	rightDisplay.print(game.right.firstPhase.delayType);
	rightDisplay.print(" ");
	rightDisplay.print(game.right.firstPhase.moveLimit);
	rightDisplay.print(" ");
	rightDisplay.print(game.right.firstPhase.enabled);

	rightDisplay.setCursor(0,1);
	rightDisplay.print(game.right.secondPhase.time.hours);
	rightDisplay.print(":");
	rightDisplay.print(game.right.secondPhase.time.minutes);
	rightDisplay.print(":");
	rightDisplay.print(game.right.secondPhase.time.seconds);
	rightDisplay.print(" ");
	rightDisplay.print(game.right.secondPhase.delayTime.hours);
	rightDisplay.print(":");
	rightDisplay.print(game.right.secondPhase.delayTime.minutes);
	rightDisplay.print(":");
	rightDisplay.print(game.right.secondPhase.delayTime.seconds);
	rightDisplay.print(" ");
	rightDisplay.print(game.right.secondPhase.delayType);
	rightDisplay.print(" ");
	rightDisplay.print(game.right.secondPhase.moveLimit);
	rightDisplay.print(" ");
	rightDisplay.print(game.right.secondPhase.enabled);

	rightDisplay.setCursor(0,2);
	rightDisplay.print(game.right.thirdPhase.time.hours);
	rightDisplay.print(":");
	rightDisplay.print(game.right.thirdPhase.time.minutes);
	rightDisplay.print(":");
	rightDisplay.print(game.right.thirdPhase.time.seconds);
	rightDisplay.print(" ");
	rightDisplay.print(game.right.thirdPhase.delayTime.hours);
	rightDisplay.print(":");
	rightDisplay.print(game.right.thirdPhase.delayTime.minutes);
	rightDisplay.print(":");
	rightDisplay.print(game.right.thirdPhase.delayTime.seconds);
	rightDisplay.print(" ");
	rightDisplay.print(game.right.thirdPhase.delayType);
	rightDisplay.print(" ");
	rightDisplay.print(game.right.thirdPhase.moveLimit);
	rightDisplay.print(" ");
	rightDisplay.print(game.right.thirdPhase.enabled);

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

	game.left.clock = &leftClock;
	game.right.clock = &rightClock;

	setupTestTimes();
}


unsigned long loopCounter = 0;

void loop()
{
	if (leftButtonPressed) {
		game.turn = right;
		leftButtonPressed = false;
	}

	if (rightButtonPressed) {
		game.turn = left;
		rightButtonPressed = false;
	}

	if (pauseButtonPressed) {
		game.running = !game.running;
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
