/*
 * Game.h - Class to represent a game.
 */

#ifndef Game_h
#define Game_h

#include <Arduino.h>
#include "Time.h"

class Game
{
	public:
		Game();
		void load(byte slot);
		void save(byte slot);
		Player left;
		Player right;
};

#endif
