/*
 * File: ex06.cpp
 */

#include <iostream>
#include <iomanip>
#include "vector.h"
#include "grid.h"
#include "simpio.h"
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
bool isInBounds(Location & pos, int & boardsize);
void printMovelist(Vector<Location> list);

/* Main program */
int main() {
	int n = getInteger("Enter n = ");
	Grid<int> chessboard(n, n);
	printChessboard(chessboard);
	if (findKnightsTour(chessboard)) {
		printChessboard(chessboard);
	}
	return 0;
}

bool findAKnightsTour(Grid<int> & chessboard, Location start, int step) {
	//Debug 
	//cout << endl;
	//cout << " step = " << step << endl;
	//printChessboard(chessboard);
	
	// Simple case
	chessboard[start.row][start.col] = step;
	//printChessboard(chessboard);
	if (step == chessboard.numRows() * chessboard.numCols())	return true;
	
	// Recursive case
	Vector<Location> movelist = nextMove(start.row, start.col, chessboard.numRows());
	for (int i = 0; i < movelist.size(); i++) {
		Location move = movelist[i];
		int row = move.row;
		int col = move.col;
		if ((chessboard[row][col] == 0) && (findAKnightsTour(chessboard, move, step + 1))) {
				return true;
		}
	}
	chessboard[start.row][start.col] = 0;
	return false;
}


Vector<Location> nextMove(int row, int col, int boardsize) {
	Vector<Location> movelist;
	Location move;
//	cout << "Current pos: (" << row << ", " << col << ");" << endl;
	for (int i = 1; i <= 2; i++) {
		move.row = row + i;
		move.col = col + 3 - i;
		if(isInBounds(move, boardsize)) movelist.add(move);
		
		move.row = row - i;
		move.col = col - (3 - i);
		if(isInBounds(move, boardsize)) movelist.add(move);
		
		move.row = row + i;
		move.col = col - (3 - i);
		if(isInBounds(move, boardsize)) movelist.add(move);

		move.row = row - i;
		move.col = col + (3 - i);
		if(isInBounds(move, boardsize)) movelist.add(move);
	}
	return movelist;
}

bool isInBounds(Location & pos, int & boardsize) {
	if ((pos.row < 0) || (pos.row >= boardsize)) return false;
	if ((pos.col < 0) || (pos.col >= boardsize)) return false;
	return true;
}


bool findKnightsTour(Grid<int> & chessboard) {
	Location start;
	start.row = chessboard.numRows() - 1;
	start.col = 0;
	if (findAKnightsTour(chessboard, start, 1)) return true;
	/*
	for (int i = 0; i < chessboard.numRows(); i++) {
		for (int j = 0; j < chessboard.numCols(); j++) {
			start.row = i;
			start.col = j;
			if (findAKnightsTour(chessboard, start, 1)) return true;
		}
	}
	*/
	return false;
}

void printChessboard(Grid<int> & chessboard) {
	for (int i = 0; i < chessboard.numRows(); i++) {
		for (int j = 0; j < chessboard.numCols(); j++) {
			cout << setw(SPACEING) << chessboard[i][j] ;
		}
		cout << endl;
	}
	cout << endl;
}


void printMovelist(Vector<Location> list) {
	Location loc;
	for (int i = 0; i < list.size(); i++) {
		cout << "next move: (" << list[i].row << ", " << list[i].col << ");" << endl; 
	}
}

