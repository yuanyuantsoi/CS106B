/*
 * File: TestLexicon.cpp
 * --------------------------------
 *  c++ programming abstrations
 */

#include <iostream>
#include <string>
#include "filelib.h"
#include "lexicon.h"
#include "set.h"
using namespace std; 

int main() {
	Lexicon english("EnglishWords.txt");
	cout << english.containsPrefix("");
	return 0;
}
