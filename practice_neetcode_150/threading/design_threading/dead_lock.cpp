#include <iostream>
#include <mutex>
#include <thread>

/*
    DEAD LOCK => When two or more threads are stuck forever waiting for the resources.

    Solution 1 => lock in the same order for both the threads mtx1 then mtx2
    SOlution 2 => Use scoped lock (for all the cases we use more than one mutex)

    Scope lock => when using mutiple mutexes
*/

template<typename... Args>
void Log(Args... args)
{
    (std::cout << ... << args) << std::endl;
}

std::mutex mtx1, mtx2;

void thread_1()
{
    // std::lock_guard<std::mutex> lg(mtx1);
    // Log("Thread 1 locks mutex1");
    // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // std::lock_guard<std::mutex> lq(mtx2);
    // Log("Thread 1 locks mutex2");

    Log("Attempting to lock the mutex");
    {
        std::scoped_lock lock(mtx1, mtx2);
        Log("Thread 1, successfully acquired both the logs");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    Log("Locks are released");
}

void thread_2()
{
    // std::lock_guard<std::mutex> lg(mtx2);
    // Log("Thread 2 locks mutex2");
    // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // Log("Thread 2 locks mutex1");
    // std::lock_guard<std::mutex> lq(mtx1);

    Log("Attempting to lock the mutex");
    {
        std::scoped_lock lock(mtx1, mtx2);
        Log("Thread 2, successfully acquired both the logs");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    Log("Locks are released");
}




int main()
{
    std::thread t1(thread_1);
    std::thread t2(thread_2);
    
    t1.join();
    t2.join();
    return 0;
}