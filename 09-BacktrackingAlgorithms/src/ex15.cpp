/*
 * 参考Gleen Streiff代码：
 *  1. struct moveT
 *      - sq
 *      - mark
 *  2. enum Outcome
 *      - HUMAN_WINS
 *      - COMPUTER_WINS
 *      - CATS_GAME
 *  3. 问题复杂点：
 *      - mark和玩家之间的链接: char getMark(Player)
 *      - 使用minimax 时，如何交替进行每个玩家的move，以及如何回退。
 *      - 如何评估静态position
 *          · 其实就是把人类判断时的过程用逻辑写下来
 *      - 如何判赢
 *      - 结束游戏时对结果对判断和Announce Result时都需要对于结果进行判断，为避免重复
 *      判断，可添加一个instance variable - outcome
 *  4. 个人习惯中需要改进的点：
 *      - 不要出现magic number和string constants在body内，要坚决执行。
 *          ·即使是像tic tac toe这种通常是3个格子的游戏，3这个数字也得用constants来替代。
 *      - top-down function listing:
 *          · main
 *          · function main directly calls
 *          · the functions called by those functions
 *          · the smallest building blocks that dont break down
 *      - 函数起名可以更清晰一点：(good naming convetion)
 *          · hasRowLineUp ----->   has3InRow/hasRowWin
 *      - 先解决问题，再code。
 *          · decompose the problem, and write the program from that already decomposed framework.
 *      - 模块之间的解耦，sensiable breakdown into modular uint.
 *
 *  5. minimax:
 *      · computer's turn to next move: rating from the opponent's view
 *      · human'turn to next move: 
 *  5. top-down design: decompose problems, not programs.
 *      TicTacToe
 *          - printInstruction
 *          - play
 *              - initGame
 *                  - !gameIsOver
 *                      - displayGame
 *                      - getMove
 *                          - getUserMove
 *                          - getComputerMove
 *                              - findBestMove
 *                                  - recFindBestMove
 *                                  - evaluatePosition
 *                                      - evaluateStaticPosition
 *                                      - 
 *
 *                      - makeMove
 *                      - switchTurn
 *                  - AnnounceResult
 *
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "strlib.h"
#include "simpio.h"
#include "error.h"
#include "map.h"
#include "grid.h"
using namespace std;

enum Player {HUMAN, COMPUTER};

Player opponent(Player player) {
    return ((player == HUMAN) ? COMPUTER : HUMAN);
}

const Player STARTING_PLAYER = COMPUTER;

/* Struct moveT */
struct moveT {
    int targetSq;   // target square
};

struct posT {
    int row;
    int col;
};

/* Constants */
const int WINNING_POSITION = 1000;
const int LOSING_POSITION = -WINNING_POSITION;
const int MAX_DEPTH = 1000;
const int BOARD_SIZE = 3;

class TicTacToe {

public: 

    void printInstructions() {
        cout << "Welcome to TicTacToe, the game of three in a row." << endl;
        cout << "I'll be X, and you'll be O."<< endl;
        cout << "The squares are numbered like this: " << endl;
        cout << endl;
        cout << " 1 | 2 | 3 " << endl;
        cout << "---+---+---" << endl;
        cout << " 4 | 5 | 6 " << endl;
        cout << "---+---+---" << endl;
        cout << " 7 | 8 | 9 " << endl;
        cout << endl;
    }

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

private: 
    
    void announceResult() {
        displayGame();
        if (isRowLineUp() || isColLineUp()) {
            if (getCurrentPlayer() == COMPUTER) {
                cout << "You win." << endl;
            } else {
                cout << "I win." << endl;
            }
        } else if (isBoardFillUp()) {
            cout << "It's a cat's game." << endl;
        }
    }

    void displayMove(moveT move) {
        cout << "I'll move to " << move.targetSq << endl;
    }

    moveT getComputerMove() {
        return findBestMove();
    }

    moveT findBestMove() {
        int rating;
        return findBestMove(0, rating);
    }

