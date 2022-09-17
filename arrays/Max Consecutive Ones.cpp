#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
    int count = 0;
    int max_count =0;
    for(int i=0; i<nums.size(); i++)
    {
        // increment the count by one's
        if(nums[i] == 1) count = count + 1;
        else 
        {
            max_count = max(max_count, count);
            count = 0;
        }
    }
    return max(max_count, count);
        
    }
};


// TIME COMPLEXITY O(N) Where N is the number of array
// SPACE COMPLEXITY O(1)



