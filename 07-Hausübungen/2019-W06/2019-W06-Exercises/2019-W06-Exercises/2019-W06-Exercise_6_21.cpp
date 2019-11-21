/* 2019-W06-Exercise_6_21.cpp :

Exercise 6.21 
  Schreiben Sie ein Programm, das Sudokus lösen kann. 

Dániel Szöke (11913915)
18.11.2019

*/

#include <iostream>     // cout
#include <vector>       // vector
//#include <cstdlib>      // qsort
//#include <string>       // string
//#include <algorithm>    // sort
//#include <cmath>        // sqrt
//#include <exception>    
//#include <stdexcept>    // runtime_error

using namespace std;

// UNASSIGNED: empty cells  
constexpr auto UNASSIGNED = 0;
// N :size of Sudoku grid.  
constexpr auto N = 9;

// find an entry that is still unassigned. If found, the row, col will be set the location
bool FindFreeLocation(vector<vector<int>> grid, int& row, int& col);

// indicates whether be legal to assign num to the given row, col location
bool isAssign(vector<vector<int>> grid, int row, int col, int num);

// "Naiv" Solver for SUDOKU by recursion
bool SolveSudoku(vector<vector<int>>& grid)
{
	int row, col;

	// If there is no unassigned location,  we are done 
	if (!FindFreeLocation(grid, row, col)) return true; 

		// consider digits 1 to 9 
	for (int num = 1; num <= 9; num++)
	{
		// if looks promising 
		if (isAssign(grid, row, col, num))
		{
			// make tentative assignment 
			grid.at(row).at(col) = num;

			// return, if success 
			if (SolveSudoku(grid)) return true;

			// failure, try again 
			grid.at(row).at(col) = UNASSIGNED;
		}
	}
	return false; // this triggers backtracking 
}

// find an entry that is still unassigned. If found, the row, col will be set the location
bool FindFreeLocation(vector<vector<int>> grid,	int& row, int& col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (grid[row][col] == UNASSIGNED)
				return true;
	return false;
}

// indicates whether an assigned entry in the specified row matches the given number
bool UsedInRow(vector<vector<int>> grid, int row, int num)
{
	for (int col = 0; col < N; col++)
		if (grid.at(row).at(col) == num)
			return true;
	return false;
}

// indicates whether an assigned entry in the specified column matches the given number
bool UsedInCol(vector<vector<int>> grid, int col, int num)
{
	for (int row = 0; row < N; row++)
		if (grid.at(row).at(col) == num)
			return true;
	return false;
}

//indicates whether assigned entry within the specified 3x3 box matches the given number
bool UsedInBox(vector<vector<int>> grid, int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid.at(row + boxStartRow).at(col + boxStartCol) == num)
				return true;
	return false;
}

// indicates whether be legal to assign num to the given row, col location
bool isAssign(vector<vector<int>> grid, int row,	int col, int num)
{
	return	!UsedInRow(grid, row, num) &&
			!UsedInCol(grid, col, num) &&
			!UsedInBox(grid, row - row % 3,	col - col % 3, num) &&	
			grid.at(row).at(col) == UNASSIGNED;
}

//Utility function to print grid
void printGridStandard(vector<vector<int>> grid)
{
	for (auto const& rowOfGrid : grid)
	{
		for (auto const& item : rowOfGrid) 
			if (item==0) std::cout << "_ ";
			else
				std::cout << item << " ";
		std::cout << endl;
	}
}

// print Colored Sudoku
// ANSI escape code: https://en.wikipedia.org/wiki/ANSI_escape_code#graphics
void printGridColored(vector<vector<int>> gridS, vector<vector<int>> gridR)
{
	for ( unsigned i=0; i< gridR.size(); i++)
	{
		for (unsigned j = 0; j < gridR.at(i).size(); j++)
			if (gridS.at(i).at(j)==0)
				std::cout << "\033[1;34m" << gridR.at(i).at(j) << "\033[0m ";
			else
				std::cout << gridR.at(i).at(j) << " ";
			
		std::cout << endl;
	}
}

int main()
{
	// 0 means unassigned cells 
	vector<vector<int>> starterGrid = { 
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 3, 1},
		{0, 0, 3, 0, 1, 0, 0, 8, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0},
		{1, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0} };

	std::cout << " ----- Original Sudoku -----\n";
	printGridStandard(starterGrid);
	std::cout << endl;

	std::cout << " ----- Solved Sudoku -----\n";
	vector<vector<int>> solvedGrid = {
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 3, 1},
		{0, 0, 3, 0, 1, 0, 0, 8, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0},
		{1, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0} };

	if (SolveSudoku(solvedGrid))	printGridColored(starterGrid, solvedGrid);
	else
		std::cout << "No solution exists";

	return 0;
}

