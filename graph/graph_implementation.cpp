#include<iostream>
#include<list>
using namespace std;


void addEdge(list<int> adj[], int source, int destination)
{
    adj[source].push_back(destination);
    adj[destination].push_back(source);
}


void display(list<int> adj[], int vertex)
{
    for(int i=0; i<vertex; i++)
    {
        cout << "head";
        for(auto x: adj[i])
        {
            cout << "->" << x;
        }
        cout << endl;
    }
}



int main()
{
    int v = 5;
    list<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    display(adj,v);
    return 0;
}