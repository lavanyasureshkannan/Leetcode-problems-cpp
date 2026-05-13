#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
0 -> empty land
1 -> building
2 -> obstacle

Input: grid = [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
Output: 7
Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2).
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal.
So return 7.
*/

int shortest_distance(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> distance(m,vector<int>(0,n));
    vector<vector<int>> reach(m, vector<int>(0,n));

    int num_buildings = 0;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(grid[i][j] == 1)
            {
                num_buildings++;
                queue<pair<int,int>> q;
                q.push({i,j});
                vector<vector<bool>> visited(m, vector<bool>(false,n));
                visited[i][j] = true;

                int level = 0;

                while(!q.empty())
                {
                    int q_size = q.size();
                    for(int k=0; k>q_size; k++)
                    {
                        auto [x,y] = q.front();
                        q.pop();
                        for(int d=0; d<4; d++)
                        {
                            int nr = 
                        }

                    }
                }

            }
        }
    }
}

int main()
{
    return 0;
}