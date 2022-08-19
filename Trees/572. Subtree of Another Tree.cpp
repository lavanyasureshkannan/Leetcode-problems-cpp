#include<iostream>
using namespace std;

struct TreeNode()
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {} 

}


// RECURRSIVE

bool isSubtree(TreeNode* root, TreeNode* subroot)
{
    // base case 1
    if(root == NULL && subroot == NULL) return true;
    // base case 2
    if(root == NULL || subroot == NULL) return false;
    // return if isSUbtree is true
    return (solveRecurrsive(root, subroot) || isSubtree(root->left, subroot) || isSubtree(root->right, subroot));
}

bool solveRecurrsive(TreeNode* x, TreeNode* y)
{
    // base case 1
    if(x == NULL && y == NULL) return true;
    // base case 2
    if(x == NULL || y == NULL) return false;
    // base case 3
    if(x->val != y->val) return false;
    // call the recurrsive on left and right
    return (solveRecurrsive(x->left,y->left) && solveRecurrsive(x->right, y->right)); 
}

// TC: O(N)
// SC: O(N)

int main()
{
    return 0;
}