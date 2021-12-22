#include <iostream>
using namespace std;

void clearBoard(char board[3][3]) {
	for(int i = 0; i<3; i++) {
		for(int j = 0; j<3; j++) {
			board[i][j] = '-';
		}
	}
}

void printBoard(char board[3][3]) {
	
	int coord[3] = {0,1,2};
	cout << "  ";
	for(int i = 0; i<3; i++) {
		cout << coord[i] << " ";
	}
		
	cout << endl;
		

	for(int i = 0; i<3; i++) {
		cout << coord[i] << " ";

		for(int j = 0; j<3; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void play(char board[3][3], char player) {
	int x,y;
	cout << "Player " << player << ", Please enter row and col between 0 and 2: ";
	cin >> x >> y;
	
	while(x < 0 || x > 2 || y < 0 || y > 2) {
		cout << "Player " << player << ", Please enter row and col between 0 and 2: ";
		cin >> x >> y;
	}
	
	if(board[x][y] == '-')
		board[x][y] = player;
	else
		cout << "You tried to snatch the co ordinates of the other player and the punishment is your turn is neglected." << endl;
}

char testRows(char board[3][3]) {

	int counterX;
	int counterO;

	for(int i = 0; i<3; i++) {
		counterX = 0;
		counterO = 0;
		for(int j = 0; j<3; j++) {
			if(board[i][j] == 'X')
				counterX++;
			if(board[i][j] == 'O')
				counterO++; 
		}
		
		if(counterX == 3)
			return 'X';
		if(counterO == 3)
			return 'O';		

	}
}

char testCols(char board[3][3]) {

	int counterX;
	int counterO;

	for(int i = 0; i<3; i++) {
		counterX = 0;
		counterO = 0;
		for(int j = 0; j<3; j++) {
			if(board[j][i] == 'X')
				counterX++;
			if(board[j][i] == 'O')
				counterO++; 
		}
		
		if(counterX == 3)
			return 'X';
		if(counterO == 3)
			return 'O';		

	}
}


char testDiag(char board[3][3]) {

	int counterX = 0;
	int counterO = 0;

	for(int i = 0; i<3; i++) {
		if(board[i][i] == 'X')
			counterX++;
		if(board[i][i] == 'O')
			counterO++;
	}

	if(counterX == 3)
		return 'X';
	if(counterO == 3)
		return 'O';
	
	counterX = 0;
	counterO = 0;
	
	for(int i = 0,j = 2; i<3; i++,j--) {
		if(board[j][i] == 'X') 
			counterX++;
		if(board[j][i] == 'O')
			counterO++;
	}

	if(counterX == 3)
		return 'X';
	if(counterO == 3)
		return 'O';
	
}

void game(char board[3][3]) {

	char player1 = 'X';
	char player2 = 'O';
	char winner;

	clearBoard(board);
	
	while(1) {	
		printBoard(board);
		play(board,player1);
		printBoard(board);
		play(board,player2);
		winner = testRows(board);
		if(winner == 'X' || winner == 'O') {
			cout << winner << " Has won the game." << endl;
			break;
		}
		winner = testCols(board);
		if(winner == 'X' || winner == 'O') {
			cout << winner << " Has won the game." << endl;
			break;
		}
		winner = testDiag(board);
		if(winner == 'X' || winner == 'O') {
			cout << winner << " Has won the game." << endl;
			break;
		}
	}
}


int main() {
	
	char board[3][3];
	char choice;
	
	while(1) {
		cout << "Start Game (Y or N): ";	
		cin >> choice;
		cin.ignore();

		if(choice == 'N' || choice == 'n') 
			break;
		if(choice == 'Y' || choice == 'y')
			game(board);
	}
	
}
