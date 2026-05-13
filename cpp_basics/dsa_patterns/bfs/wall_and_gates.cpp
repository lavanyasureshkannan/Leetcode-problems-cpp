#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/*
Input: rooms = [[2147483647,-1,0,2147483647],
                [2147483647,2147483647,2147483647,-1],
                [2147483647,-1,2147483647,-1],
                [0,-1,2147483647,2147483647]]
Output: [[3,-1,0,1],
        [2,2,1,-1],
        [1,-1,2,-1],
        [0,-1,3,4]]

-1 A wall or an obstacle.
0 A gate.
INF Infinity means an empty room.
*/

void print(vector<vector<int>>& rooms)
{
    for(int i=0; i<rooms.size(); i++)
    {
        for(int j=0; j<rooms[i].size(); j++)
        {
            cout << rooms[i][j] << " ";
        }
        cout << endl;
    }
}

void wall_and_gates(vector<vector<int>>& rooms)
{
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    int rows = rooms.size();
    int cols = rooms[0].size();

    queue<pair<int,int>> q;

    // push all the gates (multi - source bfs)
    for(int i=0; i<rooms.size(); i++)
    {
        for(int j=0; j<rooms[i].size(); j++)
        {
            if(rooms[i][j] == 0)
            {
                q.push({i,j});
            }
        }
    }

    while(!q.empty())
    {
        auto [r,c] = q.front();
        q.pop();
        
        for(int i=0; i<4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
            if(rooms[nr][nc] == INT_MAX)
            {
                rooms[nr][nc] = rooms[r][c] + 1;
                q.push({nr,nc});
            }
        }
    }
    print(rooms);
}


int main()
{
    vector<vector<int>> rooms = {{2147483647,-1,0,2147483647},
                                {2147483647,2147483647,2147483647,-1},
                                {2147483647,-1,2147483647,-1},
                                {0,-1,2147483647,2147483647}};
    
    wall_and_gates(rooms);
    return 0;
}
