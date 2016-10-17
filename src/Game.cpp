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


void Game::load(byte slot)
{
	int address = slotToAddress(slot);

	GamePhase* phases[6] = {
		&left.firstPhase,
		&left.secondPhase,
		&left.thirdPhase,
		&right.firstPhase,
		&right.secondPhase,
		&right.thirdPhase
	};


	this->left.firstPhase.time.hours          = EEPROM.read(address);
	this->left.firstPhase.time.minutes        = EEPROM.read(address + 1);
	this->left.firstPhase.time.seconds        = EEPROM.read(address + 2);
	this->left.firstPhase.delayTime.hours     = EEPROM.read(address + 3);
	this->left.firstPhase.delayTime.minutes   = EEPROM.read(address + 4);
	this->left.firstPhase.delayTime.seconds   = EEPROM.read(address + 5);
	this->left.firstPhase.delayType = (GamePhase::delay) EEPROM.read(address + 6);
	this->left.firstPhase.moveLimit           = EEPROM.read(address + 7);
	this->left.secondPhase.time.hours         = EEPROM.read(address + 8);
	this->left.secondPhase.time.minutes       = EEPROM.read(address + 9);
	this->left.secondPhase.time.seconds       = EEPROM.read(address + 10);
	this->left.secondPhase.delayTime.hours    = EEPROM.read(address + 11);
	this->left.secondPhase.delayTime.minutes  = EEPROM.read(address + 12);
	this->left.secondPhase.delayTime.seconds  = EEPROM.read(address + 13);
	this->left.secondPhase.delayType = (GamePhase::delay) EEPROM.read(address + 14);
	this->left.secondPhase.moveLimit          = EEPROM.read(address + 15);
	this->left.thirdPhase.time.hours          = EEPROM.read(address + 16);
	this->left.thirdPhase.time.minutes        = EEPROM.read(address + 17);
	this->left.thirdPhase.time.seconds        = EEPROM.read(address + 18);
	this->left.thirdPhase.delayTime.hours     = EEPROM.read(address + 19);
	this->left.thirdPhase.delayTime.minutes   = EEPROM.read(address + 20);
	this->left.thirdPhase.delayTime.seconds   = EEPROM.read(address + 21);
	this->left.thirdPhase.delayType = (GamePhase::delay) EEPROM.read(address + 22);
	this->left.thirdPhase.moveLimit           = EEPROM.read(address + 23);
	this->right.firstPhase.time.hours         = EEPROM.read(address + 24);
	this->right.firstPhase.time.minutes       = EEPROM.read(address + 25);
	this->right.firstPhase.time.seconds       = EEPROM.read(address + 26);
	this->right.firstPhase.delayTime.hours    = EEPROM.read(address + 27);
	this->right.firstPhase.delayTime.minutes  = EEPROM.read(address + 28);
	this->right.firstPhase.delayTime.seconds  = EEPROM.read(address + 29);
	this->right.firstPhase.delayType = (GamePhase::delay) EEPROM.read(address + 30);
	this->right.firstPhase.moveLimit          = EEPROM.read(address + 31);
	this->right.secondPhase.time.hours        = EEPROM.read(address + 32);
	this->right.secondPhase.time.minutes      = EEPROM.read(address + 33);
	this->right.secondPhase.time.seconds      = EEPROM.read(address + 34);
	this->right.secondPhase.delayTime.hours   = EEPROM.read(address + 35);
	this->right.secondPhase.delayTime.minutes = EEPROM.read(address + 36);
	this->right.secondPhase.delayTime.seconds = EEPROM.read(address + 37);
	this->right.secondPhase.delayType = (GamePhase::delay) EEPROM.read(address + 38);
	this->right.secondPhase.moveLimit         = EEPROM.read(address + 39);
	this->right.thirdPhase.time.hours         = EEPROM.read(address + 40);
	this->right.thirdPhase.time.minutes       = EEPROM.read(address + 41);
	this->right.thirdPhase.time.seconds       = EEPROM.read(address + 42);
	this->right.thirdPhase.delayTime.hours    = EEPROM.read(address + 43);
	this->right.thirdPhase.delayTime.minutes  = EEPROM.read(address + 44);
	this->right.thirdPhase.delayTime.seconds  = EEPROM.read(address + 45);
	this->right.thirdPhase.delayType = (GamePhase::delay) EEPROM.read(address + 46);
	this->right.thirdPhase.moveLimit          = EEPROM.read(address + 47);


	this->left.firstPhase.enabled = true;
	this->left.secondPhase.enabled = this->left.secondPhase.time.greaterThanZero();
	this->left.thirdPhase.enabled = this->left.thirdPhase.time.greaterThanZero();
	this->left.phase = 1;
	this->left.move = 0;

	this->right.firstPhase.enabled = true;
	this->right.secondPhase.enabled = this->right.secondPhase.time.greaterThanZero();
	this->right.thirdPhase.enabled = this->right.thirdPhase.time.greaterThanZero();
	this->right.secondPhase.enabled = false;
	this->right.thirdPhase.enabled = false;
	this->right.phase = 1;
	this->right.move = 0;

	this->slot = slot;
	this->running = false;
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
