/*
 * factoryDefaults.cpp - Factory reset.
 */

#include "factoryDefaults.h"


/*
 * Game field reference:
 *
 *  0 - left.firstPhase.time.hours (byte)
 *  1 - left.firstPhase.time.minutes (byte)
 *  2 - left.firstPhase.time.seconds (byte)
 *  3 - left.firstPhase.delayTime.hours (byte)
 *  4 - left.firstPhase.delayTime.minutes (byte)
 *  5 - left.firstPhase.delayTime.seconds (byte)
 *  6 - left.firstPhase.delayType (enum)
 *  7 - left.firstPhase.moveLimit (byte)
 *  8 - left.secondPhase.time.hours (byte)
 *  9 - left.secondPhase.time.minutes (byte)
 * 10 - left.secondPhase.time.seconds (byte)
 * 11 - left.secondPhase.delayTime.hours (byte)
 * 12 - left.secondPhase.delayTime.minutes (byte)
 * 13 - left.secondPhase.delayTime.seconds (byte)
 * 14 - left.secondPhase.delayType (enum)
 * 15 - left.secondPhase.moveLimit (byte)
 * 16 - left.thirdPhase.time.hours (byte)
 * 17 - left.thirdPhase.time.minutes (byte)
 * 18 - left.thirdPhase.time.seconds (byte)
 * 19 - left.thirdPhase.delayTime.hours (byte)
 * 20 - left.thirdPhase.delayTime.minutes (byte)
 * 21 - left.thirdPhase.delayTime.seconds (byte)
 * 22 - left.thirdPhase.delayType (enum)
 * 23 - left.thirdPhase.moveLimit (byte)
 * 24 - right.firstPhase.time.hours (byte)
 * 25 - right.firstPhase.time.minutes (byte)
 * 26 - right.firstPhase.time.seconds (byte)
 * 27 - right.firstPhase.delayTime.hours (byte)
 * 28 - right.firstPhase.delayTime.minutes (byte)
 * 29 - right.firstPhase.delayTime.seconds (byte)
 * 30 - right.firstPhase.delayType (enum)
 * 31 - right.firstPhase.moveLimit (byte)
 * 32 - right.secondPhase.time.hours (byte)
 * 33 - right.secondPhase.time.minutes (byte)
 * 34 - right.secondPhase.time.seconds (byte)
 * 35 - right.secondPhase.delayTime.hours (byte)
 * 36 - right.secondPhase.delayTime.minutes (byte)
 * 37 - right.secondPhase.delayTime.seconds (byte)
 * 38 - right.secondPhase.delayType (enum)
 * 39 - right.secondPhase.moveLimit (byte)
 * 40 - right.thirdPhase.time.hours (byte)
 * 41 - right.thirdPhase.time.minutes (byte)
 * 42 - right.thirdPhase.time.seconds (byte)
 * 43 - right.thirdPhase.delayTime.hours (byte)
 * 44 - right.thirdPhase.delayTime.minutes (byte)
 * 45 - right.thirdPhase.delayTime.seconds (byte)
 * 46 - right.thirdPhase.delayType (enum)
 * 47 - right.thirdPhase.moveLimit (byte)
 */


