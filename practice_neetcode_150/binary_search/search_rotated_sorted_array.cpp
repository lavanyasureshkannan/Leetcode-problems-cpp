#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [3,4,5,6,1,2], target = 1
Output: 4
*/

int search_in_rotated_array(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] >= nums[left]) 
        {
            if(target < nums[mid] && target >= nums[left])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if(target > nums[mid] && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int>nums = {3,4,5,6,1,2};
    int target = 1;
    cout << search_in_rotated_array(nums, target);
    return 0;
}