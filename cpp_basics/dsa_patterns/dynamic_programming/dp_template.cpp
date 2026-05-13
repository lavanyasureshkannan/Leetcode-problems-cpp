#include <iostream>
#include <vector>
using namespace std;

/*
    T R U M P
    T => create a dp table
    R => result
    U => Unit case (base condition)
    M => Reach current state
    P => Populate (fill the table from the loop)
*/

/*
    vector<int> dp(n, 1); // T
    dp[0] = 0; // U
    for(int i=0; i<m; i++) // P
    {
        dp[i] = .... //M
    }
    return result; // R
*/

int fib(int n)
{
    vector<int> dp(n,0); // T
    dp[0] = 1;  // U
    dp[1] = 1;
    for(int i=2; i<=n; i++) // P
    {
        dp[i] = dp[i-1] + dp[i-2]; // M
    }
    return dp[n]; // R
}


int main()
{
    cout << fib(2) << endl;
    return 0;
}