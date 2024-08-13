/*
 * File: ex08.cpp
 * ---------------------------------------
 *  This program implements the function isMagicSquare that tests
 *  to see whether the grid contains a magic square.
 */

#include <iomanip>
#include <iostream>
#include "vector.h"
#include "grid.h"
#include "simpio.h"
using namespace std;

bool isMagicSquare(Grid<int> & square);
void fillGrid(Grid<int> & grid);

int main() {
	Grid<int> grid;
	fillGrid(grid);
	cout << (isMagicSquare(grid) ? "This grid is MagicSquare " : "This grid is not a magic square") << endl;
	return 0;
}

void fillGrid(Grid<int> & grid) {
	int row = getInteger("Enter the num of rows: ");
	int col = getInteger("Enter the num of cols: ");
	grid.resize(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << "Enter grid(" << i << ", " << j << ") = ";
			cin >> grid[i][j];
		}
	}
	return;
}


bool isMagicSquare(Grid<int> & square) {
	if (square.numRows() != square.numCols()) return false;
	int len = square.numRows();
	
	int total = 0;
	int antiDiaTotal = 0;
	for (int i = 0; i < len; i++) {
		total += square[i][i];
		antiDiaTotal += square[i][len - 1 - i];
	}
	if (total != antiDiaTotal) return false;
	
	
	for (int i = 0; i < len; i++) {
		int rowTotal = 0;
		for (int j = 0; j < len; j++) {
	       		rowTotal += square[i][j];
		}
		if (total != rowTotal) return false;
	}

	for (int j = 0; j < len; j++) {
		int colTotal = 0;
		for (int i = 0; i < len; i++) {
			colTotal += square[i][j];
		}
		if (total != colTotal) return false;
	}
	
	return true;
	
}



