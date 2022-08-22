#include<iostream>
#include<vector>
using namespace std;

/*
    TOP DOWN MEMOIZATION APPROACH - DP
    1. To have base case indicating it doesn't go out of boundary
    2. use tow pointers one at s and the other at p 
    3. If (*) then make two decisions 
        -> either to use it and see the result
        -> not to use and see the result
    4. Compare the results with the s and keep updating the pointer. 
*/

// without cache
class Solution 
{
public:
    bool isMatch(string s, string p)
    {
        return helper(s,p,0,0);
    }
    
    bool helper(string s, string p, int i, int j)
    {
        // checking out of bounce for both i, j 
        if(i >= s.length() && j >=p.length()) return true;
        // checking out of bounce for j 
        if(j >= p.length()) return false;

        bool first_match = (i<s.length() && (s[i]==p[j] || p[j]=='.' ));
        
        if(j+1<p.length() && p[j+1]=='*')
        {
            return (helper(s,p,i,j+2)|| (first_match && helper(s,p,i+1,j) ));
        }
        else
        {
            return (first_match && helper(s,p,i+1,j+1));
        }
    }
};

// wuth cache
class Solution 
{
public:
    bool helper(string s, string p, int i, int j, vector<vector<int>>& dp)
    {
        // base case
        if(dp[i][j] != -1) return dp[i][j];
        // base case 1 => both are out of bounce
        if(i >= s.length() && j >= p.length()) 
        {
            return dp[i][j] = true;
        }
        // base case 2 => when j is out of bounce
        if(j >= p.length())
        {
            return dp[i][j] = false;
        }
        // check for "."
        bool match = i < s.length() && ((s[i] == p[j]) || (p[j] == '.'));

        if(p[j+1] == '*') 
        {
            //                      dont use '*'                    use '*'
            return dp[i][j] = (match && helper(s, p, i+1, j, dp)) || helper(s, p, i, j+2, dp);
        }

        return dp[i][j] = (match && helper(s, p, i+1, j+1, dp));
    }
    bool isMatch(string s, string p) 
    {
        // keep track of cache to improve the tc
        vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1, -1));
        return helper(s, p, 0, 0, dp);
    }
};