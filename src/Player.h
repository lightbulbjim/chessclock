/*
 * Player.h - Class to represent player options.
 */

#ifndef Player_h
#define Player_h

#include <Arduino.h>
#include "GamePhase.h"

class Player
{
	public:
		GamePhase firstPhase;
		GamePhase secondPhase;
		GamePhase thirdPhase;
		byte phase;
		unsigned int move;
};

#endif
