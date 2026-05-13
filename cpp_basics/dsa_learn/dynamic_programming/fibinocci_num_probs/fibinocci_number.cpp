#include <iostream>
#include <vector>
using namespace std;

/*
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
*/

int fibinocci_number(int n)
{
    vector<int> dp(n+1,0);
    if(n == 1) return 1;
    if(n==0 || n < 0) return 0;
    dp[0] = 0;
    dp[1] = 1;
    int result = 0;
    for(int i=2; i<=n; i++)
    {
        dp[i] += dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n = 4;
    cout << fibinocci_number(n) << endl;
    return 0;
}