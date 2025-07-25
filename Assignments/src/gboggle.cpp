#include <cmath>
#include "gwindow.h"
#include "gboggle.h"
#include "strlib.h"
#include "gobjects.h"

/* Constants
 * ------------------
 *  To configure fines spacing, fonts, etc.
 */
const double BOARD_BORDER = 20;           // width of border around the cubes
const double INDENT = 8;                // indent reserved at vertical edges of window
const double LABEL_HEIGHT = 70;           // space reserved at top of window for labels
const double HUMAN_PERCENTAGE = .38;       // percentage of sspace fow word lists to apportion to human (vs computer)
const string CUBE_FONT = "Helvetica";      // Font for letters on cube face
const double CUBE_CORNER_PERCENTAGE = .6;  // CUBE_CORNER_PERCENTAGE -- cube_corner specifies the diameter of the arc forming the corner
const double FONT_PERCENTAGE = 0.6;        // percentage of cube used for letter
const double TEXT_LINE_VERTICAL_OFFSET = 5; // The offset between the score text and the line
const string SCORE_FONT = "Helvetica";     // Font for scoreboard names & scores
const int SCORE_FONT_SIZE = 50;
const string WORD_FONT = "Geneva";         // Font for word lists
const double WORD_FONT_SIZE = 20;
const double WORD_COLUMN_WIDTH = 130;
const double LINEWIDTH = 3.5;                //Line Width of the score box line

const string BOARD_COLOR = "#FFDB0D";
const string DIE_COLOR = "#E6E6E6";
const string LETTER_COLOR = "#0333D9";
const string WORD_COLOR = "#03804D";
const string LABEL_COLOR = "#037340";


struct rectT { double x, y, w, h; };

static struct {
    int numWords[2];                       // num words currently displayed for each player
    int scores[2];                         // scores for each player
    GLabel *scoreLabels[2];                // used to store score label
    rectT scoreBox[2];                     // rectangle enscribing the label + score for each player
    double wordColumnWidth;                // width of word list columns
    double cubeSize;                       // size of cube
    double cubeFontSize;                   // font size used for labelling cubes   
    rectT board;                           // rectangle enscribed the cubes w/ border
    int numRows, numCols;                  // dimensions of cube layout on board
    char letters[MAX_DIMENSION][MAX_DIMENSION];
} gState;

/* Function prototypes */
static void CalculateGeometry(GWindow & gw, int numRows, int numCols);
static void FillBox(GWindow & gw, double x, double y, double w, double h, string color);
static void DrawEmptyCubes(GWindow & gw);
static void DrawCube(GWindow & gw, int row, int col, char ch, bool invert);
static void DrawAndFillRoundedRect(GWindow & gw, double x, double y, double w, double h, double corner, string color);
static double CubeX(int col);
static double CubeY(int row);
static void DrawCenteredChar(GWindow & gw, double centerX, double centerY, char ch, string color);
static string getCubeString(char ch);
static GLabel * DrawPlayerLabel(GWindow & gw, playerT player, string name);
void LabelCube(GWindow & gw, int row, int col, char letter);
void HighlightCube(GWindow & gw, int row, int col, bool flag);
static bool IsValidRowCol(int row, int col);
void RecordWordForPlayer(GWindow & gw, string word, playerT player);
static void AddToScoreForPlayer(int pointsToAdd, playerT playerNum);

static void AddToScoreForPlayer(int pointsToAdd, playerT playerNum){
	gState.scores[playerNum] += pointsToAdd;
	gState.scoreLabels[playerNum]->setLabel(realToString(gState.scores[playerNum]));
}

void RecordWordForPlayer(GWindow & gw, string word, playerT player){
	if (player != Human && player != Computer) {
		error("RecordWordForPlayer called with invalid argument.");
	}
	word = toLowerCase(word);
	int numWordsInRow = gState.scoreBox[player].w/gState.wordColumnWidth;
	gState.wordColumnWidth = gState.scoreBox[player].w * 1.0 / numWordsInRow; // Reset the columnwidth
	int row = gState.numWords[player] / numWordsInRow;
	int col = gState.numWords[player] % numWordsInRow;
        GLabel * label = new GLabel(word);
	label->setFont(WORD_FONT + "-normal-" + realToString(WORD_FONT_SIZE));
	label->setColor(WORD_COLOR);
	double x = gState.scoreBox[player].x + col * gState.wordColumnWidth;
	double y = gState.scoreBox[player].y + gState.scoreBox[player].h + (row + 1) * label->getHeight();
	gw.add(label, x, y);
	gState.numWords[player]++;
	AddToScoreForPlayer(word.length() - 3, player); // +1 pt for each letter over length 4
}

void HighlightCube(GWindow & gw, int row, int col, bool flag) {
	IsValidRowCol(row, col);
	DrawCube(gw, row, col, gState.letters[row][col], flag);
}

