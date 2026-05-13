#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]

Explanation: 
The number of soldiers in each row is: 
- Row 0: 2 
- Row 1: 4 
- Row 2: 1 
- Row 3: 2 
- Row 4: 5 
The rows ordered from weakest to strongest are [2,0,3,1,4].
*/


vector<int> k_weakest_rows(vector<vector<int>>& nums, int k)
{
    // Calculate row 
    vector<pair<int,int>> strength; // (rows, num of soldiers)
    for(int i=0; i<nums.size(); i++)
    {
        int soldiers = 0;
        for(int j=0; j<nums[i].size(); j++)
        {
            if(nums[i][j] == 1){soldiers ++;}
            else break;
        }
        strength.push_back({soldiers, i});
    }

    // sort the strength matrix
    sort(strength.begin(), strength.end());
    vector<int> result;
    for(int i=0; i<k; i++)
    {
        result.push_back(strength[i].second);
    }
    return result;
}

int main()
{
    vector<vector<int>> nums = {{1,1,0,0,0},
                                {1,1,1,1,0},
                                {1,0,0,0,0},
                                {1,1,0,0,0},
                                {1,1,1,1,1}};
    vector<int> result = k_weakest_rows(nums, 3);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << " " ;
    }
    cout << endl;
    return 0;
}