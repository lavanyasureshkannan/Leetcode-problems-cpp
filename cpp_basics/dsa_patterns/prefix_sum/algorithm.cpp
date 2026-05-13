#include <iostream>
#include <vector>
using namespace std;

/*
Input: arr[] = [10, 20, 10, 5, 15]
Output: [10, 30, 40, 45, 60]
Explanation: For each index i, add all the elements from 0 to i:
prefixSum[0] = 10, 
prefixSum[1] = 10 + 20 = 30, 
prefixSum[2] = 10 + 20 + 10 = 40 and so on.
*/

void display(vector<int>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        cout << nums[i] << " " << endl;
    }
}

vector<int> prefix_sum(vector<int>& nums)
{
    int n = nums.size();
    vector<int> result(n);
    result[0] = nums[0];
    for(int i=1; i<nums.size(); i++)
    {
        result[i] = nums[i] + result[i-1];
    }
    display(result);
    return result;
}



int main()
{
    vector<int> nums = {10, 20, 10, 5, 15};
    prefix_sum(nums);
    return 0;
}



