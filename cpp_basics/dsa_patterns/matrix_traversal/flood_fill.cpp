#include <iostream>
#include <vector>
using namespace std;

/*
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
*/

void display(vector<vector<int>>& image)
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
    if(i<0 || j<0 || i>=image.size() || j>=image[i].size() || image[i][j] != old_color) return;
    image[i][j] = new_color;
    dfs(image, i+1, j, new_color, old_color);
    dfs(image, i-1, j, new_color, old_color);
    dfs(image, i, j+1, new_color, old_color);
    dfs(image, i, j-1, new_color, old_color);
}

vector<vector<int>> floodfill(vector<vector<int>>& image, int sr, int sc, int new_color)
{
    int old_color = image[sr][sc];
    dfs(image, sr, sc, new_color, old_color);
    display(image);
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

    floodfill(image, sr, sc, new_color);
    return 0;
}