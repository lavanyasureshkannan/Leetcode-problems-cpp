#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;


// DFS solution
class Solution 
{
    public:
    unordered_map<Node* , Node*> mp; // declaring map, to check whwther we have a copy of node or not and also to store copy
    
    Node* cloneGraph(Node* node) 
    {
        if(node == NULL) // if node is null, then simply return null
        {
            return NULL;
        }
        
        // for a node, we will check whether we already creates a copy of thiis or not. If it is present in map that means we already creates a copy of this.
        //But if not present in map, that means we have not a copy of this.
        // Also, if we create a copy, then being a good neighbor, we find whether our neighbor have a copy or not, so we will travel all around our adjcant.
        
        if(mp.find(node) == mp.end()) // if not present in map
        {
            mp[node] = new Node(node -> val, {}); // make a copy
            
            for(auto adj: node -> neighbors) // travel in adjcant
            {
                mp[node] -> neighbors.push_back(cloneGraph(adj)); //add copy
            }
        }
        
        return mp[node]; // and at last, return mp[node] as till now we clone our whole graph
        
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
// SC: O(N) 


int main()
{
    return 0;
}
