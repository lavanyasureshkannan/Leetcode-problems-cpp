#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
Input: grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
Output: 1
*/

void dfs(int i, int j, int bi, int bj, vector<vector<int>>& grid, vector<pair<int,int>>& s)
{
    if (i<0 || j<0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return;
    grid[i][j] = 0;
    s.push_back({i - bi, j - bj});
    dfs(i + 1, j, bi, bj, grid, s); 
    dfs(i - 1, j, bi, bj, grid, s); 
    dfs(i, j + 1, bi, bj, grid, s); 
    dfs(i, j - 1, bi, bj, grid, s);
    
}

int distinct_islands(vector<vector<int>>& grid)
{
    set<vector<pair<int,int>>> shapes;
    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[0].size(); j++)
        {
            if(grid[i][j] == 1)
            {
                vector<pair<int,int>> shape;
                dfs(i,j,i,j, grid, shape);
                shapes.insert(shape);
            }
        }
    }
    return shapes.size();
}

int main()
{
    vector<vector<int>>grid = {{1,1,0,0,0},
                               {1,1,0,0,0},
                               {0,0,0,1,1},
                               {0,0,0,1,1}};
    cout << distinct_islands(grid) << endl;
    return 0;
}