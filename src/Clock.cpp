/*
 * Clock.cpp - Class to represent a countdown clock.
 */

#include "Clock.h"


Clock::Clock(BigTime* display)
{
	this->display = display;
	this->time.hours = 0;
	this->time.minutes = 0;
	this->time.seconds = 0;
	this->targetMilliseconds = 0;
	this->remainingMilliseconds = 0;
	this->running = false;
}


void Clock::saveTime()
{
	this->remainingMilliseconds = this->time.hours * 3600000;
	this->remainingMilliseconds += this->time.minutes * 60000;
	this->remainingMilliseconds += this->time.seconds * 1000;
	this->display->printTime(this->time.hours, this->time.minutes, this->time.seconds);
}


void Clock::start()
{
	unsigned long now = millis();
	this->targetMilliseconds = now + this->remainingMilliseconds;
	this->running = true;
}


void Clock::stop()
{
	this->running = false;
}


void Clock::tick()
{
	if (this->running) {
		unsigned long nowMilliseconds = millis();

		if (nowMilliseconds >= this->targetMilliseconds) {
			this->remainingMilliseconds = 0;
		} else {
			this->remainingMilliseconds = this->targetMilliseconds - nowMilliseconds;
		}
	}

	unsigned long remainder;
	this->time.hours = this->remainingMilliseconds / 3600000;
	remainder = this->remainingMilliseconds % 3600000;
	this->time.minutes = remainder / 60000;
	remainder = remainder % 60000;

	if (this->time.seconds != remainder / 1000) {
		this->time.seconds = remainder / 1000;
		this->display->printTime(this->time.hours, this->time.minutes, this->time.seconds);
	}
}
