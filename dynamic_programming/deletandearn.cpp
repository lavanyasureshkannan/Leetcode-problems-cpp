#include<iostream>
#include<vector>
using namespace std;

void display(vector<int>& array)
{
    for(int i=0; i< array.size(); i++)
    {
        cout << array[i] << " ";
    }
}

int deleteAndEarn(vector<int>& nums)
{
    vector<int> arr(10001,0); // ranges till 10000
    vector<int> dp(10001,0);
    for(int i=0; i<nums.size(); i++)
    {
        arr[nums[i]] += nums[i];
        
    }
    //display(arr);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for(int i = 2; i < 10001; i++)
    {
        dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
    }
    cout << dp[10000];    
    return dp[10000];
}

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> values(n, 0);
        for (int num : nums)
            values[num] += num;

        int pick = 0, leave = 0;
        for (int i = 0; i < n; i++) {
            int pickit = leave + values[i];
            int leaveit = max(pick, leave);
            pick = pickit;
            leave = leaveit;
        }
        return max(pick, leave);
    }
};

int main()
{
    vector<int> a = {2,2,3,3,3,4};
    deleteAndEarn(a);
    return 0;
}