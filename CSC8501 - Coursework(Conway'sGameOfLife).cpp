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
	Patterns block = Patterns(4, 4, "block", &blockPattern[0][0]);
	Patterns beehive = Patterns(5, 6, "beehive", &beehivePattern[0][0]);
	Patterns beehive90 = Patterns(6, 5, "beehive90", &beehivePattern90[0][0]);

	Patterns* stillLifes[3];
    stillLifes[0] = &block;
    stillLifes[1] = &beehive;
    stillLifes[2] = &beehive90;

	Patterns* blinker = new Patterns(5, 3, "blinker", &blinkerPattern[0][0]);
	Patterns* blinker90 = new Patterns(3, 5, "blinker90", &blinkerPattern90[0][0]);
	Patterns* toad = new Patterns(6, 6, "toad", &toadPattern[0][0]);
	Patterns* toad90 = new Patterns(6, 6, "toad90", &toadPattern90[0][0]);

	Patterns** oscillators[4];
	oscillators[0] = &blinker;
	oscillators[1] = &blinker90;
	oscillators[2] = &toad;
	oscillators[3] = &toad90;

	Patterns* glider = new Patterns(5, 5, "glider", &gliderPattern[0][0]);
	Patterns* glider90 = new Patterns(5, 5, "glider90", &gliderPattern90[0][0]);
	Patterns* glider180 = new Patterns(5, 5, "glider180", &gliderPattern180[0][0]);
	Patterns* glider270 = new Patterns(5, 5, "glider270", &gliderPattern270[0][0]);
	Patterns* lwss = new Patterns(6, 7, "lwss", &lwssPattern[0][0]);

	Patterns** spaceships[5];
	spaceships[0] = &glider;
	spaceships[1] = &glider90;
	spaceships[2] = &glider180;
	spaceships[3] = &glider270;
	spaceships[4] = &lwss;
	

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

		// Generate a random seed
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(1, 1000000);
		int seed = dis(gen);

		Grid newGame(width, height, steps);
		// random seed
		newGame.startGame(aliveCells, seed, loop);
		break;
	}
	case 2:
	{
		//clear screen
		system("cls");
		cout << "##### Conway's Game of Life - Still Lifes #####" << endl;
		cout << "Select a still life pattern to display:" << endl;
		cout << "1. Block" << endl;
		cout << "2. Beehive" << endl;
		cout << "3. Beehive90" << endl;
		int patternChoice;
		cin >> patternChoice;

		switch (patternChoice)
		{
		case 1:
			printPatternArray(&blockPattern[0], 1, 4, 4);
			break;
		case 2:
			printPatternArray(&beehivePattern[0], 1, 5, 6);
			break;
		case 3:
			printPatternArray(&beehivePattern90[0], 1, 6, 5);
			break;
		default:
			cout << "Invalid choice." << endl;
			break;
		}
		break;
	}
	return 0;
	}
}