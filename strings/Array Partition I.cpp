#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
    int arrayPairSum(vector<int>& nums) 
    {
        int sum=0;
        sort(nums.begin(),nums.end());
        for(int i=0; i <nums.size()-1; i+=2)
        {
            sum += nums[i];
        }
        return sum;
    }
};
