/*
 * factoryDefaults.cpp - Factory reset.
 */

#include "factoryDefaults.h"


/*
 * Game field reference:
 *
 *  0 - firstPhase.time.hours (byte)
 *  1 - firstPhase.time.minutes (byte)
 *  2 - firstPhase.time.seconds (byte)
 *  3 - firstPhase.delayTime.hours (byte)
 *  4 - firstPhase.delayTime.minutes (byte)
 *  5 - firstPhase.delayTime.seconds (byte)
 *  6 - firstPhase.delayType (enum)
 *  7 - firstPhase.moveLimit (byte)
 *  8 - secondPhase.time.hours (byte)
 *  9 - secondPhase.time.minutes (byte)
 * 10 - secondPhase.time.seconds (byte)
 * 11 - secondPhase.delayTime.hours (byte)
 * 12 - secondPhase.delayTime.minutes (byte)
 * 13 - secondPhase.delayTime.seconds (byte)
 * 14 - secondPhase.delayType (enum)
 * 15 - secondPhase.moveLimit (byte)
 * 16 - thirdPhase.time.hours (byte)
 * 17 - thirdPhase.time.minutes (byte)
 * 18 - thirdPhase.time.seconds (byte)
 * 19 - thirdPhase.delayTime.hours (byte)
 * 20 - thirdPhase.delayTime.minutes (byte)
 * 21 - thirdPhase.delayTime.seconds (byte)
 * 22 - thirdPhase.delayType (enum)
 * 23 - thirdPhase.moveLimit (byte)
 */


void resetToFactory()
{
	byte slot = 1;

	// 5m blitz
	game.clear();
	game.firstPhase.time.minutes = 5;
	game.save(slot++);

	// 10m blitz
	game.clear();
	game.firstPhase.time.minutes = 10;
	game.save(slot++);

	// 25m rapid
	game.clear();
	game.firstPhase.time.minutes = 25;
	game.save(slot++);

	// 1h standard
	game.clear();
	game.firstPhase.time.hours = 1;
	game.save(slot++);

	// 2h standard
	game.clear();
	game.firstPhase.time.hours = 2;
	game.save(slot++);

	// 2h + 30m tournament
	game.clear();
	game.firstPhase.time.hours = 2;
	game.firstPhase.moveLimit = 40;
	game.secondPhase.enabled = true;
	game.secondPhase.time.minutes = 30;
	game.save(slot++);

	// 2h + 1h tournament
	game.clear();
	game.firstPhase.time.hours = 2;
	game.firstPhase.moveLimit = 40;
	game.secondPhase.enabled = true;
	game.secondPhase.time.hours = 1;
	game.save(slot++);

	// 3m/2s Fischer blitz
	game.clear();
	game.firstPhase.time.minutes = 3;
	game.firstPhase.delayTime.seconds = 2;
	game.firstPhase.delayType = FISCHER;
	game.save(slot++);

	// 25m/10s Fischer rapid
	game.clear();
	game.firstPhase.time.minutes = 25;
	game.firstPhase.delayTime.seconds = 10;
	game.firstPhase.delayType = FISCHER;
	game.save(slot++);

	// 1h 30m/30s Fischer standard
	game.clear();
	game.firstPhase.time.hours = 1;
	game.firstPhase.time.minutes = 30;
	game.firstPhase.delayTime.seconds = 30;
	game.firstPhase.delayType = FISCHER;
	game.save(slot++);

	// 1h 30m/30s + 30m/30s Fischer tournament (FIDE)
	game.clear();
	game.firstPhase.time.hours = 1;
	game.firstPhase.time.minutes = 30;
	game.firstPhase.delayTime.seconds = 30;
	game.firstPhase.delayType = FISCHER;
	game.firstPhase.moveLimit = 40;
	game.secondPhase.enabled = true;
	game.secondPhase.time.minutes = 30;
	game.secondPhase.delayTime.seconds = 30;
	game.secondPhase.delayType = FISCHER;
	game.save(slot++);

	// 25m/10s Bronstein rapid
	game.clear();
	game.firstPhase.time.minutes = 25;
	game.firstPhase.delayTime.seconds = 10;
	game.firstPhase.delayType = BRONSTEIN;
	game.save(slot++);

	// 1h 55m/5s Bronstein standard
	game.clear();
	game.firstPhase.time.hours = 1;
	game.firstPhase.time.minutes = 55;
	game.firstPhase.delayTime.seconds = 5;
	game.firstPhase.delayType = BRONSTEIN;
	game.save(slot++);

	// 2h/30s + 15m/30s Bronstein tournament
	game.clear();
	game.firstPhase.time.hours = 2;
	game.firstPhase.delayTime.seconds = 30;
	game.firstPhase.delayType = BRONSTEIN;
	game.firstPhase.moveLimit = 40;
	game.secondPhase.enabled = true;
	game.secondPhase.time.minutes = 15;
	game.secondPhase.delayTime.seconds = 30;
	game.secondPhase.delayType = BRONSTEIN;
	game.save(slot++);

	game.clear();
	while (slot <= SLOTS) {
		game.save(slot++);
	}
}

