/*
    1. It will allow reuse
    2. Loop direction -> forward
    3. go with the max val


int unboundedKnapsack(int W, vector<int>& wt, vector<int>& val)
{
    vector<int> dp(W + 1, 0);
    for (int w = 1; w <= W; w++)
    {
        for (int i = 0; i < wt.size(); i++)
        {
            if (wt[i] <= w)
            {
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }
    }
    return dp[W];
}


    For counting/combinations => coin loop outside
    For permutations => amount loop outside

*/