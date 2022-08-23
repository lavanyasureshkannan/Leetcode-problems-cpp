#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<vector<int>>spiralMatrixIII(int rows, int cols, int rstart, int cstart)
    {
        // initialize the output vector
        vector<vector<int>> result;
        // push the rstart and cstart to the result
        result.push_back({rstart,cstart});
        // total number of outcome arrays
        int total_counts = rows * cols;
        // create 4 possible directions -> control flow inside the matrix
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        // length and direction_cell
        int len = 0;
        int d = 0;
        while(result.size() < total_counts)
        {
            if(d == 0 || d==2) len++; // checking if the d is facing towards the east
            for(int i=0; i<len; i++)
            {
                rstart += directions[d][0];
                cstart += directions[d][1];
                // Even there is a chance of getting out of the boundary
                if(rstart>=0 && rstart< rows && cstart>=0 && cstart<cols)
                {
                    result.push_back({rstart,cstart});
                }
            }
            d = (d+1)%4; // getting the mod val and updating the d cell which means moving towards the west
        }
        return result;
    }
};
