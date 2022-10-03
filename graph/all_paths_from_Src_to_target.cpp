#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// DFS + BACKTRACKING

class Solution
{
    public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int>& paths, int node)
    {
        paths.push_back(node);
        // check if i == last element
        if(node == graph.size() - 1)
        {
            result.push_back(paths);
            return;
        }
        // grab the nieghbours and do the same
        for(auto n: graph[node])
        {
            dfs(graph, result, paths, n);
        }
        paths.pop_back(); // pops the last element in the vector
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        vector<vector<int>> result;
        // base case
        if(graph.size() == 0) return result;
        vector<int> paths;
        dfs(graph,result,paths,0);
        return result;
    }
};

// TC:  O(2^v . V) where V represents the number of vertexs
// SC: O(V) recurrsive depth


// BFS + queue
class Solution_bfs
{
    public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        vector<vector<int>> result;
        if(graph.size() == 0) return result;
        
        vector<int> paths;
        queue<vector<int>>q;
        paths.push_back(0);
        q.push(paths);

        while(!q.empty())
        {
            vector<int> curr = q.front();
            q.pop();

            // take the last element from the q
            int nextnode = curr.back();
            // add the neoghbours of the next node
            for(int neigh : graph[nextnode])
            {
                vector<int> temp(curr.begin(), curr.end());
                temp.push_back(neigh);
                if(neigh == graph.size() - 1)
                {
                    result.push_back(temp);
                }
                else 
                {
                    q.push(temp);
                }
            }
        }
        return result;
    }
};




int main()
{
    return 0;
}