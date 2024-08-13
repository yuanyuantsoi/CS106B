/*
 * File: WordFrequency.cpp
 * -----------------------
 *  This programs computes the frequency of words in a text file.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "error.h"
#include <fstream>
#include "filelib.h"
using namespace std;

/* Function prototypes */

void countWords(Map<string, int> & wordCounts, istream & infile);
void displayWordCounts(Map<string, int> & wordCounts);


/* Main function */

int main() {
	ifstream infile;
	promptUserForFile(infile, "Input file: ");
	Map<string, int> wordCounts;
	countWords(wordCounts, infile);
	displayWordCounts(wordCounts);
	return 0;
}

/* Helper Function */

void  countWords(Map<string, int> & wordCounts, istream & infile) {
	Vector<string> lines, words;
	string line;
	while (getline(infile, line)) {
		lines.add(line);
		extractWords(line, words);
	}

	for (string word : words) {
		wordCounts.put("word", wordCounts.get("word") + 1);
	}
	1

