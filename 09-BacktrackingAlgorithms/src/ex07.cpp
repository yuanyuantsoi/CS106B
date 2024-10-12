/*
 * File: ex07.cpp
 * -------------------------------------
 *  The program exports the cube class and uses backtracking to solve
 *  the Insatant Insanity puzzle.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "simpio.h"
#include "vector.h"
#include "grid.h"
using namespace std;


/*
 * Class: Cube
 * ---------------------------------------
 *  The class implements the simple version of cube.
 */

class Cube{

public:

/* Constructor: cube
 * Usage: cube(top, bottom, left, right, front, back);
 * ---------------------------------------------------
 *  Construct the cube object.
 */
	Cube() {
	}

	void initializeCube() {
		top = getLine("\tEnter the color of top face: ");
		bottom = getLine("\tEnter the color of bottom face: ");
		left = getLine("\tEnter the color of left face: ");
		right = getLine("\tEnter the color of right face: ");
		front = getLine("\tEnter the color of front face: ");
		back = getLine("\tEnter the color of back face: ");
		cout << endl;
	}

	void initializeCube(string t, string f, string botm, string bk, string l, string r) {
		top = t;
		front = f;
		bottom = botm;
		back = bk;
		left = l;
		right = r;
	}


/* Method: rotatePosX
 * Usage: cube.rotatePosX();
 * ---------------------------------------------------
 *  rotate the cube aroung x in clockwise direction.
 *  坐标系参考笛卡尔右手坐标系
 */
	void rotatePosX() {
		string swap = front;
		front = bottom;
		bottom = back;
		back = top;
		top = swap;
	}


/*
 * Method: rotateNegX
 * Usage: cube.rotateNegX()
 * ----------------------------------------------------
 *  rotate the cube around x axis in anti-clockwire direction.
 */
	void rotateNegX() {
		rotatePosX();
		rotatePosX();
		rotatePosX();
	}

/*
 * Method: rotatePosY
 * Usage: rotatePosY();
 * ----------------------------------------------------
 *  rotate the cube around y axis in clockwise direction.
 */
	void rotatePosY() {
		string swap = front;
		front = right;
		right = back;
		back = left;
		left = swap;
	}



/*
 * Method: rotateNegY
 * Usage: rotateNegY()
 * ------------------------------------------------------
 *  rotate the cube around y axis in anti-clockwise direction.
 */
	void rotateNegY() {
		rotatePosY();
		rotatePosY();
		rotatePosY();
	}


/*
 * Method: rotatePosZ
 * Usage: rotateposZ()
 * ------------------------------------------------------
 *  rotate the cube around x axis in clockwise direction.
 */
	void rotatePosZ() {
		string swap = top;
		top = left;
		left = bottom;
		bottom = right;
		right = swap;
	}


/*
 * Method: rotateNegZ
 * Usage: rotateNegZ()
 * ------------------------------------------------------
 *  rotate the cube around x axis in clockwise direction.
 */
	void rotateNegZ() {
		rotatePosZ();
		rotatePosZ();
		rotatePosZ();
	}

/*
 * Getter Method
 * -----------------------------------------------------
 *  Return the string(color) of specified face.
 */
	string getTop() {
		return top;
	}
	
	string getBottom() {
		return bottom;
	}
	
	string getLeft() {
		return left;
	}

	string getRight() {
		return right;
	}
	
	string getFront() {
		return front;
	}

	string getBack() {
		return back;
	}


/* 
 * Function: toString()
 * Usage: cube.toString();
 * --------------------------------
 *  Print the color of each faces.
 */
	string toString() {
		return "Color of each face: \n" +
               		("    top = " + top + "\n") +
               		("    front = " + front + "\n") +
               		("    bottom = " + bottom + "\n") +
               		("    back = " + back + "\n") +
               		("    left = " + left + "\n") +
               		("    right = " + right + "\n");
	}



private:

/* Instance variables */
	string top;
	string bottom;
	string left;
	string right;
	string front;
	string back;
};

/* operator << overload*/
	ostream & operator<<(ostream & os, Cube cb) {
		return os << cb.toString();
	}


void initializeDiceVector(Vector<Cube> & dices);
void printDicesLayout(Vector<Cube> & dices);
bool solveInstantInsanityPuzzle(Grid<string> & solution, Vector<Cube> & dices);
bool findSolution(Grid<string> & solution, Vector<Cube> & dices, int diceIndex);
void putCubeInGrid(Grid<string> & solution, Cube cb, int col);
void printGrid(Grid<string> & grid);
string getCubeOrientation(int i);
bool isValidSolution(Grid<string> & solution, int diceIndex);


