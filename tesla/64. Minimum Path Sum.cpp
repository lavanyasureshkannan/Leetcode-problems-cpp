
/*
    Dynamic programming approach
    1. traverse and keep adding the values and return the last element
*/

int minPathSum(vector<vector<int>>& grid)
{
    // base case
    int m = grid.size(); n = grid[0].size();
    if (m == 0) return 0;
    if (n == 0) return 0;

    // iterate over and specify the conditions
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            // some element in the middle
            if((i-1 >= 0) && (j-1 >= 0))
            {
                // see which is the minimum value
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
            else
            {
                // if it is in the boundary
                if(i-1 >= 0)
                {
                    grid[i][j] += grid[i-1][j];
                } 
                if(j-1 >= 0)
                {
                    grid[i][j] += grid[i][j-1];
                }
            }
        }
    }
    return grid[m-1][n-1];

}


// TC: O(mn). We traverse the entire matrix once
// SC: O(1). No extra space is used.