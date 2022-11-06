#include <iostream>
#include <vector>
#include "tetromino.h"
#include "enums.h"
#include "tetris.h"

using namespace std;

int main(){
	
	cout << "Select class to test" << endl << "1 - Tetromino" << endl << "2 - Tetris" << endl;
	int tclass;
	cin >> tclass;
	
	if(tclass == 1){
		cout << "~~~~~~~~~~~~~~~~~~" << endl << "Testing tetromino class" << endl << "~~~~~~~~~~~~~~~~~~" << endl;
		int tetro_count;
		vector<Tetromino> blocks; //vector of classes which hold tetromino info	

		cout << "How many tetrominos do you want to generate?" << endl;
		cin >> tetro_count;

		cout << "Enter tetromino types: " << endl;
		for (int i=0; i<tetro_count; i++){
			char temp_type;
			TetrominoType temp_type_enum;
			cin >> temp_type;

			//assigning char as a enum type
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
				default:
					cout << "Type " << temp_type << "is not a valid type." << endl;
					cout << "All invalid types will be interpreted as \"O\" tetromino." << endl;
					break;
			}

			// constructing temporary objects than pushing them to a vector of objects
			Tetromino temp_block(temp_type_enum);
			temp_block.setTypeChar(temp_type);
			blocks.push_back(temp_block);


		}
		cout << "Printing original tetros" << endl;
		for(int i=0; i<tetro_count; i++){
			blocks.at(i).print();
		}
		cout << "Printing tetros turned to left" << endl;
		for(int i=0; i<tetro_count; i++){
			blocks.at(i).rotate(Direction::left);
			blocks.at(i).print();
		}
		cout << "Printing tetros turned to right" << endl;
		for(int i=0; i<tetro_count; i++){
			blocks.at(i).rotate(Direction::right);
			blocks.at(i).print();
		}

		int gg1,gg2,tetr;
		cout<<"enter two numbers to test getGrid" << endl;
		cin >> gg1;
		cin >> gg2;
		cout << "enter tetromino index" << endl;
		cin >> tetr;
		cout << blocks.at(tetr).getGrid(gg1,gg2);
	}

	else if(tclass == 2){

		cout << "~~~~~~~~~~~~~~~~~~" << endl << "Testing tetris class" << endl << "~~~~~~~~~~~~~~~~~~" << endl;

		int width_board, height_board;
		cout << "Keys: " << endl << "A/D move left/right" << endl << "S drop" << endl << "Z/X rotate right/left" << endl;
		cout << "Enter the width and height seperated by a whitespace." << endl;
		cin >> width_board;
		cin >> height_board;

		Tetris tet(width_board,height_board);

		while(tet.add()!= -1){
			while(tet.fit() != 1) tet.draw();
			tet.animate();
			tet.makePerm();
		}
	}
}