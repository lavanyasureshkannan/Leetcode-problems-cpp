#include<iostream>
#include<vector>
#include<numeric>
#include<stack>
#include<queue>
using namespace std;

// Flood fill => dfs + recurrsive
// image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

class Solution 
{
    public:
    
    void dfs(vector<vector<int>>& image, int i, int j, int color, int newColor)
    {
        if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == newColor || image[i][j] != color)
        {
            return;
        }
        image[i][j] = newColor;
        dfs(image,i-1,j,color,newColor);
        dfs(image,i+1,j,color,newColor);
        dfs(image,i,j-1,color,newColor);
        dfs(image,i,j+1,color,newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int color = image[sr][sc];
        dfs(image,sr,sc,color,newColor);
        return image;
    }
};

// TC: O(N)
// SC: O(N)