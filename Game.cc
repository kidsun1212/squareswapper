#include "Game.h"
#include "Square.h"
#include "Basic.h"
#include "Lateral.h"
#include "Upright.h"
#include "Unstable.h"
#include "Psychedelic.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

//Ctor
//Game::Game(int level, unsigned int score, int remainingMove, unsigned int highScore, int lockedSquare, Square*** Board, string filename):
//	level(level), score(score), remainingMove(remainingMove), highScore(highScore), lockedSquare(lockedSquare),Board(Board), filename(filename) {}
Game::Game(int level, unsigned int score, int remainingMove, unsigned int highScore, int lockedSquare, bool** lockedBoard, Square*** Board, string filename):
	level(level), score(score), remainingMove(remainingMove), highScore(highScore), lockedSquare(lockedSquare), lockedBoard(lockedBoard), Board(Board), filename(filename) {}

int Game::hint(/*Square ** arry*/) {
  // Find Horizontal Hint first, then vertical Hint
  Square ***arry = Board;
  for (int i = 0; i < 10; i++) { // row
    // Horizontal A************************************
    // Case1 & Case 3
    for (int k = 0; k < 8; k++) {
      if ((i > 0) && (arry[i][k]->getColour() == arry[i][k+1]->getColour())) {
        if (arry[i-1][k+2]->getColour() == arry[i][k]->getColour()) {
          //cout << "Horizontal A Case1" << endl;
          //return arry[i-1][k+2];
          cout << "(" << arry[i-1][k+2]->getX() << "," << arry[i-1][k+2]->getY() << "," << "1)" << endl;
          return 1;
        }
      }
      if ((i < 9) && (arry[i][k]->getColour() == arry[i][k+1]->getColour())) {
        if (arry[i+1][k+2]->getColour() == arry[i][k]->getColour()) {
          //cout << "Horizontal A Case3" << endl;
          //return arry[i+1][k+2];
          cout << "(" << arry[i+1][k+2]->getX() << "," << arry[i+1][k+2]->getY() << "," << "0)" << endl;
          return 1;
        }
      }
    }
    // Case2
    for (int z = 0; z < 7; z++) {
      if (arry[i][z]->getColour() == arry[i][z+1]->getColour()) {
        if (arry[i][z+3]->getColour() == arry[i][z]->getColour()) {
          //cout << "Horizontal A Case2" << endl;
          //return arry[i][z+3];
          cout << "(" << arry[i][z+3]->getX() << "," << arry[i][z+3]->getY() << "," << "2)" << endl;
          return 1;
        }
      }
    }
    // Case5
    for (int m = 3; m < 10; m++) {
      if (arry[i][m]->getColour() == arry[i][m-1]->getColour()) {
        if (arry[i][m-3]->getColour() == arry[i][m]->getColour()) {
          //cout << "Horizontal A Case 5" << endl;
          //return arry[i][m-3];
          cout << "(" << arry[i][m-3]->getX() << "," << arry[i][m-3]->getY() << "," << "3)" << endl;
          return 1;
        }
      }
    }
    // Case4 & Case6
    for (int n = 2; n < 10; n++) {
      if (arry[i][n]->getColour() == arry[i][n-1]->getColour()) {
        if ((i > 0) && (arry[i-1][n-2]->getColour() == arry[i][n]->getColour())) {
          //cout << "Horizontal A Case 6" << endl;
          //return arry[i-1][n-2];
          cout << "(" << arry[i-1][n-2]->getX() << "," << arry[i-1][n-2]->getY() << "," << "1)" << endl;
          return 1;
        }
        if ((i < 9) && (arry[i+1][n-2]->getColour() == arry[i][n]->getColour())) {
          //cout << "Horizontal A Case 4" << endl;
          //return arry[i+1][n-2];
          cout << "(" << arry[i+1][n-2]->getX() << "," << arry[i+1][n-2]->getY() << "," << "0)" << endl;
          return 1;
        }
      }
    }
    
    // Horizontal B ****OK****
    for (int k = 0; k < 8; k++) { // column
      if (arry[i][k]->getColour() == arry[i][k+2]->getColour()) {
        if (i > 0) {
          if (arry[i-1][k+1]->getColour() == arry[i][k]->getColour()) {
            //return arry[i-1][k+1];
            cout << "(" << arry[i-1][k+1]->getX() << "," << arry[i-1][k+1]->getY() << "," << "1)" << endl;
            return 1;
          }
        }
        if (i < 9) {
          if (arry[i+1][k+1]->getColour() == arry[i][k]->getColour()) {
            //return arry[i+1][k+1];
            cout << "(" << arry[i+1][k+1]->getX() << "," << arry[i+1][k+1]->getY() << "," << "0)" << endl;
            return 1;
          }
        }
      }
    }
  }

  for (int a = 0; a < 10; a++) { // column
    // Vertical A
    for (int k = 0; k < 8; k++) {
      if ((a > 0) && (arry[k][a]->getColour() == arry[k+1][a]->getColour())) {
        if (arry[k+2][a-1]->getColour() == arry[k][a]->getColour()) {
          //cout << "Vertical A Case1" << endl;
          //return arry[k+2][a-1];
          cout << "(" << arry[k+2][a-1]->getX() << "," << arry[k+2][a-1]->getY() << "," << "3)" << endl;
          return 1;
        }
      }
      if ((a < 9) && (arry[k][a]->getColour() == arry[k+1][a]->getColour())) {
        if (arry[k+2][a+1]->getColour() == arry[k][a]->getColour()) {
          //cout << "Vertical A Case3" << endl;
          //return arry[k+2][a+1];
          cout << "(" << arry[k+2][a+1]->getX() << "," << arry[k+2][a+1]->getY() << "," << "2)" << endl;
          return 1;
        }
      }
    }
    // Case2
    for (int z = 0; z < 7; z++) {
      if (arry[z][a]->getColour() == arry[z+1][a]->getColour()) {
        if (arry[z+3][a]->getColour() == arry[z][a]->getColour()) {
          //cout << "Horizontal A Case2" << endl;
          //return arry[z+3][a];
          cout << "(" << arry[z+3][a]->getX() << "," << arry[z+3][a]->getY() << "," << "1)" << endl;
          return 1;
        }
      }
    }
    // Case5
    for (int m = 3; m < 10; m++) {
      if (arry[m][a]->getColour() == arry[m-1][a]->getColour()) {
        if (arry[m-3][a]->getColour() == arry[m][a]->getColour()) {
          //cout << "Horizontal A Case 5" << endl;
          //return arry[m-3][a];
          cout << "(" << arry[m-3][a]->getX() << "," << arry[m-3][a]->getY() << "," << "0)" << endl;
          return 1;
        }
      }
    }
    // Case4 & Case6
    for (int n = 2; n < 10; n++) {
      if (arry[n][a]->getColour() == arry[n-1][a]->getColour()) {
        if ((a > 0) && (arry[n-2][a-1]->getColour() == arry[n][a]->getColour())) {
          //cout << "Horizontal A Case 6" << endl;
          //return arry[n-2][a-1];
          cout << "(" << arry[n-2][a-1]->getX() << "," << arry[n-2][a-1]->getY() << "," << "2)" << endl;
          return 1;
        }
        if ((a < 9) && (arry[n-2][a+1]->getColour() == arry[n][a]->getColour())) {
          //cout << "Horizontal A Case 4" << endl;
          //return arry[n-2][a+1];
          cout << "(" << arry[n-2][a+1]->getX() << "," << arry[n-2][a+1]->getY() << "," << "3)" << endl;
          return 1;
        }
      }
    }
    // Vertical B ****OK****
    for (int j = 0; j < 8; j++) { //row
      if (arry[j][a]->getColour() == arry[j+2][a]->getColour()) {
        if (a > 0) {
          if (arry[j+1][a-1]->getColour() == arry[j][a]->getColour()) {
            //cout << "here: " << arry[j][a]->getColour() << arry[j+1][a-1]->getColour() << arry[j+2][a]->getColour() << endl;
            //return arry[j+1][a-1];
            cout << "(" << arry[j+1][a-1]->getX() << "," << arry[j+1][a-1]->getY() << "," << "3)" << endl;
            return 1;
          }
        }
        if (a < 9) {
          if (arry[j+1][a+1]->getColour() == arry[j][a]->getColour()) {
            //return arry[j+1][a+1];
            cout << "(" << arry[j+1][a+1]->getX() << "," << arry[j+1][a+1]->getY() << "," << "2)" << endl;
            return 1;
          }
        }
      }
    }
  }
  // no hints available
  //return NULL;
  return 0;
  //cout << "Impossible" << endl;
}

