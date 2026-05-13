#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
    Output: 0
    Explanation:
    - At time 0, both rooms are not being used. The first meeting starts in room 0.
    - At time 1, only room 1 is not being used. The second meeting starts in room 1.
    - At time 2, both rooms are being used. The third meeting is delayed.
    - At time 3, both rooms are being used. The fourth meeting is delayed.
    - At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
    - At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
    Both rooms 0 and 1 held 2 meetings, so we return 0. 
*/

int meeting_rooms(vector<vector<int>>& meetings, int n)
{
    // 1. sort the meetings
    sort(meetings.begin(), meetings.end());
    // 2. create pq for free rooms
    priority_queue<int, vector<int>, greater<int>> free_rooms;
    for(size_t i=0; i<n; i++)
    {
        free_rooms.push(i); // (0,1)
    }
    // 3. create a pq for busy rooms => [end_time, room_ids]
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy_rooms;
    vector<int> count(n,0);

    for(auto &m : meetings)
    {
        long long start = m[0];
        long long end = m[1];
        long long duration = end - start;

        // a. free up the rooms
        while(!busy_rooms.empty() && busy_rooms.top().first <= start) // 
        {
            free_rooms.push(busy_rooms.top().second); //earliest end time among busy rooms
            busy_rooms.pop();
        }
        // b. assign rooms
        if(!free_rooms.empty())
        {
            int room = free_rooms.top(); // 0
            free_rooms.pop(); // 0 -> now busyrooms {1}

            busy_rooms.push({end,room}); // (0,10)
            count[room] ++;
        }
        // c. delay the case
        else
        {
            auto[free_time, room] = busy_rooms.top();
            busy_rooms.pop();
            long long new_end = duration + free_time;
            busy_rooms.push({new_end, room});
            count[room] ++;
        }
    }
    int max_rooms = 0;
    for(int i=0; i<n; i++)
    {
        if(count[i] > count[max_rooms])
        {
            max_rooms = i;
        }
    }
    return max_rooms;

}


int main()
{
    int n = 2;
    vector<vector<int>> meetings = {{0,10},{1,5},{2,7},{3,4}};
    cout << meeting_rooms(meetings, n) << endl;
    return 0;
}