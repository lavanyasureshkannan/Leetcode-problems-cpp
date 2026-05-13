#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
*/

void display(vector<vector<int>>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=0; j<nums[0].size(); j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> k_closest_points(vector<vector<int>>& points, int k)
{
    vector<vector<int>> result;
    priority_queue<pair<int,pair<int,int>>> pq;
    for(int i=0; i<points.size(); i++)
    {
        int key = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
        pair<int,int> val = {points[i][0], points[i][1]};
        pq.push({key,val});

        if(pq.size() > k)
        {
            pq.pop();
        }
    }
    while(pq.size() > 0)
    {
        auto the_point = pq.top().second;
        result.push_back({the_point.first, the_point.second});
        pq.pop();
    }
    return result;
}

int main()
{
    vector<vector<int>> points = {{1,3},{-2,2}};
    k_closest_points(points, 1);
    return 0;
}