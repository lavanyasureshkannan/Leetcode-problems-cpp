#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


class Solution
{
    // greedy APPROACH
    public:
    bool canJump(vector<int>& nums)
    {
        // 1. get the last element
        int lastElementIndex = nums.size()-1;
        // iterate from the last backwards
        for(int i = nums.size()-1; i>=0; i--)
        {
        // 3. check if you can reach the first element by jumping
        if(i + nums[i] >= lastElementIndex)
        {
            lastElementIndex = i;
        }
        }
        return lastElementIndex == 0;
        // return if the lastelement == 0

    }
};

// TC: O(n) --> single pass through nums 
// SC :o(1) --> no extra memory