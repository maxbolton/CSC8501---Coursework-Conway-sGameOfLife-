// CSC8501 - Coursework(Conway'sGameOfLife).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Grid.h"
#include "Cell.h"
#include "Patterns.h"
#include <thread>
using namespace std;



// instantiate pointers to pattern classes


/*
void allocatePatterns() {


	//Patterns* block = new Patterns(4, 4, blocks, 0, 0);
	//Patterns* beehive = new Patterns(5, 6, beehives, 1, 0);
	//Patterns* loaf = new Patterns(6, 6, loafs, 4, 0);
	//Patterns* boat = new Patterns(5, 5, boats, 4, 0);
	//Patterns* tub = new Patterns(5, 5, tubPattern, 0, 0);

	//Patterns* blinker = new Patterns(5, 3, blinkerPattern, 1, 0);
	//Patterns* toad = new Patterns(6, 6, toadPattern, 1, 0);
	//Patterns* beacon = new Patterns(6, 6, beaconPattern, 1, 0);
	//Patterns* pulsar = new Patterns(15, 15, pulsarPattern, 0);
	//Patterns* pentadecathlon = new Patterns(12, 5, pentadecathlonPattern, 1, 0);

	//Patterns* glider = new Patterns(5, 5, gliderPattern, 4, 1);
	//Patterns* lwss = new Patterns(6, 7, lwssPattern, 4);
	//Patterns* mwss = new Patterns(7, 8, mwssPattern, 4);
	//Patterns* hwss = new Patterns(7, 9, hwssPattern, 4);
	
}
*/


void printPatternArray(const bool** patternArray, int patternCount, int height, int width)
{
	// print each pattern in pattern array
	

	for (int i = 0; i < patternCount; i++)
	{

		// print each row of pattern
		for (int j = 0; j < height; j++)
		{

			// print each cell in row
			for (int k = 0; k < width; k++)
			{
				cout << patternArray[i][j * width + k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

}

int main()
{
    //std::cout << "Hello World!\n";

	const bool* patterns4x4[1] = { &blockPattern[0][0] };

	const bool* patterns5x3[1] = { &blinkerPattern[0][0] };

	const bool* patterns5x5[9] = { &boatPattern[0][0], &boatPattern90[0][0], &boatPattern180[0][0], &boatPattern270[0][0], &tubPattern[0][0], &gliderPattern[0][0], &gliderPattern90[0][0], &gliderPattern180[0][0], &gliderPattern270[0][0] };

	const bool* patterns5x6[1] = { &beehivePattern[0][0] };

	const bool* pattern6x5[1] = { &beehivePattern90[0][0] };

	const bool* patterns6x6[4] = { &loafPattern[0][0], &loafPattern90[0][0], &loafPattern180[0][0], &loafPattern270[0][0] };

	const bool* patterns6x7[1] = { &lwssPattern[0][0] };

	const bool* patterns7x8[1] = { &mwssPattern[0][0] };

	const bool* patterns7x9[1] = { &hwssPattern[0][0] };

	Grid exampleGrid(3,3);


	exampleGrid.populateGrid();
	
	//// set cells (2,2), (2,3), (2,4), (3,4), (4,3)  to true
	//exampleGrid.getGrid()[2][2].SetState(true);
	//exampleGrid.getGrid()[2][3].SetState(true);
	//exampleGrid.getGrid()[2][4].SetState(true);
	//exampleGrid.getGrid()[3][4].SetState(true);
	//exampleGrid.getGrid()[4][3].SetState(true);

	//exampleGrid.startGame(25, 256);
	//exampleGrid.startGame(25, 257);
	//exampleGrid.startGame(25, 258);
	//exampleGrid.startGame(25, 1012494);

	
	exampleGrid.getGrid()[1][1].SetState(true);
	exampleGrid.getGrid()[1][2].SetState(true);
	exampleGrid.getGrid()[2][1].SetState(true);
	exampleGrid.getGrid()[2][2].SetState(true);
	/*
	exampleGrid.getGrid()[4][4].SetState(true);
	exampleGrid.getGrid()[4][5].SetState(true);
	exampleGrid.getGrid()[5][4].SetState(true);
	exampleGrid.getGrid()[5][5].SetState(true);
	


	exampleGrid.getGrid()[1][0].SetState(true);
    exampleGrid.getGrid()[1][1].SetState(true);
	exampleGrid.getGrid()[2][0].SetState(true);
	exampleGrid.getGrid()[2][1].SetState(true);
	*/

	/*cout << "4x4 Patterns" << endl;
	printPatternArray(patterns4x4, 1, 4, 4);

	cout << "6x6 Patterns" << endl;
	printPatternArray(patterns6x6, 4, 6, 6);

	cout << "7x9 Patterns" << endl;
	printPatternArray(patterns7x9, 1, 7, 9);*/

	//exampleGrid.printGrid();
	//exampleGrid.patternSearch(patterns4x4, 1, 4, 4);

	Grid exampleGrid5x5(15, 15);
	exampleGrid5x5.populateGrid();

	// set boat pattern at (2,2)
	exampleGrid5x5.getGrid()[2][2].SetState(true);
	exampleGrid5x5.getGrid()[2][3].SetState(true);	
	exampleGrid5x5.getGrid()[3][2].SetState(true);
	exampleGrid5x5.getGrid()[3][4].SetState(true);
	exampleGrid5x5.getGrid()[4][3].SetState(true);

	//// set boatrotated90 pattern at (5,5)
	//exampleGrid5x5.getGrid()[6][6].SetState(true);
	//exampleGrid5x5.getGrid()[6][7].SetState(true);
	//exampleGrid5x5.getGrid()[5][6].SetState(true);
	//exampleGrid5x5.getGrid()[5][8].SetState(true);
	//exampleGrid5x5.getGrid()[4][7].SetState(true);

	// set blinker pattern at (8,8)
	exampleGrid5x5.getGrid()[8][8].SetState(true);
	exampleGrid5x5.getGrid()[9][8].SetState(true);
	exampleGrid5x5.getGrid()[10][8].SetState(true);


	exampleGrid5x5.printGrid();
	exampleGrid5x5.patternSearch(patterns5x5, 9, 5, 5);
	exampleGrid5x5.patternSearch(patterns5x3, 1, 5, 3);

	return 0;
}







// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
