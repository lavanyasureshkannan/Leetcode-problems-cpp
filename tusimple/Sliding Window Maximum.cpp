#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<queue>
using namespace std;


// BRUTE FORCE
vector<int>maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> result;
    int n = nums.size();
    for(size_t i = 0; i<n-k+1; i++)
    {
        int max_sum = INT_MIN;
        for(size_t j=0; j<k; j++)
        {
            max_sum = max(max_sum, nums[i+j]);
        }
        result.push_back(max_sum);
    }
    return result;
}

// TC: O(N)
// SC: O(N)


vector<int>maxSlidingWindow(vector<int>& nums, int k)
{
    deque<int> dq;
    vector<int> result;
    for(int i =0; i<nums.size(); i++)
    {
        int curr = nums[i];
        // insert the curr element in deque only if back of the element is greater than the curr
        while(dq.empty() == false && nums[dq.back()] < curr)
        {
            dq.pop_back();
        }
        dq.push_back(i);

        // remove the out of bound elements
        while(dq.empty() == false && dq.front() < i-k+1)
        {
            dq.pop_front();
        }
        // maximum element will b returned from the front of the deque
        if(i >= k-1)
        {
            result.push_back(nums[dq.front()]);
        } 
    }
    return result; 
}

// TC: O(N)
// SC: O(N LOG K)

int main()
{
    vector<int> nums = {10,20,30,40,50,60,70};
    int k = 2;
    cout << nums.size() << endl;

    maxSlidingWindow(nums,k);
    return 0;
}