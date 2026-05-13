#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: matrix = [
  [1,2,3],
  [4,5,6],
  [7,8,9]
]

Output: [
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
*/

void print(vector<vector<int>>& nums)
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

void roatate_image(vector<vector<int>>& nums)
{
    // reverse
    reverse(nums.begin(), nums.end());
    // transpose
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=i+1; j<nums[i].size(); j++)
        {
            swap(nums[i][j] , nums[j][i]);
        }
    }
    print(nums);
}

int main()
{
    vector<vector<int>> nums = {{1,2,3},
                                {4,5,6},
                                {7,8,9}};
    // {{7,8,9}}
    // {4,5,6},
    // {1,2,3},
    roatate_image(nums);
    
    return 0;
}