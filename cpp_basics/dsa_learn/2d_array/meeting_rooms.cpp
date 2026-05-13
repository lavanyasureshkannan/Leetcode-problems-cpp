#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
*/

bool meeting_rooms_1(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());
    int curr_begin = intervals[0][0];
    int curr_end = intervals[0][1];
    for(int i=1; i<intervals.size(); i++)
    {
        if(curr_end > intervals[i][0])
        {
            return false;
        }
        else
        {
            curr_begin = intervals[i][0];
            curr_end = intervals[i][1];
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> intervals = {{9, 10}, {10, 11}, {11, 12}};
    //{{0,30},{5,10},{15,20}};
    //[[9, 10], [10, 11], [11, 12]]
    cout << meeting_rooms_1(intervals) << endl;
    return 0;
}