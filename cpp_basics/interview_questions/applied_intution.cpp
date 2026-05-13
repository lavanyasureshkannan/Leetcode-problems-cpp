#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
    3d_points = {{1,0,0},{0,0,1},{1,0,1},{1,0,0},{1,1,0},{0,0,1}}
    return unique points and their indexes
*/

void print_2d(vector<vector<int>>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=0; j<nums[i].size(); j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

struct vectorhash
{
    int operator()(const vector<int>& v) const
    {
        int hash = 0;
        for(int i:v)
        {
            hash ^= hash * 31 + std::hash<int>()(i);
        }
        return hash;
    }
};

pair<vector<vector<int>>, vector<int>> unique_points(vector<vector<int>>& points)
{
    vector<vector<int>> unique_points;
    vector<int> unique_indexes;

    unordered_set<vector<int>, vectorhash> seen;
    for(int i=0; i<points.size(); i++)
    {
        if(seen.insert(points[i]).second)
        {
            unique_points.push_back(points[i]);
            unique_indexes.push_back(i);
        }
    }
    print_2d(unique_points);
    return {unique_points, unique_indexes};
}

int main()
{
    vector<vector<int>> points = {{1,0,0},{0,0,1},{1,0,1},{1,0,0},{1,1,0},{0,0,1}};
    unique_points(points);
    return 0;
}