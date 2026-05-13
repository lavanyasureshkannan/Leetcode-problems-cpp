#include <iostream>
#include <vector>
using namespace std;


/*
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
*/

// brute force 
// TC: O(n)
int binary_search(vector<int>& nums, int target)
{
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// optmized 
// TC: o(log N)
int binary_search_optimised(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while(left < right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid] < target)
        {
            left ++;
        }
        else right --;
    }
    return -1;
}


int main()
{
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    cout << binary_search_optimised(nums, 9) << endl;
    return 0;
}