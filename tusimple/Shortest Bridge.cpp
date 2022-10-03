#include<iostream>
#include<vector>

using namespace std;


/*
    FLOOD FILL ALGORITHM
    -> BFS approach
    1. Save the co-ordinates in a seperate vector
    2. we need to flip one or blocks to make 2 islands to 1
    3. Then we will calculate the distance between the blocks and choose the minimum one
*/
class Solution 
{
    public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector <pair<int, int>> &a)
    {
        //check the boundary conditions
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == 0) return;
        // just to avoid infinite loop
        grid[i][j] = 0;
        // pushing the values in a which are our coordinates
        a.push_back(make_pair(i,j));
        // recurrsive call for 4 different directions
        dfs(grid, i+1, j, a); // right
        dfs(grid, i-1, j, a);// left
        dfs(grid, i, j-1, a);// up
        dfs(grid, i, j+1, a);// down
        return;
    }
    int shortestBridge(vector<vector<int>>& grid) 
    {
        int count = 0;
        vector <pair<int, int>> x;
        vector <pair<int, int>> y;
        for(int i=0; i < grid.size(); i++)
        {
            // iterate through the array and find the land(1)
            for(int j=0; j < grid[i].size(); j++)
            {

                if(grid[i][j] == 1)
                {
                    //increase the count
                    count++;
                    if(count == 1)
                    {
                        dfs(grid, i, j, x);    // either one island
                    }
                    if(count == 2)
                    {
                        dfs(grid, i, j, y);   // two island
                    }   
                }
            }
        }
        int min_distance = INT_MAX;
        for(int i=0; i<x.size(); i++)
        {
            for(int j=0; j<y.size(); j++)
            {
                int distance = abs(x[i].first - y[j].first) + abs(x[i].second - y[j].second) - 1;
                if(distance < min_distance)
                    min_distance = distance;
            }
        }
        return min_distance;
    }
};

// tc: O(NxM)
// SC: O(N^2)