/*
 * File: card.h
 * ------------------
 *  This file exports the Card class and Suit type.
 */

#ifndef _card_h
#define _card_h

#include <string>
#include <iostream>
#include "error.h"

/* Suit type */
enum Suit  { CLUBS, DIAMONDS, HEARTS, SPADES };

/* Constants name for some of the rank*/
const int ACE = 1;
const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;

/* 
 * Class: Card
 * --------------
 *  The card class is used to represent a standard playing card, which
 *  is identified by rank and suit.
 */

class Card{

public:

/*
 * Constructor: Card
 * Usage: Card myCard;
 *        Card myCard(str);
 *        Card myCard(cardRank, cardSuit);
 * ----------------------------------
 *  Creates a Card object.
 *  The default constructor creates a card that can later be assigned a value.
 *  The constructor that takes a short string name like "10S" or "JD";
 *  The constructor that takes separate values for the rank and suti.
 */
	Card();
	Card(std::string str);
	Card(int cardRank, Suit cardSuit);



/*
 * Method: Getters
 * Usage: int rank = card.getRank();
 * 	  Suit suit = card.getSuit();
 * ------------------------------
 *  Return the rank and suit of card.
 */
	int getRank();
	Suit getSuit();

/*
 * Method: toString
 * Usage: string str = card.toString();
 * -------------------------------------
 *  Return a string representation of the card in the form of "AS", "5S".
 */
	std::string toString();


/* Private sections */
private:

/* Instances variables */
	int rank;
	Suit suit;
};

/*
 * Operator: <<
 * Usage: cout << card;
 * --------------------
 *  Overloads the << operator so that it is able to display card values.
 */

std::ostream & operator<<(std::ostream & os, Card myCard);

/*
 * Operator: ++
 * Usage: suit++
 * ---------------
 *  Overloads the ++ operator(suffix) so suit++ would make sense in for loop.
 */

Suit operator++(Suit & mySuit, int);

#endif
