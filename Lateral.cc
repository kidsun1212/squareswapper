#include <string>
#include "Lateral.h"

using namespace std;

Lateral::Lateral(string type, int colour, int positionX, int positionY, Square*** brd, bool pop, int popCount,
             int eastSame, int westSame, int southSame, int northSame,
             Square* east, Square* west, Square* south, Square* north, bool visit): 
  Square(type, colour, positionX, positionY, pop, popCount, eastSame, westSame, southSame, northSame, 
         east, west, south, north, visit), brd(brd) {}

void Lateral::crush() {
  for (int i=0; i<10; ++i) {
    if (i!=positionY) {
      if (brd[positionX][i] != NULL && brd[positionX][i]->visit == false) {
        ++popCount;
        brd[positionX][i]->visit = true;
        brd[positionX][i]->crush();
      }
    }
  }
  pop = true;
}

Lateral::~Lateral() {}
