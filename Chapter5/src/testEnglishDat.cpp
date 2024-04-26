/*
 * File: testEnglishDat.cpp
 * ---------------------------
 *  This program is used to test the EnglishWords.dat
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
#include "lexicon.h"
using namespace std;

int main() {
	string word = getLine("> ");
	Lexicon english("EnglishWords.dat");
	if (english.contains(word)) {
		cout << word << " is contained in the lexicon." << endl;
	} else {
		cout << word << " is not contained in the lexicon." << endl;
	}
	return 0;
}
