#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

*/

bool Can_partition(vector<int>& nums)
{
    int sum = 0;
    for(int i=0; i<nums.size(); i++)
    {
        sum += nums[i];
    }
    if(sum%2 != 0) return false;
    
    int target = sum/2;
    vector<bool> dp(target+1, false);
    dp[0] = true;
    for(int i=0; i<nums.size(); i++)
    {
        for(int t=target; t>= nums[i]; t--)
        {
            dp[t] = dp[t] || dp[t- nums[i]];
        }
    }
    return dp[target];
}

int main()
{
    vector<int> nums = {1,5,11,5};
    cout << Can_partition(nums) << endl;
    return 0;
}