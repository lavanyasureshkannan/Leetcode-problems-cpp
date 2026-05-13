#include <iostream>
#include <vector>
using namespace std;

/*
    Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
    Output: [[5,4,11,2],[5,8,4,5]]
*/

class TreeNode
{
    public:
    int val;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int m_val)
    {
        val = m_val;
        right = nullptr;
        left = nullptr;
    }
};

void display(vector<vector<int>>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=0; j<nums[i].size(); j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(TreeNode* root, int target, vector<vector<int>>& result, vector<int>& path)
{
    if(!root) return;
    path.push_back(root->val);
    target = target - root->val;
    if(!root->left && !root->right && target == 0)
    {
        result.push_back(path);
    }
    dfs(root->left, target, result, path);
    dfs(root->right, target, result, path);
    path.pop_back();
}

vector<vector<int>> PathSum(TreeNode* root, int target)
{
    vector<vector<int>> result;
    vector<int> path;
    dfs(root, target, result, path);
    display(result);
    return result;
}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    PathSum(root, 22);

    return 0;
}