#include <iostream>
#include <vector>
using namespace std;


/*
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
*/

class TreeNode
{
    public:
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


bool path_sum(TreeNode* root, int targetSum)
{
    if(!root) return false;
    targetSum = targetSum - root->val;
    if(!root->left && !root->right)
    {
        return(targetSum == 0);
    }
    return path_sum(root->left, targetSum) || path_sum(root->right, targetSum);
}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    cout << path_sum(root, 22) << endl;
    return 0;
}