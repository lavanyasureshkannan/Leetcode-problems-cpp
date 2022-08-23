#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
/*
    BFS ALGORITHM
    1. put every vertex of the graph into visited and non-visited.
    2. you will use queue here.
    3. take the fron item of the queue and add it to the visited list
    4. Create a list of that vertex's adjacent nodes. Add the ones which aren't in the visited list to the back of the queue.
    5. keep repeating the same untill the queue is empty.
*/

class Graph
{
private:
    // No of vertices
    int V;
    // adjacency list
    vector<list<int>> adj;

public:
    // constructor
    Graph(int V);
    // add edge to the graph
    void addEgde(int v, int w);
    // print BFS traversal
    void BFS(int s);
};

// constructor with number of vertices
Graph :: Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

//implementation to add edges
void Graph :: addEgde(int v, int w)
{
    adj[v].push_back(w);
}

// perform BFS with the starting vertex
void Graph :: BFS(int s)
{
    // visited 
    vector<bool> visited;
    // mark everything as not visited
    visited.resize(V, false);
    // create a queue for BFS
    list<int> queue;
    // mark the current node as visited
    visited[s] = true;
    queue.push_back(s);
    
    while(!queue.empty())
    {
        // deque a vertex from queue
        s = queue.front();
        queue.pop_front();

        // get the adjacent nodes
        for(auto a : adj[s])
        {
            if(!visited[a])
            {
                visited[a] = true;
                queue.push_back(a);
            }
        }
    }

}

int main()
{
    Graph g(4);
    g.addEgde(0,1);
    g.addEgde(0,2);
    g.addEgde(1,2);
    g.addEgde(2,0);
    g.addEgde(2,3);
    g.addEgde(3,4);
    return 0;
}