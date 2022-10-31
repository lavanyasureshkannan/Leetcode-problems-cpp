// DEBUGGING USING CRT DEBUG

#define _CRTDBG_MAP_ALLOC // which line exactly the memory leakage problem happens
#include<iostream>
#include <cstdlib>
#include<stdlib.h>
#include<crtdbg.h>
using namespace std;

int main()
{
    int* x_ptr = (int*) malloc(sizeof(int));
    int* y_ptr = (int*) malloc(sizeof(int));
    *x_ptr = 10;
    *y_ptr = 20;
    
    cout << *x_ptr << endl;
    cout << *y_ptr << endl;

    delete(x_ptr);
    _CrtDumpMemoryLeaks();

    cout << "after deallocating" << endl;
    cout << *x_ptr << endl;

}