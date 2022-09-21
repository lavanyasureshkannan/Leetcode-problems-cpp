#include<iostream>
#include<vector>
#include<set>
using namespace std;


class Solution
{
    public:
    void backtrack(int index, vector<int>& nums, set<vector<int>>& st)
    {
        // check if the index is equal to the array size
        if(index == nums.size())
        {
            st.insert(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            backtrack(index+1, nums, st);
            swap(nums[index], nums[i]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        set<vector<int>>st;
        backtrack(0, nums, st); // (index, array)
        vector<vector<int>> result(st.begin(),st.end());
        return result;
    }
};


// TC: O(N!)
// SC: O(N)
int main()
{
    return 0;
}