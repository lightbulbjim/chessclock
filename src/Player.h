/*
 * Player.h - Class to represent a player.
 */

#ifndef Player_h
#define Player_h

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "GamePhase.h"
#include "Clock.h"

class Player
{
	public:
		Clock* clock;
		LiquidCrystal* lcd;
		GamePhase* phase;
		unsigned int moves;
		bool flagged;
};

#endif
