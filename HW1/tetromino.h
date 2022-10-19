#ifndef TETROMINO_H
#define TETROMINO_H

#include <vector>
#include "enums.h"

class Tetromino {
	public:
		//constructors
		Tetromino(); //no-parameter inits to o tetramino
		Tetromino(TetrominoType type); //no-parameter

		//member functions
		bool rotate(RotationDirection dir);
		bool print();
		//bool canFit();
		//will implement canFit later
	private:
		std::vector<std::vector<char>> grid; //multidimensional vector
		


};

#endif