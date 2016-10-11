/*
 * Clock.cpp - Library for managing the clocks.
 */

#include <Clock.h>


Clock::Clock(BigTime* display)
{
	this->display = display;
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
	this->targetMilliseconds = 0;
	this->remainingMilliseconds = 0;
	this->running = false;
}


void Clock::saveTime()
{

}


void Clock::tick(unsigned long nowMilliseconds)
{
	if (!this->running) {
		return;
	}

	unsigned long nowMilliseconds = millis();

	if (nowMilliseconds >= this->targetMilliseconds) {
		this->remainingMilliseconds = 0;
	} else {
		this->remainingMilliseconds = this->targetMilliseconds - nowMilliseconds;
	}

	// Update hours/minutes/seconds here...

	if (this->remainingMilliseconds % 1000 == 0) {
		this->display->printTime(this->hours, this->minutes, this->seconds);
	}
}
