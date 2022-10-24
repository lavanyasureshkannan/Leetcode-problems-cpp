#include<iostream>
#include<vector>
#include<stack>
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
        TreeNode* left = NULL;
        TreeNode* right = NULL; 
    }
};

// ITERATIVE
class Solution 
{
    public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode* > st;

        TreeNode* curr = root;
        while(!st.empty() || curr != NULL)
        {
            while(curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }

        return result;
    }
};

//RECURRSIVE
class Solution
{
    public:
    void inorder(TreeNode* root, vector<int>& result)
    {
        if(root != NULL) 
        {
            inorder(root->left, result);
            result.push_back(root->val);
            inorder(root->right, result);
        }
    }
    vector<int> inordertraversal_Recurrsive(TreeNode* root)
    {
        vector<int> result;
        inorder(root, result);
        return result;
        
    }
};



int main()
{
    return 0;
}