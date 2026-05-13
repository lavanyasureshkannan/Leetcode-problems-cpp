#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1

Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

[[-52,31],[-73,-26],[82,97],[-65,-11],[-62,-49],
[95,99],[58,95],[-31,49],[66,98],[-63,2],[30,47],[-40,-26]]
*/


int non_overlapping_intervals(vector<vector<int>>& intervals)
{
    int result = 0;
    sort(intervals.begin(), intervals.end());
    int curr_start = intervals[0][0];
    int curr_end = intervals[0][1];
    for(int i=1; i < intervals.size(); i++)
    {
        if(curr_end > intervals[i][0])
        {
            result ++;
            curr_end = min(curr_end, intervals[i][1]);
        }
        else
        {
            curr_start = intervals[i][0];
            curr_end = intervals[i][1];
        }
    } 
    return result;
}


int main()
{
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout << non_overlapping_intervals(intervals) << endl;
    return 0;
}