#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
*/

vector<vector<int>> three_sum(vector<int>& nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end()); // [-4,-1,-1,0,1,2]
    for(int i=0; i<nums.size(); i++)
    {
        //base case
        if (nums[i] > 0) break;
        // check for duplicates
        if(i>0 && nums[i] == nums[i-1]) continue;
        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});
                left ++;
                right --;
                while (left < right && nums[left] == nums[left - 1]) left ++;
                while (left < right && nums[right] == nums[right + 1]) right--;
            }
            else if(sum < 0) left ++;
            else right --;
        }
    }
    return result;

}

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = three_sum(nums);
    for(int i=0; i<result.size(); i++)
    {
        for(int j=0; j<result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}