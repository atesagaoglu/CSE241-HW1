//class defs

#ifndef TETROMINO_H
#define TETROMINO_H

#include <vector>
#include "enums.h"

class Tetromino {
	public:
		Tetromino();
		Tetromino(TetrominoType type);

		bool rotate(RotationDirection dir);
		bool print() const;
		// bool canFit(Pos other);
	private:
		TetrominoType m_type;
		std::vector< std::vector<char> > m_grid{
			{'.','.','.','.'},
			{'.','.','.','.'},
			{'.','.','.','.'},
			{'.','.','.','.'}
		};
		// initialize 4x4 vector with '.' representing empty spaces
		// constructor function will simply change .'s to characters that represent a particular tetrmino
};

#endif