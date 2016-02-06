#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Square.h"
#include "Basic.h"
#include "Game.h"
#include "Level0.h"
#include "Level1.h"
#include "Level2.h"
#include "Lateral.h"
#include "Upright.h"
#include "Unstable.h"
#include "Psychedelic.h"


using namespace std;

const int row = 10;
const int column = 10;
int seed = 1;
string inputfile = "sequence.txt";
int startlevel = 0;
//Square *board[row][column];
//bool lockedboard[row][column];

int main(int argc, char *argv[]) {
	// ***** Board created
	Square*** board = new Square**[row];	
	for (int i = 0; i < row; i++) {
		board[i] = new Square*[column];
	}
    bool **lockedboard = new bool*[row];
    for (int i=0; i<row; i++) {
        lockedboard[i] = new bool[column];
    }

	int argcCount = 1;
	string commandInterface;
	// Takes input and set corresponding values.
	while (argcCount < argc) {
		commandInterface = argv[argcCount];
		if (commandInterface == "-text") {

		}
		else if (commandInterface == "-seed") {
			istringstream ss(argv[argcCount + 1]);
			ss >> seed;
			argcCount += 2;
		}
		else if (commandInterface == "-scriptfile") {
			inputfile = argv[argcCount + 1];
			argcCount += 2;
		}
		else if (commandInterface == "-startlevel") {
			istringstream ss(argv[argcCount + 1]);
			ss >> startlevel;
			argcCount += 2;
		}
	}

	// Generate Game object (i.e. game started)
	Game *game;
	// Fulfill the condition in the objects. (if file != sequence.txt then do sth)
	if (startlevel == 0) {
		//****************************************lockedboard generator
		ifstream file(inputfile.c_str());
		string input;
		int tmp1 = 0;
		int tmp2 = 0;
		int count2 = 0;
		cout << "filename:" << inputfile << endl;
		while (file >> input) {
			if (input.at(0) == '_') {
				lockedboard[tmp1][tmp2] = false;
				if (tmp2 == 9) {
					tmp1 += 1;
					tmp2 = 0;
				}
				else {
					tmp2 += 1;
				}
			}
			else if (input.at(0) == '1') {
				lockedboard[tmp1][tmp2] = true;
				count2 += 1;
				if (tmp2 == 9) {
					tmp1 += 1;
					tmp2 = 0;
				}
				else {
					tmp2 += 1;
				}
			}
		}

		game = new Level0(0, 0, 10, 0, 0, lockedboard, board, inputfile);
		game->boardGenerator(seed);
        game->assignNeigh();
	}
	else if (startlevel == 1) {
		game = new Level1(1, 0, 10, 0, 0, lockedboard, board, inputfile);
		game->boardGenerator(seed);
        game->assignNeigh();
        game->boardDisplay();
        game->chainReaction();
        game->setScore(0);
        game->boardDisplay();
	}
	else if (startlevel == 2) {
		game = new Level2(2, 0, 10, 0, 20, lockedboard, board, inputfile);
		game->boardGenerator(seed);
        game->assignNeigh();
        game->boardDisplay();
        game->chainReaction();
        game->lockedBoardGenerator();
        game->setScore(0);
        game->boardDisplay();
	}

	// After creation, display the board
	game->boardDisplay();
	
	// Command receives
	string commandLine;
	cin >> commandLine;
	while (game->getRemainingMove() != 0) {
		if (commandLine == "hint") {
			game->hint();
		}
		else if (commandLine == "restart") {
			// call restart fn
			startlevel = game->getLevel();
            int startHighScore = game->getHighScore();
			if (startlevel == 0) {
				delete game;
				Square*** board = new Square**[row];	
				for (int i = 0; i < row; i++) {
					board[i] = new Square*[column];
				}
				game = new Level0(0, 0, 10, startHighScore, 0, lockedboard, board, inputfile);
				game->boardGenerator(seed);
				game->boardDisplay(); 
			}
			else if (startlevel == 1) {
				//Level1 lev();
				delete game;
				Square*** board = new Square**[row];	
				for (int i = 0; i < row; i++) {
					board[i] = new Square*[column];
				}
				game = new Level1(1, 0, 10, 0, 0, lockedboard, board, inputfile);
				game->boardGenerator(seed);
				game->boardDisplay();
			}
			else if (startlevel == 2) {
				//Level2 lev();
				//game = &lev;
			}
			cout << "restart called" << endl;
		}
		else if (commandLine == "scramble") {
			// call level down fn
			if (game->hint() != 0) {
				cout << "Cannot execute the command" << endl; 
			}
			else {
				game->scramble();
				/*srand(time(NULL));
				for (int i = 0; i < 10; i++) {
					random_shuffle(&board[i][0], &board[i][10]);
				}
				
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						board[i][j]->setX(i);
						board[i][j]->setY(j);
					}
				}

				game->assignNeigh();
				game->boardDisplay();*/
			}
		}
		else if (commandLine == "levelup") {
			// call levelup fn
			if (game->getLevel() == 2) {
				cout << "no more level available" << endl;
			}
			else {
				if (game->getLevel() == 0) {
					Game *tmp = new Level1(1, game->getScore(), game->getRemainingMove(), game->getHighScore(), game->getLockedSquare(), lockedboard, board, game->getFileName());
					delete game;
					game = tmp;
					game->boardDisplay();
				}
				else if (game->getLevel() == 1) {
					//Level2 lev();
				}
			}
			cout << "level up" << endl;
		}
		else if (commandLine == "leveldown") {
			// call leveldown
			if (game->getLevel() == 0) {
				cout << "no more level available" << endl;
			}
			else {
				if (game->getLevel() == 1) {
					//Level0 lev();
					Game *tmp = new Level0(0, game->getScore(), game->getRemainingMove(), game->getHighScore(), game->getLockedSquare(), lockedboard, board, game->getFileName());
					delete game;
					game = tmp;
					game->boardDisplay();
				}
				else if (game->getLevel() == 2) {
					//Level1 lev();
				}
			}
			
		}
		else if (commandLine == "swap") {
			int x;
			int y;
			int z;
			cin >> x;
			cin >> y;
			cin >> z;
			//game->setRemainingMove((game->getRemainingMove()) - 1);
			// call swap fn
			game->swap(x, y, z);
            if (game->getScore() > game->getHighScore()) {
              game->setHighScore(game->getScore());
            }
			game->boardDisplay();
		}

		if (game->winningCondition()) {
			cout << endl << "LEVEL UP!!" << endl << endl;
			unsigned int tmpscore = game->getScore();
            unsigned int temhiscore = game->getHighScore();
			delete game;
            Square*** board = new Square**[row];	
            for (int i = 0; i < row; i++) {
            	board[i] = new Square*[column];
            }
            bool **lockedboard = new bool*[row];
            for (int i=0; i<row; i++) {
                lockedboard[i] = new bool[column];
            }
			
            if (startlevel == 0) {
				game = new Level1(1, tmpscore, 10, temhiscore, 0, lockedboard, board, inputfile);	
				game->boardGenerator(seed);
                game->lockedBoardGenerator();
                game->assignNeigh();
                game->boardDisplay();
                game->chainReaction();
                game->setScore(tmpscore);
                game->boardDisplay();
			}
			else if (startlevel == 1) {
				game = new Level2(2, tmpscore, 10, 0, 20, lockedboard, board, inputfile);
				game->boardGenerator(seed);
                game->assignNeigh();
                game->boardDisplay();
                game->chainReaction();
                game->lockedBoardGenerator();
                game->setScore(tmpscore);
                game->boardDisplay();
			}
            else if (startlevel == 2) {
                cout << "ALL LEVEL CLEAR" << endl;
                cerr << "Program terminated" << endl;
                return 0;
            }
		}
        if (game->getRemainingMove() == 0) break;
		cin >> commandLine;
	}
	cout << "Game lost" << endl;
	delete game;
}