    moveT findBestMove(int depth, int & rating) {
        Vector<moveT> moveList;
        moveT bestMove;
        int minRating = WINNING_POSITION + 1;
        generateMoveList(moveList);
        if (moveList.isEmpty()) error("No moves availablie");
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

    void generateMoveList(Vector<moveT> & moveList) {
        for (int i = 1; i <= 9; i++) {
            if (isEmpty(i)) {
                moveT move;
                move.targetSq = i;
                moveList.add(move);
            }
        }
    }

    int evaluatePosition(int depth) {
        if (isGameOver() || depth >= MAX_DEPTH) {
            return evaluateStaticPosition();
        }
        int rating;
        findBestMove(depth, rating);
        return rating;
    }

    int evaluateStaticPosition() {

    }

    moveT getUserMove() {
        moveT move;
        cout << "Your move" << endl;
        move.targetSq = getInteger("What square? ");
        return move;
    }

    Player getCurrentPlayer() {
        return whoseTurn;
    }

    void displayGame() {
        cout << "The game now looks like this: " << endl << endl;
        for (int i = 0; i < board.numRows(); i++) {
            if (i != 0) printGridLine();
            for (int j = 0; j < board.numCols(); j++) {
                if (j != 0) cout << "|";
                cout << " " << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void printGridLine() {
        for (int i = 0; i < board.numCols(); i++) {
            if (i != 0) cout << "+";
            cout << "---";
        }
        cout << endl;
    }


    void initGame() {
        board.resize(BOARD_SIZE, BOARD_SIZE);
        initBoard();
        whoseTurn = STARTING_PLAYER;
        marker.put(HUMAN, "O");
        marker.put(COMPUTER, "X");
    }

    void initBoard() {
        for (int i = 0; i < board.numRows(); i++) {
            for (int j = 0; j < board.numCols(); j++) {
                board[i][j] = " ";
            }
        }
    }


    bool isGameOver() {
        if (isRowLineUp()) return true;
        if (isColLineUp()) return true;
        if (isDiagonalLineUp()) return true;
        if (isBoardFillUp()) return true;
        return false;
    }

    bool isDiagonalLineUp() {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != " ")
            return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != " ")
            return true;
        return false;
    }


    bool isRowLineUp() {
        for (int i = 0; i < board.numRows(); i++) {
            if ((board[i][0] == board[i][1]) && (board[i][0] == board[i][2]) && !isEmpty(i, 0))
                return true;
        }
        return false;
    }

    bool isColLineUp() {
        for (int j = 0; j < board.numCols(); j++) {
            if  ((board[0][j] == board[1][j]) && (board[0][j] == board[2][j]) && !isEmpty(0,j))
                return true;
        }
        return false;
    }

    bool isBoardFillUp() {
        for (int i = 0; i < board.numRows(); i++) {
            for (int j = 0; j < board.numCols(); j++) {
                if (isEmpty(i, j))
                    return false;
            }
        }
        return true;
    }
                    

    void switchTurn() {
        whoseTurn = opponent(whoseTurn);
    }

    void makeMove(moveT move) {
        string marking = marker[whoseTurn];
        int n = move.targetSq;
        if (isEmpty(n)) markSquare(n, marking);
        else error("unavaliable square");
    }

    bool isEmpty(int num) {
        posT p = numToPosT(num);
        return (board[p.row][p.col] == " ");
    }

    bool isEmpty(int i, int j) {
        return (board[i][j] == " ");
    }

/*
 * Method: numToPosT
 * Usage: numToPosT(n);
 * -----------------------------------
 *  Change the num of square to location in grid.
 */
    posT numToPosT(int n) {
        posT p;
        p.row = (n - 1) / 3;
        p.col = (n - 1) % 3;
        return p;
    }

/*
 * Method: posTToNum
 * Usage: int n = posTToNum(pos);
 * ---------------------------------------
 *  Return the number of the square of pos.
 */
    int posTToNum(posT p) {
        return (3 * p.row + p.col + 1);
    }

    void markSquare(int n, string marker) {
        posT p = numToPosT(n);
        board[p.row][p.col] = marker;
    }

    void retractMove(moveT move) {
        markSquare(move.targetSq, " ");
    }

/* Instance Variables */
    Grid<string> board;
    Player whoseTurn;
    Map<Player, string> marker;
};

int main() {
    TicTacToe game;
    game.printInstructions();
    game.play();
    return 0;
}
