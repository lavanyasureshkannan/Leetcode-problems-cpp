#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
value of Rth index(center) = frequency * index -(sum of indexes on the left)
                            = sum of indexes on the right - (frequency * index)
1. create a map<value, sum of indexes> 
*/

vector<long long> getDistance(vector<int>& nums)
{
    vector<long long> result;
    unordered_map<int, long long> mp;
    vector<int> frequency;
    // traversing right
    for(long i=0; i<nums.size(); i++)
    {
        int curr = nums[i];
        if(mp.find(curr) == mp.end())
        {
            mp.insert(curr, 0);
        }
        result[i] = result[i] + (i * (frequency[curr])) - mp.find(curr);
        mp.insert(curr, mp.insert(curr)+i);
    }
    // traversing through left




    return result;
}


class Solution 
{
    public:
    vector<long long> getDistances(vector<int>& arr) 
    {
        int n = arr.size();
        vector<long long>prefix(n,0);
        vector<long long>suffix(n,0);
        vector<long long>result(n,0);
        unordered_map<int,vector<int>>mp;
        
        // store index of the same elements.
        for(int i=0; i<n; i++)
        {
            mp[arr[i]].push_back(i);
        }
        // prefix will store the sum of absolute diff. from the starting index of current element to the current index.
        // pre[cur index]=pre[prev index]+ number of same elements before cur element * abs diff of cur element pos and pre element pos
        
        // iteratig towards right
        for(auto &p:mp)
        {
            auto vec = p.second;
            for(int i=1; i<vec.size(); i++)
                prefix[vec[i]] =  prefix[vec[i-1]]+  i*(long)(vec[i]-vec[i-1]);
        }

        // suffix will store the sum of absolute diff. from the ending index of current element to the current index.
        // same formula as above but in reverse order

        // iterting towards left
        for(auto &p:mp)
        {
            auto vec = p.second;
            for(int i=vec.size()-2;i>=0;i--)
            {
                suffix[vec[i]]=  suffix[vec[i+1]] + long(vec.size()-1-i) * (long)(vec[i+1]-vec[i]);
            }
        }
        for(int i=0; i<n; i++)
        {
            ans[i] += (prefix[i]+suffix[i]);
        }
        return result;
    }
};

// TC: O(N)
// SC: O(N)

int main()
{
    return 0;
}