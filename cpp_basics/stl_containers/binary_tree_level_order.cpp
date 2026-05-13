#include <iostream>
#include <vector>
#include <queue>
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

vector<int> level_order_traversal(TreeNode* root)
{
    queue<TreeNode*> q;
    vector<int> result;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();
        result.push_back(curr->val);
        if(curr->left)
        {
            q.push(curr->left);
        }
        if(curr->right)
        {
            q.push(curr->right);
        }
    }
    display(result);
    return result;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(6);

    level_order_traversal(root);
    return 0;
}