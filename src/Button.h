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
		bool currentlyPressed();
		bool shortPressed();
		bool longPressed();
		unsigned long pressedTime();
	private:
		byte pin;
		volatile bool pressTriggered;
		unsigned long startTime;
};

#endif
