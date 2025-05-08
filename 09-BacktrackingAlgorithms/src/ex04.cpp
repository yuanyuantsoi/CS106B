#include <iostream>
#include "grid.h"
using namespace std;

void fillRegion(Grid<bool> & pixels, int row, int col);

int main() {
	Grid<bool> pixels(10,10);
	fillRegion(pixels, 5, 5);
	return 0;
}


void fillRegion(Grid<bool> & pixels, int row, int col) {
	if (row >= pixels.numRows() || col >= pixels.numCols())  return;
	if (pixels[row][col] == false)  { // White grid
		pixels[row][col] = true;
		fillRegion(pixels, row - 1, col - 1);
		fillRegion(pixels, row - 1, col);
		fillRegion(pixels, row - 1, col + 1);
		fillRegion(pixels, row, col - 1);
		fillRegion(pixels, row, col);
		fillRegion(pixels, row, col + 1);
		fillRegion(pixels, row + 1, col - 1);
		fillRegion(pixels, row + 1, col);
		fillRegion(pixels, row + 1, col + 1);
	}
}
