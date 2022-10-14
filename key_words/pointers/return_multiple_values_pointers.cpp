#include<iostream>
#include<climits>


int getMin(int nums[], int size)
{
    int min = INT_MAX;
    for(int i=0; i < size; i++)
    {
        if(nums[i] < min)
        {
            min =nums[i];
        }
    }
    return min;
}

int getMax(int nums[], int size)
{
    int max = INT_MIN;
    for(int i=0; i<size; i++)
    {
        if(nums[i] > max)
        {
            max = nums[i];
        }
    }
    return max;
}

// when you want to add both the functions into a single function then you have pass the address 
void getMinAndMax(int nums[], int size, int *min, int *max)
{
    for(int i=0; i<size; i++)
    {
        if(nums[i] < *min)
        {
            *min = nums[i]; 
        }
        if(nums[i] > *max)
        {
            *max = nums[i];
        }
    }
}

int main()
{
    int arr[6] = {-1,1,2,3,4,5};
    int min = INT_MAX;
    int max = INT_MIN;
    getMinAndMax(arr, 6, &min, &max);
    std::cout << min << std::endl;
    std::cout << max << std::endl;
    // std::cout << getMin(arr, 6) << std::endl;
    // std::cout << getMax(arr,6) << std :: endl;
    return 0;
}