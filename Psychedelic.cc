#include <string>
#include "Psychedelic.h"
#include <iostream>
using namespace std;

Psychedelic::Psychedelic(string type, int colour, int positionX, int positionY, Square*** brd, bool pop, int popCount,
             int eastSame, int westSame, int southSame, int northSame,
             Square* east, Square* west, Square* south, Square* north, bool visit): 
  Square(type, colour, positionX, positionY, pop, popCount, eastSame, westSame, southSame, northSame, 
         east, west, south, north, visit), brd(brd) {}

void Psychedelic::crush() {
  for (int i=0; i<10; ++i) {
    for (int j=0; j<10; ++j) {
      if (brd[i][j] != NULL && (i!=positionX || j!=positionY) && brd[i][j]->getColour() == colour) {
        if (brd[i][j]->visit == false) {
          popCount++;
          brd[i][j]->visit = true;
          brd[i][j]->crush();
        }
      }
    }
  }
  pop = true;
}

Psychedelic::~Psychedelic() {}
