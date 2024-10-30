/*
 * File: ex05v2.cpp
 * -------------------------
 *  Embededwords
 */

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include "strlib.h"
#include "lexicon.h"
#include "set.h"
#include "simpio.h"
using namespace std;

/* Function prototype */

void embeddedWords();
void recEmbeddedWords(string soFar, string rest, Set<string> & words, Lexicon & english);
void displaySet(Set<string> & set);

/* Main program */

int main() {
	embeddedWords();
	return 0;
}


/*
 * Function: embeddedWords;
 * Usage: embeddedWords();
 * -----------------------------
 *  Finds all the embedded words that can 
 *  be formed by taking some of letters in order from 
 *  a given starting word.
 */
void embeddedWords() {
	Lexicon english("EnglishWords.txt");
	string word = getLine("Enter starting word: ");
	Set<string> embeddedWords;
	recEmbeddedWords("", word, embeddedWords, english);
	displaySet(embeddedWords);
}

/*
 * Function: displaySet
 * Usage: displaySet(set);
 * ------------------------------------
 *  Print all the string in set.
 */
void displaySet(Set<string> & set) {
	cout << "The embedded words are: " << endl;
	for (string s : set) {
		cout << setw(4) << "" << s << endl;
	}
}

/*
 * Function: recEmbeddedWords
 * Usage: recEmbededdedWords(soFar, rest, words, english);
 * ----------------------------------------------------------
 *  The function finds all the embeddedwords using recursion.
 *  If the rest is empty, to see if the string soFar is an valid english words.
 * 	If the english contains the word soFar, add it to the words set.
 * If the rest is not empty, recursion from here both the next char is in/out of
 * the soFar string.
 */
void recEmbeddedWords(string soFar, string rest, Set<string> & words, Lexicon & english) {
	if (rest == "") {
		if (english.contains(soFar)) words.add(soFar);
	} else {
		recEmbeddedWords(soFar + rest[0], rest.substr(1), words, english);
		recEmbeddedWords(soFar, rest.substr(1), words, english);
	}
}

