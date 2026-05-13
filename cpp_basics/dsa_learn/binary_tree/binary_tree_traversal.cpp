#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node* right;
    Node* left;

    Node(int m_val)
    {
        val = m_val;
        right = nullptr;
        left = nullptr;
    }
};

// commonly used iterative
vector<int>preorder_traversal_iterative(Node* root)
{
    vector<int> result;
    // base case
    if(!root) return result;
    stack<Node*> st;
    st.push(root);

    while(!st.empty())
    {
        Node* curr = st.top();
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


int main()
{
    Node* root = new Node(2);
    root->left = new Node(1);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->right = new Node(6);

    vector<int> result = preorder_traversal_iterative(root);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}