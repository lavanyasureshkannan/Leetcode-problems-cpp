#include<iostream>
#include<vector>
#include<numeric>
#include<stack>
#include<queue>
#include<climits>
using namespace std;


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

/* ACCORDING TO THE CONDITIONS.
            10               10- min => -infinity; max => +inifinty
           /  \              5 - min => -infinity, max => 10; 15- min => 10, max=> +infinity
          5   15
         / \    \
        3   7    13 
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, NULL, NULL);
        
    }
    bool validate(TreeNode* root, TreeNode* min, TreeNode* max){
        if (root == NULL) return true;
        if ((min && root->val <= min->val) || (max && root->val >= max->val))
            return false;
        return (validate(root->left, min, root) && validate(root->right, root, max));
    }
};