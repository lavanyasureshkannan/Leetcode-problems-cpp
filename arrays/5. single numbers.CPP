136. SINGLE NUMBERS

APPROACH 1

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        sort(nums.begin(),nums.end());
        if(nums[0] != nums[1]) return nums[0];
        for(int i = 1; i < (n-1); i++){
            if (nums[i-1] != nums[i] && nums[i] != nums[i+1]) 
                return nums[i];
        }
        return nums[n-1];
    } 
    
};

APPROACH 2 - USING BITWISE XOR OPERATOR
(n^0= n
n^n =0)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i =0; i< nums.size(); i++){
            result = result ^ nums[i];
        }
        return result;
    }
    
};

class Solution
{
    public:
    int singleNumber(vector<int>& nums)
{
    int result = 0;
    unordered_map<int,int> mp;
    for(int i=0; i<nums.size(); i++)
    {
        mp[nums[i]] ++; 
    }
    for(auto i : mp)
    {
        if(i.second == 1) 
        {
            result = i.first;
            break;
        } 
    }

    return result;
}
};
// TC: O(N)
// SC:O(N)
