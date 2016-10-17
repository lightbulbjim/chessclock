/*
 * Game.cpp - Class to represent a game.
 */

#include "Game.h"


byte dummySavedGame[54] =
{
	1,		//  0 - left.firstPhase.enabled (bool)
	1,		//  1 - left.firstPhase.time.hours (byte)
	15,		//  2 - left.firstPhase.time.minutes (byte)
	0,		//  3 - left.firstPhase.time.seconds (byte)
	0,		//  4 - left.firstPhase.delayTime.hours (byte)
	0,		//  5 - left.firstPhase.delayTime.minutes (byte)
	0,		//  6 - left.firstPhase.delayTime.seconds (byte)
	0,		//  7 - left.firstPhase.delayType (enum)
	0,		//  8 - left.firstPhase.moveLimit (byte)
	0,		//  9 - left.secondPhase.enabled (bool)
	0,		// 11 - left.secondPhase.time.hours (byte)
	0,		// 12 - left.secondPhase.time.minutes (byte)
	0,		// 13 - left.secondPhase.time.seconds (byte)
	0,		// 14 - left.secondPhase.delayTime.hours (byte)
	0,		// 15 - left.secondPhase.delayTime.minutes (byte)
	0,		// 16 - left.secondPhase.delayTime.seconds (byte)
	0,		// 17 - left.secondPhase.delayType (enum)
	0,		// 18 - left.secondPhase.moveLimit (byte)
	0,		// 19 - left.thirdPhase.enabled (bool)
	0,		// 20 - left.thirdPhase.time.hours (byte)
	0,		// 21 - left.thirdPhase.time.minutes (byte)
	0,		// 22 - left.thirdPhase.time.seconds (byte)
	0,		// 23 - left.thirdPhase.delayTime.hours (byte)
	0,		// 24 - left.thirdPhase.delayTime.minutes (byte)
	0,		// 25 - left.thirdPhase.delayTime.seconds (byte)
	0,		// 26 - left.thirdPhase.delayType (enum)
	0,		// 27 - left.thirdPhase.moveLimit (byte)
	1,		// 28 - right.firstPhase.enabled (bool)
	1,		// 29 - right.firstPhase.time.hours (byte)
	15,		// 30 - right.firstPhase.time.minutes (byte)
	0,		// 31 - right.firstPhase.time.seconds (byte)
	0,		// 32 - right.firstPhase.delayTime.hours (byte)
	0,		// 33 - right.firstPhase.delayTime.minutes (byte)
	0,		// 34 - right.firstPhase.delayTime.seconds (byte)
	0,		// 35 - right.firstPhase.delayType (enum)
	0,		// 36 - right.firstPhase.moveLimit (byte)
	0,		// 37 - right.secondPhase.enabled (bool)
	0,		// 38 - right.secondPhase.time.hours (byte)
	0,		// 39 - right.secondPhase.time.minutes (byte)
	0,		// 40 - right.secondPhase.time.seconds (byte)
	0,		// 41 - right.secondPhase.delayTime.hours (byte)
	0,		// 42 - right.secondPhase.delayTime.minutes (byte)
	0,		// 43 - right.secondPhase.delayTime.seconds (byte)
	0,		// 44 - right.secondPhase.delayType (enum)
	0,		// 45 - right.secondPhase.moveLimit (byte)
	0,		// 46 - right.thirdPhase.enabled (bool)
	0,		// 47 - right.thirdPhase.time.hours (byte)
	0,		// 48 - right.thirdPhase.time.minutes (byte)
	0,		// 49 - right.thirdPhase.time.seconds (byte)
	0,		// 50 - right.thirdPhase.delayTime.hours (byte)
	0,		// 51 - right.thirdPhase.delayTime.minutes (byte)
	0,		// 52 - right.thirdPhase.delayTime.seconds (byte)
	0,		// 53 - right.thirdPhase.delayType (enum)
	0,		// 54 - right.thirdPhase.moveLimit (byte)
};


bool Game::load(byte slot)
{
	this->left.firstPhase.enabled = true;
	this->left.firstPhase.time.hours = 1;
	this->left.firstPhase.time.minutes = 15;
	this->left.firstPhase.time.seconds = 0;
	this->left.secondPhase.enabled = false;
	this->left.thirdPhase.enabled = false;
	this->left.phase = 1;
	this->left.move = 0;

	this->right.firstPhase.enabled = true;
	this->right.firstPhase.time.hours = 1;
	this->right.firstPhase.time.minutes = 15;
	this->right.firstPhase.time.seconds = 0;
	this->right.secondPhase.enabled = false;
	this->right.thirdPhase.enabled = false;
	this->right.phase = 1;
	this->right.move = 0;

	this->running = false;

	return true;
}


bool Game::save(byte slot)
{
	return true;
}
