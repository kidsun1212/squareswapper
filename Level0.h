#ifndef __LEVEL0_H__
#define __LEVEL0_H__
#include <string>
#include <sstream>
#include "Game.h"
#include "Square.h"

class Level0: public Game{
	protected:
		unsigned int startScore;
 	public:
  		Level0(int, unsigned int, int, unsigned int, int, bool**, Square***, std::string);
//  		Level0(int, unsigned int, int, unsigned int, int, Square***, std::string);
  		void boardGenerator(int);
  		void lockedBoardGenerator();
  		bool winningCondition();
  		void generate();
  		~Level0();
};

#endif
