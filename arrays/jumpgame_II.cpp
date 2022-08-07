#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    // simple bfs by creating and updating the window
    // [2,3,1,1,4-] 
    int jump(vector<int>& nums)
    {
        int jumps = 0; // number of counts
        int left = 0; 
        int right = 0; // windows

        while(right < nums.size() -1) // loop in till right reaches the last element
        {
            int farthest = 0;
            for(int i = left; i<right+1; i++)
            {
                farthest = max(farthest, i+nums[i]) // max of farthest and max of the jump we are curretnly performing which tells how far we can travel
                // update the window
            }
            left = right + 1;
            right = farthest;
            jumps += 1;
        }
    }
    return jumps;
};

// TC: O(N)
// SC: O(1)