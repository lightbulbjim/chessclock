/*
 * Button.cpp - Class to represent a button.
 */

#include "Button.h"


Button::Button(byte pin)
{
	this->pin = pin;
	this->pressTriggered = false;
	this->startTime = 0;
	this->pressedTime = 0;
	pinMode(this->pin, INPUT_PULLUP);
}


void Button::setIsr(void (*isr)())
{
	attachInterrupt(digitalPinToInterrupt(this->pin), isr, FALLING);
}


void Button::press()
{
	if (this->pressTriggered == false) {
		this->startTime = millis();
		this->pressTriggered = true;
	}
}


unsigned long Button::getPressedTime()
{
	if (this->pressTriggered) {
		this->pressedTime = millis() - this->startTime;
	}
	return this->pressedTime;
}


bool Button::currentlyPressed()
{
	return (digitalRead(this->pin) == LOW);
}


bool Button::shortPressed()
{
	if (this->pressTriggered && !this->currentlyPressed()) {
		if (this->getPressedTime() > 200 && this->getPressedTime() < 3000) {
			this->pressTriggered = false;
			return true;
		}
	}
	return false;
}


bool Button::longPressed()
{
	if (this->pressTriggered && this->currentlyPressed()) {
		if (this->getPressedTime() >= 3000) {
			this->pressTriggered = false;
			return true;
		}
	}
}
