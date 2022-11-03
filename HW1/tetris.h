#ifndef TETRIS_H
#define TETRIS_H

#include "enums.h"
#include "tetromino.h"
#include <vector>
#include <iostream>

class Tetris{
	public:
		//default parameters set to 10x20, board size of the original tetris
		Tetris();
		Tetris(int w);
		Tetris(int w, int h);

		void draw();
		int add();
		int add(TetrominoType type, Direction dir);
		void fit(Tetromino);
		int animate();

		int getHalfWidth();
		void makePerm();

		int fit();
	private:
		int m_width;
		int m_height;

		TetrominoType m_last_type;

		std::vector< std::vector <char> > m_board;
};

#endif