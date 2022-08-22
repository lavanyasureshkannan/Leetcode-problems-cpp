#include<iostream>
#include<queue>
using namespace std;

/*
grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]


DISCUSSION: we can solve this problem either with BFS(iterative) or DFS(recurrsive)

ALGORITHM: DFS
    1. Iterate through the 2d grid and find 1(island).
    2. check for the neigbouring '1's in all four directions you can increase your island count.
    3. if you find neighbouring 1's and check the boundary and then make it all 0.

Algorithm: BFS
    1. Queue -> use to add the neighbours
    2. keep poping the queue and check for its condition and making it 0
*/



// ALGORITHM: DFS - recurrsive
class Solution
{
    public:

    void callDFS(vector<vector<char>>& grid, int i, int j)
    {
        // check for the boundary
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j] == '0') return;
        // mark all the neighbouring 1's as 0's
        grid[i][j] = '0';
        // check for the directions
        callDFS(grid, i+1, j); // right
        callDFS(grid, i-1, j); //left
        callDFS(grid, i, j+1); //up
        callDFS(grid, i, j-1); // down 
        
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int num_of_islands = 0;
        // traverse through the 2d
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    // increment the island count
                    num_of_islands ++;
                    callDFS(grid,i,j);
                }
            }
        }
        return num_of_islands;
    }
};

// TC: O(MxN)->  M is the number of rows and N is the number of columns.
// SC: O(MxN) -> grid can go MxN deep. 

//***************************************************************************************************************************

// ALGORITHM - BFS(iterative)

int numIslands(vector<vector<char>>& grid)
{
    int row = grid.size();
    int col = grid[0].size();
    int islands = 0;
    // base case


    // iterate through the grid
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(grid[i][j] == '1') 
            {
                islands ++;
                // mark the current grid as '0' and mark it as visited
                grid[i][j] = '0';
                queue<pair<int,int>> neighbours; 
                neighbours.push({i,j});
                while(!neighbours.empty())
                {
                    auto curr = neighbours.front();
                    neighbours.pop();
                    int curr_row = curr.first;
                    int curr_col = curr.second;
                    // check for the boundaries and directions
                    // left
                    if(curr_row -1 >= 0 && grid[curr_row - 1][curr_col] == '1')
                    {
                        neighbours.push({curr_row - 1, curr_col});
                        grid[curr_row-1][curr_col] = '0';
                    }
                    // Right
                    if(curr_row +1 < row && grid[curr_row + 1][curr_col] == '1')
                    {
                        neighbours.push({curr_row + 1, curr_col});
                        grid[curr_row+1][curr_col] = '0';
                    }
                    // down
                    if(curr_col -1 >= 0 && grid[curr_row][curr_col - 1] == '1')
                    {
                        neighbours.push({curr_row, curr_col - 1});
                        grid[curr_row][curr_col - 1] = '0';
                    }
                    // up
                    if(curr_col +1 < col && grid[curr_row][curr_col + 1] == '1')
                    {
                        neighbours.push({curr_row, curr_col + 1});
                        grid[curr_row][curr_col + 1] = '0';
                    }


                }
            }
            
        }
    } 
    return islands;
    
}

// TC: O(MxN) -> where M is num of rows and N is num of cols;
// SC: O(min(M,N)) -> because in worst case where the grid is filled with lands, the size of queue can grow up to min(M,N)