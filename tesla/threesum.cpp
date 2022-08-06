#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        // Using set to make sure that there are no duplicates
        set<vector<int>>result;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j= i+1; j<nums.size();j++)
            {
                for (int k = j+1; k<nums.size(); k++)
                {
                    if(nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> a = {nums[i],nums[j], nums[k]};
                        sort(a.begin(),a.end());
                        result.insert(a);
                    }
                }                
            }
        }
        vector<vector<int>> result_main(result.begin(),result.end());
        return result_main;
    }
};

// TC : O(N^3)
// SC : O(M (set)) + O(N(array))


// approach 2 : Two pointer technique
class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        int n = nums.size();
        // base case
        if (n<2)
            return {};
        sort(nums.begin(), nums.end());
        // iterate through the array, since it is twosum it should not go out of bound
        for (int i = 0; i< n - 2; i++)
        {
            // to handle duplicates
            if(i ==0 || nums[i] != nums[i-1])
            {
                // setting two pointers in the lower and higher elements
                int j = i+1; //next element
                int k = n-1; // last element
                while(j<k)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == 0)
                    {
                        result.push_back({nums[i], nums[j], nums[k]});
                        // get rid of the duplicates
                        while(j<k && nums[j]==nums[j+1]) j++;
                        while(j<k && nums[j]==nums[k-1]) k--;
                        j++;
                        k--;
                    }
                    // if the sum goes beyond then adjust the boundaries
                    else if (sum<0)
                        j++;
                    else
                        k--;
                }
                
            }
        }
            return result;   
    }
};

// TC:O(N^2) -> for(two sum tow pointer)
// SC : O(nlogn) ->implementation of sorting algorithm