#include <iostream>
#include <vector>
using namespace std;

/*
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
*/

bool dfs(int i, int j, vector<vector<char>>& board, string word, int n)
{
    if(n==word.size()) return true;
    if(i<0 || j<0 || i>=board.size() || j>= board[0].size()|| board[i][j] == '*') return false;
    board[i][j] = '*';
    bool check_status = dfs(i+1,j,board,word,n+1) ||
                        dfs(i-1,j,board,word,n+1) ||
                        dfs(i,j+1,board,word,n+1) ||
                        dfs(i,j-1,board,word,n+1);
    board[i][j] = word[n];
    return check_status;
}

bool word_search(vector<vector<char>>& board, string word)
{
    
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[0].size(); j++)
        {
            if(board[i][j] == word[0])
            {
                if(dfs(i,j,board,word,0))
                {
                    return true;
                }
            }
        }
    }
    return false;
}


int main()
{
    //{A","B","C","E"},["S","F","C","S"],["A","D","E","E"]
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout << word_search(board, word) << endl;
    return 0;
}