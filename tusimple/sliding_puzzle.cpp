#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

/*
    SLIDING PUZZLE
    1. find the all possible direction in which the numbers can be swapped     // 0 1 2
                                                                                // 3 4 5
        considering the indexes here 0 can be swapped with 1 and 3.
                                    1 can be swapped with 0, 2, 4
                                    .....
                                    5 can be swapped with 2,4
    2. create a empty string and add all the intial values
    3. bfs with queue  
*/

int slidingPuzzle(vector<vector<int>>& board)
{
    string end = "123450";
    string begin = ""; // curr input string 
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[0].size(); j++)
        {
            begin += to_string(board[i][j]);
        }
    }
    // directions -> in how many ways the curr element can move
    vector<vector<int>> directions = {{1,3},{0,2,4},{1,5},
                                    {0,4},{1,3,5},{4,2}};
    unordered_set<string> visited;
    visited.insert(begin);
    queue<pair<string, int>> q;
    q.push({begin, 0});
    while(!q.empty())
    {
        auto pair_ = q.front();
        q.pop();
        string curr_str = pair_.first;
        int distance = pair_.second;
        // now we need to find 0;
        if(curr_str == end)
        {
            return distance;
        }
        int idx = curr_str.find("0");
        for(auto &i : directions[idx])
        {
            string next = curr_str;
            swap(next[idx], next[i]);
            if(!visited.count(next))
            {
                visited.insert(next);
                q.push({next, distance+1});
            }

        }

    }
    return -1;

}

// TC: O(N)
// SC: O(N)


int main()
{
    string begin = "";
    vector<vector<int>> board = {{4,1,2},{5,0,3}};
    for(int i = 0; i<board.size(); i++)
    {
        for(int j=0; j<board[0].size(); j++)
        {
            begin += to_string(board[i][j]);
        }
    }
    cout << begin;
    return 0;
}