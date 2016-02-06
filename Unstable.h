#ifndef __UNSTABLE_H__
#define __UNSTABLE_H__
#include <string>
#include "Square.h"

class Unstable: public Square {
        Square*** brd;
        void incPopCount(int x, int y);
 	public:
        Unstable(std::string type, int colour, int positionX, int positionY, Square*** brd, bool pop=0, int popCount=0,
             int eastSame=0, int westSame=0, int southSame=0, int northSame=0,
             Square* east=NULL, Square* west=NULL, Square* south=NULL, Square* north=NULL, bool visit=0);
        void crush();
        ~Unstable();
};

#endif
