#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

/*
Input: arr = [1,2,3,4,5], k = 4, x = 3

Output: [1,2,3,4]
*/

void print_arr(vector<int>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

vector<int> k_closest_bruteforce(vector<int>& nums, int k, int x)
{

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
    for(int i=0; i<nums.size(); i++)
    {
        int dist = abs(nums[i] - x);
        pq.push({dist, nums[i]});
    }
    vector<int> result;
    for(int i=0; i<k && !pq.empty(); i++)
    {
        auto [dist, val] = pq.top();
        pq.pop();
        result.push_back(val);
    }
    sort(result.begin(), result.end());
    print_arr(result);
    return result;
}


int main()
{
    // int x1 = 3;
    // int x2 = 5;
    // int delta = x2 - x1;
    // cout << sqrt(pow(delta, 2));
    vector<int> nums = {1,2,3,4,5};
    int k = 4; int x = 3;
    k_closest_bruteforce(nums, k, x);
    return 0;
}