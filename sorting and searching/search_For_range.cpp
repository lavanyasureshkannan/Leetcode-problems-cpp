#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/

void display(vector<int>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}
// vector<int> SearchforRange_bruteforce(vector<int>& nums, int target)
// {
//     vector<int> result;
//     for(int i=0; i<nums.size(); i++)
//     {
//         if(nums[i] == target)
//         {
//             result.push_back(i);
//         }
//     }
//     display(result);
//     return result;
// }





int findfirstindex(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int index = -1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] >= target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
        if(nums[mid] == target)
        {
            index = mid;
        }
    }
    return index;
}

int findlastindex(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int index = -1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] <= target)
        {
            left = mid+1;
        }
        else
        {
            right = mid -1;
        }
        if(nums[mid] == target)
        {
            index = mid;
        }
    }
    return index;
}

vector<int> SearchforRange_twopoint(vector<int>& nums, int target)
{
    vector<int> result;
    int first = findfirstindex(nums, target);
    int last = findlastindex(nums, target);
    result.push_back(first);
    result.push_back(last);
    display(result);
    return result;
}


int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    SearchforRange_twopoint(nums, target);
    return 0;
}