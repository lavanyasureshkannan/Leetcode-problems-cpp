#include <iostream>
#include <vector>
using namespace std;

/*
Input: grid = [
    ["0","1","1","1","0"],
    ["0","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
  ]
Output: 1
*/

void dfs(int i, int j, vector<vector<char>>& grid)
{
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == '0') return;
    grid[i][j] = '0';
    dfs(i+1,j,grid);
    dfs(i-1,j,grid);
    dfs(i,j+1,grid); 
    dfs(i,j-1,grid);
}


int num_of_islands(vector<vector<char>>& grid)
{
    int islands = 0;
    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[0].size(); j++)
        {
            if(grid[i][j] == '1')
            {
                islands += 1;
                dfs(i,j,grid);
            }
        }
    }
    return islands;
}

int main()
{
    vector<vector<char>> grid = {
    {'0','1','1','1','0'},
    {'0','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}};
    cout << num_of_islands(grid) << endl;
    return 0;
}