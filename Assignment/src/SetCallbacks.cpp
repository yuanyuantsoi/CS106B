/*
 * File: SetCallbacks.cpp
 * -------------------------------------
 *  Section Handout#3 - Problem 1: set callbacks
 *  The program writes a comparison callback that
 *  compares entries using last name as the primary
 *  key and first name as the secondary key.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include "set.h"
#include "simpio.h"
using namespace std;

struct entryT {
	string firstName;
	string lastName;
	string phoneNumber;
};

/* Constants */

const int NAME_WIDTH = 20;

/* Function prototypes */

int compareEntry(entryT a, entryT b);
void initializeAddressBook(Set<entryT> &setE);
void printAddressBook(Set<entryT> & addressBook);
int compareStrings(string a, string b);

/* Main program */
int main() {
	//Set<entryT> addressBook;  
	//Could compile, wont be able to use the member function.
	
	Set<entryT> addressBook(compareEntry);
	Set<string> stringSet;
	//Set<string> stringSet(compareStrings);

	// Initialize the address book
	while (true) {
		if (getLine("Enter 'Q' to quit: ") == "Q") break;
		cout << endl << "Enter new entry: " << endl;
		entryT entry;	
		entry.firstName = getLine("Enter first name: ");
		entry.lastName = getLine("Enter last name: ");
		entry.phoneNumber = getLine("Enter phone number: ");
		addressBook.add(entry);
		cout << endl;
	}

	//Print entries in the address book
	printAddressBook(addressBook);

	//Initialize the string set
	stringSet.add("Word");
	stringSet.add("word");

	for (string s : stringSet) {
		cout << s << endl;
	}
	return 0;
}

int compareStrings(string a, string b) {
	a = toLowerCase(a);
	b = toLowerCase(b);
	if (a == b) return 0;
	if (a > b) return 1;
	else return -1;
}

void printAddressBook(Set<entryT> & addressBook) {
	cout << endl << "Entries in the address book: " << endl;
	int i = 1;
	for (entryT entry : addressBook) {
		cout << i++ << ". Name: " << setw(NAME_WIDTH) << left << entry.firstName + " · " + entry.lastName
			<< "\t Phone number: " << entry.phoneNumber << endl;
	}
}

int compareEntry(entryT a, entryT b) {
	if (a.lastName > b.lastName) return 1;
	if (a.lastName < b.lastName) return -1;
	if (a.firstName == b.firstName) return 0;
	if (a.firstName > b.firstName) return 1;
	else return -1;
}
