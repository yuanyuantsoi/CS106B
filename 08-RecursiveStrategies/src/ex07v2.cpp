#include <iostream>
#include "card.h"
#include "set.h"
#include "vector.h"
using namespace std;

int countFifteens(Vector<Card> & cards);
void recCountFifteens(Vector<Card> & cards, int & count, int index, int target, Vector<Card> solutions);
void displayCards(Vector<Card> & cards);

int main() {
	Vector<Card> cards;
	
	Suit suit = CLUBS;
	int rank = 5;
	cards.add(Card(rank, suit));

	suit = DIAMONDS;
	rank = 5;
	cards.add(Card(rank, suit));

	suit = HEARTS;
	rank = 5;
	cards.add(Card(rank, suit));
	
	suit = SPADES;
	rank = 5;
	cards.add(Card(rank, suit));

	suit = CLUBS;
	rank = JACK;
	cards.add(Card(rank, suit));
	
	displayCards(cards);
	cout << countFifteens(cards) << endl;
	return 0;
}



int countFifteens(Vector<Card> & cards) {
	int count = 0;
	Vector<Card> solutions;
	recCountFifteens(cards, count, 0, 15, solutions);
	return count;
}

void recCountFifteens(Vector<Card> & cards, int & count, int index, int target, Vector<Card> solutions) {
	if (index == cards.size()) {
		if (target == 0) {
			count++;
			displayCards(solutions);
		}
	} else {
		int rank = cards[index].getRank();
		if (rank >= 11) rank = 10;
		recCountFifteens(cards, count, index + 1, target, solutions);
		recCountFifteens(cards, count, index + 1, target - rank, solutions += cards[index]);
	}
}

void displayCards(Vector<Card> & cards) {
	for (int i = 0; i < cards.size(); i++) {
		if (i != 0)  cout << " + ";
		cout << cards[i] ;
	}
	cout << endl;
}
