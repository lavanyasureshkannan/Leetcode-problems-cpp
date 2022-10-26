#include<iostream>
#include<vector>
#include<numeric>
#include<stack>
#include<queue>
#include<climits>
using namespace std;



/*
For our BFS routine, we keep a queue, q to maintain the queue of cells to be examined next.
We start by adding all the cells with 0s to q.
Intially, distance for each 0 cell is 0 and distance for each 1 is INT_MAX, which is updated during the BFS.
Pop the cell from queue, and examine its neighbors. If the new calculated distance for neighbor {i,j} is smaller, we add {i,j} to q and update dist[i][j].

*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({ i, j }); //Put all 0s in the queue.
                }
            }
        }

        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
                if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
                    if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                        dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                        q.push({ new_r, new_c });
                    }
                }
            }
        }
        return dist;
    }
};

// TC: O(R.C)
// SC: O(R.C)