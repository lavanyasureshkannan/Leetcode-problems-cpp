#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
Input: points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
Output: 3
Explanation: The shaded region represents your field of view. 
All points can be made visible in your field of view, 
including [3,3] even though [2,2] is in front and in the same line of sight.
*/


int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) 
{
    vector<double> ang;
    //int same = 0;
    
    int x0 = location[0];
    int y0 = location[1];

    // Step 1: convert to angles
    for (auto &p : points) 
    {
        int x = p[0], y = p[1];
        // if (x == x0 && y == y0) 
        // {
        //     same++;
        //     continue;
        // }
        ang.push_back(atan2(y - y0, x - x0));
    }

    // Step 2: sort
    sort(ang.begin(), ang.end());
    int n = ang.size();

    // // Step 3: duplicate for circular handling
    // for (int i = 0; i < n; i++) {
    //     ang.push_back(ang[i] + 2 * M_PI);
    // }

    double rad = angle * M_PI / 180.0;
    // Step 4: sliding window
    int i = 0;
    int ans = 0;

    for (int j = 0; j < ang.size(); j++) 
    {
        while (ang[j] - ang[i] > rad) 
        {
            i++;
        }
        ans = max(ans, j - i + 1);
    }
    return ans; // + same;
}

int main()
{
    vector<vector<int>>points = {{2,1},
                                {2,2 },
                                {3,3 }};
                    int angle = 90;
                    vector<int> location = {1,1};
    cout << visiblePoints(points, angle, location);
    return 0;
}