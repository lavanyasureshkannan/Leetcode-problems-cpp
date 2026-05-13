#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

/*
Input: points = [[0,2],[2,2]], k = 1
Output: [[0,2]]
*/
/*
(0,0) => (2,2) =>(-2,-2)
*/

vector<vector<int>> k_closest_point(vector<vector<int>>& points, int k)
{
    vector<vector<int>> result;
    priority_queue<pair<int, pair<int,int>>> pq; // [distance, {point 1, point 2}}
    for(int i=0; i<points.size(); i++)
    {
        int distance = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
        pair<int,int> p = {points[i][0], points[i][1]};
        pq.push({distance, p});
        if(pq.size() > k)
        {
            pq.pop();
        }
    }
    while(!pq.empty())
    {
        auto pair = pq.top().second;
        result.push_back({pair.first, pair.second});
        pq.pop();
    }
    return result;
}

int main()
{
    vector<vector<int>>points = {{0,2},{2,2}};
    int k = 1;
    vector<vector<int>> result = k_closest_point(points, k);
    for(int i=0; i<result.size(); i++)
    {
        for(int j=0; j<result[0].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}