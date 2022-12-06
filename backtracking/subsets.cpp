#include<iostream>
#include<vector>
using namespace std;

// BACKTRACKING


class Solution
{
    public:
    vector<vector<int>> result;
    void helper(int index, vector<int>& current, vector<int>& nums)
    {
        result.push_back(current);
        for(int i=index; i<nums.size(); i++)
        {
            // add the current element
            current.push_back(nums[i]);
            // get their subsets
            helper(i+1, current , nums);
            // as it is been used pop it
            current.pop_back();

        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int> current;
        helper(0,current,nums);
        return result;
    }
};

// TC: O(N * 2^N)
// SC: O(N * 2^N)

int main()
{
    return 0;
}