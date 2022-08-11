/*
ONE PASS SOLUTION
use three pointers
*/
class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        // base case
        if(nums.size() == 0 || nums.size() == 1) return;
        int start = 0    
        int end = nums.size()-1;
        int index = 0;

        while(index <= end && start < end)
        {
            // swap the elements
            if(nums[index] == 0)
            {
                nums[index] = nums[start];
                nums[start] = 0;
                start++;
                index++;
            }
            else if(nums[index] == 2)
            {
                nums[index] = nums[end];
                nums[end] = 2;
                end--;
            }
            else // if its 1 then we move our index forward
            {
                index++;
            }
        }
    }
};

// TC: O(N) since it's one pass along the array of length N.
// SC: O(1) constant space 