#include <iostream>
#include <vector>
using namespace std;

/*
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

int unique_path2(vector<vector<int>>& obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
    dp[0][0] = 1;

    // filling first row
    for(int i=1; i<m; i++)
    {
        if(obstacleGrid[i][0] == 0)
        {
            dp[i][0] = dp[i-1][0];
        }
    }

    // filling col
    for(int i=1; i<n; i++)
    {
        if(obstacleGrid[0][i] == 0)
        {
            dp[0][i] = dp[0][i-1];
        }
    }

    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(obstacleGrid[i][j] == 0)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    vector<vector<int>> grid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << unique_path2(grid) << endl;
    return 0;
}