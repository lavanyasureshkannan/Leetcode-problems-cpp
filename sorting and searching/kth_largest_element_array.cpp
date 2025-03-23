#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
nums = [3,2,1,5,6,4], k = 2
*/

int k_th_largest(vector<int>& nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i: nums)
    {
        pq.push(nums[i]);
        if(pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}

int main()
{
    return 0;
}
