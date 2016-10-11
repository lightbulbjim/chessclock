/*
 * Clock.cpp - Library for managing the clocks.
 */

#include <Clock.h>


Clock::Clock(BigTime* display)
{
//		: display(display) {
	this->display = display;
}


void Clock::printTestTime()
{
	byte hours = 1;
	byte minutes = 23;
	byte seconds = 45;
	this->display->printTime(hours, minutes, seconds);
}
