/*
 * Game.h - Class to represent a game.
 */

#ifndef Game_h
#define Game_h

#include <Arduino.h>
#include <EEPROM.h>
#include "GamePhase.h"
#include "Player.h"


class Game
{
	public:
		void clear();
		void load(byte slot);
		void save(byte slot);
		void reset();
		void endTurn(Player* player);
		void tick();
		GamePhase firstPhase;
		GamePhase secondPhase;
		GamePhase thirdPhase;
		Player left;
		Player right;
		Player* activePlayer;
		byte slot;
		bool running;
	private:
		int slotToAddress(byte slot);
};

#endif
