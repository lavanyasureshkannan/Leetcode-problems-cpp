#include <iostream>
#include <vector>
using namespace std;

/*
Input: prices = [10,1,5,6,7,1]
Output: 6
*/

int best_time_buy_and_sell(vector<int>& prices)
{
    int maxi = 0;
    for(int i=1; i<prices.size(); i++)
    {
        if(prices[i] > prices[i-1])
        {
            maxi += prices[i] - prices[i-1];
        }
    }
    return maxi;
}

int best_time_buy_and_sell_2pointer(vector<int>& prices)
{
    int left = 0;
    int right = 1;
    int maxi = 0;
    while(right < prices.size())
    {
        if(prices[left] < prices[right])
        {
            int profit = prices[right] - prices[left];
            maxi = max(profit, maxi);
        }
        else {
            left ++;
        }
        right ++;

    }
    return maxi;
}


int main()
{
    vector<int> prices = {10,1,5,6,7,1};
    cout << best_time_buy_and_sell(prices) << endl;
    cout << best_time_buy_and_sell_2pointer(prices) << endl;
    return 0;
}