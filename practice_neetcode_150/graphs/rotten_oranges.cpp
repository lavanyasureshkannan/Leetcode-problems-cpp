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
    int fresh = 0;
    queue<pair<int,int>> q;

    int rows = grid.size();
    int cols = grid[0].size();

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(grid[i][j] == 1)
            {
                fresh ++;
            }
            if(grid[i][j] == 2)
            {
                q.push({i,j});
            }
        }
    }
    int minutes = 0;
    while(!q.empty())
    {
        for(int i=0; i<q.size(); i++)
        {
            auto [x,y] = q.front();
            q.pop();

            if((x-1) >= 0 && grid[x-1][y] == 1)
            {
                grid[x-1][y] = 2;
                fresh --;
                q.push({x-1,y});
            }

            if((x+1) < rows && grid[x+1][y] == 1)
            {
                grid[x+1][y] = 2;
                fresh --;
                q.push({x+1,y});
            }
            
            if((y-1) >= 0 && grid[x][y-1] == 1)
            {
                grid[x][y-1] = 2;
                fresh --;
                q.push({x,y-1});
            }
            
            if((y+1) < cols && grid[x][y+1] == 1)
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
    vector<vector<int>> grid = {{1,1,0},
                                {0,1,1},
                                {0,1,2}};
    cout << rotten_oranges(grid);
    return 0;
}