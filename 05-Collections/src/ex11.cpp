/*
 * File: ex11.cpp
 * --------------------------------------------------------------
 *  This mian implements the reshape method.
 */


#include <iomanip>
#include <iostream>
#include "vector.h"
#include "grid.h"
using namespace std;

void reshape(Grid<int> & grid, int nRows, int nCols);
void printGrid(Grid<int> & grid);

int main() {
	Grid<int> grid(3, 4);
	for (int i = 0; i < grid.numRows(); i++) {
		for (int j = 0; j < grid.numCols(); j++) {
			grid[i][j] = (4 * i + j + 1);
		}
	}
	printGrid(grid);
	cout << endl;

	reshape(grid, 4, 3);
	printGrid(grid);
	cout << endl;

	reshape(grid, 2, 5);
	printGrid(grid);
	cout << endl;

	reshape(grid, 3, 5);
	printGrid(grid);
	cout << endl;

	return 0;
}


/*
 * Function: printGrid(grid)
 * ---------------------------------------------
 *  This function print an int grid in its own form.
 */
void printGrid(Grid<int> & grid) {
	for (int i = 0; i < grid.numRows(); i++) {
		for (int j = 0; j < grid.numCols(); j++) {
			cout << setw(4) << grid[i][j];
		}
		cout << endl;
	}
	cout << endl;
	return;
}

/*
 * Function: reshape
 * Usage: reshape(grid, nRows, nCols);
 * -------------------------------------------------
 *  This function resizes the grid but fills in the data
 *  from the original grid by copying elements in the
 *  standard row-major order.
 *  If the new grid does not include enough space for all
 *  of the original values, the values at the bottom are simply
 *  dropped.
 *  If there are enough elements in the original grid to fill
 *  available space, the entries at the end should simply retain 
 *  their default values.
 */
void reshape(Grid<int> & grid, int nRows, int nCols) {
	Vector<int> data;

	for (int i = 0; i < grid.numRows(); i++) {
		for (int j = 0; j < grid.numCols(); j++) {
			data.add(grid[i][j]);
		}
	}

	grid.resize(nRows, nCols);

	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			int index = nCols * i + j;
			int num = 0;
			if (index < data.size()) num = data[index];  // Checks if has enough elements in the vec
			grid[i][j] = num;
		}
	}

	return;
}
