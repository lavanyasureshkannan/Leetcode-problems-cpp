#include <iostream>
#include <vector>
using namespace std;

// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]

vector<int> two_sum(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size()-1;
    while(left < right)
    {
        int sum = nums[left] + nums[right];
        if(sum == target)
        {
            return {left+1, right+1};
        }
        else if(sum < target) 
        {
            left ++;
        }
        else
        {
            right --;
        }
    }
    return {};
}

int main()
{
    vector<int> nums = {0,0,11,15};
    int target = 0;
    vector<int> result = two_sum(nums, target);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}