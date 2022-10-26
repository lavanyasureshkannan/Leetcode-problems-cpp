class Solution 
{
    public 
    int change(int amount, vector<int>& coins) 
    {
        vector<int> dp(amount+1);
        dp[0] = 1;
        for (int coin : coins) 
        {
            for (int x = coin; x < amount + 1; ++x) 
            {
                dp[x] += dp[x - coin];
            }
        }
    return dp[amount];
    }
}

//TC: O(N)
// SC: O(amount)

/*
Now the strategy is here:

Add coins one-by-one, starting from base case "no coins".

For each added coin, compute recursively the number of combinations for each amount of money from 0 to amount.

Algorithm

Initiate number of combinations array with the base case "no coins": dp[0] = 1, and all the rest = 0.

Loop over all coins:

For each coin, loop over all amounts from 0 to amount:

For each amount x, compute the number of combinations: dp[x] += dp[x - coin].
Return dp[amount]
*/