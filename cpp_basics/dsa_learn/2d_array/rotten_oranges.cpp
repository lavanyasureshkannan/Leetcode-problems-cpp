#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
*/

int rotten_oranges(vector<vector<int>>& grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    int fresh = 0;
    int minutes = 0;

    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};
    queue<pair<int,int>> q;
    // multi source bfs
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(grid[i][j] == 1) fresh ++;
            else if(grid[i][j] == 2) 
            {
                q.push({i,j});
            }
        }
    }

    // ietrate through the queue
    while(!q.empty())
    {
        int q_size = q.size();
        bool is_rotted = false;
        for(int i=0; i<q_size; i++)
        {
            auto [r,c] = q.front();
            q.pop();

            for(int d=0; d<4; d++)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr >= 0 && nr < rows &&
                    nc >= 0 && nc < cols && 
                    grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2;
                        fresh --;
                        q.push({nr,nc});
                        is_rotted = true;
                    }
            }
        }

        if(is_rotted) minutes ++;
    }
    if(fresh == 0) return minutes;
    else return -1;

}


int main()
{
    vector<vector<int>> grid = {{2,1,1},
                                {1,1,0},
                                {0,1,1}};
    cout << rotten_oranges(grid) << endl;
    return 0;
}