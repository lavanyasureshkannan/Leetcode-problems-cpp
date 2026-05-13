#include <iostream>
#include <vector>
using namespace std;

/*
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

void print(vector<int>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        cout << nums[i] << " " ;
    }
    cout << endl;
}

int climbing_stairs(int n)
{
    vector<int> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    print(dp);
    return dp[n];
}

int main()
{
    cout << climbing_stairs(3) << endl;
    return 0;
}