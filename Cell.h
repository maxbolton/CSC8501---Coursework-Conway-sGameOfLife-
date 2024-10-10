class Grid;

class Cell {
	private:

		int xIndex;
		int yIndex;
		bool state;
		Cell* neighbours[8];
		int neighbourCount;


	public:

		Cell();
		Cell(int x, int y);

		int getXIndex() const;
		int getYIndex() const;
		bool getState() const;
		Cell** getNeighbours();
		int getNeighbourCount() const;


		void setIndex(int x, int y);
		void SetState(bool status);
		void SetNeighbours(Grid* grid);
		void UpdateNeighbours(Grid** grid);


};