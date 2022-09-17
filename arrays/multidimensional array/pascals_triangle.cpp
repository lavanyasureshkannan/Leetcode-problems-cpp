#include<iostream>
#include<vector>
using namespace std;


// DP APPROACH
// Why its a DP? because of optimal substructure and overlapping subproblems

class Solution 
{
    public:
    vector<vector<int>> generate(int numRows) 
    {
        // DECLARE A DP
        vector<vector<int>> dp(numRows);
        dp[0].push_back(1);
        
        for(int i=1; i < numRows; i++)
        {
            dp[i].push_back(1);
            for(int j=0; j+1 < i; j++)
            {
                //               prev two elements
                dp[i].push_back(dp[i-1][j] + dp[i-1][j+1]);
            }
            dp[i].push_back(1);    
        }
        return dp;    
    }
};

// TC:O(N^2)
// SC: O(1)


