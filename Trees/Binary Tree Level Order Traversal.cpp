#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        if(root== NULL)
        {
            return result;
        }
        queue<TreeNode* > Q;
        Q.push(root);
        while(!Q.empty())
        {
            vector<int> level_nodes;
            int count= Q.size();
            for (int i =0; i < count ; i++)
            {
                TreeNode* node = Q.front();
                Q.pop();
                if (node->left)
                    Q.push(node->left);
                if(node->right)
                    Q.push(node->right);
                level_nodes.push_back(node->val);
            }
            result.push_back(level_nodes);
            
        }
        return result;
        
    }
};
// TC : O(N)
// SC : O(N)