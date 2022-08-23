#include<iostream>
#include<map>
#include<list>
using namespace std;

/*
    DFS ALGORITHM
    The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph) and explores as far as possible along each branch before backtracking.
    Create a recursive function that takes the index of the node and a visited array.
    Mark the current node as visited and print the node.
    Traverse all the adjacent and unmarked nodes and call the recursive function with the index of the adjacent node.
*/

class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    // adding an edge
    void addEdge(int v, int w);

    // adding the vertex
    void DFS(int v);
};

void Graph :: addEdge(int v, int w)
{
    // add w to v's list
    adj[v].push_back(w);
}

void Graph :: DFS(int v)
{
    // mark the current node as visited
    visited[v] = true;

    // call recurrsively for the nearby vertex
    list<int> :: iterator i;
    for(int i= adj[v].begin(); i != adj[v].end(); i++)
    {
        if(!visited[*i]) 
            DFS(*i);
    }
}

int main()
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    
    return 0;
}

// TC: O(V+E) -> V is the number of vertex and E is the number of edges
// SC: O(V) -> extra visited array of size V