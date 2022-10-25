#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
class Solution
{
    public:
    int count = 0;
    int findTargetSumWays(vector<int>& nums, int target)
    {
        helper(nums, 0, 0, target);
        return count;
    }

    void helper(vector<int>& nums, int i, int sum, int target)
    {
        if(i == nums.size())
        {
            if(sum == target)
            {
                count++;
            }
        }
        else
        {
            helper(nums, i+1, sum + nums[i], target);
            helper(nums, i-1, sum + nums[i], target);
        }
    }
};

// TC: O(2^n)
// SC: O(n)
/*
let S1 be the first subarray and S2 be the second subarray
S1 + S2 = sum
S1 - S2 = target
=> 2*S1 = sum + target
=> S1 = (sum + target)/2
*/
// sum = sum of all the elements in the array
// target = the given target
class Solution 
{
    public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        // accyumulate will add all the values(from start, to end) within the given range
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int new_target = (sum + target)/2;
        //if sum is less than target or numerator of new_target is odd then there will be no ways hence we will return 0
        if(sum < target || (sum + target)%2 != 0 || new_target < 0)
            return 0;
        
        vector<int>dp(new_target+1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = new_target; j >= nums[i]; j--)
            {
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[new_target];
    }
};

// TC: O(t⋅n) // t refers to the sum of the numsnumsnums array and nnn refers to the length of the numsnumsnums array.
// SC: O(t) // dp arrays