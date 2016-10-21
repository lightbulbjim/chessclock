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
		bool isRunning();
		void endTurn(Player* player);
		void pause();
		void unPause();
		void tick();
		GamePhase firstPhase;
		GamePhase secondPhase;
		GamePhase thirdPhase;
		Player left;
		Player right;
		Player* activePlayer;
		byte slot;
	private:
		int slotToAddress(byte slot);
		void printStatus(Player* player);
		bool running;
};

#endif
