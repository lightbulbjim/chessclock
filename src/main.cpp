/**
 * Chess Clock Hacking.
 */

#include "Arduino.h"
#include "LiquidCrystal.h"
#include <BigNumbers.h>

LiquidCrystal leftDisplay(6, 7, 2, 3, 4, 5);
LiquidCrystal rightDisplay(6, 8, 2, 3, 4, 5);

//BigNumbers left(&leftDisplay);

void setup()
{
	leftDisplay.begin(20,4);
	leftDisplay.clear();
//	left.begin();
	rightDisplay.begin(20,4);
	rightDisplay.clear();
}

void lcdTest()
{
	int i;
	for ( i=1; i<=10; i++ ) {
//		leftDisplay.clear();
//		leftDisplay.print("Testing left ");
//		leftDisplay.print(i);
		
//		left.clearDigit(0);
//		left.printDigit(i, 0);

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
