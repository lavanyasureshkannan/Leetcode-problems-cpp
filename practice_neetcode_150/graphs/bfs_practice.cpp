#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_set>
using namespace std;

/*
    QUEUE
    BINARY LEVEL ORDER TRAVERSAL
    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[9,20],[15,7]]
*/

struct Tree
{
    int val;
    Tree* left;
    Tree* right;

    Tree(int m_val)
    {
        val = m_val;
        left = nullptr;
        right = nullptr;
    }
};

vector<vector<int>> level_order(Tree* root)
{
    // base case
    if(root == nullptr) return {};
    vector<vector<int>> result;
    queue<Tree*> q;
    q.push(root);
    while(!q.empty())
    {
        vector<int> levels;
        int q_size = q.size();
        for(size_t i =0; i<q_size; i++)
        {
            auto curr = q.front();
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
    return result;
}

// TC: O(N) => nodes n/2
// SC: O(N) => vector o/p

/*********************************************************************************/
/*
    COURSE SCHEDULE
    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: true
*/

bool course_scheudle(vector<vector<int>>& prerequisites, int numCourses)
{
    //1. convert this to adjacency list
    vector<vector<int>> adj_list(numCourses);
    for(auto pre: prerequisites)
    {
        int from = pre[1];
        int to = pre[0];
        adj_list[from].push_back(to);
    }
    //2. calculate the indegrees
    vector<int> indegrees(numCourses,0);
    for(size_t i=0; i<numCourses; i++)
    {
        for(auto neigh : adj_list[i])
        {
            indegrees[neigh] ++;
        }
    }
    //3. add the indegree of nodes that has 0 to q
    queue<int> q;
    for(size_t i = 0; i<indegrees.size(); i++)
    {
        if(indegrees[i] == 0)
        {
            q.push(i);
        }
    }
    //4. jump into q and add neighbours decrement your indegrees
    vector<int> result;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        result.push_back(front);
        for(int neigh : adj_list[front])
        {
            indegrees[neigh] --;
            if(indegrees[neigh] == 0)
            {
                q.push(neigh);
            }
        }
    }
    //5. result.size() == numCourses
    if(result.size() == numCourses) return true;
    else return false;
}

/***************************************************************************/
/*
    COURSE SCHEDULE 2
    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: [0,1]
*/

vector<int> course_schedule_2(vector<vector<int>>& prerequisites, int numCourses)
{
    
    vector<vector<int>> adj_list(numCourses);
    for(auto &pre: prerequisites)
    {
        int from = pre[1];
        int to = pre[0];
        adj_list[from].push_back(to);
    }
    vector<int> indegrees(numCourses,0);
    for(size_t i =0; i<numCourses; i++)
    {
        for(auto neigh : adj_list[i])
        {
            indegrees[neigh] ++;
        }
    }
    queue<int> q;
    for(size_t i =0; i<indegrees.size(); i++)
    {
        if(indegrees[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> result;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        result.push_back(curr);
        for(int neigh : adj_list[curr])
        {
            indegrees[neigh] --;
            if(indegrees[neigh] == 0)
            {
                q.push(neigh);
            }
        }
    }
    if(result.size() != numCourses) return {};
    return result;
}

// TC: O(V+E) (v-> numcourse, E->prerequisites) each node processed atleast once
// SC: O(V+E) 

/*******************************************************************************/
/*
    ROTTEN ORANGES
    Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
    Output: 4
    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.
*/

int rotten_oranges(vector<vector<int>>& grid)
{
    // base case
    if(grid.size() == 0) return 0;
    int fresh = 0;
    int minutes = 0;
    queue<pair<int,int>> q;
    for(size_t i = 0; i < grid.size(); i++)
    {
        for(size_t j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j] == 1) 
            {
                fresh ++;
            }
            else if(grid[i][j] == 2)
            {
                q.push({i,j});
            }
        }
    }
    int rows = grid.size();
    int cols = grid[0].size();
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    while(!q.empty())
    {
        int q_size = q.size();
        for(size_t i =0; i<q_size; i++)
        {
            auto[r,c] = q.front();
            q.pop();

            for(size_t i =0; i<4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >=0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1)
                {
                    grid[nr][nc] = 2;
                    fresh --;
                    q.push({nr,nc});
                }
            }
        }
        if(!q.empty())
        {
            minutes ++;
        }
    }
    if(fresh == 0) return minutes;
    else return -1;
}

// TC: O(MxN)
// SC: O(MxN)

/**********************************************************************************/
/*
    WALL AND GATES
    Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
    Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
    -1 A wall or an obstacle.
    0 A gate.
*/
void print(vector<vector<int>>& rooms)
{
    for(int i=0; i<rooms.size(); i++)
    {
        for(int j=0; j<rooms[i].size(); j++)
        {
            cout << rooms[i][j] << " ";
        }
        cout << endl;
    }
}
void wall_and_gates(vector<vector<int>>& rooms)
{
    if(rooms.size() == 0) return;
    int rows = rooms.size();
    int cols = rooms[0].size();

    queue<pair<int,int>> q;
    for(size_t i =0; i<rows; i++)
    {
        for(size_t j=0; j<cols; j++)
        {
            if(rooms[i][j] == 0)
            {
                q.push({i,j});
            }
        }
    }

    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};
    while(!q.empty())
    {
        auto[r,c] = q.front();
        q.pop();

        for(size_t i=0; i<4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nc >= 0 && nr < rows && nc < cols && rooms[nr][nc] == INT_MAX)
            {
                rooms[nr][nc] = rooms[r][c] + 1;
                q.push({nr,nc});
            }
        }
    }
    print(rooms);
}

