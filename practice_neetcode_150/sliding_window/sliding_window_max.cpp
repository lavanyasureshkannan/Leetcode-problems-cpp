#include <iostream>
#include <vector>
#include <climits>
#include <deque>
using namespace std;

/*
Input: nums = [1,2,1,0,4,2,6], k = 3
Output: [2,2,4,4,6]
Explanation:
Window position            Max
---------------           -----
[1  2  1] 0  4  2  6        2
 1 [2  1  0] 4  2  6        2
 1  2 [1  0  4] 2  6        4
 1  2  1 [0  4  2] 6        4
 1  2  1  0 [4  2  6]       6
*/

// one pass solution
vector<int> sliding_window_max_bf(vector<int>& nums, int k)
{
    vector<int> result;
    int n = nums.size();
    for(int i=0; i<(n-k); i++)
    {
        int curr_sum = INT_MAX;
        for(int j=i; j<(i+k); j++)
        {
            curr_sum = max(nums[j], curr_sum);
        }
        result.push_back(curr_sum);
    }
    return result;
}

// deque => front is maximum
/*
nums: 1  3  -1  -3  5
index:0  1   2   3  4
window size k = 3

Step i=4, window=[2,3,4]:

Deque front = 1 (value=3) → outside window → remove

Deque now: [2,3] → front=2 (value=-1) → inside window → keep
*/


vector<int> sliding_window_maxi(vector<int>& nums, int k)
{
    vector<int> result;
    deque<int> dq;
    for(int i=0; i<nums.size(); i++)
    {
        // removing the useless elements
        if(!dq.empty() && dq.front() < i-k+1) 
        {
            dq.pop_front();
        }
        // removing the smaller elements
        while(!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        // if window is ready take the max out of it
        if(i >= k-1)
        {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}


int main()
{
    vector<int>nums = {1,2,1,0,4,2,6};
    int k = 3;
    vector<int>result = sliding_window_maxi(nums,k);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}