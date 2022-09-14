#include<iostream>
#include<vector>
using namespace std;

// 1. BRUTE FORCE
class Brute_force_solution
{
    public:
    int climbStairs(int n)
    {
        return helper(0,n);
    }
    // i-> curr step
    // n-> total step
    int helper(int i, int n)
    {
        // base case
        if(i > n) return 0;
        if(i == n) return 1;
        return helper(i+1, n) + helper(i+2, n); // two ways you can climb the stairs 
    }
};

// TC: O(2^n) -> size of recurrsion
// SC: O(n)  -> depth of the recurrsion

//******************************************************************************************************

// 2. BOTTOM UP - TABULTION APPROACH -> iterative
class bottom_up_solution
{
    public:
    int climbStairs(int n)
    {
        // create a vector 
        vector<int> dp(n+1);
        // base case
        dp[0] = 1;
        dp[1] = 1;
        // iterate from 2
        for(int i=2; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
    
}
// TC: O(n) -> single loop upto n
// SC: O(n) -> dp array size

//*******************************************************************************************************

// 3. MEMOIZATION -> recurrsion
class Memozation_Solution
{
    public:
    int climbStairs(int n)
    {
        vector<int> memo(n+1);
        return helper(0,n,memo);
    }

    int helper(int i, int n, vector<int>memo)
    {
        // base cases
        if(i > n) return 0;
        if(i == n) return 1;
        if(memo[i] > 0) return memo[i];
        memo[i] = helper(i+1,n,memo) + helper(i+2, n, memo);
        return memo[i];
    }
}

// TC: O(N) -> single loop upto n
// SC: O(N) -> dp array size

//*****************************************************************************************************

// 4. FIBONACCI NUMBER

class Solution
{
    public:
    int climbStairs(int n)
    {
        // base case
        if(n == 1) return 1;
        int first = 1;
        int second = 2;
        for(int i=3; i<=n; i++)
        {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
}

// TC: O(N)
// SC: O(1)

int main()
{
    return 0;
}