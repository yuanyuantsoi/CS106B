/*
 * File: ex01.cpp
 * ----------------
 *  The program is used to test the implementation of Domino class by creating 
 *  a full set of dominos from 0-0 to 6-6 and then displays those dominos on the console.
 */

#include <string>
#include <iostream>
#include "set.h"
#include "vector.h"
#include "domino.h"
using namespace std;

/* Main program*/
int main() {
	Vector<Domino> deck;
	for (int i = 0; i <= 6; i++) {
		for (int j = 0; j <= i; j++) {
			Domino dmo(i, j);
			deck.add(dmo);
		}
	}
	
	cout << "A full set of domino has " << deck.size() << endl;
	for (int i = 0; i < deck.size(); i++) {
		Domino dmo = deck[i];
		cout << dmo << endl;
	}
	
	return 0;
}
