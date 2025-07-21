#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

/*
    lock guard -> Perfect for simple cases where:
        1. You just want to lock once
        2. No unlocking in between
        3. No need to pass the lock around  
    syntax -> lock_guard<mutex> name(myMutex);

    unique_lock -> unique_lock offers more flexibility than lock_guard. 
        1. Can lock/defer/try-lock/unlock
        2. Can be moved (used across scopes)
    syntax -> unique_lock<mutex> name(mymutex, defer_lock)

    shared_lock -> std::shared_lock is a read-only lock used with std::shared_mutex
        1. It allows multiple threads to read the same data at the same time.
        2. But only one thread can write, and when it does, no other reads or writes are allowed.   
    syntax ->   shared_mutex (instead of plain std::mutex)
                #include <shared_mutex> (C++17 or later)
                shared_lock<shared_mutex> for readers
                unique_lock<shared_mutex> for writers


*/

mutex mtx;

int count = 0;



// using lockguard
void func1()
{
    cout << "thread func1 starts...." << endl;
    lock_guard<mutex> m(mtx);
    for(int i=0; i<1000000; i++)
    {
        count++;
    }
    cout << "thread func1 ends ...." << endl;
}


// using unique_lock
void func2()
{
    // flexible locking and unlocking
    cout << "thread func2 starts .... " << endl;
    unique_lock<mutex> ul(mtx);
    cout << "thread is locked now .. " << endl;
    ul.unlock();
    cout << "thread is unlocked again .." << endl;
    ul.lock();
    for(int i=0; i<100000; i++)
    {
        count ++;
    }
    ul.unlock();
    cout << "thread func2 ends ...." << endl;
}

void func3()
{
    // defer locking more flexible
    unique_lock<mutex> ul(mtx, defer_lock); // its not locked yet
    ul.lock(); // now locked
    cout << " do something here .. " << endl;
    for(int i=0; i<100000; i++)
    {
        count ++;
    }
    ul.unlock();

}


int main()
{
    thread t1(func3);
    thread t2(func3);
    t1.join();
    t2.join();

    cout << count << endl;
    return 0;
}