#include<iostream>
#include<string.h>
using namespace std;
 

// EXPAND FROM MIDDLE METHOD
// whenever we solve palindrom we come across two edge cases
// 1. bba  abb    2.racecar -> both the left and right pointers should start from same index  
//      l  r 

class Solution 
{
    public:
    string longestPalindrome(string s) 
    {
        string str;
        int max_len = 0;
        // inorder to keep track of the boundaries 
        int start = 0;
        // base case
        if(s.length == 0) return 0;

        // iterate over the string
        for(int i=0; i<s.length(); i++)
        {    
            int len1 = expandFromCenter(s,i,i); // racecar
            int len2 = expandFromCenter(s,i,i+1); // aabbaa

            // setting boundaries for new longest palindrome
            if(max_len < max(len1,len2))
            {
                max_len = max(len1,len2);
                // so now we are at the center we should find the starting index
                start = i-(max_len-1)/2;
            }  
        }
        return s.substr(start,len);   
    }
    int expandFromCenter(string &s, int left,   int right)
    {
        // 2 pointer template where we are expanding from the middle and keep increasing if both the values at the pointers are same
        while(left >= 0 && right<s.length() && s[left]==s[right])
        {
            left--;
            right++;
        } 
        return right-left-1;
    }
};

// TC: O(N^2) ->exapnding both sides  at O(N) each ways
// SC: O(1) 