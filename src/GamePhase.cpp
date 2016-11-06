/*
 * GamePhase.cpp - Class to represent a game phase.
 */

#include "GamePhase.h"


void GamePhase::getDescription(char* buffer)
{
	static const byte length = 10;

	if (this->moveLimit > 0) {
		snprintf(buffer, length + 1, "%d/90 +30", this->moveLimit);
	} else {
	    snprintf(buffer, length + 1, "G/90 +30");
	}
}
