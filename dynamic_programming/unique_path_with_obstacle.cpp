#include<iostream>
#include<vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    // base case
    if(obstacleGrid[row-1][col-1] == 1  || obstacleGrid[0][0] == 1) return 0;
    vector<vector<int>>dp(row,vector<int>(col,0));
    // check the row for the obstacle
    for(int i=0; i<row; i++)
    {
        if(obstacleGrid[i][0]==1)
        {
            break;
        }
        else
        {
            dp[i][0]=1;
        }
    }
    // check the col for the obstacle
    for(int i=0;i<col;i++)
    {
        if(obstacleGrid[0][i]==1)
        {
            break;
        }
        else
        {
            dp[0][i]=1;
        }
    }
    // iterate through the grid
    for(int i=1; i<row; i++)
    {
        for(int j=1; j<col; j++)
        {
            // if obstacle then counting it as zero
            if(obstacleGrid[i][j]==1)
            {
                dp[i][j]=0;
            }
            else
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    return dp[row-1][col-1];
}


// TC: O(NxM)
// SC: O(NxM)
int main()
{
    return 0;
}