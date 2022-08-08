#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
	string maxValue(string n, int x) 
    {
        string ans;
        int flag = 0;

        // if string is positive
        if(n[0] != '-')
        {                  
            // iterate through the string
            for(int i=0;i<n.length();i++)
            {
                // check if the value of x is > the curr char
                if(x > (n[i]-'0') && flag==0)
                {                    
                    char c = '0' + x;
                    ans.push_back(c);
                    flag = 1;
                }
                ans.push_back(n[i]);
            }

            if(flag==0) ans.push_back(('0' + x));
        }
        else
        {              
            // when string is negetive
            ans.push_back('-');
            for(int i=1;i<n.length();i++)
            {
                if(x < (n[i]-'0') && flag==0)
                {
                    char c = '0' + x;
                    ans.push_back(c);
                    flag = 1;
                }
                ans.push_back(n[i]);
            }
            if(flag==0) ans.push_back(('0'+ x));
        }
        return ans;
    }
};

// TC: O(N)
// SC: O(1)