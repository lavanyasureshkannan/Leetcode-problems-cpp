#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int len = strs.size();
        
        if(len == 0)
            return "";
        
        sort(strs.begin(),strs.end());
        string prefix;
        string first = strs[0];
        string last = strs[len -1];
        
        for(int i = 0; i < first.size(); i++)
        {
            if(first[i] ==last[i])
            {
                prefix = prefix + first[i];
            }
            else
                break;
            
            
        }
        return prefix;
        
    }
};

// TC: O(N)
// SC: O(1)
