#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
*/

int top_k_elements(vector<int>& nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<nums.size(); i++)
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
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << top_k_elements(nums, k) << endl;
    return 0;
}