void Game::scramble() {
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    random_shuffle(&Board[i][0], &Board[i][10]);
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      Board[i][j]->setX(i);        
      Board[i][j]->setY(j);
    }
  }
  assignNeigh();
  boardDisplay();
}

void Game::assignNeigh() {
  for (int i=0; i<10; ++i) {
    for (int j=0; j<10; ++j) {
      if (i==0) {
        Board[i][j]->north = NULL;
      } else if (i>0) {
        Board[i][j]->north = Board[i-1][j];
      }

      if (i==9) {
        Board[i][j]->south = NULL;
      } else if (i<9) {
        Board[i][j]->south = Board[i+1][j];
      }

      if (j==0) {
        Board[i][j]->west = NULL;
      } else if (j>0) {
        Board[i][j]->west = Board[i][j-1];
      }

      if (j==9) {
        Board[i][j]->east = NULL;
      } else if (j<9) {
        Board[i][j]->east = Board[i][j+1];
      }
    }
  }
}

void Game::scoring(int squares ,int combo) {
  int two = 1;
  for (int i=0; i<combo; ++i) {
    two *= 2;
  }
  
  if (squares == 3) {
    score += 1*3 * two;
  } else if (squares == 4) {
    score += 2*4 * two;
  } else if (squares == 5) {
    score += 3*5 * two;
  } else if (squares > 5) {
    score += 4*squares *two;
  }
}