// TC: O(MxN)
// SC: O(MxN)

/**********************************************************************************/
/*
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", 
            which is 5 words long.
*/

int word_ladder(string beginWord, string endWord, vector<string>& wordList)
{
    unordered_set<string> dictionary(wordList.begin(), wordList.end()); 
    if(!dictionary.count(endWord)) return 0; 
    queue<string> q;
    q.push(beginWord);
    
    if(dictionary.count(beginWord))
    {   
       dictionary.erase(beginWord);
    }
    int steps = 1;

    while(!q.empty())
    {
        size_t q_size = q.size();
        for(size_t i=0; i<q_size; i++)
        {
            string curr_word = q.front();
            q.pop();
            if(curr_word == endWord) return steps;
            for(size_t s=0; s<curr_word.size(); s++)
            {
                char curr_char = curr_word[s];
                for(char c='a'; c<='z';c++)
                {
                    if(c == curr_char) continue;
                    curr_word[s] = c;
                    if(dictionary.count(curr_word))
                    {
                        q.push(curr_word);
                        dictionary.erase(curr_word);
                    }
                }
                curr_word[s] = curr_char;
            }
        } 
        steps ++;
    }
    return 0;   
}


int shortesth_path(vector<vector<int>>& grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    int dr[8] = {0,1,1,1,0,-1,-1,-1};
    int dc[8] = {1,1,0,-1,-1,-1,0,1};
    queue<pair<int,int>> q;
    int sr = 0;
    int sc = 0;
    q.push({sr,sc});

    grid[sr][sc] = 1;
    int distance = 1;

    while(!q.empty())
    {
       int q_size = q.size();
       for(size_t i=0; i<q_size; i++)
       {
          auto[r,c] = q.front();
          q.pop();
          if(r == rows-1 && c==cols-1) return distance;
          for(size_t d=0; d<8; d++)
          {
            int nr = r+dr[d];       
            int nc = c+dc[d];
            if(nr >=0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 0)
            {
                grid[nr][nc] = 1;
                q.push({nr,nc});
            }
          }
       }
       distance ++;
    }
    return -1;
}

// TC: O(MxN)
// SC: O(MxN)

/********************************************************************************/
/*
    Input: x = 2, y = 1
    Output: 1
    Explanation: [0, 0] → [2, 1]
*/

int minKnightmoves(int x, int y)
{
    int dr[8] = {2,2,1,1,-1,-1,-2,-2};
    int dc[8] = {1,-1,2,-2,2,-2,1,-1};
    int min_steps = 0;
    queue<pair<int,int>> q;
    q.push({0,0});
    vector<vector<bool>> visited(605,vector<bool>(605, false));
    visited[300][300] = true;
    while(!q.empty())
    {
        int q_size = q.size();
        for(size_t i=0; i<q_size; i++)
        {
            auto[r,c] = q.front();
            q.pop();
            if(r == x && c == y) return min_steps;
            for(size_t d=0; d<8; d++)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr >= -300 && nr <= 300 && nc >= -300 && nc <= 300 && !visited[nr+300][nc+300])                {
                    visited[nr+300][nc+300] = true;
                    q.push({nr,nc});
                }

            }
        }
        min_steps ++;
    }
    return -1;
}


int main()
{
    // Tree* root = new Tree(3);
    // root->left = new Tree(9);
    // root->right = new Tree(20);
    // root->right->left = new Tree(15);
    // root->right->right = new Tree(7);

    // vector<vector<int>> result = level_order(root);
    // for(size_t i =0; i< result.size(); i++)
    // {
    //     for(size_t j = 0; j<result[i].size(); j++)
    //     {
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    // int numCourses = 4;
    // vector<vector<int>> prerequisites =  {{1,0},{2,0},{3,1},{3,2}};
    // vector<int> result =  course_schedule_2(prerequisites, numCourses);
    // for(size_t i =0; i<result.size(); i++)
    // {
    //     cout << result[i] << " " << endl;
    // }
    // cout << endl;


    // vector<vector<int>>grid = {{2,1,1},{1,1,0},{0,1,1}};
    // cout << rotten_oranges(grid) << endl;


    // vector<vector<int>> rooms =  {{2147483647,-1,0,2147483647},
    //                                 {2147483647,2147483647,2147483647,-1},
    //                                 {2147483647,-1,2147483647,-1},
    //                                 {0,-1,2147483647,2147483647}};
    // wall_and_gates(rooms);


    // string beginWord = "hit";
    // string endWord = "cog";
    // vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    // cout << word_ladder(beginWord, endWord, wordList);

    cout << minKnightmoves(2, 1);
    return 0;
}