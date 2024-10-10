#include <iostream>
#include "Grid.h"
#include "Cell.h"
#include <random>
#include <thread>

using namespace std;


Grid::Grid()
{
	this->x_size = default_size;
	this->y_size = default_size;
	this->step_count = default_step;
	this->grid = nullptr;
}

Grid::Grid(int x, int y)
{
	this->x_size = x;
	this->y_size = y;
	this->step_count = default_step;
	this->grid = nullptr;
}

Grid::Grid(int x, int y, int step)
{
	this->x_size = x;
	this->y_size = y;
	this->step_count = step;
	this->grid = nullptr;
}

Grid::~Grid()
{
	for (int i = 0; i < y_size; ++i) {
		delete[] grid[i];
	}
	delete[] grid;
}


#pragma region Grid Methods
void Grid::populateGrid() {
	// populate grid with cells, each set to false and x and y index set to their position in the grid
	grid = new Cell* [y_size];
	for (int i = 0; i < y_size; i++)
	{
		grid[i] = new Cell[x_size];
		for (int j = 0; j < x_size; j++)
		{
			grid[i][j].setIndex(j, i);
		}
	}
}


void Grid::printGrid()
{
	for (int i = 0; i < y_size; i++)
	{
		for (int j = 0; j < x_size; j++)
		{
			cout << ".";
			if (grid[i][j].getState() == true)
			{
				cout << "x";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "." << endl;
	}
}

void Grid::updateGrid()
{
	// Create a temporary grid to store the new states
	Cell** tempGrid = new Cell * [y_size];
	for (int i = 0; i < y_size; i++)
	{
		tempGrid[i] = new Cell[x_size];
		for (int j = 0; j < x_size; j++)
		{
			tempGrid[i][j] = grid[i][j];
		}
	}

	// Update the temporary grid based on the current grid state
	for (int i = 0; i < y_size; i++)
	{
		for (int j = 0; j < x_size; j++)
		{
			Cell& currentCell = grid[i][j];
			currentCell.SetNeighbours(this);

			if (currentCell.getState() == true && currentCell.getNeighbourCount() == 2)
			{
				tempGrid[i][j].SetState(true);
			}
			else if (currentCell.getNeighbourCount() == 3)
			{
				tempGrid[i][j].SetState(true);
			}
			else
			{
				tempGrid[i][j].SetState(false);
			}
		}
	}

	// Copy the new states back to the original grid
	for (int i = 0; i < y_size; i++)
	{
		for (int j = 0; j < x_size; j++)
		{
			grid[i][j].SetState(tempGrid[i][j].getState());
		}
	}

	// Clean up the temporary grid
	for (int i = 0; i < y_size; i++)
	{
		delete[] tempGrid[i];
	}
	delete[] tempGrid;
}

void Grid::randomlyPopulate(int x, unsigned int seed)
{
	// Seed the random number generator with the provided seed
	std::mt19937 rng(seed);
	std::uniform_int_distribution<int> distX(0, x_size - 1);
	std::uniform_int_distribution<int> distY(0, y_size - 1);

	int placed = 0;
	while (placed < x)
	{
		int randX = distX(rng);
		int randY = distY(rng);

		// Only place a live cell if the position is currently dead
		if (!grid[randY][randX].getState())
		{
			grid[randY][randX].SetState(true);
			placed++;
		}
	}
}


void Grid::startGame(int x, unsigned int seed) {
	populateGrid();
	randomlyPopulate(x, seed);

	for (int i = 0; i < step_count; i++)
	{

		system("cls");
		this->printGrid();
		this->updateGrid();
		this_thread::sleep_for(chrono::milliseconds(500));

	}

}


bool Grid::gridStateCheck() {
	// if all cells are dead, end the game
	for (int i = 0; i < y_size; i++)
	{
		for (int j = 0; j < x_size; j++)
		{
			if (grid[i][j].getState())
			{
				// break out of the loop and do patternSearch
				patternSearch();
				return true;
			}
		}
	}
	return false;

}

void Grid::patternSearch() {
	// search for patterns
}

void Grid::setGrid()
{
	this->grid = grid;
}

Cell** Grid::getGrid()
{
	return grid;
}
#pragma endregion

#pragma region Getters
int Grid::getXSize()
{
	return x_size;
}

int Grid::getYSize()
{
	return y_size;
}

int Grid::getStepCount()
{
	return step_count;
}

#pragma endregion

#pragma region Setters
void Grid::setXSize(int x)
{
	x_size = x;
}

void Grid::setYSize(int y)
{
	y_size = y;
}

void Grid::setStepCount(int step)
{
	step_count = step;
}

#pragma endregion

