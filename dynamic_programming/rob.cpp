#include<iostream>
#include<vector>
using namespace std;


// BOTTOM UP -> tabulation -> iterative
class Solution
{
    public:
    int rob(vector<int>& nums)
    {
        // base case
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<n; i++)
        {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[n-1];

    }

};
// TC: O(N)
// SC: O(N) -> vector array

// OPTIMIZED SPACE COMPLEXITY
class Solution
{
    public:
    int rob(vector<int>& nums)
    {
        // base case
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        int a = nums[0];
        int b = max(nums[0],nums[1]);
        for(int i=2; i<n; i++)
        {
            int temp = b;
            b = max(b, a + nums[i]);
            a = temp;
        }
        return b;
    }
};
// TC: O(N)
// SC: O(1)

int main()
{
    return 0;
}