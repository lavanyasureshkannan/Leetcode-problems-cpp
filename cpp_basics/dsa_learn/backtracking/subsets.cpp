#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
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
void backtrack(vector<int>& nums, int index, vector<int>& sub)
{
    result.push_back(sub);
    // base case
    if(index == nums.size()) return;
    for(int i=index; i<nums.size(); i++)
    {
        //make choice
        sub.push_back(nums[i]);
        // backtrack
        backtrack(nums, i+1, sub);
        // undo
        sub.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<int> sub;
    backtrack(nums,0,sub);
    return result;
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = subsets(nums);
    print(result);   
    return 0;
}