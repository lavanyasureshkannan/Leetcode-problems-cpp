#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [-1,0,2,4,6,8], target = 4
Output: 3
*/

int binary_search(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) 
        {
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return  -1;
}


int main()
{
    vector<int>nums = {-1,0,2,4,6,8};
    int target = 4;
    cout << binary_search(nums,target);
    return 0;
}