#include <iostream>
#include <queue>
using namespace std;

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

// bfs

int maxDepth(TreeNode* root)
{
    queue<TreeNode*> q;
    if(root != NULL) q.push(root);
    int levels = 0;
    while(!q.empty())
    {
        int q_size = q.size();
        for(int i=0; i<q_size; i++)
        {
            TreeNode* curr = q.front();
            q.pop();
            if(root->left != nullptr) 
            {
                q.push(root->left);
            }
            if(root->right != nullptr)
            {
                q.push(root->right);
            }
        }
        levels++;
    }
    return levels;

}

int main()
{
    return 0;
}