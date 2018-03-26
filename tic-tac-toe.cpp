//tic tac toe game in C++
#include <iostream>
using namespace std;

void DrawBoard();		// Draws the board each turn!
void GetInput();		// Asks player for (valid) input and returns that value!
int CheckWinner();		// Checks for a winner!
const int FREE = 0;		// Board slot not taken
const int FALSE = 0;
const int X = 1;		// Player X
const int O = 2;		// Player Y
const int DRAW = -1;	// Game is a draw
char board[9] = { '1','2','3','4','5','6','7','8','9' };	// The board!
int player = X;			// The player!

int main()
{
	int winner = FALSE;		// For winner: FALSE = 0, X = 1, O = 2
	// The Game //
	while (!winner)
	{
		DrawBoard();
		GetInput();
		winner = CheckWinner();
		if (player != O) player = O; else player = X;	// Switches player each turn
	}
	DrawBoard();
	if (winner == DRAW)
		cout<< "Draw!!!\n";
	else
		cout<< "Congratulations Player " << winner << "!\nYou win!\n";
	cin.ignore();
	cin.get();
}

//function to draw board
void DrawBoard()
{
	cout<< " " << board[0] << " | " << board[1] << " | " << board[2] << " \n"
		<< "-----------\n"
		<< " " << board[3] << " | " << board[4] << " | " << board[5] << " \n"
		<< "-----------\n"
		<< " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
}

//asks user for valid input returns that value
void GetInput()
{
	int position_input;  //variable to point input at position
	// Checks Input Validity //
	while (true)
	{
		cout << "Player " << player << "\n" << "Enter a position (1-9):\n";
		cin >> position_input;
		position_input--;			// Decrement input since arrays begin at 0
		if (position_input < 0 || position_input > 8 || board[position_input] == 'X' || board[position_input] == 'O')
		{
			DrawBoard();			// Re-draw board since we just cleared screen
			cout << "INVALID POSITION, TRY AGAIN...\n";
			continue;
		}
		break;
	}
	// Updates Board Value //
	if (player != X) board[position_input] = 'O';
	else board[position_input] = 'X';
}


int CheckWinner()
{
	// Check Row Wins //
	if (board[0] == board[1] && board[1] == board[2])
		return player;
	else if (board[3] == board[4] && board[4] == board[5])
		return player;
	else if (board[6] == board[7] && board[7] == board[8])
		return player;

	// Check Column Wins //
	else if (board[0] == board[3] && board[3] == board[6])
		return player;
	else if (board[1] == board[4] && board[4] == board[7])
		return player;
	else if (board[2] == board[5] && board[5] == board[8])
		return player;

	// Check Diagonals //
	else if (board[0] == board[4] && board[4] == board[8])
		return player;
	else if (board[2] == board[4] && board[4] == board[6])
		return player;

	else return FALSE;
}
