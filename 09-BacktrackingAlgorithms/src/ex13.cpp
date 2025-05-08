#include <iostream>
#include <string>
#include "simpio.h"
#include "vector.h"
#include "error.h"
using namespace std;

/* Struct */
struct moveT {
    int nTaken;
};

/* Constants */
const int N_COINS = 17;
const int MAX_MOVE = 4;
const int NO_GOOD_MOVE = -1;
const int MAX_DEPTH = 1000000;
const int WINNING_POSITION = 1000;
const int LOSING_POSITION = -WINNING_POSITION;


/* 
 * Type: Player
 * --------------------
 *  Enumerated type differentiates the human and computer players.
 */
enum Player { HUMAN, COMPUTER};

/*
 * Function: opponent
 * --------------------
 *  Returns the opponent of the player.
 */
Player opponent(Player player) {
    return (player == HUMAN) ? COMPUTER : HUMAN;
}

/* Constants - Start Player */
const Player STARTING_PLAYER = HUMAN;

class SimpleNim {
    
public:

/* Function: play
 * --------------------------------
 *  Plays the game of Nim with the human player.
 */
    void play() {
        initGame();
        while (!gameIsOver()) {
            displayGame();
            if (getCurrentPlayer() == HUMAN) {
                makeMove(getUserMove());
            } else {
                moveT move = getComputerMove();
                displayMove(move);
                makeMove(move);
            }
            switchTurn();
        }
        announceResult();
    }

/*
 * Function: printInstruction
 * -------------------------------
 *  Explains the rules of the game to the user.
 */
    void printInstructions() {
        cout << "Welcome to the game of Nim!" << endl;
        cout << "In this game, we will start with a pile of " << endl;
        cout << N_COINS << " coins on the table. On each turn, you " << endl;
        cout << "and I will alternately take between 1 and " << endl;
        cout << MAX_MOVE << "coins from the table. The player who" << endl;
        cout << "takes the last coin loses." << endl << endl;
    }
private:
/*
 * Function: initGame
 * --------------------------------
 *  Set up the game.
 */
    void initGame() {
        nCoins = N_COINS;
        whoseTurn = STARTING_PLAYER;
        nCoinsHu = 0;
        nCoinsCom = 0;
    }

/*
 * Function: gameIsOver
 * --------------------------------
 *  Return true if the game is over.
 */
    bool gameIsOver() {
        return (nCoins == 0);
    }


/*
 * Function: displayGame
 * -------------------------------
 *  Display the latest status of the game.
 */
    void displayGame() {
        cout << endl << "There are " << nCoins << " coins in the pile." << endl;
        cout << "Human pile: " << nCoinsHu << "coins. " << endl;
        cout << "Computer pile: " << nCoinsCom << "coins. " << endl << endl;
    }

/*
 * Function: getCurrentPlayer()
 * -----------------------------
 *  Return the current player.
 */
    Player getCurrentPlayer() {
        return whoseTurn;
    }

/*
 * Function: makeMove
 * ---------------------------
 *  Make one move for the current player.
 */
    void makeMove(moveT move) {
        nCoins -= move.nTaken;
        if (whoseTurn == HUMAN) nCoinsHu += move.nTaken;
        else nCoinsCom += move.nTaken;
    }

/*
 * Function: makeMove
 * ----------------------------
 *  Overload of makeMove, user for recusive call in the findBestMove
 */
    void makeMove(moveT move, int depth) {
        nCoins -= move.nTaken;
        if (isEven(depth)) nCoinsCom += move.nTaken;
        else nCoinsHu += move.nTaken;
    }

/*
 * Function: isEven
 * --------------------------
 *  Return true if the number is even
 */
    bool isEven(int n) {
        return ((n % 2) == 0);
    }
/*
 * Function: getUserMove
 * ---------------------------
 *  Ask the user the num of coins between 1 and MAX_MOVE.
 */
    moveT getUserMove() {
        while (true) {
            moveT uMove;
            uMove.nTaken = getInteger("How many would you like?  ");
            int limit = nCoins < MAX_MOVE ? nCoins : MAX_MOVE;
            if (uMove.nTaken >= 1 && uMove.nTaken <= limit) return uMove;
            else  {
                cout << "You need to take coins between 1 and " << limit 
                    << " from the table. Please try again." << endl;
            }
        }
    }

/*
 * Function: getComputerMove
 * ---------------------------
 *  Return the best move of the computer.
 */
    moveT getComputerMove() {
         return findBestMove();
    }

/*
 * Function: findBestMove
 * -------------------------
 *  Finds the best move for the current player and return that move as
 *  this value of the function.
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
        if (moveList.isEmpty()) error("No move available.");
        for (moveT move : moveList) {
            makeMove(move, depth);
            int moveRating = evaluatePosition(depth + 1);
            if (moveRating < minRating) {
                bestMove = move;
                minRating = moveRating;
            }
            retractMove(move, depth);
        }
        rating = - minRating;
        return bestMove;
    }

/*
 * Function: retractMove
 * ----------------------
 *  Retract the move.
 */
    void retractMove(moveT move) {
        nCoins += move.nTaken;
        nCoinsCom -= move.nTaken;
    }

    void retractMove(moveT move, int depth) {
        nCoins += move.nTaken;
        if (isEven(depth)) nCoinsCom -= move.nTaken;
        else nCoinsHu -= move.nTaken;
    }


/*
 * Function: generateMoveList
 * ---------------------------
 *  Create the move list of next move.
 */
    void generateMoveList(Vector<moveT> & moveList) {
        for (int i = 1; i <= MAX_MOVE && i <= nCoins; i++) {
            moveT move;
            move.nTaken = i;
            moveList.add(move);
        }
    }
    

/*
 * Function: evaluatePosition
 * ---------------------------
 *  Evaluates a position by finding the rating of the best move starting at
 *  that point.
 *  The depth parameter is used to limit the search depth.
 */
    int evaluatePosition(int depth) {
        if (gameIsOver() || depth >= MAX_DEPTH) {
            return evaluateStaticPosition(depth);
        }
        int rating;
        findBestMove(depth, rating);
        return rating;
    }

/*
 * Function: evaluateStaticPosition
 * -----------------------------
 *  Evaluate static position of the nim game.
 */
    int evaluateStaticPosition(int depth) {
        if (isEven(depth)) {
            return ((isEven(nCoinsCom)) ? WINNING_POSITION : LOSING_POSITION);
        } else {
            return ((!isEven(nCoinsCom)) ? WINNING_POSITION : LOSING_POSITION);
        }
    }
/*
 * Function: displayMove
 * --------------------------
 *  Display the move that the computer took.
 */
    void displayMove(moveT move) {
        cout << "I'll take " << move.nTaken << endl;
    }

/*
 * Function: switchTurn
 * -------------------------
 *  Swith turn of the players between computer and human.
 */
    void switchTurn() {
        whoseTurn = opponent(whoseTurn);
    }

/*
 * Function: getWinner
 * ------------------------
 *  Return the player who wins.
 */
    Player getWinner() {
        return ((nCoinsHu % 2 == 0) ? HUMAN : COMPUTER);
    }
/*
 * Function: announceResult
 * -------------------------
 *  Announce the result of the game.
 */
    void announceResult() {
        cout << ((getWinner() == HUMAN) ? "You win." : "I win.") << endl;
    }

/* Instance variables */
    int nCoins;
    Player whoseTurn;
    int nCoinsCom;
    int nCoinsHu;
};

/* Main program */
int main() {
    SimpleNim game;
    game.printInstructions();
    game.play();
    return 0;
}
