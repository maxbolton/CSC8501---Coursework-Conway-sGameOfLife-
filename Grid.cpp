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

Grid::Grid(int x, int y, int step, int seed)
{
	this->x_size = x;
	this->y_size = y;
	this->step_count = step;
	this->grid = nullptr;
	this->gridState = false;
	this->seed = seed;
}

Grid::~Grid()
{
	for (int i = 0; i < y_size; ++i) {
		delete[] grid[i];
	}
	delete[] grid;
}
#pragma endregion




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

void Grid::randomlyPopulate(int starterCells)
{
	// Seed the random number generator with the provided seed
	std::mt19937 rng(this->getSeed());
	std::uniform_int_distribution<int> distX(0, x_size - 1);
	std::uniform_int_distribution<int> distY(0, y_size - 1);

	int placed = 0;
	while (placed < starterCells)
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

void Grid::startGame(bool loop) {
	populateGrid();
	randomlyPopulate(getAliveCells());
	system("cls");
	printGrid();


	for (int i = 0; i < step_count; i++)
	{
		// if loop is false, wait for user input to continue
		if (!loop) {
			cout << "Press Enter to continue..." << endl;
			cin.ignore();
			cin.get();
		}// if loop is true, sleep for 500ms and continue without user input
		else {
			this_thread::sleep_for(chrono::milliseconds(1000));
		}
		
		updateGrid();
		system("cls");
		printGrid();
		if (!gridStateCheck()) {
			cout << "All cells are dead. Game over." << endl;
			break;
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

PatternData<int> Grid::patternSearch(Patterns* currentPattern) {

	// Iterate through the grid, allowing the pattern to start anywhere
	// start at -1 & end at +1 to account 1 cell buffer around grid

	// iterate through each pattern

	int height = currentPattern->getX();
	int width = currentPattern->getY();
	bool match = true;



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
				// store the location of where the pattern was found in array

				return { j, i };
			}
		}
	}

	return { -2, -2 };
}

void Grid::randomiseSeed() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 1000000);
	this->setSeed(dis(gen));
}


Patterns* staticSearch(Patterns** patternArray, Grid* newGame, int arraySize) {
	
	int iterations = 0;
	bool found = false;
	int arrayP;

	// game iterations
	while (true) {
		// setup new game
		newGame->randomiseSeed();
		newGame->populateGrid();
		newGame->randomlyPopulate(newGame->getAliveCells());
		iterations++;


		// new games
		for (int i = 0; i < newGame->getStepCount(); i++)
		{
			// iterate through number of patterns in patternArray
			for (int p = 0; p < arraySize; p++){

				PatternData<int> patternPosition = newGame->patternSearch(patternArray[p]);
				// if pattern is found
				if (patternPosition.x != -2 && patternPosition.y != -2)
				{
					// update grid by the number of states in the pattern to ensure the pattern is found
					for (int states = 0; states < patternArray[p]->getStateCount(); states++)
					{
						newGame->updateGrid();
					}

					PatternData<int> newPatternPosition = newGame->patternSearch(patternArray[p]);
					if (newPatternPosition.x == patternPosition.x && newPatternPosition.y == patternPosition.y) {
						newGame->printGrid();
						newGame->setStepCount(i+ patternArray[p]->getStateCount());
						cout << "Pattern '" << patternArray[p]->getName() << "' found after " << iterations << " iterations and " << newGame->getStepCount() << " steps." << endl;
						found = true;
						arrayP = p;
						break;
					}
				}
				// try update grid until found or step count is up.
				newGame->updateGrid();
				
			}

			if (found) {
				break;
			}
		}
		if (found) {
			break;
		}
		
		
	}

	return patternArray[arrayP];
}

void traversalSearch(Spaceships** patternArray, Grid* newGame, int arraySize)
{
	int iterations = 0;
	bool match = false;

	// game iterations
	while (true) {
		// setup new game
		newGame->randomiseSeed();
	    newGame->populateGrid();
		newGame->randomlyPopulate(newGame->getAliveCells());
		iterations++;
		// new game, iterate through stepcount
		for (int i = 0; i < newGame->getStepCount(); i++)
		{

				// iterate through number of patterns in patternArray
			for (int p = 0; p < arraySize; p++) {

				PatternData<int> patternPosition = newGame->patternSearch(patternArray[p]);
				// if initial pattern is found
				if (patternPosition.x != -2 && patternPosition.y != -2)
				{
					Spaceships* currentPattern = patternArray[p];

					//cout << "Pattern '" << currentPattern->getName() << "' found." << endl;

					// update grid and search for next pattern including offset
					match = true;

					for (int states = 0; states < currentPattern->getStateCount(); states++)
					{
						 
						newGame->updateGrid();
						if (newGame->coordinateSearch(currentPattern, patternPosition)) {

							patternPosition.x += currentPattern->getOffset().x;
							patternPosition.y += currentPattern->getOffset().y;
							currentPattern = currentPattern->getNextState();
							system("cls");
							cout << states + 1 << " states of " << currentPattern->getName() << " found." << endl;
						}
						else {
							match = false;
							break;
						}

						match = true;
					}
				}
				if (match) {
					newGame->printGrid();
					newGame->setStepCount(i + patternArray[p]->getStateCount());
					cout << "Pattern '" << patternArray[p]->getName() << "' found after " << iterations << " iterations and " << newGame->getStepCount() << " steps." << endl;
					cout << "Located: " << patternPosition.x << ", " << patternPosition.y << endl;
					return;
				}
			}
		}
	}

}

bool Grid::coordinateSearch(Spaceships* currentPattern, PatternData<int> coordinates) {
	// Iterate through the grid, allowing the pattern to start anywhere
	// start at -1 & end at +1 to account 1 cell buffer around grid

	// iterate through each pattern

	int height = currentPattern->getX();
	int width = currentPattern->getY();
	bool match = true;



	int i = (coordinates.y + currentPattern->getOffset().y);
	int j = (coordinates.x + currentPattern->getOffset().x);


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

			if (iOffset < 0) { match = false; break; }
			if (iOffset > height) { match = false; break; }
			if (jOffset < 0) { match = false; break; }
			if (iOffset > width) { match = false; break; }

			if (grid[iOffset][jOffset].getState() != currentPattern->getNextState()->getPattern()[k * width + l]) {
				match = false;
				break;

			}
			


		}
		if (!match) { break; }
	}
	if (match) {
		return {true};
	}
	return {false};
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

int Grid::getSeed()
{
	return seed;
}

int Grid::getAliveCells()
{
	return aliveCells;
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

void Grid::setSeed(int seed)
{
	this->seed = seed;
}

void Grid::setAliveCells(int aliveCells)
{
	this->aliveCells = aliveCells;
}

#pragma endregion

