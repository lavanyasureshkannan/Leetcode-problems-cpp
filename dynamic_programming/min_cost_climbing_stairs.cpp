#include<iostream>
#include<vector>
using namespace std;


// BRUTE FORCE KINDA METHOD
class Solution
{
    public:
    // picking up the minimum and putting till you reach the end
    int minCostClimbingStairs(vector<int>& costs)
    {
        int n = costs.size();
        for(int i=2; i<n; i++)
        {
            costs[i] += min(costs[i-1], costs[i-2]); 
        }
        return min(costs[n-1], costs[n-2]);
    }
};

// TC: O(N)
// SC: O(N)


// DP SPACE OPTIMIZATION METHOD
class space_optimization_dp
{
    public:
    int minCostClimbingStairs(vector<int>& costs)
    {
        int n= costs.size();
        int step1 = costs[0];
        int step2 = costs[1];
        for(int i=2; i<n; i++)
        {
            int temp = costs[i] + min(step1,step2);
            step1 = step2;
            step2 = temp;
        }
        return min(step1,step2);
    }
};

// TC: O(N)
// SC: O(1)



// BOTTOM UP APPROACH
class bottom_up_solution
{
    public: 
    int minCostClimbingStairs(vector<int>& costs)
    {
        int n = costs.size();
        vector<int> dp(n+1);
        // base case
        dp[0] = costs[0];
        dp[1] = costs[1];
        // iterate 
        for(int i=2; i<n; i++)
        {
            dp[i] = costs[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
};

// TC: O(N)
// SC: O(N) 

// using memoization
class memoization_Solution
{
    public:
    int minCostClimbingStairs(vector<int>& costs)
    {
        int n = costs.size();
        vector<int> memo(n+1,-1);
        return helper(memo, n, costs);
    }

    int helper(vector<int>& memo, int n, vector<int>& costs)
    {
        if(n == 0 || n == 1) return 0;
        if(memo[n] != -1) return  memo[n];
        int step1 = costs[n-1] + helper(memo, n-1, costs);  
        int step2 = costs[n-2] + helper(memo, n-2, costs);
        return memo[n] = min(step1, step2);

    }
};

// TC: O(N)
// SC: O(N)




int main()
{
    return 0;
}