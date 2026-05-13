#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
    Similar question as leetcode 1610. Maximum Number of Visible Points with few modifications

    Given:
    struct Tree => x,y, ID
    Find: 
    return the maximum number of points ID
*/

struct Tree
{
    double x;
    double y;
    int ID;
    Tree(double m_x, double m_y, int m_ID)
    {
        x = m_x;
        y = m_y;
        ID = m_ID;
    }
};

vector<int> visible_points(vector<Tree>& points, double angle)
{
    // 1. convert the given points to angle
    vector<pair<double,int>> angles;
    // intial location origin
    double x = 0;
    double y = 0;
    //int same = 0;
    for(auto& val : points)
    {
        double x1 = val.x;
        double y1 = val.y;
        // if(x1 == 0 && y1 == 0)
        // {
        //     same ++;
        //     continue;
        // }
        double ang = atan2(y1-y, x1-x);
        angles.push_back({ang, val.ID});
    }
    // convert to rad
    angle = angle * M_PI / 180.0;
    // 2. sort all the angles
    sort(angles.begin(), angles.end());

    // use circular wrap for points beyond 360
    int n = angles.size();
    for(int i=0; i<n; i++)
    {
        angles.push_back({angles[i].first + 2 * M_PI, angles[i].second});
    }
    // 3. use sliding window to keep track of the max window
    int left = 0;
    int max_points = 0;
    int best_left = 0;
    for(int right = 0; right < angles.size(); right ++)
    {
        while((angles[right].first - angles[left].first) > angle) left ++;
        int curr_points = right - left + 1;
        if(curr_points > max_points)
        {
            best_left = left;
            max_points = curr_points;
        }
    }
    vector<int> result;
    // for unique vals
    for(int i=best_left; i<best_left+max_points; i++)
    {
        result.push_back(angles[i].second);
    }
    return result;
}

int main()
{
    
    Tree t1(2,1,100);
    Tree t2(2,2,91);
    Tree t3(3,4, 80);
    Tree t4(1,1, 50);
    vector<Tree> points;
    points.push_back(t1);
    points.push_back(t2);
    points.push_back(t3);
    points.push_back(t4);
    vector<int> res = visible_points(points, 20);
    for(int i=0; i<res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}