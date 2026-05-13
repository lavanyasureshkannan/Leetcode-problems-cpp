#include <iostream>
#include <vector>
using namespace std;

/*
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
*/

int contained_most_Water(vector<int>& height)
{
    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;
    while(left < right)
    {
        int width = right - left;
        int curr_area = width * min(height[left], height[right]);
        max_area = max(curr_area, max_area);
        if(height[left] < height[right])
        {
            left ++;
        }
        else right--;
    } 
    return max_area;
}

//TC: O(N) each iteration the pointer is moved either left or right so n times
// SC: O(1) constant space

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << contained_most_Water(height) << endl;
    return 0;
}