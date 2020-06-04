#include <iostream>
#include <ctime>
using namespace std;

const int rows = 10, elements = 10;
int matrix[rows][elements];
int maxships = 10;


void Clear() {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < elements; j++) {
			matrix[i][j] = 0;
		}
	}
}

void Show() {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < elements; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int NumberOfShips() {
	int c = 0;

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < elements; j++) {
			if(matrix[i][j] == 1)
				c++;
		}
	}

	return c;
}

void SetShips() {
	int s = 0;
	
	while(s < maxships) {
		int x = rand() % rows;
		int y = rand() % elements;
		if(matrix[x][y] != 1) {
			s++;
			matrix[x][y] = 1;
		}
	}
}

bool Attack(int x, int y) {
	if(matrix[x][y] == 1) {
		matrix[x][y] = 2;
		return true;
	}

	return false;
}

int main() {
	int position1, position2;
	string prompt;

	srand(time(NULL));
	Clear();

	cout << "Battleship\n";
	cout << "This game mimics the board game Battleship and will ask user to input locations to see if they hit a randomly generated ship. \n";
	cout << "When entering location of where you want to shoot a bomb use two integer numbers (1 2)\n\n";
	

	while(1) {
		cout << "Please input location: ";
		cin >> position1 >> position2;

		if(Attack(position1, position2))
			cout << "Hit!\n";
		else
			cout << "Miss!\n";

		cout << "Number of ships left: " << NumberOfShips() << endl;

		cout << "Do you want to surrender (yes/no)? ";
		cin >> prompt;

		if(prompt == "yes")
			break;
	}
	
	cout << "Game over!\n";

	Show();
	system("pause");
	return 0;
}
