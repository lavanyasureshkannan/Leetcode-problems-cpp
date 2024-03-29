
#include<iostream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
    // base case
    if(root == NULL) return false;
    // logic is to subtract the root value recurrsively from target till it reaches zero
    targetSum = targetSum - root->val;
    if((root->left == NULL) && (root->right == NULL)) return (targetSum == 0);
    return hasPathSum(root->left,  targetSum) || hasPathSum(root->right, targetSum);   
    }
};

//TIME COMPLEXITY O(N)
// SPACE COMPLEXITY O(LoG N) each node has only one child node