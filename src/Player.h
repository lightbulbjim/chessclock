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
		GamePhase firstPhase;
		GamePhase secondPhase;
		GamePhase thirdPhase;
		byte phase;
		unsigned int move;
};

#endif
