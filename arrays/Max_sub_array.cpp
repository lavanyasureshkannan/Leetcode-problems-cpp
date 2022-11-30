#include<iostream>
#include<vector>
using namespace std;

// brute force approach
class Solution 
{
    public:
    int maxSubArray(vector<int>& nums) 
    {
        int result = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<=nums.size(); j++)
            {
                int sum = 0;

                for(int sub = i; sub < j; sub++)
                {
                    sum = sum + nums[sub];
                }
                result = max(result, sum);
            }
            
        }
        return result;    
    }
};
// TC: O(N^3) 
// SC: O(1)


// more like a sliding window approach

class Solution 
{
    public:
    int maxSubArray(vector<int>& nums) 
    {
        int max_sum = nums[0];
        int curr_sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            // negative numbers is not gonna help us at all so lets not consider it
            if(curr_sum < 0)
            {
                curr_sum = 0;
            }
            curr_sum = curr_sum + nums[i];
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }    
};

// TC: O(N)
// SC: O(1)