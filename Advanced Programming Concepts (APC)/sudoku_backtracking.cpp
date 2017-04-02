/* Program to solve a given 9x9 Sudoku puzzle.
   Given a partially filled 9×9 grid, the goal is to assign digits from 1 to 9 to the empty cells 
   so that all the rows, all the columns, and all the nine 3x3 sub-grids contain exactly one instance of the digits from 1 to 9.
   
   Example:
   5  3  0  0  7  0  0  0  0
   6  0  0  1  9  5  0  0  0
   0  9  8  0  0  0  0  6  0
   8  0  0  0  6  0  0  0  3
   4  0  0  8  0  3  0  0  1
   7  0  0  0  2  0  0  0  6
   0  6  0  0  0  0  2  8  0
   0  0  0  4  1  9  0  0  5
   0  0  0  0  8  0  0  7  9
   
   Solution:
   5  3  4  6  7  8  9  1  2
   6  7  2  1  9  5  3  4  8
   1  9  8  3  4  2  5  6  7
   8  5  9  7  6  1  4  2  3
   4  2  6  8  5  3  7  9  1
   7  1  3  9  2  4  8  5  6
   9  6  1  5  3  7  2  8  4
   2  8  7  4  1  9  6  3  5
   3  4  5  2  8  6  1  7  9
   
   This problem can be solved by backtracking.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define NINE 9

// track the next empty position
bool findNextEmptyCell(int grid[][NINE], int *r, int *c) {
	for(*r = 0; *r < NINE; (*r)++)
		for(*c = 0; *c < NINE; (*c)++)
			if(grid[*r][*c] == 0)
				return true; // empty cell is found and (r, c) have reached the empty cell

	return false; // no empty cell found
}

// check if a digit (dig) can be placed at a given position (r, c) on the grid without violating the rules
bool isSafe(int grid[][NINE], int dig, int r, int c) {
	int i, j;

	// check for an occurrence of the same digit in the row or column
	for(i = 0, j = 0; i < NINE && j < NINE; i++, j++)
		if(grid[i][c] == dig || grid[r][j] == dig)
			return false;

	// check for an occurrence of the same digit in the 3x3 sub-grid
	int beg_r = r - (r % 3);
	int beg_c = c - (c % 3);
	for(int i = beg_r; i < beg_r + 3; i++)
		for(int j = beg_c; j < beg_c + 3; j++)
			if(grid[i][j] == dig)
				return false;

	return true;
}

// find an empty location, try to place a digit there and then recursively do the same for the next empty locations
// if a dead-end occurs (no digit can be placed), then return false and backtrack in the previous call
bool tryPlacing(int grid[][NINE]) {
	int r, c;

	// find the next empty cell (r and c will be set to its position)
	bool nextEmptyFound = findNextEmptyCell(grid, &r, &c);

	// if no empty cell is found, then all the cells have been filled satisfactorily
	if(!nextEmptyFound)
		return true;

	// try all the digits one by one and see if they don't lead to a dead-end in the next positions (next calls)
	// if a further call returns false, backtrack/undo the recent operation and try again with the next digit
	// if a dead-end is found at this position (any digit could not fit in), then return false
	for(int dig = 1; dig <= 9; dig++) {
		if(isSafe(grid, dig, r, c)) {
			grid[r][c] = dig; // place the digit at (r, c)

			if(tryPlacing(grid) == true) // try solving for the next empty position(s) recursively with the current setting
				return true;
			else
				grid[r][c] = 0; // backtrack and try the next digit if a dead-end is found (the solution could not be reached with this setting)
		}
	}

	// all the digits were exhausted and no result was found
	return false;
}

void solveSudoku(int grid[][NINE]) {
	// build the solution
	tryPlacing(grid);

	// display the solution
	cout << "\nSolution: \n";
	for(int i = 0; i < NINE; i++) {
		for(int j = 0; j < NINE; j++)
			printf("%-3d", grid[i][j]);
		cout << "\n";
	}
}

int main() {
	int grid[NINE][NINE];
	cout << "\nFill the 9x9 Sudoku grid. \nEnter numbers for filled cells and 0 for empty cells: \n";

	for(int i = 0; i < NINE; i++)
		for(int j = 0; j < NINE; j++)
			cin >> grid[i][j];

	cout << "\nPuzzle: \n";
	for(int i = 0; i < NINE; i++) {
		for(int j = 0; j < NINE; j++)
			printf("%-3d", grid[i][j]);
		cout << "\n";
	}

	solveSudoku(grid);
	cout << "\n";
	return 0;
}
