#include "Patterns.h"
#include "Grid.h"

#pragma region constructors
Patterns::Patterns()
{
	this->x = 0;
	this->y = 0;
	this->name = "";
	this->pattern = nullptr;
	this->stateCount = 0;
}

Patterns::Patterns(int x, int y, const char* name, const bool* pattern, int stateCount)
{
	this->x = x;
	this->y = y;
	this->name = name;
	this->pattern = pattern;
	this->stateCount = stateCount;
}

Patterns::~Patterns()
{
}

#pragma endregion

#pragma region Getters
int Patterns::getX()
{
	return x;
}

int Patterns::getY()
{
	return y;
}

const char* Patterns::getName()
{
	return name;
}

const bool* Patterns::getPattern()
{
	return pattern;
}

int Patterns::getStateCount()
{
	return stateCount;
}

#pragma endregion

#pragma region Setters
void Patterns::setX(int x)
{
	this->x = x;
}

void Patterns::setY(int y)
{
	this->y = y;
}

void Patterns::setName(const char* name)
{
	this->name = name;
}

void Patterns::setPattern(const bool* pattern)
{
	this->pattern = pattern;
}

void Patterns::setStateCount(int stateCount)
{
	this->stateCount = stateCount;
}

#pragma endregion


#pragma region Spaceship Constructors
// Spaceships constructor
Spaceships::Spaceships(int x, int y, const char* name, const bool* pattern, int stateCount, PatternData<int> offset) : Patterns(x, y, name, pattern, stateCount)
{
	this->offset = offset;
	this->nextState = nullptr;
}
Spaceships::Spaceships(int x, int y, const char* name, const bool* pattern, const int stateCount, PatternData<int> offset, Spaceships* nextState) : Patterns(x, y, name, pattern, stateCount)
{
	this->offset = offset;
	this->nextState = nextState;
}

Spaceships::~Spaceships()
{
}
#pragma endregion

#pragma region Spaceship Getters
PatternData<int> Spaceships::getOffset()
{
	return offset;
}

Spaceships* Spaceships::getNextState()
{
	return nextState;
}

#pragma endregion

#pragma region Spaceship Setters
void Spaceships::setOffset(PatternData<int> offset)
{
	this->offset = offset;
}

void Spaceships::setNextState(Spaceships* nextState)
{
	this->nextState = nextState;
}


#pragma endregion

