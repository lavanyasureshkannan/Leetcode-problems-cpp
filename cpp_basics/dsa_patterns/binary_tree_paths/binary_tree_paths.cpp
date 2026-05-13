#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/*
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
*/

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int m_val)
    {
        val = m_val;
        left = nullptr;
        right =  nullptr;
    }
};

void dfs(TreeNode* root, string s, vector<string>& result)
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


vector<string> binary_tree_paths(TreeNode* root)
{
    vector<string> result;
    dfs(root, "", result);
    return result;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    vector<string> result = binary_tree_paths(root);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}