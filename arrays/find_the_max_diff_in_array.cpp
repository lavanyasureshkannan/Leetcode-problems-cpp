#include<iostream>
using namespace std;

int maxi(int x, int y)
{
    if(x>y) return x;
    else return y;
}

int max_difference(int arr[], int n)
{
    
    int diff = 0;
    for(int i =0; i< n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] > arr[i])
            {
                diff = maxi(diff, arr[j] - arr[i]);
            }
        }
    }
    cout << diff;
    return diff;
}


int main()
{
    int arr[] = {2,6,7,8,9,12,15};
    int n = sizeof(arr) / sizeof(arr[0]);
    max_difference(arr,n);
    return 0;
    

}