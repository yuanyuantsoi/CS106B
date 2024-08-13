/*
 * File: ex24.cpp
 * ---------------
 *  This program generates words that allow s-tile(in scrabble) attached on both 
 *  ends of the word.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include "simpio.h"
#include "set.h"
#include "lexicon.h"
using namespace std;

int main() {
	Lexicon english("EnglishWords.dat");
	Set<string> wordSet;
	for (string word : english) {
		if (word[0] == 's && english.contains(word.substr(1)))
			wordeSet.add(word.substr(1));
	}

	for (string word : wordSet) {
		if (!english.contains(word + 's'))
			wordSet.remove(word);
	}

	return 0;
}
