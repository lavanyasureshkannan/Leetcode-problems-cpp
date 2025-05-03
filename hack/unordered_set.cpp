#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void display(vector<int>& arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        cout<< arr[i] << " ";
    }

}

vector<int> my_func(vector<int>& nums)
{
    unordered_set<int>my_Set;
    for(int i=0; i<nums.size(); i++)
    {
        my_Set.insert(nums[i]);
    }
    vector<int> result(my_Set.begin(), my_Set.end());
    display(result);
    return result;
}

int main()
{
    vector<int> arr = {1,1,2,2,3,3,4,4,5,5};
    my_func(arr);
    return 0;
}