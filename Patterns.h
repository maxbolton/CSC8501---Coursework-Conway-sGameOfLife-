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
		const char* name;
		const bool* pattern;

	public:
		Patterns(int x, int y, const char* name, const bool* pattern);
		~Patterns();
		int getX();
		int getY();
		const char* getName();
		const bool* getPattern();

		void setX(int x);	
		void setY(int y);
		void setName(const char* name);
		void setPattern(const bool* pattern);
};


#endif



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


