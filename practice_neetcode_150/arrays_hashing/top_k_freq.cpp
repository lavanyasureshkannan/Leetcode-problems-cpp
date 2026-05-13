/*
Input: nums = [1,2,2,3,3,3], k = 2
Output: [2,3]
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> top_k_freq (vector<int>& nums, int k)
{
    unordered_map<int,int> mp;
    for (int i=0; i<nums.size(); i++)
    {
        mp[nums[i]] ++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(auto i:mp)
    {
        pq.push({i.first, i.second});
        if(pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<int> result;
    while(!pq.empty())
    {
        auto x = pq.top().second;
        result.push_back(x);
        pq.pop();
    }
    return result;
}

int main()
{
    vector<int>nums = {1,2,2,3,3,3};
    int k = 2;
    vector<int>v = top_k_freq(nums,k);
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}

