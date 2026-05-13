#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

/*
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/

void print(vector<int>& nums)
{
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    
}

vector<int> sliding_window_max_bf(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<int> result;
    for(int i=0; i<=n-k; i++)
    {
        int curr_max = INT_MIN;
        for(int j=i; j<i+k; j++)
        {
            curr_max = max(nums[j], curr_max);
        }
        result.push_back(curr_max);

    }
    print(result);
    return result;
}

// TC: O(n^2)


vector<int> sliding_window_max_PQ(vector<int>& nums, int k)
{
    priority_queue<pair<int,int>> pq;
    vector<int> result;
    for(int i=0; i<nums.size(); i++)
    {
        // push the elements to pq
        pq.push({nums[i],i});
        // remove the outdated element
        while(!pq.empty() && pq.top().second <= i-k) pq.pop();
        // store max once window formed
        if(i >= k-1) result.push_back(pq.top().first);
    }
    print(result);
    return result;
}

// TC: O(NlogN)

vector<int> sliding_window_max_dq(vector<int>& nums, int k)
{

    vector<int>result;
    deque<int>dq;
    for(int i=0; i<nums.size(); i++)
    {
        if(!dq.empty() && dq.front() == i-k) dq.pop_front();
        //remove element from the back if it is too low
        while(!dq.empty() && dq.front() < nums[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k-1)
        {
            result.push_back(nums[dq.front()]);
        }
    }
    print(result);
    return result;
}

// TC: O(n)

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    priority_queue<pair<int,int>> pq;
    vector<int> result;
    for(int i=0; i<nums.size(); i++)
    {
        // push the elements to pq
        pq.push({nums[i],i});
        // remove the outdated element
        while(!pq.empty() && pq.top().second <= i-k) pq.pop();
        // store max once window formed
        if(i >= k-1) result.push_back(pq.top().first);
    }
    return result;
}

int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    sliding_window_max_bf(nums,k);
    cout << endl;
    sliding_window_max_PQ(nums,k);
        cout << endl;
    sliding_window_max_dq(nums,k);
    return 0;
}