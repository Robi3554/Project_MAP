#include <iostream>
#define N 8
using namespace std;

void printSol(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (board[i][j])
				cout << "Q ";
			else cout << ". ";
		printf("\n");
	}
}

bool isSafe(int board[N][N], int row, int col)
{
	int i, j;

	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;


	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;


	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

bool solveProb(int board[N][N], int col)
{

	if (col >= N)
		return true;


	for (int i = 0; i < N; i++) {

		if (isSafe(board, i, col)) {

			board[i][col] = 1;


			if (solveProb(board, col + 1))
				return true;

			board[i][col] = 0; 
		}
	}
	return false;
}


bool solve()
{
	int board[N][N] = { { 0, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 0 } };

	if (solveProb(board, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}

	printSol(board);
	return true;
}


int main()
{
	cout << "\t\t\t\t\t\tWelcome to the 8 Queens Problem!\n\n";
	
	solve();
	return 0;
}
