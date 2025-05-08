#include <iostream>
#include <iomanip>
#include <string>
#include "strlib.h"
#include "error.h"
#include "vector.h"
#include "simpio.h"
#include "error.h"
using namespace std;

/*
 * Type: Player
 * -----------------
 *  Used to differentiates the human and computer players.
 */

enum Player { HUMAN, COMPUTER};

/*
 * Function: opponent
 * Usage: Player p1 = opponent(p2);
 * --------------------------------
 *  Used to return the opponent of the player.
 */

Player opponent(Player p) {
    return (p == HUMAN) ? COMPUTER : HUMAN;
}

// Set human as the stating player.

const Player STARTING_PLAYER = HUMAN;

/*
 * Struct: moveT
 * ---------------
 *  Indicated the which row to take coins and the number of coins being taken.
 */
struct moveT {
    int row;
    int nTaken;
};

/* Constants */
const int MAX_DEPTH = 1000;     // Limit of the recursive search
const int WINNING_POSITION = 1000;      // Rating for winning 
const int LOSING_POSITION = -WINNING_POSITION;      // Rating for losing
const int NUM_ROWS = 3;     // Num of rows of the coins
const int NUM_COINS_R0 = 3;     // Num of coins in row 0
const int NUM_COINS_R1 = 4;     // Num of coins in row 1;
const int NUM_COINS_R2 = 5;     // Num of coins in row 2;


/* 
 * Class: NimVariant
 * ----------------------
 *  Plays the most common variant of Nim, the coins are not combined into a 
 *  single pile but are instead arranged in three rows like this:($ is used to indicate
 *  coin)
 *      Row 0: $ $ $
 *      Row 1: $ $ $ $
 *      Row 2: $ $ $ $ $
 *
 *  A move consists of taking any number of coins, subject to the condition that
 *  all the coins must come from the same row.
 *  The player who takes the last coin loses.
 */

class NimVariant {

public:

/*
 * Method: play
 * Usage: game.play();
 * -------------------
 * Two player take turns to take coins from the coin piles.
 */
    void play() {
        initGame();
        while (!isGameOver()) {
            displayGame();
            moveT move;
            if (getCurrentPlayer() == HUMAN) {
                move = getUserMove();
            } else {
                move = getComputerMove();
                displayMove(move);
            }
            makeMove(move);
            switchTurn();
        }
        announceResult();
    }

/*
 * Method: printInstructions
 * Usage: game.printInstructions();
 * ----------------------------
 *  Explains the rules of the game to the user.
 */

    void printInstructions() {
        cout << "Welcome to the game of Nim!" << endl;
        cout << "In this game,we will start with " << NUM_ROWS << " rows of coins on" << endl;
        cout << "the table. On each turn, you and I will alternately" << endl;
        cout << "take between 1 and any number of coins from the table," << endl;
        cout << "subject to the condition that all the coins must come" << endl;
        cout << "from the same row. The player who takes the last coin loses." << endl;
    }

private: 

/*
 * Method: initGame
 * Usage: initGame();
 * --------------------
 *  Initialize the game setting: 
 *   1. set the starting player to human
 *   2. initialize the coins piles
 */
    void initGame() {
        rCoins += NUM_COINS_R0;
        rCoins += NUM_COINS_R1;
        rCoins += NUM_COINS_R2;
        
        whoseTurn = STARTING_PLAYER;
    }

/*
 * Method: swtichTurn
 * Usage: switchTurn();
 * ---------------------
 *  Switch turn between human and computer.
 */
    void switchTurn() {
        whoseTurn = opponent(getCurrentPlayer());
    }

/*
 * Method: isGameOver
 * Usage: if (isGameOver())
 * ------------------------
 *  Returns true if the game is over.
 *  ( The total number of coins equals or less
 *  than 1);
 */
    bool isGameOver() {
        return (getSumCoins() <= 1);
    }

/*
 * Method: getSumCoins
 * Usage: int n = getSumCoins();
 * ----------------------------
 *  Return the sum of all the coins on the table.
 */
    int getSumCoins() {
        int sum = 0;
        for (int i = 0; i < rCoins.size(); i++) {
            sum += rCoins[i];
        }
        return sum;
    }

/*
 * Method: displayGame
 * Usage: displayGame();
 * ----------------------
 *  Print the left coins in each row.
 */
    void displayGame() {
        cout << endl;
        cout << "There are " << getSumCoins() << " coins left on the table. " << endl;
        cout << "   Row 0: " << rCoins[0] << " coins." << endl;
        cout << "   Row 1: " << rCoins[1] << " coins." << endl;
        cout << "   Row 2: " << rCoins[2] << " coins." << endl;
    }

/*
 * Method: getCurrentPlayer
 * Usage: Player player = getCurrentPlayer();
 * -----------------------
 *  Return the current player.
 */
    Player getCurrentPlayer() {
        return whoseTurn;
    }

/*
 * Method: getUserMove
 * Usage: moveT move = getUserMove();
 * --------------------------
 *  Return a legal move taken by user.
 */
    moveT getUserMove() {
        moveT move;
        while (true) {
            move.row = getInteger("Enter which row you perfer:  ");
            move.nTaken = getInteger("Enter the num of coins you would like from Row[" + integerToString(move.row) + "]:  ");
            if (isValid(move)) return move;
            cout << "Unable to take " << move.nTaken << " coins from Row[" << move.row << "]. "  << endl;
            cout << "Please choose again. " << endl << endl;
            displayGame();
        }
    }

/*
 * Method: isValid
 * Usage: if (isValid(move))
 * --------------------------
 *  Checks the coins in Row [move.row] is enough for the user to take.
 */
    bool isValid(moveT move) {
        return (move.row < rCoins.size()) && (rCoins[move.row] >= move.nTaken) && (move.nTaken > 0);
    }

/*
 * Method: getComputerMove
 * Usage: moveT move = getComputerMove();
 * ---------------------------
 *  Return the best move.
 */
    moveT getComputerMove() {
        return findBestMove();
    }


/*
 * Method: findBestMove
 * Usage: moveT move = findBestMove();
 * --------------------------
 *  Finds the best move for the current player and returns the moves as the value 
 *  of the funciton. The second form is used for later recursive calls and includes
 *  two parameters. The depth parameter is used to limit the depth of the search for
 *  games that are diffcult to analyze. The reference parameter rating is used to
 *  store the rating of the best move.
 */
    moveT findBestMove() {
        int rating;
        return findBestMove(0, rating);
    }

