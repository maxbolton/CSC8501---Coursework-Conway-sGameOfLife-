#pragma once
#ifndef PATTERNS_H
#define PATTERNS_H
#include <vector>
#include <iostream>

using namespace std;

class Patterns {
	private:
		int x;
		int y;
		bool* patterns;
		int rotationCount;
		bool flipped;

	public:
		Patterns(int x, int y, const bool* patterns, int rotationCount, bool flipped);
		~Patterns();
		int getX();
		int getY();
		bool* getPatterns();
		int getRotationCount();
		bool getFlipped();
		void setX(int x);	
		void setY(int y);
		void setPatterns(bool* patterns);
		void setRotationCount(int rotationCount);
		void setFlipped(bool flipped);
		void rotatePattern();
		void flipPattern();
};



#pragma region Still Life Patterns
// all patterns are stored as 2D arrays of bools - incorporating a cell buffer around the pattern to allow for easier checking of neighbours


// Block
const bool blockPattern[4][4] = {
	{0, 0, 0, 0},
	{0, 1, 1, 0},
	{0, 1, 1, 0},
	{0, 0, 0, 0}
};

// Beehive
const bool beehivePattern[5][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 0},
	{0, 1, 0, 0, 1, 0},
	{0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0}
};

// Beehive (Rotated 90)
const bool beehivePattern90[6][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0}
};

// Loaf
const bool loafPattern[6][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 0},
	{0, 1, 0, 0, 1, 0},
	{0, 0, 1, 0, 1, 0},
	{0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0}
};

// Loaf (Rotated 90)
const bool loafPattern90[6][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0},
	{0, 0, 1, 0, 1, 0},
	{0, 1, 0, 0, 1, 0},
	{0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0}
};

// Loaf (Rotated 180)
const bool loafPattern180[6][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0},
	{0, 1, 0, 1, 0, 0},
	{0, 1, 0, 0, 1, 0},
	{0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0}
};

// Loaf (Rotated 270)
const bool loafPattern270[6][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 0},
	{0, 1, 0, 0, 1, 0},
	{0, 1, 0, 1, 0, 0},
	{0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0}
};

// Boat
const bool boatPattern[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 1, 0, 0},
	{0, 1, 0, 1, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0}
};

// Boat (Rotated 90)
const bool boatPattern90[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 1, 1, 0},
	{0, 1, 0, 1, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0}
};

// Boat (Rotated 180)
const bool boatPattern180[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 1, 0, 1, 0},
	{0, 0, 1, 1, 0},
	{0, 0, 0, 0, 0}
};

// Boat (Rotated 270)
const bool boatPattern270[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 1, 0, 1, 0},
	{0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0}
};


// Tub
const bool tubPattern[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 1, 0, 1, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0}
};
#pragma endregion


#pragma region Oscillator Patterns
// Blinker (Vertical)
const bool blinkerPattern[5][3] = {
	{ 0, 0, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 0, 0 }
};

// Blinker (Horizontal)
const bool blinkerPattern90[3][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 1, 1, 0},
	{0, 0, 0, 0, 0}
};


// Toad
const bool toadPattern[6][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0},
	{0, 1, 0, 0, 1, 0},
	{0, 1, 0, 0, 1, 0},
	{0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0}
};

// Toad (Rotated 90)
const bool toadPattern90[6][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0}
};

// Beacon
const bool beaconPattern[6][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 1, 1, 0, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0},
	{0, 0, 0, 1, 1, 0},
	{0, 0, 0, 0, 0, 0}
};

// Beacon (Rotated 90)
const bool beaconPattern90[6][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 0},
	{0, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0},
	{0, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0}
};

// Pulsar
const bool pulsarPattern[15][15] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
	{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

// Pentadecathlon
const bool pentadecathlonPattern[12][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 1, 0, 1, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 1, 0, 1, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0}
};

// Pentadecathlon (Horizontal)
const bool pentadecathlonPattern90[5][12] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0},
	{0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};


#pragma endregion


#pragma region Spaceship Patterns
// Glider Spaceship
const bool gliderPattern[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 1, 0},
	{0, 1, 1, 1, 0},
	{0, 0, 0, 0, 0}
};

// Glider Spaceship (Rotated 90)
const bool gliderPattern90[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0},
	{0, 1, 0, 1, 0},
	{0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0}
};

// Glider Spaceship (Rotated 180)
const bool gliderPattern180[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 1, 1, 0},
	{0, 1, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0}
};

// Glider Spaceship (Rotated 270)
const bool gliderPattern270[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 1, 1, 0},
	{0, 1, 0, 1, 0},
	{0, 0, 0, 1, 1},
	{0, 0, 0, 0, 0}
};

// Lightweight Spaceship (at least 1 cell buffer around pattern)
const bool lwssPattern[6][7] = {
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 1, 0},
	{0, 1, 1, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0}
};

// Middleweight Spaceship
const bool mwssPattern[7][8] = {
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 1, 0},
	{0, 1, 1, 1, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0}
};

// Heavyweight Spaceship
const bool hwssPattern[7][9] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 0, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0}
};

#pragma endregion




#endif
