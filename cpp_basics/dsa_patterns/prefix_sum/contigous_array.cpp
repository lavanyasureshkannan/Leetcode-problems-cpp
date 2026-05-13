#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
*/

int contigous_array_bruteforce(vector<int>& nums)
{
    int max_len = 0;
    for(int i=0; i<nums.size(); i++)
    {
        int sum = 0;
        for(int j=i; j<nums.size(); j++)
        {
            int val;
            if(nums[j] == 0)
            {
                val = -1;
            }
            else val = 1;
            sum = sum + val;
            if(sum == 0)
            {
                int curr_len = j-i+1;
                max_len = max(curr_len,max_len);
            }
        }
    }
    return max_len;
}

int contigous_array_optimised(vector<int>& nums)
{
    unordered_map<int,int> mp; // stores (sum,  index)
    int max_len = 0;
    int sum = 0;
    mp[0] = -1;
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] == 0)
        {
            sum += -1;
        }
        else sum += 1;

        if(mp.count(sum)) // check if the sum already exists
        {
            int curr_len = i - mp[sum];
            max_len = max(curr_len, max_len);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return max_len;

}

/*
TC: O(N) average-> as every element is accessed once
    inside loop -> map and average loop up O(1), insertion O(1)
SC: O(N) -> map
*/

int main()
{
    vector<int> nums = {0,1,1,1,1,1,0,0,0};
    cout << contigous_array_bruteforce(nums) << endl;
    cout << contigous_array_optimised(nums) << endl;
    return 0;
}