#include <iostream>
#include "vector.h"
#include "domino.h"
using namespace std;

bool recFormsDominoChain2(Vector<Domino> & soFar, Vector<Domino> & rest);
bool formsDominoChain(Vector<Domino> & dominos);
bool recFormsDominoChain(Vector<Domino> & dominos, int n);
bool swapDominos(Vector<Domino> & dominos, int n, int m);
int findMatchedNumber(Vector<Domino> & dominos, int target, int n);
void printDominoVector(Vector<Domino> & vec);
bool reverseDomino(Vector<Domino> & dominos, int n);
void moveDomino(Vector<Domino> & vec1, Vector<Domino> & vec2, int index);
void moveBackDomino(Vector<Domino> & vec1, Vector<Domino> & vec2, int index);

int main() {
	// Create dominos vector
	Vector<Domino> dominos;
	Domino d1(1, 4);
	Domino d2(1, 6);
	Domino d3(2, 6);
	Domino d4(3, 4);
	
	dominos.add(d1);
	dominos.add(d2);
	dominos.add(d3);
	dominos.add(d4);
	
	// Print the vector
	printDominoVector(dominos);
	
	// Form the domino chain
	formsDominoChain(dominos);
	
	// Print the vector
//	printDominoVector(dominos);
	
	return 0;
}

void moveDomino(Vector<Domino> & vec1, Vector<Domino> & vec2, int index) {
	vec1 += vec2[index];
	vec2.remove(index);
	cout << "vec1" << endl;
	printDominoVector(vec1);
}

void moveBackDomino(Vector<Domino> & vec1, Vector<Domino> & vec2, int index) {
	vec2.insert(index, vec1[vec1.size() - 1]);
	vec1.remove(vec1.size() - 1);
}

bool recFormsDominoChain2(Vector<Domino> & soFar, Vector<Domino> & rest) {
	if (rest.isEmpty()) {
		return true;
	} else {
		for (int i = 0; i < rest.size(); i++) {
			int target = soFar.isEmpty() ? 0 : soFar[soFar.size() - 1].getRightDots();
			if (target == rest[i].getRightDots()) reverseDomino(rest, i);
			if (target == 0 || target == rest[i].getLeftDots()) {
				moveDomino(soFar, rest, i);
				if (recFormsDominoChain2(soFar, rest)) {
					return true;
				} else {
					moveBackDomino(soFar, rest, i);
				}
			}
		}
		return false;
	}
}
				
bool recFormsDominoChain(Vector<Domino> & dominos, int n) {
	if (n == dominos.size()) return true;
	int tailNum = dominos[n - 1].getRightDots();
	int matchedIndex;
	int startIndex = n;
	while ((matchedIndex = findMatchedNumber(dominos, dominos[n - 1].getRightDots(), startIndex)) != -1) {
		swapDominos(dominos, n, matchedIndex);
		if (dominos[n].getLeftDots() != tailNum) reverseDomino(dominos, n);
		if (recFormsDominoChain(dominos, n + 1)) {
			return true;
		} else {
			swapDominos(dominos, n, matchedIndex);
			startIndex = matchedIndex + 1;
		}
	}
	return false;
}

bool reverseDomino(Vector<Domino> & dominos, int n) {
	if (n < 0 || n >= dominos.size()) return false;
	Domino rev(dominos[n].getRightDots(), dominos[n].getLeftDots());
	dominos[n] = rev;
	return true;
}
bool swapDominos(Vector<Domino> & dominos, int n, int m) {
	if (n == m) return true;
	if (n < 0 || n >= dominos.size() || m < 0 || m >= dominos.size()) return false;
	Domino t = dominos[n];
	dominos[n] = dominos[m];
	dominos[m] = t;
	return true;
}

int findMatchedNumber(Vector<Domino> & dominos, int target, int n) {
	for (int i = n; i < dominos.size(); i++) {
		if (target == dominos[i].getLeftDots() || target == dominos[i].getRightDots()) return i;
	}
	return -1;
}

bool formsDominoChain(Vector<Domino> & dominos) {
	Vector<Domino> result;
	printDominoVector(result);
	return recFormsDominoChain2(result, dominos); 	
/*
	for (int i = 0; i < dominos.size(); i++) {
		swapDominos(dominos, 0, i);
		if (recFormsDominoChain(dominos, 1)) {
			return true;
		} else {
			reverseDomino(dominos, 0);
			if (recFormsDominoChain(dominos, 1)) return true;
		}
	}
	return false;
*/
}


void printDominoVector(Vector<Domino> & vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].getLeftDots() << "-" << vec[i].getRightDots() << " ";
	}
	cout << endl;
}
