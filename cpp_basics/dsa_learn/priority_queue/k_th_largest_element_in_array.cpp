#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/*
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
*/

int k_th_largest_element(vector<int>& nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
    while(pq.size() > k)
    {
        pq.top();
        pq.pop();
    }
    int max_element = pq.top();
    return max_element;

}

int main()
{
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << k_th_largest_element(nums, k);
    return 0;
}