#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;


// DFS solution
class Solution
{
    public:
    Node* cloneGraph(Node* node)
    {
        // declare a unordered map
        unordered_map<Node* Node*> mp;
        // base case
        if(node == NULL) return NULL;
        // find if the node already exits in the map or not
        if(mp.find(node) == mp.end()) 
        {
            mp[node] = new Node(node->val, {}); // making a copy
            for(auto i: node->neighbours) // add the neighbours
            {
                mp[node]->neighbours.push_back(cloneGraph(i)); // adding the copy
            }
        
        }
        // return the cloned graph
        return mp[node];
    }
};

// TC: O(N+M) // no of edges and vertex
// SC: O(N) -> visited

// BFS -> Using queue
class Solution
{
    unordered_map<Node*, Node*> mp;
    public:
    Node* cloneGraph(Node* node)
    {
        // base case
        if(node == NULL) return NULL;
        // make copy of the first node
        Node* first_node = new Node(node->val, {});
        mp[node] = first_node;
        // create queue
        queue<Node*> q;
        // push the node in the queue
        q.push(node);
        // while q is empty
        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop(); // pop the front element
            for(auto i: curr->neighbors) // get the neighbours
            {
                if(mp.find(i) == mp.end()) // if not present in map
                {
                    mp[i] = new Node(i->val, {});  // create a copy
                    q.push(i); // push the neighbours
                }
                mp[curr]->neighbors.push_back(mp[i]);// push the adj node
            }
        }
        return mp[node];
        // return the cloned graph
    }

};
// TC: O(N+M) // no of edges and vertex
// SC: O(N) Functors in C++


int main()
{
    return 0;
}