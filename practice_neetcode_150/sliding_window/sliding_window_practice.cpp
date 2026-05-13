#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <climits>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

template<typename... Args>
void Log(Args... args)
{
    (cout << ... << args) << endl;
} 

// ***********************************************************************************

/*
    LONGEST SUBSTRING WO REPEATING CHARACTERS
    Input: s = "zxyzxyz"
    Output: 3
*/

// int longest_substring_wo_repeating_char(string s)
// {
//     int left = 0;
//     int right = 0;
//     int maxi = 0;
//     unordered_set<char> char_ss;
//     // base case
//     if(s.empty()) return 0;

//     while(right < s.length())
//     {
//         if(char_ss.find(s[right]) == char_ss.end())
//         {
//             char_ss.insert(s[right]);
//             maxi =max(maxi, right - left + 1);
//             right ++;
//         }
//         else
//         {
//             char_ss.erase(s[left]);
//             left ++;
//         }
//     }
//     return maxi;
// }

// // TC: O(N)
// // SC: O(N)

// ***********************************************************************************

/*
    MAXIMUM SUBARRAY OF SIZE K
    nums = [2,1,5,1,3,2], k = 3
    Output = 9
*/

// int maximum_subarray_size_k_bf(vector<int>& nums, int k)
// {
//     int n = nums.size();
//     int maxi = 0;
//     for(int i=0; i<=(n-k); i++)
//     {
//         int curr_sum = 0;
//         for(int j=i; j<(i+k); j++)
//         {
//             curr_sum += nums[j];
//         }
//         maxi = max(maxi, curr_sum);
//     }
//     return maxi;
// }
// // TC: O(N^2)
// // SC: O(1)

// int maximum_subarray_size_k_optimised(vector<int>& nums, int k)
// {
//     // base case
//     if(nums.size() == 0 || k == 0) return 0;
//     int curr_sum = 0;
//     for(int i=0; i<k; i++)
//     {
//         curr_sum += nums[i];
//     }
//     int maxi = curr_sum;
//     for(int i=k; i<nums.size(); i++)
//     {
//         curr_sum =  curr_sum + nums[i] - nums[i-k];
//         maxi = max(curr_sum, maxi);
//     }
//     return maxi;
// }

// TC: O(N) every element accessed once
// SC: O(1) constant space

/***************************************************************************************/

/*
    Input: s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"
*/

// string sliding_window_minimum_sub(string s, string t)
// {
//     unordered_map<char, int> target_freq;
//     for(int i=0; i<t.length(); i++)
//     {
//         target_freq[t[i]] ++;
//     }
//     int need = target_freq.size();
//     int have = 0;
//     int left = 0;
//     int right = 0;
//     unordered_map<char, int> window_freq;
//     int min_len = INT_MAX;
//     int start = 0;
//     while(right < s.length())
//     {
//         char curr_char = s[right];
//         // add curr_char to window freq
//         window_freq[curr_char] ++;
//         if(target_freq.count(curr_char) && target_freq[curr_char] == window_freq[curr_char]) 
//         {
//             have ++;
//         }
//         while(have == need)
//         {
//             int curr_len = right - left + 1;
//             if(curr_len < min_len)
//             {
//                 min_len = curr_len;
//                 start = left;
//             }
//             // shrinking part
//             char curr_left = s[left];
//             window_freq[curr_left] --;
//             if(target_freq.count(curr_left) && window_freq[curr_left] < target_freq[curr_left]) 
//             {
//                 have --;
//             }
//             left ++;
//         }
//         right ++;
//     }

//     if(min_len == INT_MAX) return "";
//     else return s.substr(start, min_len);
// }

// TC: O(|s|)
// SC: O(|s| + |t|) 

/**************************************************************************************/

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

// void print(vector<int>& nums)
// {
//     for(int i=0; i<nums.size(); i++)
//     {
//         cout << nums[i] << " ";
//     }
//     cout << endl;
// }

// vector<int> sliding_window_maximum_bf(vector<int>& nums, int k)
// {
//     int n = nums.size();
//     vector<int> result;
//     for(int i=0; i<=(n-k); i++)
//     {
//         int maxi = INT_MIN;
//         for(int j=i; j<(i+k); j++)
//         {
//             maxi = max(maxi, nums[j]);
//         }
//         result.push_back(maxi);
//     }
//     return result;
// }
// TC: O(N^2)
// SC: O(1) 

// vector<int> sliding_window_optimised(vector<int>& nums, int k)
// {
//     vector<int> result;
//     deque<int> dq;
//     for(int i=0; i<nums.size(); i++)
//     {
//         if(!dq.empty() && dq.front() < i-k+1) { dq.pop_front();}
//         while(!dq.empty() && nums[dq.back()] < nums[i]){ dq.pop_back();}
//         dq.push_back(i);
//         if(i >= (k-1)){ result.push_back(nums[dq.front()]);}
//     }
//     return result;
// }

// TC: O(N)
// SC: O(N)

/*********************************************************************************/ 
// MAX NUMBER OF VISIBLE POINTS
// Input: points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
// Output: 3

