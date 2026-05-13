#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
*/

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int m_val)
    {
        val = m_val;
        left = nullptr;
        right = nullptr;
    }
};

vector<vector<int>> binary_level_order(TreeNode* root)
{
    vector<vector<int>> result;
    if(root == NULL) return result;

    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        vector<int> level_nodes;
        for(int i=0; i<q.size(); i++)
        {
            TreeNode* front = q.front();
            q.pop();
            if(front->left)
            {
                q.push(front->left);
            }
            if(front->right)
            {
                q.push(front->right);
            }
            level_nodes.push_back(front->val);
        }
        result.push_back(level_nodes);   
    }
    return result;
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> result = binary_level_order(root);
    for(int i=0; i<result.size(); i++)
    {
        for(int j=0; j<result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}