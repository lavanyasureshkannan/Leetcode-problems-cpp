#include<iostream>
#include<vector>
using namespace std;

// create your own sort function
// static bool comparator
// keep updating the reult string

class Solution
{
    public:
    static bool compare(int a, int b)
    {
        // convert int into string
        string x = to_string(a);
        string y = to_string(b);
        return ((x+y) > (y+x));
    } 
    string LargestNumber(vector<int>& nums)
    {
        int n = nums.size();
        string result = "";
        // sort the elements and compare it simulataneosuly
        sort(nums.begin(), nums.end(), compare);
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[0] == 0) return "0";
            result = result + to_string(nums[i]);
        }
        return result;
    }
};

// TC: O(NlogN) -> you are using a comaprator
// SC: O(N) -> to store the new string