#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    for(int i=0; i< matrix.size(); i++)
    {
        for(int j=0;j<matrix[0].size(); j++)
        {
            if(matrix[i][j] == target) return true;
        }
    }
    return false;

}

// TC: O(mxn) -> iterating thorugh the entire matrix
// SC: O(1)


// Search Space Reduction
// initialise rows and cols
// start from the bottome left since the values are in sorted order
// if the value is greater than target increase row
// else increase col

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int row = matrix.size() - 1;
    int col = 0;
    while(row >= 0 && col < matrix[0].size())
    {
        if(matrix[row][col] > target) row--;
        else if(matrix[row][col] < target) col++;
        else return true; // if you found
    }
    return false;

}

// TC: O(mxn)
// SC: O(1)

int main()
{
    return 0;
}