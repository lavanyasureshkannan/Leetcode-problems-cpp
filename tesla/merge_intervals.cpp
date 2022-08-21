#include<iostream>
#include<vector>
using namespace std;

/*
    MERGE INTERVALS
    intervals = [[1,3],[2,6],[8,10],[15,18]]

    Taking first two -> [1 2 3 6]

    input-> 2d array , output -> 2d array

    ALGORITHM
    1. sort the 2d array.
    2. create a new 2d array result 
    3. update this result by just comparing the elements in the array


*/

class Solution
{
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> results;
        // sort
        sort(intervals.begin(), intervals.end());
        // specify the curr_begin and curr_end
        int n = intervals.size();
        int curr_begin = intervals[0][0];
        int curr_end = intervals [0][1];

        for(int i =1; i<n; i++)
        {
            // condition to check the min and max values comparing 2 elements
            if(intervals[i][0] >= curr_begin && intervals[i][0] <= curr_end)
            {
                curr_begin = min(curr_begin, intervals[i][0]);
                curr_end = max(curr_end, intervals[i][1]);
            }
            else
            {
                results.push_back({curr_begin,curr_end});
                curr_begin = intervals[i][0];
                curr_end = intervals[i][1];
            }
        }
        // if it doesn't have a overlap you can just pushback the same element
        results.push_back({curr_begin,curr_end});
        return results;
    }
};

// TC: O(NlogN) -> Sorting, for loop
// SC: O(N) -> using result 

