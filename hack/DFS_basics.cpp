#include <iostream>
#include <vector>
using namespace std;


/*
    1. convert the array into a adjacency list
    2. traverse through the adjacencey list
    3. track the visited 
    4. get neighbours
    5. follow it recurssively 

*/

void print_adj_list(vector<vector<int>> adj_list)
{
    for(int i=0; i<adj_list.size(); i++)
    {
        cout << i << ": " ; 
        for(int neigh: adj_list[i])
        {
            cout << neigh << " "; 
        }
        cout << endl;
    }
}

//1. convert the array into a adjacency list
vector<vector<int>> create_adjacency_list(vector<vector<int>> edges, int n)
{
    vector<vector<int>> adjacency_list(n);
    for(auto edge : edges)
    {
        int from = edge[0];
        int to = edge[1];
        adjacency_list[from].push_back(to); // directed graph
        adjacency_list[to].push_back(from); // undirected graph 
    }
    //print_adj_list(adjacency_list);
    return adjacency_list;
}
//     2. traverse through the adjacencey list
void dfs(vector<vector<int>>& adj_list, int n, vector<bool> visited)
{
    cout << n << " ";
    //3. track the visited
    visited[n] = true;
    for(auto neigh : adj_list[n])
    {   
        // 4.  get neighbours     
        if(!visited[neigh])
        {
            dfs(adj_list, neigh, visited);
        }
    }


}


int main()
{
    vector<vector<int>> arr = {{1, 2}, {1, 0}, {2, 0}, {2, 3}, {2, 4}};
    /*
        Nodes/vertex => 0,1,2,3,4
        links/edges => 1-2, 1-0, 2-0, 2-3, 2-4
        adjacency list => 0 {1,2}, 1 {0,2}, 2{0,1,3,4}, 3{2}, 4{2}
    */
    int N = 5;
    create_adjacency_list(arr, N);
    
    vector<bool> visited(N, false);
    return 0;
}
