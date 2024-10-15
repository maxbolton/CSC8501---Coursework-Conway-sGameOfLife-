class Cell;

class Grid {
	private:

		const int default_size = 15;
		const int default_step = 20;
		int x_size;
		int y_size;
		int step_count;
		bool gridState;

		Cell** grid;


	public:

		Grid();
		Grid(int x, int y);
		Grid(int x, int y, int step);
		~Grid();

		void populateGrid(); 
		void printGrid();
		void updateGrid();
		void randomlyPopulate(int x, unsigned int seed);
		void startGame(int x, unsigned int seed);
		bool gridStateCheck();
		void patternSearch(const bool** patternArray, int patternCount, int height, int width);



		int getXSize();
		int getYSize();
		int getStepCount();
		bool getGridState();
		Cell** getGrid();

		void setXSize(int x);
		void setYSize(int y);
		void setStepCount(int step);
		void setGridState(bool state);
		void setGrid();


};
