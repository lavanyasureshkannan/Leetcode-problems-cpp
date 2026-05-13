#include <iostream>
#include <vector>
using namespace std;

/*
nums = [2,5,6,9]
target = 9

Output: [[2,2,5],[9]]
*/

void backtrack(int index, vector<vector<int>>& result, vector<int>& paths, vector<int>& candidates, int target)
{
    if(target == 0)
    {
        result.push_back(paths);
        return;
    }
    if(target < 0) return;
    for(int i=index; i<candidates.size(); i++)
    {
        // candidates[i] + x = target
        // x = target - candidates[i]
        paths.push_back(candidates[i]);
        backtrack(i, result, paths, candidates, target - candidates[i]);
        paths.pop_back();
    }   
}

vector<vector<int>> combination_Sum(vector<int>& candidates, int target)
{
    vector<vector<int>> result;
    vector<int> paths;
    backtrack(0, result, paths, candidates, target);

    return result;
}
int main()
{
    vector<int>nums = {2,5,6,9};
    int target = 9;
    vector<vector<int>> result = combination_Sum(nums, target);
    return 0;
}