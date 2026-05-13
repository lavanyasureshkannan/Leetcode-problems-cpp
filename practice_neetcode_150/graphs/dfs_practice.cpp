#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

/*
    WORD SEARCH
    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    Output: true
*/

bool dfs(vector<vector<char>>& board, size_t i, size_t j, string word, int n)
{
    if(word.size() == n) return true;
    // boundary check
    if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] == '*') return false;
    board[i][j] = '*'; // visisted
    bool check_status = dfs(board, i+1, j, word, n+1) ||
                        dfs(board, i-1, j, word, n+1) ||
                        dfs(board, i, j+1, word, n+1) ||
                        dfs(board, i, j-1, word, n+1);
    board[i][j] = word[n];
    return check_status;
}


bool word_search(vector<vector<char>>& board, string word)
{
    for(size_t i=0; i<board.size(); i++)
    {
        for(size_t j=0; j<board[0].size(); j++)
        {
            if(board[i][j] == word[0])
            {
                if(dfs(board,i,j,word,0))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

/****************************************************************************************/
/*
    NUMBER OF ISLANDS
    Input: grid = [["1","1","1","1","0"],
                   ["1","1","0","1","0"],
                   ["1","1","0","0","0"],
                   ["0","0","0","0","0"]]
    Output: 1
*/

void dfs(vector<vector<char>>& grid, size_t i, size_t j)
{
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == '*') return;
    grid[i][j] = '*';
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
    dfs(grid,i,j+1);
    dfs(grid,i,j-1);
}

int num_of_islands(vector<vector<char>>& grid)
{
    int num_of_islands = 0;
    for(size_t i=0; i<grid.size(); i++)
    {
        for(size_t j=0; j<grid[i].size(); j++)
        {
            if(grid[i][j] == '1')
            {
                num_of_islands ++;
                dfs(grid,i,j);
            }
        }
    }
    return num_of_islands;
}

/***************************************************************************************/
/*
    MAX AREA ISLAND
    input : grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],
                    [0,0,0,0,0,0,0,1,1,1,0,0,0],
                    [0,1,1,0,1,0,0,0,0,0,0,0,0],
                    [0,1,0,0,1,1,0,0,1,0,1,0,0],
                    [0,1,0,0,1,1,0,0,1,1,1,0,0],
                    [0,0,0,0,0,0,0,0,0,0,1,0,0],
                    [0,0,0,0,0,0,0,1,1,1,0,0,0],
                    [0,0,0,0,0,0,0,1,1,0,0,0,0]]
    Output: 6 
*/


int dfs(vector<vector<int>>& grid, int i, int j)
{
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]== 0) return 0;
    grid[i][j] = 0;
    int result = 1;
    return result + dfs(grid,i+1,j) + dfs(grid,i-1,j) + dfs(grid,i,j+1) + dfs(grid,i,j-1);
}

int maxAreaIsland(vector<vector<int>>& grid)
{
    int max_area_island = 0;
    for(size_t i=0; i<grid.size(); i++)
    {
        for(size_t j=0; j<grid[0].size(); j++)
        {
            if(grid[i][j] == 1)
            {
                int curr_area = dfs(grid,i,j);
                max_area_island = max(max_area_island, curr_area);
            }
        }
    }
    return max_area_island;
}

/**********************************************************************************/
/*
    CLONE GRAPH
    Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
    Output: [[2,4],[1,3],[2,4],[1,3]]
*/

struct Node
{
    int val;
    vector<Node*> neighbours;
    Node(int m_val)
    {
        val = m_val;
        neighbours = vector<Node*> ();
    }
};

Node* clonegraph(Node* node)
{
    unordered_map<Node*, Node*> mp;
    if(mp.find(node) != mp.end())
    {
        return mp[node];
    }
    Node* new_node = new Node(node->val);
    mp[node] = new_node;
    for(auto neigh : node->neighbours)
    {
        new_node->neighbours.push_back(clonegraph(neigh));
    }
    return new_node;
}

/**************************************************************************************/
/*
    NUMBER OF DISTINCT ISLANDS
    Input: grid = [[1,1,0,0,0],
                   [1,1,0,0,0],
                   [0,0,0,1,1],
                   [0,0,0,1,1]]
    Output: 1
*/

void dfs(vector<vector<int>>& grid, int i, int j, int bi, int bj, vector<pair<int,int>>& s)
{
    if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || grid[i][j] == 0) return;
    grid[i][j] = 0;
    s.push_back({i-bi, j-bj});
    dfs(grid,i+1,j,bi,bj,s);
    dfs(grid,i-1,j,bi,bj,s);
    dfs(grid,i,j-1,bi,bj,s);
    dfs(grid,i,j+1,bi,bj,s);
}

int num_of_distinct_islands(vector<vector<int>>& grid)
{
    set<vector<pair<int,int>>> shapes_total;
    for(size_t i=0; i<grid.size(); i++)
    {
        for(size_t j=0; j<grid[0].size(); j++)
        {
            if(grid[i][j] == 1)
            {
                vector<pair<int,int>> shapes;
                dfs(grid,i,j,i,j,shapes);
                shapes_total.insert(shapes);
            }
        }
    }
    return (shapes_total.size());
}

int main()
{
    // vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
    //                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
    //                             {0,1,1,0,1,0,0,0,0,0,0,0,0},
    //                             {0,1,0,0,1,1,0,0,1,0,1,0,0},
    //                             {0,1,0,0,1,1,0,0,1,1,1,0,0},
    //                             {0,0,0,0,0,0,0,0,0,0,1,0,0},
    //                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
    //                             {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    // cout << maxAreaIsland(grid) << endl;

    // vector<vector<char>>grid = {{'1','1','1','1','0'},
    //                             {'1','1','0','1','0'},
    //                             {'1','1','0','0','0'},
    //                             {'0','0','0','0','0'}};
    
    // cout << num_of_islands(grid) << endl;

    // vector<vector<char>>board = {{'A','B','C','E'},
    //                              {'S','F','C','S'},
    //                              {'A','D','E','E'}};
    // string word = "ABCCED";
    // cout << word_search(board, word) << endl;

    // Node* node1 = new Node(1);
    // Node* node2 = new Node(2);
    // Node* node3 = new Node(3);
    // Node* node4 = new Node(4);

    // // neighbours
    // node1->neighbours = {node2, node4};
    // node2->neighbours = {node1, node3};
    // node3->neighbours = {node2, node4};
    // node4->neighbours = {node1, node3};

    // clonegraph(node1);


    vector<vector<int>>grid = {{1,1,0,0,0},
                        {1,1,0,0,0},
                        {0,0,0,1,1},
                        {0,0,0,1,1}};

    cout << num_of_distinct_islands(grid) << endl;
    return 0;
}