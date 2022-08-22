#include<iostream>
#include<vector>
using namespace std;

/*
    1. Scan through the array and and try to find 1 -> if yes break if not found then return 1;
    2.  base case -> if the size of the array == 1 then return n+1 = 2;
    3. iterate through the array and find if the number is negative or more than the size and mark it as 1 (the number which is replaced)
    4. comapre the indexes with the values as the values can be appear from (1 to n) and the indexes can be from 0 to n-1;
    5. (nums[i] - 1) => find the index and take the values in that index and make it negative


    ex: [2,3,6,-1,1]
    after 3rd step [2,3,1,1,1]
    after 4th and 5th step [-2, -3, -1, 1, 1] 
                           [0,   1,  2, 3, 4] idexes
    Here at index 3 the first poistive value occurs so i+1 => 3+1 =4  
*/

class Solution
{
    public:
    int firstMissingPositive(vector<int>& nums)
    {
        bool hasOne = false;
        for(int x : nums)
        {
            if(x == 1) 
            {
                hasOne = true;
                break;
            }
        }
        if(!hasOne) return 1;

        // base case
        int n = nums.size();
        if(n==1) return 2;

        for(int i=0; i<n; i++)
        {
            if(nums[i] > n || nums[i] <= 0) nums[i] = 1;
        }
        for(int i=0; i<n; i++)
        {
            int abs_val = abs(nums[i]);
            if(nums[abs_val-1] > 0) 
            {
                nums[abs_val-1] *= -1;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(nums[i] > 0) return (i + 1);
        }
        return n+1;
    }
};


// TC: O(N)
// SC: O(1)