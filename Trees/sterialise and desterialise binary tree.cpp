#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<sstream>
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
        right = nullptr;
        left = nullptr;
    }
};

// The idea behind my answer would be to use a preorder traversal and queue.
// Why Queue?
// Because we wanna process the data from left to right.

string serialize(TreeNode* root) 

{
    if(!root) 
    {
     return "NULL,";
    }
    return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) 
{
    queue<string> q;
    string s;
    for(int i=0;i < data.size(); i++)
    {
        if(data[i]==',')
        {
            q.push(s);
            s = "";
            continue;
        }
        s += data[i];
    }
    if(s.size() != 0)
    {
        q.push(s);
    }
    return deserialize_helper(q);
}

TreeNode* deserialize_helper(queue<string> &q) 
{
    string s = q.front();
    q.pop();
    if(s == "NULL") return NULL;
    TreeNode* root = new TreeNode(stoi(s));
    root->left = deserialize_helper(q);
    root->right = deserialize_helper(q);
    return root;
}


class Codec {
public:

    string serialize(TreeNode* root) 
    {
        return !root ? " null" : " " + to_string(root->val) + serialize(root->left) + serialize(root->right);
    }
	
    TreeNode* deserialize(string data) 
    {
        istringstream ss(data);
        return buildTree(ss);
    }
    
private:
    
    TreeNode* buildTree(istringstream& ss)
    {
        string s;
        ss >> s;
        
        if (s == "null")
			return NULL;
        
        TreeNode* node = new TreeNode(stoi(s));
        node->left = buildTree(ss);
        node->right = buildTree(ss);
            
        return node;
    }