#include <iostream>
#include <unordered_set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

/*
Input: s = "abcabcbb"
Output: 3
*/

int longest_substring(const std::string& s)
{
    int left = 0;
    int right = 0;
    int maxi = 0;
    std::unordered_set<char> char_ss;
    while(right < s.length())
    {
        if(char_ss.find(s[right]) == char_ss.end())
        {
            char_ss.insert(s[right]);
            maxi = std::max(maxi, right - left + 1);
            right ++;
        }
        else
        {
            char_ss.erase(s[left]);
            left ++;
        }
    }
    return maxi;
}


/*
Input: points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
Output: 3
*/

struct Tree
{
    double x;
    double y;
    int ID;
    Tree(double mx, double my, int m_id) : x(mx) , y(my), ID(m_id) {};
};

vector<int> num_of_visible_points(const vector<Tree>& points, double angle_rad, const vector<int>& location)
{
    // 1. convert all the points to angles
    vector<pair<double, int>> angles;
    angle_rad = angle_rad * M_PI / 180;

    double x = location[0];
    double y = location[1];
    int same_points = 0;
    for(auto i : points)
    {
        // atan2(y-y1, x-x1)
        double x1 = i.x;
        double y1 = i.y;
        // edge case 1
        if(x1==x && y1==y)
        {
            same_points ++;
            continue;
        }
        double ang = atan2(y1-y, x1-x);
        angles.push_back({ang, i.ID}); 
    }

    // 2. Sort all the angles
    sort(angles.begin(), angles.end());

    // edge case 2
    int n = angles.size();
    for(size_t i=0; i<n; i++)
    {
        angles.push_back({angles[i].first + 2 * M_PI, angles[i].second});
    }
    // 3. sliding window to get the maximum
    int max_points = 0;
    int best_left = 0;
    int left = 0;
    vector<int> results;
    for(int right = 0; right < angles.size(); right++)
    {
        while((angles[right].first - angles[left].first) > angle_rad)
        {
            left ++;
        }
        int curr_points = right - left + 1;
        if(curr_points > max_points)
        {
            best_left = left;
            max_points = curr_points;
        }
        //max_points = max(max_points, right - left + 1);
    }
    for (size_t i = best_left; i < (best_left + max_points); i++)
    {
        results.push_back(angles[i].second);
    }
    return results;
    //return max_points + same_points;
}


/*
/*
["MedianFinder", "addNum", "1", "findMedian", "addNum", "3" "findMedian", "addNum", "2", "findMedian"]
Output:
[null, null, 1.0, null, 2.0, null, 2.0]
Explanation:
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.findMedian(); // return 1.0
medianFinder.addNum(3);    // arr = [1, 3]
medianFinder.findMedian(); // return 2.0
medianFinder.addNum(2);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
*/

class Median_bf
{
    private:
    vector<double> nums;
    public:
    Median_bf() {}
    void addNum(double num)
    {
        nums.push_back(num);
    }
    double findMedian()
    {
        double result = 0;
        size_t n = nums.size();
        if(n%2 != 0)
        {
            result = (nums[n/2]);
        }
        else
        {
            result = (nums[n/2] + nums[n/2-1]) / 2; 
        }
        return result;
    } 
    
};


class Median_optimised
{
    private:
    priority_queue<double> pq_left;
    priority_queue<double, vector<double>, greater<double>> pq_right;

    public:
    void addNum(double val)
    {
        pq_left.push(val);
        pq_right.push(pq_left.top());
        pq_left.pop();
        // balance
        if(pq_right.size() > pq_left.size())
        {
            pq_left.push(pq_right.top());
            pq_right.pop();
        }
    }
    double findMedian()
    {
        double result = 0.0;
        if(pq_left.size() == pq_right.size())
        {
            result = (pq_left.top() + pq_right.top()) / 2.0;
        }
        else
        {
            result = pq_left.top();
        }
        return result;
    }
};


/*
Input: nums = [1,2,1,0,4,2,6], k = 3
Output: [2,2,4,4,6]

Explanation:
Window position            Max
---------------           -----
[1  2  1] 0  4  2  6        2
 1 [2  1  0] 4  2  6        2
 1  2 [1  0  4] 2  6        4
 1  2  1 [0  4  2] 6        4
 1  2  1  0 [4  2  6]       6
*/

vector<int> sliding_window_max_bf(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<int> results;
    for(size_t i=0; i<=(n-k); i++)
    {
        int curr_max = INT_MIN;
        for(size_t j=i; j<(i+k); j++)
        {
            curr_max = max(nums[j], curr_max);
        }
        results.push_back(curr_max);
    }
    return results;
};

vector<int> sliding_window_dq(vector<int>& nums, int k)
{
    vector<int> results;
    deque<int> dq;
    for(size_t i=0; i<nums.size(); i++)
    {
        if(!dq.empty() && dq.front() < i-k+1)
        { 
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()] < nums[i])
        { 
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k-1)
        { 
            results.push_back(nums[dq.front()]); 
        }
        
    }
    return results;
}

/*
Input: grid = [[1,1,0],[0,1,1],[0,1,2]]
Output: 4

0 representing an empty cell
1 representing a fresh fruit
2 representing a rotten fruit
*/

int rotten_oranges(vector<vector<int>>& grid)
{
    queue<pair<int,int>> q;
    int fresh = 0;
    for(size_t i=0; i<grid.size(); i++)
    {
        for(size_t j=0; j<grid[i].size(); j++)
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
    int minutes = 0;
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,1,-1};
    int row = grid.size();
    int col = grid[0].size();

    while(!q.empty())
    {
        int q_size = q.size();
        for(size_t i=0; i<q_size; i++)
        {
            auto [r,c] = q.front();
            q.pop();

            for(size_t i=0; i<4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nc >= 0 && nr < row && nc < col && grid[nr][nc] == 1)
                {
                    grid[nr][nc] = 2;
                    fresh -- ;
                    q.push({nr,nc});
                } 
            }
        }
        if(!q.empty())
        { minutes ++;
        }
    }
    if(fresh == 0) return minutes;
    else return -1;
}

int main()
{
    //string s = "abcabcbb";
    // cout << longest_substring(s) << endl;

    // Median_optimised median_finder;
    // median_finder.addNum(1.0);
    // median_finder.addNum(2.0);
    // median_finder.addNum(3.0);
    // median_finder.addNum(4.0);
    // cout << median_finder.findMedian() << endl;

    // vector<int> nums = {1,2,1,0,4,2,6};
    // int k = 3;
    // vector<int> results = sliding_window_dq(nums, k);
    // for(size_t i=0; i<results.size(); i++)
    // {
    //     cout << results[i] << " " ;
    // }
    // cout << endl;

    vector<vector<int>> grid = {{1,1,0},{0,1,1},{0,1,2}};
    cout << rotten_oranges(grid);

    return 0;
}