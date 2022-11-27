#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Solution 
{
    public:
    bool check(int i,int j, map<pair<int,int>,bool>& visited, vector<vector<int>>& grid)
    {
        if(i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] == 0 && (visited.find({i,j}) == visited.end()))
        {
            return true;
        }
        return false;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        // if first element of our grid is not zero then return -1
        if(grid[0][0] == 1) return -1;
        
        int row = grid.size();
        int col = grid[0].size();
       
        // creating queue to store co-ordinates and distance
        queue<vector<int>> Q;
        // i , j , dist
        Q.push({0,0,0});

        // creating map to keep track of the visited
        map<pair<int,int>,bool> visited;
        visited[{0,0}] = true;
        
        // BFS
        while(!Q.empty())
        {
            // take our the front vector from queue
            auto curr = Q.front();
            Q.pop();
            
            // extracting the data information
            int i = curr[0];
            int j = curr[1];
            int dist = curr[2];
            
            // if we reach to the last cell then return the dist+1 because we will also consider current cell value as 1
            if(i == row-1 && j == col-1)
            {
                return dist+1;
            }
            
            // left
            if(check(i, j-1, visited, grid))
            {
                visited[{i, j-1}] = true;
                Q.push({i, j-1, dist+1});
            }
            
            // right
            if(check(i, j+1, visited, grid))
            {
                visited[{i, j+1}] = true;
                Q.push({i, j+1, dist+1});
            }
            
            // up 
            if(check(i-1, j, visited, grid))
            {
                visited[{i-1, j}] = true;
                Q.push({i-1, j, dist+1});
            }
            
            // down 
            if(check(i+1, j, visited, grid))
            {
                visited[{i+1, j}] = true;
                Q.push({i+1, j, dist+1});
            }
            
            // leftUp
            if(check(i-1, j-1, visited, grid))
            {
                visited[{i-1, j-1}] = true;
                Q.push({i-1, j-1, dist+1});
            }
            
            // rightUp 
            if(check(i-1, j+1, visited, grid))
            {
                visited[{i-1, j+1}] = true;
                Q.push({i-1,j+1,dist+1});
            }
            
            // leftDown 
            if(check(i+1, j-1, visited, grid))
            {
                visited[{i+1, j-1}] = true;
                Q.push({i+1, j-1, dist+1});
            }
            
            // rightDown 
            if(check(i+1, j+1, visited, grid))
            {
                visited[{i+1, j+1}] = true;
                Q.push({i+1, j+1, dist+1});
            }
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> matrix = {{0,0,0},{1,1,0},{1,1,0}};
    Solution s1;
    cout << s1.shortestPathBinaryMatrix(matrix);
    return 0;
}