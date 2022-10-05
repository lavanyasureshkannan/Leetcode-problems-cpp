#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
    BFS -> iterative using queue
    push the co-ordinates of (i,j) in the queue and keep adding its neighbours in all possible directions
    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.
*/

class Solution
{
    public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>> rotten_oranges;
        int fresh = 0;
        int time = 0;
        // push the rotten orange co-ordinates to q
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j] == 2)
                {
                    rotten_oranges.push({i,j});
                } 
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        // go into the q and get its neighbours
        while(!rotten_oranges.empty())
        {
            int q_size = rotten_oranges.size();
            for(int i=0; i< q_size; i++)
            {
                int x = rotten_oranges.front().first;
                int y = rotten_oranges.front().second;
                rotten_oranges.pop();
                // go to the neighbouring co-ordinates and find if the orange is fresh(1)
                // if its fresh then mark it as rotten(2)
                
                // left
                if(x > 0 && grid[x-1][y] == 1)
                {
                    grid[x-1][y] = 2;
                    fresh--;
                    rotten_oranges.push({x-1,y});
                }
                // right
                if(x < row-1 && grid[x+1][y] == 1)
                {
                    grid[x+1][y] = 2;
                    fresh--;
                    rotten_oranges.push({x+1,y});
                }
                // down
                if(y > 0 && grid[x][y-1] == 1)
                {
                    grid[x][y-1] = 2;
                    fresh--;
                    rotten_oranges.push({x,y-1});
                }
                // up
                if(y < col-1 && grid[x][y+1] == 1)
                {
                    grid[x][y+1] = 2;
                    fresh--;
                    rotten_oranges.push({x,y+1});
                }                                
            }// by the end of this loop the rotten will be empty
            if(!rotten_oranges.empty()) time++;
        }
        if (fresh == 0) return time;
        else return -1;
    }
};

// TC: O(N) ->First, we scan the grid to find the initial values for the queue, which would take O(N) time.
// Then we run the BFS process on the queue, which in the worst case would enumerate all the cells in the grid once and only once. 
// SC: Space Complexity: O(N)O(N), where NNN is the size of the grid.
// In the worst case, the grid is filled with rotten oranges. As a result, the queue would be initialized with all the cells in the grid.

int main()
{
    return 0;
}