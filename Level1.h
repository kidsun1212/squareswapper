#ifndef __LEVEL1_H__
#define __LEVEL1_H__
#include <string>
#include "Game.h"
#include "Square.h"

class Level1: public Game{
	protected:
 		double startScore;
 	public:
  		//Level1(int, unsigned int, int, unsigned int, int, Square***, std::string);
  		Level1(int, unsigned int, int, unsigned int, int, bool**, Square***, std::string);
  		void boardGenerator(int);
  		void lockedBoardGenerator();
  		bool winningCondition();
  		void generate();
  		~Level1();
};

#endif
