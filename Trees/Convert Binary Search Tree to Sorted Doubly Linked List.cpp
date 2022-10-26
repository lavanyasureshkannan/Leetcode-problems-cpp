#include<iostream>
#include<vector>
#include<numeric>
#include<stack>
#include<queue>
#include<climits>
using namespace std;

/*
Initiate the first and the last nodes as nulls.

Call the standard inorder recursion helper(root) :

If node is not null :

Call the recursion for the left subtree helper(node.left).

If the last node is not null, link the last and the current node nodes.

Else initiate the first node.

Mark the current node as the last one : last = node.

Call the recursion for the right subtree helper(node.right).

Link the first and the last nodes to close DLL ring and then return the first node.
*/

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution 
{
  public:
  // the smallest (first) and the largest (last) nodes
  Node* first = NULL;
  Node* last = NULL;

  void helper(Node* node) 
  {
    if (node) 
    {
      // left
      helper(node->left);
      // node 
      if (last) 
      {
        // link the previous node (last)
        // with the current one (node)
        last->right = node;
        node->left = last;
      }
      else {
        // keep the smallest node
        // to close DLL later on
        first = node;
      }
      last = node;
      // right
      helper(node->right);
    }
  }

  Node* treeToDoublyList(Node* root) {
    if (!root) return NULL;

    helper(root);
    // close DLL
    last->right = first;
    first->left = last;
    return first;
  }
};

