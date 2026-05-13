#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/*
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
*/

vector<int> top_q_elements(vector<int>& nums, int k)
{
    unordered_map<int,int> mp;
    for(int i=0; i<nums.size(); i++)
    {
        mp[nums[i]] ++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(auto i:mp)
    {
        pq.push({i.second, i.first});
        if(pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<int> result;
    while(pq.size() > 0)
    {
        int x = pq.top().second;
        result.push_back(x);
        pq.pop();
    }
    return result;
}

int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = top_q_elements(nums,k);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}