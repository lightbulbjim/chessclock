/*
 * Game.cpp - Class to represent a game.
 */

#include "Game.h"


byte dummySavedGame[48] =
{
	1,		//  0 - left.firstPhase.time.hours (byte)
	15,		//  1 - left.firstPhase.time.minutes (byte)
	0,		//  2 - left.firstPhase.time.seconds (byte)
	0,		//  3 - left.firstPhase.delayTime.hours (byte)
	0,		//  4 - left.firstPhase.delayTime.minutes (byte)
	0,		//  5 - left.firstPhase.delayTime.seconds (byte)
	0,		//  6 - left.firstPhase.delayType (enum)
	0,		//  7 - left.firstPhase.moveLimit (byte)
	0,		//  8 - left.secondPhase.time.hours (byte)
	0,		//  9 - left.secondPhase.time.minutes (byte)
	0,		// 10 - left.secondPhase.time.seconds (byte)
	0,		// 11 - left.secondPhase.delayTime.hours (byte)
	0,		// 12 - left.secondPhase.delayTime.minutes (byte)
	0,		// 13 - left.secondPhase.delayTime.seconds (byte)
	0,		// 14 - left.secondPhase.delayType (enum)
	0,		// 15 - left.secondPhase.moveLimit (byte)
	0,		// 16 - left.thirdPhase.time.hours (byte)
	0,		// 17 - left.thirdPhase.time.minutes (byte)
	0,		// 18 - left.thirdPhase.time.seconds (byte)
	0,		// 19 - left.thirdPhase.delayTime.hours (byte)
	0,		// 20 - left.thirdPhase.delayTime.minutes (byte)
	0,		// 21 - left.thirdPhase.delayTime.seconds (byte)
	0,		// 22 - left.thirdPhase.delayType (enum)
	0,		// 23 - left.thirdPhase.moveLimit (byte)
	1,		// 24 - right.firstPhase.time.hours (byte)
	15,		// 25 - right.firstPhase.time.minutes (byte)
	0,		// 26 - right.firstPhase.time.seconds (byte)
	0,		// 27 - right.firstPhase.delayTime.hours (byte)
	0,		// 28 - right.firstPhase.delayTime.minutes (byte)
	0,		// 29 - right.firstPhase.delayTime.seconds (byte)
	0,		// 30 - right.firstPhase.delayType (enum)
	0,		// 31 - right.firstPhase.moveLimit (byte)
	0,		// 32 - right.secondPhase.time.hours (byte)
	0,		// 33 - right.secondPhase.time.minutes (byte)
	0,		// 34 - right.secondPhase.time.seconds (byte)
	0,		// 35 - right.secondPhase.delayTime.hours (byte)
	0,		// 36 - right.secondPhase.delayTime.minutes (byte)
	0,		// 37 - right.secondPhase.delayTime.seconds (byte)
	0,		// 38 - right.secondPhase.delayType (enum)
	0,		// 39 - right.secondPhase.moveLimit (byte)
	0,		// 40 - right.thirdPhase.time.hours (byte)
	0,		// 41 - right.thirdPhase.time.minutes (byte)
	0,		// 42 - right.thirdPhase.time.seconds (byte)
	0,		// 43 - right.thirdPhase.delayTime.hours (byte)
	0,		// 44 - right.thirdPhase.delayTime.minutes (byte)
	0,		// 45 - right.thirdPhase.delayTime.seconds (byte)
	0,		// 46 - right.thirdPhase.delayType (enum)
	0,		// 47 - right.thirdPhase.moveLimit (byte)
};


int Game::slotToAddress(byte slot)
{
	return int((slot - 1) * 48);
}


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


void Game::save(byte slot)
{
	int address = slotToAddress(slot);
	int element = 0;

	while (address < slotToAddress(slot + 1))
	{
		EEPROM.update(address, dummySavedGame[element]);
		address++;
		element++;
	}
}
