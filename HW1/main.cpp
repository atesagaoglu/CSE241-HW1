#include <iostream>
#include <vector>
#include "tetromino.h"
#include "enums.h"
#include "tetris.h"

using namespace std;

int main(){
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