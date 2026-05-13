#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//////////////// BFS /////////////////////////////
struct TreeNode
{
    int val; TreeNode* left; TreeNode* right;
    TreeNode(int m_val)
    {
        val = m_val; left = nullptr; right = nullptr;
    }
};
vector<vector<int>> binary_level_order_traversal(TreeNode* root)
{
    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        vector<int> level_nodes;
        for(int i=0; i<q.size(); i++)
        {
            TreeNode* front = q.front();
            q.pop();
            if(front->left) {q.push(front->left);}
            if(front->right){q.push(front->right);}
            level_nodes.push_back(front->val);
        }
        result.push_back(level_nodes);}
}


vector<int> course_Scehdule(vector<vector<int>>& prerequisites, int numCourses)
{
    // vector -> adjacency list
    vector<vector<int>> adjacency_list(numCourses);
    for(auto pre : prerequisites)
    {
        int from = pre[1];
        int to = pre[0];
        adjacency_list[from].push_back(to);
    }

    // calculate the number of indegree
    vector<int> indegree(numCourses,0);
    for(int i=0; i<numCourses; i++)
    {
        for(int neigh : adjacency_list[i])
        {
            indegree[neigh] ++;
        }
    }

    // create a queue and indegree of value 0
    queue<int> q;
    for(int i=0; i<numCourses; i++)
    {
        if(indegree[i] == 0){q.push(i);}
    }
    // iterate through queue and add its neighbours
    vector<int> result;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        result.push_back(front);
        for(int neigh : adjacency_list[front])
        {
            indegree[neigh] --;
            if(indegree[neigh] == 0){q.push(neigh);}
        }
    }
    if(result.size() == numCourses) return result;
    else return {};
}
class _subsets
{
    public:
    void backtrack(int index, vector<int>& nums, vector<int>& sub, vector<vector<int>>& result)
    {
    result.push_back(sub);
    for(int i=index; i<nums.size(); i++)
    {
        sub.push_back(nums[i]);
        backtrack(i+1, nums, sub, result);
        sub.pop_back();
    }
    }
    vector<vector<int>> subset(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> sub;
        backtrack(0, nums, sub, result);
        return result;
}};

class permuattaions
{
    void backtrack(vector<int>& nums, vector<int>& paths, vector<bool>& visited, vector<vector<int>>& result)
    {
        if(paths.size() == nums.size())
        {
            result.push_back(paths);
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(visited[i]) continue;
            visited[i] = true;
            paths.push_back(nums[i]);
            backtrack(nums, paths, visited, result);
            paths.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permutations(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> paths;
        vector<bool> visited(nums.size(), false);
        backtrack(nums,paths,visited, result);
        return result;
    }
};

class combination{
    void backtrack(int index, vector<vector<int>>& result, vector<int>& paths, vector<int>& candidates, int target)
    {
        if(target == 0){
        result.push_back(paths);
        return;}
        if(target < 0) return;
        for(int i=index; i<candidates.size(); i++)
        {
            // candidates[i] + x = target
            // x = target - candidates[i]
            paths.push_back(candidates[i]);
            backtrack(i, result, paths, candidates, target - candidates[i]);
            paths.pop_back();
        }      
    }
    vector<vector<int>> combination_Sum(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> paths;
        backtrack(0, result, paths, candidates, target);
        return result;
    }
};

/////////////////////////////////// TWO POINTERS //////////////////////////////////

vector<vector<int>> three_sum_two_pointers(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for(int i=0; i<nums.size(); i++)
    {
        int left = 0; 
        int right = nums.size() -1 ;
        if(i > 0 && (nums[i] == nums[i-1])) continue;
        while(left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});
                while(left < right && nums[left] == nums[left + 1]) left ++;
                while(left < right && nums[right] == nums[right - 1]) right --;
                left ++;
                right --;
            }
            else if(sum < 0){left ++;}
            else{right --;}
        }
    }
    return result;
}
vector<int> sort_colors(vector<int>& nums)
{
    int left = 0;
    int right = nums.size() -1;
    int mid = 0;
    while(left < right && mid <= right)
    {
        if(nums[mid] == 0)
        {
            swap(nums[left], nums[mid]);
            left++;
            mid++;
        }
        else if(nums[mid] == 1){mid++;}
        else{swap(nums[mid], nums[right]);right --;}
    }
    return nums;
}



