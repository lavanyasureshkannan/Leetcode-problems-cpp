#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
*/

int find_min_rotated(vector<int>& nums)
{
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] > nums[mid+1]) return nums[mid+1];
        else if(nums[mid-1] > nums[mid]) return nums[mid];

        if(nums[mid] > nums[0]) left = mid +1;
        else right = mid - 1;
        
    }
    return -1;
}

int find_min_bf(vector<int>& nums)
{
    int n = nums.size();
    vector<bool> mask(n,false);
    for(int i=1; i<nums.size(); i++)
    {
        if(nums[i] < nums[i-1])
        {
            mask[i] = true;
        }
    }
    for(int i=0; i<mask.size(); i++)
    {
        if(mask[i] == true)
        {
            return nums[i];
            break;
        }
    }
    return -1;
}


int main()
{
    vector<int> nums = {3,4,5,1,2};
    cout << find_min_rotated(nums) << endl;
    return 0;
}