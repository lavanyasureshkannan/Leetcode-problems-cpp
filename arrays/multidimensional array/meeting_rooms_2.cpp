#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;


int minMeetingRooms(vector<vector<int>>& intervals)
{
    
    // create two arrays to save the start and end timings
    vector<int> start;
    vector<int> end;

    for(int i=0; i<intervals.size(); i++)
    {
        start.push_back(intervals[i][0]);
        end.push_back(intervals[i][1]);
    }
    sort(start.begin(), start.end()); // [0 5 10]
    sort(end.begin(), end.end()); // [10 15 30]
    // keep two pointers and check if (0 < 10) if yes then count++ then shift the pointer
    int s_ptr = 0;
    int e_ptr = 0;

    int count = 0; // number of meetings thats been going on
    int result = 0;
    while(s_ptr < intervals.size())
    {
        if(start[s_ptr] < end[e_ptr]) 
        {
            s_ptr = s_ptr + 1;
            count = count + 1;
        }
        else
        {
            e_ptr = e_ptr + 1;
            count = count - 1;
        }
        result = max(result, count);

    }
    cout << result;
    return result;

}


// TC: O(N logN)
// SC: O(N)

int main()
{
    vector<vector<int>> a = {{5,10},{10,15},{0,30}};
    minMeetingRooms(a);
    return 0;
}
