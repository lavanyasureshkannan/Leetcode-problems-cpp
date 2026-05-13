#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
*/

double max_average_subarray(vector<int>& nums, int k)
{
    double curr_sum = 0;
    for(int i=0; i<k; i++)
    {
        curr_sum = curr_sum + nums[i];
    }
    double max_sum = curr_sum;
    for(int i=k; i<nums.size(); i++)
    {
        curr_sum = curr_sum - nums[i-k] + nums[i];
        max_sum = max(curr_sum, max_sum);
    }

    return max_sum/k;
}

int main()
{
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    cout << max_average_subarray(nums, k) << endl;
    return 0;
}