#include <iostream>
#include <vector>
using namespace std;

/*
    1. Choose the min element and swap its pos with the curr element

    ex: [5, 3, 8, 4, 2]
*/

void print_elements(vector<int>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void selection_sort(vector<int>& nums)
{
    int n = nums.size();
    for(int i=0; i<n-1; i++)
    {
        int min_idx = i;
        for(int j=i+1; j<n; j++)
        {
            if(nums[j] < nums[min_idx])
            {
                min_idx = j;
            }
        }
        swap(nums[i], nums[min_idx]);
    }
    print_elements(nums);
}


int main()
{
    vector<int> nums = {5, 3, 8, 4, 2};
    selection_sort(nums);
    return 0;
}