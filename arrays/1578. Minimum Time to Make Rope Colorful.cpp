#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        int total_time = 0;
        // iterate through the string
        for(int i=0; i<colors.length(); i++)
        {
            if(colors[i] == colors[i+1])
            {
                if(neededTime[i] > neededTime[i+1])
                {
                    swap(neededTime[i],neededTime[i+1]);
                }
                total_time = total_time + min(neededTime[i], neededTime[i+1]);
            }
        }

        return total_time;
    }

};

// TC : O(N)
// SC : O(1)