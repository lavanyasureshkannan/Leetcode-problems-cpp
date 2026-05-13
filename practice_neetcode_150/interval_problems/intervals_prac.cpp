#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
    INSERT INTERVALS
    Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
    Output: [[1,5],[6,9]]
*/

vector<vector<int>> insert_intervals(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end()); //[[1,3],[2,5],[6,9]]
    int curr_begin = intervals[0][0];
    int curr_end = intervals[0][1];
    vector<vector<int>> result;
    for(int i=1; i<intervals.size(); i++)
    {
        if(intervals[i][0] < curr_end)
        {
            curr_end = max(curr_end, intervals[i][1]);
        }
        else
        {
            result.push_back({curr_begin, curr_end});
            curr_begin = intervals[i][0];
            curr_end = intervals[i][1];
        }
    }
    result.push_back({curr_begin, curr_end});
    return result;
}

// TC: O(nlogn)
// SC: O(n)

/**************************************************************************************/
/*
    MERGE INTERVALS
    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
*/

vector<vector<int>> merge_intervals(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());
    int curr_begin = intervals[0][0];
    int curr_end = intervals[0][1];
    vector<vector<int>> result;
    for(int i=1; i<intervals.size(); i++)
    {
        if(intervals[i][0] < curr_end)
        {
            curr_end = max(curr_end, intervals[i][1]);
        }
        result.push_back({curr_begin, curr_end});
        curr_begin = intervals[i][0];
        curr_end = intervals[i][1];
    }
    result.push_back({curr_begin, curr_end});
    return result;
}

// TC: O(nlogN)
// SC: O(N)

/************************************************************************************/
/*
    Non overlapping elements
    Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
    Output: 1
*/

int non_overlaping_elements(vector<vector<int>>& intervals)
{
    int result = 0;
    sort(intervals.begin(), intervals.end()); // [[1,2],[1,3],[2,3],[3,4]]
    int curr_begin = intervals[0][0];
    int curr_end = intervals[0][1];
    for(size_t i=1; i<intervals.size(); i++)
    {
        if(intervals[i][0] < curr_end)
        {
            result ++;
            curr_end = min(intervals[i][i], curr_end);
        }
        else
        {
            curr_begin = intervals[i][0];
            curr_end = intervals[i][1];
        }
    }
    return result;
}
// TC: O(n log n) sorting + for loop
// SC: O(1)

/************************************************************************************/
/*
    MEETING ROOMS 1
    Input: intervals = [[0,30],[5,10],[15,20]]
    Output: false
*/

bool meeting_rooms_I(vector<vector<int>>& intervals)
{
    // base case
    if(intervals.empty()) return true;
    sort(intervals.begin(), intervals.end());
    int curr_begin = intervals[0][0];
    int curr_end = intervals[0][1];
    for(size_t i=1; i<intervals.size(); i++)
    {
        if(intervals[i][0] < curr_end) return false;
        else
        {
            curr_begin = intervals[i][0];
            curr_end = intervals[i][1];
        }
    }
    return true;
}

/****************************************************************************************/
/*
    Input: intervals = [[0,30],[5,10],[15,20]]
    Output: 2
*/

int meeting_room_II(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> pq; // prioritizes min value
    pq.push(intervals[0][1]);
    for(size_t i =1; i<intervals.size(); i++)
    {
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
    // vector<vector<int>> intervals = {{1,3},{6,9}};
    // vector<int> new_intervals = {2,5};

    //vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    
    // vector<vector<int>> intervals = {{1,2},{1,3},{2,3},{3,4}};
    // cout << non_overlaping_elements(intervals);

    // vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
    // cout << meeting_rooms_I(intervals) << endl;
    
    vector<vector<int>>intervals = {{0,30},{5,10},{15,20}};
    cout << meeting_room_II(intervals);


    // vector<vector<int>> result = merge_intervals(intervals);
    // for(int i=0; i<result.size(); i++)
    // {
    //     for(int j=0; j<result[i].size(); j++)
    //     {
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}