void Game::clearCrush() {
//cout << "in clearCrush" << endl;
//boardDisplay();
  for (int i=0; i<10; ++i) {
    for (int j=0; j<10; ++j) {
//cout << i << " " << j << endl;
      if (Board[i][j] != NULL && Board[i][j]->pop == true) {
        Board[i][j]->crush();
//boardDisplay();
      }
    }
  }
  for (int i=0; i<10; ++i) {
    for (int j=0; j<10; ++j) {
      if (Board[i][j] != NULL && Board[i][j]->pop == true) {
        if (Board[i][j]->popCount != 0) {
          scoring(Board[i][j]->popCount, 0);
        }
        delete Board[i][j];
        Board[i][j] = NULL;
        if (lockedBoard[i][j]) {
          lockedBoard[i][j] = false;
          lockedSquare--;
        }
      }
    }
  }
}

void Game::fillin() {
//cout << "fillin called" << endl;
  for (int i = 9; i > 0; i--) {
    for (int j = 0; j < 10; j++) {
      if (Board[i][j] == NULL) {
        int z = 1;
        while ((Board[i-z][j] == NULL) && ((i-z) > 0)) {
          z++;
        }
        
        if (Board[i-z][j] != NULL) {
          Board[i][j] = Board[i-z][j];
          Board[i][j]->setX(i);
          Board[i-z][j] = NULL;
        }
        z = 1;
      }
    }
  }
}

string Game::crushable(Square* piv) {
  int dirCount = 0;
  if (piv->northSame > 0) ++dirCount;
  if (piv->southSame > 0) ++dirCount;
  if (piv->westSame > 0) ++dirCount;
  if (piv->eastSame > 0) ++dirCount;

  if (piv->popCount == 3) {
    if (dirCount==1 || (dirCount==2 && piv->northSame==1 && piv->southSame==1) || 
        (dirCount==2 && piv->westSame==1 && piv->eastSame==1)) {
          return "Basic";
        }
  }
  
  if (piv->popCount == 4) {
    if (dirCount==2 && ( (piv->northSame>0 && piv->eastSame>0) || (piv->northSame>0 && piv->westSame>0) || 
    (piv->southSame>0 && piv->eastSame>0) || (piv->southSame>0 && piv->westSame>0) )) {
          if (piv->northSame==2 || piv->southSame==2) {
            if (piv->westSame>0) (piv->west)->chain(piv->getColour(), 0, false, piv);
            if (piv->eastSame>0) (piv->east)->chain(piv->getColour(), 0, false, piv);
          }
          if (piv->westSame==2 || piv->eastSame==2) {
            if (piv->northSame>0) (piv->north)->chain(piv->getColour(), 0, false, piv);
            if (piv->southSame>0) (piv->south)->chain(piv->getColour(), 0, false, piv);
          }
          return "Basic";
    }

    if (dirCount==3) {
      if (piv->northSame==0 && piv->southSame>0) (piv->south)->chain(piv->getColour(), 0, false, piv);
      if (piv->southSame==0 && piv->northSame>0) (piv->north)->chain(piv->getColour(), 0, false, piv);
      if (piv->westSame==0 && piv->eastSame>0) (piv->east)->chain(piv->getColour(), 0, false, piv);
      if (piv->eastSame==0 && piv->westSame>0) (piv->west)->chain(piv->getColour(), 0, false, piv);
      return "Basic";
    }
    
    if (dirCount==2) {
      if (piv->northSame>0 && piv->southSame>0) return "Upright";
      if (piv->westSame>0 && piv->eastSame>0) return "Lateral";
    }
  }

  if (piv->popCount == 5) {
    if (dirCount==3) {
      if ((piv->northSame==1 && piv->southSame==1) || (piv->westSame==1 && piv->eastSame==1)) {
        return "Unstable";
      } 
      if (piv->northSame>0 && piv->southSame>0) {
        if (piv->westSame==0 && piv->eastSame>0) (piv->east)->chain(piv->getColour(), 0, false, piv);
        if (piv->eastSame==0 && piv->westSame>0) (piv->west)->chain(piv->getColour(), 0, false, piv);
        return "Upright";
      }
      if (piv->westSame>0 && piv->eastSame>0) {
        if (piv->northSame==0 && piv->southSame>0) (piv->south)->chain(piv->getColour(), 0, false, piv);
        if (piv->southSame==0 && piv->northSame>0) (piv->north)->chain(piv->getColour(), 0, false, piv);
        return "Lateral";
      }
    }

    if (dirCount==2) {
      if ((piv->northSame==2 && piv->southSame==2) || (piv->westSame==2 && piv->eastSame==2)) {
        return "Psychedelic";
      } else {
        return "Unstable";
      }
    }
  }

  if (piv->popCount == 6) {
    if (piv->northSame==2 && piv->southSame==2) {
      if (piv->westSame==0 && piv->eastSame>0) (piv->east)->chain(piv->getColour(), 0, false, piv);
      if (piv->eastSame==0 && piv->westSame>0) (piv->west)->chain(piv->getColour(), 0, false, piv);
      return "Psychedelic";
    }
    if (piv->westSame==2 && piv->eastSame==2) {
      if (piv->northSame==0 && piv->southSame>0) (piv->south)->chain(piv->getColour(), 0, false, piv);
      if (piv->southSame==0 && piv->northSame>0) (piv->north)->chain(piv->getColour(), 0, false, piv);
      return "Psychedelic";
    }
    return "Unstable";
  }

  if (piv->popCount == 7) {
    if (dirCount == 3) {
      return "Psychedelic";
    }
  }

  return "None";
  
}

