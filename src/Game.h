/*
 * Game.h - Class to represent a game.
 */

#ifndef Game_h
#define Game_h

#include <Arduino.h>
#include <EEPROM.h>
#include "Time.h"
#include "Player.h"

enum Turn { 
	LEFT,
	RIGHT
};


class Game
{
	public:
		void clear();
		void load(byte slot);
		void save(byte slot);
		void tick();
		Player left;
		Player right;
		Turn turn;
		byte slot;
		bool running;
	private:
		int slotToAddress(byte slot);
};

#endif
