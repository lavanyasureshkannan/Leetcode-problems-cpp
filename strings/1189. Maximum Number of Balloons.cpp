#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;




class Solution
{
    public:
    int maxNumberOfBalloons (string s)
    {
        int count_b = 0;
        int count_a = 0;
        int count_l = 0;
        int count_o = 0;
        int count_n = 0;

        // iterate through the array and count the frequency
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == 'b') count_b++;
            else if (s[i] == 'a') count_a++;
            else if(s[i] == 'l') count_l++;
            else if(s[i] == 'o') count_o++;
            else if(s[i] == 'n') count_n++;
        }

        // finding the potential of each character
        count_l = count_l/2;
        count_o = count_o /2;

        return min({count_b,count_a,count_o,count_l,count_n});    
    }
};


// TC:  O(N) We iterate over all the characters of string text which requires NN operations.
// SC: O(1) All we need is the 55 variables to store the frequency of characters. Hence the space complexity is constant.

