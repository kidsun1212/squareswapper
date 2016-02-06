#include "Square.h"
#include <string>
#include <iostream>

using namespace std;

// Ctor
Square::Square(string type, int colour, int positionX, int positionY, bool pop, int popCount,
               int northSame, int southSame, int westSame, int eastSame,
               Square* north, Square* south, Square* west, Square* east, bool visit): 
  type(type), colour(colour), positionX(positionX), positionY(positionY), pop(pop), popCount(popCount),
  northSame(northSame), southSame(southSame), westSame(westSame), eastSame(eastSame), visit(visit)  {}

Square::Square(const Square &sq) : type(sq.type), colour(sq.colour), positionX(sq.positionX), 
  positionY(sq.positionY), pop(sq.pop), popCount(sq.popCount), northSame(sq.northSame), 
  southSame(sq.southSame), westSame(sq.westSame), eastSame(sq.eastSame), visit(sq.visit) {}

void Square::chain(int crushColour, int direction, bool crushed, Square *oriSquare) {
//cout << "chain call" << endl;
  if (crushColour == colour) {
//cout << "chain same colour" << endl;
    pop = crushed;
    visit = crushed;
    if (crushed) {
      ++oriSquare->popCount;
    } else {
      --oriSquare->popCount;
    }

    if (direction == 0) {
      if (crushed) {
        ++oriSquare->northSame;
      } else {
        --oriSquare->northSame;
      }
      if (positionX > 0) north->chain(crushColour, 0, crushed, oriSquare);
    
    } else if (direction == 1) {
      if (crushed) {
        ++oriSquare->southSame;
      } else {
        --oriSquare->southSame;
      }
      if (positionX < 9) south->chain(crushColour, 1, crushed, oriSquare);
    
    } else if (direction == 2) {
      if (crushed) {
        ++oriSquare->westSame;
      } else {
        --oriSquare->westSame;
      }
      if (positionY > 0) west->chain(crushColour, 2, crushed, oriSquare);
    
    } else if (direction == 3) {
      if (crushed) {
        ++oriSquare->eastSame;
      } else {
        --oriSquare->eastSame;
      }
      if (positionY < 9) east->chain(crushColour, 3, crushed, oriSquare);
    }
  }
//cout << "chain exit" << endl;

}

void Square::chainCheck(int crushColour, int direction, Square *oriSquare) {
  if (oriSquare->getColour() == getColour()) {
    ++oriSquare->popCount;

    if (direction == 0) {
      ++oriSquare->northSame;
      if (positionX > 0) north->chainCheck(crushColour, 0, oriSquare);
    
    } else if (direction == 1) {
      ++oriSquare->southSame;
      if (positionX < 9) south->chainCheck(crushColour, 1, oriSquare);
    
    } else if (direction == 2) {
      ++oriSquare->westSame;
      if (positionY > 0) west->chainCheck(crushColour, 2, oriSquare);
    
    } else if (direction == 3) {
      ++oriSquare->eastSame;
      if (positionY < 9) east->chainCheck(crushColour, 3, oriSquare);
    }
  }
}

void Square::setType(string squareType) {
    type = squareType;
}

string Square::getType() {
    return type;
}

void Square::setColour(int newColour) {
    colour = newColour;
}

int Square::getColour() {
	return colour;
}

void Square::setX(int newX) {
    positionX = newX;
}

int Square::getX() {
    return positionX;
}

void Square::setY(int newY) {
    positionY = newY;
}

int Square::getY() {
    return positionY;
}

// Destructor
Square::~Square() {}
