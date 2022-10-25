
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution 
{
    public:
    Node* connect(Node* root)
    {
    // recurrsive aproach
    // base case
    if(root == NULL || root->left == NULL || root->right == NULL) return root;

    root->left->next = root->right;
    // for child nodes
    if(root->next != NULL)
    {
        root->right->next = root->next->left;
    }
    connect(root->left);
    connect(root->right);
    return root;

    }
};

// TC O(N)
// SC O(N)


//*******************************************************************************************************************************************



// BFS QUEUE

class Solution 
{
public:
Node* connect(Node* root)
{
    // base case
    if(root == NULL) return root;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        Node* prev = NULL; // previous null pointer
        for(int i =0; i<size; i++)
        {
            Node* curr = q.front();
            q.pop();
            // adding children back in the queue
            if(curr->right) q.push(curr->right);
            if(curr->left) q.push(curr->left);
            curr->next = prev;
            prev = curr; 
        }
    }
    return root;


}
};

// TC - O(N)
// SC - O(N)
