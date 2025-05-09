#include "gwindow.h"
#include "gboggle.h"
#include "strlib.h"
#include "gobjects.h"

/* Constants
 * ------------------
 *  To configure fines spacing, fonts, etc.
 */
const double BOARD_BORDER = 20;           // width of border around the cubes
const double INDENT = 0.05;                // indent reserved at vertical edges of window
const double LABEL_HEIGHT = 70;           // space reserved at top of window for labels
const double HUMAN_PERCENTAGE = .38;       // percentage of sspace fow word lists to apportion to human (vs computer)
const string CUBE_FONT = "Helvetica";      // Font for letters on cube face
const double CUBE_CORNER_PERCENTAGE = .6;  // CUBE_CORNER_PERCENTAGE -- cube_corner specifies the diameter of the arc forming the corner
const double FONT_PERCENTAGE = 0.6;        // percentage of cube used for letter
const string SCORE_FONT = "Helvetica";     // Font for scoreboard names & scores
const int SCORE_FONT_SIZE = 18;
const string WORD_FONT = "Geneva";         // Font for word lists
const int WORD_FONT_SIZE = 10;
const int WORD_COLUMN_WIDTH = 5;

const string BOARD_COLOR = "YELLOW";
const string DIE_COLOR = "white";
const string LETTER_COLOR = "Dark_Blue";
const string WORD_COLOR = "cyan";
const string LABEL_COLOR = "green";


struct rectT { double x, y, w, h; };

static struct {
    int numWords[2];                       // num words currently displayed for each player
    int scores[2];                         // scores for each player
    rectT scoreBox[2];                     // rectangle enscribing the label + score for each player
    double wordColumnWidth;                // width of word list columns
    double cubeSize;                       // size of cube
    double cubeFontSize;                   // font size used for labelling cubes   
    rectT board;                           // rectangle enscribed the cubes w/ border
    int numRows, numCols;                  // dimensions of cube layout on board
    char letter[MAX_DIMENSION][MAX_DIMENSION];
} gState;

/* Function prototypes */
static void CalculateGeometry(GWindow & gw, int numRows, int numCols);
static void FillBox(GWindow & gw, double x, double y, double w, double h, string color);
static void DrawEmptyCubes(GWindow & gw);
static void DrawCube(GWindow & gw, int row, int col, char ch, bool invert);
static void DrawAndFillRoundedRect(GWindow & gw, double x, double y, double w, double h, double corner, string color);
static double CubeX(int col);
static double CubeY(int row);
static void DrawCenteredChar(GWindow & gw, double centerX, double centerY, char ch);
/*
 * Function: DrawBoard
 * ------------------------------
 *  Exported function to draw a new board.  Sets up named colors, draws the yellow border,
 *  draws the empty cubes, the labels on the scoreboard, and resets scores to zero and
 *  words lists to empty.
 */
void DrawBoard(GWindow & gw, int numRows, int numCols) {
    if (numRows < 0 || numRows > MAX_DIMENSION || numCols < 0 || numCols > MAX_DIMENSION)
        error("DrawBoard called with invalid dimension.");
    
    gw.setWindowTitle("Welcome to Boggle!");
    CalculateGeometry(gw, numRows, numCols);

    // Draws a filled rect underneath cubes
    FillBox(gw, gState.board.x, gState.board.y, gState.board.w, gState.board.h, BOARD_COLOR);
    DrawEmptyCubes(gw); //Debug
}

static void DrawEmptyCubes(GWindow & gw) {
    for (int row = 0; row < gState.numRows; row++) 
        for (int col = 0; col < gState.numCols; col++) 
            DrawCube(gw, row, col, ' ', false); // erase all cubes, start with blank chars
}

static void DrawCube(GWindow & gw, int row, int col, char ch, bool invert) {
    DrawAndFillRoundedRect(gw, CubeX(col), CubeY(row), gState.cubeSize, gState.cubeSize, gState.cubeSize * CUBE_CORNER_PERCENTAGE, (invert ? LETTER_COLOR : DIE_COLOR));
    //DrawCenteredChar(gw, CubeX(col) + gState.cubeSize / 2.0, CubeY(row) + gState.cubeSize / 2.0, ch);
}

static void DrawCenteredChar(GWindow & gw, double centerX, double centerY, char ch) {
    cout << "A" << endl;
   // string s = "A";
    GLabel *label = new GLabel("AB");
    cout << "BA" << endl;
    //string font = CUBE_FONT + "-normal-" + realToString(gState.cubeFontSize);
    string font = "SansSerif-18";
    cout << "CA" << endl;
    label->setFont("SansSerif-18");
    //debug print
    cout << "DA" << endl;
    //cout << font << endl;
    //cout << label->getColor() << endl;
    double x = centerX - label->getWidth() / 2.0;
    cout << "EA" << endl;
    double y = centerY + label->getFontAscent() / 2.0;
    cout << "FA" << endl;
    gw.add(label, x, y);
}

static void DrawAndFillRoundedRect(GWindow & gw, double x, double y, double w, double h, double corner, string color) {
    GRoundRect *rect = new GRoundRect(x, y, w, h, corner);
    rect->setFilled(true);
    rect->setColor(color);
    gw.add(rect);
    GRoundRect *bounds = new GRoundRect(x, y, w, h, corner);
    bounds->setFilled(false);
    bounds->setColor("black");
    gw.add(bounds);
}

static double CubeX(int col) {
    return gState.board.x + BOARD_BORDER / 2.0 + gState.cubeSize * col;
}

static double CubeY(int row) {
    return gState.board.y + gState.board.h - BOARD_BORDER / 2.0 - gState.cubeSize * (row + 1);
}

static void FillBox(GWindow & gw, double x, double y, double w, double h, string color){
    GRect *rect = new GRect(x, y, w, h);
    rect->setFilled(true);
    rect->setColor(color);
    gw.add(rect);
    cout << x << endl;
    cout << y << endl;
    cout << w << endl;
    cout << h << endl;
}


static void CalculateGeometry(GWindow & gw, int numRows, int numCols) {
    double boardSize = min(gw.getWidth()/3, gw.getHeight() - LABEL_HEIGHT);
    gState.cubeSize = min((boardSize - BOARD_BORDER)/numRows, (boardSize - BOARD_BORDER)/numCols);
    gState.board.w = gState.board.h = boardSize;
    gState.board.y = LABEL_HEIGHT;
    double leftover = gw.getWidth() - gState.board.w - 2 * INDENT;
    gState.scoreBox[Human].x = INDENT;
    gState.scoreBox[Human].y = gState.scoreBox[Computer].y = INDENT;
    gState.scoreBox[Human].h = gState.scoreBox[Computer].h = LABEL_HEIGHT;
    gState.scoreBox[Human].w = leftover * HUMAN_PERCENTAGE;
    gState.board.x = gState.scoreBox[Human].x + gState.scoreBox[Human].w;
    gState.scoreBox[Computer].x = gState.board.x + gState.board.w + INDENT;
    gState.scoreBox[Computer].w = gw.getWidth() - gState.scoreBox[Computer].x - INDENT;
    gState.numRows = numRows;
    gState.numCols = numCols;
    gState.wordColumnWidth = WORD_COLUMN_WIDTH;
    gState.cubeFontSize = gState.cubeSize * FONT_PERCENTAGE;
}
