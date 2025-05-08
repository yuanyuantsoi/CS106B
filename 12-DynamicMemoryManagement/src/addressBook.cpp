/*
 * File: addressBook.cpp
 * ------------------------------------
 *  Handout#21 - Linked list code
 *  AddressBook implemented using linked list.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
using namespace std;

/* Struct - node structure */
struct Entry{
    string name, address, phone;
    Entry *next;
};


/* 
 * Function: GetNewEntry
 * Usage: Entry *address = GetNewEntry();
 * ----------------------------------------
 *  Create a node, and return its address.
 */
Entry *GetNewEntry() {
    string name = getLine("Enter name (Enter to quit):");
    if (name == "") return NULL;
    Entry *newOne = new Entry; // allocate in heap
    newOne->name = name;
    newOne->address = getLine("Enter address: ");
    newOne->phone = getLine("Enter phone: ");
    newOne->next = NULL; // no one follows
    return newOne;
}

/*
 * Function: PrintEntry
 * Usage: PrintEntry(entry);
 * ------------------------------------
 *  Print the entry.
 */
void PrintEntry(Entry *person) {
    cout << person->name << endl
         << person->address << endl
         << person->phone << endl;
}

/*
 * Function: RecPrintList
 * Usage: RecPrintList(list);
 * ----------------------------------
 *  Print the nodes in the list one by one in 
 *  order.
 */
void RecPrintList(Entry *list) {
    if (list != NULL) {
        PrintEntry(list);
        RecPrintList(list->next);
    }
}

/*
 * Function: RecPrintListRev
 * Usage: RecPrintListRev(list);
 * ---------------------------------
 *  Print the list in reverse order.
 */
void RecPrintListRev(Entry * list) {
    if (list != NULL) {
        RecPrintList(list->next);
        PrintEntry(list);
    }
}
