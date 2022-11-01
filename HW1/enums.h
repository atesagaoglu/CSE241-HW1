// using seperate file to store enum classes
#ifndef ENUMS_H
#define ENUMS_H

enum class Direction {right, left};
enum class Facing {up, right, down, left}; // all tetraminos are facing up by default. 2 rotation == facing down
enum class Pos{right, left}; //assuming that canFit function will only be used for horizontal fit

enum class TetrominoType {I, O, T, J, L, S, Z};

#endif