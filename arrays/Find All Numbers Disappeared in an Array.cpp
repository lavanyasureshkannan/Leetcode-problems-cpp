class Solution 
{
    public:
    vector<int> findDisappearedNumbers(vector<int> &nums) 
    {
        vector<int> result;
        int size = int(nums.size());
        for (int i = 0; i < size;i++) 
        {
            if (nums[i] == 0) 
            {
                continue;
            }
            int index = nums[i] - 1;
            while (nums[index]) 
            {
                int nextIndex = nums[index] - 1;
                nums[index] = 0;
                index = nextIndex;
            }
        }
        
        for (int i = 0; i < size; i++) 
        {
            if (nums[i] != 0) 
            {
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};