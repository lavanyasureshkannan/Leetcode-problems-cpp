#include<iostream>
#include<vector>
#include<string>
using namespace std;

//344. Reverse String
//Approach 1

class Solution 
{
public:
    void reverseString(vector<char>& s) 
    {
        vector <char>result;
        int size = s.size();
        for(int i = size -1; i>=0 ; i--)
        {
            result.push_back(s[i]);
        }
        s = result;
        
    }
};

// APPROCH 2 :
// 2pointer swap

class Solution 
{
    public:
    void reverseString(vector<char>& s) 
    {
        int left = 0;
        int right = s.size() -1;
        while (left < right)
        {
            swap(s[left++],s[right--]);
            
        }
        
    }
};

//TC: O(N)
// SC: O(1)