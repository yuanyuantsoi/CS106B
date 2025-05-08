/*
 * File: Scores.cpp
 * -----------------
 *  This program takes a filename,reads the scores from it, and returns the struct
 *  you defined.
 *  For efficiency's sake, your function should make only a single pass over the file。
 */

#include <iostream>
#include <fstream>
#include "error.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

/* Struct */

struct ScoreSum {
	int minSco;
	int maxSco;
	double aveSco;
};


/* Function prototypes */

string promptUserForFile(ifstream & infile, string prompt = "");
ScoreSum readScoresFromFile(istream & infile);
bool isInBounds(int score);
/* Main Function */

int main() {
	ifstream infile;
	promptUserForFile(infile, "Input file: ");
	ScoreSum scoreSum = readScoresFromFile(infile);
	infile.close();
	cout << "Min score = " << scoreSum.minSco << endl;
	cout << "Max score = " << scoreSum.maxSco << endl;
	cout << "Ave score = " << scoreSum.aveSco << endl;
	return 0;
}


/*
 * Function: promptUserForFile;
 * Usage: string filename = promptUserForFile(infile, prompt);
 * --------------------------------------------------
 *  Prompt the user for filename.
 */
string promptUserForFile(ifstream & infile, string prompt) {
	while (true) {
		cout << prompt;
		string filename;
		getline(cin, filename);
		infile.open(filename.c_str());
		if(!infile.fail()) return filename;
		cout << "Unable to open that file. Try again." << endl;
		if (prompt.empty()) prompt = "Input file: ";
	}
}


/*
 * Fucntion: readScoresFromFile
 * Usage: struct  ScoresStat readScoresFromFile(filename)
 * --------------------------------------------------------
 *  Reads Scores from file.
 */
ScoreSum readScoresFromFile(istream & infile) {
	string scoStr;
	int total,num;
	total = num = 0;
	ScoreSum sum;
	sum.minSco = 101;
	sum.maxSco = 0;
	sum.aveSco = 0;
	while (getline(infile,scoStr)) {
		int score = stringToInteger(scoStr);
		if(isInBounds(score)) {
			total += score;
			if (score > sum.maxSco) sum.maxSco = score;
			if (score < sum.minSco) sum.minSco = score;
			num++;
			sum.aveSco = double (total)/ num;
		} else {
			cout << "Error data: " << score << endl;
		}
	}
	return sum;
}

/*
 * Function:isInBounds
 * Usage: bool valid = isInBounds(score);
 * ------------------------------------------
 *  Checks if the score is in bounds.
 */
bool isInBounds(int score) {
	return ((score >= 0) && (score <= 100));
}
