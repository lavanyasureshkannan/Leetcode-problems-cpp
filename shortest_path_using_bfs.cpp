#include<vector>
#include<iostream>
#include<queue>
using namespace std;
// given start and end node
class Solution
 {
     public:
     bool isTraversable(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j)
     {
         return (i >= 0 && j < grid.size() && j >= 0 && j < grid[0].size()) && grid[i][j] == 0 && !visited[i][j];
     }
     int shortestPathBinaryMatrix(vector<vector<int>>& grid, pair<int, int> src, pair<int, int> dest)
     {
         int row = grid.size();
         int col = grid[0].size();
         int distance = 0;
         vector<vector<bool>> visited(row, vector<bool>(col, false));
         queue<pair<int,int>> q;
         q.push({src.first, src.second});
         visited[src.first][src.second] = true;
         while(!q.empty())   
         {
             int size = q.size();
             distance++;
             for(int i = 0; i<size; i++)
             {
                 auto curr = q.front();
                 int curr_i = curr.first;
                 int curr_j = curr.second;
                 q.pop();
                 if(curr_i == dest.first && curr_j == dest.second)
                 {
                     return distance;
                 }
                 for(int r = curr_i-1; r <= curr_i+1; r++)
                 {
                     for(int c = curr_j-1; c <= curr_j+1; c++)
                     {
                         if(isTraversable(grid, visited, r, c))
                         {
                             q.push({r,c});
                             visited[r][c] = true;
                         }
                     }
                 }

             }

         }
         return -1; 
     }
}; 

        
int main()
{
    vector<vector<int>> arr = {{0,0,0,1},{0,0,1,1},{1,0,0,1},{1,0,0,0}};
    pair<int, int> src = make_pair(0, 0);
	pair<int, int> dest = make_pair(2,2);
    Solution s;
    cout << s.shortestPathBinaryMatrix(arr,src,dest);
    
    return 0;
}
