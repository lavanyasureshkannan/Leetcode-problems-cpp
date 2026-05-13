#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*

Use grid BFS when:
    1. shortest path in maze
    2. flood fill
    3. number of islands
    4. rotten oranges
    5. walls and gates
    6. escape / spreading problems

✅ Use q_size (level-order BFS) when:
Time / distance / steps advance in discrete layers
“How many steps / minutes / levels?”
“What happens per minute?”
“How far is X from Y?”
Example: Rotten Oranges, Binary Matrix shortest path, minimum time problems

❌ Don’t use q_size when:
You just need to visit everything, not track “levels”

*/

void print(vector<vector<int>>& grid)
{
    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[i].size(); j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int shortest_path(vector<vector<int>>& grid, int src_r, int src_c, int des_r, int des_c)
{
    // up down left right 
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    // rows and cols
    int rows = grid.size();
    int cols = grid[0].size();

    // distance vector
    vector<vector<int>> distance(rows, vector<int>(cols,-1));

    queue<pair<int,int>> q;
    q.push({src_c,src_r});
    distance[src_c][src_r] = 0;

    while(!q.empty())
    {
        auto [r,c] = q.front();
        q.pop();

        if(r == des_r && c == des_c) return distance[r][c];
        for(int i=0; i<4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >=0 && nr <= rows && 
                nc >= 0 && nc <= cols
               && distance[nr][nc] == -1 && grid[nr][nc] == 0)
               {
                    distance[nr][nc] = distance[r][c] + 1;
                    q.push({nr,nc});
               }
        }
    }
    return -1;
    
}


int main()
{
    vector<vector<int>> grid = {{1,0,0},
                                {1,1,0},
                                {1,1,0}};
    print(grid);
    int sr = 0; int sc = 0;
    int dr = 2; int dc = 2;  
    cout << shortest_path(grid, sr, sc, dr, dc) << endl;
    return 0;
}