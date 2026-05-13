#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//////////////////// SLOW FAST ALGORITHM //////////////////////////
int find_duplicate_floyd(vector<int>& nums){
    int slow = nums[0];
    int fast = nums[0];
    // detect the cycyle
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];

    } while (slow != fast);
    // find the entry point
    slow = nums[0];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow; 
}

class happy_num{
    public:
    int calculate_sum(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            int digit = n % 10; 
            sum += (digit * digit);
            n = n/10; 
        }
        return sum;
    }
    bool isHappy(int n)
    {
        int slow = n;
        int fast = calculate_sum(n);
        while(fast != 1 && slow != fast)
        {
            slow = calculate_sum(slow);
            fast = calculate_sum(calculate_sum(fast));
        }
        return fast == 1;
    }};

struct Node
{
    int val; 
    Node* next;
    vector<Node*> neighbours; 
    Node(int m_val){
        val = m_val;
        next = nullptr;
        neighbours = vector<Node*> ();
    }
};
bool hascycle(Node* head)
{
    if(head == NULL) return false;
    Node* slow = head;
    Node* fast = head;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        return true;
    }
    return false;
}
//////////////////// DFS //////////////////////
unordered_map<Node*, Node*> mp;
Node* clonegraph(Node* node)
{
    if(!node) return nullptr;
    if(mp.find(node) != mp.end()) return mp[node];
    Node* new_node = new Node(node->val);
    mp[node] = new_node;
    for(Node* neigh : node->neighbours)
    {
        new_node->neighbours.push_back(clonegraph(neigh));
    }
    return new_node;
}

class TreeNode
{
    public:
    int val; TreeNode* left; TreeNode* right;
    TreeNode(int m_val) { val = m_val; left = nullptr; right = nullptr;}
};
bool path_sum(TreeNode* root, int targetSum)
{
    if(!root) return false;
    targetSum = targetSum - root->val;
    if(!root->left && !root->right)
    {
        return(targetSum == 0);
    }
    return path_sum(root->left, targetSum) || path_sum(root->right, targetSum);
}

/*
    Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
    Output: [[5,4,11,2],[5,8,4,5]]
*/
class pathsum2
{
    public:
    void dfs(TreeNode* root, vector<vector<int>>& result, vector<int>& path, int target)
    {
        if(!root) return;
        path.push_back(root->val);
        target = target - root->val;
        if(!root->left && root->right && target == 0)
        {
            result.push_back(path);
        }
        dfs(root->left, result, path, target);
        dfs(root->right, result, path, target); 
        path.pop_back();
    }
    vector<vector<int>> path_sum(TreeNode* root, int target)
    {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, result, path, target);
        return result;
    }
}
int main()
{
    return 0;
}