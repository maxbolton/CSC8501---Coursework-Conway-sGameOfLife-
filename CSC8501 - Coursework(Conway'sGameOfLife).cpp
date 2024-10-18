// CSC8501 - Coursework(Conway'sGameOfLife).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Grid.h"
#include "Cell.h"
#include "Patterns.h"
#include <thread>
#include <random>
#include <fstream> 
#include <sstream> 
#include <string> 


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

	Spaceships* gliders[32];
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
																								// x, y
	Spaceships* lwssW1 = new Spaceships(7, 6, "lwssW", &lwssPatternW1[0][0], 4, PatternData<int>{ 0, 0 });
	Spaceships* lwssW2 = new Spaceships(7, 6, "lwssW", &lwssPatternW2[0][0], 4, PatternData<int>{ -1, -1 }); // left & up
	Spaceships* lwssW3 = new Spaceships(7, 6, "lwssW", &lwssPatternW3[0][0], 4, PatternData<int>{ 0, 0 });
	Spaceships* lwssW4 = new Spaceships(7, 6, "lwssW", &lwssPatternW4[0][0], 4, PatternData<int>{ -1, 1 }); // left & down

	lwssW1->setNextState(lwssW2);
	lwssW2->setNextState(lwssW3);
	lwssW3->setNextState(lwssW4);
	lwssW4->setNextState(lwssW1);

	Spaceships* lwssE1 = new Spaceships(7, 6, "lwssE", &lwssPatternE1[0][0], 4, PatternData<int>{ 0, 0 });
	Spaceships* lwssE2 = new Spaceships(7, 6, "lwssE", &lwssPatternE2[0][0], 4, PatternData<int>{ 1, -1 }); // right & up
	Spaceships* lwssE3 = new Spaceships(7, 6, "lwssE", &lwssPatternE3[0][0], 4, PatternData<int>{ 0, 0 });
	Spaceships* lwssE4 = new Spaceships(7, 6, "lwssE", &lwssPatternE4[0][0], 4, PatternData<int>{ 1, 1 }); // right & down

	lwssE1->setNextState(lwssE2);
	lwssE2->setNextState(lwssE3);
	lwssE3->setNextState(lwssE4);
	lwssE4->setNextState(lwssE1);

	Spaceships* lwssN1 = new Spaceships(7, 6, "lwssN", &lwssPatternN1[0][0], 4, PatternData<int>{ 0, 0 });
	Spaceships* lwssN2 = new Spaceships(7, 6, "lwssN", &lwssPatternN2[0][0], 4, PatternData<int>{ 1, -1 }); // right & up
	Spaceships* lwssN3 = new Spaceships(7, 6, "lwssN", &lwssPatternN3[0][0], 4, PatternData<int>{ 0, 0 });
	Spaceships* lwssN4 = new Spaceships(7, 6, "lwssN", &lwssPatternN4[0][0], 4, PatternData<int>{ -1, -1 }); // left & up
		
	lwssN1->setNextState(lwssN2);
	lwssN2->setNextState(lwssN3);
	lwssN3->setNextState(lwssN4);
	lwssN4->setNextState(lwssN1);

	Spaceships* lwssS1 = new Spaceships(7, 6, "lwssS", &lwssPatternS1[0][0], 4, PatternData<int>{ 0, 0 });
	Spaceships* lwssS2 = new Spaceships(7, 6, "lwssS", &lwssPatternS2[0][0], 4, PatternData<int>{ -1, 1 }); // left & down
	Spaceships* lwssS3 = new Spaceships(7, 6, "lwssS", &lwssPatternS3[0][0], 4, PatternData<int>{ 0, 0 });
	Spaceships* lwssS4 = new Spaceships(7, 6, "lwssS", &lwssPatternS4[0][0], 4, PatternData<int>{ 1, 1 }); // right & down

	lwssS1->setNextState(lwssS2);
	lwssS2->setNextState(lwssS3);
	lwssS3->setNextState(lwssS4);
	lwssS4->setNextState(lwssS1);


	Spaceships* lwsss[16];
	lwsss[0] = lwssW1;
	lwsss[1] = lwssW2;
	lwsss[2] = lwssW3;
	lwsss[3] = lwssW4;
	lwsss[4] = lwssE1;
	lwsss[5] = lwssE2;
	lwsss[6] = lwssE3;
	lwsss[7] = lwssE4;
	lwsss[8] = lwssN1;
	lwsss[9] = lwssN2;
	lwsss[10] = lwssN3;
	lwsss[11] = lwssN4;
	lwsss[12] = lwssS1;
	lwsss[13] = lwssS2;
	lwsss[14] = lwssS3;
	lwsss[15] = lwssS4;

	Spaceships* spaceships[32];
	spaceships[0] = gliderSE1;
	spaceships[1] = gliderSE2;
	spaceships[2] = gliderSE3;
	spaceships[3] = gliderSE4;
	spaceships[4] = gliderNE1;
	spaceships[5] = gliderNE2;
	spaceships[6] = gliderNE3;
	spaceships[7] = gliderNE4;
	spaceships[8] = gliderSW1;
	spaceships[9] = gliderSW2;
	spaceships[10] = gliderSW3;
	spaceships[11] = gliderSW4;
	spaceships[12] = gliderNW1;
	spaceships[13] = gliderNW2;
	spaceships[14] = gliderNW3;
	spaceships[15] = gliderNW4;
	spaceships[16] = lwssW1;
	spaceships[17] = lwssW2;
	spaceships[18] = lwssW3;
	spaceships[19] = lwssW4;
	spaceships[20] = lwssE1;
	spaceships[21] = lwssE2;
	spaceships[22] = lwssE3;
	spaceships[23] = lwssE4;
	spaceships[24] = lwssN1;
	spaceships[25] = lwssN2;
	spaceships[26] = lwssN3;
	spaceships[27] = lwssN4;
	spaceships[28] = lwssS1;
	spaceships[29] = lwssS2;
	spaceships[30] = lwssS3;
	spaceships[31] = lwssS4;



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
				cout << "1) Start New Game" << endl;
				cout << "2) Load Game" << endl;

				int gameChoice;
				cin >> gameChoice;

				if (gameChoice == 1) {
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
				}
				else if (gameChoice == 2) {
					system("cls");
					cout << "##### Conway's Game of Life - Demonstration Game #####" << endl;
					cout << "Which entry would you like to load?" << endl;
					int entry;
					cin >> entry;

					// Open the CSV file in read mode
					std::ifstream file("conways_game_data.csv");
					if (file.is_open()) {
						std::string line;
						int currentLine = 1;
						bool found = false;

						// Loop through the CSV file
						while (std::getline(file, line)) {
							if (currentLine == entry) {
								// We found the desired line, now parse the CSV line
								std::stringstream ss(line);
								std::string seedStr, xStr, yStr, aliveCellsStr, stepsStr;

								// Read each column in the CSV
								std::getline(ss, seedStr, ',');
								std::getline(ss, xStr, ',');
								std::getline(ss, yStr, ',');
								std::getline(ss, aliveCellsStr, ',');
								std::getline(ss, stepsStr, ',');

								// Convert strings to integers
								int seed = std::stoi(seedStr);
								int x = std::stoi(xStr);
								int y = std::stoi(yStr);
								int aliveCells = std::stoi(aliveCellsStr);
								int steps = std::stoi(stepsStr);

								// Output the loaded data to confirm
								cout << "Loaded Grid width: " << x << endl;
								cout << "Loaded Grid height: " << y << endl;
								cout << "Loaded Number of steps: " << steps << endl;
								cout << "Loaded Number of alive cells: " << aliveCells << endl;
								cout << "Loaded Seed: " << seed << endl;

								// Create the game grid with the loaded data
								Grid loadedGame(x, y, steps);
								loadedGame.setAliveCells(aliveCells);
								loadedGame.setSeed(seed);


								loadedGame.startGame(false);
								found = true;
								break;
							}
							currentLine++;
						}
						file.close();

						if (!found) {
							cout << "Entry not found in the file!" << endl;
						}
					}
					else {
						cout << "Unable to open file." << endl;
					}

				}
					// wait 1 second, return to main menu
					this_thread::sleep_for(chrono::seconds(3));

					break;

			}
			case 2:
			{
				//clear screen
				system("cls");
				cout << "##### Conway's Game of Life - Still Lifes #####" << endl;

				// x, y, steps
				Grid newGame(40, 40, 20);
				newGame.setAliveCells(480);
				int size = sizeof(stillLifes) / sizeof(stillLifes[0]);
				Patterns* found = staticSearch(stillLifes, &newGame, size);

				cout << "Visualise Seed? (yes/no): " << endl;
				string visualise;
				cin >> visualise;
				if (visualise == "yes")
				{	// starter cells, seed, loop
					newGame.startGame(true);
				}


				this_thread::sleep_for(chrono::seconds(1));
				system("cls");
				cout << "##### Conway's Game of Life - Still Lifes #####" << endl;
				cout << "1) Save the seed" << endl;
				cout << "2) Continue for 10 steps" << endl;

				int cont;
				cin >> cont;
				if (cont == 1) {

					// Open the CSV file in append mode
					std::ofstream file("conways_game_data.csv", std::ios::app);

					// Write the data to the file in CSV format
					if (file.is_open()) {
						file << newGame.getSeed() << "," << newGame.getXSize() << "," << newGame.getYSize() << "," << newGame.getAliveCells() << "," << newGame.getStepCount() << "," << found->getName() << "\n";
						file.close();
						cout << "Game data saved successfully!" << endl;
					}
					else {
						cout << "Unable to open file." << endl;
					}

				}
				if (cont == 2)
				{
					for (int i = 0; i < 10; i++)
					{
						system("cls");
						newGame.updateGrid();
						newGame.printGrid();
						this_thread::sleep_for(chrono::seconds(1));
					}
				}
				

				break;
			}
			case 3: {
				//clear screen
				system("cls");
				cout << "##### Conway's Game of Life - Oscillators #####" << endl;

				// x, y, steps
				Grid newGame(40, 40, 20);
				newGame.setAliveCells(480);
				int size = sizeof(oscillators) / sizeof(oscillators[0]);
				Patterns* found = staticSearch(oscillators, &newGame, size);

				cout << "Visualise Seed? (yes/no): " << endl;
				string visualise;
				cin >> visualise;
				if (visualise == "yes")
				{	// starter cells, seed, loop
					newGame.startGame(true);


				}

				this_thread::sleep_for(chrono::seconds(1));
				system("cls");
				cout << "##### Conway's Game of Life - Still Lifes #####" << endl;
				cout << "1) Save the seed" << endl;
				cout << "2) Continue for 10 steps" << endl;

				int cont;
				cin >> cont;
				if (cont == 1) {

					// Open the CSV file in append mode
					std::ofstream file("conways_game_data.csv", std::ios::app);

					// Write the data to the file in CSV format
					if (file.is_open()) {
						file << newGame.getSeed() << "," << newGame.getXSize() << "," << newGame.getYSize() << "," << newGame.getAliveCells() << "," << newGame.getStepCount() << "," << found->getName() << "\n";
						file.close();
						cout << "Game data saved successfully!" << endl;
					}
					else {
						cout << "Unable to open file." << endl;
					}

				}
				if (cont == 2)
				{
					for (int i = 0; i < 10; i++)
					{
						system("cls");
						newGame.updateGrid();
						newGame.printGrid();
						this_thread::sleep_for(chrono::seconds(1));
					}
				}


				break;

			}
			case 4: {
				//clear screen
				system("cls");
				cout << "##### Conway's Game of Life - Spaceships #####" << endl;

				// x, y, steps
				Grid newGame(32, 32, 70);
				newGame.setAliveCells(300);

				newGame.populateGrid();
				

				traversalSearch(spaceships, &newGame, 16);

				
				cout << "Visualise Seed? (yes/no): " << endl;
				string visualise;
				cin >> visualise;
				if (visualise == "yes")
				{
					newGame.startGame(true);


				}
				
				this_thread::sleep_for(chrono::seconds(1));
				system("cls");
				cout << "##### Conway's Game of Life - Still Lifes #####" << endl;
				cout << "1) Save the seed" << endl;
				cout << "2) Continue for 10 steps" << endl;

				int cont;
				cin >> cont;
				if (cont == 1) {
					// Open the CSV file in append mode
					std::ofstream file("conways_game_data.csv", std::ios::app);

					// Write the data to the file in CSV format
					if (file.is_open()) {
						file << newGame.getSeed() << "," << newGame.getXSize() << "," << newGame.getYSize() << "," << newGame.getAliveCells() << "," << newGame.getStepCount() << "," << "spaceship" << "\n";
						file.close();
						cout << "Game data saved successfully!" << endl;
					}
					else {
						cout << "Unable to open file." << endl;
					}
				}
				if (cont == 2) {
					for (int i = 0; i < 10; i++)
					{
						system("cls");
						newGame.updateGrid();
						newGame.printGrid();
						this_thread::sleep_for(chrono::seconds(1));
					}
					
				}
				break;
			}
		}


	return 0;

	}
}