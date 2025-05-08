#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include "set.h"
#include "lexicon.h"
using namespace std;

string digitToChar(char ch);
void listMnemonics(string str);
void recListMnemonics(Lexicon & english, string numStr, int index, string prefix);

int main() {
	listMnemonics("723");
	return 0;
}

void listMnemonics(string str) {
	Lexicon english("EnglishWords.txt");
	recListMnemonics(english, str, 0, "");
}
 
string digitToChar(char ch) {
	switch (ch) {
	case '2': return "ABC";
	case '3': return "DEF";
	case '4': return "GHI";
	case '5': return "JKL";
	case '6': return "MNO";
	case '7': return "PQRS";
	case '8': return "TUV";
	case '9': return "WXYZ";
	default: return "";
	}
}
void recListMnemonics(Lexicon & english, string numStr, int index, string prefix) {
	if (index == numStr.size()) {
		if (english.contains(prefix)) cout << prefix << endl;
		return;
	}
	string letters = digitToChar(numStr[index]);
	for (int i = 0; i < letters.size(); i++) {
		recListMnemonics(english, numStr, index + 1, prefix + letters[i]);
	}
}
