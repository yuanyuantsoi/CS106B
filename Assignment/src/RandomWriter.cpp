/*
 * File: RandomWriter.cpp
 * -----------------------------
 *  Assignment2- ADT Client Extravaganza
 *  This  program reads a source text, build an order k Markov 
 *  model for it, and generate random output that follws the 
 *  frequence pattern of  model.
 */

#include <iostream>
#include <fstream>
#include "filelib.h"
#include "simpio.h"
#include "map.h"
#include "vector.h"
#include "random.h"
#include <string>
#include <cctype>
using namespace std;

string findStartSeed(Map<string, Vector<char> > & letterFreq);
void buildKMarkovModel(Map<string, Vector<char> > & letterFreq, int k, ifstream & infile);
void generateRandomText(Map<string, Vector<char> > & letterFreq, int num);
void printMap(Map<string, Vector<char> > & letterFreq) {
	for (string seed : letterFreq) {
		cout << " seed = " << seed << endl;
		cout << " follow up size = " << letterFreq[seed].size() << endl;
		cout << " follow up char list: " << endl;
	        for (int i = 0; i < letterFreq[seed].size(); i++) {
			cout << "follow up " <<  i << letterFreq[seed][i] << endl;
		}
		cout << endl;	
	}
}

int main() {
	cout << "This program reads a source text, and build a Markov model." << endl;
	ifstream infile;
	promptUserForFile(infile, "Input source file: ");
	int k = getInteger("Enter the order of the Markov model k = ");	
	Map<string, Vector<char> > letterFreq;
	buildKMarkovModel(letterFreq, k, infile);
	int num = getInteger("Enter the num of characters generated by the Markov model: ");
	generateRandomText(letterFreq, num);
	//printMap(letterFreq); // --Debug Print
	return 0;
}

/*
 * Function: buildKMarkovModel
 * Usage: void buildMarkovModel(letterFreq, k, infile);
 * ---------------------------------------------------
 *  This function reads the infile char by char, and store the letterfreq accroding to
 *  the order k into the map.
 */
void buildKMarkovModel(Map<string, Vector<char> > & letterFreq, int k, ifstream & infile) {
	int ch;
	string seed = "";
	while ((ch = infile.get()) != EOF) {
		char Ch = char (ch);
		if (seed.size() < k) {
			seed += Ch;
		} else if (seed.size() == k) {
			if (letterFreq.containsKey(seed)) {
				letterFreq[seed].add(Ch);
			} else {
				if (ch == EOF) cout << "EOF" << endl;
				Vector<char> newVec;
				newVec.add(Ch);
				letterFreq.put(seed, newVec);
			}
			seed = seed.substr(1) + Ch;
		}
	}
	infile.close();
}

/*
 * Function: generateRandomText
 * Usage: void genrateRandomText(letterFreq, num);
 * ------------------------------------------------
 *  Generates the random text.
 *  First find the most often repeated in the source to start the random writing.
 */
void generateRandomText(Map<string, Vector<char> > & letterFreq, int num) {
	int totalWords = 0;
	string seed = findStartSeed(letterFreq);
	char followChar;
	string outputStr = seed;
	while (totalWords < num) {
		cout << outputStr;
		totalWords += outputStr.size();
		if (letterFreq.containsKey(seed)) {
			int index = randomInteger(0, (letterFreq[seed].size() - 1));
			char followCh = letterFreq[seed][index];
			seed = seed.substr(1) + followCh;
			outputStr = followCh;
		} else {
			break;
		}
	}
}


/*
 * Function: findStartSeed
 * Usage: string str = findStartSeed(letterFreq);
 * -----------------------------------------------
 *  Iterate through the letterFreq map, find tht larggest vector in the map
 *  and return its key as the start seed.
 */
string findStartSeed(Map<string, Vector<char> > & letterFreq) {
	string startSeed = "";
	int larggestSize = 0;
	for (string seed : letterFreq) {
		if (letterFreq[seed].size() > larggestSize) {
			startSeed = seed;
			larggestSize = letterFreq[seed].size();
		}
	}
	return startSeed;
}
			
