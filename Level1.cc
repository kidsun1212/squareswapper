#include "Level1.h"
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

Level1::Level1(int level, unsigned int score, int remainingMove, unsigned int highScore, int lockedSquare, bool** lockedBoard, Square *** Board, string filename):
	Game(level, score, remainingMove, highScore, lockedSquare, lockedBoard ,Board, filename), startScore(score) {}

void Level1::boardGenerator(int seed) {
	if (filename == "sequence.txt") {
		int count = 0;
		srand(seed);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				count += 1;
				int acc = rand() % 48;
				if ((count % 5) != 0) {
					if (acc < 16) {
						Board[i][j] = new Basic("_", 0, i, j);
					}
					else if ((acc >= 16) && (acc < 32)) {
						Board[i][j] = new Basic("_", 1, i, j);
					}
					else if ((acc >= 32) && (acc < 40)) {
						Board[i][j] = new Basic("_", 2, i, j);
					}
					else {
						Board[i][j] = new Basic("_", 3, i, j);
					}
				}
				else {
					if (acc < 16) {
						if ((acc % 4) == 0) {
							Board[i][j] = new Lateral("h", 0, i, j, Board);
						}
						else if ((acc % 4) == 1) {
							Board[i][j] = new Upright("v", 0, i, j, Board);
						}
						else if ((acc % 4) == 2) {
							Board[i][j] = new Unstable("b", 0, i, j, Board);
						}
						else {
							Board[i][j] = new Psychedelic("p", 0, i, j, Board);
						}
					}
					else if ((acc >= 16) && (acc < 32)) {
						if ((acc % 4) == 0) {
							Board[i][j] = new Lateral("h", 1, i, j, Board);
						}
						else if ((acc % 4) == 1) {
							Board[i][j] = new Upright("v", 1, i, j, Board);
						}
						else if ((acc % 4) == 2) {
							Board[i][j] = new Unstable("b", 1, i, j, Board);
						}
						else {
							Board[i][j] = new Psychedelic("p", 1, i, j, Board);
						}
					}
					else if ((acc >= 32) && (acc < 40)) {
						if ((acc % 4) == 0) {
							Board[i][j] = new Lateral("h", 2, i, j, Board);
						}
						else if ((acc % 4) == 1) {
							Board[i][j] = new Upright("v", 2, i, j, Board);
						}
						else if ((acc % 4) == 2) {
							Board[i][j] = new Unstable("b", 2, i, j, Board);
						}
						else {
							Board[i][j] = new Psychedelic("p", 2, i, j, Board);
						}
					}
					else {
						if ((acc % 4) == 0) {
							Board[i][j] = new Lateral("h", 3, i, j, Board);
						}
						else if ((acc % 4) == 1) {
							Board[i][j] = new Upright("v", 3, i, j, Board);
						}
						else if ((acc % 4) == 2) {
							Board[i][j] = new Unstable("b", 3, i, j, Board);
						}
						else {
							Board[i][j] = new Psychedelic("p", 3, i, j, Board);
						}
					}
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


void Level1::generate() {
	int count = 0;
	if (filename != "sequence.txt") {
		ifstream file (filename.c_str());
		string input;
		for (int a = 100; a != 0; a--) {
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

void Level1::lockedBoardGenerator() {
	if (filename == "sequence.txt") {
		for(int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				lockedBoard[i][j] = false;
			}
		}
	}
	else {
		ifstream file(Game::filename.c_str());
		string input;
		int row = 0;
		int column = 0;
		int count = 0;
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
}

bool Level1::winningCondition() {
	return (score > (200 + startScore));
}

Level1::~Level1() {
	for (int i = 0; i < 10; i++) {
		delete [] Board[i];
	}
	delete [] Board;
    for (int i = 0; i < 10; i++) {
		delete [] lockedBoard[i];
	}
	delete [] lockedBoard;
}
