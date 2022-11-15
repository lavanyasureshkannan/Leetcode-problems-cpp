#include<iostream>
#include<vector>
#include<numeric>
#include<stack>
#include<queue>
#include<climits>
using namespace std;



/*
For our BFS routine, we keep a queue, q to maintain the queue of cells to be examined next.
We start by adding all the cells with 0s to q.
Intially, distance for each 0 cell is 0 and distance for each 1 is INT_MAX, which is updated during the BFS.
Pop the cell from queue, and examine its neighbors. If the new calculated distance for neighbor {i,j} is smaller, we add {i,j} to q and update dist[i][j].

*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
{
    int row = matrix.size();
    if(row == 0)
    {
        return matrix;
    }
    int col = matrix[0].size();
    vector<vector<int>> distance(row, vector<int>(col, INT_MAX));
    queue<pair<int,int>>q;
    vector<vector<int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
    for(int i =0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(matrix[i][j] == 0)
            {
                distance[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    while(!q.empty())
    {
        pair<int,int> curr = q.front();
        q.pop();
        for(int i = 0; i<direction.size(); i++)
        {   
            int new_row = curr.first + direction[i][0]; 
            int new_col = curr.second + direction[i][1];
            if(new_row >= 0 && new_row < row && new_col >= 0 && new_col < col)
            {
                if(distance[new_row][new_col] > distance[curr.first][curr.second] + 1)
                {
                    distance[new_row][new_col] = distance[curr.first][curr.second] + 1;
                    q.push({new_row, new_col});
                }
             }
        }
    }
    return distance;
}

// TC: O(r,c)
// SC: O(r,c)
};

// TC: O(R.C)
// SC: O(R.C)
