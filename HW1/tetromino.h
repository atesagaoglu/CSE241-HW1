//class defs

#ifndef TETROMINO_H
#define TETROMINO_H

#include <vector>
#include "enums.h"

class Tetromino {
	public:
		Tetromino();
		Tetromino(TetrominoType type);

		void setTypeChar(char inp);
		char getTypeChar() const;

		bool rotate(Direction dir);
		void print() const;
		bool canFit(Pos other);

		void shiftTetro();

	private:
		TetrominoType m_type;
		char m_type_char;
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