/* WRITTEN BY BRENDAN
*/

#include <iostream>
#include <string>
#include <istream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int valueGrid [3][3];
char charGrid [4][4];
int PLAYER_X = 1;
int PLAYER_O = 2;
int X_TURN = 0;
int O_TURN = 1;
//struct xYCoord{int x, int y};
bool translateMove(char *move, int player);
bool checkWin(int player);
void updateGrid();
bool checkTie();

int main(){
	system("clear");
	bool validMove = false;
	char move [30];
	charGrid[0][0]=' ';
	charGrid[0][1]='a';
	charGrid[0][2]='b';
	charGrid[0][3]='c';
	charGrid[1][0]='1';
	charGrid[2][0]='2';
	charGrid[3][0]='3';
	for(int x = 1; x < 4; x++){
		for(int y = 1; y < 4; y++){
			charGrid[x][y]='.';
		}
	}
	for(int y = 0; y < 3; y++){
		for(int x = 0; x < 3; x++){
			valueGrid[x][y] = 0;
		}
	}
	for(int x =0;  x < 30; x++){//cleans input
		move[x]='\0';
	}
	cout << "Welcome to Tic Tac Toe! Type your move into the console. X cord first, then Y cord. EX. '1a', '2a' \n";
	int turn = 0;
	while(true){
		
		while (!validMove){//move input
			updateGrid();
			
			if(turn == 0){
				cout << "Input new move.\n";
				cin.getline(move, 30);
				if(translateMove(move, PLAYER_X)){
					validMove = true;
				}
				if(checkWin(PLAYER_X)){
					cout << "X WINS.";
					cout << endl << "Hit ENTER to continue...";
					cin.clear();
					cin.sync();
					cin.get();
				}else if(checkWin(PLAYER_X)){
					cout << "O WINS.";
					cout << endl << "Hit ENTER to continue...";
					cin.clear();
					cin.sync();
					cin.get();
				}else if(checkTie()){
					cout << "NO WINS.";
					cout << endl << "Hit ENTER to continue...";
					cin.clear();
					cin.sync();
					cin.get();
				}
				turn = O_TURN;
			}else{
				
				turn = X_TURN;
			}
			system("clear");
			//cin.ignore();
		}
		cout << "SUCCESS\n";
		validMove = false;
	}
}


void updateGrid(){
	for(int x = 0; x < 3; x++){
		for(int y = 0; y < 3; y++){
			if(valueGrid[x][y]== PLAYER_X){
				charGrid[x+1][y+1]='X';
			}else if(valueGrid[x][y]== PLAYER_O){
				charGrid[x+1][y+1]='Y';
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


bool translateMove(char *move, int player){
	if(strcmp(move, "1a") == 0){
		valueGrid[0][0]= player;
		return true;
	}else if(strcmp(move, "1b")==0){
		valueGrid[0][1]= player;
		return true;
	}else if(strcmp(move, "1c")==0){
		valueGrid[0][2]= player;
		return true;
	}else if(strcmp(move, "2a")==0){
		valueGrid[1][0]= player;
		return true;
	}else if(strcmp(move, "2b")==0){
		valueGrid[1][1]= player;
		return true;
	}else if(strcmp(move, "2c")==0){
		valueGrid[1][2]= player;
		return true;
	}else if(strcmp(move, "3a")==0){
		valueGrid[2][0]= player;
		return true;
	}else if(strcmp(move, "3b")==0){
		valueGrid[2][1]= player;
		return true;
	}else if(strcmp(move, "3c")==0){
		valueGrid[2][2]= player;
		return true;
	}else{
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