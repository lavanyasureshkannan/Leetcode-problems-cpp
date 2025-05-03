#include <iostream>
#include <vector>
using namespace std;

void printAdjList(const vector<vector<int>>& adjList) {
    // Print the adjacency list
    for (int i = 0; i < adjList.size(); i++) {
        cout << "Node " << i << " connects to: ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> Convert_to_Adjacency(vector<vector<int>>& list,int nodes)
{
    vector<vector<int>> adj_list(nodes);
    for(auto edges : list)
    {
        int from = edges[0];
        int to = edges[1];
        adj_list[from].push_back(to);
    }
    printAdjList(adj_list);
    return adj_list;
}

int main()
{
    vector<vector<int>> arr = { {0, 1}, {0, 2}, {1, 2}, {2, 3} };
    Convert_to_Adjacency(arr,4);
    return 0;
}