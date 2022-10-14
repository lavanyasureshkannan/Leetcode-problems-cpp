#include<iostream>
// create an array at runtime using new keyword
// deleting the array using delete keyword
int main()
{
    int size;
    std::cout << " Enter the size of an array: ";
    std::cin >> size;
    // allocation of array using pointer and new keyword
    int* Myarray = new int[size];

    for(int i=0; i<size; i++)
    {
        std::cout << "Myarray[" << i << "]" << ":";
        std::cin >> Myarray[i]; 
    }
    for(int i=0; i<size; i++)
    {
        std::cout << Myarray[i] << " " << std::endl;
    } 
    delete Myarray;
    Myarray = NULL;
    std::cout << "your array has been deleted" << std::endl;

    return 0;
}