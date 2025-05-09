/*
 * File: gboggle.h
 * ------------------------------
 *  The gboggle.h file defines the interface for a set of
 *  functions that
 *      
 *      1. Draw the boggle board
 *      2. Manage the word lists
 *      3. Update the scoreboard
 */

#ifndef _gboggle_h
#define _gboggle_h

#include "error.h"

enum playerT {Human, Computer};

const int MAX_DIMENSION = 5;

void DrawBoard(GWindow & gw, int numRows, int numCols);

void LabelCube(GWindow & gw, int row, int col, char letter);

#endif
