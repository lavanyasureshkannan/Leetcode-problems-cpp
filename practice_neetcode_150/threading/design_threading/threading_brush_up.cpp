#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <queue>

/*
    1. possible ways to intiate the thread
*/
// void func(int dets, int id)
// {
//     std::cout << "hello world" << std::endl;
// }

// void func2(std::vector<int>& data)
// {
//     for(size_t i=0; i<data.size(); i++)
//     {
//         std::cout << "data: " << data[i] << std::endl;
//     }
// }
// // possible ways to wirte thread
// // 1. free thread
// std::thread t1(func);
// // 2. Lmabda func
// std::thread t2([] {
//     do_work();
// });
// // 3. with args
// std::thread t3(func, 10, 1);
// 4. take with ref
// std::vector<int> a = {1,2,3,4,5};
// std::thread t4(func2, std::ref(a));

/*********************************************************************************/
/*
    2. MULTIPLE THREADS
*/

// std::vector<std::thread> threads;
// for(size_t i=0; i<5; i++)
// {
//     threads.emplace_back(worker,i);
// }
// for(auto &thread:threads)
// {
//     thread.join();
// }

/********************************************************************************/
/*
    3. MUTEXS
    1. Lock_guard:
        => simple lock 
        => locks on construction and unlocks on destruction
        => no manual unlock
    2. unique_lock
        => flexible lock
        => locks on construction and unlock on destruction
        => manual unlocking and locking 
        => definetly required for condition variable
    3. scoped_lock
        => used when two or more mutexs involved
        => Its argument order doesnt matter
        => dead- lock safe scenarios
    
    ALways use all the locks inside the scope and timer outside the scope
*/

// int data = 0;
// std::mutex mtx;
// {
//     std::lock_guard<std::mutex> lg(mtx);
//     data ++;
//     std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // this will hold the lock for 1000 ms
// }

// {
//     {
//         std::lock_guard<std::mutex> lg(mtx);
//         data ++;
//     }
//     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
// }

/************************************************************************************/
/*  
    4. CONDITION VARIABLE
    It does two things => sleeps and wake up
   
    ex: simple producer and consumer thread
    producer pushes → notify → consumer wakes → consumes ONE item → exits
*/
// std::queue<int> q;
// std::mutex mtx;
// std::condition_variable cv;

// void producer(int val)
// {
//     {
//         std::unique_lock<std::mutex> uql(mtx);
//         q.push(val);
//         std::cout << "pushed val: " << val << std::endl; 
//     }
//     cv.notify_one(); // something in the q is changed
//     std::this_thread::sleep_for(std::chrono::milliseconds(200));
// }

// void consumer()
// {
//     while(true)
//     {
//         std::unique_lock<std::mutex> uql(mtx);
//         cv.wait(uql, [] () {
//             return !q.empty(); //  something is changed so it wokes up and check the status
//                                 // if true continues, if false goes back to sleep again
//         });
//         int val = q.front();
//         q.pop();
//     }
    
// }

/************************************************************************************/
/*
    5. SHARED MUTEX
    Shared mutex uses shared lock
    works during the few readers and one writer scenarios 
    All readers hold shared_lock simultaneously — no blocking between readers. 
        Writer gets exclusive access — blocks until all readers done.
    
*/

int main()
{

    return 0;
}