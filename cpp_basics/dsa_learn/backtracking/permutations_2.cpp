#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
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
    if(nums.size() == index)
    {
        result.push_back(nums);
    }
    unordered_set<int> used;
    for(int i=index; i<nums.size(); i++)
    {
        if(used.count(nums[i])) continue;
        used.insert(nums[i]);
        // make choice
        swap(nums[index], nums[i]);
        // backtrack
        backtrack(nums,index+1);
        // undo
        swap(nums[index], nums[i]);
    }

}

vector<vector<int>> permutations_unique(vector<int>& nums)
{
    backtrack(nums,0);
    print(result);
    return result;
}

int main()
{
    vector<int> nums = {1,1,2};
    permutations_unique(nums);
    return 0;
}