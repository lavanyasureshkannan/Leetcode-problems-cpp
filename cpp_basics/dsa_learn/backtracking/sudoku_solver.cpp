#include <iostream>
#include <vector>
using namespace std;

/*
Input: board = [["5","3",".",".","7",".",".",".","."],
                ["6",".",".","1","9","5",".",".","."],
                [".","9","8",".",".",".",".","6","."],
                ["8",".",".",".","6",".",".",".","3"],
                ["4",".",".","8",".","3",".",".","1"],
                ["7",".",".",".","2",".",".",".","6"],
                [".","6",".",".",".",".","2","8","."],
                [".",".",".","4","1","9",".",".","5"],
                [".",".",".",".","8",".",".","7","9"]]

Output: [["5","3","4","6","7","8","9","1","2"],
        ["6","7","2","1","9","5","3","4","8"],
        ["1","9","8","3","4","2","5","6","7"],
        ["8","5","9","7","6","1","4","2","3"],
        ["4","2","6","8","5","3","7","9","1"],
        ["7","1","3","9","2","4","8","5","6"],
        ["9","6","1","5","3","7","2","8","4"],
        ["2","8","7","4","1","9","6","3","5"],
        ["3","4","5","2","8","6","1","7","9"]]
*/

bool isvalid(vector<vector<char>>& board, int r, int c, char ch)
{
    for(int i=0; i<9; i++) 
    {
        if(board[r][c] == ch) return false;
    }
    for(int j=0; j<9; j++)
    {
        if(board[r][c] == ch) return false;
    }

    int boxRow = (r/3) * 3;
    int boxCol = (c/3) * 3;
    for(int i=boxRow; i<boxRow+3; i++)
    {
        for(int j=boxCol; j<boxCol+3; j++)
        {
            if(board[i][j] == ch)
            {
                return false;
            }
        }
    }
    return true;
}

bool backtrack(vector<vector<char>>& board)
{
    for(int r=0; r<9; r++)
    {
        for(int c=0; c<9; c++)
        {
            if(board[r][c] == '.')
            {
                for(int ch='1'; ch<='9'; ch++)
                {
                    if(isvalid(board,r,c,ch))
                    {
                        // make choice
                        board[r][c] = ch;
                        // recursive call
                        if(backtrack(board)) return true;
                        // undo
                        board[r][c] = '.';
                    }
                }
                return false;    
            }
        }
    }
    return true;
}

void sudoku_solver(vector<vector<char>>& board)
{   
    backtrack(board);
}

int main()
{
    return 0;
}