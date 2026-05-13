#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/

void print(vector<int>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        cout << nums[i] << " " ;
    }
    cout << endl;
}

int house_robber(vector<int>& nums)
{
    int n = nums.size();
    vector<int> dp(n,0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i=2; i<=n; i++)
    {
        dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
    }
    print(dp);
    return dp[n];
}



int main()
{
    vector<int> nums = {2,7,9,3,1};
    cout << house_robber(nums) << endl;
    return 0;
}
