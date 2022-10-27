
class Solution
{
    public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        // base case
        if(edges.size() != n-1) return false;
        // graph representation
        vector<vector<int>> adj_list(n);
        for(vector<int>i : edges)
        {
            adj_list[i[0]].push_back(i[1]);
            adj_list[i[1]].push_back(i[0]);
        }
        // for getting the neighbours
        stack<int> st;
        st.push(0);
        // if the graph is fully connected then every node in the graph is visited.
        unordered_set<int> visited;
        visited.insert(0);
        while(!st.empty())
        {
            int curr_node = st.top();
            st.pop();
            for(int neigh : adj_list[curr_node])
            {
                if(visited.find(neigh) != visited.end()) continue;
                visited.insert(neigh);
                st.push(neigh); 
            }
        }
        return (visited.size() == n);
    }
};


class Solution
{
    public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        // base case
        if(edges.size() != n-1) return false;
        vector<vector<int>> adj_list(n);
        for(vector<int>i : edges)
        {
            adj_list[i[0]].push_back(i[1]);
            adj_list[i[1]].push_back(i[0]);
        }
        // for getting the neighbours
        queue<int> q;
        q.push(0);
        unordered_set<int> visited;
        visited.insert(0);
        while(!q.empty())
        {
            int curr_node = q.front();
            q.pop();
            // checking for the neighbours of the current node in your adj list
            for(int neigh : adj_list[curr_node])
            {
                if(visited.find(neigh) != visited.end()) continue;
                visited.insert(neigh);
                q.push(neigh); 
            }
        }
        return (visited.size() == n);
    }
};