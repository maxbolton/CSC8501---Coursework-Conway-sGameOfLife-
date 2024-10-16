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

	#pragma region instatiate pattern objects
	Patterns block = Patterns(4, 4, "block", &blockPattern[0][0], 1);
	Patterns beehive = Patterns(5, 6, "beehive", &beehivePattern[0][0], 1);
	Patterns beehive90 = Patterns(6, 5, "beehive", &beehivePattern90[0][0], 1);

	Patterns* stillLifes[3];
	stillLifes[0] = &block;
	stillLifes[1] = &beehive;
	stillLifes[2] = &beehive90;

	Patterns* blinker = new Patterns(5, 3, "blinker", &blinkerPattern[0][0], 2);
	Patterns* blinker90 = new Patterns(3, 5, "blinker", &blinkerPattern90[0][0], 2);
	Patterns* toad = new Patterns(6, 6, "toad", &toadPattern[0][0], 2);
	Patterns* toad90 = new Patterns(6, 6, "toad", &toadPattern90[0][0], 2);

	Patterns* oscillators[4];
	oscillators[0] = blinker;
	oscillators[1] = blinker90;
	oscillators[2] = toad;
	oscillators[3] = toad90;

	Spaceships* gliderSE1 = new Spaceships(5, 5, "gliderSE1", &gliderPatternSE1[0][0], 4, PatternData<int>{ 0, 0 });
	Spaceships* gliderSE2 = new Spaceships(5, 5, "gliderSE2", &gliderPatternSE2[0][0], 4, PatternData<int>{ 0, 1 });
	Spaceships* gliderSE3 = new Spaceships(5, 5, "gliderSE3", &gliderPatternSE3[0][0], 4, PatternData<int>{ 0, 0 });
	Spaceships* gliderSE4 = new Spaceships(5, 5, "gliderSE4", &gliderPatternSE4[0][0], 4, PatternData<int>{ 1, 0 });

	gliderSE1->setNextState(gliderSE2);
	gliderSE2->setNextState(gliderSE3);
	gliderSE3->setNextState(gliderSE4);
	gliderSE4->setNextState(gliderSE1);

	Spaceships* gliderNE1 = new Spaceships(5, 5, "gliderNE1", &gliderPatternNE1[0][0], 4, PatternData<int>{ 0, 0 });
	Spaceships* gliderNE2 = new Spaceships(5, 5, "gliderNE2", &gliderPatternNE2[0][0], 4, PatternData<int>{ 0, -1 });
	Spaceships* gliderNE3 = new Spaceships(5, 5, "gliderNE3", &gliderPatternNE3[0][0], 4, PatternData<int>{ 0, 0 });
	Spaceships* gliderNE4 = new Spaceships(5, 5, "gliderNE4", &gliderPatternNE4[0][0], 4, PatternData<int>{ 1, 0 });

	gliderNE1->setNextState(gliderNE2);
	gliderNE2->setNextState(gliderNE3);
	gliderNE3->setNextState(gliderNE4);
	gliderNE4->setNextState(gliderNE1);

	Spaceships* gliderSW1 = new Spaceships(5, 5, "gliderSW1", &gliderPatternSW1[0][0], 4, PatternData<int>{ 0, 0 });
	Spaceships* gliderSW2 = new Spaceships(5, 5, "gliderSW2", &gliderPatternSW2[0][0], 4, PatternData<int>{ 0, 1 });
	Spaceships* gliderSW3 = new Spaceships(5, 5, "gliderSW3", &gliderPatternSW3[0][0], 4, PatternData<int>{ 0, 0 });
	Spaceships* gliderSW4 = new Spaceships(5, 5, "gliderSW4", &gliderPatternSW4[0][0], 4, PatternData<int>{ -1, 0 });

	gliderSW1->setNextState(gliderSW2);
	gliderSW2->setNextState(gliderSW3);
	gliderSW3->setNextState(gliderSW4);
	gliderSW4->setNextState(gliderSW1);

	Spaceships* gliderNW1 = new Spaceships(5, 5, "gliderNW1", &gliderPatternNW1[0][0], 4, PatternData<int>{ 0, 0 });
	Spaceships* gliderNW2 = new Spaceships(5, 5, "gliderNW2", &gliderPatternNW2[0][0], 4, PatternData<int>{ 0, -1 });
	Spaceships* gliderNW3 = new Spaceships(5, 5, "gliderNW3", &gliderPatternNW3[0][0], 4, PatternData<int>{ 0, 0 });
	Spaceships* gliderNW4 = new Spaceships(5, 5, "gliderNW4", &gliderPatternNW4[0][0], 4, PatternData<int>{ -1, 0 });

	gliderNW1->setNextState(gliderNW2);
	gliderNW2->setNextState(gliderNW3);
	gliderNW3->setNextState(gliderNW4);
	gliderNW4->setNextState(gliderNW1);

	Spaceships* gliders[16];
	gliders[0] = gliderSE1;
	gliders[1] = gliderSE2;
	gliders[2] = gliderSE3;
	gliders[3] = gliderSE4;
	gliders[4] = gliderNE1;
	gliders[5] = gliderNE2;
	gliders[6] = gliderNE3;
	gliders[7] = gliderNE4;
	gliders[8] = gliderSW1;
	gliders[9] = gliderSW2;
	gliders[10] = gliderSW3;
	gliders[11] = gliderSW4;
	gliders[12] = gliderNW1;
	gliders[13] = gliderNW2;
	gliders[14] = gliderNW3;
	gliders[15] = gliderNW4;

	#pragma endregion

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

					cout << "Continue for 10 steps? (yes/no):" << endl;
					string cont;
					cin >> cont;
					if (cont == "yes")
					{
						for (int i = 0; i < 10; i++)
						{
							system("cls");
							newGame.updateGrid();
							newGame.printGrid();
							this_thread::sleep_for(chrono::seconds(1));
						}
					}
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

					cout << "Continue for 10 steps? (yes/no):" << endl;
					string cont;
					cin >> cont;
					if (cont == "yes")
					{
						for (int i = 0; i < 10; i++)
						{
							system("cls");
							newGame.updateGrid();
							newGame.printGrid();
							this_thread::sleep_for(chrono::seconds(1));
						}
					}
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
				int size = 16;

				newGame.populateGrid();
				

				traversalSearch(gliders, &newGame, size);

				
				cout << "Visualise Seed? (yes/no): " << endl;
				string visualise;
				cin >> visualise;
				if (visualise == "yes")
				{
					newGame.startGame(true);

					cout << "Continue for 10 steps? (yes/no):" << endl;
					string cont;
					cin >> cont;
					if (cont == "yes")
					{
						for (int i = 0; i < 10; i++)
						{
							system("cls");
							newGame.updateGrid();
							newGame.printGrid();
							this_thread::sleep_for(chrono::seconds(1));
						}
					}
				}
				break;
			}
		}


	return 0;

	}
}