// int max_num_of_pts(vector<vector<int>>& points, int angle, vector<int>& location)
// {
//     vector<double> angles;
//     int x0 = location[0];
//     int y0 = location[1];

//     int same = 0;
//     for(auto &i: points)
//     {
//         int x1 = i[0];
//         int y1 = i[1];
//         // edge case
//         if(x1 == x0 && y1 == y0) same++;
//         double ang = atan2(x1-x0, y1-y0);
//         angles.push_back(ang);
//     }

//     sort(angles.begin(), angles.end());

//     // edge case 2 -> duplicate circular handling
//     for(int i=0; i<angles.size(); i++)
//     {
//         angles.push_back(angles[i] + 2*M_PI);
//     }

//     double rad = angle * M_PI / 180.0;
//     int i = 0;
//     int maxi_points = 0;
//     for(int j=0; j<angles.size(); j++)
//     {
//         while(angles[j] - angles[i] > rad)
//         {
//             i++;
//         }
//         maxi_points = max(maxi_points, j-i+1);
//     }
//     return maxi_points;
// }

/********************************************************************************/
// similar question to MAX VISIBLE POINTS -> but find the maximum number of points ID
    //  Given:
    // struct Tree => x,y, ID
    // Find: 
    // return the maximum number of points ID


// struct Tree
// {
//     double x;
//     double y;
//     int ID;
//     Tree(double m_x, double m_y, int m_ID)
//     {
//         x = m_x;
//         y = m_y;
//         ID = m_ID;
//     }
// };

// vector<int> visible_points(vector<Tree>& points, int angle)
// {
//     vector<pair<double,int>> angles;
//     // convert the points to angles
//     // origin
//     double x0 = 0.0;
//     double y0 = 0.0;

//     for(auto &i: points)
//     {
//         double x1 = i.x;
//         double y1 = i.y;
//         double ang = atan2(y1-y0,x1-x0);
//         angles.push_back({ang,i.ID});
//     }

//     sort(angles.begin(), angles.end());
//     int n = angles.size();
//     for(size_t i =0; i<n; i++)
//     {
//         angles.push_back({angles[i].first + 2* M_PI, angles[i].second});
//     }

//     size_t left = 0;
//     vector<int> result;
//     int best_left = 0;
//     int max_points = 0;
//     for(size_t right = 0; right<n; right++)
//     {
//         while(angles[right].first - angles[left].first > angle)
//         {
//             left ++;
//         }
//         int curr_points = right - left + 1;
//         if(left > best_left)
//         {
//             best_left = left;
//             max_points = curr_points;
//         }
//     }
//     for(size_t i=0; i<(best_left + max_points); i++)
//     {
//         result.push_back(angles[i].second);
//     }
//     return result;
// }

// TC: O(NlogN)
// SC: O(N)


/**************************************************************************************/
/***** LONGEST REPEATING CHAR DEVELOPEMENT*/
/*
/*
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
*/

int longest_repeating_char_dev(string s, int k)
{
    size_t left = 0;
    int freq[26] = {0}; // 26 alphabets
    size_t n = s.size();
    int max_freq = 0;
    int maxi = 0;
    for(size_t right = 0; right<n; right ++)
    {
        freq[s[right] - 'A'] ++; // {2,1}
        max_freq = max(max_freq, freq[s[right] - 'A']);
        int curr_window = right - left + 1;
        // curr_win - max_freq > k => shrink the window
        if((curr_window - max_freq) > k)
        {
            freq[s[right]] --;
            left++;
        } 
        maxi = max(maxi, curr_window);
    }
    return maxi;
}



/*
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
*/



int main()
{
    //string s = "zxyzxyz";
    //Log(longest_substring_wo_repeating_char(s));

    // vector<int> nums =  {2,1,5,1,3,2};
    // int k = 3;
    // Log(maximum_subarray_size_k_bf(nums,k));
    // Log(maximum_subarray_size_k_optimised(nums, k));

    // string s = "ADOBECODEBANC";
    // string t = "ABC";
    // Log(sliding_window_minimum_sub(s,t));

    // vector<int> nums = {1,2,1,0,4,2,6};
    // int k = 3;
    // vector<int> result = sliding_window_maximum_bf(nums,k);
    // vector<int> result_opt = sliding_window_optimised(nums, k);
    // print(result);
    // print(result_opt);

    // vector<vector<int>>points = {{2,1},{2,2},{3,3}};
    // int angle = 90;
    // vector<int> location = {1,1};
    //Log(max_num_of_pts(points,angle,location));

    // Tree t1(2,1,100);
    // Tree t2(2,2,91);
    // Tree t3(3,4, 80);
    // Tree t4(1,1, 50);
    // vector<Tree> points;
    // points.push_back(t1);
    // points.push_back(t2);
    // points.push_back(t3);
    // points.push_back(t4);
    // vector<int> res = visible_points(points, 20);
    // for(int i=0; i<res.size(); i++)
    // {
    //     cout << res[i] << " ";
    // }
    // return 0;

    Log(longest_repeating_char_dev("ABAB",2));
}
