#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int dominantIndex(vector<int>& nums) 
    {
        // library function to find the maximum element int the array
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