/*
Input: numbers = [1,2,4,5], target = 3
Output: [1,2]
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> two_sum_sorted(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while(left < right)
    {
        int sum = nums[left] + nums[right];
        if(sum == target)
        {
            return {left+1, right+1};
        }        
        else if(sum < target) left ++;
        else right --;
    }
    return {};
}



int main()
{
    vector<int> nums = {1,2,3,4};
    int target = 3;
    vector<int> result = two_sum_sorted(nums, target);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}