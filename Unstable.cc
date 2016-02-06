#include <string>
#include "Unstable.h"

using namespace std;

Unstable::Unstable(string type, int colour, int positionX, int positionY, Square*** brd, bool pop, int popCount,
             int eastSame, int westSame, int southSame, int northSame,
             Square* east, Square* west, Square* south, Square* north, bool visit): 
  Square(type, colour, positionX, positionY, pop, popCount, eastSame, westSame, southSame, northSame, 
         east, west, south, north, visit), brd(brd) {}

/*void Unstable::incPopCount(int x, int y) {
  if (brd[x][y]->visit == false) {
    popCount++;
    brd[x][y]->visit = true;
  }
}*/

void Unstable::crush() {
  int horizontal = 1;
  int vertical = 1;
  int X = positionX;
  int Y = positionY;

  if (north != NULL && north->getColour() == colour) {
    vertical++;
    if (north->north != NULL && (north->north)->getColour() == colour) {
      vertical++;
      if ((north->north)->north != NULL && ((north->north)->north)->getColour() == colour) {
        vertical++;
        if (((north->north)->north)->north != NULL && (((north->north)->north)->north)->getColour() == colour) {
          vertical++;
        }
      }
    }
  }
  if (south != NULL && south->getColour() == colour) {
    vertical++;
    if (south->south != NULL && (south->south)->getColour() == colour) {
      vertical++;
      if ((south->south)->south != NULL && ((south->south)->south)->getColour() == colour) {
        vertical++;
        if (((south->south)->south)->south != NULL && (((south->south)->south)->south)->getColour() == colour) {
          vertical++;
        }
      }
    }
  }
  if (west != NULL && west->getColour() == colour) {
    horizontal++;
    if (west->west != NULL && (west->west)->getColour() == colour) {
      horizontal++;
      if ((west->west)->west != NULL && ((west->west)->west)->getColour() == colour) {
        horizontal++;
        if (((west->west)->west)->west != NULL && (((west->west)->west)->west)->getColour() == colour) {
          horizontal++;
        }
      }
    }
  }
  if (east != NULL && east->getColour() == colour) {
    horizontal++;
    if (east->east != NULL && (east->east)->getColour() == colour) {
      horizontal++;
      if ((east->east)->east != NULL && ((east->east)->east)->getColour() == colour) {
        horizontal++;
        if (((east->east)->east)->east != NULL && (((east->east)->east)->east)->getColour() == colour) {
          horizontal++;
        }
      }
    }
  }
  
  if (horizontal > 3 || vertical > 3) {   // 5X5
    for (int i=X-2; i<=X+2; i++) {
      for (int j=Y-2; j<=Y+2; j++) {
        if (i>=0 && i<=9 && j>=0 && j<=9 && (i!=X || j!=Y)) {
          if (brd[i][j] != NULL && brd[i][j]->visit == false) {
            popCount++;
            brd[i][j]->visit = true;
            brd[i][j]->crush();
          }
        }
      }
    }
/*
    if (X>1 && X<8 && Y>1 && Y<8) {
      for (int i=X-2; i<=X+2; i++) {
        incPopCount(i, Y-2);
        brd[i][Y-2]->crush();
        incPopCount(i, Y-1);
        brd[i][Y-1]->crush();
      }
      incPopCount(X-2, Y);
      brd[X-2][Y]->crush();
      incPopCount(X-1, Y);
      brd[X-1][Y]->crush();
      pop = true;
      incPopCount(X+1, Y);
      brd[X+1][Y]->crush();
      incPopCount(X+2, Y);
      brd[X+2][Y]->crush();
      for (int i=X-2; i<=X+2; i++) {
        incPopCount(i, Y+1);
        brd[i][Y+1]->crush();
        incPopCount(i, Y+2);
        brd[i][Y+2]->crush();
      }

    } else if (X==0 && Y==0) {
      pop = true;
      incPopCount(X+1, Y);
      brd[X+1][Y]->crush();
      incPopCount(X+2, Y);
      brd[X+2][Y]->crush();
      for (int i=0; i<=2; ++i) {
        incPopCount(i, 1);
        brd[i][1]->crush();
        incPopCount(i, 2);
        brd[i][2]->crush();
      }
    } else if (X==1 && Y==0) {
      incPopCount(X-1, Y);
      brd[X-1][Y]->crush();
      pop = true;
      incPopCount(X+1, Y);
      brd[X+1][Y]->crush();
      incPopCount(X+2, Y);
      brd[X+2][Y]->crush();
      for (int i=0; i<=3; ++i) {
        incPopCount(i, 1);
        brd[i][1]->crush();
        incPopCount(i, 2);
        brd[i][2]->crush();
      }
    } else if (X==0 && Y==1) {
      for (int i=0; i<=2; ++i) {
        incPopCount(i, Y-1);
        brd[i][Y-1]->crush();
      }
      pop = true;
      incPopCount(X+1, Y);
      brd[X+1][Y]->crush();
      incPopCount(X+2, Y);
      brd[X+2][Y]->crush();
      for (int i=0; i<=2; ++i) {
        incPopCount(i, 2);
        brd[i][2]->crush();
        incPopCount(i, 3);
        brd[i][3]->crush();
      }
    } else if (X==1 && Y==1) {
      for (int i=0; i<=3; ++i) {
        incPopCount(i, Y-1);
        brd[i][Y-1]->crush();
      }
      incPopCount(X-1, Y);
      brd[X-1][Y]->crush();
      pop = true;
      incPopCount(X+1, Y);
      brd[X+1][Y]->crush();
      incPopCount(X+2, Y);
      brd[X+2][Y]->crush();
      for (int i=0; i<=3; ++i) {
        incPopCount(i, 2);
        brd[i][2]->crush();
        incPopCount(i, 3);
        brd[i][3]->crush();
      }
    } else if (X==8 && Y==0) {
      incPopCount(X-2, Y);
      brd[X-2][Y]->crush();
      incPopCount(X-1, Y);
      brd[X-1][Y]->crush();
      pop = true;
      incPopCount(X+1, Y);
      brd[X+1][Y]->crush();
      for (int i=6; i<=9; ++i) {
        incPopCount(i, 1);
        brd[i][1]->crush();
        incPopCount(i, 2);
        brd[i][2]->crush();
      }
    } else if (X==9 && Y==0) {
      incPopCount(X-2, Y);
      brd[X-2][Y]->crush();
      incPopCount(X-1, Y);
      brd[X-1][Y]->crush();
      pop = true;
      for (int i=7; i<=9; ++i) {
        incPopCount(i, 1);
        brd[i][1]->crush();
        incPopCount(i, 2);
        brd[i][2]->crush();
      }
    } else if (X==8 && Y==1) {
      for (int i=6; i<=9; ++i) {
        incPopCount(i, Y-1);
        brd[i][Y-1]->crush();
      }
      incPopCount(X-2, Y);
      brd[X-2][Y]->crush();
      incPopCount(X-1, Y);
      brd[X-1][Y]->crush();
      pop = true;
      incPopCount(X+1, Y);
      brd[X+1][Y]->crush();
      for (int i=6; i<=9; ++i) {
        incPopCount(i, 2);
        brd[i][2]->crush();
        incPopCount(i, 3);
        brd[i][3]->crush();
      }
    } else if (X==9 && Y==1) {
      for (int i=7; i<=9; ++i) {
        incPopCount(i, Y-1);
        brd[i][Y-1]->crush();
      }
      incPopCount(X-2, Y);
      brd[X-2][Y]->crush();
      incPopCount(X-1, Y);
      brd[X-1][Y]->crush();
      pop = true;
      for (int i=7; i<=9; ++i) {
        incPopCount(i, 2);
        brd[i][2]->crush();
        incPopCount(i, 3);
        brd[i][3]->crush();
      }
    } else if (X==0 && Y==8) {
      for (int i=0; i<=2; ++i) {
        incPopCount(i, 6);
        brd[i][6]->crush();
        incPopCount(i, 7);
        brd[i][7]->crush();
      }
      pop = true;
      incPopCount(X+1, Y);
      brd[X+1][Y]->crush();
      incPopCount(X+2, Y);
      brd[X+2][Y]->crush();
      for (int i=0; i<=2; ++i) {
        incPopCount(i, Y+1);
        brd[i][Y+1]->crush();
      }
    } else if (X==1 && Y==8) {
      for (int i=0; i<=3; ++i) {
        incPopCount(i, 6);
        brd[i][6]->crush();
        incPopCount(i, 7);
        brd[i][7]->crush();
      }
      incPopCount(X-1, Y);
      brd[X-1][Y]->crush();
      pop = true;
      incPopCount(X+1, Y);
      brd[X+1][Y]->crush();
      incPopCount(X+2, Y);
      brd[X+2][Y]->crush();
      for (int i=0; i<=3; ++i) {
        incPopCount(i, Y+1);
        brd[i][Y+1]->crush();
      }
    } else if (X==0 && Y==9) {
      for (int i=0; i<=2; ++i) {
        incPopCount(i, 7);
        brd[i][7]->crush();
        incPopCount(i, 8);
        brd[i][8]->crush();
      }
      pop = true;
      incPopCount(X+1, Y);
      brd[X+1][Y]->crush();
      incPopCount(X+2, Y);
      brd[X+2][Y]->crush();
    } else if (X==1 && Y==9) {
      for (int i=0; i<=3; ++i) {
        incPopCount(i, 7);
        brd[i][7]->crush();
        incPopCount(i, 8);
        brd[i][8]->crush();
      }
      incPopCount(X-1, Y);
      brd[X-1][Y]->crush();
      pop = true;
      incPopCount(X+1, Y);
      brd[X+1][Y]->crush();
      incPopCount(X+2, Y);
      brd[X+2][Y]->crush();
    } else if (X==8 && Y==8) {
      for (int i=6; i<=9; ++i) {
        incPopCount(i, 6);
        brd[i][6]->crush();
        incPopCount(i, 7);
        brd[i][7]->crush();
      }
      incPopCount(X-2, Y);
      brd[X-2][Y]->crush();
      incPopCount(X-1, Y);
      brd[X-1][Y]->crush();
      pop = true;
      incPopCount(X+1, Y);
      brd[X+1][Y]->crush();
      for (int i=6; i<=9; ++i) {
        incPopCount(i, Y+1);
        brd[i][Y+1]->crush();
      }
    } else if (X==9 && Y==8) {
      for (int i=7; i<=9; ++i) {
        incPopCount(i, 6);
        brd[i][6]->crush();
        incPopCount(i, 7);
        brd[i][7]->crush();
      }
      incPopCount(X-2, Y);
      brd[X-2][Y]->crush();
      incPopCount(X-1, Y);
      brd[X-1][Y]->crush();
      pop = true;
      for (int i=7; i<=9; ++i) {
        incPopCount(i, Y+1);
        brd[i][Y+1]->crush();
      }
    } else if (X==8 && Y==9) {
      for (int i=6; i<=9; ++i) {
        incPopCount(i, 7);
        brd[i][7]->crush();
        incPopCount(i, 8);
        brd[i][8]->crush();
      }
      incPopCount(X-2, Y);
      brd[X-2][Y]->crush();
      incPopCount(X-1, Y);
      brd[X-1][Y]->crush();
      pop = true;
      incPopCount(X+1, Y);
      brd[X+1][Y]->crush();
    } else if (X==9 && Y==9) {
      for (int i=7; i<=9; ++i) {
        incPopCount(i, 7);
        brd[i][7]->crush();
        incPopCount(i, 8);
        brd[i][8]->crush();
      }
      incPopCount(X-2, Y);
      brd[X-2][Y]->crush();
      incPopCount(X-1, Y);
      brd[X-1][Y]->crush();
      pop = true;

    } else if (X==0) {
      incPopCount(X, Y-2);
      brd[X][Y-2]->crush();
      incPopCount(X, Y-1);
      brd[X][Y-1]->crush();
      pop = true;
      incPopCount(X, Y+1);
      brd[X][Y+1]->crush();
      incPopCount(X, Y+2);
      brd[X][Y+2]->crush();
      for (int i=Y-2; i<=Y+2; ++i) {
        incPopCount(1, i);
        brd[1][i]->crush();
        incPopCount(2, i);
        brd[2][i]->crush();
      }
    } else if (X==1) {
      for (int i=Y-2; i<=Y+2; ++i) {
        incPopCount(0, i);
        brd[0][i]->crush();
      }
      incPopCount(X, Y-2);
      brd[X][Y-2]->crush();
      incPopCount(X, Y-1);
      brd[X][Y-1]->crush();
      pop = true;
      incPopCount(X, Y+1);
      brd[X][Y+1]->crush();
      incPopCount(X, Y+2);
      brd[X][Y+2]->crush();
      for (int i=Y-2; i<=Y+2; ++i) {
        incPopCount(2, i);
        brd[2][i]->crush();
        incPopCount(3, i);
        brd[3][i]->crush();
      }
    } else if (X==8) {
      for (int i=Y-2; i<=Y+2; ++i) {
        incPopCount(6, i);
        brd[6][i]->crush();
        incPopCount(7, i);
        brd[7][i]->crush();
      }
      incPopCount(X, Y-2);
      brd[X][Y-2]->crush();
      incPopCount(X, Y-1);
      brd[X][Y-1]->crush();
      pop = true;
      incPopCount(X, Y+1);
      brd[X][Y+1]->crush();
      incPopCount(X, Y+2);
      brd[X][Y+2]->crush();
      for (int i=Y-2; i<=Y+2; ++i) {
        incPopCount(9, i);
        brd[9][i]->crush();
      }
    } else if (X==9) {
      for (int i=Y-2; i<=Y+2; ++i) {
        incPopCount(7, i);
        brd[7][i]->crush();
        incPopCount(8, i);
        brd[8][i]->crush();
      }
      incPopCount(X, Y-2);
      brd[X][Y-2]->crush();
      incPopCount(X, Y-1);
      brd[X][Y-1]->crush();
      pop = true;
      incPopCount(X, Y+1);
      brd[X][Y+1]->crush();
      incPopCount(X, Y+2);
      brd[X][Y+2]->crush();
    } else if (Y==0) {
      incPopCount(X-2, Y);
      brd[X-2][Y]->crush();
      incPopCount(X-1, Y);
      brd[X-1][Y]->crush();
      pop = true;
      incPopCount(X+1, Y);
      brd[X+1][Y]->crush();
      incPopCount(X+2, Y);
      brd[X+2][Y]->crush();
      for (int i=X-2; i<=X+2; ++i) {
        incPopCount(i, 1);
        brd[i][1]->crush();
        incPopCount(i, 2);
        brd[i][2]->crush();
      }
    } else if (Y==1) {
      for (int i=X-2; i<=X+2; ++i) {
        incPopCount(i, 0);
        brd[i][0]->crush();
      }
      incPopCount(X-2, Y);
      brd[X-2][Y]->crush();
      incPopCount(X-1, Y);
      brd[X-1][Y]->crush();
      pop = true;
      incPopCount(X+1, Y);
      brd[X+1][Y]->crush();
      incPopCount(X+2, Y);
      brd[X+2][Y]->crush();
      for (int i=Y-2; i<=Y+2; ++i) {
        incPopCount(i, 2);
        brd[i][2]->crush();
        incPopCount(i, 3);
        brd[i][3]->crush();
      }
    } else if (Y==8) {
      for (int i=Y-2; i<=Y+2; ++i) {
        incPopCount(i, 6);
        brd[i][6]->crush();
        incPopCount(i, 7);
        brd[i][7]->crush();
      }
      incPopCount(X-2, Y);
      brd[X-2][Y]->crush();
      incPopCount(X-1, Y);
      brd[X-1][Y]->crush();
      pop = true;
      incPopCount(X+1, Y);
      brd[X+1][Y]->crush();
      incPopCount(X+2, Y);
      brd[X+2][Y]->crush();
      for (int i=X-2; i<=X+2; ++i) {
        incPopCount(i, 9);
        brd[i][9]->crush();
      }
    } else if (Y==9) {
      for (int i=Y-2; i<=Y+2; ++i) {
        incPopCount(i, 7);
        brd[i][7]->crush();
        incPopCount(i, 8);
        brd[i][8]->crush();
      }
      incPopCount(X-2, Y);
      brd[X-2][Y]->crush();
      incPopCount(X-1, Y);
      brd[X-1][Y]->crush();
      pop = true;
      incPopCount(X+1, Y);
      brd[X+1][Y]->crush();
      incPopCount(X+2, Y);
      brd[X+2][Y]->crush();
    }*/

  } else {                                // 3X3
    for (int i=X-1; i<=X+1; i++) {
      for (int j=Y-1; j<=Y+1; j++) {
        if (i>=0 && i<=9 && j>=0 && j<=9 && (i!=X || j!=Y)) {
          if (brd[i][j] != NULL && brd[i][j]->visit == false) {
            popCount++;
            brd[i][j]->visit = true;
            brd[i][j]->crush();
          }
        }
      }
    }
/*
    if (X>0 && X<9 && Y>0 && Y<9) {
      for (int i=X-1; i<=X+1; i++) {
        incPopCount(i, Y-1);
        brd[i][Y-1]->crush();
      }
      incPopCount(X-1, Y);
      brd[X-1][Y]->crush();
      pop = true;
      incPopCount(X+1, Y);
      brd[X+1][Y]->crush();
      for (int i=X-1; i<=X+1; i++) {
        incPopCount(i, Y+1);
        brd[i][Y+1]->crush();
      }

    } else if (X==0 && Y==0) {
      incPopCount(0, 1);
      brd[0][1]->crush();
      incPopCount(1, 0);
      brd[1][0]->crush();
      incPopCount(1, 1);
      brd[1][1]->crush();
    } else if (X==9 && Y==0) {
      incPopCount(8, 0);
      brd[8][0]->crush();
      incPopCount(8, 1);
      brd[8][1]->crush();
      incPopCount(9, 1);
      brd[9][1]->crush();
    } else if (X==0 && Y==9) {
      incPopCount(0, 8);
      brd[0][8]->crush();
      incPopCount(1, 8);
      brd[1][8]->crush();
      incPopCount(1, 9);
      brd[1][9]->crush();
    } else if (X==9 && Y==9) {
      incPopCount(8, 8);
      brd[8][8]->crush();
      incPopCount(8, 9);
      brd[8][9]->crush();
      incPopCount(9, 8);
      brd[9][8]->crush();

    } else if (X==0) {
      incPopCount(0, Y-1);
      brd[0][Y-1]->crush();
      for (int i=Y-1; i<=Y+1; ++i) {
        incPopCount(1, i);
        brd[1][i]->crush();
      }
      incPopCount(0, Y+1);
      brd[0][Y+1]->crush();
    } else if (X==9) {
      incPopCount(9, Y-1);
      brd[9][Y-1]->crush();
      for (int i=Y-1; i<=Y+1; ++i) {
        incPopCount(8, i);
        brd[8][i]->crush();
      }
      incPopCount(9, Y+1);
      brd[9][Y+1]->crush();
    } else if (Y==0) {
      incPopCount(X-1, 0);
      brd[X-1][0]->crush();
      for (int i=X-1; i<=X+1; ++i) {
        incPopCount(i, 1);
        brd[i][1]->crush();
      }
      incPopCount(X+1, 0);
      brd[X+1][0]->crush();
    } else if (Y==9) {
      incPopCount(X-1, 9);
      brd[X-1][9]->crush();
      for (int i=X-1; i<=X+1; ++i) {
        incPopCount(i, 8);
        brd[i][8]->crush();
      }
      incPopCount(X+1, 9);
      brd[X+1][9]->crush();
    }*/
  }
  pop = true;
}

Unstable::~Unstable() {}
