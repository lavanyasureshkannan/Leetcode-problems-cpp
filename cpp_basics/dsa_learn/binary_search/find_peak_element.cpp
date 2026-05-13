#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [1,2,3,1]
Output: 2

Input: nums = [1,2,1,3,5,6,4]
Output: 5
*/

// BRUTE FORCE
int peak_element_brute_force(vector<int>& nums)
{
    for(int i=1; i<nums.size(); i++)
    {
        if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
        {
            return i;
        }
    }
    return -1;
}

// Optimised method
int peak_element_optimsed(vector<int>& nums)
{
    int left = 0;
    int right = nums.size() - 1;
    while(left < right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] > nums[mid+1]) 
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    vector<int> nums = {1,2,1,3,5,6,4};
    cout << peak_element_brute_force(nums) << endl;
    cout << peak_element_optimsed(nums) << endl;
    return 0;
}