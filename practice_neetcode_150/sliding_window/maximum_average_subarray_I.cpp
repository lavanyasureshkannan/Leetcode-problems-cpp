#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
*/

double max_average_subarray_bf(vector<int>& nums, int k)
{
    int n = nums.size();
    double max_sum = 0.0;
    for(int i=0; i<(n-k); i++)
    {
        double curr_sum = 0;
        for(int j=i; j<(i+k); j++)
        {
            curr_sum += nums[j];
        }
        max_sum = max(curr_sum, max_sum);
    }
    return max_sum/k;
}

double max_average_subarray_sliding_win(vector<int>& nums, int k)
{
    double curr_sum = 0;
    for(int i=0; i<k; i++)
    {
        curr_sum += nums[i];
    }
    double max_sum = curr_sum;
    for(int i=k; i<nums.size(); i++)
    {
        curr_sum = curr_sum - nums[i-k] + nums[i];
        max_sum = max(curr_sum, max_sum);
    }
    return max_sum/k;
}


double max_average_deque(vector<int>& nums, int k)
{
    deque<int> dq;
    double max_average = 0.0;
    for(size_t i=0; i<nums.size(); i++)
    {
        dq.push_back(nums[i]);
        if(dq.size() > k) dq.pop_front();
        if(dq.size() == k)
        {
            double sum = 0;
            for(double e : dq) {sum += e;}
            double curr_avg = sum / k; 
            max_average = max(max_average, curr_avg);
        }
    }
    return max_average;
}


int main()
{
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    cout << max_average_subarray_bf(nums,k) << endl;
    cout << max_average_subarray_sliding_win(nums,k) << endl;
    cout << max_average_deque(nums,k) << endl;
    return 0;
}