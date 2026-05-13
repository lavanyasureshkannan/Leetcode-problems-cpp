#include <iostream>
#include <queue>
#include <vector>
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


// BFS traverse bianry tree level vice
void traverse_bfs(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* curr = q.front();
        cout << curr->val << " ";
        q.pop();
        
        if(curr->left)
        {
            q.push(curr->left);
        }

        if(curr->right)
        {
            q.push(curr->right);
        }
    }
}


void print(vector<vector<int>>& result)
{
    for(int i=0; i<result.size(); i++)
    {
        for(int j=0; j<result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

// BFS traverse binary tree level wise and push in the 2d vector
vector<vector<int>> traverse_bfs_level_nodes(Node* root)
{
    vector<vector<int>> result;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        vector<int>levelnodes;
        int q_size = q.size();
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
            levelnodes.push_back(curr->val);
        }
        result.push_back(levelnodes);
    }
    print(result);
    return result;
}



int main()
{
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    //traverse_bfs(root);
    traverse_bfs_level_nodes(root);
    return 0;
}