/*
 * Player.h - Class to represent player options.
 */

#ifndef Player_h
#define Player_h

#include <Arduino.h>
#include "GamePhase.h"
#include "Clock.h"

class Player
{
	public:
		Clock* clock;
		byte phase;
		unsigned int move;
		bool flagged;
};

#endif
