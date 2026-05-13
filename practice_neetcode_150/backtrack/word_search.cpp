#include <iostream>
#include <vector>
using namespace std;

/*
board = [
  ["A","B","C","D"],
  ["S","A","A","T"],
  ["A","C","A","E"]
],
word = "CAT"
Output: true
*/

bool dfs(int i, int j, vector<vector<char>>& board, string word, int n)
{
    if(n == word.size()) return true;
    if(i<0 || j<0 || i>board.size() || j>board[0].size() || board[i][j] == '*') return false;
    board[i][j] = '*';
    bool exist = dfs(i+1, j, board, word, n+1) ||
                 dfs(i-1, j, board, word, n+1) ||
                 dfs(i, j+1, board, word, n+1) ||
                 dfs(i, j-1, board, word, n+1) ;
    return exist;
}


bool word_Search(vector<vector<char>>& board, string word)
{
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].size(); j++)
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
    vector<vector<char>>board = {{'A','B','C','D'},
                                 {'S','A','A','T'},
                                 {'A','C','A','E'}};
    string word = "CAT";

    cout << word_Search(board, word);
    return 0;
}