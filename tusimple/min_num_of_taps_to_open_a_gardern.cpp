#include<iostream>
#include<vector>
using namespace std;

int minTaps(int n, vector<int>& A) 
{
        // dp[i] is the minimum number of taps to water [0, i].
        // Initialize dp[i] with max = n + 2
        vector<int> dp(n + 1, n + 2);
        //as we need no tap to water nothing
        dp[0] = 0;
        // Find the leftmost point of garden to water with tap i
        for (int i = 0; i <= n; i++)
        {
            int left = max(i - A[i] + 1, 0);
            int right = min(i + A[i], n);
            for (int j = left; j <= right; j++)
            {
                dp[j] = min(dp[j], dp[max(0, i - A[i])] + 1);
            }
        }
        if(dp[n] < n+2) return dp[n];
        else return -1;
        
}

// TC: O(N * R) -> R is the range
// SC: O(N)
int main()
{
    return 0;
}