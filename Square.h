#ifndef __SQUARE_H__
#define __SQUARE_H__
#include <string>

class Square {
    protected:
        std::string type;
        int colour;
        int positionX;
        int positionY;
    public:
        bool pop;
        int popCount;
        
        int northSame;
        int southSame;
        int westSame;
        int eastSame;

        Square * north;
        Square * south;
        Square * west;
        Square * east;
        
        bool visit;
        
        Square(std::string, int, int, int, bool, int, int, int, int, int, Square *, Square *, Square *, Square *, bool);
        Square(const Square&);
       // Square &operator=(const Basic&);
        
        void chain(int, int, bool, Square*);
        void chainCheck(int, int, Square*);
        virtual void crush() = 0;

        void setType(std::string);
        std::string getType();
        void setColour(int);
        int getColour();
        void setX(int);
        int getX();
        void setY(int);
        int getY();

        virtual ~Square() = 0;
};

#endif
