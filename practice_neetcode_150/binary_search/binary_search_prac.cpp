#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    SEARCH A 2D MATRIX
    Input: matrix = [[1,3,5,7],
                    [10,11,16,20],
                    [23,30,34,60]], target = 3
    Output: true 
*/

bool search_2d_matrix(vector<vector<int>>& matrix, int target)
{
    int row = matrix.size() - 1 ;
    int col = 0;
    while(row >= 0 && col < matrix[0].size())
    {
        if(matrix[row][col] < target) col ++;
        else if(matrix[row][col] > target) row --;
        else return true;
    }
    return false;
}
// TC: O(M + N)
// SC: O(1)

/********************************************************************************/
/*
    SEARCH IN ROTATED SORTED ARRAY
    Input: nums = [3,4,5,6,1,2], target = 1
    Output: 4
*/

int search_in_rotated_array(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while(left < right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] >= nums[left])
        {
            if(target < nums[mid] && target >= nums[left]) right = mid - 1;
            else left = mid + 1;
        }
        else
        {
            if(target > nums[mid] && target <= nums[right]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}

/*
    TIME BASED KEY VALUE PAIR
    Input: ["TimeMap", "set", "get", "get", "set", "get", "get"]
            [[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
    Output: [null, null, "bar", "bar", null, "bar2", "bar2"]
*/

class TimeMap
{
    public:
    TimeMap() {};
    unordered_map<string, vector<pair<string,int>>> mp; // key {value,timestamp}
    void set(string key, string value, int timestamp)
    {
        mp[key].emplace_back(value,timestamp);
    }
    string get(string key, int timestamp)
    {
        auto &values = mp[key];
        int left = 0;
        int right = values.size() - 1;
        string result = " ";
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(values[mid].second <= timestamp)
            {
                result = values[mid].first;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return result;
    }
};

int main()
{
    // vector<vector<int>>matrix = {{1,3,5,7},
    //                             {10,11,16,20},
    //                             {23,30,34,60}};
    // int target = 3;
    // cout << search_2d_matrix(matrix, target) << endl;

    // vector<int>nums = {3,4,5,6,1,2};
    // int target = 1;
    // cout << search_in_rotated_array(nums, target) << endl;

    TimeMap TM1;
    TM1.set("alice", "happy", 1);
    cout << TM1.get("alice", 1);
    return 0;
}