static bool IsValidRowCol(int row, int col){
	if (row < 0 || row >= gState.numRows || col < 0 || col >= gState.numCols) {
		error("LabelCube called with invalid row, col arguments.");
	}
	return true;
}
void LabelCube(GWindow & gw, int row, int col, char letter) {
	IsValidRowCol(row, col);
	gState.letters[row][col] = letter;
	DrawCube(gw, row, col, letter, false);
}

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
    DrawEmptyCubes(gw); 
    gState.scoreLabels[Human] = DrawPlayerLabel(gw, Human, "Me");
    gState.scoreLabels[Computer] = DrawPlayerLabel(gw, Computer, "Computer");
}

static void DrawEmptyCubes(GWindow & gw) {
    for (int row = 0; row < gState.numRows; row++) 
        for (int col = 0; col < gState.numCols; col++) 
            DrawCube(gw, row, col, ' ', false); // erase all cubes, start with blank chars
}

static void DrawCube(GWindow & gw, int row, int col, char ch, bool invert) {
    DrawAndFillRoundedRect(gw, CubeX(col), CubeY(row), gState.cubeSize, gState.cubeSize, gState.cubeSize * CUBE_CORNER_PERCENTAGE, (invert ? LETTER_COLOR : DIE_COLOR));
    DrawCenteredChar(gw, CubeX(col) + gState.cubeSize / 2.0, CubeY(row) + gState.cubeSize / 2.0, ch, (invert ? DIE_COLOR : LETTER_COLOR));
}

static void DrawCenteredChar(GWindow & gw, double centerX, double centerY, char ch, string color) {
    string s = getCubeString(ch);
    GLabel *label = new GLabel(s);
    string font = CUBE_FONT + "-bold-" + integerToString(gState.cubeFontSize); 
    label->setFont(font);   // setFont中font size 为小数时，该指令无效
    label->setColor(color);
    if (s == "Qu") {
            label->scale(0.9, 1);
    }
    double x = centerX - label->getWidth() / 2.0;
    double y = centerY + label->getHeight() / 2.0 - label->getFontDescent();
    gw.add(label, x, y);
}

static string getCubeString(char ch) {
	if (tolower(ch) == 'q') return "Qu";
	else return string(1, toupper(ch));
}

static GLabel * DrawPlayerLabel(GWindow & gw, playerT player, string name) {
    gState.scores[player] = gState.numWords[player] = 0;
    // Draw divider line:
    double y = gState.scoreBox[player].y + gState.scoreBox[player].h + LINEWIDTH / 2.0;
    GLine *line = new GLine(gState.scoreBox[player].x, y, gState.scoreBox[player].x + gState.scoreBox[player].w, y);
    line->setLineWidth(LINEWIDTH);
    line->setColor(LABEL_COLOR);
    gw.add(line);

    // Add name label
    GLabel *label = new GLabel(name);
    string font = SCORE_FONT + "-bold-" + realToString(SCORE_FONT_SIZE);
    label->setFont(font);
    label->setColor(LABEL_COLOR);
    double textY = y - label->getFontDescent() - TEXT_LINE_VERTICAL_OFFSET;
    gw.add(label, gState.scoreBox[player].x, textY);

    // Add score label
    GLabel *score = new GLabel(realToString(gState.scores[player]));
    score->setFont(font);
    score->setColor(LABEL_COLOR);
    gw.add(score, gState.scoreBox[player].x + gState.scoreBox[player].w / 4.0 * 3.0, textY);
    return score;
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
	//eturn gState.board.y + gState.board.h - BOARD_BORDER / 2.0 - gState.cubeSize * (row + 1);
	return gState.board.y + gState.cubeSize * row + BOARD_BORDER / 2.0;
}

static void FillBox(GWindow & gw, double x, double y, double w, double h, string color){
    GRect *rect = new GRect(x, y, w, h);
    rect->setFilled(true);
    rect->setColor(color);
    gw.add(rect);
}

static void CalculateGeometry(GWindow & gw, int numRows, int numCols) {
    double boardSize = min(gw.getWidth()/3, gw.getHeight() - LABEL_HEIGHT);
    gState.cubeSize = min((boardSize - BOARD_BORDER)/numRows, (boardSize - BOARD_BORDER)/numCols);
    gState.board.w = gState.board.h = boardSize;
    gState.board.y = LABEL_HEIGHT;
    double leftover = gw.getWidth() - gState.board.w - 2 * INDENT;
    gState.scoreBox[Human].x = 0;
    gState.scoreBox[Human].y = gState.scoreBox[Computer].y = 0;
    gState.scoreBox[Human].h = gState.scoreBox[Computer].h = LABEL_HEIGHT;
    gState.scoreBox[Human].w = leftover * HUMAN_PERCENTAGE;
    gState.board.x = gState.scoreBox[Human].x + gState.scoreBox[Human].w + INDENT;
    gState.scoreBox[Computer].x = gState.board.x + gState.board.w + INDENT;
    gState.scoreBox[Computer].w = gw.getWidth() - gState.scoreBox[Computer].x;
    gState.numRows = numRows;
    gState.numCols = numCols;
    gState.wordColumnWidth = WORD_COLUMN_WIDTH;
    gState.cubeFontSize = std::round(gState.cubeSize * FONT_PERCENTAGE);  // Font size不能为小数
}
