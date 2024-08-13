/*
 * File: ex09.cpp
 * -----------------------------------
 *  This program checks the puzzle contains
 *  a 9 X 9 grid of integers and report an
 *  error if this is not the case.
 */

#include <iomanip>
#include <iostream>
#include "grid.h"
#include "vector.h"
using namespace std;

bool checkSudokuSolution(Grid<int> & puzzle);
bool checkPartInSudoku(Vector<int> & vec);
void fillGrid(Grid<int> & grid, Vector<int> & values);
void printGrid(Grid<int> & grid);
bool findNum(Vector<int> data, int num);

int main() {
	Grid<int> puzzle(9, 9);
	Vector<int> data;
	data += 8,1,3,9,4,6,2,7,5;
	data += 6,2,7,1,3,5,9,4,8;
	data += 5,9,4,7,2,8,6,3,1;
	data += 1,7,5,6,9,4,8,2,3;
	data += 3,6,9,8,1,2,7,5,4;
	data += 2,4,8,3,5,7,1,6,9;
	data += 4,5,1,2,6,9,3,8,7;
	data += 7,3,6,5,8,1,4,9,2;
	data += 9,8,2,4,7,3,5,1,5;
	fillGrid(puzzle, data);
	printGrid(puzzle);

	if (checkSudokuSolution(puzzle)) {
		cout << "proper sudoku solution" << endl;
	} else {
		cout << "Not a proper solution" << endl;
	}

	return 0;
}

bool findNum(Vector<int> data, int num) {
	for (int i = 0; i < data.size(); i++) {
		if (num == data[i]) return true;
	}
	return false;
}

bool checkPartInSudoku(Vector<int> & vec) {
	if (vec.size() != 9) return false;
	for (int i = 1; i <= 9; i++) {
		if(!findNum(vec, i)) return false;
	}
	return true;
}

bool checkSudokuSolution(Grid<int> & puzzle) {
	if ((puzzle.numRows() != 9) || (puzzle.numCols() != 9)) return false;
	int width = puzzle.numRows();
	Vector<int> partSudu;
	// Checks each row
	for (int i = 0; i < width; i++) {
		partSudu.clear();
		for (int j = 0; j < width; j++) {
			partSudu.add(puzzle[i][j]);
		}
		if (!checkPartInSudoku(partSudu)) return false;
	}
	// checks each cols
	for (int j = 0; j < width; j++) {
		partSudu.clear();
		for(int i = 0; i < width; i++) {
			partSudu.add(puzzle[i][j]);
		}
		if (!checkPartInSudoku(partSudu)) return false;
	}

	// check each 3 x 3 grid
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			partSudu.clear();
			for (int a = 3 * i; a < (3 * i + 3); a++) {
				for (int b = 3 * j; b < (3 * j + 3); b++) {
					partSudu.add(puzzle[a][b]);
				}
			}
			if (!checkPartInSudoku(partSudu)) return false;
		}
	}
	return true;
}


void fillGrid(Grid<int> & grid, Vector<int> & values) {
	for (int i = 0; i < grid.numRows(); i++) {
        	for (int j = 0; j < grid.numCols(); j++) {
			grid[i][j] =  values[grid.numCols() * i + j];
                 }
         }
         return;
 }



void printGrid(Grid<int> & grid) {
	for (int i = 0; i < grid.numRows(); i++) {
		for (int j = 0; j < grid.numCols(); j++) {
			cout << setw(4) << grid[i][j];
		}
		cout << endl;
	}
	return;
}
