#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Input: grid = [[1,1,0],[0,1,1],[0,1,2]]
Output: 4

0 representing an empty cell
1 representing a fresh fruit
2 representing a rotten fruit

*/
int rotten_oranges(vector<vector<int>>& grid)
{
    // base case
    if(grid.size() == 0) return 0;
    int fresh = 0;
    int minutes = 0;
    queue<pair<int,int>> q;
    for(size_t i = 0; i < grid.size(); i++)
    {
        for(size_t j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j] == 1) 
            {
                fresh ++;
            }
            else if(grid[i][j] == 2)
            {
                q.push({i,j});
            }
        }
    }
    int rows = grid.size();
    int cols = grid[0].size();
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    while(!q.empty())
    {
        int q_size = q.size();
        for(size_t i =0; i<q_size; i++)
        {
            auto[r,c] = q.front();
            q.pop();

            for(size_t i =0; i<4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >=0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1)
                {
                    grid[nr][nc] = 2;
                    fresh --;
                    q.push({nr,nc});
                }
            }
        }
        if(!q.empty())
        {
            minutes ++;
        }
    }
    if(fresh == 0) return minutes;
    else return -1;
}

// TC: O(MxN)
int main()
{
    vector<vector<int>> grid = {{1,1,0},
                                {0,1,1},
                                {0,1,2}};
    cout << rotten_oranges(grid);
    return 0;
}