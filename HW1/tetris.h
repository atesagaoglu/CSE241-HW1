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

		//draws the current board
		//letters indicate tetromino
		// .'s are free spaces
		// #'s are tetrominos that are placed and not moving anymore
		void draw();
		//adds tetromino to center of top-most row
		int add();
		void fit(Tetromino);
		//falling animation of tetromino
		int animate();

		int getHalfWidth();
		//after a tetromino hits the floor or top of an another tetromino it becomes a permanent piece
		//this way it stayed on its place and didn't move with other tetromino
		void makePerm();

		//lets user to move the piece
		int fit();
		//not working properly
		int add(TetrominoType type, Direction dir);
		
	private:
		int m_width;
		int m_height;

		TetrominoType m_last_type;

		std::vector< std::vector <char> > m_board;
};

#endif