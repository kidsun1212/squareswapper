#include "Level2.h"
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
#include <algorithm>

using namespace std;

Level2::Level2(int level, unsigned int score, int remainingMove, unsigned int highScore, int lockedSquare, bool** lockedBoard, Square *** Board, string filename):
	Game(level, score, remainingMove, highScore, lockedSquare, lockedBoard ,Board, filename), startScore(score) {}

void Level2::boardGenerator(int seed) {
	if (filename == "sequence.txt") {
        srand(seed);
        for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				int acc = rand() % 48;
				if (acc < 16) {
					//cout << "here" << endl;
					//if (*lockedBoard[i][j] == true) {
					//	Board[i][j] = new Basic("l", 0, i, j);
					//}
					//else {
						Board[i][j] = new Basic("_", 0, i, j);	
					//}
					
				}
				else if ((acc >= 16) && (acc < 32)) {
					//if (*lockedBoard[i][j] == true) {
					//	Board[i][j] = new Basic("l", 1, i, j);
					//}
					//else {
						Board[i][j] = new Basic("_", 1, i, j);	
					//}
				}
				else if ((acc >= 32) && (acc < 40)) {
					//if (*lockedBoard[i][j] == true) {
					//	Board[i][j] = new Basic("l", 2, i, j);
					//}
					//else {
						Board[i][j] = new Basic("_", 2, i, j);	
					//}
				}
				else {
					//if (*lockedBoard[i][j] == true) {
					//	Board[i][j] = new Basic("l", 3, i, j);
					//}
					//else {
						Board[i][j] = new Basic("_", 3, i, j);	
					//}
				}
			}
		}
	}
	else {
		ifstream file(Game::filename.c_str());
		string input;
		int row = 0;
		int column = 0;
		while (file >> input) {
			//char arry[3] = input.c_str();
			if (input.at(1) == '_') {
				char tmp = input.at(2);
				int input = (int)tmp;
				Board[row][column] = new Basic("_", input - 48, row, column);
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
				int input = (int)tmp;
				Board[row][column] = new Lateral("h", input, row, column, Board);
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
				int input = (int)tmp;
				Board[row][column] = new Upright("v", input, row, column, Board);
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
				int input = (int)tmp;
				Board[row][column] = new Unstable("v", input, row, column, Board);
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
				int input = (int)tmp;
				Board[row][column] = new Psychedelic("p", input, row, column, Board);
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
}

void Level2::lockedBoardGenerator() {
  for (int i=0; i<2; i++) {
    for (int j=0; j<10; j++) {
      lockedBoard[j][i] = true;
    }
  }
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    random_shuffle(&lockedBoard[i][0], &lockedBoard[i][10]);
  }
}

bool Level2::winningCondition() {
	bool lockedcond = true;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (lockedBoard[i][j] == true) {
				lockedcond = false;
			}
		}
	}
	bool cond = false;
	if (score > (startScore + 500)) {
		cond = true;
	}
	return (cond && lockedcond);
	//return cond;
}

void Level2::generate() {
	int count = 0;
  	if (filename != "sequence.txt") {
		ifstream file (filename.c_str());
		string input;
		for (int a = 100; a != 0; a--) {
			file >> input;
		}
		file >> input;
		char tmp = input.at(1);
		if ((tmp >= 48) && (tmp <= 58)) {
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
	}
    else {
		bool cond = false;
		do {
			for (int i = 0; i < 10; i++) {
				if (Board[0][i] == NULL) {
					int acc = rand() % 48;
					if (acc < 16) {
						Board[0][i] = new Basic("_", 0, 0, i);
					}
					else if ((acc >= 16) && (acc < 32)) {
						Board[0][i] = new Basic("_", 1, 0, i);
					}
					else if ((acc >= 32) && (acc < 40)) {
						Board[0][i] = new Basic("_", 2, 0, i);
					}
					else {
						Board[0][i] = new Basic("_", 3, 0, i);
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
}

Level2::~Level2() {
	for (int i = 0; i < 10; i++) {
		delete [] Board[i];
	}
	delete [] Board;
    for (int i = 0; i < 10; i++) {
		delete [] lockedBoard[i];
	}
	delete [] lockedBoard;
}