void Game::chainReaction() {
//cout << "CHAINREACTION BEFORE" << endl;
boardDisplay();
//cout << "CHAINREACTION START" << endl;
  bool contin = false;
  int twoToThe = 1;
  do {
    contin = false;
    Square* arr[19];
    for (int k=0; k<19; ++k) arr[k] = NULL;
    int c = 0;
  
    for (int i=0; i<10; ++i) {
      for (int j=0; j<10; ++j) {
        if (Board[i][j] != NULL && Board[i][j]->pop == false && Board[i][j]->popCount != -1) {
//cout << endl;
//cout << "Board[" << i << "][" << j << "] accessed" << endl;
          Square* init = Board[i][j];
          Square* aim = Board[i][j];
          //&& aim->popCount != -1
          int a = 1;
          while (aim != NULL && aim->getColour() == init->getColour()) {
            arr[c] = aim;
            ++c;
            if (i+a == 10) {
              aim = NULL;
            } else {
              aim = Board[i+a][j];
            }
            ++a;
//cout << "#aim->east assigned#" << endl;
          } a=1;
          
          if (j+1 != 10) {
            aim = Board[i][j+1];
          } else {
            aim = NULL;
          }
          
          int b = 1;
          while (aim != NULL && aim->getColour() == init->getColour()) {
            arr[c] = aim;
            ++c;
//if (aim->south != NULL) cout << "aim->south is not NULL" << endl;
            if (j+b == 10) {
              aim = NULL;
            }  else {
              aim = Board[i][j+b];
            }
            ++b;
//cout << "#aim->south assigned#" <<endl;
          } b=1;

          int n = 0;
          int pickedn = 0;
          string pickedType = "None";
          while (arr[n] != NULL) {
//cout << "For Board[" << arr[n]->getX() << "][" << arr[n]->getY() << "]" << endl;
//cout << " Colour : " << arr[n]->getColour() << endl;
//cout << "In WHILE ... n=" << n << endl;
            arr[n]->pop = true;
            arr[n]->popCount = 1;
            if (arr[n]->getX() > 0) (arr[n]->north)->chainCheck(arr[n]->getColour(), 0, arr[n]);
//cout << "chainCheck NORTH ";
            if (arr[n]->getX() < 9) (arr[n]->south)->chainCheck(arr[n]->getColour(), 1, arr[n]);
//cout << "chainCheck SOUTH ";
            if (arr[n]->getY() > 0) (arr[n]->west)->chainCheck(arr[n]->getColour(), 2, arr[n]);
//cout << "chainCheck WEST ";
            if (arr[n]->getY() < 9) (arr[n]->east)->chainCheck(arr[n]->getColour(), 3, arr[n]);
//cout << "chainCheck EAST " << endl;
//cout << "popCount=" << arr[n]->popCount << " northSame=" << arr[n]->northSame <<
//        " southSame=" << arr[n]->southSame << " westSame=" << arr[n]->westSame << " eastSame=" << arr[n]->eastSame << endl;
            
            string typeofsq;

            if ((arr[n]->northSame>=2 && arr[n]->southSame>=2) || (arr[n]->westSame>=2 && arr[n]->eastSame>=2)) {
              if (arr[n]->popCount == 6) {
                if (arr[n]->northSame==1) {
                  arr[n]->northSame = 0;
                  arr[n]->popCount--;
                }
                if (arr[n]->southSame==1) {
                  arr[n]->southSame = 0;
                  arr[n]->popCount--;
                }
                if (arr[n]->westSame==1) {
                  arr[n]->westSame = 0;
                  arr[n]->popCount--;
                }
                if (arr[n]->eastSame==1) {
                  arr[n]->eastSame = 0;
                  arr[n]->popCount--;
                }
              }
              typeofsq = "Psychedelic";
            
            } else if (arr[n]->popCount >= 5 &&
            ((arr[n]->northSame>=2 && arr[n]->eastSame>=2) || (arr[n]->eastSame>=2 && arr[n]->southSame>=2) ||
            (arr[n]->southSame>=2 && arr[n]->westSame>=2) || (arr[n]->westSame>=2 && arr[n]->northSame>=2))) {
              typeofsq = "Unstable";

            } else if (arr[n]->popCount >= 4 && 
            ((arr[n]->westSame == 2 && arr[n]->eastSame == 1) || (arr[n]->eastSame == 2 && arr[n]->westSame == 1))) {
              if (arr[n]->popCount == 5) {
                if (arr[n]->northSame==1 && arr[n]->southSame==0) {
                  arr[n]->northSame = 0;
                  arr[n]->popCount--;
                }
                if (arr[n]->southSame==1 && arr[n]->northSame==0) {
                  arr[n]->southSame = 0;
                  arr[n]->popCount--;
                }
                if (arr[n]->westSame==1 && arr[n]->eastSame==0) {
                  arr[n]->westSame = 0;
                  arr[n]->popCount--;
                }
                if (arr[n]->eastSame==1 && arr[n]->westSame==0) {
                  arr[n]->eastSame = 0;
                  arr[n]->popCount--;
                }
              }
              typeofsq = "Lateral";
            
            } else if (arr[n]->popCount >= 4 && 
            ((arr[n]->northSame == 2 && arr[n]->southSame == 1) || (arr[n]->southSame == 2 && arr[n]->northSame == 1))) {
              if (arr[n]->popCount == 5) {
                if (arr[n]->northSame==1 && arr[n]->southSame==0) {
                  arr[n]->northSame = 0;
                  arr[n]->popCount--;
                }
                if (arr[n]->southSame==1 && arr[n]->northSame==0) {
                  arr[n]->southSame = 0;
                  arr[n]->popCount--;
                }
                if (arr[n]->westSame==1 && arr[n]->eastSame==0) {
                  arr[n]->westSame = 0;
                  arr[n]->popCount--;
                }
                if (arr[n]->eastSame==1 && arr[n]->westSame==0) {
                  arr[n]->eastSame = 0;
                  arr[n]->popCount--;
                }
              }
              typeofsq = "Upright";

            } else if (arr[n]->popCount >= 3 &&
            ((arr[n]->northSame == 1 && arr[n]->southSame == 1) || (arr[n]->westSame == 1 && arr[n]->eastSame == 1))) {
              if (arr[n]->northSame==1 && arr[n]->southSame==0) {
                arr[n]->northSame = 0;
                arr[n]->popCount--;
              }
              if (arr[n]->southSame==1 && arr[n]->northSame==0) {
                arr[n]->southSame = 0;
                arr[n]->popCount--;
              }
              if (arr[n]->westSame==1 && arr[n]->eastSame==0) {
                arr[n]->westSame = 0;
                arr[n]->popCount--;
              }
              if (arr[n]->eastSame==1 && arr[n]->westSame==0) {
                arr[n]->eastSame = 0;
                arr[n]->popCount--;
              }
              typeofsq = "Basic";
              
            } else {
              arr[n]->pop = false;
              arr[n]->popCount = 0;
              arr[n]->northSame = 0;
              arr[n]->southSame = 0;
              arr[n]->westSame = 0;
              arr[n]->eastSame = 0;
              typeofsq = "None";
            }
            
            
            if (typeofsq == "Psychedelic") {
              pickedn = n;
              pickedType = "Psychedelic";
            } else if (pickedType!="Psychedelic" && typeofsq=="Unstable") {
              pickedn = n;
              pickedType = "Unstable";
            } else if (pickedType!="Psychedelic" && pickedType!="Unstable" && (typeofsq=="Lateral" || typeofsq=="Upright")) {
              pickedn = n;
              if (typeofsq == "Lateral") pickedType = "Lateral";
              if (typeofsq == "Upright") pickedType = "Upright";
            } else if (pickedType=="None" && typeofsq=="Basic") {
              pickedn = n;
              pickedType = "Basic";
            }
//cout << "Picked Type : " << pickedType << endl;
            ++n;
          }

          for (int m=0; arr[m]!=NULL && m<19; ++m) {
            arr[m]->popCount = 0;
            arr[m]->northSame = 0;
            arr[m]->southSame = 0;
            arr[m]->westSame = 0;
            arr[m]->eastSame = 0;
          }

          arr[pickedn]->pop = true;
          arr[pickedn]->visit = true;
          arr[pickedn]->popCount = 1;

          if (arr[pickedn]->getX() > 0) (arr[pickedn]->north)->chain(arr[pickedn]->getColour(), 0, true, arr[pickedn]);
          if (arr[pickedn]->getX() < 9) (arr[pickedn]->south)->chain(arr[pickedn]->getColour(), 1, true, arr[pickedn]);
          if (arr[pickedn]->getY() > 0) (arr[pickedn]->west)->chain(arr[pickedn]->getColour(), 2, true, arr[pickedn]);
          if (arr[pickedn]->getY() < 9) (arr[pickedn]->east)->chain(arr[pickedn]->getColour(), 3, true, arr[pickedn]);

          if (pickedType == "None") {
            arr[pickedn]->pop = false;
            arr[pickedn]->visit = false;

            // reset arr[pickedn] chains
            if (arr[pickedn]->northSame > 0) {
              (arr[pickedn]->north)->chain(arr[pickedn]->getColour(), 0, false, arr[pickedn]);
            }
            if (arr[pickedn]->southSame > 0) {
              (arr[pickedn]->south)->chain(arr[pickedn]->getColour(), 1, false, arr[pickedn]);
            }
            if (arr[pickedn]->westSame > 0) {
              (arr[pickedn]->west)->chain(arr[pickedn]->getColour(), 2, false, arr[pickedn]);
            }
            if (arr[pickedn]->eastSame > 0) {
              (arr[pickedn]->east)->chain(arr[pickedn]->getColour(), 3, false, arr[pickedn]);
            }
            arr[pickedn]->popCount = 0;

          } else {

            // reset uncrushed arr[pickedn] chains
            if (pickedType == "Basic") {
              if (arr[pickedn]->westSame == 1 && arr[pickedn]->eastSame == 1) {
                if (arr[pickedn]->northSame > 0) {
                  (arr[pickedn]->north)->chain(arr[pickedn]->getColour(), 0, false, arr[pickedn]);
                }
                if (arr[pickedn]->southSame > 0) {
                  (arr[pickedn]->south)->chain(arr[pickedn]->getColour(), 1, false, arr[pickedn]);
                }
              } else if (arr[pickedn]->northSame == 1 && arr[pickedn]->southSame == 1) {
                if (arr[pickedn]->westSame > 0) {
                  (arr[pickedn]->west)->chain(arr[pickedn]->getColour(), 2, false, arr[pickedn]);
                }
                if (arr[pickedn]->eastSame > 0) {
                  (arr[pickedn]->east)->chain(arr[pickedn]->getColour(), 3, false, arr[pickedn]);
                }
              }
            }
            if (pickedType == "Lateral") {
              if (arr[pickedn]->northSame == 1 || arr[pickedn]->southSame == 1) {
                if (arr[pickedn]->northSame > 0) {
                  (arr[pickedn]->north)->chain(arr[pickedn]->getColour(), 0, false, arr[pickedn]);
                }
                if (arr[pickedn]->southSame > 0) {
                  (arr[pickedn]->south)->chain(arr[pickedn]->getColour(), 1, false, arr[pickedn]);
                }
              }
            }
            if (pickedType == "Upright") {
              if (arr[pickedn]->westSame == 1 || arr[pickedn]->eastSame == 1) {
                if (arr[pickedn]->westSame > 0) {
                  (arr[pickedn]->west)->chain(arr[pickedn]->getColour(), 2, false, arr[pickedn]);
                }
                if (arr[pickedn]->eastSame > 0) {
                  (arr[pickedn]->east)->chain(arr[pickedn]->getColour(), 3, false, arr[pickedn]);
                }
              }
            }
            if (pickedType == "Psychedelic") {
              if (arr[pickedn]->westSame == 2 && arr[pickedn]->eastSame == 2) {
                if (arr[pickedn]->northSame > 0) {
                  (arr[pickedn]->north)->chain(arr[pickedn]->getColour(), 0, false, arr[pickedn]);
                }
                if (arr[pickedn]->southSame > 0) {
                  (arr[pickedn]->south)->chain(arr[pickedn]->getColour(), 1, false, arr[pickedn]);
                }
              } else if (arr[pickedn]->northSame == 2 && arr[pickedn]->southSame == 2) {
                if (arr[pickedn]->westSame > 0) {
                  (arr[pickedn]->west)->chain(arr[pickedn]->getColour(), 2, false, arr[pickedn]);
                }
                if (arr[pickedn]->eastSame > 0) {
                  (arr[pickedn]->east)->chain(arr[pickedn]->getColour(), 3, false, arr[pickedn]);
                }
              }
            }

            contin = true;

            int arrX = arr[pickedn]->getX();
            int arrY = arr[pickedn]->getY();
            int arrColour = arr[pickedn]->getColour();

            arr[pickedn]->crush();
            scoring(arr[pickedn]->popCount, twoToThe);
            delete Board[arrX][arrY];
            Board[arrX][arrY] = NULL;

            if (pickedType == "Lateral") Board[arrX][arrY] = new Lateral("h", arrColour, arrX, arrY, Board);
            if (pickedType == "Upright") Board[arrX][arrY] = new Upright("v", arrColour, arrX, arrY, Board);
            if (pickedType == "Unstable") Board[arrX][arrY] = new Unstable("b", arrColour, arrX, arrY, Board);
            if (pickedType == "Psychedelic") Board[arrX][arrY] = new Psychedelic("p", arrColour, arrX, arrY, Board);
            if (Board[arrX][arrY] != NULL) Board[arrX][arrY]->popCount = -1;
//cout << "IN CHAINREACTION: squares made" << endl;
//boardDisplay();
          }
          
          for (int k=0; k<19; ++k) arr[k] = NULL;
          c = 0;
        }
      }
    }

    for (int i=0; i<10; ++i) {
      for (int j=0; j<10; ++j) {
        if (Board[i][j] != NULL && Board[i][j]->popCount == -1) Board[i][j]->popCount = 0;
      }
    }

    clearCrush();
//boardDisplay();
    fillin();
//boardDisplay();
    generate();
    assignNeigh();
//boardDisplay();
    twoToThe++;
  } while (contin);
}

