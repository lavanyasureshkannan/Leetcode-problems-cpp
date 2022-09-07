#include<iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}; 
};


// recurrsive approach
class Solution
{
    public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        if(root == NULL || val == root->val) return root;
        // if we find the root of the given val return the root
        if(root->val == val) return root;
        // if the value is gonna be greater than root->val then search in right subtree
        if(root->val < val) return(searchBST(root->right, val));
        // or search in left subtree
        else return(searchBST(root->left, val));
    }
};

// TC: O(N)
// SC: O(N)


// Iterative approach
class Solution
{
    public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        while(root != NULL)
        {
            if(root->val == val) return root;
            else if(root->val < val) root = root->right;
            else if(root->val > val) root = root->left; 
        }
        return NULL;

    }
};

// TC: O(N)
// SC: O(1)