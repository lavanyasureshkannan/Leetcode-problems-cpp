#include<iostream>
#include<vector>
#include<algorithm>

/*
    APPROACH DYNAMIC PROGRAMMING with cache
1. Initialise an array dp and make all the values inside dp as 1
2. dp[i] will represent the longest sequence
3. keep two loops one start at index 0 and the next starts at index 1.
4. keep comparing the previous elements if its less than the current element and increase the dp[i] count
5. return the max dp 
*/

int lengthOfLIS(std::vector<int>& nums)
{
    int n = nums.size();
    std:: vector<int> dp(n,1);
    int result = 0;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(nums[i] > nums[j])
            {
                dp[i] = std::max(dp[i], dp[j]+1);
            }
        }
    }
    for(int i : dp)
    {
        result = std::max(result, i);
    }
    return result;
}

int main()
{
    std::vector<int> nums1 = {10,9,2,5,3,7}; 
    std::cout << lengthOfLIS(nums1);
    return 0;
}


// TC: O(N^2) -> Two nested for loops
// SC: O(N) -> O(N)