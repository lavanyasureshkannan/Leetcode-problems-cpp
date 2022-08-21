#include<iostream>
using namespace std;

/*
    Diameter of the subtree DFS

*/

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}; 
};


class Solution
{
    public: 
    int result = 0;
    int length(TreeNode* root)
    {
        // base case to find if the node doesnt exist
        if(root == NULL) return -1;

        // recursively find the longest path in
        // both left child and right child
        int left = 1 + length(root->left); 
        int right = 1 + length(root->right);

        // update the diameter if left_path plus right_path is larger
        result = max(result, left + right);
        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root)
    {
        length(root);
        return result;
    }

};

// TC: O(N) -> This is because in our recursion function longestPath, we only enter and exit from each node once
// SC: O(N) -> The space complexity depends on the size of our implicit call stack during our DFS, which relates to the height of the tree. 

