#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

void backtrack(vector<vector<int>>& res, vector<int>& path, vector<int>& num, vector<bool>& visited)
{
    if(path.size() == num.size())
    {
        res.push_back(path);
    }
    for(int i=0; i<num.size(); i++)
    {
        if(visited[i]) continue;
        visited[i] = true;
        path.push_back(num[i]);
        backtrack(res,path,num,visited);
        path.pop_back();
        visited[i] = false;
    }
}

vector<vector<int>> permutations(vector<int>& nums)
{
    vector<int> paths;
    vector<vector<int>> result;
    vector<bool> visited(nums.size(), false);
    backtrack(result, paths, nums, visited);
    return result;
}

int main()
{
    return 0;
}