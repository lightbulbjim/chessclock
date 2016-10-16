/*
 * Game.cpp - Class to represent a game.
 */

#include "Game.h"


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
