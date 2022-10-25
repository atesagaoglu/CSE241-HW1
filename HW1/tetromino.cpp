// class implementations

#include "tetromino.h"
#include <iostream>
#include <cmath> 

Tetromino::Tetromino() : m_type(TetrominoType::O) { // no param. constructor inits to o type by default
	for(int i=0; i<2; i++){
		for(int j=1; j<3; j++){
			m_grid[i][j] = 'O';
		}
	}
	this->shiftTetro();
}

Tetromino::Tetromino(TetrominoType type) : m_type(type) { // only need 1 parameter to construct the tetromino object
	switch(type){
		case TetrominoType::I:
			for(int i=0; i<4; i++) m_grid[2][i] = 'I';
			break;
		case TetrominoType::O:
			for(int i=0; i<2; i++){
				for(int j=1; j<3; j++){
					m_grid[j][i] = 'O';
				}
			}
			break;
		case TetrominoType::T:
			for(int i=1; i<4; i++){
				m_grid[i][0] = 'T';
			}
			m_grid[2][1] = 'T';
			break;
		case TetrominoType::J:
			for(int i=0; i<3; i++){
				m_grid[2][i] = 'J';
			}
			m_grid[1][2] = 'J';
			break;
		case TetrominoType::L:
			for(int i=0; i<3; i++){
				m_grid[2][i] = 'L';
			}
			m_grid[3][2] = 'L';
			break;
		case TetrominoType::S:
			m_grid [2][0] = 'S'; 
			m_grid [3][0] = 'S';
			m_grid [1][1] = 'S';
			m_grid [2][1] = 'S';
			break;
		case TetrominoType::Z:
			m_grid [1][0] = 'Z';
			m_grid [2][0] = 'Z';
			m_grid [2][1] = 'Z';
			m_grid [3][1] = 'Z';
			break;
	}
	this->shiftTetro();
}

void Tetromino::print() const{
	for(int y=0; y<4; y++){
		for(int x=0; x<4; x++){

			// if(m_grid[x][y] == '.'){
			// 	std::cout << ' ';
			// }else{
				std::cout << m_grid[x][y];
			// }

		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

bool Tetromino::rotate(Direction dir){

	std::vector< std::vector <char> > temp_grid{
		{'.','.','.','.'},
		{'.','.','.','.'},
		{'.','.','.','.'},
		{'.','.','.','.'}
	};

	if(dir == Direction::right){ // Clockwise rotation
		for(int ny=0; ny<4; ny++){
			for(int nx=0; nx<4; nx++){
				temp_grid[nx][ny] = m_grid[ny][3-nx];
			}
		}
		m_grid = temp_grid;
		this->shiftTetro();
		return true;
	}else if(dir == Direction::left){ // Anti-Clockwise rotaion
		for(int ny=0; ny<4; ny++){
			for(int nx=0; nx<4; nx++){
				temp_grid[nx][ny] = m_grid[3-ny][nx];
			}
		}
		m_grid = temp_grid;
		this->shiftTetro();
		return true;
	}else{ // invalid direction
		return false;
	}
	
}

void Tetromino::setTypeChar(char inp){
	m_type_char = inp;
}

char Tetromino::getTypeChar() const{
	return m_type_char;
};

void Tetromino::shiftTetro(){
	int xi=-1;; // x index of the left-most piece of tetromino inside grid


	for(int x=0; x<4; x++){
		for(int y=0; y<4; y++){
			if(m_grid[x][y]!='.'){
				xi=x;
				break;
			}
		}
		if(xi!=-1) break;
	}

	// std::cout <<xi <<std::endl;
	for(int i=0; i<xi; i++){

		for(int y=0; y<4; y++){
			for(int x=0; x<3; x++){
				std::swap(m_grid[x][y],m_grid[x+1][y]);
			}
		}
	}
}