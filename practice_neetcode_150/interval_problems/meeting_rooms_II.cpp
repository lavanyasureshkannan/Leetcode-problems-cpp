#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
Input: intervals = [(0,30),(5,10),(15,20)]
Output: 2
*/

int meeting_rooms(vector<vector<int>>& intervals)
{
    if(intervals.size() == 0) return 0;
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> pq; // keeep track of the end time
    pq.push(intervals[0][1]);
    for(int i=1; i<intervals.size(); i++)
    {
        int start_time = intervals[i][0];
        int end_time = intervals[i][1];
        if(start_time >= pq.top()) // pq.top -> smallest end time
        {
            pq.pop();
        }
        pq.push(end_time);
    }
    return pq.size();
}

int main()
{
    vector<vector<int>> inetrvals = {{0,30},{5,10},{15,20}};
    cout << meeting_rooms(inetrvals) << endl;
    return 0;
}