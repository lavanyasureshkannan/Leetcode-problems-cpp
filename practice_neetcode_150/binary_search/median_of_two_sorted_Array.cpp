#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

*/

double median(vector<int>& nums1, vector<int>& nums2)
{
    for(int i=0; i<nums2.size(); i++)
    {
        nums1.push_back(nums2[i]);
    }
    sort(nums1.begin(), nums1.end());
    int n = nums1.size(); 
    double result = 0.0;
    if(n%2 == 1)  
    {
        result = nums1[n/2];
    }
    else
    {
        result = (nums1[n/2] + nums1[n/2-1]) / 2.0;
    }
    return result;

}

// O(NlogN)

int main()
{
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2,4};

    cout << median(nums1, nums2);
    return 0;
}