#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void listPermutations(string str);
void recPermutations(string & str, int index);
void swapChars(string & str, int i, int j);

int main() {
	string str = "AAAB";
	listPermutations(str);
	return 0;
}


void listPermutations(string str) {
	recPermutations(str, 0);
}

void recPermutations(string & str, int index) {
	if (index == (str.size() - 1)) {
		cout << str << endl;
	} else {
		for (int i = index; i < str.size(); i++) {
			if (i != index && str[i] == str[index]) continue;
			swapChars(str, i, index);
			recPermutations(str, index + 1);
			swapChars(str, i, index);
		}
	}
}


void swapChars(string & str, int i, int j) {
	char tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
}
