/**
 * Blink
 *
 * Simple blinky thing.
 */
#include "Arduino.h"
#include "LiquidCrystal.h"

LiquidCrystal leftDisplay(6, 7, 2, 3, 4, 5);
LiquidCrystal rightDisplay(6, 8, 2, 3, 4, 5);

void setup()
{
	leftDisplay.begin(20,4);
	rightDisplay.begin(20,4);
}

void lcdTest()
{
	int i;
	for ( i=1; i<=10; i++ ) {
		leftDisplay.clear();
		leftDisplay.print("Testing left ");
		leftDisplay.print(i);

		rightDisplay.clear();
		rightDisplay.print("Testing right ");
		rightDisplay.print(i);

		delay(1000);
	}
}

void loop()
{
	lcdTest();
}
