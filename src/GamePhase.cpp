/*
 * GamePhase.cpp - Class to represent a game phase.
 */

#include "GamePhase.h"


void GamePhase::getDescription(char* buffer)
{
	static const byte length = 10;

	if (this->time.hours == 0 && this->time.minutes == 0) {
		if (this->moveLimit > 0) {
			snprintf(buffer, length + 1, "%d/%ds", this->moveLimit, this->time.inSeconds());
		} else {
		    snprintf(buffer, length + 1, "G/%ds", this->time.inSeconds());
		}
	} else {
		if (this->moveLimit > 0) {
			snprintf(buffer, length + 1, "%d/%d", this->moveLimit, this->time.inMinutes());
		} else {
		    snprintf(buffer, length + 1, "G/%d", this->time.inMinutes());
		}
	}
}
