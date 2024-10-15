#include <iostream>
#include "Grid.h"
#include "Cell.h"
#include "Patterns.h"
#include <random>
#include <thread>

using namespace std;

#pragma region Constructors
Grid::Grid()
{
	this->x_size = default_size;
	this->y_size = default_size;
	this->step_count = default_step;
	this->grid = nullptr;
	this->gridState = false;
}

Grid::Grid(int x, int y)
{
	this->x_size = x;
	this->y_size = y;
	this->step_count = default_step;
	this->grid = nullptr;
	this->gridState = false;
}

Grid::Grid(int x, int y, int step)
{
	this->x_size = x;
	this->y_size = y;
	this->step_count = step;
	this->grid = nullptr;
	this->gridState = false;
}

Grid::~Grid()
{
	for (int i = 0; i < y_size; ++i) {
		delete[] grid[i];
	}
	delete[] grid;
}
#pragma endregion

const bool* blockPatterns[1] = { &blockPattern[0][0] };

const bool* blinkerPatterns[1] = { &blinkerPattern[0][0] };

const bool* gliderPatterns[4] = { &gliderPattern[0][0], &gliderPattern90[0][0], &gliderPattern180[0][0], &gliderPattern270[0][0] };

const bool* beehivePatterns5x6[1] = { &beehivePattern[0][0] };

const bool* beehivePatterns6x5[1] = { &beehivePattern90[0][0] };

const bool* toadpatterns[2] = { &toadPattern[0][0], &toadPattern90[0][0] };

const bool* lwssPatterns[1] = { &lwssPattern[0][0] };

const bool* mwssPatterns[1] = { &mwssPattern[0][0] };

const bool* hwssPatterns[1] = { &hwssPattern[0][0] };

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
			grid[i][j].checkIfEdge(this);
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
				cout << "0";
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

void Grid::startGame(int x, unsigned int seed, bool loop) {
	populateGrid();
	randomlyPopulate(x, seed);


	for (int i = 0; i < step_count; i++)
	{

		system("cls");
		this->printGrid();
		this->updateGrid();
		if (!gridStateCheck()) {
			cout << "All cells are dead. Game over." << endl;
			break;
		}

		// if loop is false, wait for user input to continue
		if (!loop) {
			cout << "Press Enter to continue..." << endl;
			cin.ignore();
			cin.get();
		}
		// if loop is true, sleep for 500ms and continue without user input
		else {
			this_thread::sleep_for(chrono::milliseconds(500));
		}

		

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
				this->setGridState(true);
				return true;
			}
		}
	}
	this->setGridState(false);
	return false;

}


// template?? input array of patterns to search for or single pattern
void Grid::patternSearch(Patterns** patternArray) {

	// Iterate through the grid, allowing the pattern to start anywhere
	// start at -1 & end at +1 to account 1 cell buffer around grid

	// iterate through each pattern

	for (int p = 0; p < 3; p++)
	{

		// currentPattern points to the current pattern in the array
		Patterns* currentPattern = patternArray[p];
		int height = currentPattern->getX();
		int width = currentPattern->getY();
		bool match = true;

		cout << "Searching for pattern: " << currentPattern->getName() << endl;

		for (int i = -1; i < (y_size + 2) - height; i++) { // rows
			for (int j = -1; j < (x_size + 2) - width; j++) { // columns

				match = true;

				int patternHeight = height;
				int patternWidth = width;

				int heightStart = 0;
				int widthStart = 0;

				// if top row, reduce pattern height by 1 and start at position 1 in the pattern
				if (i < 0) { patternHeight -= 1; heightStart = 1; };
				// if left column, reduce pattern width by 1 and start at position 1 in the pattern
				if (j < 0) { patternWidth -= 1; widthStart = 1; };

				// if bottom row, reduce pattern height by 1
				if (i > (y_size - height)) { patternHeight -= 1; };
				// if right column, reduce pattern width by 1
				if (j > (x_size - width)) { patternWidth -= 1; };


				// Iterate through the pattern, correcting the length of array if cell is an edge.


				for (int k = 0 + heightStart; k < patternHeight + heightStart; k++) {
					for (int l = 0 + widthStart; l < patternWidth + widthStart; l++) {


						// compare grid cell to pattern cell accounting for the buffer
						int iOffset = i + k;
						int jOffset = j + l;


						if (grid[iOffset][jOffset].getState() != currentPattern->getPattern()[k * width + l]) {
							match = false;
							break;

						}
					}
					if (!match) { break; }
				}
				if (match) {
					cout << "Pattern " << currentPattern->getName() << " found at(" << i << ", " << j << ")" << endl;
				}
			}
		}
	}

	return;
}

int* specificSearch(Patterns** patternArray) {
	int width = 50;
	int height = 50;
	int alive = 50;
	int stepCount = 100;
	int iterations = 0;

	//get random seed
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 1000000);



	while (true) {
		int seed = dis(gen);
		Grid newGame(width, height, 100);
		newGame.randomlyPopulate(alive, seed);


		for (int i = 0; i < stepCount; i++)
		{
			newGame.patternSearch(patternArray);
			newGame.updateGrid();

		}
		
	}




	return 0;
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

bool Grid::getGridState()
{
	return gridState;
}

Cell** Grid::getGrid()
{
	return grid;
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

void Grid::setGridState(bool state)
{
	gridState = state;
}

void Grid::setGrid()
{
	this->grid = grid;
}

#pragma endregion

