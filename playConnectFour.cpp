#include "connectFour.hpp"

using namespace std;

int main(int argc, char *argv[]){
    game connect4;
    int rows = 6, columns = 7, pieces = 4;
    checkArgc(argc);
    for (int i = 1; i<7; i+=2){
	if(argv[i][0] == '-' && argv[i][1] == 'r')
	    rows = checkArgs(argv[i+1]);
	else if (argv[i][0] == '-' && argv[i][1] == 'c')
	    columns = checkArgs(argv[i+1]);
	else if (argv[i][0] == '-' && argv[i][1] == 'p')
	    pieces = checkArgs(argv[i+1]);
	else
	    cout<<"You entered something wrong!  Please enter -r <number of rows> -c <number of columns -p <number of pieces> "<<endl;
    }
    connect4.board = new char*[rows];
    for(int i = 0; i<columns; i++)
	connect4.board[i] = new char[columns];
    initializeBoard(connect4.board, rows, columns, pieces);
}


