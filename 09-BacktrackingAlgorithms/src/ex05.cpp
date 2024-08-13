/*
 * File: ex05.cpp
 * ------------------------
 *  The program solves the more genreal problem of
 *  whether it is possible to place N queens on an
 *  N x N checcboard so that none of them can move
 *  to a square occupied by any of the others in a 
 *  single turn.
 */

#include <iostream>
#include "gwindow.h"
#include "gobjects.h"
#include "vector.h"
#include "grid.h"
#include "simpio.h"
#include "error.h"
#include "stack.h"
using namespace std;

// Strucure used to indicate location of queens on chessboard.
struct Location{
	int row;
	int col;
};

/* constant */
const int SQUARE_LENGTH = 50;

/* Function prototypes */
bool placeNQueensOnChessboard(int n, Grid<bool> & chessboard, Stack<Location> & queensLoc);
void drawChessboard(GWindow & gw, int n);
void drawQueensOnChessboard(GWindow & gw, Stack<Location>  queensLoc);
bool setQueenArea(int row, int col, Grid<bool> & chessboard);

/* Main program */

int main() {
	// Get the N
	int n = getInteger("Enter N = ");
	
	
	// Found out the soultion if there is any
	Grid<bool> chessboard(n,  n);
	Stack<Location> queensLoc;
	bool solution = placeNQueensOnChessboard(n, chessboard, queensLoc);
	
	// Print out the solution if there is any.
	if (solution) {
		GWindow  gw(n * SQUARE_LENGTH, n * SQUARE_LENGTH);
		drawChessboard(gw, n);
		drawQueensOnChessboard(gw, queensLoc);
	} else {
		cout << "There is no solution to place " << n << " queens on an " << n << " x " 
			<< n << " chessboard so that none of them can move to a square occupied by any" 
			<< " of the others in a single turn." << endl;
	}
	return 0;
}



/*
 * Function: placeNQueensOnChessboard
 * Usage: if(placeNQueensOnChessboard(n, chessboard, queensLoc))
 * ------------------------------------------------------------------------
 *  Return the result of place n queens on chessboard.
 */
bool placeNQueensOnChessboard(int n, Grid<bool> & chessboard, Stack<Location> & queensLoc) {
	Grid<bool> lastboard(n, n);
	if (n == 0) return true;
	int nGrid = chessboard.numRows();
	for (int i = 0; i < nGrid; i++) {
		for (int j = 0; j < nGrid; j++) {
			if (chessboard[i][j] == false) {  // the grid[i][j] is avaliable for queen
        			lastboard = chessboard;
				setQueenArea(i, j, chessboard);
				struct Location loc;
				loc.row = i;
				loc.col = j;
				queensLoc.push(loc);
				if(placeNQueensOnChessboard(n - 1, chessboard, queensLoc) == false) {   //reset the queen area just put down
					queensLoc.pop();
					chessboard = lastboard;
				} else {
					return true;
				}
			}
		}
	}
	return false;
}

/*
 * Function: placeOneQueen
 * Usage: if(placeOneQueen(row, col, chessboard)) 
 * ---------------------------------------------------
 *  Place one queen on the chessboard at (row, col), return true if the place is
 *  avaliable, and set the path to true;
 */
bool setQueenArea(int row, int col, Grid<bool> & chessboard) {
	int nRow = chessboard.numRows();
	int nCol = chessboard.numCols();
	for (int i = 0; i < nRow; i++) {
		chessboard[i][col] = true;
	}
	for (int j = 0; j < nCol; j++) {
		chessboard[row][j] = true;
	}
	for (int i = row, j = col; ((i >= 0) && (j >= 0)); i--, j--) {
		chessboard[i][j] = true;
	}
	for (int i = row, j = col; (i < nRow) && (j < nCol); i++, j++) {
		chessboard[i][j] = true;
	}
	for (int i = row, j = col; (i >= 0) && (j < nCol); i--, j++) {
		chessboard[i][j] = true;
	}
	for (int i = row, j = col; (i < nRow) && (j >= 0); i++, j--) {
		chessboard[i][j] = true;
	}
	return true;
}

/*
 * Function: drawChessboard
 * Usage: drawChessboard(gw, n);
 * ----------------------------------------------------------------------
 *  Draw a n x n chessboard on gw.
 */
void drawChessboard(GWindow & gw, int n) {
	bool whiteFlag = true;
	for (int i = 0; i < n; i++) {
		whiteFlag = (i % 2 == 0)? true : false;
		for (int j = 0; j < n; j++) {
			string color = whiteFlag ? "white" : "black";
			gw.setColor(whiteFlag ? "white" : "black");
			gw.fillRect(i * SQUARE_LENGTH, j * SQUARE_LENGTH, SQUARE_LENGTH, SQUARE_LENGTH);
			whiteFlag = !whiteFlag;
		}
	}
}

/*
 * Function: drawQueensOnChessboard
 * Usage: drawQueensOnChessboard(gw, queensLoc);
 * -------------------------------------------------------------------------
 *  Draws n queens on chessboard.
 *  Yellow oval is used to stand the queen position.
 */

void drawQueensOnChessboard(GWindow & gw, Stack<Location>  queensLoc) {
	while(!queensLoc.isEmpty()) {
		struct Location loc = queensLoc.pop();
		int height = loc.row * SQUARE_LENGTH;
		int width = loc.col * SQUARE_LENGTH;
		gw.setColor("yellow");
		gw.fillOval(width, height, SQUARE_LENGTH, SQUARE_LENGTH);
	}
}

