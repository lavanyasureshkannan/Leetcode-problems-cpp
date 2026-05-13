#include <iostream>
#include <vector>
using namespace std;

/*
    Input: nums = [10,9,2,5,3,7,101,18]
    Output: 4
    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/

int Longest_Increasing_Subseq(vector<int>& nums)
{
    int n = nums.size();
    vector<int>dp(n, 1);
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=0; j<nums.size(); j++)
        {
            if(nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int result = 0;
    for(int i : dp)
    {
        result = max(result, i);
    }
    return result;
}

int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << Longest_Increasing_Subseq(nums) << endl;
    return 0;
}