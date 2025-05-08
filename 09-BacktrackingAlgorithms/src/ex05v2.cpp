#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include "grid.h"
using namespace std;

/* Constants */
const string EMPTY = "*";
const string QUEEN = "Q";

/* Function prototypes */

void initBoard(Grid<string> & board);
bool solveQueens(Grid<string> & board);
bool recSolveQueens(Grid<string> & board, int col);
void printBoard(Grid<string> & board);
bool isValid(Grid<string> & board, int row, int col);

int main() {
	Grid<string> board(8, 8);
	initBoard(board);
	printBoard(board);
	solveQueens(board);
	printBoard(board);
	return 0;
}

void initBoard(Grid<string> & board)	{
	for (int i = 0; i < board.numRows(); i++) {
		for (int j = 0; j < board.numCols(); j++) {
			board[i][j] = EMPTY;
		}
	}
}

bool solveQueens(Grid<string> & board) {
	return recSolveQueens(board, 0);
}

bool recSolveQueens(Grid<string> & board, int col) {
	if (col == board.numCols()) return true;
	
	for (int row = 0; row < board.numRows(); row++) {
		if (isValid(board, row, col)) {
			board[row][col] = QUEEN;
			if (recSolveQueens(board, col + 1)) {
				return true;
			} else {
				board[row][col] = EMPTY;
   			}
		}
	}
	return false;
}

void printBoard(Grid<string> & board) {
	cout << endl;
	for (int i = 0; i < board.numRows(); i++) {
		cout << endl;
		for (int j = 0; j < board.numCols(); j++) {
			cout << setw(4) << board[i][j];
		}
	}
}

bool isValid(Grid<string> & board, int row, int col) {
	// check row 
	for (int j = 0; j < board.numCols(); j++) {
		if (board[row][j] == QUEEN) return false;
	}

	// check diagonally
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j] == QUEEN) return false;
	}

	// check diagonally
	for (int i = row, j = col; i < board.numRows() && j >= 0; i++, j--) {
		if (board[i][j] == QUEEN) return false;
	}
	return true;
}

