#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[[1,1,6],[1,2,5],[1,7],[2,6]]
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

void backtrack(vector<int>& candidates, int target, vector<int>& sub, int index)
{
    if(target == 0)
    {
        result.push_back(sub);
    }
    if(target < 0) return;
    unordered_set<int> used;
    for(int i=index; i<candidates.size(); i++)
    {
        if(used.count(candidates[i]))  continue;
        used.insert(candidates[i]);
        // make choice
        sub.push_back(candidates[i]);
        // recursive call
        backtrack(candidates, target - candidates[i], sub, i+1);
        // undo
        sub.pop_back();
    }
}

vector<vector<int>>combinationSum2(vector<int>& candidates, int target)
{
    vector<int> sub;
    sort(candidates.begin(), candidates.end());
    backtrack(candidates, target, sub, 0);
    print(result);
    return result;

}

int main()
{
    vector<int>candidates = {10,1,2,7,6,1,5};
    int target = 8;
    combinationSum2(candidates, target);
    return 0;
}