#include <iostream>
#include <vector>
using namespace std;

int unique_paths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 1)); // only one way to go right and down
    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    cout << unique_paths(3,7) << endl;
    return 0;
}