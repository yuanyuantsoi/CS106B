#include <string>
#include <iostream>
#include <iomanip>
#include "vector.h"
#include "random.h"
#include "console.h"
using namespace std;

int main() {
	//setConsoleFont("monospace");
	setConsoleFont("Courier New-bold-20");
	Vector<string> words;
	words.add("apple");
	words.add("banan");
	words.add("cheryyyyyyyyyyyyyyyyyy");
	for (int i = 0; i <= 30; i++) {
		//string output = integerToString(i) + "." + words[randomInteger(0, 1)];
		string output = integerToString(i) + "." + words[randomInteger(0, 1)];
		//string output = words[randomInteger(0, 1)];
		cout << left << setw(30) << output << "|";
		if (i % 4 == 0) cout << endl;
	}
	return 0;
}
