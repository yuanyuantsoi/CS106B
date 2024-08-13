/*
 * File: ex05.cpp
 * ----------------------------------------------------
 *  The program implements EmbeddedWords function.
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "set.h"
#include "lexicon.h"
using namespace std;

/* Function prototypes */

Set<string> embeddedWords(string startWord);

/* Main program */

int main() {
	string word = getLine("Enter starting word: ");
	Set<string> wordsList = embeddedWords(word);
	cout << "The embedded words are: " << endl;
	for (string s : wordsList) {
		cout << s << endl;
	}
	return 0;
}

/*
 * Function: embeddedWords
 * Usage: Set<string> wordsList = embeddedWords(startWord);
 * -----------------------------------------------------------
 *  The program finds all english words that can be formed by 
 *  taking some subset of letters in order from a given 
 *  starting word.
 */

Set<string> embeddedWords(string startWord) {
	Set<string> result;
	Lexicon english("EnglishWords.dat");
	if (startWord == "") {
		result += "";
	} else {
		for (int i = 0; i < startWord.length(); i++) {
			char ch = startWord[i];
			for (string s : embeddedWords(startWord.substr(i))) {
				if (english.contains(s)) result += s;
			}
		}
	}
	return result;
}
