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
vector<int> preordertraversal(TreeNode* root)
{
    stack<TreeNode*> st;
    vector<int> result;
    if(!root) return result;
    st.push(root);
    while(!st.empty())
    {
        TreeNode* curr = st.top();
        st.pop();
        result.push_back(curr->val);
        if(curr->right)
        {
            st.push(curr->right);
        }
        if(curr->left)
        {
            st.push(curr->left);
        }
    }
    return result;
}


//RECURRSIVE
class Solution
{
    public:
    void preorder(TreeNode* root, vector<int>& result)
    {
        if(root == NULL) return;
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }
    vector<int> preordertraversal_Recurrsive(TreeNode* root)
    {
        vector<int> result;
        preorder(root, result);
        return result;
        
    }
};

int main()
{
    return 0;
}