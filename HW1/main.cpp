#include <iostream>
#include <vector>
#include "tetramino.h"
#include "enums.h"

using namespace std;

int main(){
	int num_tetra;
	vector<Tetramino> tetraminos;
	vector<TetraminoType> types;

	cout << "How many tetraminos do you want to create: ";
	cin >> num_tetra;

	cout << "Enter tetramino types: " << endl;
	for(int i = 0; i<num_tetra; i++){
		char temp;
		cin >> temp;
		
		//cast inputed char to enum type
		switch (temp){
			case 'i':
			case 'I':
				types.push_back(TetraminoType::I);
				break;
			case 'o':
			case 'O':
				types.push_back(TetraminoType::O);
				break;
			case 't':
			case 'T':
				types.push_back(TetraminoType::T);
				break;
			case 'j':
			case 'J':
				types.push_back(TetraminoType::J);
				break;
			case ';':
			case 'L':
				types.push_back(TetraminoType::L);
				break;
			case 's':
			case 'S':
				types.push_back(TetraminoType::S);
				break;
			case 'z':
			case 'Z':
				types.push_back(TetraminoType::Z);				
				break;
			default:
				cout << "unkown type!" << endl << "all unknowns are assigned as O tetraminos" << endl;
				types.push_back(TetraminoType::O);
				break;
		}

	}

	for(int i = 0; i<num_tetra; i++){
		Tetramino temp(types.at(i));
		tetraminos.push_back(temp);

	}

}

