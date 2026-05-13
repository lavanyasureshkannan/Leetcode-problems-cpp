#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/

bool partition_subset(vector<int>& nums)
{
    int sum = 0;
    for(int i=0; i<nums.size(); i++)
    {
        sum += nums[i];
    }
    if(sum % 2 != 0) return false;
    int target = sum/2;
    vector<bool> dp(target+1, false); // (F,F,F,F,F,F,F,F,F,F,F)
    dp[0] = true; // (T,F,F,F,F,F,F,F,F,F,F)
    for(int i=0; i<nums.size(); i++)
    {
        for(int t=target; t>=nums[i]; t--)
        {
            dp[t] = dp[t] || dp[t-nums[i]]; // dp[11] = dp[11] || dp[11-1] // you take the number or not
        }
    }
    return dp[target];
}


int main()
{
    vector<int> nums = {1,5,11,5};
    cout << partition_subset(nums) << endl;
    return 0;
}