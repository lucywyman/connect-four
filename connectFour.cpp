#include "playConnectFour.cpp"

using namespace std;

void checkArgc(int argc){
	if(argc != 7 && argc!=1){
		cout<<"You entered something wrong!  Please enter -rows <number of rows> -columns <number of columns> -p <number of pieces>"<<endl;
		exit(1);
	}
}

int checkArgs(char r[]){
	int arg, valid = 0;
	for (int i = 0; i<sizeof(*r); i++){
		if(!isdigit(r[i]))
			valid = 0;
		else if (atoi(r)<1)
			valid = 0;
		else
			valid = 1;
	}
	if (valid == 1)
		arg = atoi(r);
	while(valid == 0){
		cout<<"Input was wrong! Please input a positive integer greater than 0: ";
		cin>>arg;
		if (arg<1 || cin.fail()){
			cin.clear();
			cin.ignore(1000, '\n');
			valid = 0;
		}
		else
			valid = 1;
	}
	return arg;
}


void printBoard(char **board, int rows, int columns){
	cout<<"The board currently looks like: "<<endl;
	cout<<"    ";
	for(int i = 0; i<=rows; i++)
		cout<<i+1<<"   ";
	cout<<endl;
	for(int i = 0; i<rows; i++){
		cout<<i+1<<" ";
		for (int j = 0; j<columns; j++){
			cout<<"| "<<board[i][j]<<" ";
		}
		cout<<"|"<<endl;
	}
}

void initializeBoard(char **board, int rows, int columns, int pieces){
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<columns; j++){
			board[i][j] = char(32);
		}
	}
	printBoard(board, rows, columns);
	playGame(board, rows, columns, pieces, 0);
}

void makeMove(char **board, int rows, int columns, char player){
	int valid = 0;
	while (valid == 0){
		int b;	
		cout<<"Which column would you like to place your piece in? ";
		cin>>b;
		if (b<1 || b>columns || cin.fail()){
			cin.clear();
			cin.ignore(1000, '\n');
			cout<<"Sorry! You didn't input an integer between 1 and the number of columns.  Please input a valid integer to continue!"<<endl;
			valid = 0;
		}
		else{
			if(board[0][b-1] == char(32)){
				int i;
				for(i = 0; board[i][b-1]==char(32) && i<rows; i++){
					valid = 1;
				}
				board[i-1][b-1] = player;
				valid = 1;
			}
			else{
				cout<<"That column is full!  Please enter a different one:  ";
				valid = 0;
			}
		}
	}
	printBoard(board, rows, columns);
}

int aiPlayer(){
	int ai, valid = 0;
	cout<<"How many humans are playing?  Please enter either 1 or 2: ";
	while (valid == 0){
		cin>>ai;
		if (ai>2 || ai<1 || cin.fail()){
			cin.clear();
			cin.ignore(1000, '\n');
			cout<<"Sorry! You didn't enter a 1 or a 2.  Please try again! ";
			valid = 0;
		}
		else
			valid = 1;
	}
	return ai;
}

void playai(char **board, int rows, int columns, char player){
	int valid = 0;
	while (valid == 0){
		int b = rand()%columns+1;
		if(board[0][b-1] == char(32)){
			int i;
			for(i = 0; board[i][b-1]==char(32) && i<rows; i++){
				valid = 1;
			}
			board[i-1][b-1] = player;
			valid = 1;
		}
		else
			valid = 0;
	}
	printBoard(board, rows, columns);
}

void playGame(char **board, int rows, int columns, int pieces, int win){
	int ai = aiPlayer();
	int turn = 0;
	while (win == 0){
		char player;
		if (turn%2 == 0){
			player = 'y';
			makeMove(board, rows, columns, player);
		}
		else{
			player = 'r';
			if (ai == 1)
				playai(board, rows, columns, player);
			else
				makeMove(board, rows, columns, player);
		}
		turn+=1;
		win = checkWin(board, rows, columns, pieces, player);
	}
}

int checkWin(char **board, int rows, int columns, int pieces, char player){
	int h = 0, v = 0, rd = 0, ld = 0, total = 0;
	cout<<endl;
	h = checkHorizontal(board, rows, columns, pieces, player);
	v = checkVertical(board, rows, columns, pieces, player);
	rd = checkRightDiagonal(board, rows, columns, pieces, player);
	ld =checkLeftDiagonal(board, rows, columns, pieces, player);
	total = h+v+rd+ld;
	if(total>0)
		cout<<"Congratulations player "<<player<<"!  You won this round of Connect 4!"<<endl;
	return total;
}

int checkHorizontal(char **board, int rows, int columns, int pieces, char player){
	int count;
	for (int i = 0; i<rows; i++){
		for(int j = 0; j<columns; j++){
			if(board[i][j] == player)
				count+=1;
			else if (count>=pieces)
				return 1;
			else
				count = 0;
		}
		count = 0;
	}
	cout<<endl;
	return count;
}

int checkVertical(char **board, int rows, int columns, int pieces, char player){
	int count;
	for (int j = 0; j<columns; j++){
		for(int i = rows; i>0; i--){
			if(board[i][j] == player)
				count+=1;
			else if (count>=pieces)
				return 1;
			else
				count = 0;
		}
		count = 0;
	}
	cout<<endl;
	return count;
}

int checkRightDiagonal(char **board, int rows, int columns, int pieces, char player){
	int count;
	for(int i = rows; i>0; i--){
		for(int j =columns; j>0; j--){
			for (int z = 0; z<=i && z<=j; z++){
				if(board[i-z][j-z] == player)
					count+=1;
				else if (count>=pieces)
					return 1;
				else
					count = 0;
			}
			count = 0;
		}
		count = 0;
	}
	cout<<endl;
	return count;
}

int checkLeftDiagonal(char **board, int rows, int columns, int pieces, char player){
	int count;
	for(int i = rows; i>0; i--){
		for(int j = 0; j<columns; j++){
			for (int z = 0; z<=i && z<=columns-pieces; z++){
				if(board[i-z][j+z] == player)
					count+=1;
				else if (count>=pieces)
					return 1;
				else
					count = 0;
			}
			count = 0;
		}
		count = 0;
	}
	cout<<endl;
	return count;
}

