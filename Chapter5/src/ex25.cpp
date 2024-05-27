/*
 * File: ex25.cpp
 * --------------
 *  This program displays a table showing the number of words that appear in
 *  the english lexicon, sorted by the length of the word.
 *  !how to keep track of the lengest word.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include "lexicon.h"
#include "vector.h"
using namespace std;

int main() {
	Lexicon english("EnglishWords.dat");
	Vector<int> nWord(50);
	int longest = 0;
	for (string word : english) {
		nWord[word.size()]++;
		if (word.size() > longest) longest = word.size();
	}

	for (int i = 1; i =< longest; i++) {
		cout << setw(2) << set(8) << nWord[i] << endl;
	}
	return 0;
}
