#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

void print(vector<vector<int>>& result)
{
    for(int i=0; i<result.size(); i++)
    {
        for(int j=0; j<result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}


vector<vector<int>> result;
void backtrack(vector<int>& nums, int index)
{
    // base case
    if(index == nums.size())
    {
        result.push_back(nums);
    };
    for(int i=index; i<nums.size(); i++)
    {
        // make choice
        swap(nums[index], nums[i]);
        // backtrack
        backtrack(nums, index + 1);
        // undo
        swap(nums[index], nums[i]);
    }
    
}

vector<vector<int>> permute(vector<int>& nums)
{
    backtrack(nums, 0);
    print(result);
    return result;
}


int main()
{
    vector<int> nums = {1,2,3};
    permute(nums);
    return 0;
}