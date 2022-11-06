#include "tetris.h"
#include <chrono>
#include <thread>
//constructors
Tetris::Tetris(int w, int h) : m_width(w), m_height(h) {
	std::vector<char> temp;
	for(int i=0; i<h; i++){
		temp.push_back('.');
	}
	for(int i=0; i<w; i++){
		m_board.push_back(temp);
	}
}
Tetris::Tetris() : Tetris(20,20) {
}
Tetris::Tetris(int w) : Tetris(w,20) {}


void Tetris::draw(){
	//empty spaces are indicated with '.'
	//clear terminal escape sequance
	std::cout << "\033[2J " << std::endl;

	for(int h=0; h<m_height; h++){
		for(int w=0; w<m_width; w++){
			std::cout << m_board[w][h] << " ";	
			// std::cout << h  << " ";	
			// std::cout << w  << " ";	

		}
		std::cout << std::endl;
	}
}
//to find the center
int Tetris::getHalfWidth(){
	return m_width/2;
}

int Tetris::add(){
	//creates the tetromino object that will added to the board
	char temp_type;
	TetrominoType temp_type_enum;

	std::cout << "Enter tetromino type('R' for random, 'Q' to quit):";
	std::cin >> temp_type;

	std::vector <TetrominoType> types{
		TetrominoType::I,
		TetrominoType::O,
		TetrominoType::T,
		TetrominoType::T,
		TetrominoType::J,
		TetrominoType::L,
		TetrominoType::S,
		TetrominoType::Z
	};
	int num;
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
			srand(time(NULL));
		
			num = rand()%8;
			
			temp_type_enum = types.at(num);

			break;
		
		default:
			std::cout << "Type " << temp_type << "is not a valid type." << std::endl;
			std::cout << "All invalid types will be interpreted as \"O\" tetromino." << std::endl;
			break;
	}
	//place tetromino to the center of the top row
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
	//draws after adding the tetromino
	this->draw();
	m_last_type = temp_type_enum;
	return 1;
}

int Tetris::animate(){
	while(1){
		//sleeps half a second
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		//creates a temporary board
		//to move blocks i copied every block in original block to temporary board with their next positions
		//after that i copied tempboard back to the original board
		std::vector< std::vector <char> > tempboard;
		std::vector<char> temp;
		//creates a new board with all empty spaces
		for(int i=0; i<m_height; i++){
			temp.push_back('.');
		}
		for(int i=0; i<m_width; i++){
			tempboard.push_back(temp);
		}
		//copies permanent blocks
		for(int y=0;y<m_height;y++){
			for(int x=0; x<m_width;x++){
				if(m_board[x][y] == '#'){
					tempboard[x][y] = '#';
				}
			}
		}
		//exits animate function if falling ttetromino hits ground or another tetromino
		//starts looking from the bottom of board
		for(int y=m_height-1;y>=0;y--){
			for(int x=0;x<m_width;x++){
				//ignore empty spaces and permanent blocks
				if(m_board[x][y] != '.' && m_board[x][y] != '#'){
					//first part detects ground second part detetcs another tetromino
					if(y==m_height-1 || m_board[x][y+1] == '#'){
						//draw and exit 
						this->draw();
						return-1;
					}
					//if didn't hit anywhere update board or animation
					tempboard[x][y+1] = m_board[x][y];
				}
			}
		}
		//copy back to the original board
		m_board = tempboard;
		this->draw();

	}

}
//after animate method makePerm checks the board and turns tetromino to permanent block
void Tetris::makePerm(){
	for(int y=0;y<m_height;y++){
		for(int x=0; x<m_width;x++){
			if(m_board[x][y] != '.' && m_board[x][y] != '#'){
				m_board[x][y] = '#';
			}
		}
	}
}
//moves tetromino before falling
//rotate doens't work properly
int Tetris::fit(){
	const char LEFT = 'a';
	const char RIGHT = 'd';
	const char UP = 'w';
	const char DOWN = 's';
	const char CW = 'x';
	const char ACW = 'z';

	char key = 0;

	while (key != DOWN){
		std::cin >> key;
		//create temporary board for copying
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

		switch(key){
			case LEFT:
				for(int y=0; y<m_height; y++){
					for(int x=0; x<m_width; x++){
						//checks for bounds	
						if((m_board[x][y] != '.' && m_board[x][y] != '#') && x==0){
							return -1;
						}
						
						if(m_board[x][y] != '.' && m_board[x][y] != '#'){
							tempboard[x-1][y] = m_board[x][y];
						}
					}
					
				}
				m_board = tempboard;
				this->draw();
				break;
			case RIGHT:
				for(int y=0; y<m_height; y++){
					for(int x=0; x<m_width; x++){
						
						if((m_board[x][y] != '.' && m_board[x][y] != '#') && x==m_width-1){
							return -1;
						}
						
						if(m_board[x][y] != '.' && m_board[x][y] != '#'){
							tempboard[x+1][y] = m_board[x][y];
						}
					}
					
				}
				m_board = tempboard;
				this->draw();
				break;
			case DOWN:
				return 1;
			//not working properly
			case CW:
				this->add(m_last_type,Direction::right);
				this->draw();
				break;
			case ACW:
				this->add(m_last_type,Direction::left);
				this->draw();
				break;

			default:
				break; 
		}
	}
	return 1;
}
//FIXME
int Tetris::add(TetrominoType type, Direction dir){
	//uses rotate method from tetromino class
	//adds a rotated version of tetromino
	Tetromino tempTetro(type);
	tempTetro.rotate(dir);
	for(int y=0; y<4; y++){
		for(int x=0; x<m_width; x++){
			if(m_board[x][y] != '.' && m_board[x][y] != '#'){
				m_board[x][y] = '.';
 			}
		}
	}
	
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
	return 1;
}