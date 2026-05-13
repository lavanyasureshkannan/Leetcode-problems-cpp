#include <iostream>
#include <vector>
using namespace std;
/*
Input: height = [1,7,2,5,4,7,3,6]
Output: 36
*/

int contained_most_water(vector<int>& height)
{
    if(height.size() == 0) return 0;
    int left = 0;
    int right = height.size() - 1;
    int maxi = 0;
    while(left < right)
    {
        int width = right - left;
        int curr_Area = width * min(height[left], height[right]);
        maxi = max(curr_Area, maxi);
        if(height[left] < height[right]) left ++;
        else right --;
    }
    return maxi;
}

int main()
{
    vector<int>height = {1,7,2,5,4,7,3,6};
    cout << contained_most_water(height) << endl;
    return 0;
}