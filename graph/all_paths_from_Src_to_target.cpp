#include<iostream>
#include<vector>
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


int main()
{
    return 0;
}
