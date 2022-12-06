#include<iostream>
#include<vector>
using namespace std;

// board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
class Solution
{
    private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int n)
    {
        if(n == word.size()) return true;
        // booundary checking
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[n] || board[i][j] == '*') return false;
        board[i][j] = '*';
        bool check_status = dfs(board, word, i+1,j,n+1) ||
                            dfs(board, word, i,j+1,n+1) ||
                            dfs(board, word, i-1,j,n+1) ||
                            dfs(board, word, i,j-1,n+1);
        // change the character for the next search
        board[i][j] = word[n];
        return check_status; 
    }

    public:
    bool exists(vector<vector<char>>& board, string& word)
    {
    // base case
        if(word == " ") return false;
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j] == word[0])
                {
                    if(dfs(board, word, i, j, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

// TC: O(MxN)
// SC: O(1)

