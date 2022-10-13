#include<iostream>

/*
    every element in the array holds different memory address
    your 0th index element and the entire address of the element will be same
*/

int main()
{
    int arr[5] = {1,2,3,4,5};
    std::cout << arr << std::endl;
    // std::cout << &arr[0] << std::endl;
    // std::cout << &arr[1] << std::endl;
    for(int i=0; i<5; i++)
    {
        std::cout << &arr[i] << std::endl;
    }
    return 0;
}