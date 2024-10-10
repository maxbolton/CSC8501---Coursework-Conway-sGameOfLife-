// CSC8501 - Coursework(Conway'sGameOfLife).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Grid.h"
#include "Cell.h"
#include <thread>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

	Grid exampleGrid;


	exampleGrid.populateGrid();
	
	//// set cells (2,2), (2,3), (2,4), (3,4), (4,3)  to true
	//exampleGrid.getGrid()[2][2].SetState(true);
	//exampleGrid.getGrid()[2][3].SetState(true);
	//exampleGrid.getGrid()[2][4].SetState(true);
	//exampleGrid.getGrid()[3][4].SetState(true);
	//exampleGrid.getGrid()[4][3].SetState(true);

	exampleGrid.startGame(25, 256);
	exampleGrid.startGame(25, 257);
	exampleGrid.startGame(25, 258);
	exampleGrid.startGame(25, 1012494);


	
	


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
