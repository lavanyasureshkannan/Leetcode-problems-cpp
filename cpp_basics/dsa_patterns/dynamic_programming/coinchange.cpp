#include <iostream>
#include <vector>
using namespace std;

/*
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Input: coins = [2], amount = 3
Output: -1

Input: coins = [1], amount = 0
Output: 0
*/

int coinchange(vector<int>& coins, int amount)
{
    int maxi = amount + 1;
    vector<int> dp(maxi, maxi);
    dp[0] = 0;

    for(int i=1; i<=amount; i++)
    {
        for(int c:coins)
        {
            if(c <=i)
            {
                dp[i] = min(dp[i], dp[i-c]+1); // subtract the coin value from amount
            }
        }
    }
    if(dp[amount] > amount) return -1;
    return dp[amount]; 
}



int main()
{
    vector<int>coins = {1,2,5};
    cout << coinchange(coins, 11) << endl;
    return 0;
}