#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

*/


class recurrsive_sol
{
    public:
    int total = 0;
    void helper(vector<int>& nums, int target, int curr_index, int curr_val)
    {
        if(curr_index == nums.size())
        {
            if(curr_val == target)
            {
                total ++;
            } 
        }
        else
        {
            helper(nums, target, curr_index+1, curr_val + nums[curr_index]);
            helper(nums, target, curr_index+1, curr_val - nums[curr_index]);
        }
    }


    int target_sum(vector<int>& nums, int target)
    {
        helper(nums, target, 0, 0);
        return total;
    }
};


class dp_solution
{
    public:
    /*
        sum(p) - sum(n) = target
        sum(p) + sum(p) = total_sum
        solving both 
        ----------------------------
        2 * sum(p) = target + total_sum
        sum(p) = target + target_sum / 2
    */

    int target_sum_dp(vector<int>& nums, int target)
    {
        int total_sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            total_sum += nums[i];
        }
        if(abs(target) > total_sum) return 0;
        if((target + total_sum) % 2 != 0) return 0;
        int subset_sum = (target + total_sum) / 2;

        vector<int> dp(subset_sum+1, 0);
        dp[0] = 1;

        for(int i=0; i<nums.size(); i++)
        {
            for(int t=subset_sum; t>=nums[i]; t--)
            {
                dp[t] += dp[t-nums[i]];
            }
        }
        return dp[subset_sum];
    }
};

int main()
{
    vector<int>nums = {1,1,1,1,1};
    int target = 3;
    recurrsive_sol r_sol;
    cout << r_sol.target_sum(nums, target) << endl;
    dp_solution dp_sol;
    cout << dp_sol.target_sum_dp(nums,target) << endl;
    return 0;
}