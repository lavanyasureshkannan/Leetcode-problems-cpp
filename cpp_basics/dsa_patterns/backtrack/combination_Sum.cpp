#include <iostream>
#include <vector>
using namespace std;

/*
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
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
    display(result);
    return result;
}



int main()
{
    vector<int>candidates = {2,3,6,7};
    int target = 7;
    combination_Sum(candidates, target);
    return 0;
}