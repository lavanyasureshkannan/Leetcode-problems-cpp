#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: root = [3,1,4,null,2], k = 1
Output: 1
*/

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

int kthsmallest_element_in_bst_bf(Node* root, int k)
{
    vector<int> result;
    if(!root) return -1;
    stack<Node*> st;
    st.push(root);
    while(!st.empty())
    {
        Node* curr = st.top();
        st.pop();
        result.push_back(curr->val);
        if(curr->left) {st.push(curr->left);}
        if(curr->right) {st.push(curr->right);}
    }
    sort(result.begin(), result.end());
    for(int i=0; i<result.size(); i++)
    {
        if(i == (k-1))
        {
            return result[i];
        }
    }
    return -1;
}

int kthsmallest_element_in_bst_opti(Node* root, int k)
{
   stack<Node*> st;
   Node* curr = root;
   while(curr || !st.empty())
   {
        // going all the way left coz in binary tree left is smaller
        while(curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        k--;
        if(k==0) return curr->val;
        curr = curr->right;
   }
   return -1;
}

int main()
{
    Node* root = new Node(3);
    root->left = new Node(1);
    root->left->right = new Node(2);
    root->right = new Node(4);
    int k = 1;
    cout << kthsmallest_element_in_bst_bf(root, k) << endl;
    cout << kthsmallest_element_in_bst_opti(root,k) << endl;
    return 0;
}