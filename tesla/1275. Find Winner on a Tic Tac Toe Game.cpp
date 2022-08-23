#include<iostream>
#include<vector>
using namespace std;

// create a 3x3 grid
// check for even times -> player A
// check for odd times  -> player B
// iterate and check for row, col, diag1, and diag2
// if all 9 boxes are filled then return draw or pending


string tictactoe(vector<vector<int>>& moves) 
{
	 // csontruct a grid
	char grid[3][3] = {};
    // iterate over the 2d vector and find the even idx and make it player A's count and odd for player B's count
	for(int i=0; i<moves.size(); i++)
	{
        // specify the row and col
		int row = moves[i][0];
		int col = moves[i][1];
        // check for the even places
		if(i % 2 == 0)
        {
            grid[row][col] = 'X'; // Player A
        }
		else
        {
            grid[row][col] = 'O'; // PLayer B
        }

	}

	// check for the winner in both row and col
	for(int i=0; i<3; i++)
	{
        // row
		if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])  
		{
            // if the condition satisfies then mark the grids for player 1 and player 2
			if(grid[i][0] == 'X') return "A";
			if(grid[i][0] == 'O') return "B";
		}
		if(grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])   
		{
			if(grid[0][i] == 'X') return "A";
			if(grid[0][i] == 'O') return "B";
		}
	}

    // diagnol left -> right

	if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])  
	{
		if(grid[1][1] == 'X') return "A";
		if(grid[1][1] == 'O') return "B";
	}

    // diagnol right -> left
	if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])   
	{
		if(grid[1][1] == 'X') return "A";
		if(grid[1][1] == 'O') return "B";
	}
    // draw or pending
	if (moves.size() == 9) 
    {
        return "Draw"; 
    }
    else
    {
        return "Pending";
    }
}

// TC: O(N) -> iterating through the vector
// SC: O(N) -> occupyiing a grid space

int main()
{
    return 0;

}
