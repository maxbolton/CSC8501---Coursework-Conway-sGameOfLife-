#pragma once

// Forward declaration of PatternData template
template <typename T>
struct PatternData;

class Cell;
class Patterns;
class Spaceships;

class Grid {
	private:

		const int default_size = 15;
		const int default_step = 20;
		int x_size;
		int y_size;
		int step_count;
		bool gridState;
		int seed;
		int aliveCells;

		Cell** grid;


	public:

		Grid();
		Grid(int x, int y);
		Grid(int x, int y, int step);
		Grid(int x, int y, int step, int seed);
		~Grid();

		void populateGrid(); 
		void printGrid();
		void updateGrid();
		void randomlyPopulate(int starterCells);
		void startGame(bool loop);
		bool gridStateCheck();
		PatternData<int> patternSearch(Patterns* currentPattern);
		bool coordinateSearch(Spaceships* currentPattern, PatternData<int> coordinates);
		void randomiseSeed();



		int getXSize();
		int getYSize();
		int getStepCount();
		bool getGridState();
		Cell** getGrid();
		int getSeed();
		int getAliveCells();

		void setXSize(int x);
		void setYSize(int y);
		void setStepCount(int step);
		void setGridState(bool state);
		void setGrid();
		void setSeed(int seed);
		void setAliveCells(int aliveCells);
};


void staticSearch(Patterns** patternArray, Grid* newGame, int arraySize);
void traversalSearch(Spaceships** patternArray, Grid* newGame, int arraySize);
