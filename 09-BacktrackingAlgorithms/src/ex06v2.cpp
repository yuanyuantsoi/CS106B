#include <iostream>
#include <iomanip>
#include "grid.h"
using namespace std;

struct posT {
	int row;
	int col;
};

void knightsTour(Grid<int> & board);
bool recKnightsTour(Grid<int> & board, posT start, int step);
void printGrid(Grid<int> & g);
Vector<posT> getNextMove(Grid<int> & board, posT start);
bool inBounds(Grid<int> & board, posT p);

int main() {
	Grid<int> chessboard(8, 8);
	printGrid(chessboard);
	knightsTour(chessboard);
	printGrid(chessboard);
	return 0;
}

void printGrid(Grid<int> & g) {
	cout << endl;
	for (int i = 0; i < g.numRows(); i++) {
		for (int j = 0; j < g.numCols(); j++) {
			cout << setw(4) << g[i][j];
		}
		cout << endl;
	}
}


void knightsTour(Grid<int> & board) {
	posT start;
	start.row = board.numRows() - 1;
	start.col = 0; 
	recKnightsTour(board, start, 1);
	printGrid(board);
}

bool recKnightsTour(Grid<int> & board, posT start, int step) {
	if (step == 65) return true;
	if (board[start.row][start.col] != 0) return false;
	
	board[start.row][start.col] = step;
	Vector<posT> next;
	next = getNextMove(board, start);
	
	for (int i = 0; i < next.size(); i++) {
		if (recKnightsTour(board, next[i], step + 1)) {
			return true;
		}
	}

	board[start.row][start.col] = 0;
	return false;
}

Vector<posT> getNextMove(Grid<int> & board, posT start) {
	int r = start.row;
	int c = start.col;
	Vector<posT> list;
	posT move;
	// 0
	move.row = r - 2;
	move.col = c + 1;
	if (inBounds(board, move)) list.add(move);
	
	// 1
	move.row = r - 1;
	move.col = c + 2;
	if (inBounds(board, move)) list.add(move);

	// 2
	move.row = r + 1;
	move.col = c + 2;
	if (inBounds(board, move)) list.add(move);
	
	// 3
	move.row = r + 2;
	move.col = c + 1;
	if (inBounds(board, move)) list.add(move);
	
	// 4
	move.row = r + 2;
	move.col = c - 1;
	if (inBounds(board, move)) list.add(move);
	
	// 5
	move.row = r + 1;
	move.col = c - 2;
	if (inBounds(board, move)) list.add(move);
	
 	// 6
	move.row = r - 1;
	move.col = c - 2;
	if (inBounds(board, move)) list.add(move);

	// 7
	move.row = r - 2;
	move.col = c - 1;
	if (inBounds(board, move)) list.add(move);
	
	return list;
}

bool inBounds(Grid<int> & board, posT p) {
	if (p.row < 0 || p.row >= board.numRows()) return false;
	if (p.col < 0 || p.col >= board.numCols()) return false;
	return true;
}
