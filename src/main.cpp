/*
 * Chess Clock.
 */

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "global.h"
#include "BigTime.h"
#include "Button.h"
#include "Clock.h"
#include "Game.h"
#include "factoryDefaults.h"

// Pin definitions.
const byte LEFT_LCD_ENABLE = 7;
const byte RIGHT_LCD_ENABLE = 8;
const byte COMMON_LCD_RS = 6;
const byte COMMON_LCD_D4 = 10;
const byte COMMON_LCD_D5 = 16;
const byte COMMON_LCD_D6 = 14;
const byte COMMON_LCD_D7 = 15;
const byte ROCKER_LEFT = 0;
const byte ROCKER_RIGHT = 1;
Button decButton(2);
Button pauseButton(3);
Button incButton(4);

enum SystemMode {
	PLAY,
	EDIT,
	PRESETS
} mode;

// Number of memory slots.
const byte SLOTS = 40;

LiquidCrystal leftDisplay(COMMON_LCD_RS, LEFT_LCD_ENABLE, COMMON_LCD_D4,
		COMMON_LCD_D5, COMMON_LCD_D6, COMMON_LCD_D7);
LiquidCrystal rightDisplay(COMMON_LCD_RS, RIGHT_LCD_ENABLE, COMMON_LCD_D4,
		COMMON_LCD_D5, COMMON_LCD_D6, COMMON_LCD_D7);

BigTime leftBigTime(&leftDisplay);
BigTime rightBigTime(&rightDisplay);

Clock leftClock(&leftBigTime);
Clock rightClock(&rightBigTime);

Game game;


void decButtonHandler()
{
	decButton.press();
}


void pauseButtonHandler()
{
	pauseButton.press();
}


void incButtonHandler()
{
	incButton.press();
}


void setup()
{
	leftDisplay.begin(20,4);
	leftDisplay.clear();
	rightDisplay.begin(20,4);
	rightDisplay.clear();

	game.left.clock = &leftClock;
	game.right.clock = &rightClock;

	game.left.lcd = &leftDisplay;
	game.right.lcd = &rightDisplay;

	pinMode(ROCKER_LEFT, INPUT_PULLUP);
	pinMode(ROCKER_RIGHT, INPUT_PULLUP);

	decButton.setIsr(decButtonHandler);
	pauseButton.setIsr(pauseButtonHandler);
	incButton.setIsr(incButtonHandler);

	resetToFactory();
	game.load(1);
	mode = PLAY;
}


void loop()
{
	if (game.activePlayer == &game.left && digitalRead(ROCKER_LEFT) == LOW) {
		if (game.isRunning()) {
			game.endTurn(&game.left);
		} else {
			game.activePlayer = &game.right;
		}
	}

	if (game.activePlayer == &game.right && digitalRead(ROCKER_RIGHT) == LOW) {
		if (game.isRunning()) {
			game.endTurn(&game.right);
		} else {
			game.activePlayer = &game.left;
		}
	}

	switch (mode)
	{
		case PLAY:
		{
			if (pauseButton.longPressed()) {
				if (!game.isRunning()) {
					game.reset();
				}
			} else if (pauseButton.shortPressed()) {
				if (game.isRunning()) {
					game.pause();
				} else {
					game.unPause();
				}
			}
			break;
		}
		case EDIT:
		{
			break;
		}
		case PRESETS:
		{
			break;
		}
	}

	game.tick();
}
