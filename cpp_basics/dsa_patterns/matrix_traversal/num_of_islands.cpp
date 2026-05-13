#include <iostream>
#include <vector>
using namespace std;

/*
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/


void dfs(vector<vector<char>>& grid, int i, int j)
{
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == '0') return;
    grid[i][j] = '0';
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
    dfs(grid,i,j+1);
    dfs(grid,i,j-1);
}

int num_of_islands(vector<vector<char>>& grid)
{
    int island = 0;
    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[0].size(); j++)
        {
            if(grid[i][j] == '1')
            {
                island ++;
                dfs(grid, i, j);
            }
        }
    }
    return island;
}


int main()
{
    vector<vector<char>> grid = {{'1','1','0','0','0'},
                                {'1','1','0','0','0'},
                                {'0','0','1','0','0'},
                                {'0','0','0','1','1'}};

    cout << num_of_islands(grid) << endl; 
    return 0;
}
