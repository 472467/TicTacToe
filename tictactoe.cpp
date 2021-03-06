/* WRITTEN BY BRENDAN
PLAYS A CRAPPY TEXT BASED TICTACTOE
USES GLOBAL GRID AND STUFF
CHAR ARRAY move IS PASSED INTO TRANSLATE MOVE,
VERY FANCY STUFF
HAVE FUN

*/

#include <iostream>
#include <string>
#include <istream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int valueGrid [3][3];//contains who owns each spot(0 is unowned)
char charGrid [4][4];//char grid for printing 
int PLAYER_X = 1;//final ints to simplify 
int PLAYER_O = 2;
int X_TURN = 0;
int O_TURN = 1;
//struct xYCoord{int x, int y};
bool translateMove(char *move, int player);//initializes  other functions in front of main method, could put main() at bottom of page and that would work too
bool checkWin(int player);
void updateGrid(int turn, int xWins, int oWins);
bool checkTie();
void resetGrid();

int main(){
	system("clear");//clears other garbage that pollutes the game
	bool validMove = false;
	char move [30];
	charGrid[0][0]=' ';//adds framework to char grid so it isnt readded everytime, this is never edited
	charGrid[0][1]='a';
	charGrid[0][2]='b';
	charGrid[0][3]='c';
	charGrid[1][0]='1';
	charGrid[2][0]='2';
	charGrid[3][0]='3';
	for(int x = 1; x < 4; x++){//adds markers in char grid
		for(int y = 1; y < 4; y++){
			charGrid[x][y]='.';
		}
	}
	for(int y = 0; y < 3; y++){//makes value grid all zeroes to start
		for(int x = 0; x < 3; x++){
			valueGrid[x][y] = 0;
		}
	}
	for(int x =0;  x < 30; x++){//cleans input
		move[x]='\0';
	}
	
	int turn = 0;
	int xWins = 0;
	int oWins = 0;
	while(true){//endless games of tictactoe yay!
		
		while (!validMove){//move input
			updateGrid(turn, xWins, oWins);//outputs the char grid
			
			cout << "Input new move.\n";
			cin.clear();
			cin.sync();//cleans cin 
			cin.getline(move, 30);
			
			if(turn == X_TURN){//changes turn only if unoccupied space is claimed
				if(translateMove(move, PLAYER_X)){
					validMove = true;
				}else{
					validMove = false;
				}
			}else{
				if(translateMove(move, PLAYER_O)){
					validMove = true;
				}else{
					validMove = false;
				}
			}
			
			if(checkWin(PLAYER_X)){
				cout << "X WINS.";
				cout << endl << "Hit ENTER to continue...";
				xWins++;
				cin.clear();
				cin.sync();
				cin.get();//makes the click to continue thing
				
				turn = PLAYER_X;
				resetGrid();
			}else if(checkWin(PLAYER_X)){
				cout << "O WINS.";
				cout << endl << "Hit ENTER to continue...";
				oWins++;
				cin.clear();
				cin.sync();
				cin.get();
				
				turn = PLAYER_X;
				resetGrid();
			}else if(checkTie()){
				cout << "NO WINNER.";
				cout << endl << "Hit ENTER to continue...";
				
				cin.clear();
				cin.sync();
				cin.get();
				
				turn = PLAYER_X;
				resetGrid();
			}
			
			if(validMove == true){
				//cout << "ValidMove";
				if(turn == X_TURN){
					turn = O_TURN;
				}else{
					turn = X_TURN;
				}
			}
			
			
			system("clear");//clears thing again to give illusion of fps sorta
		}
		validMove = false;//makes it so that above while loop runs again
	}
}


void updateGrid(int turn, int xWins, int oWins){//updates the char grid then prints it
	cout << "Welcome to Tic Tac Toe! Type your move into the console. X cord first, then Y cord. EX. '1a', '2a' \n\n";
	cout << "x wins: " << xWins << " | o wins: " << oWins << "\n";
	
	if(turn == X_TURN){
		cout << "X TURN\n";
	}else{
		cout << "O TURN\n";
	}
	for(int x = 0; x < 3; x++){
		for(int y = 0; y < 3; y++){
			if(valueGrid[x][y]== PLAYER_X){
				charGrid[x+1][y+1]='X';
			}else if(valueGrid[x][y]== PLAYER_O){
				charGrid[x+1][y+1]='O';
			}else{
				charGrid[x+1][y+1]='.';
			}
			
		}
	}
	for(int x = 0; x < 4; x++){
		for(int y = 0; y < 4; y++){
			cout << charGrid[x][y] << ' ';
		}
		cout << '\n';
	}
}

