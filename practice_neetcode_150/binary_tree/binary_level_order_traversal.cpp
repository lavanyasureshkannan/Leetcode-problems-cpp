#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Input: root = [1,2,3,4,5,6,7]
Output: [[1],[2,3],[4,5,6,7]]
*/

struct TreeNode
{
    int val;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int m_val)
    {
        val = m_val;
        right = nullptr;
        left = nullptr;
    }
};

vector<vector<int>> level_order_traversal(TreeNode* root)
{
    vector<vector<int>> result;
    queue<TreeNode*> q;
    if(root != nullptr) q.push(root);
    while(!q.empty())
    {
        int q_size = q.size();
        vector<int> level_nodes;
        for(int i=0; i<q_size; i++)
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            level_nodes.push_back(curr->val);
        }
        result.push_back(level_nodes);
    }
    return result;
}

int main()
{
    return 0;
}