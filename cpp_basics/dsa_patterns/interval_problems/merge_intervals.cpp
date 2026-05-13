#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
*/

void display(vector<vector<int>>& result)
{
    for(int i=0; i<result.size(); i++)
    {
        for(int j=0; j<result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> merge_intervals(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());
    int curr_begin = intervals[0][0];
    int curr_end = intervals[0][1];
    vector<vector<int>> result;
    for(int i=1; i<intervals.size(); i++)
    {
        if(intervals[i][0] <= curr_end)
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
    display(result);
    return result;
}

int main()
{
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    merge_intervals(intervals);
    return 0;
}