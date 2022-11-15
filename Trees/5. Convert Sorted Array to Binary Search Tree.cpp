108. Convert Sorted Array to Binary Search Tree

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
class Solution {
public:
     // create a function 
    TreeNode* create_sorted_array(vector<int>&nums, int left, int right){
        if(left > right) return NULL;
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = create_sorted_array(nums, left, mid-1);
        node->right = create_sorted_array(nums, mid+1, right);
        return node;
    }
      
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //base case
        if(nums.size() == 0 ) return NULL;
        return create_sorted_array (nums, 0, nums.size()-1);
                 
    
    }
};