    moveT findBestMove(int depth, int & rating) {
        Vector<moveT> moveList;
        moveT bestMove;
        int minRating = WINNING_POSITION + 1;
        generateMoveList(moveList);
        if (moveList.isEmpty()) error("No moves available");
        for (moveT move : moveList) {
            makeMove(move);
            int moveRating = evaluatePosition(depth + 1);
            if (moveRating < minRating) {
                bestMove = move;
                minRating = moveRating;
            }
            retractMove(move);
        }
        rating = -minRating;
        return bestMove;
    }

/*
 * Method: generateMoveList
 * Usage: generateMoveList(moveList);
 * ------------------------------------
 *  Generate a list of next possible move taken by player.
 */
    void generateMoveList(Vector<moveT> & moveList) {
        moveT move;
        for (int r = 0; r < rCoins.size(); r++) {
            for (int n = 1; n <= rCoins[r]; n++) {
                move.row = r;
                move.nTaken = n;
                moveList.add(move);
            }
        }
    }

/*
 * Method: retractMove
 * Usage: retractMove(move);
 * -------------------------
 *  Retract move.
 */
    void retractMove(moveT move) {
        if (move.row >= rCoins.size()) error("Retract move failed");
        rCoins[move.row] += move.nTaken;
    }
/*
 * Method: evaluatePosition
 * Usage: int rating = evaluatePosition(depth);
 * ------------------------------------
 *  Evaluates a position by finding the rating of the best move starting at
 *  that point. The depth parameter is used to limit the search depth.
 */
    int evaluatePosition(int depth) {
        if (isGameOver() || depth >= MAX_DEPTH) {
            return evaluateStaticPosition();
        }
        int rating;
        findBestMove(depth,rating);
        return rating;
    }


/*
 * Method: evaluateStaticPosition
 * Usage: evaluateStaticPosition();
 * ----------------------------------
 * Return a rating in this position.
 */
    int evaluateStaticPosition() {
        int rating; // rating from the player who makes the move.
        
        int nRows = getLeftRows();    // The num of rows which has coins left.

        switch (nRows) {
            case 0: rating = LOSING_POSITION; break;
            case 1: rating = (getSumCoins() >= 2) ? WINNING_POSITION : LOSING_POSITION;
                    break;
            case 2: rating = (hasOneCoinRow()) ? WINNING_POSITION : LOSING_POSITION;
                    break;
            default: error("unmatched situtaion.");
        }
        return rating;
    }


/*
 * Method: hasOneCoinRow
 * Usage: if (hasOneCoinRow())
 * ----------------------------------
 *  If one of the left rows has only one coin, returns true;
 */
    bool hasOneCoinRow() {
        for (int i = 0; i < rCoins.size(); i++) {
            if (rCoins[i] == 1) return true;
        }
        return false;
    }

/*
 * Method: getLeftRows
 * Usage: int n = getLeftRows();
 * ------------------------------
 *  Return the number of rows has coins.
 */
    int getLeftRows() {
        int total = 0;
        for (int i = 0; i < rCoins.size(); i++) {
            if (rCoins[i] != 0) total++;
        }
        return total;
    }

/*
 * Method: displayMove
 * Usage: displayMove(move);
 * ---------------------------
 *  Display the move taken by the computer.
 */

    void displayMove(moveT move) {
        cout << "I'll take " << move.nTaken << " coins from Row " << move.row << endl;
    }

/*
 * Method: makeMove
 * Usage: makeMove(move);
 * --------------------------
 *  Make a move.
 */
 
    void makeMove(moveT move) {
        rCoins[move.row] -= move.nTaken;
    }

/*
 * Method: announceResult
 * Usage: announceResult();
 * --------------------------
 *  Announce the result of the game.
 */
    void announceResult() {
        if (getSumCoins() == 0) {
            cout << " You took the last coin. You lose." << endl;
        } else {
            cout << " There is only one coin left." << endl;
            cout << ((whoseTurn == HUMAN) ? "I win." : "I lose.") << endl;
        }
    }

/* Instance variables */
    Vector<int> rCoins;   /* Rows of coins left on the table */
    Player whoseTurn;     /* Marker showing whose turn it is */

};

/* Main Program */

int main() {
    NimVariant game;
    game.printInstructions();
    game.play();
    return 0;
}
