#include<iostream>
#include<thread>
#include<chrono>
#include<ctime>
using namespace std;

/*
    MUTEX IN THREADING

    MUTEX: Mutually Exclusive
    -> Mutex is used to avoid the race condition. We use lock() and unlock() i mutex to avoid such race conditions.

    Race Condition: Its a situation when two or more threads tries to change a common data at the same time.
    Critical section: If we come across the race condition then we have to protect it and the protected section is called critical section

    Note: Race condition occurs when we try to modify the data and not when we try to access it.
*/

int count = 0;

void increment_count()
{
    count++;
}

int main()
{
    thread t1(increment_count);
    thread t2(increment_count);
    t1.join();
    t2.join();
    return 0;
}