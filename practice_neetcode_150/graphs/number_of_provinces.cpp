#include <iostream>
#include <vector>
using namespace std;

/*
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]] 
                      city 0   city 1  city 2
Output: 2
*/

void dfs(vector<vector<int>>& isConnected, size_t i, vector<bool>& visit)
{
    visit[i] = true;
    // From i city, find all the connected cities
    // similar to grid where we traverse left, right, up, down
    // here we traverse inside the cities and look if it is connected or not
    for(size_t j=0; j<isConnected.size(); j++) 
    {
        if(isConnected[i][j] == 1 && !visit[j])
        {
            dfs(isConnected,j,visit);
        }
    }
}


int number_of_provinces(vector<vector<int>>& isConnected)
{
    int num_of_provinces = 0;
    int n = isConnected.size();
    // 1. keep track of the visisted
    vector<bool> visited(n, false);
    // 2. Iterate thorugh the cities    
    for(size_t i=0; i<n; i++) 
    {
        // 3. Increase the number of province if not in visisted
        if(!visited[i])
        {
            num_of_provinces ++;
            dfs(isConnected, i, visited);
        }
    }
    return num_of_provinces;
}


int main()
{
    vector<vector<int>>isConnected = {{1,1,0},
                                     {1,1,0},{0,0,1}};
    cout << number_of_provinces(isConnected) << endl; 
}