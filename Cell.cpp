#include  <iostream>
#include "Cell.h"
#include "Grid.h"

using namespace std;

Cell::Cell()
{
	this->xIndex = -1;
	this->yIndex = -1;
	this->state = false;
	this->edgeCell = false;
	for (int i = 0; i < 8; i++) {
		this->neighbours[i] = nullptr;
	}
	this->neighbourCount = 0;

}

Cell::Cell(int x, int y)
{
	this->xIndex = x;
	this->yIndex = y;
	this->state = false;
	this->edgeCell = false;
	for (int i = 0; i < 8; i++) {
		this->neighbours[i] = nullptr;
	}
	this->neighbourCount = 0;
}


#pragma region Getters
int Cell::getXIndex() const
{
	return xIndex;
}

int Cell::getYIndex() const
{
	return yIndex;
}

bool Cell::getState() const
{
	return state;
}

bool Cell::getIsEdgeCell() const
{
	return edgeCell;
}

Cell** Cell::getNeighbours()
{
	return neighbours;
}

int Cell::getNeighbourCount() const
{
	return neighbourCount;
}
#pragma endregion

#pragma region Setters

void Cell::setIndex(int x, int y) {
	xIndex = x;
	yIndex = y;
}

void Cell::SetState(bool status)
{
	state = status;
}

void Cell::SetNeighbours(Grid* grid)
{
	int x = this->getYIndex(); // y = rows
	int y = this->getXIndex(); // x = columns

	int xSize = grid->getXSize();
	int ySize = grid->getYSize();


	neighbours[0] = (x - 1 >= 0 && y + 1 < ySize) ? &grid->getGrid()[x - 1][y + 1] : nullptr; // top right
	neighbours[1] = (y + 1 < ySize) ? &grid->getGrid()[x][y + 1] : nullptr; // right
	neighbours[2] = (x + 1 < xSize && y + 1 < ySize) ? &grid->getGrid()[x + 1][y + 1] : nullptr; // bottom right
	neighbours[3] = (x + 1 < xSize) ? &grid->getGrid()[x + 1][y] : nullptr; // bottom
	neighbours[4] = (x + 1 < xSize && y - 1 >= 0) ? &grid->getGrid()[x + 1][y - 1] : nullptr; // bottom left
	neighbours[5] = (y - 1 >= 0) ? &grid->getGrid()[x][y - 1] : nullptr; // left
	neighbours[6] = (x - 1 >= 0 && y - 1 >= 0) ? &grid->getGrid()[x - 1][y - 1] : nullptr; // top left
	neighbours[7] = (x - 1 >= 0) ? &grid->getGrid()[x - 1][y] : nullptr; // top

	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		if (neighbours[i] != nullptr && neighbours[i]->getState() == true)
		{
			count++;
		}
	}
	neighbourCount = count;
}

#pragma endregion

bool Cell::checkIfEdge(Grid* grid) {

	int xSize = grid->getXSize();
	int ySize = grid->getYSize();

	if (this->xIndex == 0 || xIndex == xSize - 1 || this->yIndex == 0 || yIndex == ySize - 1) {
		return true;
	}
	else {
		return false;
	}
}