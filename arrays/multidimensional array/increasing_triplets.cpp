#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// nums = [1,2,3,4,5]

bool increasingTriplets(vector<int>& nums)
{
    int first = INT_MAX;
    int second = INT_MAX;
    for(int i : nums)
    {
        if(i <= first)
        {
            first = i;
        }
        else if(i <= second)
        {
            second = i;
        }
        else
        {
            return true;
        }
    }
    return false;

}


// TC: O(N)
// SC: O(1)