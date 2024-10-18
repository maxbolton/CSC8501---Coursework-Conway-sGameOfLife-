#pragma once
#include <vector>
#include <iostream>

using namespace std;

// Templated struct to store pattern data, x&y coordinates/offsets etc.
template <typename T>
struct PatternData {
	T x;
	T y;
};

class Patterns {
private:
	int x;
	int y;
	const char* name;
	const bool* pattern;
	int stateCount;

public:
	Patterns();
	Patterns(int x, int y, const char* name, const bool* pattern, const int stateCount);
	~Patterns();
	int getX();
	int getY();
	const char* getName();
	const bool* getPattern();
	int getStateCount();

	void setX(int x);
	void setY(int y);
	void setName(const char* name);
	void setPattern(const bool* pattern);
	void setStateCount(int stateCount);
};

// Spaceships class, polymorphically derived from Patterns
class Spaceships : public Patterns {
private:
	PatternData<int> offset;
	Spaceships* nextState;

public:
	Spaceships(int x, int y, const char* name, const bool* pattern, const int stateCount, PatternData<int> offset);
	Spaceships(int x, int y, const char* name, const bool* pattern, const int stateCount, PatternData<int> offset, Spaceships* nextState);
	~Spaceships();
	PatternData<int> getOffset();
	Spaceships* getNextState();

	void setOffset(PatternData<int> offset);
	void setNextState(Spaceships* nextState);

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


#pragma region Gliders
// Glider Spaceship - 1x1 offset
const bool gliderPatternSE1[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0},
	{0, 0, 1, 1, 0},
	{0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0}
};
const bool gliderPatternSE2[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 1, 0},
	{0, 1, 1, 1, 0},
	{0, 0, 0, 0, 0}
};
const bool gliderPatternSE3[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 0, 1, 0},
	{0, 0, 1, 1, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0}
};
const bool gliderPatternSE4[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0},
	{0, 1, 0, 1, 0},
	{0, 0, 1, 1, 0},
	{0, 0, 0, 0, 0}
};

// Glider Spaceship - -1x1 offset
const bool gliderPatternSW1[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0},
	{0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0},
	{0, 0, 0, 0, 0}
};
const bool gliderPatternSW2[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 1, 0, 0, 0},
	{0, 1, 1, 1, 0},
	{0, 0, 0, 0, 0}
};
const bool gliderPatternSW3[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 0, 1, 0},
	{0, 1, 1, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0}
};
const bool gliderPatternSW4[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0},
	{0, 1, 0, 1, 0},
	{0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0}
};
// Glider Spaceship -1x-1
const bool gliderPatternNW1[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 1, 1, 0},
	{0, 1, 1, 0, 0},
	{0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0}
};
const bool gliderPatternNW2[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 1, 1, 0},
	{0, 1, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0}
};
const bool gliderPatternNW3[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 1, 1, 0, 0},
	{0, 1, 0, 1, 0},
	{0, 0, 0, 0, 0}
};
const bool gliderPatternNW4[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 1, 0, 0},
	{0, 1, 0, 1, 0},
	{0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0}
};

// Glider Spaceship 1x-1
const bool gliderPatternNE1[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0},
	{0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0}
};
const bool gliderPatternNE2[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 1, 1, 0},
	{0, 0, 0, 1, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0}
};
const bool gliderPatternNE3[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 1, 1, 0},
	{0, 1, 0, 1, 0},
	{0, 0, 0, 0, 0}
};
const bool gliderPatternNE4[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 1, 1, 0},
	{0, 1, 0, 1, 0},
	{0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0}
};
#pragma endregion

#pragma region LWSSs
// Lightweight Spaceship (at least 1 cell buffer around pattern)
const bool lwssPatternW1[6][7] = {
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0},
	{0, 0, 1, 1, 1, 1, 0},
	{0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0}
};
const bool lwssPatternW2[6][7] = {
	{0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 0, 0},
	{0, 1, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0}
};
const bool lwssPatternW3[6][7] = {
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 1, 1, 0},
	{0, 0, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0}
};
const bool lwssPatternW4[6][7] = {
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 1, 0},
	{0, 1, 1, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0}
};

const bool lwssPatternE1[6][7] = {
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0},
	{0, 1, 1, 0, 1, 1, 0},
	{0, 0, 1, 1, 1, 1, 0},
	{0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0}
};
const bool lwssPatternE2[6][7] = {
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 1, 0},
	{0, 1, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0}
};
const bool lwssPatternE3[6][7] = {
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0},
	{0, 1, 1, 1, 1, 0, 0},
	{0, 1, 1, 0, 1, 1, 0},
	{0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0}
};
const bool lwssPatternE4[6][7] = {
	{0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 1, 0},
	{0, 0, 1, 1, 1, 1, 0},
	{0, 0, 0, 0, 0, 0, 0}
};

const bool lwssPatternN1[7][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0},
	{0, 0, 1, 1, 1, 0},
	{0, 1, 1, 0, 1, 0},
	{0, 1, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0}
};

const bool lwssPatternN2[7][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 0},
	{0, 1, 0, 0, 1, 0},
	{0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 1, 0},
	{0, 1, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0}
};

const bool lwssPatternN3[7][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0},
	{0, 1, 1, 1, 0, 0},
	{0, 1, 0, 1, 1, 0},
	{0, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0}
};

const bool lwssPatternN4[7][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 0, 0},
	{0, 1, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{0, 0, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 0}
};

const bool lwssPatternS1[7][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 1, 0},
	{0, 1, 0, 1, 1, 0},
	{0, 1, 1, 1, 0, 0},
	{0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0}
};
const bool lwssPatternS2[7][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 1, 0},
	{0, 1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{0, 1, 0, 0, 1, 0},
	{0, 1, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0}
};
const bool lwssPatternS3[7][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 0},
	{0, 1, 1, 1, 0, 0},
	{0, 1, 1, 0, 1, 0},
	{0, 0, 1, 1, 1, 0},
	{0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0}
};
const bool lwssPatternS4[7][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 1, 0, 1, 0, 0},
	{0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 1, 0},
	{0, 0, 1, 1, 1, 0},
	{0, 0, 0, 0, 0, 0}
};


#pragma endregion

#pragma endregion
