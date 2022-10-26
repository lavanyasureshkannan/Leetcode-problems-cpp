#include<iostream>
#include<vector>
#include<numeric>
#include<stack>
#include<queue>
#include<climits>
using namespace std;


class Solution
{
    public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result(rowIndex+1, 1); // answer is going to be rowindex + 1
        for(int i= 1; i<rowIndex; i++)
        {
            for(int j=i; j>0; j--)
            {
                result[j] = result[j] + result[j-1]; 
            }
        }
        return result;
    }

};