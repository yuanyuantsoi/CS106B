#include <iostream>
#include "gwindow.h"
#include "gobjects.h"
#include "vector.h"
#include "grid.h"
#include "simpio.h"
#include "error.h"
#include "stack.h"

using namespace std;

// Structure used to indicate location of queens on chessboard.
struct Location {
    int row;
    int col;
};

// Constant
const int SQUARE_LENGTH = 50;

// Function prototypes
bool placeNQueensOnChessboard(int n, Grid<bool> &chessboard, Stack<Location> &queensLoc, Vector<bool> &rows, Vector<bool> &cols, Vector<bool> &d1, Vector<bool> &d2);
void drawChessboard(GWindow &gw, int n);
void drawQueensOnChessboard(GWindow &gw, Stack<Location> queensLoc);
void markAttackArea(int row, int col, Grid<bool> &chessboard, Vector<bool> &rows, Vector<bool> &cols, Vector<bool> &d1, Vector<bool> &d2, bool value);

/* Main program */
int main() {
    // Get the N
    int n = getInteger("Enter N = ");
    
    // Found out the solution if there is any
    Grid<bool> chessboard(n, n);
    Stack<Location> queensLoc;
    Vector<bool> rows(n, false), cols(n, false), d1(2 * n - 1, false), d2(2 * n - 1, false);
    bool solution = placeNQueensOnChessboard(n, chessboard, queensLoc, rows, cols, d1, d2);
    
    // Print out the solution if there is any.
    if (solution) {
        GWindow gw(n * SQUARE_LENGTH, n * SQUARE_LENGTH);
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
 * Usage: if(placeNQueensOnChessboard(n, chessboard, queensLoc, rows, cols, d1, d2))
 * ------------------------------------------------------------------------
 *  Return the result of place n queens on chessboard.
 */
bool placeNQueensOnChessboard(int n, Grid<bool> &chessboard, Stack<Location> &queensLoc, Vector<bool> &rows, Vector<bool> &cols, Vector<bool> &d1, Vector<bool> &d2) {
    static int col = 0;
    if (col >= n) return true;
    
    for (int row = 0; row < n; ++row) {
        if (!rows[row] && !cols[col] && !d1[row - col + n - 1] && !d2[row + col]) {
            // Place queen
            queensLoc.push({row, col});
            chessboard[row][col] = true;
            markAttackArea(row, col, chessboard, rows, cols, d1, d2, true);

            // Move to the next column
            if (placeNQueensOnChessboard(n, chessboard, queensLoc, rows, cols, d1, d2)) return true;

            // Backtrack
            markAttackArea(row, col, chessboard, rows, cols, d1, d2, false);
            chessboard[row][col] = false;
            queensLoc.pop();
        }
    }

    ++col; // Move to the next column
    return false;
}

/*
 * Function: markAttackArea
 * Usage: markAttackArea(row, col, chessboard, rows, cols, d1, d2, true/false)
 * -------------------------------------------------------------------------
 *  Marks or unmarks the attack areas for the queen at (row, col).
 */
void markAttackArea(int row, int col, Grid<bool> &chessboard, Vector<bool> &rows, Vector<bool> &cols, Vector<bool> &d1, Vector<bool> &d2, bool value) {
    rows[row] = cols[col] = value;
    d1[row - col + chessboard.numRows() - 1] = value;
    d2[row + col] = value;
}

/*
 * Function: drawChessboard
 * Usage: drawChessboard(gw, n);
 * ----------------------------------------------------------------------
 *  Draw an n x n chessboard on gw.
 */
void drawChessboard(GWindow &gw, int n) {
    bool whiteFlag = true;
    for (int i = 0; i < n; ++i) {
        whiteFlag = (i % 2 == 0);
        for (int j = 0; j < n; ++j) {
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
 *  Yellow oval is used to mark the queen position.
 */
void drawQueensOnChessboard(GWindow &gw, Stack<Location> queensLoc) {
    while (!queensLoc.isEmpty()) {
        Location loc = queensLoc.pop();
        int height = loc.row * SQUARE_LENGTH;
        int width = loc.col * SQUARE_LENGTH;
        gw.setColor("yellow");
        gw.fillOval(width, height, SQUARE_LENGTH, SQUARE_LENGTH);
    }
}

