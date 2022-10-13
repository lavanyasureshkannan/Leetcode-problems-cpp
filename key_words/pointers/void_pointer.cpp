#include<iostream>

/* 
    VOID POINTER
    1. void pointer is a special type of pointer which holds the memory address of any data type
*/

void display_int(int *p)
{
    std::cout << *p << std::endl;
}

void display_char(char *ch)
{
    std::cout << *ch << std::endl;
}

void display_data(void *ptr, char type)
{
    if(type == 'i')
    {
        std::cout << *((int*) ptr) << std:: endl;

    }
    else if(type == 'c')
    {
        std::cout << *((char*) ptr) << std::endl;
    }
}


int main()
{
    int n = 10; // variable
    char alpha = 'a';
    int *ptr = &n; // storing the address of the variable in a pointer
    *ptr = 10; // dereferencing the pointer
    //display_int(&n);
    //display_char(&alpha);
    display_data(&n,'i');
    display_data(&alpha, 'c');


    // std::cout << n << std::endl;
    // std::cout << &n << std::endl;
    // std::cout << ptr << std::endl;
    // std::cout << *ptr << std::endl;
    // std::cout << n << std::endl;

    return 0;
}