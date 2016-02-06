#ifndef __BASIC_H__
#define __BASIC_H__
#include <string>
#include "Square.h"

class Basic: public Square {
 	public:
        Basic(std::string type, int colour, int positionX, int positionY, bool pop=0, int popCount=0,
             int eastSame=0, int westSame=0, int southSame=0, int northSame=0,
             Square* east=NULL, Square* west=NULL, Square* south=NULL, Square* north=NULL, bool visit=0);
        //Basic(const Basic &basic);
        void crush();
        ~Basic();
};

#endif
