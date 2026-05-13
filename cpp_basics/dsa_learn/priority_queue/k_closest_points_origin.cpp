#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

/*
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
*/


vector<vector<int>> closest_points(vector<vector<int>>& points, int k)
{
    int x1 = 0;
    int y1 = 0;
    priority_queue<pair<int, pair<int,int>>> pq;
    for(int i=0; i<points.size(); i++)
    {
        int x2 = points[i][0];
        int y2 = points[i][1];
        int x_diff = (x1-x2);
        int y_diff = (y1-y2);
        int distance = x_diff * x_diff + y_diff * y_diff;
        pair<int,int> points = {x2,y2};
        pq.push({distance, points});
    }
    while(pq.size() > k)
    {
        pq.pop();
    }
    vector<vector<int>> result;
    while(pq.size() > 0)
    {
        auto point = pq.top().second;
        result.push_back({point.first, point.second});
        pq.pop();
    }
    return result;
}


int main()
{
    vector<vector<int>> points = {{1,3},{-2,2}};
    int k = 1;
    vector<vector<int>> result = closest_points(points, k);
    for(int i=0; i<result.size(); i++)
    {
        for(int j=0; j<result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}