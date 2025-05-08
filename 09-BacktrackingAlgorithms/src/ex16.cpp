/*
 * File: ex16.cpp
 * ----------------------------------
 *  Answear to the CS106B chapter09ex16.
 *  THe program implement the Boggle game.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include "grid.h"
#include "vector.h"
#include "lexicon.h"
#include "set.h"
using namespace std;

/* Constants */
const int SIZE = 4; // The size of the boggle board: 4 x 4
const string DICT_FILE = "EnglishWords.txt"; // The file name of the lexicon file.
const int NUM_PER_LINE = 5; // Print format of wordsFound: 5 words per line;
const int WORDS_SPACING = 15; // Print format of wordsFound: 10 spacing between adjacent words;

void initBoggleBoard(Grid<char> & board);
void findBoggleWords(Grid<char> & board, const Lexicon & english, Set<string> & wordsFound);
bool recFindBoggleWords(int row, int col, string soFar, Grid<char> & board, 
                        const Lexicon & english, Set<string> & wordsFound, Grid<bool> & cubeUsed);
bool isValidWord(string str, const Lexicon & english);
void printWordsList(Set<string> & list);

int main() {
    Lexicon english(DICT_FILE);

    Grid<char> boggleBoard;
    initBoggleBoard(boggleBoard);
    
    Set<string> wordsFound;
    findBoggleWords(boggleBoard, english, wordsFound);

    printWordsList(wordsFound);
    return 0;
}

void initBoggleBoard(Grid<char> & board) {
    board.resize(SIZE,SIZE);

    board[0][0] = 'X';
    board[0][1] = 'C';
    board[0][2] = 'E';
    board[0][3] = 'R';

    board[1][0] = 'I';
    board[1][1] = 'M';
    board[1][2] = 'G';
    board[1][3] = 'A';

    board[2][0] = 'N';
    board[2][1] = 'O';
    board[2][2] = 'M';
    board[2][3] = 'L';

    board[3][0] = 'G';
    board[3][1] = 'Z';
    board[3][2] = 'R';
    board[3][3] = 'P';
}

void findBoggleWords(Grid<char> & board, const Lexicon & english, Set<string> & wordsFound) {
    for (int row = 0; row < board.numRows(); row++) {
        for (int col = 0; col < board.numCols(); col++) {
           // if (board[row][col] != 'A') continue; // Debug 
            string soFar = "";
            Grid<bool> cubeUsed(SIZE, SIZE);  // Default value =  false
           // cout << cubeUsed.toString() << endl;
            recFindBoggleWords(row, col, soFar, board, english, wordsFound, cubeUsed);
        }
    }
}

/*
 * Function: recFindBoggleWords
 * Usage: recFindBoggleWords(row, col, soFar, board, english, wordsFound, cubeUsed);
 * -----------------------------------------------------------------------------------
 *  The function is implemented using recursion backtracking.
 *  First, append the current cube(row, col) to the end of the string 'soFar';
 *  Check the string soFar:
 *      add it to the set(wordsFound), if it is a valid word.
 *      return false, if is not prefix to any words.
 *      go on if it is prefix to certain words:
 *          try out every unused cube around the cube(row, col), 
 *           set the cube to unused if the recursion return false.
 *      return false if every option is explored.
 */
bool recFindBoggleWords(int row, int col, string soFar, Grid<char> & board, const Lexicon & english,
                        Set<string> & wordsFound, Grid<bool> & cubeUsed) { 
    // Add the current cube to the string
    soFar += board[row][col];
    cubeUsed[row][col] = true;

    // Add the soFar to the set, if is is a word in the english.
    if (isValidWord(soFar, english)) wordsFound.add(soFar);
    
    // Return to the upper level, if the string soFar is not prefix to any words.
    if (!english.containsPrefix(soFar)) {
        return false;
    }

    for (int i = (row - 1); i <= (row + 1); i++) {
        for (int j =(col - 1); j <= (col + 1); j++) {
            if ((i == row) && (j == col)) continue;
            if (board.inBounds(i, j) && !cubeUsed[i][j]) {
                if (!recFindBoggleWords(i, j, soFar, board, english, wordsFound, cubeUsed)) {
                    cubeUsed[i][j] = false;
                }
            }
        }
    }
    // Tryied every possible options, and return to the upper level, set the current as unused.
   return false;
}

bool isValidWord(string str, const Lexicon & english) {
    return (str.size() >= 4) && (english.contains(str));
}


void printWordsList(Set<string> & list) {
    cout << "Found Words: " << endl;
    int count = 0;
    for (string str : list) {
        count++;
        cout << left << setw(WORDS_SPACING) << str;
        if (count % 5 == 0) cout << endl;
    }
    cout << endl;
}
    
    
    
