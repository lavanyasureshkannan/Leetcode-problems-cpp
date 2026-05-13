#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int m_val)
    {
        val = m_val;
        left = nullptr;
        right = nullptr;
    }
};

/*
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
*/

void dfs(Node* root, string s, vector<string>& result)
{
    if(!root) return;
    if(!s.empty())
    {
        s += "->";
    }
    s += to_string(root->val);
    if(!root->left && !root->right)
    {
        result.push_back(s);
    }
    dfs(root->left, s, result);
    dfs(root->right, s, result);
}


void binary_tree_paths(Node* root)
{
    if(!root) return;
    if(root->left == nullptr && root->right == nullptr)
    {
        cout << root->val << endl;
    }     
    vector<string> result;
    dfs(root, "", result);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
}


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(5);
    root->right = new Node(3); 
    binary_tree_paths(root);

    return 0;
}