//connect-4 game
#include <iostream>
#include <vector>
using namespace std;

//get board size
void get_board_size(int& col, int& row) {
	// default value of board is 7 columns and 6 rows
	cout << "Enter Board Size!" << endl;
	cout << "Column: "; cin >> col;
	while (col < 7 || col > 9) {
		cout << "Invalid Column!\nColumn must be greater than 6 and less than 10.\n";
		cout << "Column: "; cin >> col;
	}
	cout << "Row   : "; cin >> row;
	while (row < 6 || row > 9) {
		cout << "Invalid Row!\nRow must be greater than 5 and less than 10.\n";
		cout << "Row   : "; cin >> row;
	}
	cout << "As per your request, game board has been created for " << col << " column and " << row << " rows." << endl;
}

//initialize board
void initialize_board(vector<vector<int>>& board) {
	int c, r;
	get_board_size(c, r);
	vector<int> col(c, 0);
	vector<vector<int>> b(r, col);
	board = b;
}

//print board
void print_board(vector<vector<int>>& board) {
	for (int i = 0, n = board.size(); i < n; i++) {
		for (int j = 0, m = board[i].size(); j < m; j++) cout << board[i][j] << " ";
		cout << endl;
	}
}

//initialize game
void initialize_game(vector<vector<int>>& board) {
	initialize_board(board);
	print_board(board);
}

// get move for next player
void get_move(int& r, int& c) {
	cout << "Enter your coordinate to play!\n";
	cout << "Row No    : ";
	cin >> r;
	cout << "Column No : ";
	cin >> c;
}

// check for valid move
bool isMoveValid(int r, int c, vector<vector<int>>& board) {
	int row = board.size();
	int col = board[0].size();
	bool value = true;
	if (r < 1 || r > row) {
		value = false;
		cout << "Wrong Row! ";
	}
	else if (c < 1 || c > col) {
		value = false;
		cout << "Wrong Column! ";
	}
	else if (value) {
		if (board[r - 1][c - 1] != 0) {
			value = false;
			cout << "Location Occupied! ";
		}
	}
	return value;
}

// play piece
void place_piece(int player, vector<vector<int>>& board) {
	int r, c;
	get_move(r, c);
	while (!isMoveValid(r, c, board)) {
		cout << "Try Again\n";
		get_move(r, c);
	}
	board[r - 1][c - 1] = player;
}

//horizontal winner
bool horizontal_winner(vector<vector<int>>& board, int player) {
	for (int i = 0, r = board.size(); i < r; i++) {
		for (int j = 0, c = board[i].size(); j < c - 3; j++) {
			if (board[i][j] == player) {
				if (board[i][j] == board[i][j + 1]) {
					if (board[i][j] == board[i][j + 2]) {
						if (board[i][j] == board[i][j + 3]) return true;
					}
				}
			}
		}
	}
	return false;
}

//vertical winner
bool vertical_winner(vector<vector<int>>& board, int player) {
	for (int i = 0, c = board[0].size(); i < c; i++) {
		for (int j = 0, r = board.size(); j < r - 3; j++) {
			if (board[j][i] == player) {
				if (board[j][i] == board[j + 1][i]) {
					if (board[j][i] == board[j + 2][i]) {
						if (board[j][i] == board[j + 3][i]) return true;
					}
				}
			}
		}
	}
	return false;
}

//rising diagonal
bool rising_diagonal(vector<vector<int>>& board, int player) {
	int r = board.size() - 1, c = board[0].size();
	for (int i = r; i > 2; i--) {
		for (int j = 0; j < c - 3; j++) {
			if (board[i][j] == player) {
				if (board[i][j] == board[i - 1][j + 1]) {
					if (board[i][j] == board[i - 2][j + 2]) {
						if (board[i][j] == board[i - 3][j + 3]) return true;
					}
				}
			}
		}
	}
	return false;
}

//falling diagonal
bool falling_diagonal(vector<vector<int>>& board, int player) {
	for (int i = 0, r = board.size(); i < r - 3; i++) {
		for (int j = 0, c = board[i].size(); j < c - 3; j++) {
			if (board[i][j] == player) {
				if (board[i][j] == board[i + 1][j + 1]) {
					if (board[i][j] == board[i + 2][j + 2]) {
						if (board[i][j] == board[i + 3][j + 3]) return true;
					}
				}
			}
		}
	}
	return false;
}

//diagonal winner
bool diagonal_winner(vector<vector<int>>& board, int player) {
	if (rising_diagonal(board, player)) return true;
	else if (falling_diagonal(board, player)) return true;
	else return false;
}

//check for winner
bool check_winner(vector<vector<int>>& board, int player) {
	if (horizontal_winner(board, player)) return true;
	else if (vertical_winner(board, player)) return true;
	else if (diagonal_winner(board, player)) return true;
	else return false;
}

//check for tie
bool check_tie(vector<vector<int>>& board) {
	for (int i = 0, r = board.size(); i < r; i++) {
		for (int j = 0, c = board[0].size(); j < c; j++) {
			if (board[i][j] == 0) return false;
		}
	}
	return true;
}

int main() {
	//initialize game
	vector<vector<int>> board;
	initialize_game(board);

	//repeat turns
	int player = 1;
	while (true) {
		// get move for next player
		cout << "Player " << player << " turn!\n";

		//place piece
		place_piece(player, board);

		//display board
		print_board(board);

		//check for winner or tie
		if (check_winner(board, player)) break;
		if (check_tie(board)) {
			player = 0;
			break;
		}

		//change player turn
		if (player == 1) player = 2;
		else player = 1;
	}

	//declare winner or tie
	if (player) cout << "Game Ended!\nPlayer " << player << " wins!\n";
	else cout << "Game tie!\n";
}