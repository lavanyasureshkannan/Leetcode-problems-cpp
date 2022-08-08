#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <queue>
using namespace std;


class Solution
{
    public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>>q;
        for(int i=0; i<nums.size(); i++)
        {
            q.push(nums[i]);
            if(q.size() > k)
            {
                q.pop();
            }
        }
        return q.top();

    }
   
};

// TC: O(NlogN) -> q contruction O(n), inserting elements in q O(log n), pop O(1)
// SC: O(K) -> store the heap elements