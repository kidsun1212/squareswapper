#include <string>
#include "Upright.h"

using namespace std;

Upright::Upright(string type, int colour, int positionX, int positionY, Square*** brd, bool pop, int popCount,
             int eastSame, int westSame, int southSame, int northSame,
             Square* east, Square* west, Square* south, Square* north, bool visit): 
  Square(type, colour, positionX, positionY, pop, popCount, eastSame, westSame, southSame, northSame, 
         east, west, south, north, visit), brd(brd) {}

void Upright::crush() {
  for (int i=0; i<10; ++i) {
    if (i!=positionX) {
      if (brd[i][positionY] != NULL && brd[i][positionY]->visit == false) {
        ++popCount;
        brd[i][positionY]->visit = true;
        brd[i][positionY]->crush();
      }
    }
  }
  pop = true;
}

Upright::~Upright() {}
