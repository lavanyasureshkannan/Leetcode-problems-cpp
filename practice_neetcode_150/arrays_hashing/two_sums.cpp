/*
nums = [3,4,5,6], target = 7
Output: [0,1]
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> two_sum(vector<int>& nums, int target)
{
    unordered_map<int,int> mp;
    vector<int>result;
    for(int i=0; i<nums.size(); i++)
    {
        int search = target - nums[i];
        if (mp.find(search) != mp.end())
        {
            result.push_back(i);
            result.push_back(mp[search]);
            return result;
        }
        else
        {
            mp[nums[i]] = i;
        }
    }
    return result;
}

int main()
{
    return 0;
}