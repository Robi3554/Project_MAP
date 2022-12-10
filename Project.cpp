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

void randQuote() {
	int nr;

	srand(time(0));
	nr = rand() % 10;
	switch (nr)
	{
	case 0:
		cout << "I would rather die in a swamp in Greater Romania than in a paradise in a small Romania.\"- Ion Antonescu";
		break;
	case 1:
		cout << "It's good to trust others, but, not to do so is much better.\"- Benito Mussolini";
		break;
	case 2:
		cout << "If you tell a big enough lie and tell it frequently enough, it will be believed.\"- Adolf Hitler";
		break;
	case 3:
		cout << "A good speech should be like a woman's skirt: long enough to cover the subject and short enough to create interest.\"- Winston Churchill";
		break;
	case 4:
		cout << "Whoever said the pen is mightier than the sword obviously never encountered automatic weapons.\"- Douglas MacArthur";
		break;
	case 5:
		cout << "The Pope! How many divisions has he got?\"- Joseph Stalin";
		break;
	case 6:
		cout << "Politics is war without bloodshed, while war is politics with bloodshed.\"- Mao Zedong";
		break;
	case 7:
		cout << "It is us today. It will be you tomorrow.\"- Haile Selassie I, in 1936";
		break;
	case 8:
		cout << "To be defeated and not submit, is victory. To be victorious and rest on one's laurels, is defeat.\"- Józef Piłsudski";
		break;
	case 9:
		cout << "Antonescu and the others considered me a child. When I took the state from under their noses they were so shocked they didn't know what to do.\"- King Michael I of Romania";
		break;
	case 10:
		cout << "I can run wild for six to twelve months of a war with the United States and the United Kingdom. After that, I have no expectation of success.\"- Isoroku Yamamoto";
		break;
	}

}


int main()
{
	using namespace std::this_thread;
	using namespace std::chrono;

	cout <<"\t\t\t\t\tWelcome to the 8 Queens Problem!\n\n";
	sleep_for(seconds(2));

	cout << "Here is your solution:\n";
	solve();

	sleep_for(seconds(1));
	cout << "\nHere is a random quote:\n";
	sleep_for(seconds(2));
	randQuote();
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~\n";

	return 0;
}
