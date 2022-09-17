
class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        // two pointer approach
        int c = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != val)
            {
                nums[c] = nums[i];
                c++;
            }
        }
        return c;
            
    }
};


// two pointer

class Solution
{
    public:
    int removeElement(vector<int>& nums, int val) 
    {
        int i = 0;
        int n = nums.length;
        while (i < n) 
        {
            if (nums[i] == val) 
            {
                nums[i] = nums[n - 1];
                // reduce array size by one
                n--;
            } else 
            {
                i++;
            }
    }
    return n;
};


// TC: O(N)
// SC: O(1)