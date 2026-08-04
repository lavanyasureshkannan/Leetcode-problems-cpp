#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Input: arr[] = [10, 20, 10, 5, 15]
//Output: [10, 30, 40, 45, 60]

void print(const vector<int>& nums)
{
    for(size_t i=0; i<nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

// prefix sum
vector<int> prefix_sum (vector<int>& nums)
{
    size_t n = nums.size();
    vector<int> result(n);
    result[0] = nums[0];
    for(size_t i=1; i<nums.size(); i++)
    {
        result[i] = nums[i] + result[i-1];
    }
    print(result);
    return result;
}

// Range Sum Query - Immutable
class Range_sum
{
    public:
    vector<int> prefix;
    Range_sum(vector<int>& nums)
    {
        size_t n = nums.size();
        prefix.reserve(n);
        prefix[0] = nums[0];
        for(size_t i = 1; i<n; i++)
        {
            prefix[i] = nums[i] + prefix[i-1];
        }
    }
    int sum_range(int left, int right)
    {
        if(left == 0)
        {
            return prefix[right];
        }
        else
        {
            return prefix[right] - prefix[left - 1];
        }
    }
};

// Subarray Sum Equals K
/*

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
*/

int subarray_sum_bf(vector<int>& nums, int k)
{
    int result = 0;
    for(size_t i=0; i<nums.size(); i++)
    {
        int sum = 0;
        for(size_t j=i; j<nums.size(); j++)
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

int subarray_sum_optimised(vector<int>& nums, int k)
{
    unordered_map<int,int> mp;
    mp[0] = 1;
    int curr_Sum = 0;
    int result = 0;
    for(size_t i=0; i<nums.size(); i++)
    {
        curr_Sum += nums[i];
        if(mp.find(curr_Sum-k) != mp.end())
        {
            result += mp[curr_Sum-k];
        }
        mp[curr_Sum] ++;
    }
    return result;
}



int main()
{
    // vector<int> nums = {-2, 0, 3, -5, 2, -1};
    // prefix_sum(nums);
    // Range_sum r1(nums);
    // cout << r1.sum_range(0,2) << endl;
    // cout << r1.sum_range(2,5) << endl;
    // cout << r1.sum_range(0,5) << endl;

    // vector<int>nums = {1,1,1};
    // int k = 2;
    // cout << subarray_sum_bf(nums,k) << endl;
    // cout << subarray_sum_optimised(nums,k) << endl;

    return 0;
}