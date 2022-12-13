# Project_MAP
This is a project for Advanced Programming Methods

The eight queens problem is the problem of placing eight queens on an 8×8 chessboard such that none of them attack one another (no two are in the same row, column, or diagonal). 
More generally, the 8 queens problem places 8 queens on an 8x8 chessboard.

There are different solutions to this problem. The one I used here is the solution using backtracking.
The way in which we accomplished this is as follows:
-Firstly, we make the board and a space where we collect
-After we start from the topmost row
-We then make a recursive function takes the state of the board and the current row number as its parameter.
-After tha cis done we put a queen in a safe place and use the state of the board to advance to next recursive
call and add 1 to the current row. Afterward we revert the state of the board after making the call.
Safe function checks the current column, left top diagonal and right top diagonal.
-We keep calling the function till the row is out of bounds.
-If current row reaches the number of rows in the board then the board is filled.
-Store the state and return.

After I added simple functions to make the output look a little nicer.
I did that with the sleep_for() function.

I also added a function to print out 1 of 11 random quotes from famous people.
I used a variable in witch i stored a random number then i used % 10 to get a number between 0 - 10.
