/*
 * File: ex07.cpp
 * ---------------------------------------
 *  This program implements the function 
 *  fillGrid that takes a vector to initialize
 *  the grid.
 */

#include <iomanip>
#include <iostream>
#include "simpio.h"
#include "vector.h"
#include "grid.h"
using namespace std;

void fillGrid(Grid<int> & grid, Vector<int> & values);

int main() {
	Grid<int> matrix(3, 3);
	Vector<int> values;
	values += 1, 2, 3;
	values += 4, 5, 6;
	values += 7, 8, 9;
	fillGrid(matrix, values);
	for (int i = 0; i < matrix.numRows(); i++) {
		for (int j = 0; j < matrix.numCols(); j++) {
			cout << setw(4) << matrix[i][j];
		}
		cout << endl;
	}
	return 0;
}

void fillGrid(Grid<int> & grid, Vector<int> & values) {
	for (int i = 0; i < grid.numRows(); i++) {
		for (int j = 0; j < grid.numCols(); j++) {
			grid[i][j] =  values[3 * i + j];
		}
	}
	return;
}

