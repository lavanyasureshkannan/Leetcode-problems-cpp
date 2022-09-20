#include<iostream>
#include<unordered_set>
using namespace std;

class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    { 
        //vector of sets; elements can be inserted by pushback 
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>>  cols(9);
        vector<unordered_set<int>>  boxes(9);
        
    
        for(int i =0; i< board.size(); i++)
        {
            for(int j =0; j< board.size(); j++)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                int curr_element = board[i][j];
                int idx = (i / 3) *3 + j/3;
                if(rows[i].count(curr_element) || cols[j].count(curr_element) || boxes[idx].count(curr_element))
                {
                    return false;  
                }
                else
                {
                    rows[i].insert(curr_element);
                    cols[j].insert(curr_element);
                    boxes[idx].insert(curr_element);
                }    
            }
        }
        return true;    
    }
};

// TC: O(N^2)
// SC: O(N^2)