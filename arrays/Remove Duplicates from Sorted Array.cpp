#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int count = 1;
        // TOW POINTERS APPROACH
        for(int i = 1; i< nums.size(); i++)
        {
            if (nums[i-1] != nums[i])
            {
                nums[count] = nums[i];
                count++;   
            }
        }
        return count;
    }
};

// TIME COMPLEXITY - O(N)
// SPACE COMPLEXITY O(1)

// TC: O(N)
// SC: O(1) 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int count = 1;
        // TOW POINTERS APPROACH
        for(int i = 1; i< nums.size(); i++){
            if (nums[i-1] != nums[i])
            {
                nums[count] = nums[i];
                count++;   
            }
        }
        return count;
    }
};

// TIME COMPLEXITY - O(N)
// SPACE COMPLEXITY O(1)

int removeDuplicates(vector<int>& nums)
{
    unordered_set<int> s;
    for(int i=0; i<nums.size(); i++)
    {
        s.insert(nums[i]);
    }
    return s.size();
}


int main()
{
    return 0;
}
