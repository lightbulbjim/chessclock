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
		byte currentPhase;
		GamePhase firstPhase;
		GamePhase secondPhase;
		GamePhase thirdPhase;
		unsigned int move;
};

#endif
