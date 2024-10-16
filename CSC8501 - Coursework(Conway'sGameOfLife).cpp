// CSC8501 - Coursework(Conway'sGameOfLife).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Grid.h"
#include "Cell.h"
#include "Patterns.h"
#include <thread>
#include <random>
using namespace std;


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

	// instantiate patternObjects
	Patterns block = Patterns(4, 4, "block", &blockPattern[0][0], 1);
	Patterns beehive = Patterns(5, 6, "beehive", &beehivePattern[0][0], 1);
	Patterns beehive90 = Patterns(6, 5, "beehive90", &beehivePattern90[0][0], 1);

	Patterns* stillLifes[3];
	stillLifes[0] = &block;
	stillLifes[1] = &beehive;
	stillLifes[2] = &beehive90;

	Patterns* blinker = new Patterns(5, 3, "blinker", &blinkerPattern[0][0], 2);
	Patterns* blinker90 = new Patterns(3, 5, "blinker90", &blinkerPattern90[0][0], 2);
	Patterns* toad = new Patterns(6, 6, "toad", &toadPattern[0][0], 2);
	Patterns* toad90 = new Patterns(6, 6, "toad90", &toadPattern90[0][0], 2);

	Patterns* oscillators[4];
	oscillators[0] = blinker;
	oscillators[1] = blinker90;
	oscillators[2] = toad;
	oscillators[3] = toad90;

	Spaceships* gliderSE1 = new Spaceships(5, 5, "gliderSE", &gliderPatternSE1[0][0], 4, PatternData<int>{ 0, 0 });
	Spaceships* gliderSE2 = new Spaceships(5, 5, "glider90", &gliderPatternSE2[0][0], 4, PatternData<int>{ 0, 1 });
	Spaceships* gliderSE3 = new Spaceships(5, 5, "glider180", &gliderPatternSE3[0][0], 4, PatternData<int>{ 0, 0 });
	Spaceships* gliderSE4 = new Spaceships(5, 5, "glider270", &gliderPatternSE4[0][0], 4, PatternData<int>{ 1, 0 });

	gliderSE1->setNextState(gliderSE2);
	gliderSE2->setNextState(gliderSE3);
	gliderSE3->setNextState(gliderSE4);
	gliderSE4->setNextState(gliderSE1);

	Spaceships* glidersSE[4];
	glidersSE[0] = gliderSE1;
	glidersSE[1] = gliderSE2;
	glidersSE[2] = gliderSE3;
	glidersSE[3] = gliderSE4;

	//Grid newGame(25, 25, 25);
	//newGame.startGame(75, 18374234);

	/*
	Grid exampleGrid(10, 10);
	exampleGrid.populateGrid();


	// block pattern
	exampleGrid.getGrid()[1][1].SetState(true);
	exampleGrid.getGrid()[1][2].SetState(true);
	exampleGrid.getGrid()[2][1].SetState(true);
	exampleGrid.getGrid()[2][2].SetState(true);

	// beehive pattern
	exampleGrid.getGrid()[4][2].SetState(true);
	exampleGrid.getGrid()[4][3].SetState(true);
	exampleGrid.getGrid()[5][1].SetState(true);
	exampleGrid.getGrid()[5][4].SetState(true);
	exampleGrid.getGrid()[6][2].SetState(true);
	exampleGrid.getGrid()[6][3].SetState(true);

	// beehive90 pattern
	exampleGrid.getGrid()[2][6].SetState(true);
	exampleGrid.getGrid()[3][6].SetState(true);
	exampleGrid.getGrid()[1][7].SetState(true);
	exampleGrid.getGrid()[4][7].SetState(true);
	exampleGrid.getGrid()[2][8].SetState(true);
	exampleGrid.getGrid()[3][8].SetState(true);


	exampleGrid.printGrid();
	exampleGrid.patternSearch(stillLifes);
	*/


	// Command Line Interface
	while (true)
	{
		system("cls");
		cout << "##### Conway's Game of Life #####" << endl;
		cout << "Select a question to run:" << endl;
		cout << "1. Demonstration Game" << endl;
		cout << "2. Still Lifes" << endl;
		cout << "3. Oscillators" << endl;
		cout << "4. Spaceships" << endl;
		cout << "5. ERN Experiment" << endl;

		int choice;
		cin >> choice;



		switch (choice)
		{
			case 1:
			{
				//clear screen
				system("cls");
				cout << "##### Conway's Game of Life - Demonstration Game #####" << endl;
				cout << "Input a grid width: ";
				int width;
				cin >> width;
				cout << "Input a grid height: ";
				int height;
				cin >> height;
				cout << "Input a number of steps: ";
				int steps;
				cin >> steps;
				cout << "Input a starting number of alive cells: ";
				int aliveCells;
				cin >> aliveCells;
				cout << "Manaully change state or loop? (0/1): ";
				bool loop;
				cin >> loop;


				Grid newGame(width, height, steps);
				newGame.setAliveCells(aliveCells);
				newGame.randomiseSeed();
				newGame.startGame(loop);

				// wait 1 second, return to main menu
				this_thread::sleep_for(chrono::seconds(1));
				break;
			}
			case 2:
			{
				//clear screen
				system("cls");
				cout << "##### Conway's Game of Life - Still Lifes #####" << endl;

				// x, y, steps
				Grid newGame(20, 20, 20);
				newGame.setAliveCells(60);
				int size = sizeof(stillLifes) / sizeof(stillLifes[0]);
				staticSearch(stillLifes, &newGame, size);

				cout << "Visualise Seed? (yes/no): " << endl;
				string visualise;
				cin >> visualise;
				if (visualise == "yes")
				{	// starter cells, seed, loop
					newGame.startGame(true);
					this_thread::sleep_for(chrono::seconds(2));
				}

				break;
			}
			case 3: {
				//clear screen
				system("cls");
				cout << "##### Conway's Game of Life - Oscillators #####" << endl;

				// x, y, steps
				Grid newGame(20, 20, 20);
				newGame.setAliveCells(60);
				int size = sizeof(oscillators) / sizeof(oscillators[0]);
				staticSearch(oscillators, &newGame, size);

				cout << "Visualise Seed? (yes/no): " << endl;
				string visualise;
				cin >> visualise;
				if (visualise == "yes")
				{	// starter cells, seed, loop
					newGame.startGame(true);
					this_thread::sleep_for(chrono::seconds(2));
				}
				break;

			}
			case 4: {
				//clear screen
				system("cls");
				cout << "##### Conway's Game of Life - Spaceships #####" << endl;

				// x, y, steps
				Grid newGame(20, 20, 20);
				newGame.setAliveCells(60);
				int size = sizeof(glidersSE) / sizeof(glidersSE[0]);

				newGame.populateGrid();
				// glider pattern
				newGame.getGrid()[1][5].SetState(true);
				newGame.getGrid()[2][6].SetState(true);
				newGame.getGrid()[3][6].SetState(true);
				newGame.getGrid()[3][5].SetState(true);
				newGame.getGrid()[3][4].SetState(true);

				traversalSearch(glidersSE, &newGame, size);

				/*
				cout << "Visualise Seed? (yes/no): " << endl;
				string visualise;
				cin >> visualise;
				if (visualise == "yes")
				{	// starter cells, seed, loop
					newGame.startGame(true);
					this_thread::sleep_for(chrono::seconds(2));
				}*/
				break;
			}
		}


	return 0;

	}
}