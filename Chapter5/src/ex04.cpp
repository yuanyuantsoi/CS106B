/*
 * File: ex04.cpp
 * ------------------------------------
 *  This program reads in a vector of integers 
 *  from a data file and then displays a histogram
 *  of those numbers.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
#include "filelib.h"
#include "vector.h"
#include "strlib.h"
using namespace std;

void readScoreFromFile(istream & is, Vector<int> & data);

int main() {
	ifstream infile;
	promptUserForFile(infile, "Input file: ");
	Vector<int> scores(11);
	readScoreFromFile(infile, scores);
	for (int i = 0; i < scores.size(); i++) {
		if (i != 10) {
			cout << i << "0s: " << string(scores[i], '*') << endl;
		} else {
			cout << "100: " << string(scores[i], '*') << endl;
		}
	}
	return 0;
}

void readScoreFromFile(istream & is, Vector<int> & data) {
	string line;
	while (getline(is, line)) {
		int score = stringToInteger(line);
		data[score/10]++;
	}
	return;
}
