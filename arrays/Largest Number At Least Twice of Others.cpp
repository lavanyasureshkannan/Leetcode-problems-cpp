#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int dominantIndex(vector<int>& nums) 
    {
        // std::max_element is defined inside the header file and it returns an iterator pointing to the element 
        // with the largest value in the range [first, last). 
        int maxi = *max_element(nums.begin(), nums.end());
        int max_idx = 0;
        
        // finding the index of the maximum element
        for(int i =0; i<nums.size(); i++)
        {
            if(nums[i] == maxi){
                max_idx = i;
            }
        }
        for(int i =0; i< nums.size(); i++)
        {
            if(2* nums[i] > maxi && i != max_idx)
            {
                return -1;
            }
        }
        return max_idx;
    }
};
