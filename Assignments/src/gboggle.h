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

/* Function: DrawBoard
 * Usage: DrawBoard(gw, row, col);
 * -----------------------------------
 *  Draw a row * col board.
 */
void DrawBoard(GWindow & gw, int numRows, int numCols);

/*
 * Function: LabelCube
 * Usage: LabelCube(gw, row, col, letter);
 * ------------------------------------------
 *  Label the cube (row, col) with char 'letter'.
 */
void LabelCube(GWindow & gw, int row, int col, char letter);

/*
 * Function: HighlightCube
 * Usage: HighlightCube(gw, row, col, flag);
 * ------------------------------------------
 *  If flag is true, cube(row, col) is highlighted, false otherwise.
 */
void HighlightCube(GWindow & gw, int row, int col, bool flag);

/*
 * Function: RecordWordForPlayer
 * Usage: RecordWordForPlayer(ge, word, player);
 * ------------------------------------------------
 *  Record the word for the player and add it to the canvas gw.
 */
void RecordWordForPlayer(GWindow & gw, string word, playerT player);

#endif