void Game::swap(int posX, int posY, int direction) {
  if (posX>=0 && posX<10 && posY>=0 && posY<10) {
//cout << "*********************swap called*********************" << endl;
    Square *original = Board[posX][posY];
    Square *other;
  
    // assigning swapping square
    if (direction == 0 && posX>0) {
      other = Board[posX-1][posY];
    } else if (direction == 1 && posX<9) {
      other = Board[posX+1][posY];
    } else if (direction == 2 && posY>0) {
      other = Board[posX][posY-1];
    } else if (direction == 3 && posY<9) {
      other = Board[posX][posY+1];
    } else {
      other = NULL;
    }
//cout << "assign swapping square" << endl;
    if (other != NULL) {
      original->pop = true;
      original->visit = true;
      original->popCount = 1;
      other->pop = true;
      other->visit = true;
      other->popCount = 1;
      
      // swap
      Board[posX][posY] = other;
      Board[posX][posY]->setX(posX);
      Board[posX][posY]->setY(posY);
//cout << "swap position" << endl;
      if (direction == 0) {
        Board[posX-1][posY] = original;
        Board[posX-1][posY]->setX(posX-1);
        Board[posX-1][posY]->setY(posY);
      } else if (direction == 1) {
        Board[posX+1][posY] = original;
        Board[posX+1][posY]->setX(posX+1);
        Board[posX+1][posY]->setY(posY);
      } else if (direction == 2) {
        Board[posX][posY-1] = original;
        Board[posX][posY-1]->setX(posX);
        Board[posX][posY-1]->setY(posY-1);
      } else if (direction == 3) {
        Board[posX][posY+1] = original;
        Board[posX][posY+1]->setX(posX);
        Board[posX][posY+1]->setY(posY+1);
      }
      assignNeigh();
//cout << "assignNeigh()" << endl;
      // 4 direction chains of original
      if (original->getX() > 0 && direction != 1) (original->north)->chain(original->getColour(), 0, true, original);
//cout << "passed north ";
      if (original->getX() < 9 && direction != 0) (original->south)->chain(original->getColour(), 1, true, original);
//cout << "passed south ";
      if (original->getY() > 0 && direction != 3) (original->west)->chain(original->getColour(), 2, true, original);
//cout << "passed west ";
      if (original->getY() < 9 && direction != 2) (original->east)->chain(original->getColour(), 3, true, original);
//cout << "passed east " << endl;

      // 4 direction chains of other
      if (other->getX() > 0 && direction != 0) (other->north)->chain(other->getColour(), 0, true, other);
//cout << "passed north ";
      if (other->getX() < 9 && direction != 1) (other->south)->chain(other->getColour(), 1, true, other);
//cout << "passed south ";
      if (other->getY() > 0 && direction != 2) (other->west)->chain(other->getColour(), 2, true, other);
//cout << "passed west ";
      if (other->getY() < 9 && direction != 3) (other->east)->chain(other->getColour(), 3, true, other);
//cout << "passed east" << endl;

      // call crushable
      string typeofOri = crushable(original);
      string typeofOther = crushable(other);
//cout << "  end crushable" << endl;
//cout << "typeofOri = " << typeofOri << endl;
//cout << "typeofOther = " << typeofOther << endl << endl;
      if (typeofOri == "None") {
        original->pop = false;
        original->visit = false;
        
        // reset original chains
        if (original->northSame > 0) {
          (original->north)->chain(original->getColour(), 0, false, original);
        }
        if (original->southSame > 0) {
          (original->south)->chain(original->getColour(), 1, false, original);
        }
        if (original->westSame > 0) {
          (original->west)->chain(original->getColour(), 2, false, original);
        }
        if (original->eastSame > 0) {
          (original->east)->chain(original->getColour(), 3, false, original);
        }
        original->popCount = 0;

      } else {
        int x = original->getX();
        int y = original->getY();
        int oricolour = original->getColour();

        original->crush();
        scoring(original->popCount, 0);
        delete Board[x][y];
        Board[x][y] = NULL;

        if (typeofOri == "Lateral") Board[x][y] = new Lateral("h", oricolour, x, y, Board);
        if (typeofOri == "Upright") Board[x][y] = new Upright("v", oricolour, x, y, Board);
        if (typeofOri == "Unstable") Board[x][y] = new Unstable("b", oricolour, x, y, Board);
        if (typeofOri == "Psychedelic") Board[x][y] = new Psychedelic("p", oricolour, x, y, Board);
//cout << "special squares checked(original)" << endl;
      }

      if (typeofOther == "None") {
        other->pop = false;
        other->visit = false;

        // reset other chains
        if (other->northSame > 0) {
          (other->north)->chain(other->getColour(), 0, false, other);
        }
        if (other->southSame > 0) {
          (other->south)->chain(other->getColour(), 1, false, other);
        }
        if (other->westSame > 0) {
          (other->west)->chain(other->getColour(), 2, false, other);
        }
        if (other->eastSame > 0) {
          (other->east)->chain(other->getColour(), 3, false, other);
        }
        other->popCount = 0;

      } else {
        int x = other->getX();
        int y = other->getY();
        int othcolour = other->getColour();
        
        other->crush();
        scoring(other->popCount, 0);
        delete Board[x][y];
        Board[x][y] = NULL;
        if (typeofOther == "Lateral") Board[x][y] = new Lateral("h", othcolour, x, y, Board);
        if (typeofOther == "Upright") Board[x][y] = new Upright("v", othcolour, x, y, Board);
        if (typeofOther == "Unstable") Board[x][y] = new Unstable("b", othcolour, x, y, Board);
        if (typeofOther == "Psychedelic") Board[x][y] = new Psychedelic("p", othcolour, x, y, Board);
//cout << "special squares checked(other)" << endl;
      }
        
      if (typeofOri == "None" && typeofOther == "None") {
//cout << " NO NO CASE" << endl;
        // swap
        Board[posX][posY] = original;
        Board[posX][posY]->setX(posX);
        Board[posX][posY]->setY(posY);
        if (direction == 0) {
          Board[posX-1][posY] = other;
          Board[posX-1][posY]->setX(posX-1);
          Board[posX-1][posY]->setY(posY);
        } else if (direction == 1) {
          Board[posX+1][posY] = other;
          Board[posX+1][posY]->setX(posX+1);
          Board[posX+1][posY]->setY(posY);
        } else if (direction == 2) {
          Board[posX][posY-1] = other;
          Board[posX][posY-1]->setX(posX);
          Board[posX][posY-1]->setY(posY-1);
        } else if (direction == 3) {
          Board[posX][posY+1] = other;
          Board[posX][posY+1]->setX(posX);
          Board[posX][posY+1]->setY(posY+1);
        }
        cout << "No Matching Squares!" << endl;
        assignNeigh();
      } else {
//cout << "about to clear" << endl;
        clearCrush();
//boardDisplay();
//cout << "before fillin" << endl;
        fillin();
//boardDisplay();
        generate();
//cout << "GENERATE" << endl;
//boardDisplay();
        assignNeigh();
        chainReaction();
//cout << "ALL CHAINREACTION Done" << endl;
        remainingMove--;
        
      }
      
    } else {
      cerr << "Invalid Swap Position" << endl;
    }
  } else {
    cerr << "Invalid Position" << endl;
  }
}








