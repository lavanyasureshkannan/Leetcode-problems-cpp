#include <iostream>
#include <vector>
using namespace std;

/*
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], 
target = 5
Output: true
*/

bool search_2d_mat_bf(vector<vector<int>>& matrix, int target)
{
    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix[i].size(); j++)
        {
            if(matrix[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}


// optimised 
bool search_2d_mat_optmised(vector<vector<int>>& matrix, int target)
{
    int row = matrix.size() - 1;
    int col = 0;
    while(row >= 0 && col < matrix[0].size())
    {
        if(matrix[row][col] > target) row --;
        else if(matrix[row][col] < target) col ++;
        else return true; 
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix_2d = {{1,4,7,11,15},
                                    {2,5,8,12,19},
                                    {3,6,9,16,22},
                                    {10,13,14,17,24},
                                    {18,21,23,26,30}};
    int target = 5; 
    cout << search_2d_mat_optmised(matrix_2d, target) << endl;
    return 0;
}