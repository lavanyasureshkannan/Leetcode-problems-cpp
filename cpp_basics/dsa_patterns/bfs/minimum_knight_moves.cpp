#include <iostream>
#include <queue>
using namespace std;

/*
Example 1:
Input: x = 2, y = 1
Output: 1
Explanation: [0, 0] → [2, 1]

Example 2:
Input: x = 5, y = 5
Output: 4
Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
*/

int min_moves(int x, int y)
{
    int dr[8] = {2,2,1,1,-1,-1,-2,-2};
    int dc[8] = {1,-1,2,-2,2,-2,1,-1};
    int min_steps = 0;
    queue<pair<int,int>> q;
    // visisted
    vector<vector<bool>> visited(x+1,vector<bool>(y+1, false));
    q.push({0,0});
    visited[0][0] = true;

    while(!q.empty())
    {
        int q_size = q.size();
        for(int i=0; i<q_size; i++)
        {
            auto curr = q.front();
            q.pop();
            if(x == curr.first && y == curr.second) return min_steps;
            for(int d=0; d<8; d++)
            {
                int nx = curr.first + dr[d];
                int ny = curr.second + dc[d];
                if(nx >= 0 && ny >=0 && nx <= x && ny <= y && visited[nx][ny] == false)
                {
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                } 
            }

        }
        min_steps ++;
        
    }
    return -1;
}

int main()
{
    cout << min_moves(5,5);
    return 0;
}