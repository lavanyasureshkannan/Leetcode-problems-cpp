#include <iostream>
#include <vector>
using namespace std;

/*
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
*/

void dfs(int i, int j, vector<vector<string>>& grid)
{
    // 1. boundary check
    if(i < 0 || i > grid.size() || j < 0 || j >grid[i].size()) return;
    // 2. check visited
    if(grid[i][j] == "0") return;
    // 3. mark as visited
    grid[i][j] = "0";

    dfs(i+1, j, grid);
    dfs(i-1, j, grid);
    dfs(i, j+1, grid);
    dfs(i, j-1, grid);
}

int number_of_islands(vector<vector<string>>& grid)
{
    int result = 0;
    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[i].size(); j++)
        {
            if(grid[i][j] == "1")
            {
                dfs(i,j,grid);
                result ++;
            }
        }
    }
    return result;
}

int main()
{
    vector<vector<string>> grid = { {"1","1","0","1","0"},
                                    {"1","1","0","1","0"},
                                    {"1","1","0","0","0"},
                                    {"0","0","0","0","0"}};
    cout << number_of_islands(grid) << endl;
    return 0;
}