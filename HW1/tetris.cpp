#include "tetris.h"
#include <chrono>
#include <thread>
//constructors
Tetris::Tetris() : m_width(10), m_height(20) {
	std::vector <char> temp_v(20,'.');
	for(int i=0; i<10; i++){
		m_board.push_back(temp_v);
	}
}
Tetris::Tetris(int w) : m_width(w), m_height(20) {
	std::vector <char> temp_v(20,'.');
	for(int i=0; i<w; i++){
		m_board.push_back(temp_v);
	}
}
Tetris::Tetris(int w, int h) : m_width(w), m_height(h) {
	std::vector<char> temp;
	for(int i=0; i<h; i++){
		temp.push_back('.');
	}
	for(int i=0; i<w; i++){
		m_board.push_back(temp);
	}
}


void Tetris::draw(){
	//empty spaces are indicated with '.'

	std::cout << "\033[2J " << std::endl;
	// std::system("clear");
	for(int h=0; h<m_height; h++){
		for(int w=0; w<m_width; w++){
			std::cout << m_board[w][h] << " ";	
			// std::cout << h  << " ";	
			// std::cout << w  << " ";	

		}
		std::cout << std::endl;
	}
}

int Tetris::getHalfWidth(){
	return m_width/2;
}

int Tetris::add(){
	char temp_type;
	TetrominoType temp_type_enum;

	std::cout << "Enter tetromino type('R' for random, 'Q' to quit):";
	std::cin >> temp_type;

	switch(temp_type){
		case 'i': case 'I':
			temp_type_enum = TetrominoType::I;
			break;
		case 'o': case 'O':
			temp_type_enum = TetrominoType::O;
			break;
		case 't': case 'T':
			temp_type_enum = TetrominoType::T;
			break;
		case 'j': case 'J':
			temp_type_enum = TetrominoType::J;
			break;
		case 'l': case 'L':
			temp_type_enum = TetrominoType::L;
			break;
		case 's': case 'S':
			temp_type_enum = TetrominoType::S;
			break;
		case 'z': case 'Z':
			temp_type_enum = TetrominoType::Z;
			break;
		case 'q': case 'Q':
			return -1;
			break;
		case 'r': case 'R':
			break;
		default:
			std::cout << "Type " << temp_type << "is not a valid type." << std::endl;
			std::cout << "All invalid types will be interpreted as \"O\" tetromino." << std::endl;
			break;
	}

	Tetromino tempTetro(temp_type_enum);
	for(int y=0; y<4; y++){
		for(int x=0;x<4;x++){
			if(m_board[this->getHalfWidth()+x-1][y] != '.'){
				continue;
			}else{
				m_board[this->getHalfWidth()+x-1][y] = tempTetro.getGrid(x,y);
			}
		}
	}
	
	this->draw();
	// tempTetro.print(this->getHalfWidth());


	return 1;
}

int Tetris::animate(){
	while(1){
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		std::vector< std::vector <char> > tempboard;
		std::vector<char> temp;
		for(int i=0; i<m_height; i++){
			temp.push_back('.');
		}
		for(int i=0; i<m_width; i++){
			tempboard.push_back(temp);
		}

		for(int y=0;y<m_height;y++){
			for(int x=0; x<m_width;x++){
				if(m_board[x][y] == '#'){
					tempboard[x][y] = '#';
				}
			}
	}

		for(int y=m_height-1;y>=0;y--){
			for(int x=0;x<m_width;x++){
				
				if(m_board[x][y] != '.' && m_board[x][y] != '#'){
					if(y==m_height-1 || m_board[x][y+1] == '#'){
						this->draw();
						return-1;
					}
					tempboard[x][y+1] = m_board[x][y];
				}
			}
		}
		m_board = tempboard;
		this->draw();

	}
	
	// for(int y=0;y<m_height;y++){
		// for(int x=0;x<m_width;x++){
			// if(m_board[x][y] != '.') m_board[x][y] = '#';
		// }
	// }

}

void Tetris::makePerm(){
	for(int y=0;y<m_height;y++){
		for(int x=0; x<m_width;x++){
			if(m_board[x][y] != '.' && m_board[x][y] != '#'){
				m_board[x][y] = '#';
			}
		}
	}
}