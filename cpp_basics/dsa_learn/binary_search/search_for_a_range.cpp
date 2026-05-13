#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/





int first_occurence(vector<int>& nums, int target)
{
    int index = -1;
    int left = 0;
    int right = nums.size()-1;
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


int last_occurence(vector<int>& nums, int target)
{
    int index = -1;
    int left = 0;
    int right = nums.size()-1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] <= target) 
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
        if(nums[mid] == target)
        {
            index = mid;
        }
    }
    return index;
}

vector<int> search_Range(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    vector<int> result;
    int first = first_occurence(nums, target);
    int last = last_occurence(nums, target);
    result.push_back(first);
    result.push_back(last);
    return result;
}

int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> result = search_Range(nums, target);
    for(int i=0; i <result.size(); i++)
    {
        cout << result[i] << " ";
    }
    // cout << first_occurence(nums, target) << endl;
    // cout << last_occurence(nums, target) << endl;
    return 0;
}