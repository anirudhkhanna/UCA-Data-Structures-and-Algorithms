/* The N queens problem is the problem of placing N queens on an N×N chessboard so that no two queens can attack each other.
   A queen can attack in the row, in the column and in the diagonals.
   
   This problem can be solved by backtracking.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

// check if a given position (r, c) is safe for the current chessboard[][]
bool isSafe(int **chessboard, int N, int r, int c) {
	int i, j;

	// check for another queen in the column
	for(i = 0; i < N; i++)
		if(chessboard[i][c] == 1)
			return false;

	// check for another queen in the row
	for(j = 0; j < N; j++)
		if(chessboard[r][j] == 1)
			return false;

	// check for another queen in the diagonals (need to check only upper-left and upper-right diagonals, as the lower side is not filled yet)
	for(i = r, j = c; i >= 0 && j >= 0; i--, j--)
		if(chessboard[i][j] == 1)
			return false;

	for(i = r, j = c; i >= 0 && j < N; i--, j++)
		if(chessboard[i][j] == 1)
			return false;

	return true;
}

// try placing a queen at a suitable position in the given row (r), and recursively do the same for the next row
// if a dead-end occurs (next row could not be built), then backtrack
bool tryPlacing(int **chessboard, int N, int r) {
	// base case: all queens placed
	if(r >= N)
		return true;

	// try all cells (cols) in this row one by one and see if they don't lead to a dead-end in the deeper rows
	// if a further call returns false, backtrack/undo the recent operation and try again with next cell
	// if a dead-end is found in this row (all cells in this row are exhausted), return false
	for(int c = 0; c < N; c++) {

		if(isSafe(chessboard, N, r, c)) {

			chessboard[r][c] = 1; // place queen at (r, c)

			if(tryPlacing(chessboard, N, r + 1) == true) // try next row(s) recursively with the current setting
				return true;
			else
				chessboard[r][c] = 0; // backtrack and try the next cell when a dead-end is found (next rows did not work well with this setting)
		}
	}

	return false;
}

void placeNQueens(int N) {
	// create a chessboard of size NxN initialized with 0s
	int **chessboard = new int *[N];
	for(int i = 0; i < N; i++)
		chessboard[i] = (int *) calloc(N, sizeof(int));

	// build the solution, starting with row 0
	tryPlacing(chessboard, N, 0);

	// display the solution on the chessboard
	cout << "\nSolution (1s represent the queens on the chessboard): \n";
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++)
			cout << chessboard[i][j] << " ";
		cout << "\n";
	}
}

int main() {
	int N;
	cout << "\nEnter number N for placing N queens on an NxN chess board: ";
	cin >> N;

	placeNQueens(N);
	cout << "\n";
	return 0;
}
