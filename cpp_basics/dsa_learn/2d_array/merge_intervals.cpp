#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
*/

vector<vector<int>> merge_intervals(vector<vector<int>>& intervals)
{
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());
    int curr_start = intervals[0][0];
    int curr_end = intervals[0][1];
    for(int i=1;i <intervals.size(); i++)
    {
        if(curr_end >= intervals[i][0])
        {   
            curr_end = max(curr_end, intervals[i][1]);
        }
        else
        {
            result.push_back({curr_start, curr_end});
            curr_start = intervals[i][0];
            curr_end = intervals[i][1];
        }
    }
    result.push_back({curr_start, curr_end});
    return result;
}

int main()
{
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = merge_intervals(intervals);
    for(int i=0; i<result.size(); i++)
    {
        for(int j=0; j<result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0; 
}
