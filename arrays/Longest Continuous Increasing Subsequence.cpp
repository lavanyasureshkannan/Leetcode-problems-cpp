#include<iostream>
#include<vector>
using namespace std;



// sliding window kind of approach
int findLengthOfLCIS(vector<int>& nums) 
{
        int curr_sum = 0;
        int window = 0;

        for(int i=0; i<nums.size(); i++)
        {
            // checking i>0 else it goes out of bounce
            if(i>0 && nums[i-1] >= nums[i]) 
            {
                window = i;
            }
            curr_sum = max(curr_sum, i - window + 1);
        }
        return curr_sum;    
}

// TC: O(N)
// SC: O(1)


int main()
{
    
    vector<int> nums = {1,3,5,4,7};
    cout << findLengthOfLCIS(nums);
    return 0;
}