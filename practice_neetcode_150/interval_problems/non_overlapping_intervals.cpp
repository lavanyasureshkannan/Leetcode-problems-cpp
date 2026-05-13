#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
Input: intervals = [[1,2],[2,4],[1,4]]
Output: 1
*/

int non_overlapping(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());
    int result = 0;
    int curr_start = intervals[0][0];
    int curr_end = intervals[0][1];
    for(int i=1; i<intervals.size(); i++)
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
    vector<vector<int>> intervals = {{1,2},{2,4},{1,4}};
    cout << non_overlapping(intervals);
    return 0;
}