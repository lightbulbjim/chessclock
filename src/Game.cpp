/*
 * Game.cpp - Class to represent a game.
 */

#include "Game.h"


int Game::slotToAddress(byte slot)
{
	return int((slot - 1) * 24);
}


void Game::clear()
{
	GamePhase* phases[3] = {
		&this->firstPhase,
		&this->secondPhase,
		&this->thirdPhase
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

	this->reset();
}


void Game::load(byte slot)
{
	int address = slotToAddress(slot);

	GamePhase* phases[3] = {
		&this->firstPhase,
		&this->secondPhase,
		&this->thirdPhase
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

	this->slot = slot;
	this->reset();
}


void Game::save(byte slot)
{
	int address = slotToAddress(slot);

	GamePhase* phases[3] = {
		&this->firstPhase,
		&this->secondPhase,
		&this->thirdPhase
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


void Game::reset()
{
	this->running = false;
	this->turn = LEFT;

	Player* players[2] = {
		&this->left,
		&this->right
	};

	for (int i=0; i<=1; i++) {
		players[i]->clock->stop();
		players[i]->clock->time = this->firstPhase.time;
		players[i]->clock->saveTime();
		players[i]->phase = 1;
		players[i]->move = 0;
		players[i]->flagged = false;
	}
}


void Game::tick()
{
	if (!this->running) {
		return;
	}
}
