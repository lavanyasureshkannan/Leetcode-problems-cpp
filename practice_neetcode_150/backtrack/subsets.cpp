#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

void print(vector<vector<int>>& nums)
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


void helper(vector<int>& nums, vector<int>& sub, vector<vector<int>>& result, int index)
{
    result.push_back(sub);
    for(int i=index; i<nums.size(); i++)
    {
        sub.push_back(nums[i]);
        helper(nums,sub,result, i+1);
        sub.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> result;
    vector<int> sub;
    helper(nums, sub, result, 0);
    print(result);
    return result;
}

int main()
{
    vector<int> nums = {1,2,3};
    subsets(nums);
    return 0; 
}