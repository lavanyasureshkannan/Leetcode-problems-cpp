#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/

int longest_increasing_sub(vector<int>& nums)
{
    int result = 0;
    int n = nums.size();
    vector<int> dp(n, 1);
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++) // for every element check its before elements
        {
            if(nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    for(int i:dp)
    {
        result = max(i, result);
    }
    return result;
}


int main()
{
    vector<int>nums = {10,9,2,5,3,7,101,18};
    cout << longest_increasing_sub(nums) << endl;
    return 0;
}