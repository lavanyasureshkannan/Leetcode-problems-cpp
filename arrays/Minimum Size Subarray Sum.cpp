#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n= nums.size();
        int ans = INT_MAX;
        int left = 0;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            while(sum >= target)
            {
                ans = min(ans, i+1-left);
                sum = sum - nums[left++];
            }
        }
        return (ans != INT_MAX) ? ans : 0;
        
        
    }
};

// TC: O(N)
// SC: O(1)