/*
 * File: RemoveSpam.cpp
 * -----------------------
 *  Section Handout #2
 *  This program constructs the eMailMsg datatype and implements the 
 *  function RemoveSpam that will remove all elements whose subject
 *  begins with the strings"SPAM";
 */

#include <iostream>
#include "vector.h"
#include "simpio.h"
#include "strlib.h"
#include <string>
using namespace std;

struct eMailMsg {
	string to; // i. e. "professor@stanford.edu"
	string from; // i. e. "student@stanford.edu"
	string message; // body of message;
	string subject; // i.e. "CS106 Rocks!"
	int date;
	int time;
};

void removeSpam(Vector<eMailMsg> & mailbox);

int main() {
	Vector<eMailMsg> mailbox;
	eMailMsg mail1, mail2, mail3, mail4;
	mail1.to = "aa";
	mail1.from = "bb";
	mail1.message = "";
	mail1.subject = "CS106B";
	
	mail2.subject = "SPAM";

	mail3.subject = "ROCKS";

	mail4.subject = "SPAMMAIL";

	mailbox.add(mail1);
	mailbox.add(mail2);
	mailbox.add(mail3);
	mailbox.add(mail4);

	removeSpam(mailbox);
	
	cout << " Mails after removing spam mail: " << endl;
	for (int i = 0; i < mailbox.size(); i++) {
		cout << mailbox[i].subject << endl;
	}
	return 0;

}



void removeSpam(Vector<eMailMsg> & mailbox) {
	for (int i = mailbox.size() - 1; i >= 0; i--) {
		if (startsWith(toUpperCase(mailbox[i].subject), "SPAM")) {
			mailbox.remove(i);
		}
	}
}
