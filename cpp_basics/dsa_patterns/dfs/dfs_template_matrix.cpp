#include <iostream>
#include <vector>
using namespace std;

void dfs(int r, int c, vector<vector<int>>& grid)
{
    // 1. boundary check
    if(r < 0 || r > grid.size() || c < 0 || c >grid[0].size()) return;
    // 2. check if it is visited
    if(grid[r][c] == 0) return;
    // 3. mark it visited
    grid[r][c] = 0;
    // 4. Get its neighbours
    dfs(r+1, c, grid);
    dfs(r-1, c, grid);
    dfs(r, c+1, grid);
    dfs(r, c-1, grid);
}

int main()
{
    vector<vector<int>> grid;
    int row = grid.size();
    int col = grid[0].size();
    return 0;
}