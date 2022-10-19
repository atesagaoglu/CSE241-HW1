#include <iostream>
#include <vector>
#include "tetromino.h"
#include "enums.h"

using namespace std;

int main(){
	int num_tetro;
	vector<Tetromino> tetrominos;
	vector<TetrominoType> types;

	cout << "How many tetraminos do you want to create: ";
	cin >> num_tetro;

	cout << "Enter tetramino types: " << endl;
	for(int i = 0; i<num_tetro; i++){
		char temp;
		cin >> temp;
		
		//cast inputed char to enum type
		switch (temp){
			case 'i':
			case 'I':
				types.push_back(TetrominoType::I);
				break;
			case 'o':
			case 'O':
				types.push_back(TetrominoType::O);
				break;
			case 't':
			case 'T':
				types.push_back(TetrominoType::T);
				break;
			case 'j':
			case 'J':
				types.push_back(TetrominoType::J);
				break;
			case 'l':
			case 'L':
				types.push_back(TetrominoType::L);
				break;
			case 's':
			case 'S':
				types.push_back(TetrominoType::S);
				break;
			case 'z':
			case 'Z':
				types.push_back(TetrominoType::Z);				
				break;
			default:
				cout << "unkown type!" << endl << "all unknowns are assigned as O tetraminos" << endl;
				types.push_back(TetrominoType::O);
				break;
		}

	}

	for(int i = 0; i<num_tetro; i++){
		Tetromino temp(types.at(i));
		tetrominos.push_back(temp);

	}

}

