#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

// APPROACH 1
// case 1 - 1,2,3 --> Increase the last value by 1
// case 2 - 1,2,9 --> change 9 to 0
// case 3 - 9,9,9 --> change 9 to 0 and index goes out of range so add 1 to the beginning.

class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int index = digits.size() - 1;
        while (index >= 0) 
        {
            if (digits[index] == 9)
            {
                digits[index] = 0;
            }
            else
            {
                digits[index]+=1;
                return digits;
            }
            index --;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};