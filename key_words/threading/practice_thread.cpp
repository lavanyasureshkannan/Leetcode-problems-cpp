#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <atomic>
#include <condition_variable>
using namespace std;

/*
    Join -> the main func will wait for thread to finish.
    detach -> the main will not wait for the thread to end.
               if main ends before thread then thread is forcefully shut down 
    Mutex -> mutex is a synchronization primitive that is used to protect data from race condition.
    atomic -> Its a variable that you can use when you dont want to use mutex
    lock_guard -> Its a wrapper for mutex that gets 
                  locked and unlocked automtatically when the onject goes out of scope.
    unique_lock -> Its almost same as lock_guard except that you can manually lock, unlock, 
                  defer_lock, change ownership and all those.
    shared_lock -> Its a read only lock used with shared_mutex
                   it allows many thread to read but let only one thread to write.
    condition_variable -> Its needed in cases where one thread should wait for the other thread to finish its tasks and
                    notify the thread.
    

*/

// const int count = 0;


// int count = 0;
// mutex mtx;
// condition_variable cv;

// void producer()
// {
//     unique_lock<mutex> uq_lock(mtx); // locked
//     for(int i=0; i< 1000000; i++)
//     {
//         count ++;
//     }
//     cv.notify_one();
// }

// void consumer()
// {
//     unique_lock<mutex> uq_lock(mtx); 
//     for(int i=0; i<1000000; i++)
//     {
//         count ++;
//     }
//     while(count < 2 * 1000000)
//     {
//         cv.wait(uq_lock); // it sleeps till it gets its notification
//     }
// }

// int main()
// {
//     thread producer_t(producer);
//     thread consumer_t(consumer);
//     producer_t.join();
//     consumer_t.join();

//     cout << count << endl;
//     return 0;
// }

// int count = 0;
// mutex mtx;

// shared_mutex s_mtx;
// int shared = 0;


// void reader(int id)
// {
//     shared_lock<shared_mutex> sl(s_mtx);
//     cout << "Reader " << id << "reading data: " << shared << endl;
// }

// void writer(int id)
// {
//     unique_lock<shared_mutex> sl(s_mtx);
//     for(int i=0; i<5; i++)
//     {
//         shared ++;
//     }
//     cout << "Writer " << id << "writing data: " << shared << endl;
// }

// void func()
// {
//     //lock_guard<mutex> lg(mtx);
//     //unique_lock<mutex> uq_l(mtx); // now its locked
//     //mtx.lock();
//     unique_lock<mutex> uq_l(mtx, defer_lock); // its not locked now
//     this_thread::sleep_for(chrono::seconds(3));
//     uq_l.lock();
//     for(int i=0; i< 1000000; i++)
//     {
//         count ++;
//     }
//     uq_l.unlock();
//     // mtx.unlock();
//     // cout << "Thread starts ..." << endl;
//     // this_thread::sleep_for(chrono::seconds(5));
//     // cout << "Thread ends .. " << endl; 
// }


// int main()
// {
//     thread r1(reader, 1);
//     thread r2(reader, 2);
//     thread w1(writer, 1);

//     r1.join();
//     r2.join();
//     w1.join();
// }

// // int main()
// // {
// //     thread t1(func);
// //     thread t2(func);

// //     t1.join();
// //     t2.join();

// //     cout << count << endl;
// //     // cout << "Main starts ... " << endl; 
// //     // thread t1(func);
// //     // t1.detach();
// //     // this_thread::sleep_for(chrono::seconds(2));
// //     // cout << "Main ends .. " << endl;
// //     return 0;
// // }

// mutex m1, m2;

// // Thread 1 locks m1, then m2
// void task1() 
// {
//     cout << "task 1 starts ..." << endl;
//     unique_lock<mutex> lg1(m1);
//     this_thread::sleep_for(chrono::milliseconds(100));
//     unique_lock<mutex> lg2(m2); // waits if m2 is already locked
//     cout << "task 1 ends ...." << endl;
// }

// // Thread 2 locks m2, then m1
// void task2() 
// {
//     cout << "tasks 2 starts ..," << endl;
//     unique_lock<mutex> lg2(m1);
//     this_thread::sleep_for(chrono::milliseconds(100));
//     unique_lock<mutex> lg1(m2); // waits if m1 is already locked
//     cout << "tasks 2 ends .. " << endl;
// }


// void func() 
// {
//     mutex m;
//     lock_guard<mutex> lg(m);
//     cout << "Thread safe code" << endl;
// }
// int main()
// {
//     thread t1(func);
//     t1.join();
//     // thread t1(task1);
//     // thread t2(task2);

//     // t1.join();
//     // t2.join();

//     return 0;

// }



void say_hello(string& name) {
    this_thread::sleep_for(chrono::milliseconds(10));
    cout << "Hello, " << name << endl;
}

int main() {
    string n = "Alice";
    thread t(say_hello, ref(n));
    n = "Bob"; // changed before thread runs
    t.join();
}
