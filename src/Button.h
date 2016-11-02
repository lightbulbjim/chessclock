/*
 * Button.h - Class to represent a button.
 */

#ifndef Button_h
#define Button_h

#include <Arduino.h>

class Button
{
	public:
		Button(byte pin);
		void setIsr(void (*isr)());
		void press();
		bool shortPressed();
		bool longPressed();
	private:
		bool currentlyPressed();
		unsigned long getPressedTime();
		byte pin;
		volatile bool pressTriggered;
		unsigned long startTime;
		unsigned long pressedTime;
};

#endif
