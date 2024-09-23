#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int fieldNums = 9;

void rules();
void showField(const vector<char>& const field);
bool isLegal(const vector<char>& const field, int move);
int botMove(vector<char>& field, char& pawn);
bool isOver(const vector<char>& const field, bool winner);
void goesX(vector<char>& field, int move);
void goesO(vector<char>& field, int move);
bool winner(vector<char>& field);

int main() {
	bool draw = false;
	int move;
	char whoMovesFirstQeustion;
	vector<char> field(fieldNums, '?');
	
	rules();
	do {
		cout << "Who moves first? Enter 'X' if you or 'O' if bot." << endl;
		cin >> whoMovesFirstQeustion;
	} while (whoMovesFirstQeustion != 'X' && whoMovesFirstQeustion != 'O');


	while (!isOver(field, winner(field))) {
		int temp = 0;
		for (auto it = field.begin(); it != field.end(); it++) {
			if (*it == '?') {
				draw = false;
				break;
			}
			else {
				draw = true;
			}
		}
		if (!winner(field) && draw == true) {
			cout << "It's a draw!";
			break;
		}
		if (whoMovesFirstQeustion == 'X') {
			do {
				cout << "Enter your move: ";
				cin >> move;
			} while (!isLegal(field, move));
			if (isLegal(field, move)) {
				goesX(field, move);
				showField(field);
				if (winner(field)) {
					cout << "Human won!";
					break;
				}
			}
			cout << "Bot's move: " << endl;
			goesO(field, botMove(field, whoMovesFirstQeustion));
			showField(field);
			if (winner(field)) {
				cout << "Bot won!";
				break;
			}
		} 
		if (whoMovesFirstQeustion == 'O') {
			cout << "Bot's move: " << endl;
			goesX(field, botMove(field, whoMovesFirstQeustion));
			showField(field);
			if (winner(field)) {
				cout << "Bot won!";
				break;
			}

			do {
				cout << "Enter your move: ";
				cin >> move;
			} while (!isLegal(field, move));
			if (isLegal(field, move)) {
				goesO(field, move);
				showField(field);
				if (winner(field)) {
					cout << "Human won!";
					break;
				}
			}
		}
	}

}


void goesX(vector<char>& field, int move) {
	field[move] = 'X';
}

void goesO(vector<char>& field, int move) {
	field[move] = 'O';
}


bool isLegal(const vector<char>& const field, int move) {
	if (field[move] != 'O' && field[move] != 'X') {
		return true;
	}
	else {
		return false;
	}
}

void rules() {
	cout << "Rules: " << endl;
	cout << "Bla bla bla, u know it." << endl;
}

void showField(const vector<char>& const field) {
	cout << "|-|-|-|" << endl;
	cout << "|" << field[0] << "|" << field[1] << "|" << field[2] << "|" << endl;
	cout << "|" << field[3] << "|" << field[4] << "|" << field[5] << "|" << endl;
	cout << "|" << field[6] << "|" << field[7] << "|" << field[8] << "|" << endl;
	cout << "|-|-|-|" << endl;
}

bool isOver(const vector<char>& const field, bool winner) {
	int over = 0;
	vector<char>::const_iterator it;
	for (it = field.begin(); it != field.end(); it++) {
		if (*it == '?') {
			over++;
		}
		
	}
	if (over == 0) {
		return true;
	}
	else {
		return false;
	}
	if (winner == true) {
		return true;
	}
}

bool winner(vector<char>& field) {
	if (field[0] == 'X' && field[1] == 'X' && field[2] == 'X') {
		return true;
	}
	if (field[3] == 'X' && field[4] == 'X' && field[5] == 'X') {
		return true;
	}
	if (field[6] == 'X' && field[7] == 'X' && field[8] == 'X') {
		return true;
	}
	if (field[0] == 'X' && field[3] == 'X' && field[6] == 'X') {
		return true;
	}
	if (field[1] == 'X' && field[4] == 'X' && field[7] == 'X') {
		return true;
	}
	if (field[2] == 'X' && field[5] == 'X' && field[8] == 'X') {
		return true;
	}
	if (field[0] == 'X' && field[4] == 'X' && field[8] == 'X') {
		return true;
	}
	if (field[2] == 'X' && field[4] == 'X' && field[6] == 'X') {
		return true;
	}
	// O
	if (field[0] == 'O' && field[1] == 'O' && field[2] == 'O') {
		return true;
	}
	if (field[3] == 'O' && field[4] == 'O' && field[5] == 'O') {
		return true;
	}
	if (field[6] == 'O' && field[7] == 'O' && field[8] == 'O') {
		return true;
	}
	if (field[0] == 'O' && field[3] == 'O' && field[6] == 'O') {
		return true;
	}
	if (field[1] == 'O' && field[4] == 'O' && field[7] == 'O') {
		return true;
	}
	if (field[2] == 'O' && field[5] == 'O' && field[8] == 'O') {
		return true;
	}
	if (field[0] == 'O' && field[4] == 'O' && field[8] == 'O') {
		return true;
	}
	if (field[2] == 'O' && field[4] == 'O' && field[6] == 'O') {
		return true;
	}
	else {
		return false;
	}

}

