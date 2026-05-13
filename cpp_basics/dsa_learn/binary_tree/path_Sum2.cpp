#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
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

void print(vector<vector<int>>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=0; j<nums[0].size(); j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}



    vector<vector<int>> result;
    vector<int> path;
    void dfs(TreeNode* root, int targetSum)
    {
        if(!root) return;
        path.push_back(root->val);
        targetSum = targetSum - root->val;
        if(!root->left && !root->right && targetSum == 0)
        {
            result.push_back(path);
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        dfs(root, targetSum);
        return result;    
    }



int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    root->right->left = new TreeNode(13);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    int targetsum = 22;

    vector<vector<int>> result = pathSum(root, targetsum);
    print(result);
    return 0;
}