void resetGrid(){//resets valueGrid which essential resets the game, minus wins of course
	for(int x = 0; x < 3; x++){
		for(int y = 0; y < 3; y++){
			valueGrid[x][y]=0;
		}
	}
}


bool translateMove(char *move, int player){//translates input to a position on the board
	if(strcmp(move, "1a") == 0){
		if(valueGrid[0][0]== 0){
			cout << valueGrid[0][0];
			valueGrid[0][0]= player;
			return true;
		}else{//need these to output false, otherwise turn swaps
			return false;
		}
	}else if(strcmp(move, "1b")==0){
		if(valueGrid[0][1]== 0){
			valueGrid[0][1]= player;
			return true;
		}else{
			return false;
		}
	}else if(strcmp(move, "1c")==0){
		if(valueGrid[0][2]== 0){
			valueGrid[0][2]= player;
			return true;
		}else{
			return false;
		}
	}else if(strcmp(move, "2a")==0){
		if(valueGrid[1][0]== 0){
			valueGrid[1][0]= player;
			return true;
		}else{
			return false;
		}
	}else if(strcmp(move, "2b")==0){
		if(valueGrid[1][1]== 0){
			valueGrid[1][1]= player;
			return true;
		}else{
			return false;
		}
	}else if(strcmp(move, "2c")==0){
		if(valueGrid[1][2]== 0){
			valueGrid[1][2]= player;
			return true;
		}else{
			return false;
		}
	}else if(strcmp(move, "3a")==0){
		if(valueGrid[2][0]== 0){
			valueGrid[2][0]= player;
			return true;
		}else{
			return false;
		}
	}else if(strcmp(move, "3b")==0){
		if(valueGrid[2][1]== 0){
			valueGrid[2][1]= player;
			return true;
		}else{
			return false;
		}
	}else if(strcmp(move, "3c")==0){
		if(valueGrid[2][2]== 0){
			valueGrid[2][2]= player;
			return true;
		}else{
			return false;
		}
	}else{
		cout << "test\n\n\n\n\n\n test test test test";
		return false;
	}
}

bool checkWin(int player){ //checks if anyone has won yet, gets palyer
	if (valueGrid [0][0] == player &&
			valueGrid[0][1] == player && 
			valueGrid[0][2] == player){
		return true;
	}
	if (valueGrid [0][0] == player 
			&& valueGrid[1][1] == player 
			&& valueGrid[2][2] == player){
		return true;
	}
	if (valueGrid [1][0] == player &&
			valueGrid[1][1] == player && 
			valueGrid[1][2] == player){
		return true;
	}
	if (valueGrid [0][0] == player 
			&& valueGrid[1][0] == player 
			&& valueGrid[2][0] == player){
		return true;
	}
	if (valueGrid [0][1] == player &&
			valueGrid[1][1] == player && 
			valueGrid[2][1] == player){
		return true;
	}
	if (valueGrid [0][2] == player 
			&& valueGrid[1][2] == player 
			&& valueGrid[2][2] == player){
		return true;
	}
	if (valueGrid [0][2] == player &&
			valueGrid[1][1] == player && 
			valueGrid[2][0] == player){
		return true;
	}
	if (valueGrid [2][0] == player 
			&& valueGrid[2][1] == player 
			&& valueGrid[2][2] == player){
		return true;
	}
	
	return false;
 }
bool checkTie(){//checks if game is tie
	int emptyO = 0;
	int emptyX= 0;
	int empty = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (valueGrid[i][j] == 1){
				emptyX++; 
			}
			else if(valueGrid[i][j] == 2){
				emptyO++; 
			}
			empty+= valueGrid[i][j];
		}
		
	}
	if (checkWin(PLAYER_X) == false){
		if (checkWin(PLAYER_O) == false){
			if (emptyO == 5){ //starting turn alternates making this necessary
				if (empty == 14){
					return true;
				}
			}
			if (emptyO == 4){
				if (empty == 13){
					return true;
				}
			}
		}
	}
	return false;
}