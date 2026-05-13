#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input:  [[0,30],[5,10],[15,20]]
Output: false  
*/

bool meeting_room_1(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());
    for(int i=0; i<intervals.size()-1; i++)
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
    vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
    cout << meeting_room_1(intervals) << endl;
    return 0;
}