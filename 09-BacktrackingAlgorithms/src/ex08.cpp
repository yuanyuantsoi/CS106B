/*
 * File: ex08.cpp
 * -----------------------------
 *  This program implements solves the peg solitaire 
 *  puzzle.
 */

#include <iostream>
#include <iomanip>
#include "direction.h"
#include "simpio.h"
#include "grid.h"
using namespace std;

/* Enum type */

enum Hole {
	Missing = -1,
	Empty = 0,
	HasPeg = 1
};

/* Struct type */

struct HoleLocation{
	int x;
	int y;
};

using Location = HoleLocation;

struct PegMove{
	Location start;
	Location jump;
	Location end;
};

using Move = PegMove;


/* Constants */

const int BOARD_SIZE = 7;
const int ETCHED_LENGTH = 2;

/*
 * Class: PegSolitaire
 * ------------------------
 *  The PegSolitaire class implements the
 *  simple version of peg solitarire.
 */

class PegSolitaire{

public: 

/*
 * Method: solve
 * Usage: puzzle.solve();
 * --------------------------
 *  Solves the peg solitaire puzzle.
 */
	void solve() {
		initBoard();
		printBoard();
		if (findSolution()) {
			printMovement();
		} else {
			cout << "No solution to this puzzle." << endl;
		}
	}

private:

/*
 * Method: initBoard
 * Usage: initBoard();
 * ----------------------------
 *  Helper function of solve(). Set up the
 *  board for the puzzle.
 */
       void initBoard() {
	       numPegs = 0;
	       BoardT.resize(BOARD_SIZE, BOARD_SIZE);
	       for (int i = 0; i < BOARD_SIZE; i++) {
		       for (int j = 0; j < BOARD_SIZE; j++) {
			       if (inBounds(i, j)) {
				       numPegs++;
				       BoardT[i][j] = HasPeg;
			       } else {
				       BoardT[i][j] = Missing;
			       }
		       }
	       }
	       int center = BOARD_SIZE / 2;
	       Location centerHole;
	       centerHole.x = center;
	       centerHole.y = center;
	       emptyHoles.add(centerHole);
	       BoardT[center][center] = Empty;
	       numPegs--;
       }
/*
 * Method: inBounds
 * Usage: if (inBounds(x, y))
 * -------------------------------
 *  Helper function of the function initBoard();
 *  Return true if the hole is in the bounds of peg board, false otherwise.
 */
       bool inBounds(int x, int y) {
	       int lowerLimit = ETCHED_LENGTH;
	       int upperLimit = BOARD_SIZE - ETCHED_LENGTH - 1;
	       if (x < lowerLimit && y < lowerLimit) return false;
	       if (x < lowerLimit && y > upperLimit) return false;
	       if (x > upperLimit && y > upperLimit) return false;
	       if (x > upperLimit && y < lowerLimit) return false;
	       return true;
       }


/*
 * Method: printBoard
 * Usage: printBoard();
 * ------------------------------
 *  Print the board.
 */
       void printBoard() {
	       for (int i = 0; i < BOARD_SIZE; i++) {
		       for (int j = 0; j < BOARD_SIZE; j++) {
			       cout << setw(4) << BoardT[i][j];
		       }
		       cout << endl;
	       }
       }


/*
 * Method: printDebugInfo
 * Usage: printDebugInfo();
 * -------------------------
 *  Print part of instance variables for debug.
 */
       void printDebugInfo() {
	       cout << numPegs << endl;
       }

/*
 * Method: findSolution
 * Usage: findSolution();
 * -----------------------------
 *  Finds out a set of peg movement to solve the puzzle.
 *  Returns true if there is a solution, false otherwise.
 */       
       bool findSolution() {
	        printDebugInfo();
		Grid<Hole> StashedBoard;
		StashedBoard.resize(BoardT.numRows(), BoardT.numCols());
		StashedBoard = BoardT;
	       // Simple Case
	       if ((numPegs == 1) && (BoardT[BoardT.numRows() / 2][BoardT.numCols() / 2] == HasPeg)) {
		       return true;
	       }

	       // Recursive case
	       // Go through the empty holes
	       for (int i = 0; i < emptyHoles.size(); i++) {
		       Location target = emptyHoles[i];
		       for (Direction dir = NORTH; dir <= WEST; dir++) {
			       Location start, mid;
			       if (isMoveValid(dir, start, mid, target)) {
				       // move Peg from start to target, and remove peg in the mid hole
				       // Remove peg from start to target
				       BoardT[start.x][start.y] = Empty;
				       emptyHoles.add(start);
				       BoardT[target.x][target.y] = HasPeg;
				       emptyHoles.remove(i);
				       i--;
				       numPegs--;
				       BoardT[mid.x][mid.y] = Empty;
				       emptyHoles.add(mid);
				       if (findSolution()) {
					       return true;
				       } else {
					       i++;
					       emptyHoles.remove(emptyHoles.size() - 1);
					       emptyHoles.remove(emptyHoles.size() - 1);
					       emptyHoles.insert(i, target);
					       BoardT = StashedBoard;
					       numPegs++;
				       }
			       }
		       }
	       }
	       return false;
       }


/*
 * Method: updateEmptyHoles
 * Usage: updateEmptyHoles(start, mid, target);
 * --------------------------------------------
 *  Update the hole status.
 */
	void updateEmptyHoles(Location start, Location mid, Location target) {
		//if (BoardT[start.x][start.y] == Empty) 
	}

/*
 * Method: isMoveValid
 * Usage: if (isMoveValid(dir, start, mid, target))
 * -------------------------------------------------
 *  Returns true if move is valid.
 */
	bool isMoveValid(Direction dir, Location & start, Location & mid, Location & target) {
		if (!inBounds(start.x, start.y) || !inBounds(mid.x, mid.y) || !inBounds(target.x, target.y)) return false;
		int deltaX, deltaY;
		getDeltaForDir(dir, deltaX, deltaY);
		start.x = target.x + deltaX;
		start.y = target.y + deltaY;

		mid.x = mid.x + deltaX / 2;
		mid.y = mid.y + deltaY / 2;
		
		if ((BoardT[start.x][start.y] == HasPeg) && (BoardT[mid.x][mid.y] == HasPeg) 
				&& (BoardT[target.x][target.y] == Empty)) {
			return true;
		}
		return false;
	}

/*
 * Method: getDeltaForDir
 * Usage: getDeltaForDir(dir, deltaX, deltaY);
 * -------------------------------------------------
 *  Calculate deltaX and deltaY for each dir.
 *  Return false if the dir is out of bounds.
 */
	bool getDeltaForDir(Direction dir, int & deltaX, int & deltaY) {
		switch (dir) {
			case NORTH: deltaX = 0; deltaY = -2; return true;
			case EAST: deltaX = -2; deltaY = 0; return true;
			case SOUTH: deltaX = 0; deltaY = 2; return true;
			case WEST: deltaX = 2; deltaY = 0; return true;
			default: deltaX = 0; deltaY = 0; return false;
		}
	}

/*
 * Method: printMovement
 * Usage: printMovement();
 * ------------------------------
 *  Prints the peg movement of the puzzle.
 */
       void printMovement() {
	       cout << "Solution to this puzzle: " << endl;
       }

/* Instance variables */
       Grid<Hole> BoardT;  /* Board Size */
       int numPegs;  /* Num of pegs left on the board */
       Vector<Location> emptyHoles; /* Location of empty holes */
       Vector<Move> solution; /* Solution in the form of peg movement */
};

/* Main program */
int main() {
	PegSolitaire puzzle;
	puzzle.solve();
	return 0;
}

