class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> result(n);
        for (int i =0; i<nums.size(); i++)
        {
            result[(i+k) % n] = nums[i];
        }
        nums = result;
    }
};

// TC: O(N)
// SC: O(N)