#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        void moveZeroes(vector<int>& nums) 
        {
            int j = 0;
            for (int i = 0; i<nums.size(); i++)
            {
                if(nums[i] !=0)
                {
                    swap (nums[i], nums[j]);
                    j++;
                }
            }
        }
};


// TIME COMPLEXITY O(N)
// SPACE COMPLEXITY O(1)



// TIME COMPLEXITY - O(N)
// SPACE COMPLEXITY O(1)

// TC: O(N)
// SC: O(1) 




int main()
{
    return 0;
}