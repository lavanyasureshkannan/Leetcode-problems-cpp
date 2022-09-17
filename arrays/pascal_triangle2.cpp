#include<iostream>
#include<vector>
using namespace std;


// DP
class Solution
{
    public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result(rowIndex+1, 1); // answer is going to be rowindex + 1
        for(int i= 1; i<rowIndex; i++) // row
        {
            for(int j=i; j>0; j--) // col 
            {
                result[j] = result[j] + result[j-1]; 
            }
        }
        return result;
    }

};

// TC: O(K^2) -> calculating row and col
// SC: O(K) -> No extra space
