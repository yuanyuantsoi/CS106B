/*
 * File: ex02.cpp
 * ---------------
 *  This file is used to test the implementation of Card class.
 *  The program exports the card.
 */

#include <string>
#include <iostream>
#include <cstdlib>
#include "card.h"
using namespace std;

int main() {
	for (Suit suit = CLUBS; suit <= SPADES; suit++) {
		for (int rank = ACE; rank <= KING; rank++) {
			cout << " " << Card(rank, suit);
		}
		cout << endl;
	}
	return 0;
}
