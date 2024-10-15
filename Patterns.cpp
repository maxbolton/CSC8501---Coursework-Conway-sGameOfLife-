#include "Patterns.h"

Patterns::Patterns(int x, int y, const bool* patterns, int rotationCount, bool flipped)
{
	this->x = x;
	this->y = y;
	this->patterns = nullptr;
	this->rotationCount = rotationCount;
	this->flipped = flipped;
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

bool* Patterns::getPatterns()
{
	return patterns;
}

int Patterns::getRotationCount()
{
	return rotationCount;
}

bool Patterns::getFlipped()
{
	return flipped;
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

void Patterns::setPatterns(bool* patterns)
{
	this->patterns = patterns;
}

void Patterns::setRotationCount(int rotationCount)
{
	this->rotationCount = rotationCount;
}

void Patterns::setFlipped(bool flipped)
{
	this->flipped = flipped;
}
#pragma endregion

#pragma region Methods
void Patterns::rotatePattern()
{
}

void Patterns::flipPattern()
{
}



#pragma endregion


