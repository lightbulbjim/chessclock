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
	for (int i=0; i<=2; i++) {
		this->phases[i].enabled = (i <= 1);
		this->phases[i].time.hours = 0;
		this->phases[i].time.minutes = 0;
		this->phases[i].time.seconds = 0;
		this->phases[i].delayTime.hours = 0;
		this->phases[i].delayTime.minutes = 0;
		this->phases[i].delayTime.seconds = 0;
		this->phases[i].delayType = NONE;
		this->phases[i].moveLimit = 0;
	}

	this->reset();
}


void Game::load(byte slot)
{
	int address = slotToAddress(slot);

	for (int i=0; i<=2; i++) {
		this->phases[i].time.hours          = EEPROM.read(address);
		this->phases[i].time.minutes        = EEPROM.read(address + 1);
		this->phases[i].time.seconds        = EEPROM.read(address + 2);
		this->phases[i].delayTime.hours     = EEPROM.read(address + 3);
		this->phases[i].delayTime.minutes   = EEPROM.read(address + 4);
		this->phases[i].delayTime.seconds   = EEPROM.read(address + 5);
		this->phases[i].delayType   = (Delay) EEPROM.read(address + 6);
		this->phases[i].moveLimit           = EEPROM.read(address + 7);

		this->phases[i].enabled = !this->phases[i].time.isZero();

		address += 8;
	}

	this->slot = slot;
	this->reset();
}


void Game::save(byte slot)
{
	int address = slotToAddress(slot);

	for (int i=0; i<=2; i++) {
		EEPROM.update(address,     this->phases[i].time.hours);
		EEPROM.update(address + 1, this->phases[i].time.minutes);
		EEPROM.update(address + 2, this->phases[i].time.seconds);
		EEPROM.update(address + 3, this->phases[i].delayTime.hours);
		EEPROM.update(address + 4, this->phases[i].delayTime.minutes);
		EEPROM.update(address + 5, this->phases[i].delayTime.seconds);
		EEPROM.update(address + 6, this->phases[i].delayType);
		EEPROM.update(address + 7, this->phases[i].moveLimit);

		address += 8;
	}
}


void Game::reset()
{
	this->running = false;
	this->activePlayer = &this->left;

	Player* players[2] = {
		&this->left,
		&this->right
	};

	for (int i=0; i<=1; i++) {
		players[i]->clock->stop();
		players[i]->clock->time = this->phases[0].time;
		players[i]->clock->saveTime();
		players[i]->phase = &this->phases[0];
		players[i]->moves = 0;
		players[i]->flagged = false;
	}

	this->pause();
	this->printStatus();
}


bool Game::isRunning()
{
	return this->running;
}


bool Game::isFinished()
{
	return (this->left.flagged || this->right.flagged);
}


void Game::endTurn(Player* player)
{
	if (player != this->activePlayer) {
		return;
	}
	
	this->activePlayer->clock->stop();
	this->activePlayer->moves++;
	this->printStatus();

	if (player == &this->left) {
		this->activePlayer = &this->right;
	} else if (player == &this->right) { 
		this->activePlayer = &this->left;
	}

	this->activePlayer->clock->start();
}


void Game::endPhase(Player* player)
{
	if (player->phase == &this->phases[2]) {
		if (!this->isFinished()) {
			player->flagged = true;
			this->printStatus();
		}
	} else if (!(player->phase + 1)->enabled) {
		if (!this->isFinished()) {
			player->flagged = true;
			this->printStatus();
		}
	} else {
		player->phase++;
		player->clock->time.hours += player->phase->time.hours;
		player->clock->time.minutes += player->phase->time.minutes;
		player->clock->time.seconds += player->phase->time.seconds;
		player->clock->saveTime();
	}
}


void Game::pause()
{
	if (this->running) {
		this->left.clock->stop();
		this->right.clock->stop();
		this->running = false;
		this->printStatus();
	}
}


void Game::unPause()
{
	if (!this->running) {
		this->activePlayer->clock->start();
		this->running = true;
		this->printStatus();
	}
}


void Game::printStatus()
{
	Player* players[2] = {
		&this->left,
		&this->right
	};

	for (int i=0; i<=1; i++) {
		players[i]->lcd->setCursor(0, 3);
		players[i]->lcd->print("                    ");
		players[i]->lcd->setCursor(0, 3);

		if (players[i]->flagged) {
			players[i]->lcd->print("FLAG      ");
		} else if (this->running) {
			char status[] = "          ";
			players[i]->phase->getDescription(status);
			players[i]->lcd->print(status);
		} else {
			players[i]->lcd->print("PAUSED    ");
		}

		players[i]->lcd->setCursor(10, 3);
		players[i]->lcd->print("Moves:    ");
		players[i]->lcd->setCursor(17, 3);
		players[i]->lcd->print(players[i]->moves);
	}
}


void Game::tick()
{
	if (this->isRunning() && this->activePlayer->clock->time.isZero()) {
		this->endPhase(this->activePlayer);
	}

	this->activePlayer->clock->tick();
}
