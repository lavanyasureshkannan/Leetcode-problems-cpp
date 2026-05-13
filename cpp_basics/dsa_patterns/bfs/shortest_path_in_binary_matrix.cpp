#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Input: grid = [[0,1],[1,0]]
Output: 2
0 -> open cells
1 -> blocked cells
*/

int shortest_path_in_binary (vector<vector<int>>& grid)
{
    if (grid.empty() || grid[0].empty()) return -1;

    int rows = grid.size();
    int cols = grid[0].size();

    int dr[8] = {0,1,1,1,0,-1,-1,-1};
    int dc[8] = {1,1,0,-1,-1,-1,0,1};
    // start end block
    if(grid[0][0] != 0 || grid[rows-1][cols-1] != 0) return -1;
    queue<pair<int,int>> q;

    q.push({0,0});
    grid[0][0] = 1;
    int distance = 1;

    while(!q.empty())
    {
        int q_size = q.size();
        for(int i=0; i<q_size; i++)
        {
            auto [r,c] = q.front();
            q.pop();

            if(r == rows-1 && c == cols-1) return distance;
            for(int d=0; d<8; d++)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr >= 0 && nr <= rows &&
                    nc >= 0 && nc <= cols &&
                grid[nr][nc] == 0)
                {

                    grid[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        distance ++;
    }
    return -1;
}

int main()
{
    vector<vector<int>> grid = {{0,1},{1,0}};
    cout << shortest_path_in_binary(grid);
    return 0;
}