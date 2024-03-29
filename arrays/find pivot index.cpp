class Solution 
{
public:
    int pivotIndex(vector<int>& nums) 
    {
        int total = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            total += nums[i];
        }
        
        int left_sum = 0;
        for(int i =0; i<nums.size(); i++)
        {
            int right_sum = total - left_sum - nums[i];
            if(left_sum == right_sum)
            {
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
        
    }
};

// TC: O(N)
// SC: O(1)