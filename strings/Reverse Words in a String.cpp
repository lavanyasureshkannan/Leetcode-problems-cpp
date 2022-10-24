#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    string reverseWords(string s)
    {
        // since its an inplace operation return the same string
        // reverse the entire string
        reverse(s.begin(), s.end());
        int n = s.size();
        // keep track of the begining index
        int idx = 0;
        // then iterate over and find " "
        for(int start = 0; start<n; start++)
        {
            if(s[start] != ' ')
            {
                // go to the begining of the word
                if(idx != 0)
                {
                    s[idx++] = ' ';
                }
                // go to the end of the word
                int end = start;
                // check for the boundary 
                while(end < n && s[end] != ' ') 
                {
                    s[idx++] = s[end++];
                }
                // reverse the word
                reverse(s.begin() + idx - (end - start), s.begin()+idx);
                // move to the next word
                start = end;
            }
        }
        s.erase(s.begin()+idx, s.end());
        return s;
    }
};