int main() {
	Vector<Cube> dices;

	// Test Case: predefined cube
	Cube dice1;
	dice1.initializeCube("g", "b", "g", "w", "b", "r");
	dices.add(dice1);

	Cube dice2;
	dice2.initializeCube("r", "g", "g", "w", "w", "b");
	dices.add(dice2);

	Cube dice3;
	dice3.initializeCube("w", "w", "g", "r", "r", "b");
	dices.add(dice3);

	Cube dice4;
	dice4.initializeCube("b", "r", "w", "g", "r", "r");
	dices.add(dice4);
//	initializeDiceVector(dices);
	printDicesLayout(dices);
	Grid<string> solution(6, dices.size());
	if (solveInstantInsanityPuzzle(solution, dices)) {
		cout << "The solution to the puzzle follows: " << endl;
		printGrid(solution);
	} else {
		cout << "No solution to this puzzle." << endl;
	}
	return 0;
}


void initializeDiceVector(Vector<Cube> & dices) {
	// Allowed user to define different cubes
	  while (true) {
		string input = getLine("Enter 'Q' to quit: ");
		if (input == "Q") break;
		cout << endl << "Add new cube: " << endl;
		Cube dice1;
		dice1.initializeCube();
		dices.add(dice1);
	}
}

void printDicesLayout(Vector<Cube> & dices) {
	for(int i = 0; i < dices.size(); i++) {
		cout << dices[i] << endl;
	}
}

bool solveInstantInsanityPuzzle(Grid<string> & solution, Vector<Cube> & dices) {
	putCubeInGrid(solution, dices[0], 0);
	printGrid(solution);
	bool result = findSolution(solution, dices, 1);
	return result;
}

/*
 * Funtion: finceSolution
 * Usage: if(findSolution(solution, dices, diceIndex));
 * -------------------------------------------------
 *  Return the boolean value to specify if there is a solution.
 *  diceIndex stands for the vector index of the dices.
 */
bool findSolution(Grid<string> & solution, Vector<Cube> & dices, int diceIndex) {
	// Simple case:  diceIndex == dices.size() means all cubes have been placed without
	// violeating the rules
	if (diceIndex == dices.size()) return true;
	
	// Recursive case:
	// Rotate the cube clockwise around x, y, z, to see if there is a solution.
	for (int i = 0; i < 4; i++) {
		if (i != 0) dices[diceIndex].rotatePosX();
		for (int j = 0; j < 4; j++) {
			if (j != 0) dices[diceIndex].rotatePosY();
			for (int k = 0; k < 4; k++) {
				if(k != 0) dices[diceIndex].rotatePosZ();
				putCubeInGrid(solution, dices[diceIndex], diceIndex);
				// Debug output
				/*
				if (diceIndex == 2) {	
					printGrid(solution);
					cout << "diceIndex = " << diceIndex << endl;
					string stop = getLine("Press to continue");
				}
				*/
				if (isValidSolution(solution, diceIndex)) {
					if(findSolution(solution, dices, diceIndex + 1)) return true;
				}
			}
		}
	}
	return false;
}

bool isValidSolution(Grid<string> & solution, int diceIndex) {
	for (int row = 0; row < solution.numRows(); row++) {
		if (row == 0) continue;
		if (row == 2) continue;
		string color = solution[row][diceIndex];
		for (int col = 0; col < diceIndex; col++) {
			if (color == solution[row][col]) return false;
		}
	}
	return true;
}



void putCubeInGrid(Grid<string> & solution, Cube cb, int col) {
	// Grid Defination
	// Row 0 - top
	// Row 1 - front
	// Row 2 - bottom
	// Row 3 - left
	// Row 4 - right
	// Row 5 - back
	solution[0][col] = cb.getTop();
	solution[1][col] = cb.getFront();
	solution[2][col] = cb.getBottom();
	solution[3][col] = cb.getLeft();
	solution[4][col] = cb.getRight();
	solution[5][col] = cb.getBack();
}
	
void printGrid(Grid<string> & grid) {
	for (int i = 0; i < grid.numRows(); i++) {
		cout << setw(10) << getCubeOrientation(i) << ": ";
		for (int j = 0; j < grid.numCols(); j++) {
			cout << setw(10) << grid[i][j];
		}
		cout << endl;
	}
}


string getCubeOrientation(int i) {
	switch(i) {
		case 0: return "top";
		case 1: return "front";
		case 2: return "bottom";
		case 3: return "left";
		case 4: return "right";
		case 5: return "back";
		default: return "error";
	}
}
