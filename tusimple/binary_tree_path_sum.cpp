#include<iostream>
#include<bits/stdc++.h>


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val, TreeNode* left, TreeNode* right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

// POST ORDER TRAVERSAL -> BOTTOM TO TOP => RECURRSION
class Solution
{
    private:
    int max_path_sum;
    // give the maximum pathsum of the children node
    int PathSum(TreeNode* node)
    {
        // base case 
        if(node == NULL) return 0;
        // traverse recurssively till end child node and calculate the path sum
        int left = std::max(PathSum(node->left), 0);
        int right = std::max(PathSum(node->right), 0);
        max_path_sum = std::max(max_path_sum, node->val+left+right);
        return std::max(left, right) + node->val;
    }
    public:
    int maxPathSum(TreeNode* root)
    {
        max_path_sum = INT_MIN;
        PathSum(root);
        return max_path_sum;
    }
};