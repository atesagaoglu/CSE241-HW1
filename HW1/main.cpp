#include <iostream>
#include <vector>
#include "tetromino.h"
#include "enums.h"

using namespace std;

int main(){
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

	for(int i=0; i<tetro_count; i++){
		// cout << blocks.at(i).getTypeChar() << endl;
		// blocks.at(i).rotate(Direction::right); //tester
		// blocks.at(i).rotate(Direction::left); //tester
		blocks.at(i).print();
	}

}