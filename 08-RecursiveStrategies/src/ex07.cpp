/*
 * File: ex07.cpp
 * ------------------------------------------------------------------
 *  This program implements the countFifteens function, and test it
 *  in the main program.
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "vector.h"
#include "random.h"
#include "card.h"
using namespace std;

/* Function prototypes */

int countFifteens(Vector<Card> & cards);
int countSubsetSum(Vector<Card> & cards, int target);

/* Main program */

int main() {
	Vector<Card> cards;
	
	// Generating the cards deck while printing each one on the console.
	for (int i = 0; i < 5; i++) {
		int rank = randomInteger(1, 13);
		Suit suit = Suit (randomInteger(CLUBS, SPADES));
		Card newCard(rank, suit);
		cout << newCard.toString() << endl;
		cards.add(newCard);
	}

	cout << "There are " << countFifteens(cards) 
		<< " different combinations that sum to 15." << endl;

	return 0;
}

/* Function: countFifteens
 * Usage: int n = countFifteens(cards);
 * -----------------------------------------------------------------
 *  The function takes a vector of Card values and returns the number of
 *  ways you can make 15 from that set of cards.
 */

int countFifteens(Vector<Card> & cards) {
	int target = 15;
	return countSubsetSum(cards, target);
}

int countSubsetSum(Vector<Card> & cards, int target) {
	if (cards.isEmpty()) {
		return target == 0 ? 1 : 0;
	} else {
		int rank = cards[0].getRank();
		if (rank >= 11) rank = 10;
		Vector<Card> newDeck = cards;
		newDeck.remove(0);
		return countSubsetSum(newDeck, target) + countSubsetSum(newDeck, target - rank);
	}
}
