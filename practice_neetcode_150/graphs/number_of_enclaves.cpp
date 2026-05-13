#include <iostream>
#include <vector>
using namespace std;

/*
    Number of Enclaves
    Input: grid = [[0,0,0,0],
                   [1,0,1,0],
                   [0,1,1,0],
                   [0,0,0,0]]
    Output: 3
    Explanation: There are three 1s that are enclosed by 0s, 
                and one 1 that is not enclosed because its on the boundary
*/

void dfs(vector<vector<int>>& grid, int i, int j, int m, int n)
{
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0) return;
    grid[i][j] = 0;
    
    dfs(grid,i+1,j,m,n);
    dfs(grid,i-1,j,m,n);
    dfs(grid,i,j+1,m,n);
    dfs(grid,i,j-1,m,n);
}


int number_of_enclaves(vector<vector<int>>& grid)
{
    int m = grid.size(); 
    int n = grid[0].size();

    // 1. column boundaries
    for(size_t i=0; i<m; i++)
    {
        // first column
        if(grid[i][0] == 1)
        {
            dfs(grid,i,0,m,n);
        }
        // last column
        if(grid[i][n-1] == 1)
        {
            dfs(grid,i,n-1,m,n);
        }
    }

    for(size_t i=0; i<n; i++)
    {
        if(grid[i][0] == 1)
        {
            dfs(grid,i,0,m,n);
        }
        if(grid[i][m-1] == 1)
        {
            dfs(grid,i,m-1,m,n);
        }
    }

    // count the remaining 1's
    int count  = 0;
    for(size_t i=0; i<m; i++)
    {
        for(size_t j=0; j<n; j++)
        {
            if(grid[i][j] == 1)
            {
                count ++;
            }
        }
    }
    return count;
}


int main()
{
    vector<vector<int>> grid = {{0,0,0,0},
                                {1,0,1,0},
                                {0,1,1,0},
                                {0,0,0,0}};
    cout << number_of_enclaves(grid) << endl;
    return 0;
}