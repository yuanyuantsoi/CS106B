/*
 * File: TwoLetterWords.cpp
 * -----------------------------
 *  This program generates a list of the two-letter English words.
 */

#include <iostream>
#include "lexicon.h"
using namespace std;

/* Main Function */

int main() {
	Lexicon english("EnglishWords.dat");
	string word = "xx";
	for (char c0 = 'a'; c0 <= 'z'; c0++) {
		word[1] = c0;
		for (char c1 = 'a'; c1 <= 'z'; c1++) {
			word[2] = c1;
			if (english.contains(word)) {
				cout << word << endl;
			}
		}
	}
	return 0;
}
