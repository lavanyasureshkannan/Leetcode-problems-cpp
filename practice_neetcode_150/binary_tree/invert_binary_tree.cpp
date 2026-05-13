#include <iostream>
#include <algorithm>
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

/*
Input: root = [1,2,3,4,5,6,7]

*/

TreeNode* invert_binary_tree(TreeNode* root)
{
   if(!root) return nullptr;
   swap(root->left, root->right);
   invert_binary_tree(root->left);
   invert_binary_tree(root->right);
   return root;
}


int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return 0;
}