#include<iostream>
using namespace std;

class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {
        
        int hay_len = haystack.length();
        int need_len = needle.length();
        int i = 0;
        int j = 0;
        for(i=0; i<= (hay_len-need_len); i++)
        {
            for(j =0; j < need_len; j++)
            {
                if(haystack[i+j] != needle[j])
                    break;
            }
            if (j == need_len)
            {
                return i;
            
            }
        }
        return -1;
        
    }
};

// TC: O(n*m)
// SC: O(1) 