/* File: boggle.cpp
 * ----------------
 * Your name here!
 */
 
#include "console.h"
#include "simpio.h"
#include <iostream>
#include "gwindow.h"
#include "strlib.h"
#include "gobjects.h"
#include "gboggle.h"
using namespace std;

/* Constants */
const double GWINDOW_WIDTH = 1200;
const double GWINDOW_HEIGHT = GWINDOW_WIDTH / 3 + 70;

string StandardCubes[16]  = 
{"AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS", "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
 "DISTTY", "EEGHNW", "EEINSU", "EHRTVW", "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"};
 
string BigBoggleCubes[25]  = 
{"AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM", "AEEGMU", "AEGMNN", "AFIRSY", 
"BJKQXZ", "CCNSTW", "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT", "DHHLOR", 
"DHLNOR", "EIIITT", "EMOTTT", "ENSSSU", "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"};

void GiveInstructions()
{
    cout << endl << "The boggle board is a grid onto which I will randomly distribute " 
	 << "cubes. These 6-sided cubes have letters rather than numbers on the faces, " 
	 << "creating a grid of letters on which you try to form words. You go first, " 
	 << "entering all the words you can find that are formed by tracing adjoining " 
	 << "letters. Two letters adjoin if they are next to each other horizontally, " 
	 << "vertically, or diagonally. A letter can only be used once in the word. Words "
	 << "must be at least 4 letters long and can only be counted once. You score points "
	 << "based on word length: a 4-letter word is worth 1 point, 5-letters earn 2 "
	 << "points, and so on. After your puny brain is exhausted, I, the super computer, "
	 << "will find all the remaining words and double or triple your paltry score." << endl;
	
    string str = getLine("\nHit return when you're ready...");
}

static void Welcome()
{
    cout << "Welcome!  You're about to play an intense game of mind-numbing Boggle. " 
	 << "The good news is that you might improve your vocabulary a bit.  The "
	 << "bad news is that you're probably going to lose miserably to this little "
	 << "dictionary-toting hunk of silicon.  If only YOU had a gig of RAM..." << endl << endl;
}


int main()
{
	Welcome(); //Printed in a sepreate console.
	GiveInstructions(); //Printed in a sepreate console.
    clearConsole();
    GWindow gw(GWINDOW_WIDTH, GWINDOW_HEIGHT); //Game board Layout
    //GLabel *label = new GLabel("Hello", 100.0, 100.0); 
    //label->setFont("Serif-24");
    //gw.draw(label);
    DrawBoard(gw, 4, 4);
	return 0;
}
