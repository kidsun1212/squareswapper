#ifndef __UPRIGHT_H__
#define __UPRIGHT_H__
#include <string>
#include "Square.h"

class Upright: public Square {
        Square*** brd;
 	public:
        Upright(std::string type, int colour, int positionX, int positionY, Square*** brd, bool pop=0, int popCount=0,
             int eastSame=0, int westSame=0, int southSame=0, int northSame=0,
             Square* east=NULL, Square* west=NULL, Square* south=NULL, Square* north=NULL, bool visit=0);
        void crush();
        ~Upright();
};

#endif
