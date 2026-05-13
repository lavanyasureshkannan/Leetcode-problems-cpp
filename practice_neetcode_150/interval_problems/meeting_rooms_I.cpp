#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: intervals = [(0,30),(5,10),(15,20)]
Output: false
*/

bool meeting_room(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());
    for(int i=1; i<intervals.size(); i++)
    {
        if(intervals[i][1] > intervals[i+1][0])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<vector<int>>intervals = {{0,30},{5,10},{15,20}};
    cout << meeting_room(intervals) << endl;
    return 0;
}