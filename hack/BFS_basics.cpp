#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
    BFS -> BREADTH FIRST SEARCH
    1. create a adjacency list
    2. start with first node
    3. create a queue
    4. find the neighbours and keep track of your visited nodes
*/

void BFS(int start, vector<vector<int>>& adjacency_list, int n)
{
    vector<bool>visited(n, false);
    queue<int>q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cout << front << " ";
        for(auto neigh : adjacency_list[front])
        {
            if(!visited[neigh])
            {
                visited[neigh] = true;
                q.push(neigh);
            }
        }

    }
    

}

int main()
{
    vector<vector<int>> edges = { {0, 1},{0, 2}, {1, 2},{1, 3},{2, 4}};
    int n = 5;
    // 1. create a adjacency list
    vector<vector<int>> adj_list;
    for(auto edge : edges)
    {
        int from = edge[0];
        int to = edge[1];
        adj_list[from].push_back(to);
    }
    vector<bool> visited(n);
    BFS(0, adj_list, n);
    return 0;
}


