// Input: nums = [1, 2, 3, 3]
// Output: true

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool contains_duplciates(vector<int>& nums)
{
    // base case
    if(nums.size() == 0) return false;
    unordered_map <int,int> mp;
    for(int i=0; i<nums.size(); i++)
    {
        mp[nums[i]] ++;
    }
    for(const auto& i : mp)
    {
        if(i.second > 1)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 3};
    cout << contains_duplciates(nums);
    return 0;
}