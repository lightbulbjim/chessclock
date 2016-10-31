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
		bool detectPress(unsigned long time);
		byte pin;
		volatile bool pressed;
		unsigned long startTime;
};

#endif
