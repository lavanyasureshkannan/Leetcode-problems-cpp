#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


// class Solution {
// public:
//     int calculate(string s) {
        
//     }
// };

class Solution
{
    public:
    int largestPerimeter(vector<int>& nums)
    {
        int result = 0;
        // 1. perimeter of the triangle -> (a+b)>c, (b+c)>a, (c+a)>b
        // 2. sort the elements
        sort(nums.begin(),nums.end(), greater<int>()); // greater int to sort in descending order
        for(int i =0; i<nums.size() - 2; i++)
        {
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];
            // 3. check if the first three elements satisfy the above property if not check the rest
            if(((a+b)>c) && ((b+c)>a) && ((c+a)>b))
            {
                result = result + a + b + c;
                break;
            }
        }
        return result;
    }
};


// TC: O(NlogN), where NN is the length of nums.
// SC: O(1) 
