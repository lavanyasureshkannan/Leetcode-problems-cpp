#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/

// int rob_bf(vector<int>& nums)
// {
//     int maxi = 0;
//     for(int i=0; i<nums.size()-1; i+2)
//     {
//         maxi = maxi + nums[i];
//     }
//     return maxi;
// }


int rob(vector<int>& nums)
{
    int n = nums.size();
    vector<int> dp(n,0);
    if(n == 0) return nums[0];
    if(n == 1) return nums[0];
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);
    for(int i=2; i<n; i++)
    {
        dp[i] =  max(dp[i-2] + nums[i] , dp[i-1]);
    }
    return dp[n-1];
}


int main()
{
    vector<int>nums = {1,2,3,1};
    cout << rob(nums) << endl;
    return 0;
}