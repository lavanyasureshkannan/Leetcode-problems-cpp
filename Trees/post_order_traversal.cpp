#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

struct TreeNode
{
    int val;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int val, TreeNode* left, TreeNode* right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

// POST ORDER TRAVERSAL -> left, right, root
// Iterative

class Solution
{
    public:
    std::vector<int>postorderTraversal(TreeNode* root)
    {
        std::vector<int> result;
        std::stack<TreeNode*> st; 
        // base case 
        if(root == NULL) return result;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* curr = st.top();
            st.pop();
            result.push_back(curr->val);
            if(curr->left)
            {
                st.push(curr->left);
            }
            if(curr->right)
            {
                st.push(curr->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// TC: O(N)
// SC: O(N)

// Recurrsive
class Solution
{
    public:
    std::vector<int> result;
    std::vector<int> postorderTraversal(TreeNode* root)
    {
        if(root == NULL) return result;
        if(root)
        {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            result.push_back(root->val);
        }
        return result; 
    }
};
// TC: O(N)
// SC: O(N)


int main()
{
    return 0;
}