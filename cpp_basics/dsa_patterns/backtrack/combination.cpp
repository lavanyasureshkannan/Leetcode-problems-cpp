#include <iostream>
#include <vector>
using namespace std;

/*
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
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
class Solution
{
    public:
    vector<vector<int>> result;

    void backtrack(vector<int>& path, int n, int k, int start)
    {
        if(path.size() == k)
        {
            result.push_back(path);
        }
        // get all posibilities from  start
        for(int i=start; i<=n; i++)
        {
            path.push_back(i);
            backtrack(path, n, k, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinations(int n, int k)
    {
        vector<int> path;
        backtrack(path, n, k, 1);
        return result;
    }

};

int main()
{
    Solution s1;
    vector<vector<int>> result = s1.combinations(4,2);
    display(result);
    return 0;
}