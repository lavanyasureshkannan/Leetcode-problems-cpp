#include <iostream>
using namespace std;

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

bool has_path_sum(TreeNode* root, int target)
{
    if(root == NULL) return root;
    target = target - root->val;
    if((root->left == NULL) && (root->right == NULL)) return (target == 0); 
    return (has_path_sum(root->left, target) || has_path_sum(root->right, target));
}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    root->right->left = new TreeNode(13);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    int targetsum = 22;

    cout << has_path_sum(root, targetsum);
    return 0;
}