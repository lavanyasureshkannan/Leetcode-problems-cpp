#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


// class Solution {
// public:
//     int calculate(string s) {
        
//     }
// };

class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        // both the strings should have the same length
        if (s.length() != t.length())
        {
            return false;
        }
        // sort the elements ans see if they are equal
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        // iterate and see of it is equal
        for (int i =0; i<s.size(); i++)
        {
            if (s[i] != t[i])
                return false;
        }
        return true;
        
    }
};


// TC: O(N Log n) Assume that nn is the length of ss, sorting costs O(n \log n)O(nlogn) and comparing two strings costs O(n)O(n). Sorting time dominates and the overall time complexity is O(n \log n)O(nlogn).
// SC: O(1) Space depends on the sorting implementation 