void resetToFactory()
{
	byte slot = 1;

	// 5m blitz
	game.clear();
	game.left.firstPhase.time.minutes = 5;
	game.right.firstPhase.time.minutes = 5;
	game.save(slot++);

	// 10m blitz
	game.clear();
	game.left.firstPhase.time.minutes = 10;
	game.right.firstPhase.time.minutes = 10;
	game.save(slot++);

	// 25m rapid
	game.clear();
	game.left.firstPhase.time.minutes = 25;
	game.right.firstPhase.time.minutes = 25;
	game.save(slot++);

	// 1h standard
	game.clear();
	game.left.firstPhase.time.hours = 1;
	game.right.firstPhase.time.hours = 1;
	game.save(slot++);

	// 2h standard
	game.clear();
	game.left.firstPhase.time.hours = 2;
	game.right.firstPhase.time.hours = 2;
	game.save(slot++);

	// 2h + 30m tournament
	game.clear();
	game.left.firstPhase.time.hours = 2;
	game.left.firstPhase.moveLimit = 40;
	game.left.secondPhase.enabled = true;
	game.left.secondPhase.time.minutes = 30;
	game.right.firstPhase.time.hours = 2;
	game.right.firstPhase.moveLimit = 40;
	game.right.secondPhase.enabled = true;
	game.right.secondPhase.time.minutes = 30;
	game.save(slot++);

	// 2h + 1h tournament
	game.clear();
	game.left.firstPhase.time.hours = 2;
	game.left.firstPhase.moveLimit = 40;
	game.left.secondPhase.enabled = true;
	game.left.secondPhase.time.hours = 1;
	game.right.firstPhase.time.hours = 2;
	game.right.firstPhase.moveLimit = 40;
	game.right.secondPhase.enabled = true;
	game.right.secondPhase.time.hours = 1;
	game.save(slot++);

	// 3m/2s Fischer blitz
	game.clear();
	game.left.firstPhase.time.minutes = 3;
	game.left.firstPhase.delayTime.seconds = 2;
	game.left.firstPhase.delayType = FISCHER;
	game.right.firstPhase.time.minutes = 3;
	game.right.firstPhase.delayTime.seconds = 2;
	game.right.firstPhase.delayType = FISCHER;
	game.save(slot++);

	// 25m/10s Fischer rapid
	game.clear();
	game.left.firstPhase.time.minutes = 25;
	game.left.firstPhase.delayTime.seconds = 10;
	game.left.firstPhase.delayType = FISCHER;
	game.right.firstPhase.time.minutes = 25;
	game.right.firstPhase.delayTime.seconds = 10;
	game.right.firstPhase.delayType = FISCHER;
	game.save(slot++);

	// 1h 30m/30s Fischer standard
	game.clear();
	game.left.firstPhase.time.hours = 1;
	game.left.firstPhase.time.minutes = 30;
	game.left.firstPhase.delayTime.seconds = 30;
	game.left.firstPhase.delayType = FISCHER;
	game.right.firstPhase.time.hours = 1;
	game.right.firstPhase.time.minutes = 30;
	game.right.firstPhase.delayTime.seconds = 30;
	game.right.firstPhase.delayType = FISCHER;
	game.save(slot++);

	// 1h 30m/30s + 30m/30s Fischer tournament
	game.clear();
	game.left.firstPhase.time.hours = 1;
	game.left.firstPhase.time.minutes = 30;
	game.left.firstPhase.delayTime.seconds = 30;
	game.left.firstPhase.delayType = FISCHER;
	game.left.firstPhase.moveLimit = 40;
	game.left.secondPhase.enabled = true;
	game.left.secondPhase.time.minutes = 30;
	game.left.secondPhase.delayTime.seconds = 30;
	game.left.secondPhase.delayType = FISCHER;
	game.right.firstPhase.time.hours = 1;
	game.right.firstPhase.time.minutes = 30;
	game.right.firstPhase.delayTime.seconds = 30;
	game.right.firstPhase.delayType = FISCHER;
	game.right.firstPhase.moveLimit = 40;
	game.right.secondPhase.enabled = true;
	game.right.secondPhase.time.minutes = 30;
	game.right.secondPhase.delayTime.seconds = 30;
	game.right.secondPhase.delayType = FISCHER;
	game.save(slot++);

	// 25m/10s Bronstein rapid
	game.clear();
	game.left.firstPhase.time.minutes = 25;
	game.left.firstPhase.delayTime.seconds = 10;
	game.left.firstPhase.delayType = BRONSTEIN;
	game.right.firstPhase.time.minutes = 25;
	game.right.firstPhase.delayTime.seconds = 10;
	game.right.firstPhase.delayType = BRONSTEIN;
	game.save(slot++);

	// 1h 55m/5s Bronstein rapid
	game.clear();
	game.left.firstPhase.time.hours = 1;
	game.left.firstPhase.time.minutes = 55;
	game.left.firstPhase.delayTime.seconds = 5;
	game.left.firstPhase.delayType = BRONSTEIN;
	game.right.firstPhase.time.hours = 1;
	game.right.firstPhase.time.minutes = 55;
	game.right.firstPhase.delayTime.seconds = 5;
	game.right.firstPhase.delayType = BRONSTEIN;
	game.save(slot++);

	// 2h/30s + 15m/30s Bronstein tournament
	game.clear();
	game.left.firstPhase.time.hours = 2;
	game.left.firstPhase.delayTime.seconds = 30;
	game.left.firstPhase.delayType = BRONSTEIN;
	game.left.firstPhase.moveLimit = 40;
	game.left.secondPhase.enabled = true;
	game.left.secondPhase.time.minutes = 15;
	game.left.secondPhase.delayTime.seconds = 30;
	game.left.secondPhase.delayType = BRONSTEIN;
	game.right.firstPhase.time.hours = 2;
	game.right.firstPhase.delayTime.seconds = 30;
	game.right.firstPhase.delayType = BRONSTEIN;
	game.right.firstPhase.moveLimit = 40;
	game.right.secondPhase.enabled = true;
	game.right.secondPhase.time.minutes = 15;
	game.right.secondPhase.delayTime.seconds = 30;
	game.right.secondPhase.delayType = BRONSTEIN;
	game.save(slot++);

}

