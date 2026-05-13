#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
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

void backtrack(int index, vector<int>& nums, vector<int>& sub, vector<vector<int>>& result)
{
    result.push_back(sub);
    for(int i=index; i<nums.size(); i++)
    {
        sub.push_back(nums[i]);
        backtrack(i+1, nums, sub, result);
        sub.pop_back();
    }
}

vector<vector<int>> subset(vector<int>& nums)
{
    vector<vector<int>> result;
    vector<int> sub;
    backtrack(0, nums, sub, result);
    display(result);
    return result;

}

int main()
{
    vector<int> nums = {1,2,3};
    subset(nums);
    return 0;
}