#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
using namespace std;

/*
    JOIN => controlled. Your main thread will wait for your worker thread to finish
    DETACH => uncontrolled. Your main thread will NOT wait for your worker thread to finish. 
            If it ends early than your worker thread then it stops worker thread abdroptly.
    RACE CONDITION => when two threads are trying to modify the same variable, then it would result in RACE CONDITION.
    MUTEX =>  Mutex prevents race condition and helps in thread synchronization.
    DEAD LOCK => When two or more threads waiting on each other forever. No crash but hangs up. 
                This happens when you use two or more mutexs m1 and m2 lets say. one waits forever for the other.
    LOCK_GUARD => RAII technique. Which lock and unlocks automatically. 
    UNIQUE_LOCK => similar to lock guard but it comes with more control.
    SHARED_LOCK => allows multiple threads to read and write at the same time. very efficient. 
                    shared lock uses shared mutex (use shared lock for readers and unique lock for writers)
    CONDITION_VARIABLE => It is a synchronization primitive that other threads in the environment 
                          that the shared resource is free to access.
    ATOMIC => atomic operation works with basic data types (int to keep track of counts and stuff) 
                    allowing it do perform multi threading without using locks 
    ATOMIC_FLAG => acts like a boolean atomic flag
    HARDWARE_CONCURRENCY => Number of threads available in your system
    THREAD_get.id() => retruns the unique id of the current thread 
*/

template <typename... Args>
void Log(Args... args)
{
    (cout << ... << args) << endl;
}
int counter = 0;
//mutex m;

shared_mutex sm;

void incoming_data(int dets, int thread_id)
{
    for(int i=0; i<dets; i++)
    {
        // m.lock();
        //lock_guard<mutex> lock(m);
        //unique_lock<mutex> lock(m, defer_lock);
        //lock.lock();
        
        this_thread::sleep_for(chrono::milliseconds(200));
        unique_lock<shared_mutex> lock(sm);
        counter ++;
        //lock.unlock();

        Log("Writer ", thread_id, "updated counter to = ", counter);
        //Log("Thread", thread_id," ", "Counter val", counter);
        // m.unlock();
        //Log("Thread", thread_id, " Iteration ", i);
    }
}

void read_thread(int dets, int thread_id)
{
    for(size_t i=0; i< dets; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(2));
        shared_lock<shared_mutex> lock(sm);
        Log("Reader ", thread_id, "reader count = ", counter);
    }
}

int main()
{
    // thread t1(incoming_data,1000,1);
    // thread t2(incoming_data,1000,2);

    thread t1(read_thread, 10, 1);
    thread t2(read_thread, 10, 2);
    thread t3(incoming_data, 5, 99);
    t1.join();
    t2.join();
    t3.join();

    Log("Final_counter = ", counter);
    //this_thread::sleep_for(chrono::seconds(3));
    return 0;
}