#include <iostream>
#include <vector>
using namespace std;

/*
Can you pick numbers that sums to the target ?
nums = [3, 34, 4, 12, 5, 2], target = 9
*/

bool susbet_sum(vector<int>& nums , int target)
{
    vector<bool> dp(target+1, false);
    dp[0] = true;
    for(int i=0; i<nums.size(); i++)
    {
        for(int t=target; t>=nums[i]; t--)
        {
            dp[t] = dp[t] || dp[t-nums[i]];
        }
    }
    return dp[target];
}

int main()
{
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int target = 9;
    cout << susbet_sum(nums, target);
    return 0;
}