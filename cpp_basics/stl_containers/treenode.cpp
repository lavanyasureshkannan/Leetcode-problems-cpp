#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


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

void display(vector<int>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// Inorder Traversal => left -> root -> right
// Iterative approach
vector<int> inorder_iterative(TreeNode* root)
{
    vector<int> result;
    TreeNode* curr = root;
    stack<TreeNode*> st;

    while(curr != nullptr || !st.empty())
    {
        while(curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        result.push_back(curr->val);
        curr = curr->right;
    }
    display(result);
    return result;

}

vector<int> inorder_traversal_recurrsive(TreeNode* root, vector<int>& result)
{
    if(!root) return result;
    inorder_traversal_recurrsive(root->left, result);
    result.push_back(root->val);
    inorder_traversal_recurrsive(root->right, result);
    return result;
}


////////////////////////////////////////////////////////////////////////////////////
// PreOrder Traversal => Root => left => right
// Iterative approach
vector<int> preOrderTraversal(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while(curr != nullptr || !st.empty())
    {
        while(curr != nullptr)
        {
            st.push(curr);
            result.push_back(curr->val);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        curr = curr->right;
    }
    display(result);
    return result;
}

vector<int> preOrder_traversal_recurrsive(TreeNode* root, vector<int>& result)
{
    if(!root) return result;
    result.push_back(root->val);
    preOrder_traversal_recurrsive(root->left, result);
    preOrder_traversal_recurrsive(root->right, result);
    return result;
}

/////////////////////////////////////////////////////////////////////////////////
// PostOrderTraversal => Left => Right => Root 
// Iterative approach
vector<int> PostOrder_Traversal(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty())
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
    display(result);
    return result;
    
}

vector<int> PostOrdertraversal_recursive(TreeNode* root, vector<int>& result)
{
    if(!root) return result;
    PostOrdertraversal_recursive(root->left, result);
    PostOrdertraversal_recursive(root->right, result);
    result.push_back(root->val);
    return result;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    //inorder_iterative(root); // 4 2 5 1 3 6
    //preOrderTraversal(root); // 1 2 4 5 3 6
    //PostOrder_Traversal(root); // 4 5 2 6 3 1

    vector<int> result;
    
    //inorder_traversal_recurrsive(root, result);
    //preOrder_traversal_recurrsive(root, result);
    PostOrdertraversal_recursive(root, result);
    display(result);

}