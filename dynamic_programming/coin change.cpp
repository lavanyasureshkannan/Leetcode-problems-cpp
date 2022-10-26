#include<iostream>
#include<vector>
using namespace std;

// BOTTOM UP APPROACH

/*
    [1,3,4,5] amount = 7
    dp[0] = 0; => for zero amount how many coins 
    dp[1] = 1;
    dp[2] = 1 + dp[1] = 2;
    dp[3] = 1;
    dp[4] = 1;
    dp[5] = 1; 
    dp[6] = 2;
    dp[7] = 1+ dp[6] => 3 or 1 + dp[4] => 2 => min(3,2) = 2

*/

class Solution 
{
    public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int maxi = amount + 1;
        vector<int>dp(maxi, maxi);
        dp[0]=0;
        for(int i=1; i<= amount; i++) // from one to all the to the amount
        {
            for(int j=0; j < coins.size(); j++)
            {
                if(coins[j]<=i)
                {
                    dp[i] = min(dp[i], dp[i-coins[j]]+1); // // coin = 4, aount = 7
                                                            // dp[7] = 1 + dp[amount - 4] = 1 + dp[3] 
                }
            }
        }
        if(dp[amount] > amount)
        {
            return -1;
        }

        return dp[amount];
    }
};

// TC: O(S * n) iterations
// SC; O(S) extra space for memoization


// coin = 4, aount = 7
// dp[7] = 1 + dp[amount - 4] = 1 + dp[3] 