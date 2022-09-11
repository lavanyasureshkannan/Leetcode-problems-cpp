#include<iostream>
#include<queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}; 

};

// Iterative method
int max_depth(TreeNode* root)
{
    int result = 0;
    // base case
    if(root == NULL) return 0;
    // bfs iteration
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int q_size = q.size();
        for(int i=0; i<q_size; i++)
        {
            // pop the front element
            TreeNode* top = q.front();
            q.pop();
            if(top->left)
            {
                q.push(top->left);
            }
            if(top->right)
            {
                q.push(top->right);
            }
        }
        result++;
    }
    return result;
}
// TC: O(N) -> visiting the nodes exactly once
// SC: O(N) -> number of TreeNodes 


// recurrsive method
int max_depth(TreeNode* root)
{
    // base case
    if(root == NULL) return 0;
    return (1+max(max_depth(root->left), max_depth(root->right)));

}
// TC: O(N) -> visiting the nodes exactly once
// SC: O(N) -> Number of TreeNodes




int main()
{
    return 0;
}