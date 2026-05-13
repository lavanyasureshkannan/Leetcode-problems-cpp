#include <iostream>
#include <vector>
using namespace std;


/*
Input: cost = [10,15,20]
Output: 15
*/

int minClimbingstairs(vector<int>& costs)
{
    int n = costs.size();
    vector<int> dp(n,0);
    dp[0] = 0;
    dp[1] = 0;
    for(int i=2; i<=n; i++)
    {
        dp[i] = min(dp[i-1] + costs[i-1], dp[i-2] + costs[i-2]);
    }
    return dp[n];
}

int main()
{
    vector<int> costs = {10,15,20};
    cout << minClimbingstairs(costs) << endl;
    return 0;
}