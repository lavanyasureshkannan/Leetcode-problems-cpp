#include <iostream>
#include <vector>
using namespace std;

int climbing_stairs(int n)
{
    vector<int> dp(n+1,0);
    if(n >= 1)
    {
        dp[0] = 1;
        dp[1] = 1;
    }
    for(int i=2; i<n; i++)
    {
        dp[n] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    return 0;
}