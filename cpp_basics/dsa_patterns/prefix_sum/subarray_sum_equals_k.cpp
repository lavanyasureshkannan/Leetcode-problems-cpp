#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Input: nums = [1,2,3], k = 3
Output: 2
Explanation: [1,2] [3]
*/

int subarraysum_bruteforce(vector<int>& nums, int k)
{
    int result = 0;
    for(int i=0; i<nums.size(); i++)
    {
        int sum = 0;
        for(int j=i; j<nums.size(); j++)
        {
            sum += nums[j];
            if(sum == k) 
            {
                result ++;
            }
        }
    }
    return result;
}

/*
    TC: O(N^2)
    SC: O(1)
*/

int subarray_optimised(vector<int>& nums, int k)
{
    int sum = 0;
    int result = 0;
    unordered_map<int,int> mp; // [prefix_sum ,  counts]
    mp[0] = 1; // [[0,1]
    for(int i=0; i<nums.size(); i++)
    {
        sum = sum + nums[i];
        if(mp.count(sum-k)) // lets say if sum = 4 and if (sum - k) (4-3) = 1 which is already found in the map then the following array is subarray
        {
           result += mp[sum-k];
        }
        mp[sum] ++; 
    }
    return result; 
}

/*
TC: O(N) -> loops once
SC: O(N) -> prefix sum
*/

int main()
{
    vector<int> nums = {1,2,3};
    int k = 3;
    cout << subarraysum_bruteforce(nums, k);
    return 0;
}