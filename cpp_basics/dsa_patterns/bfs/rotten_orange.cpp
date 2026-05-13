#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
*/

int rotten_oranges(vector<vector<int>>& grid)
{
    queue<pair<int,int>> q;
    int minutes = 0;
    int fresh = 0;

    // add the elements in queue
    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[i].size(); j++)
        {
            if(grid[i][j] == 2)
            {
                q.push({i,j});
            }
            else if(grid[i][j] == 1)
            {
                fresh ++;
            }
        }
    }
    int rows = grid.size();
    int cols = grid[0].size();

    while(!q.empty())
    {
        int q_size = q.size();
        for(int i=0; i<q_size; i++)
        {
            auto [x,y] = q.front();
            q.pop();

            // up
            if(x-1 >= 0 && grid[x-1][y] == 1)
            {
                grid[x-1][y] = 2;
                fresh --;
                q.push({x-1,y});
            }
            // down
            if(x+1 < rows && grid[x+1][y] == 1)
            {
                grid[x+1][y] = 2;
                fresh --;
                q.push({x+1,y});
            }
            // left
            if(y-1 >= 0 && grid[x][y-1] == 1)
            {
                grid[x][y-1] = 2;
                fresh --;
                q.push({x,y-1});
            }
            // right
            if(y+1 < cols && grid[x][y+1] == 1)
            {
                grid[x][y+1] = 2;
                fresh --;
                q.push({x,y+1});
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

int main()
{
    //grid = [[2,1,1],[1,1,0],[0,1,1]]
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << rotten_oranges(grid) << endl;
    return 0;
}
