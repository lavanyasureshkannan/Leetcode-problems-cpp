#include <iostream>
#include <vector>
using namespace std;

/*
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
*/


void print(vector<vector<int>>& image)
{
    for(int i=0; i<image.size(); i++)
    {
        for(int j=0; j<image[i].size(); j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(vector<vector<int>>& image, int i, int j, int new_color, int old_color)
{
    // 1. boundary check
    if(i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] == 0) return;
    // 2. check if it already visited
    if(image[i][j] == new_color) return;
    // 3. if not mark it visited
    image[i][j] = new_color;
    // 4. recurssive dfs
    dfs(image, i + 1, j, new_color, old_color);
    dfs(image, i - 1, j, new_color, old_color);
    dfs(image, i , j + 1, new_color, old_color);
    dfs(image, i , j - 1, new_color, old_color);
}


vector<vector<int>> flood_fill(vector<vector<int>>& image, int sr, int sc, int new_color)
{
    int old_color = image[sr][sc];
    dfs(image, sr,sc, new_color, old_color);
    return image;
}

int main()
{
    vector<vector<int>> image = {{1,1,1},
                                 {1,1,0},
                                 {1,0,1}};
    int sr = 1;
    int sc = 1;
    int new_color = 2;
    vector<vector<int>> image_output = flood_fill(image,sr,sc,new_color);
    print(image_output);
    return 0;
}