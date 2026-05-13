#include <iostream>
#include <climits>
using namespace std;

/*
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
*/

struct Node
{
    int val;
    Node* right;
    Node* left;

    Node(int m_val)
    {
        val = m_val;
        right = nullptr;
        left = nullptr;
    }
};


class solution
{
    public:
    int max_sum = INT_MIN;
    int dfs(Node* root)
    {
        if(!root) return 0;
        // go left
        int left_gain = max(0, dfs(root->left));
        int right_gain = max(0, dfs(root->right));

        int maxi = root->val + left_gain + right_gain;
        max_sum = max(max_sum, maxi);
        return (root->val + max(left_gain, right_gain));
    }

    int max_path_sum(Node* root)
    {
        dfs(root);
        return max_sum;
    }
};


int main()
{
    Node* root = new Node(1);
    root ->left= new Node(2);
    root->right = new Node(3);

    solution s1;
    cout << s1.max_path_sum(root) << endl;
    return 0;
}