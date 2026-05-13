#include <iostream>
#include <vector>
using namespace std;


/*
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
*/

void print(vector<vector<string>>& result)
{
    for(int i=0; i<result.size(); i++)
    {
        for(int j=0; j<result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}


vector<vector<string>> result;
vector<bool> col, diagonal, anti_diag;
vector<string> board;

void backtrack(int row, int n)
{
    // base case
    if(row == n)
    {
        result.push_back(board);
    } 
    // try every possibility
    for(int c=0; c<n; c++)
    {
        // check if the queens are placed anywhere
        if(col[c] || diagonal[row - c + n + 1] || anti_diag[row+c]) continue;;
        // put the queen
        board[row][c] = 'Q';
        col[c] = true;
        diagonal[row - c + n + 1] = true;
        anti_diag[row+c] = true;
        // recursive call
        backtrack(row+1, n);
        // undo
        board[row][c] = '.';
        col[c] = false;
        diagonal[row - c + n + 1] = false;
        anti_diag[row+c] = false;

    }

}

vector<vector<string>> n_Queens(int n)
{
    board.assign(n, string(n,'.'));
    col.assign(n, false);
    diagonal.assign(2 * n-1, false);
    anti_diag.assign(2 * n-1, false);
    backtrack(0, n);
    print(result);
    return result;
}

int main()
{
    int n = 4;
    n_Queens(n);
    return 0;
}