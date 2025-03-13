/*
KHAN TOPOLOGICAL SORT

vertex -> Assumed as a node
Edges -> Assumed as a arrow
In-degree -> Number of edges that points at the node
Queue -> Fist In First out

Algorithm
1. Find the nodes and their in-dergrees
2. create a queue
3. Add all the nighbours with zero that points to the node.
4. pop q and  decrease the indegree of neighbours
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void display(vector<int>& arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

vector<int> topological_sort(vector<vector<int>>& adj_list, int V)
{
    // 1. Find the nodes and their in-dergrees
    vector<int> indegree(V,0);
    for(int i=0; i<V; i++)
    {
        for(int neighbours : adj_list[i])
        {
            indegree[neighbours]++;
        }
    }
    // 2. create a queue
    queue<int> q;
    for(int i=0; i<V; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> result;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        result.push_back(front);

        for(int neighbour : adj_list[front])
        {
            indegree[neighbour] --;
            if(indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    display(result);
    return result;

}


int main()
{   
    vector<vector<int>> list =  { { 0, 1 }, { 1, 2 }, { 2, 3 },
                                    { 4, 5 }, { 5, 1 }, { 5, 2 }};
    int V = 6;
    vector<vector<int>> adj_list(V);
    for (auto edge : list) 
    {
        int from = edge[0];
        int to = edge[1];
        adj_list[from].push_back(to);
    }
    
    topological_sort(adj_list,V);
    return 0;
}


