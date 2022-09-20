#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <queue>
#include <map>
using namespace std;


/* 
1. use a map and get the frequencies of every element [key : frequencies] 
2. initialise the priority queue -> frequencies will be your priority
3. return the key value and append it on the result array
*/

vector<int> topKfrequent(vector<int>& nums, int k)
{
    vector<int> result;
    // base case
    if(k == nums.size()) return nums;
    // use a map and get the frequencies of every element [key : frequencies] 
    unordered_map<int, int> mp;
    for(int n : nums) 
    {
        mp[n] += 1;
    }

    // initialise the priority queue -> frequencies will be your priority
    priority_queue<pair<int,int>, vector<pair<int,int>>>, greater<pair<int,int>>> PQ;

    // keeping k top frequent elements
    for(auto p : mp) 
    {
        //push pair i.e push(frequency of x, x)
        PQ.push({p.second, p.first});
        //as soon as size of minheap is greater than k pop the the element so that element with least frequency gets popped
        if(PQ.size() > k)
        {
            PQ.pop();
        }
    }
    //now min heap will contain k elements with higher frequency 
    //store them in ans vector

    while(PQ.size() > 0)
    {
        int x = PQ.top().second;
        result.push_back(x);
        PQ.pop();
    }
    return result;
}



// TC: O(N log K) -> O(n) map, O(log k) -> keeping track of the k freq elements
// SC: O(N+K) to store the hash map with not more NN elements and a heap with kk elements.