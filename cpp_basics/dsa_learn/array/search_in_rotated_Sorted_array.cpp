#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

int search_in_roatated(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] >= nums[left]) // 7 >= 4
        {
            if(nums[left] <= target && target < nums[mid]) // 4 <= 5 < 7 
            {
                right = mid - 1; //ignore right, move the right to mid
            }
            else
            {
                left = mid + 1;
            }
        }   
        else
        {
            if(nums[right] >= target && target > nums[mid])
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

// TC: O(Log N) -> eliminate half the search space
// SC: O(1) -> left right constant space

int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 5;
    cout << search_in_roatated(nums, target);
    return 0;
}