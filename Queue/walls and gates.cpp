#include<iostream>
#include<queue>
#include<vector>
using namespace std;


class Solution 
{
    public:    
    void callDFS(int i, int j, int count,vector<vector<int>>& rooms)
    {
        //check for boundaries
        if(i<0 || i>=rooms.size() || j<0 || j>=rooms[i].size() || rooms[i][j] < -1)
        {
            return;
        }
        // minimum of the count and track
        if(rooms[i][j] == min(rooms[i][j],count) && count != 0)
        {
            return;
        }
        rooms[i][j] = min(rooms[i][j],count);
        callDFS(i + 1,j,count+1, rooms);
        callDFS(i - 1,j,count+1, rooms);
        callDFS(i,j + 1,count+1, rooms);
        callDFS(i,j - 1,count+1, rooms);
    }
    
    
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        // traverse through the 2D array
        for(int i =0; i<rooms.size(); i++)
        {
            for(int j = 0; j<rooms[i].size(); j++)
            {
                if(rooms[i][j] == 0)
                {
                    callDFS(i,j,0,rooms);
                }
            }
        }
    }
    
};


class Solution
{
    public:
    void wallsAndGates(vector<vector<int>>& rooms)
    {
        // rows and col
        int m = rooms.size();
        int n = rooms[0].size();

        queue<pair <int, int>> q;
        vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

        // search for gate
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(rooms[i][j] == 0)
                {
                    q.push({i,j});
                }
            }

        }

        // BFS
        while(!q.empty())
        {
            int s = q.size();
            for(int i=0; i<s; i++)
            {
                pair<int, int> curr = q.front();
                q.pop();

                for(int j=0; j<4; j++)
                {
                    int row = curr.first + directions[j][0];
                    int col = curr.second + directions[j][1];

                    // check for the boundaries and empty rooms
                    if(row>=0 && col>=0 && row<m && col<n && rooms[row][col] == INT_MAX)
                    {
                        // curr.first and curr.second represents the co-ordinates
                        rooms[row][col]  = rooms[curr.first][curr.second]+1;
                        q.push({row,col});
                    };

                }
            }
        }


    }
};

// TC: O(M,N) -> rows and cols
// SC: O(M,N) -> queue




int main()
{
    return 0;
}