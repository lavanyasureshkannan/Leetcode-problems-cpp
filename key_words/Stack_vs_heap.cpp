#include<iostream>
using namespace std;

/*
    STACK VS HEAP

    STACK:
    1. It’s a temporary memory allocation scheme where the data members are accessible only if the method( ) that contained them is currently is running.
    2. It allocates or de-allocates the memory automatically as soon as the corresponding method completes its execution.
    3. Stack memory allocation is considered safer as compared to heap memory allocation because the data stored can only be access by owner thread.

    HEAP:
    1. This memory allocation scheme is different from the Stack-space allocation, here no automatic de-allocation feature is provided. 
    2. We need to use a Garbage collector to remove the old unused objects in order to use the memory efficiently.
    3. The processing time(Accessing time) of this memory is quite slow as compared to Stack-memory.
    4. Heap-memory is also not threaded-safe as Stack-memory because data stored in Heap-memory are visible to all threads.
    5. Size of Heap-memory is quite larger as compared to the Stack-memory.
    
********************************************************|*******************************************************************
            stack                                       |               heap                                                                   
********************************************************|**********************************************************************
    1. contagious block of memory                       |      Allocated in random order
********************************************************|***********************************************************************
    2. The memory gets free once the variable goes      |      You have manually delete it but incase if you are using
    variable goes out of scope                          |      smart pointers, it does delete things automatically.
********************************************************|************************************************************************
    3. Each thread creates its own stack when it        |      Heap is shared among all the threads
    is created.                                         |
********************************************************|*************************************************************************
    4. Created automatically by compiler instructions   |       Manually by the programmer
********************************************************|*************************************************************************
    5. Implementation is easy                           |       Implementation is hard
********************************************************|************************************************************************
    6. Access time is faster                            |       Access time is slow
********************************************************|*************************************************************************
    7. The Size	is Smaller than heap memory.	        |       The size is Smaller than heap memory is larger than stack memory.  
********************************************************|**************************************************************************
*/

struct nums
{
    int num1, num2, num3;
};

int main()
{
    // stack
    int value= 5;// int
    int arr[5]; /// array
    nums n;


    // heap
    int* h_value  = new int;
    *h_value = 10;
    int* h_array = new int[5];
    nums* h_nums = new nums(); 
    return 0;
}