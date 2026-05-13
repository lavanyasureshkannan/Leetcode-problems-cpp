#include <iostream>
#include <vector>
using namespace std;

/*
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
*/

void print(vector<vector<char>>& board)
{
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int i, int j, vector<vector<char>>& board)
{
    // 1. boundary check
    if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size()) return;
    // 2. visisted check
    if(board[i][j] != 'O') return;
    //// 3. mark as visited
    board[i][j] = '#';
    //// 4. recursive call
    dfs(i+1, j, board);
    dfs(i-1, j, board);
    dfs(i, j+1, board);
    dfs(i, j-1, board);
}


void surround_regions(vector<vector<char>>& board)
{
    int rows = board.size();
    int cols = board[0].size();
    
    // rows
    for(int i=0; i<rows; i++)
    {
        dfs(i, 0, board);
        dfs(i, cols-1, board);
    }

    // cols
    for(int j=0; j<cols; j++)
    {
        dfs(0, j, board);
        dfs(rows-1, j, board);
    }

    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].size(); j++)
        {
            if(board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
            else if(board[i][j] == '#')
            {
                board[i][j] = 'O';
            }
        }
    }
    print(board);
}

int main()
{
    vector<vector<char>> board = {{'X','X','X','X'},
                                  {'X','O','O','X'},
                                  {'X','X','O','X'},
                                  {'X','O','X','X'}};
    surround_regions(board);
    return 0;
}