/*
 * Game.h - Class to represent a game.
 */

#ifndef Game_h
#define Game_h

#include <Arduino.h>
#include "Time.h"
#include "Player.h"

class Game
{
	public:
		bool load(byte slot);
		bool save(byte slot);
		void tick();
		Player left;
		Player right;
		bool running;
};

#endif
