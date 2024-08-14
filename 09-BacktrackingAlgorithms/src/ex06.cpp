/*
 * File: ex06.cpp
 */

#include <iostream>
#include <iomanip>
#include "vector.h"
#include "grid.h"
using namespace std;

/* Structure */
struct Location{
	int row;
	int col;
};

/* Constant */
const int SPACEING = 4;

/* Function prototypes */
Vector<Location> nextMove(int row, int col, int boardsize);
bool findKnightsTour(Grid<int> & chessboard);
bool findAKnightsTour(Grid<int> & chessboard, Location start, int step);
void printChessboard(Grid<int> & chessboard);

/* Main program */
int main() {
	int n = 8;
	Grid<int> chessboard(n, n);
	printChessboard(chessboard);
	if (findKnightsTour(chessboard)) {
		printChessboard(chessboard);
	}
	return 0;
}

bool findAKnightsTour(Grid<int> & chessboard, Location start, int step) {
	if (step == 64) return true;
	Vector<Location> movelist = nextMove(start.row, start.col, chessboard.numRows());
	for (int i = 0; i < movelist.size(); i++) {
		Location move = movelist[i];
		if (chessboard[move.row][move.col] == 0) {
			findAKnightsTour(chessboard, move, step + 1);
		}
	}
	return false;
}


Vector<Location> nextMove(int row, int col, int boardsize) {
	Vector<Location> movelist;
	struct Location move;
	for (int i = 1; i <= 2; i++) {
		move.row = row + i;
		move.col = col + 3 - i;
		movelist.add(move);
		
		move.row = row - i;
		move.col = col - (3 - i);
		movelist.add(move);
		
		move.row = row + i;
		move.col = col - (3 - i);
		movelist.add(move);

		move.row = row - i;
		move.col = col + (3 - i);
		movelist.add(move);
	}
	return movelist;
}


bool findKnightsTour(Grid<int> & chessboard) {
	struct Location start;
	for (int i = 0; i < chessboard.numRows(); i++) {
		for (int j = 0; j < chessboard.numCols(); j++) {
			start.row = i;
			start.col = j;
			if (findAKnightsTour(chessboard, start, 1)) return true;
		}
	}
	return false;
}

void printChessboard(Grid<int> & chessboard) {
	for (int i = 0; i < chessboard.numRows(); i++) {
		for (int j = 0; j < chessboard.numCols(); j++) {
			cout << setw(SPACEING) << chessboard[i][j] ;
		}
		cout << endl;
	}
}




