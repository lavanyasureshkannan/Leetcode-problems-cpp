#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

int search_target(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] >= nums[left])
        {
            if(target >= nums[left] && target < nums[mid])
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
            if(target <= nums[right] && target > nums[mid])
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
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << search_target(nums, target) << endl; 
    return 0;
}
