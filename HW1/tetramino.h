#ifndef TETRAMINO_H
#define TETRAMINO_H

#include <vector>
#include "enums.h"

class Tetramino {
	public:
		//constructors
		Tetramino(); //no-parameter inits to o tetramino
		Tetramino(TetraminoType type); //no-parameter

		//member functions
		bool rotate(RotationDirection dir);
		bool print();
		//bool canFit();
		//will implement canFit later
	private:
		std::vector<std::vector<char>> grid; //multidimensional vector
		


};

#endif