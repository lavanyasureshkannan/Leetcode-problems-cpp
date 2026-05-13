#include <iostream>
#include <vector>
using namespace std;


/*
Input: grid = [
  [0,1,1,0,1],
  [1,0,1,0,1],
  [0,1,1,0,1],
  [0,1,0,0,1]
]

Output: 6
*/

int dfs(int i, int j, vector<vector<int>>& grid)
{
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == 0) return 0;
    grid[i][j] = 0;
    int result = 1;
    return result + 
    dfs(i+1,j,grid) +
    dfs(i-1,j,grid) +
    dfs(i,j+1,grid) +
    dfs(i,j-1,grid);
}


int max_area_island(vector<vector<int>>& grid)
{
    int max_area = 0;
    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[0].size(); j++)
        {
            if(grid[i][j] == 1)
            {
                int curr_area = dfs(i,j,grid);
                max_area = max(max_area, curr_area);
            }
        }
    }
    return max_area;
}

int main()
{
        vector<vector<int>> grid = {
  {0,1,1,0,1},
  {1,0,1,0,1},
  {0,1,1,0,1},
  {0,1,0,0,1}};
    cout << max_area_island(grid) << endl;
    return 0;
}