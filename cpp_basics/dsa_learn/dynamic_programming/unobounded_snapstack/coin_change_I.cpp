#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
*/

class Rec_solution
{
    public:
    int helper(vector<int>& coins, int amount)
    {
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        int answer = INT_MAX;
        for(int coin : coins)
        {
            int result = helper(coins, amount - coin);
            if(result != INT_MAX)
            {
                answer = min(answer, result+1);
            }
        }
        return answer;
    }

    int coin_change_I(vector<int>& coins, int amount)
    {
        int result = helper(coins, amount);
        if(result == INT_MAX) return -1;
        else return result;
    }
};


class dp_solution
{
    public:
    int coin_change_dp(vector<int>& coins, int amount)
    {
        int maxi = amount + 1; 
        vector<int>dp(maxi, maxi);
        dp[0] = 0;
        for(int i=0; i<=amount; i++)
        {
            for(int j=0; j<coins.size(); j++)
            {
                if(coins[j] <= amount) 
                {
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
    return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main()
{
    vector<int> coins = {1,2,5};
    int amount = 11;
    Rec_solution s1;
    cout << s1.coin_change_I(coins, amount) << endl;
    dp_solution dp1;
    cout << dp1.coin_change_dp(coins,amount) << endl;
    return 0;
}