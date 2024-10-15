#include "Patterns.h"

Patterns::Patterns(int x, int y, const char* name, const bool* pattern)
{
	this->x = x;
	this->y = y;
	this->name = name;
	this->pattern = pattern;
}

Patterns::~Patterns()
{
}

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

#pragma endregion

#pragma region Methods


#pragma endregion


