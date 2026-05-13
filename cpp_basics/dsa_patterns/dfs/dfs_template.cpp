#include <iostream>
using namespace std;

/*
    DFS template for binary tree
*/

void dfs_binary(TreeNode* root)
{
    if(!root) return;
    cout << "visitng" << root->val << endl;
    dfs(root->left);
    dfs(root->right);
}

/*
    DFS template for graph/grid
*/

void dfs_graph(vector<vector<int>>& adj_list, vector<bool>& visited, int node)
{
    visited[node] = true;
    for(int nei : adj_list[node])
    {   
        if(!visited[node])
        {
            dfs(adj_list, visited, nei);
        }
    }
}


/*
    DFS template for Backtracking
*/

void dfs_backtracking(vector<int>& nums, vector<int>& path, vector<vector<int>>& result, vector<bool> used)
{
    if(path.size() == nums.size())
    {
        result.push_back(path);
        return;
    }

    for(int i=0; i<nums.size(); i++)
    {
        if(used[i]) continue;
        used[i] = true;
        dfs(nums,path,result,used);
        path.pop_back();
        used[i] = false;

    }
}



int main()
{
    return 0;
}