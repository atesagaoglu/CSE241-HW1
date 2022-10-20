// class implementations

#include "tetromino.h"
#include <iostream>

Tetromino::Tetromino() : m_type(TetrominoType::O) { // no param. constructor inits to o type by default
	for(int i=0; i<2; i++){
		for(int j=1; j<3; j++){
			m_grid[i][j] = 'O';
		}
	}
}

Tetromino::Tetromino(TetrominoType type) : m_type(type) { // only need 1 parameter to construct the tetromino object
	switch(type){
		case TetrominoType::I:
			for(int i=0; i<4; i++) m_grid[3][i] = 'I';
			break;
		case TetrominoType::O:
			for(int i=0; i<2; i++){
				for(int j=1; j<3; j++){
					m_grid[i][j] = 'O';
				}
			}
			break;
		case TetrominoType::T:
			for(int i=1; i<4; i++){
				m_grid[0][i] = 'T';
			}
			m_grid[1][2] = 'T';
			break;
		case TetrominoType::J:
			for(int i=0; i<3; i++){
				m_grid[2][i] = 'J';
			}
			m_grid[1][2] = 'J';
			break;
		case TetrominoType::L:
			for(int i=0; i<3; i++){
				m_grid[2][i] = 'l';
			}
			m_grid[1][3] = 'L';
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
			m_grid [2][2] = 'Z';
			break;
	}
}

bool Tetromino::print() const{
	for(int x=0; x<4; x++){
		for(int y=0; y<4; y++){
			std::cout << m_grid[x][y];
		}
		std::cout << std::endl;
	}
}

bool Tetromino::rotate(RotationDirection dir){

	std::vector< std::vector <char> > temp_grid{
		{'.','.','.','.'},
		{'.','.','.','.'},
		{'.','.','.','.'},
		{'.','.','.','.'}
	};

	if(dir == RotationDirection::right){ // Clockwise rotation
		for(int ny=0; ny<4; ny++){
			for(int nx=0; nx<4; nx++){
				temp_grid[nx][ny] = m_grid[ny][3-nx];
			}
		}
		return true;
	}else if(dir == RotationDirection::left){ // Anti-Clockwise rotaion
		for(int ny=0; ny<4; ny++){
			for(int nx=0; nx<4; nx++){
				temp_grid[nx][ny] = m_grid[3-ny][nx];
			}
		}
		return true;
	}else{ // invalid direction
		return false;
	}
	
}