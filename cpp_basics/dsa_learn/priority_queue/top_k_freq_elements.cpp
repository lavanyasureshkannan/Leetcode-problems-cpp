#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/*
Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]
*/

vector<int> k_freq_elements(vector<int>& nums, int k)
{
    unordered_map<int, int> mp;
    vector<int> result;
    for(int i=0; i<nums.size(); i++)
    {
        mp[nums[i]] ++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(auto i : mp)
    {
        int element = i.first;
        int freq = i.second;
        pq.push({freq, element});
    }
    while(pq.size() > k)
    {
        pq.pop();
    }
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
    vector<int> result = k_freq_elements(nums,k);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}