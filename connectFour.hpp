#include<string>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

/***************************************
**Function: checkArgc
**Description: Make sure that user has entered 7 items in command line (t    he file name, and three arguments)
**Parameters: argc (number of arguments)
**Post-condition: User must have entered 7 items, or program will exit.
****************************************/
void checkArgc(int argc);

/***************************************
  **Function: checkArgs
  **Description: Make sure that command line arguments user passes to program are positive integers with the correct flags.
  **Parameters: character array of commands passed to the program
  **Post-condition: Each parameter rows, columns, and pieces must have a positive integer less than 100 passed to it.
  ***************************************/
int checkArgs(char *r);

/****************************************
  **Function: printBoard
  **Description: Prints the 2D array that is the board to the screen.
  **Parameters: Double pointer to the 2D array, the number of rows and the number of columns.
  **Pre-condition: board must have been built.
******************************************/
void printBoard(char **board, int rows, int columns);

/****************************************
  **Function: initializeBoard
  **Description: Populates the board with null characters, making it so that the board can identify an empty space vs. a filled one.
  **Parameters: 2D array that is the board, number of rows, number of columns, and number of pieces (to be passed to a later function).
  **Pre-conditions: Board must be constructed
  **Post-conditions: Board should have a space character in each cell.
  ***************************************/
void initializeBoard(char **board, int rows, int columns, int pieces);

/****************************************
  **Function: makeMove
  **Description: Drop a piece into the board, and have it "sink" to the bottom.
  **Parameters: The board, rows, columns, and the player making the move.
  **Post-conditions: piece should fill one of the cells on the board.
  **************************************/
void makeMove(char **board, int rows, int columns, char player);

/***************************************
  **Function: aiPlayer
  **Description: Ask user whether there are 1 or 2 human players to determine whether to run ai or not.
  **Parameters: none
  **Post-conditions: Must know whether ai should be used or not!  Return 1 or 2;
  *************************************/
int aiPlayer();

/*************************************
  **Function: playai
  **Description: ai makes a move
  **Parameters: board, rows, columns, which player the computer is
  **Pre-conditions: User must say there is only one human
  ************************************/
void playai(char **board, int rows, int columns, char player);

/*************************************
  **Function: playGame
  **Description: This function controls the flow of the game--who's turn it is, let's them move, then checks for a win.
  **Parameters: board, rows, columns, pieces, and whether someone has won.
  ***********************************/
void playGame(char **board, int rows, int columns, int pieces, int win);
/************************************
  **Function: checkWin
 **Description: use each "check win" function to see if the user has won the game horizontally, vertically or diagonally. 
**Parameters: board, rows, columns, pieces needed to win, and the player who is being check for win.
**Post-condition: determine whether a player has won or not!
************************************/
 int checkWin(char **board, int rows, int columns, int pieces, char player);

int checkHorizontal(char **board, int rows, int columns, int pieces, char player);

int checkVertical(char **board, int rows, int columns, int pieces, char player);

int checkRightDiagonal(char **board, int rows, int columns, int pieces, char player);

int checkLeftDiagonal(char **board, int rows, int columns, int pieces, char player);

struct game{
    char **board;
    char player1;
    char player2;
};

