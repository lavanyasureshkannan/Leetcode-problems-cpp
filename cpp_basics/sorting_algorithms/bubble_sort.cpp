#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Array = [5, 3, 8, 4, 2]
*/

void print_elements(vector<int>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void swapped(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubble_Sort(vector<int>& nums)
{
    int n = nums.size();
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(nums[j] > nums[j+1])
            {
                swapped(nums[j], nums[j+1]);
            }
        }
    }
    print_elements(nums);
}

int main()
{
    vector<int> nums = {5, 3, 8, 4, 2, 1};
    bubble_Sort(nums);
    return 0;
}