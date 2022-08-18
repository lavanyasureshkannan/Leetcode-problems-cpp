#include<iostream>
#include<vector>
using namespace std;

/*
    TWO POINTER TECHNIQUE
*/
class Solution 
{
    public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int result = nums[0] + nums[1] + nums[nums.size()-1];
        sort(nums.begin(), nums.end());

        // For the current position i, set lo to i + 1, and hi to the last index.
        for(int i=0; i<nums.size()-2; i++)
        {
            int a_ptr = i+1;
            int b_ptr = nums.size() -1;

            while(a_ptr < b_ptr)
            {
                // Set sum to nums[i] + nums[low] + nums[high]
                int curr_sum = nums[i] + nums[a_ptr] + nums[b_ptr];
                if(curr_sum > target)
                {
                    b_ptr --;
                }
                else
                {
                    a_ptr ++;
                }
                if(abs(curr_sum - target) < abs(result-target))
                {
                    result = curr_sum;
                }
            }
        }
        return result;
        }
};

// TC: O(N^2) Sorting the array takes O(n log n)  + over all
// SC: O(n) Depending on the implementation of the sorting algorithm.

