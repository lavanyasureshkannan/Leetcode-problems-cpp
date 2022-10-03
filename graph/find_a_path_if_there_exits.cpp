#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;


// DFS-> STACK

class solution_dfs
{
    public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end)
    {
        vector<vector<int>> adjacency_list(n);
        stack<int> st;
        vector<bool> visited(n);

        // add the elements in the adjacency list
        for(vector<int> edge : edges)
        {
            adjacency_list[edge[0]].push_back(edge[1]);
            adjacency_list[edge[1]].push_back(edge[0]);
        }

        // push the starting element
        st.push(start);

        while(!st.empty())
        {
            // pop the curr node from the stack
            int curr_node = st.top();
            st.pop();
            // see if the node is the end
            if(curr_node == end) return true;
            // mark node as visited if it is not
            if(visited[curr_node]) continue;
            visited[curr_node] = true;
            // add all the neighbours of the curr node to the stack
            for(int neighbour : adjacency_list[curr_node])
            {
                st.push(neighbour);
            }
        }
        return false;
    }
};

// TC: O(V+E) -> visited all the nodes
// SC: O(V+E) -> stack - O(E) elements, list - O(V+E)


// BFS -> QUEUE

class solution_bfs
{
    public:
    bool isValid(vector<vector<int>>& edges, int n, int start, int end)
    {
        vector<vector<int>> adj_list(n);
        queue<int>q;
        // insert all the edges in the adjacency list
        for(vector<int> edge : edges)
        {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        q.push(start);
        vector<int> visited(n);
        visited[start] = true;

        while(!q.empty())
        {
            // get the front node
            int curr = q.front();
            q.pop();

            // if the curr reached the target
            if(curr == end) return true;
            for(int neighbour : adj_list[curr])
            {
                if(!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }
};

// TC: O(V+E) -> visited all the nodes
// SC: O(V+E) -> stack - O(E) elements, list - O(V+E)

int main()
{
    return 0;
}