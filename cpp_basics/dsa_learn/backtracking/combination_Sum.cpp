#include <iostream>
#include <vector>
using namespace std;

/*
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
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

void backtrack(vector<int>& candidates, int target, int index, vector<int>& sub)
{
    // base case
    if(target == 0)
    {
        result.push_back(sub);
    }
    if(target < 0) return;
    for(int i=index; i<candidates.size(); i++)
    {
        // make choice
        sub.push_back(candidates[i]);
        // bakctrack
        backtrack(candidates, target - candidates[i], i, sub);
        // undo
        sub.pop_back();
    }
    
}
vector<vector<int>> combination_sum(vector<int>& candidates, int target)
{
    vector<int> sub;
    backtrack(candidates, target, 0, sub);
    print(result);
    return result;
}

int main()
{
    vector<int>candidates = {10,1,2,7,6,1,5};
    int target = 8;
    combination_sum(candidates, target);
    return 0;
}