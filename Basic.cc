#include "Basic.h"
#include <string>

using namespace std;

Basic::Basic(string type, int colour, int positionX, int positionY, bool pop, int popCount,
             int eastSame, int westSame, int southSame, int northSame,
             Square* east, Square* west, Square* south, Square* north, bool visit): 
  Square(type, colour, positionX, positionY, pop, popCount, eastSame, westSame, southSame, northSame, 
         east, west, south, north, visit)  {}
/*Basic::Basic(string type, int colour, int positionX, int positionY) : 
  Square(type, colour, positionX, positionY)  {}
*/

//Basic::Basic(const Basic &b) : Square(b) {}

void Basic::crush() {
  pop = true;
  visit = true;
}

Basic::~Basic() {}
