/*
 * GamePhase.h - Class to represent a game phase (time control).
 */

#ifndef GamePhase_h
#define GamePhase_h

#include <Arduino.h>
#include "Time.h"

class GamePhase
{
	public:
		bool enabled;
		Time time;
		Time delayTime;
		enum delay {
			fischer,
			bronstein,
			us
		} delayType;
		unsigned int moveLimit;
};

#endif
