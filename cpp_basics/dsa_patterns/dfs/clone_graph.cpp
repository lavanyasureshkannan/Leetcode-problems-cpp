#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    Input -> adjlist:  [[2,4],[1,3],[2,4],[1,3]]
    Ouput -> graph: [[2,4],[1,3],[2,4],[1,3]]
*/

/*
    1. create a new node and mark as visited in mp
    2. recurssively clone every node
*/

class Node
{
    public:
    int val;
    vector<Node*> neighbours;

    Node(int m_val)
    {
        val = m_val;
        neighbours = vector<Node*>(); // creates dynamic neighbours
    }
};

unordered_map<Node*, Node*> mp;

Node* cloned_graph(Node* node)
{
    if(!node) return nullptr;
    if(mp.find(node) != mp.end())
    {
        return mp[node];
    }
    Node* new_node = new Node(node->val);
    mp[node] = new_node;
    for(Node* neigh : node->neighbours)
    {
        new_node->neighbours.push_back(cloned_graph(neigh));
    }
    return new_node;
}

int main()
{
    //[[2,4],[1,3],[2,4],[1,3]]
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    // neighbours
    node1->neighbours = {node2, node4};
    node2->neighbours = {node1, node3};
    node3->neighbours = {node2, node4};
    node4->neighbours = {node1, node3};
    
    cloned_graph(node1);
    return 0;
}