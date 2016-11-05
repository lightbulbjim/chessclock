/*
 * Button.cpp - Class to represent a button.
 */

#include "Button.h"


Button::Button(byte pin)
{
	this->pin = pin;
	this->pressTriggered = false;
	this->startTime = 0;
	pinMode(this->pin, INPUT_PULLUP);
}


void Button::setIsr(void (*isr)())
{
	attachInterrupt(digitalPinToInterrupt(this->pin), isr, FALLING);
}


void Button::press()
{
	this->startTime = millis();
	this->pressTriggered = true;
}


unsigned long Button::pressedTime()
{
	if (this->currentlyPressed()) {
		return millis() - this->startTime;
	}
	return 0;
}


bool Button::currentlyPressed()
{
	return (digitalRead(this->pin) == LOW);
}


bool Button::shortPressed()
{
	if (this->pressTriggered && !this->currentlyPressed()) {
		this->pressTriggered = false;
		return true;
	}
	return false;
}


bool Button::longPressed()
{
	if (this->pressTriggered && this->currentlyPressed()) {
		if (this->pressedTime() >= 3000) {
			this->pressTriggered = false;
			return true;
		}
	}
	return false;
}
