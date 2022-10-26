#include<iostream>
#include<vector>
#include<numeric>
#include<stack>
#include<queue>
#include<climits>
using namespace std;

class Solution 
{
    public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        queue<int> q;
        q.push(0);
        vector<int> visited(rooms.size());
        while (!q.empty()) 
        {
            int r = q.front();
            q.pop();
            if (visited[r]) 
            {
                continue;
            }
            visited[r] = 1;
            for (auto& k : rooms[r]) 
            {
                q.push(k);
            }
        }
        
        for(int i = 0;  i < visited.size(); i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};