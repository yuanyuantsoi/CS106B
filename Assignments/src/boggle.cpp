/* File: boggle.cpp
 * ----------------
 * This file implement the boggle game.
 * Board is set up by default or user defined. 
 */

#include "console.h"
#include "simpio.h"
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include "gwindow.h"
#include "strlib.h"
#include "gobjects.h"
#include "gboggle.h"
#include "grid.h"
#include "random.h"
#include "simpio.h"
#include "set.h"
#include "vector.h"
#include "lexicon.h"
#include "sound.h"
using namespace std;

/* Constants */
//const double GWINDOW_WIDTH = 1200;   
const double GWINDOW_WIDTH = 1800;   
//const double GWINDOW_HEIGHT = GWINDOW_WIDTH / 3 + 70;
const double GWINDOW_HEIGHT = GWINDOW_WIDTH / 3 + 500;
const int BOARD_SIZE = 4;  // board size is set to be BOARD_SIZE * BOARD_SIZE
const double HIGHLIGHT_TIME = 1000; // Used to pause during highlight cubes
const string ASTERISK_SEPARATOR = string(50, '*'); // Used to visiual block separator

/* Type definations */
struct posT{
	int row;
	int col;
};

string StandardCubes[16]  = 
{"AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS", "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
 "DISTTY", "EEGHNW", "EEINSU", "EHRTVW", "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"};
 
string BigBoggleCubes[25]  = 
{"AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM", "AEEGMU", "AEGMNN", "AFIRSY", 
"BJKQXZ", "CCNSTW", "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT", "DHHLOR", 
"DHLNOR", "EIIITT", "EMOTTT", "ENSSSU", "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"};

void GiveInstructions()
{
    cout << endl << "The boggle board is a grid onto which I will randomly distribute " 
	 << "cubes. These 6-sided cubes have letters rather than numbers on the faces, " 
	 << "creating a grid of letters on which you try to form words. You go first, " 
	 << "entering all the words you can find that are formed by tracing adjoining " 
	 << "letters. Two letters adjoin if they are next to each other horizontally, " 
	 << "vertically, or diagonally. A letter can only be used once in the word. Words "
	 << "must be at least 4 letters long and can only be counted once. You score points "
	 << "based on word length: a 4-letter word is worth 1 point, 5-letters earn 2 "
	 << "points, and so on. After your puny brain is exhausted, I, the super computer, "
	 << "will find all the remaining words and double or triple your paltry score." << endl;
	
    string str = getLine("\nHit return when you're ready...");
}

static void Welcome()
{
    cout << "Welcome!  You're about to play an intense game of mind-numbing Boggle. " 
	 << "The good news is that you might improve your vocabulary a bit.  The "
	 << "bad news is that you're probably going to lose miserably to this little "
	 << "dictionary-toting hunk of silicon.  If only YOU had a gig of RAM..." << endl << endl;
}

/* Function prototypes */
static void play();
static void initializeBoard(GWindow & gw, Grid<char> & cubeLetters);
static void configureBoardLetters(Grid<char> & cubeLetters);
static bool askIfCustomizeLetters();
static void customizeBoardLetters(Grid<char> & cubeLetters);
static void setDefaultBoardLetters(Grid<char> & cubeLetters);
static string getBoardLettersFromUser(int minLength);
static void initializeCubes(Grid<string> & cubes);
static void shuffleCubes(Grid<string> & cubes);
static void setRandomFrontSide(Grid<string> & cubes, Grid<char> & frontSide);
static void displayBoard(GWindow & gw, Grid<char> & cubeLetters);
static void labelAllCubes(GWindow & gw, Grid<char> & cubeLetters);
static void humanTurn(GWindow & gw, Lexicon & english, Grid<char> & cubeLetters);
static string getWordFromHuman();
static bool isValidWord(string word, Set<string> & foundWords, Lexicon & english);
static bool findGivenWord(string word, Grid<char> & cubeLetters, Grid<bool> & usedCubes);
static bool recFindGivenWord(string word, int row, int col, Grid<char> & cubeLetters, Grid<bool> & usedCubes);
static bool inBounds(int row, int col, int numRow, int numCol);
static void highlightCubes(GWindow & gw, Grid<bool> & usedCubes);
static void toggleHighlightCubes(GWindow & gw, Grid<bool> & usedCubes, bool highlight);
static void computerTurn(GWindow & gw, Lexicon & english, Grid<char> & cubeLetters);
static void findAllWords(Set<string> & foundWords, Lexicon & english, Grid<char> & cubeLetters);
static void recFindAllWords(string prefix, int row, int col, Grid<bool> & usedCubes, Set<string> & wordsSet, Grid<char> & cubeLetters, Lexicon & english);
static void recordAllWordsForComputer(GWindow & gw, Set<string> & wordsSet);
static void playSound(string soundFilename);

/* Main program */
int main()
{
	play();
	return 0;
}

