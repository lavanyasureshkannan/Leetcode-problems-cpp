#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
*/

bool k_consecutive_nums(vector<int> nums, int k)
{
    int n = nums.size();
    if(n%k != 0) return false;
    map<int,int> mp;
    for(int i=0; i<nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    for(auto i : mp)
    {
        int start = i.first;
        int count = i.second;
        if(count > 0)
        {
            for(int i=0; i<k; i++)
            {
                if(mp[start+i] < count) return false;
                mp[start+i] -= count;
            }
        }
    }
    return true;

}

int main()
{
    vector<int>nums = {1,2,3,3,4,4,5,6};
    int k = 4;
    cout << k_consecutive_nums(nums,k);
}