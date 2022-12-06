#include<iostream>
#include<vector>
using namespace std;

// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

class Solution 
{
    public:
    void setZeroes(vector<vector<int>>& matrix) 
    {     
        int rowsize = matrix.size(); 
        int columnsize = matrix[0].size(); 
        vector<int>row(rowsize,1);
        vector<int>col(columnsize,1); 
        for(int i=0; i < matrix.size(); i++)
        {
            for(int j=0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    row[i] = 0; 
                    col[j] = 0;
                }
            }
        } 
        for(int i=0; i < matrix.size(); i++)
        {
            for(int j=0; j < matrix[0].size(); j++)
            {
                if(row[i] == 0 or col[j]==0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};