static void play() {
	Lexicon english("EnglishWords.txt"); // Lexicon used to verify the found words
	Grid<char> cubeLetters(BOARD_SIZE, BOARD_SIZE); // Uset to store the letter in each cube
	GWindow gw(GWINDOW_WIDTH, GWINDOW_HEIGHT); //Set window size;
	while (true) {
		Welcome(); //Printed in a sepreate console.
		GiveInstructions(); //Printed in a sepreate console.
		clearConsole();
		initializeBoard(gw, cubeLetters);
		humanTurn(gw, english, cubeLetters);
		computerTurn(gw, english, cubeLetters);
		string input = getLine("Enter \"y\" to start a new game ");
		if (toLowerCase(input) != "y") break;
		clearConsole();
		gw.clear();
	}
	exitGraphics();
}

static void initializeBoard(GWindow & gw, Grid<char> & cubeLetters) {
	configureBoardLetters(cubeLetters);  // get cube letters from user or by default
	displayBoard(gw, cubeLetters);    // draw the board and add the letters to the cubes
}

static bool askIfCustomizeLetters() {
	while (true) {
		string userInput = getLine("Would you like to customized the board letters? (y/n): ");
		userInput = toLowerCase(userInput);
		if (userInput == "y" || userInput == "yes") return true;
		else if (userInput == "n" || userInput == "no") return false;
		else cout << "Invalid input, please enter 'y' or 'n'." << endl;
	}
}

static void configureBoardLetters(Grid<char> & cubeLetters) {
	if (askIfCustomizeLetters()) {  
		customizeBoardLetters(cubeLetters); // set board letters by user input
	} else {
		setDefaultBoardLetters(cubeLetters); // set board letters by default
	}
}

static void customizeBoardLetters(Grid<char> & cubeLetters) {
	string letters = getBoardLettersFromUser(cubeLetters.numRows() * cubeLetters.numCols());
	for (int row = 0, i = 0; row < cubeLetters.numRows(); row++) {
		for (int col = 0; col < cubeLetters.numCols(); col++) {
			cubeLetters[row][col] = letters[i++];
		}
	}
}

static string getBoardLettersFromUser(int minLength) {
	while (true) {
		string letters = getLine("Enter a string of characters, representing the cubes from left to right, top to bottom: ");
		if (letters.length() >= minLength) return letters;
		cout << "There aren't enough letters to apply to the cubes, please try again." << endl;
	}
}

static void setDefaultBoardLetters(Grid<char> & cubeLetters) {
	Grid<string> cubes(cubeLetters.numRows(), cubeLetters.numCols()); // stores the cube string
	initializeCubes(cubes); // initialize the cubes with string 
	shuffleCubes(cubes); // shuffle the cubes
	setRandomFrontSide(cubes, cubeLetters); // set random char as the front side, and assign it to the cubeLetters
}

static void initializeCubes(Grid<string> & cubes) {
	for (int row = 0, i = 0; row < cubes.numRows(); row++) {
	       for (int col = 0; col < cubes.numCols(); col++) {
		       cubes[row][col] = StandardCubes[i++];
	       }
	}
}

static void shuffleCubes(Grid<string> & cubes) {
	for (int row = 0; row < cubes.numRows(); row++) {
		for (int col = 0; col < cubes.numCols(); col++) {
			int randRow = randomInteger(row, cubes.numRows() - 1);
			int randCol = randomInteger(col, cubes.numRows() - 1);
			string tmp = cubes[randRow][randCol];
			cubes[randRow][randCol] = cubes[row][col];
			cubes[row][col] = tmp;
		}
	}
}

static void setRandomFrontSide(Grid<string> & cubes, Grid<char> & frontSide) {
	for (int row = 0; row < cubes.numRows(); row ++) {
		for (int col = 0; col < cubes.numCols(); col++) {
			string str = cubes[row][col];
			frontSide[row][col] = str.at(randomInteger(0, str.length() - 1));
		}
	}
}


static void displayBoard(GWindow & gw, Grid<char> & cubeLetters) {
	DrawBoard(gw, cubeLetters.numRows(), cubeLetters.numCols());
	labelAllCubes(gw, cubeLetters);
}

static void labelAllCubes(GWindow & gw, Grid<char> & cubeLetters) {
	for (int row = 0; row < cubeLetters.numRows(); row++) {
		for (int col = 0; col < cubeLetters.numCols(); col++) {
			LabelCube(gw, row, col, cubeLetters[row][col]);
		}
	}
}

static void humanTurn(GWindow & gw, Lexicon & english, Grid<char> & cubeLetters) {
	cout << ASTERISK_SEPARATOR << " Enter Human's turn " << ASTERISK_SEPARATOR << endl;
	Set<string> wordsList;
	while (true) {
		string inputWord = getWordFromHuman();
		if (inputWord.empty()) break;
		Grid<bool> usedCubes(cubeLetters.numRows(), cubeLetters.numCols());
		if (isValidWord(inputWord, wordsList, english) && findGivenWord(inputWord, cubeLetters, usedCubes)) {
			wordsList.add(inputWord);
			RecordWordForPlayer(gw, inputWord, Human);
			highlightCubes(gw, usedCubes);
		} else {
			cout << "Invalid word, please try again." << endl;
		}
	}
	cout << ASTERISK_SEPARATOR << " Exiting Human's turn " << ASTERISK_SEPARATOR << endl;
}

