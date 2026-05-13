#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [3,4,5,1,2]
Output: 1

Input: nums = [4,5,6,7,0,1,2]
Output: 0
*/

int find_min_brute_force(vector<int>& nums)
{
    int smallest = nums[0];
    for(int i=1; i<nums.size(); i++)
    {
        if(nums[i] < smallest)
        {
            smallest = nums[i];
        }
    }
    return smallest;
}

int find_min_two_pointer(vector<int>& nums)
{
    if(nums.size() == 0) return -1;
    if(nums.size() == 1) return nums[0];
    int left = 0;
    int right = nums.size()-1;
    while(left < right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] > nums[mid+1])
        {
            left = mid+1;
        }
        else
        {
            right = mid;
        }
    }
    return nums[left];
}

int find_min_template2(vector<int>& nums)
{
    int left = 0;
    int right = nums.size()-1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] > nums[mid+1]) return nums[mid+1];
        else if(nums[mid-1] < nums[mid]) return nums[mid];

        if(nums[mid] > nums[0]) 
        {
            left = mid + 1;
        }
        else
        {
            right = mid-1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {3,4,5,1,2};
    cout << find_min_brute_force(nums) << endl;
    cout << find_min_two_pointer(nums) << endl;
    cout << find_min_template2(nums) << endl; 
    return 0;
}