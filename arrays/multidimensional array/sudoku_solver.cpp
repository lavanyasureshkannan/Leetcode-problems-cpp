#include<iostream>
using namespace std;

/*
    SUDOKU SOLVER
    1. what can be done?
        traverse through the 2d grid and check row, col and the small 3x3 box and see if the box is valid ('.' , char inside the box is unique)
        then you can do backtracking and fill the boxes 
    
    ALGO
    1. Bool helper function with backtracking 
    2. isvalid function

*/

class Solution
{
public:

    bool helperFunction(vector<vector<char>>& board) // main function
    {
        // iterate through the 2d grid
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                // check if the curr cell value is '.'
                if (board[i][j] == '.')
                {       
                    // go ahead and try all the possible characters from '1' to '9' 
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(board, i, j, c))
                        {
                            // fill in the values
                            board[i][j] = c;
                            // if true we return as we only want atleast one correct way
                            if (helperFunction(board) == true) return true;
                            else
                            {
                                board[i][j] = '.'; // backtracking
                            }
                        }
                    }
                return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c)
    {    
        // iterate through the 2d grid and check for the validity
        for(int i = 0; i < 9; i++)
        {    
            // check the entire row
            if(board[row][i] == c) return false;
            // col check
            if(board[i][col] == c) return false; 
            // small 3x3 box
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board)
    {    
        helperFunction(board);
    }
};