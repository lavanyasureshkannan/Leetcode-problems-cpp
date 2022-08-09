#include<iostream>
#include<unordered_map>
using namespace std;


class Solution
{
    public:
    int subarraySum(vector<int>& nums, int k)
    {
        int result = 0;
        /*
            BRUTE FORCE APPROACH
            1. iterate over the array
            2. iterate again with the next element
            3. int sum -> updating
            4. iterate the subarray and check if it is going to be == k
        */
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<=nums.size(); j++)
            {
                int sum = 0;
                for(int sub = i; sub < j; sub++)
                {
                    sum = sum + nums[i];
                }
                if (sum == k) 
                {
                    result++;
                }
            }
        }

        return result;
    }
};
// TC: O(N^3)
// SC: O(1)



class Solution
{
    public:
    int subarraySum(vcetor<int>& nums, int k)
    {
        int result = 0;
        /*
            UNORDERED MAP APPROACH
            1. create an unordered map
            2. if sum == k update the count
            3. keep track of the (sum -k) part either 0 or k
        */
        int sum=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size(); i++)
        {
            sum = sum + nums[i];
            if(sum == k) result ++;
            if(mp.count(sum-k)) result = result + mp[sum-k];
            mp[sum]++;
        }

        return result;  
    }
}

// TC: O(N)
// SC : O(N)
int main()
{
    return 0;
}