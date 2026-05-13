#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
Input: nums = [9,6,4,2,3,5,7,0,1]

Output: 8
Explanation:

n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 
8 is the missing number in the range since it does not appear in nums.
*/
// [0,1,2,3,4,5,6,7,9]

int missing_num(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    // base case
    int n = nums.size();
    if(nums[n-1] != n) return n;
    else if(nums[0] != 0) return 0;
    int result = 0;
    for(int i=1; i<nums.size(); i++)
    { 
        // 1 = 0+1
        if(nums[i] != nums[i-1] + 1) 
        {
            result = nums[i-1] + 1;
        }

    }
    return result;
}

int main()
{
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    cout << missing_num(nums);
    return 0;
}