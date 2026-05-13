#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


/*
Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
*/

int meeting_rooms(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> pq; // have min heap to add the end time of the meetings
    pq.push(intervals[0][1]);
    for(int i=1; i<intervals.size(); i++)
    {
        // check if the next meeting start_time > end time of the prev meeting
        int start_time = intervals[i][0];
        int end_time = intervals[i][1];
        if(start_time >= pq.top())
        {
            pq.pop();
        }
        pq.push(end_time);
    } 
    return pq.size();
}

int main()
{
    vector<vector<int>> intervals = {{0,30},{15,20}, {5,10}};
    cout << meeting_rooms(intervals) << endl;
    return 0;
}