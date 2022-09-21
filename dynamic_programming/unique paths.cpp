#include<iostream>
using namespace std;


int UniquePaths(int m, int n)
{
    // construct a grid
    vector<vector<int>> dp(m,n);
    // iterate through the grid
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1]; // update the dp with right and down values
            }
        }
    }
    return dp[m-1][n-1]; // return the last val
}

// TC: O(NxM) -> n rows and m cols
// SC: O(NxM)

int main()
{
    return 0;
}