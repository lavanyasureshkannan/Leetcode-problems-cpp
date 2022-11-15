Maximum Subarray

// DP
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sub = nums[0];
        int curr_sum = 0;
        for(int i =0; i<nums.size(); i++){
            if (curr_sum < 0){
                curr_sum = 0;
            }
            curr_sum += nums[i];
            max_sub = max(max_sub, curr_sum);
            
        }
        return max_sub;
    }
};

// TC: O(N)
// SC: O(1)

int max_sub_array(vector<int>& nums)
{
    int result = INT_MAX;
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=i+1; j<nums.size(); j++)
        {
            int sum =0;
            for(int sub = i; sub < j; sub++)
            {
                sum = sum + nums[sub];
            }
            result = max(result, sum);
        }
    }
    return result;
}
// TC: O(N^2)
// SC: O(1)
