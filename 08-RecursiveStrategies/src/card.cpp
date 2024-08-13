/*
 * File: Card.cpp
 * ---------------
 *  This file implements the Card class composed of rank and suit.
 */

#include <string>
#include <cstdlib>
#include <iostream>
#include "strlib.h"
#include "error.h"
#include "card.h"
using namespace std;

/* Function prototypes */
void checkRankInBounds(int num);
void checkSuitInBounds(Suit mySuit);

/*
 * Implementation notes: Constructors
 * -----------------------------------
 *  There are three constructors for the Card class.
 *  The default constructor creates a Card with non value that can be assigned later on;
 *  The one-argument form converts a short string to a Card;
 *  The two-argument form allows you to specify a Card.
 *
 *  The constructor ensure that tht following invariants are maintained:
 *  	1. rank num ranged from 1-13
 *  
 */

Card::Card() { }

Card::Card(string str) {
	int num = stringToInteger(str.substr(0, (str.size() - 2)));
	checkRankInBounds(num);
	char suitCh = str[str.size() - 1];
	switch (suitCh) {
		case 'S': suit = SPADES; break;
		case 'C': suit = CLUBS; break;
		case 'D': suit = DIAMONDS; break;
		case 'H': suit = HEARTS; break;
		default: error("Illegal suit: " + str);
	}
}

Card::Card(int cardRank, Suit cardSuit) {
	checkRankInBounds(cardRank);
	checkSuitInBounds(cardSuit);
	rank = cardRank;
	suit = cardSuit;
}


/*
 * Implementation notes: Getters
 * -----------------------------
 *  The getters return the value of the corresponding instance variable.
 *  No setters are provided to ensure that Card objects are immutable.
 */

int Card::getRank() {
	return rank;
}

Suit Card::getSuit() {
	return suit;
}


/*
 * Implementation notes: toString
 * --------------------------------
 *  Represent the card in form of " rank + suit".
 *  If the rank should be named for certain number: 1 -ace, 11 - jack, 12 - queen, 13 - king. 
 */

string Card::toString() {
	string rankStr = "";
	switch (rank) {
		case 1: rankStr = "A"; break;
		case 11: rankStr = "J"; break;
		case 12: rankStr = "Q"; break;
		case 13: rankStr = "K"; break;
		default: rankStr = integerToString(rank);
	}
	
	string suitStr = "";
	switch (suit) {
		case CLUBS: suitStr = "C"; break;
		case DIAMONDS: suitStr = "D"; break;
		case HEARTS: suitStr = "H"; break;
		case SPADES: suitStr = "S"; break;
		default: suitStr = "???";
	}

	return rankStr + suitStr;
}

/*
 * Implementation notes: overload of operator <<
 */
ostream & operator<<(ostream & os, Card myCard) {
	return os << myCard.toString();
}

/*
 * Implementation notes: overload of operator ++ (suffix)
 * -------------------------------------------------------
 *  The integer argument has no purpose other than to differentiate it
 *  from prefix counterpart.
 */
Suit operator++(Suit & mySuit, int) {
	       Suit old = mySuit;
 	       mySuit = Suit(mySuit + 1);
               return old;
}


/*
 * Implementation notes: checkRankInBounds, checkSuitInBounds
 * ----------------------------------------------------------
 *  Check the rank and suit out of bounds, report error if otherwise.
 */

void checkRankInBounds(int num) {
	if (num > 13 || num < 0) error("Illegal rank: " + num);
}

void checkSuitInBounds(Suit suit) {
	switch (suit) {
		case CLUBS:
		case DIAMONDS:
		case HEARTS:
		case SPADES:  return;
		default: error("Illegal suit: " + suit);
	}
}

