/*
 * File: RecursivePuzzle.cpp
 * ------------------------------------
 *  CS106B. H18 - Assign3RecPs. Problem5 A recursive puzzle.
 *  The program solve the puzzle consisting of a row of squares
 *  each containing an integer. The circle on the initial square
 *  is a marker that can move to other squares along the row.
 *  The goal of the puzzle is to move the marker to the 0 at the
 *  far end of the row.
 */

#include <iostream>
#include "vector.h"
using namespace std;

/* Function prototypes */

bool solvable(int start, Vector<int> & squares);
bool recMoveMarker(int circledIndex, Vector<int> & squares, Vector<bool> & visited);
bool inBounds(int maxIndex, int index);
void initMarkedVector(Vector<bool> & vec);

/* Main program */

int main() {
	Vector<int> puzzle;
	puzzle += 3, 6, 4, 1, 3, 4, 2, 5, 3, 0;
	cout << (solvable(0, puzzle) ? "solvable" : "unsolvable") << endl;

	Vector<int> puzzle2;
	puzzle2 += 3, 1, 2, 3, 0;
	cout << (solvable(0, puzzle2) ? "solvable" : "unsolvable") << endl;
	return 0;
}

/*
 * Function: solvable
 * Usage: if (solvable(start, squares));
 * -------------------------------------------------
 *  Return true if the puzzle as the squares is solvable, return false otherwise.
 *  This is a warpper function for recMoveMarker.
 */
bool solvable(int start, Vector<int> & squares) {
	Vector<bool> visited(squares.size());
	initMarkedVector(visited);
	return recMoveMarker(start, squares, visited);
}


/*
 * Function: recMoveMarker
 * Usage: if(recMoveMarker(circledIndex, squares, visited))
 * --------------------------------------------------------------------
 *  This function does all the hard work for solvable by move the marker recursively.
 *  
 *  Base case: circled value == 0
 *
 *  Recursive case: 
 *  	1. move marker to left, 
 *  	2. check left target in bounds and unvisited, 
 *  	3. recursive call recMoveMarker to see if it returns true;
 *  	same as move marker to right
 *  	return false if both direction fails.
 */
bool recMoveMarker(int circledIndex, Vector<int> & squares, Vector<bool> & visited) {
	int circledValue = squares[circledIndex];

	if (circledValue == 0) return true;

	for (int i = 0; i <= 1; i++) {
		// if i == 0, move the marker to the left, if i == 1, move the marker to the right
		int targetIndex = ((i == 0) ? (circledIndex - circledValue) : (circledIndex + circledValue));
		if (inBounds(squares.size() - 1, targetIndex) && !visited[targetIndex]) {
			visited[targetIndex] = true;
			if (recMoveMarker(targetIndex, squares, visited)) return true;
			else visited[targetIndex] = false;
		}
	}
	return false;
}



/*
 * Function: inBounds
 * Usage: if(inBounds(maxIndex, index));
 * ---------------------------------------------------
 *  Helper function for the recMoveMarker, check the index if is in
 *  bounds or not.
 */
bool inBounds(int maxIndex, int index) {
	return (index >= 0) && (index <= maxIndex);
}

/*
 * Function: initMarkedVector
 * Usage: initMarkedVector(vec);
 * ---------------------------------------
 *  Initialize the vector of bool type to be false.
 *  The vector is used to indicated that wheather or not the index has been
 *  visited. False stand for unvisited, true otherwise.
 */
void initMarkedVector(Vector<bool> & vec) {
	for (int i = 0; i < vec.size(); i++) {
		vec[i] = false;
	}
}
