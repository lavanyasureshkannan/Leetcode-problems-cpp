#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
*/

vector<vector<int>> three_sum(vector<int>& nums)
{
    set<vector<int>> result;
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=i+1; j<nums.size(); j++)
        {
            for(int k=j+1; k<nums.size(); k++)
            {
                if ((nums[i] + nums[j] + nums[k]) == 0)
                {
                    vector<int> levels = {nums[i], nums[j], nums[k]};
                    sort(levels.begin(), levels.end());
                    result.insert(levels);
                }
            }
        }
    }
    return vector<vector<int>> (result.begin(), result.end());
}

vector<vector<int>> three_sum_two_pointers(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for(int i=0; i<nums.size(); i++)
    {
        int left = i+1; 
        int right = nums.size() -1 ;
        if(i > 0 && (nums[i] == nums[i-1])) continue;
        while(left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});
                while(left < right && nums[left] == nums[left + 1]) left ++;
                while(left < right && nums[right] == nums[right - 1]) right --;
                left ++;
                right --;
            }
            else if(sum < 0)
            {
                left ++;
            }
            else
            {
                right --;
            }
        }
    }
    return result;
}

int main()
{
    vector<int>nums = {-1,0,1,2,-1,-4};
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