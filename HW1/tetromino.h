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
		void print() ;
		void print(int hPos) ; //overloading print function
		//if hpos is given cursor will move hPos tiles to the right and then

		void canFit(); // couldn't implement
		char getGrid(int,int);


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