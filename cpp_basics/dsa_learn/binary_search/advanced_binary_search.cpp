#include <iostream>
#include <vector>
using namespace std;

/*
Binary search template II
*/

int binary_Search2(vector<int>& nums, int target)
{
    if(nums.size() == 0) return -1;
    int left = 0;
    int right = nums.size() - 1;
    while(left < right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target)
        {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }
    // termination condition
    if(nums[left] == target) return left;
    return -1;
}

int main()
{
    return 0;
}