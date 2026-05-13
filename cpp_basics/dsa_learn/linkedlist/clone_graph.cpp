#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
*/

struct Node
{
    int val;
    vector<Node*> neighbours;

    Node(int m_val)
    {
        val = m_val;
        neighbours = vector<Node*>();
    }
};


unordered_map<Node*, Node*> mp;
Node* clone_graph(Node* node)
{
    if(mp.find(node) != mp.end())
    {
        return mp[node];
    } 
    Node* new_node = new Node(node->val);
    mp[node] = new_node;
    for(Node* neigh : node->neighbours)
    {
        new_node->neighbours.push_back(clone_graph(neigh));
    } 
    return new_node;
}


int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    // adjlist:  [[2,4],[1,3],[2,4],[1,3]]
    node1->neighbours = {node2, node4};
    node2->neighbours = {node1, node3};
    node3->neighbours = {node2, node4};
    node4->neighbours = {node1, node3};

    clone_graph(node1);
    return 0;
}