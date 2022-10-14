#include<iostream>

int main()
{
    int rows = 3;
    int cols = 3;

    /*
        allocating memory for the array
        lets say,

        arr = {{1,2,3},{4,5,6},{7,8,9}};
        `         0       1        2
        00xee   00xaa    00xbb   00xcc

        ptr0* -> &arr[0]
        ptr1* -> &arr[1]
        ptr2* -> &arr[2]

        ptr** -> {ptr0*, ptr1*, ptr2*}

    */ 

    int **array = new int*[rows];
    for(int i=0; i<rows; i++)
    {
        array[i] = new int [cols];
    }
    array[0][0] = 1;

    // when you delete the allocated memory 

    for(int i=0; i<rows; i++)
    {
        delete[] array[i]; // just delete the rows

    }
    // delete the entire array
    delete[] array;
    array = NULL;
    return 0;
}