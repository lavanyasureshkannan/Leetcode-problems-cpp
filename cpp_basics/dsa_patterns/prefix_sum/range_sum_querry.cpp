#include <iostream>
#include <vector>
using namespace std;

/*
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]
*/

class NumArray
{
    public:
    vector<int> v;
    NumArray(vector<int>& nums)
    {
        v = nums; 
    }
    int range_sum(int left, int right)
    {
        int result = 0;
        result = result + v[left];
        for(int i=left+1; i<=right; i++)
        {
            result = result + v[i]; 
        }
        return result;
    }
};

// CONSTRUCTOR
// Copies an entire array
// TC: O(N)
// SC: O(N) 

// FUNCTION
// TC: O(N)
// SC: O(1)

int main()
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray na1(nums);
    cout << na1.range_sum(0, 5) << endl; 
    return 0;
}