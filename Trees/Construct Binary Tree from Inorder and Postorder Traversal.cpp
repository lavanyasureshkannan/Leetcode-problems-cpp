#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int val)
    {
        this->val = val;
        right = nullptr;
        left = nullptr;
    }
};

// ALGORITHM

/*
1. We start by initializing postIdx = n-1, where n is the number of nodes. postIdx denotes the index of postorder traversal that we are at. 
    It will give us the root node for each point of recursion
2. We also initialize inStart = 0 and inEnd = n-1 which denotes the current range in inorder that the subtree will lie in.
3. At each recursion, we choose postorder[postIdx] as current root node. We search that index of that node in inorder as well. 
    Then all nodes to the left of that index (till the previous root) are part of current root's left sub-tree and all nodes to the right of it are part of its right sub-tree.
4. We decrement postIdx and recurse to build the right sub-tree and then left sub-tree.
5. Why right first? Because postorder goes as left->right->root and we are traversing it from end. 
    So we consider in order root->right->left)
6. The process is continued till all nodes are traversed.
*/


// we maintain a mapping of node's value to inorder node index in a hashmap.
class Solution
{
    public:
    unordered_map<int,int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        for(int i=0; i<inorder.size(); i++)
        {
            mp[inorder[i]] = i; // mapping all the index of inorder
        }
        int n = inorder.size();
        int postIdx = n-1;
        return build(inorder, postorder, 0, n-1, postIdx); 
    }
    TreeNode* build(vector<int>& inorder_, vector<int>& postorder_, int instart, int inEnd, int& postIdx)
    {
        if(instart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(postorder_[postIdx--]);
        int inIdx = mp[root -> val];
        root -> right = build(inorder_, postorder_, inIdx+1, inEnd, postIdx);
        root -> left  = build(inorder_, postorder_, instart, inIdx-1, postIdx);
        return root;
    }

};


// TC: O(N) -> time required to build the tree
// SC: O(N) -> hashmap


