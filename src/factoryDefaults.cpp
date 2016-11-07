/*
 * factoryDefaults.cpp - Factory reset.
 */

#include "factoryDefaults.h"


/*
 * Game field reference:
 *
 *  0 - phases[0].time.hours (byte)
 *  1 - phases[0].time.minutes (byte)
 *  2 - phases[0].time.seconds (byte)
 *  3 - phases[0].delayTime.hours (byte)
 *  4 - phases[0].delayTime.minutes (byte)
 *  5 - phases[0].delayTime.seconds (byte)
 *  6 - phases[0].delayType (enum)
 *  7 - phases[0].moveLimit (byte)
 *  8 - phases[1].time.hours (byte)
 *  9 - phases[1].time.minutes (byte)
 * 10 - phases[1].time.seconds (byte)
 * 11 - phases[1].delayTime.hours (byte)
 * 12 - phases[1].delayTime.minutes (byte)
 * 13 - phases[1].delayTime.seconds (byte)
 * 14 - phases[1].delayType (enum)
 * 15 - phases[1].moveLimit (byte)
 * 16 - phases[2].time.hours (byte)
 * 17 - phases[2].time.minutes (byte)
 * 18 - phases[2].time.seconds (byte)
 * 19 - phases[2].delayTime.hours (byte)
 * 20 - phases[2].delayTime.minutes (byte)
 * 21 - phases[2].delayTime.seconds (byte)
 * 22 - phases[2].delayType (enum)
 * 23 - phases[2].moveLimit (byte)
 */


void resetToFactory()
{
	byte slot = 1;

	// 5m blitz
	game.clear();
	game.phases[0].time.minutes = 5;
	game.save(slot++);

	// 10m blitz
	game.clear();
	game.phases[0].time.minutes = 10;
	game.save(slot++);

	// 25m rapid
	game.clear();
	game.phases[0].time.minutes = 25;
	game.save(slot++);

	// 1h standard
	game.clear();
	game.phases[0].time.hours = 1;
	game.save(slot++);

	// 2h standard
	game.clear();
	game.phases[0].time.hours = 2;
	game.save(slot++);

	// 2h + 30m tournament
	game.clear();
	game.phases[0].time.hours = 2;
	game.phases[0].moveLimit = 40;
	game.phases[1].enabled = true;
	game.phases[1].time.minutes = 30;
	game.save(slot++);

	// 2h + 1h tournament
	game.clear();
	game.phases[0].time.hours = 2;
	game.phases[0].moveLimit = 40;
	game.phases[1].enabled = true;
	game.phases[1].time.hours = 1;
	game.save(slot++);

	// 3m/2s Fischer blitz
	game.clear();
	game.phases[0].time.minutes = 3;
	game.phases[0].delayTime.seconds = 2;
	game.phases[0].delayType = FISCHER;
	game.save(slot++);

	// 25m/10s Fischer rapid
	game.clear();
	game.phases[0].time.minutes = 25;
	game.phases[0].delayTime.seconds = 10;
	game.phases[0].delayType = FISCHER;
	game.save(slot++);

	// 1h 30m/30s Fischer standard
	game.clear();
	game.phases[0].time.hours = 1;
	game.phases[0].time.minutes = 30;
	game.phases[0].delayTime.seconds = 30;
	game.phases[0].delayType = FISCHER;
	game.save(slot++);

	// 1h 30m/30s + 30m/30s Fischer tournament (FIDE)
	game.clear();
	game.phases[0].time.hours = 1;
	game.phases[0].time.minutes = 30;
	game.phases[0].delayTime.seconds = 30;
	game.phases[0].delayType = FISCHER;
	game.phases[0].moveLimit = 40;
	game.phases[1].enabled = true;
	game.phases[1].time.minutes = 30;
	game.phases[1].delayTime.seconds = 30;
	game.phases[1].delayType = FISCHER;
	game.save(slot++);

	// 25m/10s Bronstein rapid
	game.clear();
	game.phases[0].time.minutes = 25;
	game.phases[0].delayTime.seconds = 10;
	game.phases[0].delayType = BRONSTEIN;
	game.save(slot++);

	// 1h 55m/5s Bronstein standard
	game.clear();
	game.phases[0].time.hours = 1;
	game.phases[0].time.minutes = 55;
	game.phases[0].delayTime.seconds = 5;
	game.phases[0].delayType = BRONSTEIN;
	game.save(slot++);

	// 2h/30s + 15m/30s Bronstein tournament
	game.clear();
	game.phases[0].time.hours = 2;
	game.phases[0].delayTime.seconds = 30;
	game.phases[0].delayType = BRONSTEIN;
	game.phases[0].moveLimit = 40;
	game.phases[1].enabled = true;
	game.phases[1].time.minutes = 15;
	game.phases[1].delayTime.seconds = 30;
	game.phases[1].delayType = BRONSTEIN;
	game.save(slot++);

	game.clear();
	while (slot <= SLOTS) {
		game.save(slot++);
	}
}

