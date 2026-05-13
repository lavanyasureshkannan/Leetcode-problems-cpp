#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3

*/

int duplicate_num_bf(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] == nums[i+1])
        {
            return nums[i];
        }
    }
    return -1;
}

int duplicate_map(vector<int>& nums)
{
    unordered_map<int, int> mp;
    for(int i=0; i<nums.size(); i++)
    {
        mp[nums[i]] ++;
    }
    for(auto i : mp)
    {
        if(i.second >=2) return i.first;
    }
    return -1;
}

int duplicate_floyd(vector<int>& nums)
{
    int n = nums.size();
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[slow]];
    } while(slow != fast);

    // find the start of the cycle
    fast = nums[0];
    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main()
{
    vector<int> nums = {1,3,4,2,2,2};
    cout << duplicate_num_bf(nums) << endl;
    cout << duplicate_map(nums) << endl;
    cout << duplicate_floyd(nums) << endl;
    return 0;
}