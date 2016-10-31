/*
 * Button.cpp - Class to represent a button.
 */

#include "Button.h"


Button::Button(byte pin)
{
	this->pin = pin;
	this->pressed = false;
	pinMode(this->pin, INPUT_PULLUP);
}


void Button::setIsr(void (*isr)())
{
	attachInterrupt(digitalPinToInterrupt(this->pin), isr, FALLING);
}


void Button::press()
{
	this->startTime = millis();
	this->pressed = true;
}


bool Button::detectPress(unsigned long time)
{
	if (this->pressed) {
		return (millis() - this->startTime > time);
	} else {
		return false;
	}
}


bool Button::shortPressed()
{
	return detectPress(100);
}


bool Button::longPressed()
{
	return detectPress(3000);
}
