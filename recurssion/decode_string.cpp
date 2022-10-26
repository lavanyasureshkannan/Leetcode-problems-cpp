#include<iostream>
#include<vector>
#include<numeric>
#include<stack>
#include<queue>
using namespace std;

class Solution
{
    string helper(string& s, int& i)
    {
        string result;
        while(i < s.length() && s[i] != ']')
        {
            if(isdigit(s[i]))
            {
                int k = 0; // for digits greater than one 
                while(i < s.length() && isdigit(s[i]))
                    k =  k*10 + s[i++] - '0';
                i++;
                string r = helper(s,i);
                while(k-- > 0)
                {
                    result += r;    
                }
                i++;
            }
            else
            {
                result += s[i++];
            }
        }
        return result;
    }
    public:
    string decodeString(string s)
    {
        int i = 0;
        return helper(s,i);
    }
};

// TC: O(maxK⋅n) 
// S C: O(n)