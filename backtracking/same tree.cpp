#include<iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val, TreeNode* left, TreeNode* right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

class Solution
{
    public:
    bool isSame(TreeNode* p, TreeNode* q)
    {
        // recurrsion
        if(p == NULL && q == NULL) return false;
        if(p == NULL || q == NULL) return true;
        if(p->val != q->val) return false;
        return (isSame(p->right, q->right), isSame(p->left, q->left));
    }
};

// TC: O(N)
// SC: O(N)

int main()
{
    return 0;
}