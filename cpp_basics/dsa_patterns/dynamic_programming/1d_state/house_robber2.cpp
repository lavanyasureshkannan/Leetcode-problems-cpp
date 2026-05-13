#include <iostream>
#include <vector>
using namespace std;

/*
Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/

int helper(vector<int>& nums, int start, int end)
{
    int n = end - start + 1;
    if (n==0) return 0;
    if (n==1) return nums[start];
    vector<int> dp(n,0);
    dp[0] = nums[start];
    dp[1] = max(nums[start], nums[start+1]);
    for(int i=2; i<n; i++)
    {
        dp[i] = max(nums[start + i] + dp[i-2], dp[i-1]);
    }  
    return dp[n-1];
}


int house_robber2(vector<int>& nums)
{
    int n = nums.size();
    if(n == 0) return 0;
    if(n == 1) return nums[0];
    int even = helper(nums,0,n-2);
    int odd = helper(nums,0,n-1);
    return max(even,odd);
}


int main()
{
    vector<int> nums = {1,2,3,1};
    cout << house_robber2(nums) << endl;
    return 0;
}