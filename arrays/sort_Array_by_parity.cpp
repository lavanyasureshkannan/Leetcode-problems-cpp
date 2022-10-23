class Solution {
public:
vector<int> sortArrayByParity(vector<int>& nums)
{
    int left = 0;
    int right = nums.size() - 1;
    while(left < right)
    {
        if(nums[left] % 2 >nums[right] % 2)
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
        }
        if(nums[left] % 2 == 0) left++;
        if(nums[right] % 2 == 1) right--;
    }
    return nums;
}
};




// TIME COMPLEXITY O(N) --> N is the size of A
// SPACE COMPLEXITY O(1)