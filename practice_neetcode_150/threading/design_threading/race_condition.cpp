#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

/*
    RACE CONDITION : When two or more threads trying to make chnages to the common variable.

    solution 1: fix with mutex
    solution 2: fix with atomic
    
    Atomic for single primitive values — counters, flags, single pointers. 
    Mutex when I need multiple related variables to update together as one operation — like head, tail, and count in my circular buffer. 
    Two atomics updated separately are not atomic as a pair
*/

//int count = 0;
//std::mutex mtx;

std::atomic<int> count = 0;
void increment_counter()
{
    for(size_t i=0; i<100000; i++)
    {
        //std::lock_guard<std::mutex> lg(mtx); 
        count ++;
        std::cout << "INcremeneted count: " << count << std::endl;
    }
}

int main()
{
    std::thread t1(increment_counter);
    std::thread t2(increment_counter);

    t1.join();
    t2.join();

    std::cout << "Total count: " << count << std::endl;
    return 0;
}