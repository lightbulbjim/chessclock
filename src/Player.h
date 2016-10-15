/*
 * Player.h - Class to represent player options.
 */

#ifndef Player_h
#define Player_h

#include <Arduino.h>
#include "Time.h"

class Player
{
	public:
		Player();
		byte numberOfPhases;
		byte currentPhase;
		Time firstTime;
		Time firstBonusTime;
		Time secondTime;
		Time secondBonusTime;
		Time thirdTime;
		Time thirdBonusTime;
}

#endif
