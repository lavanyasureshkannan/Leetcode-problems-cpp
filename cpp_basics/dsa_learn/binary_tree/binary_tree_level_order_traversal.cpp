#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
*/

vector<vector<int>> binary_tree_level_order(Node* root)
{
    vector<vector<int>> result;
    if(root == NULL) return result;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int q_size = q.size();
        vector<int> levels;
        for(int i=0; i<q_size; i++)
        {
            Node* curr = q.front();
            q.pop();
            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
            levels.push_back(curr->val);
        }
        result.push_back(levels);
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    vector<vector<int>> bianry_levels = binary_tree_level_order(root);
    for(int i=0; i<bianry_levels.size(); i++)
    {
        for(int j=0; j<bianry_levels[i].size(); j++)
        {
            cout << bianry_levels[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}