#include "Level0.h"
#include "Square.h"
#include "Game.h"

#include "Basic.h"
#include "Lateral.h"
#include "Upright.h"
#include "Unstable.h"
#include "Psychedelic.h"

#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

Level0::Level0(int level, unsigned int score, int remainingMove, unsigned int highScore, int lockedSquare, bool** lockedBoard, Square *** Board, string filename):
	Game(level, score, remainingMove, highScore, lockedSquare, lockedBoard, Board, filename), startScore(score) {}

void Level0::boardGenerator(int seed) {
	ifstream file(Game::filename.c_str());
	string input;
	int row = 0;
	int column = 0;
	while (file >> input) {
		if (input.length() > 5) {
			
			break;
		}
		else if (input.at(1) == '_') {
			char tmp = input.at(2);
			int input = (int)tmp;

			Board[row][column] = new Basic(/*input.at(1)*/"_", input - 48, row, column);

			if (column == 9) {
				row += 1;
				column = 0;
			}
			else {
				column += 1;
			}
		}
		else if (input.at(1) == 'h') {
			char tmp = input.at(2);
			int input = static_cast<int> (tmp);


			Board[row][column] = new Lateral(/*input.at(1)*/"h", input - 48, row, column, Board);
			if (column == 9) {
				row += 1;
				column = 0;
			}
			else {
				column += 1;
			}
		}
		else if (input.at(1) == 'v') {
			char tmp = input.at(2);
			int input = static_cast<int> (tmp);

			Board[row][column] = new Upright("v", input - 48, row, column, Board);
			if (column == 9) {
				row += 1;
				column = 0;
			}
			else {
				column += 1;
			}
		}
		else if (input.at(1) == 'b') {
			char tmp = input.at(2);
			int input = static_cast<int> (tmp);

			Board[row][column] = new Unstable("b", input - 48, row, column, Board);
			if (column == 9) {
				row += 1;
				column = 0;
			}
			else {
				column += 1;
			}
		}
		else if (input.at(1) == 'p') {
			char tmp = input.at(2);
			int input = static_cast<int> (tmp);

			Board[row][column] = new Psychedelic("p", input - 48, row, column, Board);
			if (column == 9) {
				row += 1;
				column = 0;
			}
			else {
				column += 1;
			}
		}
	}

}

void Level0::lockedBoardGenerator() {
	ifstream file(Game::filename.c_str());
	string input;
	int row = 0;
	int column = 0;
	int count = 0;
	//lockedBoard = new bool[10][10];
	while (file >> input) {
		if (input.at(0) == '_') {
			lockedBoard[row][column] = false;
			if (column == 9) {
				row += 1;
				column = 0;
			}
			else {
				column += 1;
			}
		}
		else if (input.at(0) == '1') {
			lockedBoard[row][column] = true;
			count += 1;
			if (column == 9) {
				row += 1;
				column = 0;
			}
			else {
				column += 1;
			}
		}
	}
	lockedSquare = count;
}

void Level0::generate() {
	int count = 0;
	ifstream file(filename.c_str());
	string input;
	for (int i = 100; i != 0; i--) {
		file >> input;
	}
	file >> input;
	int length = input.length();
	
	bool cond = false;
	do {
		for (int i = 0; i < 10; i++) {
			if (Board[0][i] == NULL) {
				char tmp = input.at(count);
				int col = (int)tmp;
				Board[0][i] = new Basic("_", col - 48, 0, i);
				if (count == (length - 1)) {
					count = 0;
				}
				else {
					count++;
				}
			}
		}
		fillin();
		cond = false;
		for (int j = 0; j < 10; j++) {
			if (Board[0][j] == NULL) {
				cond = true;
			}
		}
	} while (cond == true);
	
}

bool Level0::winningCondition() {
	return (score > (200 + startScore));
}

Level0::~Level0() {
	for (int i = 0; i < 10; i++) {
		delete [] Board[i];
	}
	delete [] Board;
    for (int i = 0; i < 10; i++) {
		delete [] lockedBoard[i];
	}
	delete [] lockedBoard;
}

