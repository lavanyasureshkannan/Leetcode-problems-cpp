#include <iostream>
#include <vector>
using namespace std;

/*
matrix = [[1,2,4,8],
          [10,11,12,13],
          [14,20,30,40]], target = 10
*/

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int row = matrix.size() - 1;
    int col = 0;
    while(row >= 0 && col < matrix[0].size())
    {
        if(matrix[row][col] < target) col ++;
        else if(matrix[row][col] > target) row --;
        else return true;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1,2,4,8},
                                {10,11,12,13},
                                {14,20,30,40}};
    cout << searchMatrix(matrix, 10);
    return 0;

}