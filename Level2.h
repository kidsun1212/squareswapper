#ifndef __LEVEL2_H__
#define __LEVEL2_H__
#include <string>
#include "Game.h"
#include "Square.h"

class Level2: public Game{
	protected:
		double startScore;
	public:
		Level2(int, unsigned int, int, unsigned int, int, bool**, Square***, std::string);
		void boardGenerator(int);
		void lockedBoardGenerator();
		bool winningCondition();
		void generate();
		~Level2();
};

#endif
