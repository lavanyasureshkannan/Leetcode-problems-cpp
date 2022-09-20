#include<iostream>
#include<unordered_map>
using namespace std;

int singleNumber(vector<int>& nums) 
{
    int result = 0;
    for (int i =0; i< nums.size(); i++)
    {
        result = result ^ nums[i];
    }
    return result;
}

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

int main()
{
    return 0;
}