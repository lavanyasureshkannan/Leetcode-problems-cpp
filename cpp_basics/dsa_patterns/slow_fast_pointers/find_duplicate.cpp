#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
Input: nums = [1,3,4,2,2]
Output: 2
*/
int findDuplicate(vector<int>& nums)
{
    unordered_map<int,int> mp;
    for(int i=0; i<nums.size(); i++)
    {
        mp[nums[i]] ++;
    }
    for(auto i:mp)
    {
        if(i.second > 1)
        {
            return i.first;
        }
    }
    return -1;
}

int find_duplicate_floyd(vector<int>& nums)
{
    int slow = nums[0];
    int fast = nums[0];
    // detect the cycyle
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];

    } while (slow != fast);

    // find the entry point
    slow = nums[0];
    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow; 
}

int main()
{
    vector<int> nums = {1,3,4,2,2};
    cout << findDuplicate(nums) << endl;
    cout << find_duplicate_floyd(nums) << endl;
}