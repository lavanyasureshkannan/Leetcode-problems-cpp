#include <iostream>
#include <vector>
using namespace std;

/*
Input: cost = [1,2,3]
Output: 2
*/

int min_cost(vector<int>& cost)
{
    int n = cost.size();
    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = 0;
    for(int i=2; i<=n; i++)
    {
        dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
    }
    return dp[n];
}

int main()
{
    vector<int>cost = {1,2,3};
    cout << min_cost(cost) << endl;
    return 0;
}