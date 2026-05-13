#include <iostream>
#include <vector>
using namespace std;

/*
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/

int coin_change_II(vector<int>& coins, int amount)
{
    vector<int>dp(amount+1,0);
    dp[0] = 1;
    for(int coin : coins)
    {
        for(int i=coin; i<=amount; i++)
        {
            dp[i] += dp[i-coin];
        }
    }
    return dp[amount];
}

int main()
{
    int amount = 5;
    vector<int> coins = {1,2,5};
    cout << coin_change_II(coins, amount) << endl;
    return 0;
}