static string getWordFromHuman() {
	string input = getLine("Enter found word(press enter to quit): ");
	input = trim(input); //return a new string after removing any whitespace characters from the beginning and end of the argument
	return toLowerCase(input);
}

static bool isValidWord(string word, Set<string> & foundWords, Lexicon & english) {
	return ((word.length() > 3) && (!foundWords.contains(word)) && (english.contains(word)));
}

static bool findGivenWord(string word, Grid<char> & cubeLetters, Grid<bool> & usedCubes) {
	for (int row = 0; row < cubeLetters.numRows(); row++) {
		for (int col = 0; col < cubeLetters.numCols(); col++) {
			if (recFindGivenWord(word, row, col, cubeLetters, usedCubes)) return true;
		}
	}
	return false;
}

static bool recFindGivenWord(string word, int row, int col, Grid<char> & cubeLetters, Grid<bool> & usedCubes) {
	if (word.empty()) return true;
	if (usedCubes[row][col]) return false; // cube is used already
	if (word.at(0) != cubeLetters[row][col]) return false;

	usedCubes[row][col] = true;
	for (int r = row - 1; r <= row + 1; r++) {
		for (int c = col - 1; c <= col + 1; c++) {
			if ((r == row) & (c == col)) continue;
			if (inBounds(r, c, cubeLetters.numRows(), cubeLetters.numCols())) {
				string left = word.substr(1);
				if (tolower(word.at(0)) == 'q') string left = word.substr(2);
				if (recFindGivenWord(left, r, c, cubeLetters, usedCubes)) return true;
			}
		}
	}
	usedCubes[row][col] = false;
	return false;
}

static bool inBounds(int row, int col, int numRow, int numCol) {
	return ((row >= 0) && (row < numRow) && (col >= 0) && (col < numCol));
}

static void highlightCubes(GWindow & gw, Grid<bool> & usedCubes) {
	toggleHighlightCubes(gw, usedCubes, true);
	pause(HIGHLIGHT_TIME);
	toggleHighlightCubes(gw, usedCubes, false);
}

static void toggleHighlightCubes(GWindow & gw, Grid<bool> & usedCubes, bool highlight) {
	for (int row = 0; row < usedCubes.numRows(); row++) {
		for (int col = 0; col < usedCubes.numCols(); col++) {
			if (usedCubes[row][col]) HighlightCube(gw, row, col, highlight);
		}
	}
}

static void computerTurn(GWindow & gw, Lexicon & english, Grid<char> & cubeLetters) {
	cout << ASTERISK_SEPARATOR << " Enter Computer's turn " << ASTERISK_SEPARATOR << endl;
	Set<string> foundWords;
	findAllWords(foundWords, english, cubeLetters);
	recordAllWordsForComputer(gw, foundWords);
	cout << ASTERISK_SEPARATOR << " Exiting Computer's turn " << ASTERISK_SEPARATOR << endl;
}

static void findAllWords(Set<string> & foundWords, Lexicon & english, Grid<char> & cubeLetters) {
	for (int row = 0; row < cubeLetters.numRows(); row++) {
		for (int col = 0; col < cubeLetters.numCols(); col++) {
			Grid<bool> usedCubes(cubeLetters.numRows(), cubeLetters.numCols());
			recFindAllWords("", row, col, usedCubes, foundWords, cubeLetters, english);
		}
	}
}

static void recFindAllWords(string prefix, int row, int col, Grid<bool> & usedCubes, Set<string> & wordsSet, Grid<char> & cubeLetters, Lexicon & english) {
	if (usedCubes[row][col]) return; // cubes already used
	
	usedCubes[row][col] = true;
	char letter = tolower(cubeLetters[row][col]);
	string tail = (letter == 'q') ? "qu" : string(1, letter);
	prefix = toLowerCase(prefix + tail);
	if (!english.containsPrefix(prefix)) {
		usedCubes[row][col] = false;
		return; // return true if prefix is empty
	}
	if (english.contains(prefix) && isValidWord(prefix, wordsSet, english)) wordsSet.add(prefix); // add current word to the words set

	for (int r = row - 1; r <= row + 1; r++) {
		for (int c = col - 1; c <= col + 1; c++) {
			if ((r == row) && (c == col)) continue;
			if (inBounds(r, c, cubeLetters.numRows(), cubeLetters.numCols())) {
				recFindAllWords(prefix, r, c, usedCubes, wordsSet, cubeLetters, english);
			}
		}
	}
	usedCubes[row][col] = false;
}

static void recordAllWordsForComputer(GWindow & gw, Set<string> & wordsSet) {
	int i = 0; // debug print
	for (string word : wordsSet) {
		RecordWordForPlayer(gw, word, Computer);
		string output = integerToString(++i) + "." + word;
		cout << left << setw(30) << output;  // debug print
		if (i % 5 == 0) cout << endl; // debug print
	}
}

static void playSound(string soundFilename) {
	Sound sound(soundFilename);
	sound.play();
}
