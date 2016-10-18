/*
 * GamePhase.h - Class to represent a game phase (time control).
 */

#ifndef GamePhase_h
#define GamePhase_h

#include <Arduino.h>
#include "Time.h"


enum Delay {
	NONE,
	FISCHER,
	BRONSTEIN,
	US
};


class GamePhase
{
	public:
		bool enabled;
		Time time;
		Time delayTime;
		Delay delayType;
		byte moveLimit;
};

#endif