//***********************************************************
int Game::getLevel() {
	return level;
}

void Game::setLevel(int num) {
	level = num;
}

unsigned int Game::getScore() {
	return score;
}

void Game::setScore(unsigned int num) {
	score = num;
}

int Game::getRemainingMove() {
	return remainingMove;
}

void Game::setRemainingMove(int num) {
	remainingMove = num;
}

unsigned int Game::getHighScore() {
	return highScore;
}

void Game::setHighScore(unsigned int num) {
	highScore = num;
}

int Game::getLockedSquare() {
	return lockedSquare;
}

void Game::setLockedSquare(int num) {
	lockedSquare = num;
}

string Game::getFileName() {
	return filename;
}

void Game::setFileName(string name) {
	filename = name;
}

Square** Game::getBoard() {
	return *Board;
}



void Game::boardDisplay() {
	cout << "Level: " << level << endl;
	cout << "Score: " << score << endl;
	cout << "Moves Remaining: " << remainingMove << endl;
	cout << "Hi Score: " << highScore << endl;
	cout << "--------------------------------" << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
            if (lockedBoard[i][j] == false) {
              cout << "_";
            } else {
              cout << "l";
            }
			if (Board[i][j] == NULL) {
                cout << "__ ";
            }
            else {
                cout << Board[i][j]->getType() << Board[i][j]->getColour() << " ";
            }
		}
		cout << endl;
	}
}

// Destructor
Game::~Game() {}
