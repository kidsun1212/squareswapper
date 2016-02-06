#ifndef __GAME_H__
#define __GAME_H__
#include <string>
#include "Square.h"


class Game {
	protected:
		int level;
		unsigned int score;
		int remainingMove;
    unsigned int highScore;
		int lockedSquare;
		bool **lockedBoard;
    Square*** Board;
    std::string filename;
 	public:
  		Game(int, unsigned int, int, unsigned int, int, bool**, Square***, std::string);
  		virtual void boardGenerator(int) = 0;
  		virtual void lockedBoardGenerator() = 0;
  		virtual bool winningCondition() = 0;
        virtual void generate() = 0;

      int hint();
  		void scramble();

      void assignNeigh();
      void scoring(int, int);
      void fillin();
      void clearCrush();
      std::string crushable(Square *);
      void chainReaction();
      void swap(int, int, int);


      int getLevel();
      void setLevel(int);
  		unsigned int getScore();
      void setScore(unsigned int);
  		int getRemainingMove();
      void setRemainingMove(int);
  		unsigned int getHighScore();
      void setHighScore(unsigned int);
  		int getLockedSquare();
      void setLockedSquare(int);
      std::string getFileName();
      void setFileName(std::string);

      Square ** getBoard();
      
      
      void boardDisplay();


  		virtual ~Game() = 0;
};

#endif
