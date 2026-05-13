#include <iostream>
#include <vector>
using namespace std;

/*
    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

*/

void display(vector<vector<int>>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=0; j<nums[i].size(); j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

void backtrack(vector<int>& nums, vector<int>& paths, vector<bool>& visited, vector<vector<int>>& result)
{
    if(paths.size() == nums.size())
    {
        result.push_back(paths);
    };
    for(int i=0; i<nums.size(); i++)
    {
        if(visited[i]) continue;
        visited[i] = true;
        paths.push_back(nums[i]);
        backtrack(nums, paths, visited, result);
        paths.pop_back();
        visited[i] = false;
    }
}
vector<vector<int>> permutations(vector<int>& nums)
{
    vector<vector<int>> result;
    vector<int> paths;
    vector<bool> visited(nums.size(), false);
    backtrack(nums,paths,visited, result);
    display(result);
    return result;
}


int main()
{
    vector<int> nums = {1,2};
    permutations(nums);
    return 0;
}