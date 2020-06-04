// This game only requires the std C++ library, nothing else
// This game is a cool way to introduce yourself to work with matrices

#include <iostream>
using namespace std;

int n;
char player = 'X';
char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void Draw() {
	system("cls");
	
	cout << "Tic-tac-toe \n";

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}
}

void Input() {
	int a;

	cout << "Enter your action: ";
	cin >> a;

	if(a == 1) {
		if(matrix[0][0] == '1')
			matrix[0][0] = player;
		else {
			cout << "Cannot assign spot, already in use.\n";
			Input();
		}
	}
	else if(a == 2) {
		if(matrix[0][1] == '2')
			matrix[0][1] = player;
		else {
			cout << "Cannot assign spot, already in use.\n";
			Input();
		}
	}
	else if(a == 3) {
		if(matrix[0][2] == '3')
			matrix[0][2] = player;
		else {
			cout << "Cannot assign spot, already in use.\n";
			Input();
		}
	}
	else if(a == 4) {
		if(matrix[1][0] == '4')
			matrix[1][0] = player;
		else {
			cout << "Cannot assign spot, already in use.\n";
			Input();
		}
	}
	else if(a == 5) {
		if(matrix[1][1] == '5')
			matrix[1][1] = player;
		else {
			cout << "Cannot assign spot, already in use.\n";
			Input();
		}
	}
	else if(a == 6) {
		if(matrix[1][2] == '6')
			matrix[1][2] = player;
		else {
			cout << "Cannot assign spot, already in use.\n";
			Input();
		}
	}
	else if(a == 7) {
		if(matrix[2][0] == '7')
			matrix[2][0] = player;
		else {
			cout << "Cannot assign spot, already in use.\n";
			Input();
		}
	}
	else if(a == 8) {
		if(matrix[2][1] == '8')
			matrix[2][1] = player;
		else {
			cout << "Cannot assign spot, already in use.\n";
			Input();
		}
	}
	else if(a == 9) {
		if(matrix[2][2] == '9')
			matrix[2][2] = player;
		else {
			cout << "Cannot assign spot, already in use.\n";
			Input();
		}
	}
}

void TogglePlayer() {
	if(player == 'X')
		player = 'O';
	else 
		player = 'X';
}

char WinCondition() {
	// 1st set of win conditions for player 'X'
	if(matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
		return 'X';
	if(matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
		return 'X';
	if(matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
		return 'X';

	if(matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
		return 'X';
	if(matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
		return 'X';
	if(matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
		return 'X';

	if(matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
		return 'X';
	if(matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X')
		return 'X';

	// 2nd set of win conditions for player 'O'
	
	if(matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
		return 'O';
	if(matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
		return 'O';
	if(matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
		return 'O';

	if(matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
		return 'O';
	if(matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
		return 'O';
	if(matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
		return 'O';

	if(matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
		return 'X';
	if(matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O')
		return 'O';

	return '/';
}

int main() {
	n = 0;

	Draw();

	while(1) {
		n++; 
		Input();
		Draw();
		if(WinCondition() == 'X') {
			cout << "Player X wins!\n";
			break;
		}
		else if(WinCondition() == 'O') {
			cout << "Player O wins!\n";
			break;
		}
		else if(WinCondition() == '/' && n == 9) {
			cout << "Nobody wins, it's a draw!\n";
			break;
		}

		TogglePlayer();
	}	

	system("pause");
	return 0;
}