int botMove(vector<char>& field, char& pawn) {
	char botPawn;
	if (pawn == 'O') {
		botPawn = 'X';
	}
	if (pawn == 'X') {
		botPawn = 'O';
	}
	if (field[0] == botPawn && field[1] == botPawn && field[2] != pawn) {
		return 2;
	}
	if (field[1] == botPawn && field[2] == botPawn && field[0] != pawn) {
		return 0;
	}
	if (field[0] == botPawn && field[2] == botPawn && field[1] != pawn) {
		return 1;
	}

	if (field[3] == botPawn && field[4] == botPawn && field[5] != pawn) {
		return 5;
	}
	if (field[4] == botPawn && field[5] == botPawn && field[3] != pawn) {
		return 3;
	}
	if (field[3] == botPawn && field[5] == botPawn && field[4] != pawn) {
		return 4;
	}

	if (field[6] == botPawn && field[7] == botPawn && field[8] != pawn) {
		return 8;
	}
	if (field[7] == botPawn && field[8] == botPawn && field[6] != pawn) {
		return 6;
	}
	if (field[6] == botPawn && field[8] == botPawn && field[7] != pawn) {
		return 7;
	}

	if (field[0] == botPawn && field[3] == botPawn && field[6] != pawn) {
		return 6;
	}
	if (field[3] == botPawn && field[6] == botPawn && field[0] != pawn) {
		return 0;
	}
	if (field[0] == botPawn && field[6] == botPawn && field[3] != pawn) {
		return 3;
	}

	if (field[1] == botPawn && field[4] == botPawn && field[7] != pawn) {
		return 7;
	}
	if (field[4] == botPawn && field[7] == botPawn && field[1] != pawn) {
		return 1;
	}
	if (field[1] == botPawn && field[7] == botPawn && field[4] != pawn) {
		return 4;
	}

	if (field[2] == botPawn && field[5] == botPawn && field[8] != pawn) {
		return 8;
	}
	if (field[5] == botPawn && field[8] == botPawn && field[2] != pawn) {
		return 2;
	}
	if (field[2] == botPawn && field[8] == botPawn && field[5] != pawn) {
		return 5;
	}

	if (field[0] == botPawn && field[4] == botPawn && field[8] != pawn) {
		return 8;
	}
	if (field[4] == botPawn && field[8] == botPawn && field[0] != pawn) {
		return 0;
	}
	if (field[0] == botPawn && field[8] == botPawn && field[4] != pawn) {
		return 4;
	}

	if (field[2] == botPawn && field[4] == botPawn && field[6] != pawn) {
		return 6;
	}
	if (field[4] == botPawn && field[6] == botPawn && field[2] != pawn) {
		return 2;
	}
	if (field[2] == botPawn && field[6] == botPawn && field[4] != pawn) {
		return 4;
	}

	//humanContr

	if (field[0] == pawn && field[1] == pawn && field[2] != botPawn) {
		return 2;
	}
	if (field[1] == pawn && field[2] == pawn && field[0] != botPawn) {
		return 0;
	}
	if (field[0] == pawn && field[2] == pawn && field[1] != botPawn) {
		return 1;
	}

	if (field[3] == pawn && field[4] == pawn && field[5] != botPawn) {
		return 5;
	}
	if (field[4] == pawn && field[5] == pawn && field[3] != botPawn) {
		return 3;
	}
	if (field[3] == pawn && field[5] == pawn && field[4] != botPawn) {
		return 4;
	}

	if (field[6] == pawn && field[7] == pawn && field[8] != botPawn) {
		return 8;
	}
	if (field[7] == pawn && field[8] == pawn && field[6] != botPawn) {
		return 6;
	}
	if (field[6] == pawn && field[8] == pawn && field[7] != botPawn) {
		return 7;
	}

	if (field[0] == pawn && field[3] == pawn && field[6] != botPawn) {
		return 6;
	}
	if (field[3] == pawn && field[6] == pawn && field[0] != botPawn) {
		return 0;
	}
	if (field[0] == pawn && field[6] == pawn && field[3] != botPawn) {
		return 3;
	}

	if (field[1] == pawn && field[4] == pawn && field[7] != botPawn) {
		return 7;
	}
	if (field[4] == pawn && field[7] == pawn && field[1] != botPawn) {
		return 1;
	}
	if (field[1] == pawn && field[7] == pawn && field[4] != botPawn) {
		return 4;
	}

	if (field[2] == pawn && field[5] == pawn && field[8] != botPawn) {
		return 8;
	}
	if (field[5] == pawn && field[8] == pawn && field[2] != botPawn) {
		return 2;
	}
	if (field[2] == pawn && field[8] == pawn && field[5] != botPawn) {
		return 5;
	}

	if (field[0] == pawn && field[4] == pawn && field[8] != botPawn) {
		return 8;
	}
	if (field[4] == pawn && field[8] == pawn && field[0] != botPawn) {
		return 0;
	}
	if (field[0] == pawn && field[8] == pawn && field[4] != botPawn) {
		return 4;
	}

	if (field[2] == pawn && field[4] == pawn && field[6] != botPawn) {
		return 6;
	}
	if (field[4] == pawn && field[6] == pawn && field[2] != botPawn) {
		return 2;
	}
	if (field[2] == pawn && field[6] == pawn && field[4] != botPawn) {
		return 4;
	}

	//free moves

	if (field[4] == '?') {
		return 4;
	}
	else if (field[0] == '?') {
		return 0;
	}
	else if (field[2] == '?') {
		return 2;
	}
	else if (field[6] == '?') {
		return 6;
	}
	else if (field[8] == '?') {
		return 8;
	}
	else if (field[1] == '?') {
		return 1;
	}
	else if (field[5] == '?') {
		return 5;
	}
	else if (field[7] == '?') {
		return 7;
	}
	else if (field[3] == '?') {
		return 3;
	}

}