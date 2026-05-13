#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Input: nums = [2,3,1,5,4], k = 2
Output: 4
*/

int kth_largest_element(vector<int>& nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq_min;
    for(int i : nums)
    {
        pq_min.push(i);
        if(pq_min.size() > k)
        {
            pq_min.pop();
        }
    }
    return pq_min.top();
}

int main()
{
    vector<int>nums = {2,3,1,5,4};
    int k = 2;

    cout << kth_largest_element(nums,k);
    return 0;
}