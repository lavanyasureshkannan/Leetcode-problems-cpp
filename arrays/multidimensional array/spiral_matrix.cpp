#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> result;
        // base case  matrix = 0
        if(matrix.size() == 0) return result; 
        // set the boundaries for a 2d array
        int rowBegin = 0;
        int rowEnd = matrix.size() - 1; 
        int colBegin = 0;
        int colEnd = matrix[0].size() - 1;
        // traverse through the rows and column and add that on your array
        while(rowBegin <= rowEnd && colBegin <= colEnd)
        {
            // first traverse the first row and add the elements by accesing the column values
            for(int i=colBegin; i <= colEnd; i++)
            {
                result.push_back(matrix[rowBegin][i]);
            }
            // done with the row just increment the row
            rowBegin++;
            // traverse from beginning row boundary to end row boundary
            for(int i = rowBegin; i <= rowEnd; i++)
            {
                result.push_back(matrix[i][colEnd]); // changing the row position
            } 
            colEnd --;
            // to make sure that the boundaries are moving inwards
            if(rowBegin <= rowEnd)
            {
                // we are going from ending column to begining column
                for(int i=colEnd; i>=colBegin; i--)
                {
                    result.push_back(matrix[rowEnd][i]);
                }
            }
            rowEnd --;

            if(colBegin <= colEnd)
            {
                for(int i=rowEnd; i>=rowBegin; i--)
                {
                    result.push_back(matrix[i][colBegin]);
                }
            }
            colBegin ++;
    }
    return result;

    }
};

// TC: O(M . N) M-> Number of rows, N-> number of columns
// SC: O(1) -> no additional space
