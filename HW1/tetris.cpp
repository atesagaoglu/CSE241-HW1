#include "tetris.h"
//constructors
Tetris::Tetris() : m_width(10), m_height(20) {
	std::vector <char> temp_v(10,'.');
	for(int i=0; i<20; i++){
		m_board.push_back(temp_v);
	}
}
Tetris::Tetris(int w) : m_width(w), m_height(20) {
	std::vector <char> temp_v(w,'.');
	for(int i=0; i<20; i++){
		m_board.push_back(temp_v);
	}
}
Tetris::Tetris(int w, int h) : m_width(w), m_height(h) {
	std::vector <char> temp_v(w,'.');
	for(int i=0; i<h; i++){
		m_board.push_back(temp_v);
	}
}


void Tetris::draw(){
	//empty spaces are indicated with '.'

	std::cout << "\033[3J " << std::endl;

	for(int h=0; h<m_height; h++){
		for(int w=0; w<m_width; w++){
			std::cout << m_board[h][w];	
		}
		std::cout << std::endl;
	}
}

int Tetris::getHalfWidth(){
	return m_width/2;
}