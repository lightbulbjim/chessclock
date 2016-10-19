/*
 * Game.cpp - Class to represent a game.
 */

#include "Game.h"


int Game::slotToAddress(byte slot)
{
	return int((slot - 1) * 48);
}


void Game::clear()
{
	GamePhase* phases[3] = {
		&this->firstPhase,
		&this->secondPhase,
		&this->thirdPhase,
	};

	for (int i=0; i<=2; i++) {
		phases[i]->enabled = (i <= 1);
		phases[i]->time.hours = 0;
		phases[i]->time.minutes = 0;
		phases[i]->time.seconds = 0;
		phases[i]->delayTime.hours = 0;
		phases[i]->delayTime.minutes = 0;
		phases[i]->delayTime.seconds = 0;
		phases[i]->delayType = NONE;
		phases[i]->moveLimit = 0;
	}

	this->left.phase = 1;
	this->left.move = 0;
	this->left.flagged = false;

	this->right.phase = 1;
	this->right.move = 0;
	this->right.flagged = false;

	this->turn = LEFT;
	this->running = false;
}


void Game::load(byte slot)
{
	int address = slotToAddress(slot);

	GamePhase* phases[3] = {
		&this->firstPhase,
		&this->secondPhase,
		&this->thirdPhase,
	};

	for (int i=0; i<=2; i++) {
		phases[i]->time.hours          = EEPROM.read(address);
		phases[i]->time.minutes        = EEPROM.read(address + 1);
		phases[i]->time.seconds        = EEPROM.read(address + 2);
		phases[i]->delayTime.hours     = EEPROM.read(address + 3);
		phases[i]->delayTime.minutes   = EEPROM.read(address + 4);
		phases[i]->delayTime.seconds   = EEPROM.read(address + 5);
		phases[i]->delayType   = (Delay) EEPROM.read(address + 6);
		phases[i]->moveLimit           = EEPROM.read(address + 7);

		phases[i]->enabled = phases[i]->time.greaterThanZero();

		address += 8;
	}

	this->left.phase = 1;
	this->left.move = 0;

	this->right.phase = 1;
	this->right.move = 0;

	this->slot = slot;
	this->running = false;
}


void Game::save(byte slot)
{
	int address = slotToAddress(slot);

	GamePhase* phases[3] = {
		&this->firstPhase,
		&this->secondPhase,
		&this->thirdPhase,
	};

	for (int i=0; i<=2; i++) {
		EEPROM.update(address, phases[i]->time.hours);
		EEPROM.update(address + 1, phases[i]->time.minutes);
		EEPROM.update(address + 2, phases[i]->time.seconds);
		EEPROM.update(address + 3, phases[i]->delayTime.hours);
		EEPROM.update(address + 4, phases[i]->delayTime.minutes);
		EEPROM.update(address + 5, phases[i]->delayTime.seconds);
		EEPROM.update(address + 6, phases[i]->delayType);
		EEPROM.update(address + 7, phases[i]->moveLimit);

		address += 8;
	}
}


void Game::tick()
{
	if (!this->running) {
		return;
	}
}
